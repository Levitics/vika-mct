
#include <memory>
#include <didactics/core/utils/observable/SharedSubscription.hpp>

SharedSubscription::SharedSubscription(SharedSubscription && subscription)
    : unsubscribe_ { std::make_shared<SharedSubscription>(std::move(subscription)) }
{

}

auto SharedSubscription::unsubscribe ()
{
    unsubscribe_.reset();
}

SharedSubscription::operator bool () const noexcept
{
    return !!unsubscribe_;
}
