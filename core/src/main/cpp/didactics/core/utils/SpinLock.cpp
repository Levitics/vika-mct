
#include <didactics/core/utils/SpinLock.hpp>
SpinLock::SpinLock()
    : atomicLock(false)
{
}

void SpinLock::lock ()
{
    while (this->atomicLock.exchange(true))
        ;
}

void SpinLock::unlock ()
{
    this->atomicLock = false;
}

bool SpinLock::isLocked (void) const
{
    return (this->atomicLock);
}
