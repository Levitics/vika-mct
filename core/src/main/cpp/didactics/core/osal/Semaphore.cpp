
#include <didactics/core/osal/Semaphore.hpp>

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

Semaphore::Semaphore(const Semaphore& orig) {
}

Semaphore::~Semaphore() {
}
