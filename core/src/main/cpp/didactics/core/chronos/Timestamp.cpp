
#include <didactics/core/chronos/Timestamp.hpp>

#define BILLION 1000000000.0

log4cxx::LoggerPtr Timestamp::logger = log4cxx::Logger::getLogger(std::string("didactics.core.chrono.Timestamp"));

/*!
 * @brief Create a new Timestamp and seed it with the current time.
 */
Timestamp::Timestamp()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    clock_gettime(CLOCK_REALTIME , &this->mTimestamp);
}

/*!
 *  @brief Create a new Timestamp and seed it with the given time.
 */
Timestamp::Timestamp(const timespec timestamp)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->set(timestamp.tv_sec , timestamp.tv_nsec);
}

/*!
 *  @brief Create a new Timestamp and seed it with the given time.
 */
Timestamp::Timestamp(const double offset)
    : Timestamp()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->set(offset);
}

/*!
 *  @brief Create a new Timestamp and seed it with the given time.
 */
Timestamp::Timestamp(const long secondsOffset ,
                     const long nanosecondsOffset)
    :    Timestamp()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->set(secondsOffset , nanosecondsOffset);
}

/*!
 *  @brief Copy the given Timestamp. This is a deep copy.
 */
Timestamp::Timestamp(const Timestamp & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mTimestamp = orig.mTimestamp;
}

/*!
 *  @brief Remove the object. Very empty since the time is saved in a stack object,
 *         which will be deleted automatically.
 */
Timestamp::~Timestamp() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

/*!
 *  @brief Get the structure saving the time. It is defined in the time.h header file.
 */

struct timespec Timestamp::getTimestamp () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mTimestamp;
}

/*!
 *  @brief Get the number of seconds as an signed long integer.
 */

long Timestamp::getSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mTimestamp.tv_sec;
}

/*!
 *  @brief Get the number of nanoseconds as an signed long integer.
 */

long Timestamp::getNanoSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mTimestamp.tv_nsec;
}

/*
 * Get the time in seconds as a double precission variable.
 */

double Timestamp::getTime () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    double time = this->getSeconds() + (this->getNanoSeconds() / BILLION);

    return time;
}

/*
 * Set the number of seconds.
 */

void Timestamp::setSeconds (const long seconds) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mTimestamp.tv_sec = seconds;
}

/*
 * Set the number of seconds. If there is an overflow, i.e. more than one
 * billion nanoseconds, the surplus will be saved in tv_nsec and the number of
 * seconds will be returned.
 */

long Timestamp::setNanoSeconds (const long nanoseconds) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    long seconds = lround( floor(nanoseconds / BILLION) );

    this->mTimestamp.tv_nsec = nanoseconds - (seconds * BILLION);

    return seconds;
}

/*
 * Sets the time accordng to the parameter. The overflow of the nanoseconds will
 * be added to seconds. Please regard, an overflow of the seconds part will not
 * be handled.
 */

void Timestamp::set (const long seconds ,
                     const long nanoseconds) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    long secondsOverflow = this->setNanoSeconds(nanoseconds);

    this->setSeconds(seconds + secondsOverflow);
}

/*
 * Converts the double to two integers and sets the time.
 */

void Timestamp::set (const double seconds) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    double fractpart , intpart;
    long sec , nanosec;

    // deviding the double in the integer part and the fractional part
    fractpart = modf(seconds , &intpart);

    // convert both parts to long variables
    sec = lround(intpart);
    nanosec = lround(fractpart * BILLION);

    // set time
    this->set(sec , nanosec);
}

/*
 * Assign a Timestamp object to another. This is actually a deep copy, since the
 * time stored is copied to the left-hand-side object. Both objects stay
 * independent.
 */

Timestamp & Timestamp::operator = (const Timestamp & rhs) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)    // objects are the same
    {
        return *this;
    }

    // set time to values of the given Timestamp
    this->set(rhs.getSeconds() , rhs.getNanoSeconds());

    return *this;
}

/*
 * Adds the given Timestamp to this one.
 */

Timestamp & Timestamp::operator += (const Timestamp & rhs) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->set(this->getSeconds() + rhs.getSeconds() ,
              this->getNanoSeconds() + rhs.getNanoSeconds());

    return *this;
}

/*
 * Subtracts the given Timestamp from this one.
 */

Timestamp & Timestamp::operator -= (const Timestamp & rhs) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->set(this->getSeconds() - rhs.getSeconds() ,
              this->getNanoSeconds() - rhs.getNanoSeconds());

    return *this;
}

/*
 * Creates a new Timestamp with the time value from this object and adds the
 * value from the other to it. The original objects are not changed.
 */

const Timestamp Timestamp::operator + (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp newTimestamp = *this;

    newTimestamp += rhs;

    return newTimestamp;
}

/*
 * Creates a new Timestamp with the time value from this object and subtracts
 * the value from the other to it. The original objects are not changed.
 */

const Timestamp Timestamp::operator - (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp newTimestamp = *this;

    newTimestamp -= rhs;

    return newTimestamp;
}

/*
 * Checks whether both objects are at the same memory location and if not, if
 * they hold the same values.
 */

bool Timestamp::operator == (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)   // both objects have the same address
    {
        return true;
    }

    // check for the time values
    if (this->getSeconds() == rhs.getSeconds() and
        this->getNanoSeconds() == rhs.getNanoSeconds())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Checks whether they are the same and returns the opposite result.
 */

bool Timestamp::operator != (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return !(*this == rhs);
}

/*
 * Checks whether this object is newer as the other or not. Newer means a higher
 * value for seconds and/or nanoseconds.
 */

bool Timestamp::operator > (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this->getSeconds() > rhs.getSeconds())
    {
        return true;
    }
    else
    if (this->getSeconds() == rhs.getSeconds() &&
        this->getNanoSeconds() > rhs.getNanoSeconds())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Checks if this object is older, i.e. smaller, than the other.
 */

bool Timestamp::operator < (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return rhs > *this;
}

/*
 * Checks if this object is newer or of the same age as the other.
 */

bool Timestamp::operator >= (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (*this == rhs)or (*this > rhs);
}

/*
 * Checks if this object is older or of the same age as the other.
 */

bool Timestamp::operator <= (const Timestamp & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (*this == rhs)or (*this < rhs);
}

/*
 * Sets the time values to the current time.
 */

void Timestamp::setNow () {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    clock_gettime(CLOCK_REALTIME , &this->mTimestamp);
}

/*
 * This returns a double precission variable containing the frequency, which
 * results from the timestamp. The unit is Hertz(Hz). If the time is zero, the
 * frequency returned will be 0.
 */

double Timestamp::getFrequency () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    double time = this->getTime();
    double frequency;

    if (time != 0.0)
    {
        frequency = 1.0 / time;
    }
    else
    {
        frequency = 0.0;
    }

    return frequency;
}
