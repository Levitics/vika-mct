
#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include <didactics/core/utils/SpinLock.hpp>
template <class Derived>

class Singleton
{
public:

    template <typename ... Args>
    static inline Derived &getInstance (Args && ... args)
    {

    }

    template <typename ... Args>
    static inline Derived * getInstancePointer (Args && ... args)
    {

    }

    static Derived & get ();

protected:

    Singleton() = delete;
    Singleton(const Singleton & orig) = delete;
    Singleton & operator = (const Singleton &) = delete;
    Singleton & operator = (Singleton &&) = delete;      // Move assig
    Singleton(Singleton &&) = delete;                  // Move construct
    virtual ~Singleton();
    static Derived * instance_;
    //    std::shared_ptr<Derived> instance;

private:

    static Derived & instance ()
    {
        if (instance_ == nullptr)
        {
            instance_ = new Derived();
        }

        return *instance_;
    }

    static Derived * InstancePointer;
    static SpinLock lock;
};

#endif
