
// #http://jean-luc.massat.perso.luminy.univ-amu.fr/ens/docs/thread-sem.html
#ifndef DIDACTICS_CORE_OSAL_SEMAPHORE_HPP
#define DIDACTICS_CORE_OSAL_SEMAPHORE_HPP
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string>
#include <didactics/core/errorhandling/ErrnoMapper.hpp>
#include <didactics/core/Defines.hpp>

class Semaphore
{
public:

    /*!
     * @brief Automatically take/give semaphore.
     */
    class Auto
    {
public:

        /*!
         * @brief Take semaphore.
         * @param sem Semaphore to take and give automatically.
         * @param timeout Take timeout.
         * @throw std::runtime_error When semaphore could not be taken.
         */
        Auto(const Semaphore & sem , int timeout = -1);
        /*!
         * @brief Give semaphore.
         */
        ~Auto();

private:

        /*!
         * @brief Semaphore reference.
         */
        const Semaphore & semaphore;
    };

    Semaphore();
    Semaphore(const Semaphore & orig);
    virtual ~Semaphore();

    /*!
     *  @brief Initialize semaphore object SEM to VALUE.  If PSHARED then share it
     *          with other processes.
     */
    bool init (int pshared = 0 , unsigned int value = 1);
    /*!
     *  @brief Free resources associated with semaphore object SEM.
     */
    bool destroy ();

    /*!
     *  @brief Open a named semaphore NAME with open flags OFLAG.
     */
    sem_t * open (std::string & name , int oflag);

    /*!
     *  @brief Close descriptor for named semaphore SEM.
     */
    bool close ();

    /*!
     *  @brief Remove named semaphore NAME.
     */
    bool unlink (std::string &name);

    /*!
     *  @brief Wait for SEM being posted.
     *          This function is a cancellation point and therefore not marked with
     */
    bool wait (sem_t * sem);
    /*!
     *  @brief Similar to `sem_wait' but wait only until ABSTIME.
     *          This function is a cancellation point and therefore not marked with __THROW.
     */
    bool timedwait (sem_t * sem , const struct timespec * abstime);

    /*!
     *  @brief Test whether SEM is posted.
     */
    bool trywait (sem_t * sem);

    /*!
     *  @brief Post SEM.
     */
    bool post (sem_t * sem);

    /*!
     * @brief Get current value of SEM and store it in *SVAL.
     */
    bool getvalue (sem_t * sem , int * sval);
    int take (int timeout = WAIT_FOREVER) const;
    int give () const;

private:

    sem_t mtx;
};

#endif /* SEMAPHORE_HPP */
