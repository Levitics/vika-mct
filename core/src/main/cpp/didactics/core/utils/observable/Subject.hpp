
#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <functional>
#include <memory>
#include <type_traits>
#include <didactics/core/utils/observable/SharedSubscription.hpp>
#include <didactics/core/utils/observable/Collection.hpp>


template <typename ...>
class Subject;

/*!
 *  @brief Stores observers and provides a way to notify them when the notify().
 */
//! Observers are objects that satisfy the Callable concept and can be stored
//! inside a ``std::function<void(Args ...)>``.
//!
//! Once you call subscribe(), the observer is said to be subscribed to
//! notifications from the subject.
//!
//! Calling notify(), will call all the currently subscribed observers with the
//! arguments provided to notify().
//!
//! All methods can be safely called in parallel, from multiple threads.
//!
//! \tparam Args Observer arguments. All observer types must be storable
//!              inside a ``std::function<void(Args ...)>``.
//!
//! \warning Even though subjects themselves are safe to use in parallel,
//!          observers need to handle being called from multiple threads too
template <typename ... Args>
class Subject <void (Args ...)>
{
public:

    using observer_type = void (Args ...);

    template <typename Callable>
    auto subscribe (Callable && observer)->SharedSubscription;
    auto notify (Args ... arguments) const->void;

    Subject() = default;;
    Subject(Subject const &) = delete;    //! Subjects are **not** copy-constructible.
    Subject(Subject &&) noexcept = default;                      //! Subjects are move-constructible.
    auto operator = (Subject const &)->Subject & = delete;       //! Subjects are **not** copy-assignable.
    auto operator = (Subject &&) noexcept->Subject & = default;  //! Subjects are move-assignable.

    //    Subject(const Subject& orig);
    //    virtual ~Subject();

private:

    using collection = Collection<std::function<observer_type> >;
    std::shared_ptr<collection> observersList { std::make_shared<collection>() };
};


template <typename ObserverType , typename EnclosingType>

class Subject<ObserverType , EnclosingType> : public Subject<ObserverType>
{
public:

    using Subject<ObserverType>::Subject;

private:

    using Subject<ObserverType>::notify; //! \see subject<void(Args...)>::notify
    friend EnclosingType;
};

#endif
