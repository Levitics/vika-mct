
#include <errno.h>
#include <didactics/core/osal/Semaphore.hpp>
// *
Semaphore::Auto::Auto(const Semaphore & sem ,
                      int timeout)
    : semaphore(sem)
{
    // if (this->semaphore.take(timeout) == ERROR)
    {
        // throwErrno("take", this->semaphore);
    }
}

Semaphore::Auto::~Auto()
{
    try
    {
        // if (this->semaphore.give() == ERROR)
        {
            // throwErrno("give", this->semaphore);
        }
    }
    catch (... /*const std::exception & exception*/)
    {
        // Don't throw exceptions in destructors !
        // std::cerr << exception.what() << std::endl;
    }
}

Semaphore::Semaphore() {
}

Semaphore::Semaphore(const Semaphore & orig) {
}

Semaphore::~Semaphore() {
}

bool Semaphore::init (int pshared ,
                      unsigned int value)
{
    int status = sem_init(&this->mtx , pshared , value);

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::destroy ()
{
    int status = sem_destroy(&this->mtx);

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

sem_t * Semaphore::open (std::string & name ,
                         int oflag)
{
    return (sem_open(name.c_str() , oflag));
}

bool Semaphore::close ()
{
    int status = sem_close(&this->mtx);

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::unlink (std::string & name)
{
    int status = sem_unlink(name.c_str());

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::wait (sem_t * sem)
{
    int status = sem_wait(sem);

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::timedwait (sem_t * sem ,
                           const struct timespec * abstime)
{
    int status = sem_timedwait(sem , abstime);

    if (status == FAILURE)
    {
        return (false);
    }

    return (true);
}

bool Semaphore::trywait (sem_t * sem)
{
    int status = sem_trywait(sem);

    if (status == FAILURE)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::post (sem_t * sem)
{
    int status = sem_post(sem);

    if (status == FAILURE)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

bool Semaphore::getvalue (sem_t * sem ,
                          int * sval)
{
    int status = sem_getvalue(sem , sval);

    if (status == -1)
    {
        return (FAILURE);
    }

    return (SUCCESS);
}

int Semaphore::take (int timeout) const
{

}

int Semaphore::give () const
{

}
