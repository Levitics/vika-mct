
#ifndef SCOPEGUARD_HPP
#define SCOPEGUARD_HPP
#include <iostream>
#include <utility>

template<class F>

class ScopeGuard
{
public:

    ScopeGuard() = delete;
    ScopeGuard(const ScopeGuard & orig) = delete;
    //    ScopeGuard& operator=(const ScopeGuard &) = delete;
    ScopeGuard & operator = (ScopeGuard && rhs) noexcept;
    ScopeGuard(ScopeGuard && rhs);
    virtual ~ScopeGuard();

    ScopeGuard(F af);
    void dismiss ();
    void commit (void) const noexcept;

private:

    F f;
    bool active;
};

/*
   template<class F>
   ScopeGuard<F> scopeGuard(F f)
   {
    return ScopeGuard<F>(std::move(f));
   }

   namespace detail
   {
    enum class ScopeGuardOnExit
    {
    };
    template<typename F>
    ScopeGuard<F> operator+(ScopeGuardOnExit, F&& fn)
    {
        return ScopeGuard<F>(std::forward < F > (fn));
    }
   }*/
#endif
