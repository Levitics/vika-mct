
#include <didactics/core/utils/observable/Subject.hpp>

template <typename ... Args>
template <typename Callable>
auto Subject::Subject<void (Args ...)>::subscribe (Callable && observer)->UniqueSubscription
{
    isCompatibleWithObserver<Callable , observer_type>::value;
    auto id = observersList->insert(observer);

    return unique_subscription
           {
               [this , id , weak_observers = std::weak_ptr < Collection > { observersList }]()
               {
                   auto const observers = weak_observers.lock();

                   if (!observers)
                   {
                       return;
                   }

                   observers->remove(id);
               }
           };
}

template <typename ... Args>
void Subject::Subject<void (Args ...)>::notify (Args ... arguments) const
{
    observers_->apply([&](auto && observer) {
        observer(arguments ...);
    });
}
