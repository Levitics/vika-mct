
#include <mutex>
#include <didactics/core/utils/Singleton.hpp>

template <class Derived>
Derived* Singleton<Derived>::instance_ = nullptr; // Derived();//

template <class Derived>
Derived & Singleton<Derived>::get ()
{
    static std::once_flag flag;
    std::call_once(flag , [] { instance(); });
    return (instance());
}

/*
   template <class Derived>
   Singleton<Derived>::Singleton() {
   }

   template <class Derived>
   Singleton<Derived>::Singleton(const Singleton & orig) {
   }

   template <class Derived>
   Singleton<Derived>::~Singleton() {
   }
 */
