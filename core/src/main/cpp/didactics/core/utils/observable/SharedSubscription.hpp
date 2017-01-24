
#ifndef SHAREDSUBSCRIPTION_HPP
#define SHAREDSUBSCRIPTION_HPP
#include <atomic>
#include <functional>

class SharedSubscription final
{
public:

    SharedSubscription() noexcept = default;
    explicit SharedSubscription(SharedSubscription && subscription);
    SharedSubscription(const SharedSubscription & orig);
    virtual ~SharedSubscription();
    auto unsubscribe ();
    explicit operator bool () const noexcept;

private:

    std::shared_ptr<SharedSubscription> unsubscribe_;
};

#endif
