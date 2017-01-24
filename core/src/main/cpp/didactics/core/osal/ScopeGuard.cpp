
#include <didactics/core/osal/ScopeGuard.hpp>
template<class F>
ScopeGuard<F>::ScopeGuard(F af)
    : f(std::move(af))
    , active(true)
{

}

/*
   ScopeGuard::ScopeGuard() {
   }

   ScopeGuard::ScopeGuard(const ScopeGuard& orig) {
   }

   ScopeGuard& operator=(ScopeGuard && rhs) noexcept
   {
    if (this != &rhs)
    {
        this->active = std::move(rhs.active);
        this->f  = std::move(rhs.f);
        rhs.commit();
    }
    return *this;
   }

   void commit(void) const noexcept
   {
    this->active = true;
   }

   ScopeGuard::~ScopeGuard() {
    if(active)
    {
        f();
    }
   }

   void ScopeGuard::dismiss()
   {
    active = false;
   }

   ScopeGuard::ScopeGuard(ScopeGuard && rhs)
   : f(std::move(rhs.f))
   , active(rhs.active)
   {
    rhs.dismiss();
   }
 */
