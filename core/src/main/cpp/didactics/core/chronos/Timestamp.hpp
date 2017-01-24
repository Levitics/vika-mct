
#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP
#include <didactics/core/log/Logger.hpp>
#include <time.h>
#include <cmath>

/**
 * \brief This class stores times.
 *
 * It is used by the Timer class to store its start and stop times. It can also
 * be used to generate timestamps without the use of the Timer class.
 *
 * \attention This class is \b NOT reentrant and \b NOT thread-safe.
 */
class Timestamp
{
public:

    /**
     * \brief Default constructor.
     *
     * Creates a new timestamp with the time from epoch until creation.
     */
    Timestamp();

    /**
     * \brief Creates new Timestamp from existing time.
     *
     * Needs the time given by clock_gettime(). See man 3 clock_gettime.
     * @param timestamp
     */
    Timestamp(const struct timespec timestamp);

    /**
     * \brief Creates a new Timestamp and adds an offset
     *
     * The Timestamp is created with the actual time. The offset is interpreted
     * as seconds and is added to this time.
     * @param offset
     */
    Timestamp(const double offset);

    /**
     * \brief Creates a new Timestamp an adds an offset
     *
     * The Timestamp is created with the actual time. The seconds and
     * nanoseconds are added to this time.
     * @param secondsOffset
     * @param nanosecondsOffset
     */
    Timestamp(const long secondsOffset , const long nanosecondsOffset);

    /**
     * \brief Creates a new Timestamp from another one.
     *
     * This is actually a deep copy, so there are no shared variables.
     * @param orig
     */
    Timestamp(const Timestamp & orig);

    /**
     * \brief Standard destructor.
     */
    virtual ~Timestamp();

    /**
     * \brief Assign a Timestamp object to another.
     *
     * This is actually a deep copy. All variables and therefore the objects
     * stay independent.
     * @param rhs
     */
    Timestamp & operator = (const Timestamp & rhs);

    /**
     * \attention No overflow checking.
     * @param rhs
     */
    Timestamp & operator += (const Timestamp & rhs);

    /**
     * \attention No overflow checking.
     * @param rhs
     */
    Timestamp & operator -= (const Timestamp & rhs);

    /**
     * \attention No overflow checking.
     * @param rhs
     */
    const Timestamp operator + (const Timestamp & rhs) const;

    /**
     * \attention No overflow checking.
     * @param rhs
     */
    const Timestamp operator - (const Timestamp & rhs) const;

    /**
     * Checks if the both objects are the same or of the same age, i.e. have the
     * same values for seconds and nanoseconds.
     * @param rhs
     */
    bool operator == (const Timestamp & rhs) const;

    /**
     * Checks for inequality of both values.
     * @param rhs
     */
    bool operator != (const Timestamp & rhs) const;

    /**
     * Checks whether this object is newer as the other.
     * @param rhs
     */
    bool operator > (const Timestamp & rhs) const;

    /**
     * Checks whether this object is newer or of the same age as the other.
     * @param rhs
     */
    bool operator >= (const Timestamp & rhs) const;

    /**
     * Checks whether this object is older as the other.
     * @param rhs
     */
    bool operator < (const Timestamp & rhs) const;

    /**
     * Checks whether this object is older or of the same age as the other.
     * @param rhs
     */
    bool operator <= (const Timestamp & rhs) const;

    /**
     * Returns the structure holding the time. It is defined in the time.h
     * header file.
     */
    struct timespec getTimestamp () const;

    /**
     * Returning only the seconds part of the time.
     */
    long getSeconds () const;

    /**
     * Returns only the nanoseconds part of the time.
     */
    long getNanoSeconds () const;

    /**
     * Returns the time in seconds as a double.
     *
     * \attention There is a possible loss of accuracy due to the precission of
     * double variables.
     */
    double getTime () const;

    /**
     * Sets the time to the given values
     *
     * \attention No overflow checking for the seconds.
     * @param seconds
     * @param nanoseconds
     */
    void set (const long seconds , const long nanoseconds);

    /**
     * Sets the time to the given value. The parameter will be interpreted as
     * seconds
     *
     * \attention No overflow checking for the seconds.
     * @param seconds
     */
    void set (const double seconds);

    /**
     * Sets the seconds part of the time.
     *
     * \attention No overflow checking.
     * @param seconds
     */
    void setSeconds (const long seconds);

    /**
     * Sets the nanoseconds part of the time. Overflow will be returned as
     * seconds. To ensure the correct time, please update the seconds part
     * accordingly.
     *
     * @param nanoseconds
     */
    long setNanoSeconds (const long nanoseconds);

    /**
     * Sets the time to the current time.
     */
    void setNow ();

    /**
     * \brief Returns the frequency resulting from the Timestamp.
     *
     * This returns 1/s. Therefore its unit is Hertz(Hz). Returns 0, if the
     * Timestamp is 0.
     */
    double getFrequency () const;

private:

    struct timespec mTimestamp;
    /*!
     * @brief Class logger.
     */
    static log4cxx::LoggerPtr logger;
};

#endif
