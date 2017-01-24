
#ifndef HIGHRESOLUTIONTIMER_HPP
#define HIGHRESOLUTIONTIMER_HPP
/*!
 * @file HighResolutionWatch.hpp
 * @brief Header file for @link HighResolutionWatch @endlink class.
 */
#include <stdlib.h>
#include <stdio.h>
// #include <posix-timers.h> //usr/src/linux-headers-4.8.0-27/include/linux/posix-timers.h
// #include <timers.h>
#include <time.h>
#include <math.h>
#include <string>
// #include <strstream>


/*!
 * \brief Watch with a nano second of time resolution.
 *
 * The high resolution watch is meant to provide time
 * tools dealing with up to a nanosecond of resolution.
 *
 * It wraps the \c clockLib and \c ansiTime libraries in order
 * to consistently use the functions they provide.
 *
 * The main asset of using this wrapper is to reduce the risks induced
 * by the tricky activity of measuring time.
 *
 * The main pitfalls come from the limited capacity of data types
 * which induce, sooner or later, a value rollover forcing to keep track
 * of the latter during application uptime. Because there is no other choice
 * but to store the rollover counts in a limited capacity typed variable,
 * the rollover counter itself requires a rollover counter and so on until
 * a total capacity allowing at least to count nanoseconds in a year is
 * attained (ie: \c 31536000000000000 nanoseconds overruns a \c long \c double).
 *
 * The only reasonnable way to keep track of running time is to count
 * CPU clock ticks. Taken that correctly handling data rollover requires
 * quite a complex data structure, it is best to rely on the existing
 * \c clockLib implementation which defines and allows to request a structure
 * reflecting clock tick counts as calendar like data allowing to consider
 * time and date at once.
 *
 * The \c clockLib defines the \c timespec structure. It encapsulates the \c time_t structure
 * defined by the \c ansiTime library which deals with up to a second of time resolution.
 * The \c time_t structure is encapsulated in the \c timespec structure along with a
 * counter of nanoseconds in seconds.
 *
 * The main objective of this object is to provide means to compute differences between
 * successive times returned by the system library taking into account both its low and high
 * resolution parts.
 */
class HighResolutionTimer
{
public:

    /*!
     * \defgroup WatchInstance HighResolutionWatch instance members
     * @{
     */
    HighResolutionTimer();
    HighResolutionTimer(const HighResolutionTimer & orig);
    virtual ~HighResolutionTimer();
    /*!
     * @}
     * \defgroup TimeInfo Time information members
     * @{
     */
    timespec getClockResolution ();
    time_t getSeconds ();
    long getNanoSeconds ();
    timespec getTime ();
    /*!
     * @}
     * \defgroup TimeTool Time tools members
     * @{
     */
    std::string formatToString (const timespec);
    double diffSeconds (const timespec , const timespec);
    long diffNanoSeconds (const timespec , const timespec);
    double diffTime (const timespec , const timespec);
    /*!
     * @}
     * \defgroup TimeMeasure Time measurement members
     * @{
     */
    void init ();
    void reset ();
    double elapsedSeconds ();
    long elapsedNanoSeconds ();
    double elapsedTime ();

private:

    /*!
     * \brief The last time stored.
     */
    timespec lastTime;
    /*!
     * @}
     */

};

#endif
