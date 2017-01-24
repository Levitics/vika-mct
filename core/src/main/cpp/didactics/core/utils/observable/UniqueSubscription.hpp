
#ifndef UNIQUESUBSCRIPTION_HPP
#define UNIQUESUBSCRIPTION_HPP
#include <atomic>
#include <functional>
#include <memory>
class UniqueSubscription final
{
public:

    //! This class is not copy-constructible.
    UniqueSubscription(UniqueSubscription const & ) = delete;

    //! This class is not copy-assignable.
    UniqueSubscription & operator = (UniqueSubscription const &) = delete;

    //! This class is move-constructible.
    UniqueSubscription(UniqueSubscription &&) = default;

    //! This class is move-assignable.
    UniqueSubscription & operator = (UniqueSubscription &&) = default;

    UniqueSubscription() = default;
    // UniqueSubscription(const UniqueSubscription& orig);
    virtual ~UniqueSubscription();
    /*
     *  @brief Create a subscription with the specified unsubscribe funct
     */
    UniqueSubscription(std::function<void()> const & unsubscribe);

    auto unsubscribe ();
    /*
     * Disassociate the subscription from the subscribed observer.
     */
    auto release ();

private:

    std::function<void()> unsubscribe_ = []() {
                                         };
    std::unique_ptr<std::atomic_flag> called_ = std::make_unique<std::atomic_flag>();
};

#endif
