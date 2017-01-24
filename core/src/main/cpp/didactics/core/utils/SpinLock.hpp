
#ifndef SPINLOCK_HPP
#define SPINLOCK_HPP
#include <atomic>
class SpinLock final
{
public:

    SpinLock();
    SpinLock(const SpinLock & orig) = default;
    SpinLock(SpinLock && orig) = default;
    SpinLock & operator = (const SpinLock & orig) = default;
    SpinLock & operator = (SpinLock && orig) = default;
    virtual ~SpinLock() = default;

    void lock ();
    void unlock ();
    bool isLocked (void) const;

private:

    std::atomic_bool atomicLock;
};

#endif
