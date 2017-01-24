
#ifndef COLLECTION_HPP
#define COLLECTION_HPP
#include <atomic>
#include <functional>
#include <type_traits>
#include <memory>
/*!
 *  @brief Check if a callable type is compatible with an observer type.
 */
template <typename CallableType , typename ObserverType>
using isCompatibleWithObserver = std::is_convertible<CallableType , std::function<ObserverType> >;

/*!
 * @brief Check if a callable type can be used to subscribe to a subject.
 */
template <typename CallableType , typename SubjectType>
using isCompatibleWithSubject = isCompatibleWithObserver<CallableType , typename SubjectType::observer_type>;


template <typename ValueType>
class Collection final
{
    struct Node
    {
        Node * next { nullptr };
        ValueType element;
        std::atomic<bool> deleted { false };
        std::size_t node_id;
    };

    /*
       struct gc_blocker
       {
        gc_blocker(Collection<ValueType> const * c) noexcept :
            collection_{ c }
        {
     ++collection_->block_gc_;
            while(collection_->gc_active_.load())
                ;
        }

        ~gc_blocker() noexcept
        {
            --collection_->block_gc_;
        }

       private:
        Collection<ValueType> const * collection_;
       };*/

public:

    Collection() noexcept = default;;
    Collection(const Collection & orig);
    virtual ~Collection();
    template <typename V>
    auto insert (V && element)
    {
        auto const i = ++last_id_;
        auto n = std::make_unique<Node>();
        n->node_id = i;
        n->element = std::forward<V>(element);
        {
            // gc_blocker const block { this };
            n->next = head_.load();

            while (!head_.compare_exchange_weak(n->next , n.get()))
                ;

            n.release();
        }
        // gc();
        return (i);
    }

    auto remove (std::size_t const & element_id) noexcept
    {
        auto deleted = false;
        {
            //        gc_blocker const block { this };

            for (auto n = head_.load(); n; n = n->next)
            {
                if (n->node_id != element_id)
                {
                    continue;
                }

                deleted = !n->deleted.exchange(true);
                break;
            }
        }

        gc();
        return deleted;
    }

private:

    void gc () noexcept;
    std::atomic<Node *> head_ { nullptr };
    mutable std::atomic<std::size_t> block_gc_ { 0 };
    std::atomic<bool> gc_active_ { false };
    std::atomic<std::size_t> last_id_ { 0 };
};

#endif
