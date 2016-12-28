
// #http://jean-luc.massat.perso.luminy.univ-amu.fr/ens/docs/thread-sem.html
#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

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
    Semaphore(const Semaphore& orig);
    virtual ~Semaphore();

    /*!
     *  @brief Initialize semaphore object SEM to VALUE.  If PSHARED then share it
     *          with other processes.
     */
    int init (sem_t * sem , int pshared , unsigned int value);
    /*!
     *  @brief Free resources associated with semaphore object SEM.
     */
    int destroy (sem_t * sem);

    /*!
     *  @brief Open a named semaphore NAME with open flags OFLAG.
     */
    sem_t * open (const char * name , int oflag);

    /*!
     *  @brief Close descriptor for named semaphore SEM.
     */
    int close (sem_t *__sem);

    /*!
     *  @brief Remove named semaphore NAME.
     */
    int unlink (const char *name);

    /*!
     *  @brief Wait for SEM being posted.
     *          This function is a cancellation point and therefore not marked with
     */
    int wait (sem_t *sem);


    /*!
     *  @brief Similar to `sem_wait' but wait only until ABSTIME.
     *          This function is a cancellation point and therefore not marked with __THROW.
     */
    int timedwait (sem_t * sem , const struct timespec *abstime);

    /*!
     *  @brief Test whether SEM is posted.
     */
    int trywait (sem_t *sem);

    /*!
     *  @brief Post SEM.
     */
    int post (sem_t * sem);

    /*!
     * @brief Get current value of SEM and store it in *SVAL.
     */
    int getvalue (sem_t *sem , int *sval);

private:

};

#endif /* SEMAPHORE_HPP */
