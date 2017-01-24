
#include <didactics/core/utils/observable/UniqueSubscription.hpp>
/*
   UniqueSubscription::UniqueSubscription() {
   }

   UniqueSubscription::UniqueSubscription(const UniqueSubscription& orig) {
   }

   UniqueSubscription::~UniqueSubscription() {
    this->unsubscribe();
   }
 */
UniqueSubscription::UniqueSubscription(std::function<void()> const & unsubscribe)
    : unsubscribe_ { unsubscribe }
{

}

auto UniqueSubscription::unsubscribe ()
{

    if (!called_ || !unsubscribe_ || called_->test_and_set())
    {
        return;
    }

    try
    {
        if (unsubscribe_)
        {
            unsubscribe_();
        }
    }
    catch (...)
    {
        called_->clear();
        throw;
    }
}

auto UniqueSubscription::release ()
{
    decltype(unsubscribe_)unsub = []() {
                                  };
    std::swap(unsub , unsubscribe_);
    return unsub;
}
