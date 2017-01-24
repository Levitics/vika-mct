
#include <didactics/core/chronos/Clocker.hpp>

#define THOUSAND    1000.0
#define MILLION     1000000.0
#define BILLION     1000000000.0


/*
 * Create a new Timer object. The Timestamps are set to zero.
 */
Clocker::Clocker() :
    mStartTime(0.0) ,
    mStopTime(0.0) ,
    mIsRunning(false) ,
    mIsReset(true)
    , logger (log4cxx::Logger::getLogger(std::string("didactics.core.chrono.Clocker")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

/*
 * Create a new object and copy the Timestamps and the current state to this
 * object.
 */
Clocker::Clocker(const Clocker & orig) : Clocker() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mStartTime = orig.mStartTime;
    this->mStopTime = orig.mStopTime;

    this->mIsRunning = orig.mIsRunning;
    this->mIsReset = orig.mIsReset;
}

/*
 * There is nothing to do here.
 */
Clocker::~Clocker() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

/*
 * Assign the values to this object. If the objects are the same, then there is
 * nothing to do.
 */

Clocker & Clocker::operator = (const Clocker & rhs) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)   // the objects are the same
    {
        return *this;
    }

    this->mStartTime = rhs.mStartTime;
    this->mStopTime = rhs.mStopTime;

    this->mIsRunning = rhs.mIsRunning;
    this->mIsReset = rhs.mIsReset;

    return *this;
}

/*
 * There is no sense in comparing the different start and stop times. Therefore
 * only the duration of both objects is considered. A new Timestamp object is
 * returned containing the sum of the durations.
 */

const Timestamp Clocker::operator + (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp sum = this->getTime();
    sum += rhs.getTime();

    return sum;
}

/*
 * There is no sense in comparing the different start and stop times. Therefore
 * only the duration of both objects is considered. A new Timestamp object is
 * returned containing the difference of the durations.
 */

const Timestamp Clocker::operator - (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp difference = this->getTime();
    difference -= rhs.getTime();

    return difference;
}

/*
 * Checks if the objects are the same. If not, it checks if the difference of
 * the durations is small enough to consider them as equal. This value is
 * arbitrarily chosen. You can set this value with the macro HRTPP_ERROR_MARGIN.
 * The bigger the margin is, the more duration difference are regarded as equal.
 */

bool Clocker::operator == (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)    // the objects are the same
    {
        return true;
    }
    else
    {
        double difference = fabs( this->getTimeInSeconds() -
                                  rhs.getTimeInSeconds() );

        return difference <= HRTPP_ERROR_MARGIN;
    }
}

/*
 * If the objects are not equal, this returns true. It invertes the answer given
 * by the check for equality.
 */

bool Clocker::operator != (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return !(*this == rhs);
}

/*
 * This checks if this object is significantly larger, hence the error margin,
 * as the other object.
 */

bool Clocker::operator > (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // has to be bigger than zero
    double difference = this->getTimeInSeconds() - rhs.getTimeInSeconds();

    return (difference > HRTPP_ERROR_MARGIN and difference > 0.0);
}

/*
 * This checks if this object is significantly smaller, hence the error margin,
 * as the other object.
 */

bool Clocker::operator < (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // has to be smaller than zero
    double difference = this->getTimeInSeconds() - rhs.getTimeInSeconds();

    return (fabs(difference) > HRTPP_ERROR_MARGIN and difference < 0.0);
}

/*
 * This check returns true, if the object is either significantly larger or of
 * the same size within the margin of error.
 */

bool Clocker::operator >= (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (*this > rhs)or (*this == rhs);
}

/*
 * This check returns true, if the object is either significantly smaller or of
 * the same size within the margin of error.
 */

bool Clocker::operator <= (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (*this < rhs)or (*this == rhs);
}

/*
 * This method checks not only if the objects are the same and if the durations
 * are the same, but also if the starting and the ending times are the same.
 * With this you can check for duplicate objects. Since the Timestamps work
 * with integral types, there is no margin of error necessary.
 */

bool Clocker::isEqual (const Clocker & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)    // the objects are the same
    {
        return true;
    }

    if (*this == rhs and  // time range is equal
        this->mStartTime == rhs.mStartTime and      // start dates are equal
        this->mStopTime == rhs.mStopTime)        // stop dates are equal
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Starts the Timer if has not been run previously and is not running at the
 * moment.
 */

void Clocker::start () {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this->mIsReset and !this->mIsRunning)
    {
        this->mStartTime.setNow();

        this->mIsReset = false;
        this->mIsRunning = true;
    }
}

/*
 * Stops the Timer if two conditions are met. The Timer will not be changed if
 * it hasn't been started or if it is not running currently.
 */

void Clocker::stop () {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (!this->mIsReset and this->mIsRunning)
    {
        this->mStopTime.setNow();

        this->mIsRunning = false;
    }
}

/*
 * This resets the Timer. It does not regard the current state. The Timer will
 * be stopped afterwards and the Timestamps are zeroed.
 */

void Clocker::reset () {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mStartTime.set(0.0);
    this->mStopTime.set(0.0);

    this->mIsRunning = false;
    this->mIsReset = true;
}

/*
 * Getter for the state of running.
 */

bool Clocker::isRunning () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mIsRunning;
}

/*
 * Getter for the reset status.
 */

bool Clocker::isReset () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mIsReset;
}

/*
 * Calculates the duration between the start and the stop. If the Timer is
 * currently running, this calculates the duration between the start and the
 * moment you call this method. The Timer will not be stopped by this.
 */

const Timestamp Clocker::getTime () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if ( this->isRunning() )    // the timer is currently running
    {
        return Timestamp() - this->mStartTime;
    }

    Timestamp difference = this->mStopTime - this->mStartTime;

    return difference;
}

/*
 * This returns a double precission variable containing the duration this timer
 * was running. It returns the time as seconds.
 */

double Clocker::getTimeInSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp difference = this->getTime();

    return difference.getTime();  // this returns the time in seconds
}

/*
 * This returns a double precission variable containing the duration this timer
 * was running. It returns the time as milliseconds.
 */

double Clocker::getTimeInMilliSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp difference = this->getTime();

    double timeInMilliSeconds = difference.getSeconds() * THOUSAND
                                + difference.getNanoSeconds() / MILLION;

    return timeInMilliSeconds;
}

/*
 * This returns a double precission variable containing the duration this timer
 * was running. It returns the time as microseconds.
 */

double Clocker::getTimeInMicroSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp difference = this->getTime();

    double timeInMicroSeconds = difference.getSeconds() * MILLION
                                + difference.getNanoSeconds() / THOUSAND;

    return timeInMicroSeconds;
}

/*
 * This returns a double precission variable containing the duration this timer
 * was running. It returns the time as nanoseconds.
 */

double Clocker::getTimeInNanoSeconds () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Timestamp difference = this->getTime();

    double timeInNanoSeconds = difference.getSeconds() * BILLION
                               + difference.getNanoSeconds();

    return timeInNanoSeconds;
}

/*
 * This returns a double precission variable containing the frequency, which
 * results from the time the Timer was running. The unit is Hertz(Hz). If the
 * Timer was not run, the frequency returned will be 0.
 */

double Clocker::getFrequency () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    double time = this->getTimeInSeconds();
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
