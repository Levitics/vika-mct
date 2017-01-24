
#include <didactics/core/chronos/Timerseries.hpp>
#include <iostream>

/*
 * Creates a new object and stores the timers on the heap.
 */
Timerseries::Timerseries() {
    this->mTimer = new std::list<Clocker *>();
}

/*
 * This copy-constructor uses the copy-constructor of the standard libraries
 * container to make a deep copy of all elements.
 */
Timerseries::Timerseries(const Timerseries & orig) {
    this->mTimer = new std::list<Clocker *>();

    // for every Timer in origs series, push a copy to this list
    for (const Clocker * timer: *(orig.mTimer))
    {
        this->mTimer->push_back(new Clocker(*timer));
    }
}

/*
 * This frees a lot of memory. Mind that all elements are destroyed, by calling
 * their destructor.
 */
Timerseries::~Timerseries() {
    for (Clocker * timer: *(this->mTimer))
    {
        delete timer;
        timer = nullptr;
    }

    delete this->mTimer;
}

/*
 * This assigns a copy from the rhs series to this series. All Timer stored in
 * this series are destroyed and freed.
 */

Timerseries & Timerseries::operator = (const Timerseries & rhs) {
    if (this == &rhs)    // the objects are the same
    {
        return *this;
    }

    // delete the existing Timer
    for (Clocker * timer: *(this->mTimer))
    {
        delete timer;
        timer = nullptr;
    }

    // delete the list holding the Timer pointer
    delete this->mTimer;

    // create a new list
    this->mTimer = new std::list<Clocker *>();

    // make a copy for every Timer in the rhs series and store it in this series
    for (const Clocker * timer: *(rhs.mTimer))
    {
        this->mTimer->push_back(new Clocker(*timer));
    }

    return *this;
}

/*
 * Adds copies from all Timer in rhs to this series. This does not respect
 * duplicates. If a Timer was duplicated and added to both lists, it will be
 * twize in this series.
 */

Timerseries & Timerseries::operator += (const Timerseries & rhs) {
    // make a copy for every Timer in the rhs series and store it in this series
    for (const Clocker * timer: *(rhs.mTimer))
    {
        this->mTimer->push_back(new Clocker(*timer));
    }

    return *this;
}

/*
 * Adds the given timer to this series. It will not be copied. If the series is
 * destroyed, it will destroy this timer as well.
 */

Timerseries & Timerseries::operator += (Clocker * timerToAdd) {
    this->mTimer->push_back( timerToAdd );

    return *this;
}

/*
 * Removes every element from this series, that is present in rhs. Since every
 * combination has to be checked within the algorithm used at the moment, this
 * method takes O(n^2) time.
 */

Timerseries & Timerseries::operator -= (const Timerseries & rhs) {
    std::list<Clocker *>::iterator rhsIt , thisIt;
    // list of Timers which should be deleted from this series
    std::list<Clocker *> * toErase = new std::list<Clocker *>();

    // check for every combination of two Timers in both series
    for (rhsIt = rhs.mTimer->begin(); rhsIt != rhs.mTimer->end(); ++rhsIt)
    {
        for (thisIt = this->mTimer->begin();
             thisIt != this->mTimer->end(); ++thisIt)
        {

            // reference Timer for simplicity
            // iterator -*-> Timer* -*-> Timer
            Clocker & rhsTimer = **rhsIt;
            Clocker & thisTimer = **thisIt;

            // if the Timers are equal, mark them to be deleted
            if (thisTimer.isEqual(rhsTimer))
            {
                toErase->push_back(*thisIt);
            }
        }
    }

    // delete every Timer that has been marked
    for (Clocker * timer: *toErase)
    {
        // remove Timer from list
        this->mTimer->remove(timer);
        // free memory for the Timer
        delete timer;
    }

    // free memory for the list of Timer which were to be deleted
    delete toErase;
    return *this;
}

/*
 * This removes a timer and all its copies from this list, by encapsulating it
 * in a new list and use the method to remove a complete list.
 */

Timerseries & Timerseries::operator -= (const Clocker & timerToRemove) {
    /*new list to encapsulate the timer*/
    Timerseries timersToRemove;

    /*add a copy of the timer to the list*/
    timersToRemove += new Clocker(timerToRemove);

    /*remove the timer from this objects list of timers*/
    *this -= timersToRemove;

    return *this;
}

/*
 * Add all Timers of both series to a new series and return this.
 */

const Timerseries Timerseries::operator + (const Timerseries & rhs) {
    Timerseries newTimerseries(*this);

    newTimerseries += rhs;

    return newTimerseries;
}

/*
 * Add the given timer to this series. This series handles the timer from then
 * on. If the series is destroyed, it will destroy this timer as well.
 */

const Timerseries Timerseries::operator + (Clocker * timerToAdd) {
    Timerseries newTimerseries(*this);

    newTimerseries += timerToAdd;

    return newTimerseries;
}

/*
 * Creates a new series, which holds only the elements which are in this series
 * and not in rhs.
 */

const Timerseries Timerseries::operator - (const Timerseries & rhs) {
    Timerseries newTimerseries(*this);

    newTimerseries -= rhs;

    return newTimerseries;
}

/*
 * Removes the given Timer and all its copies from the list.
 */

const Timerseries Timerseries::operator - (const Clocker & timerToRemove) {
    Timerseries newTimerseries(*this);

    newTimerseries -= timerToRemove;

    return newTimerseries;
}

/*
 * Checks whether the series are the same object or if they have the same size,
 * whether all elements are the same. Therefore if the have the same size and
 * the difference contains no elements, the both series are the same.
 */

bool Timerseries::operator == (const Timerseries & rhs)  const {
    // if the objects are the same, this shoul be true
    if (this == &rhs)
    {
        return true;
    }

    // if the size differs, they could not be equal
    if (this->getSize() == rhs.getSize())
    {
        Timerseries newTimerseries(*this);
        newTimerseries -= rhs;

        // if the are of the same size and a subtraction leaves no elements,
        // all elements are equally present in both series
        if (newTimerseries.getSize() == 0)
        {
            return true;
        }
    }

    return false;
}

/*
 * Uses the check for equality to answer the question for inequaliy.
 */

bool Timerseries::operator != (const Timerseries & rhs) const {
    return !(*this == rhs);
}

/*
 * This series is a true super-set if all elements of rhs are in this series,
 * but there is at least one element more in this series than in rhs.
 */

bool Timerseries::operator > (const Timerseries & rhs)  const {
    // if the objects are the same, this could not be a true super-set of rhs
    if (this == &rhs)   // the objects are the same
    {
        return false;
    }

    // check if there is at least one element mor in this series than in rhs
    if (this->getSize() > rhs.getSize())
    {

        // if this is a super-set and bigger than rhs, this is a true super-set
        if (*this >= rhs)
        {
            return true;
        }
    }

    return false;
}

/*
 * Check if rhs is a true super-set of this series to know if this series is a
 * true sub-set ob rhs.
 */

bool Timerseries::operator < (const Timerseries & rhs)  const {
    return rhs > *this;
}

/*
 * Checks if this series is a super-set of rhs. It first checks for the address
 * and the size of the series, to prevent unnecessary checks of all elements.
 * This series is a super-set, if this series is bigger or of equal size as rhs
 * and if the number of equal elements is equal to rhs. Therefore at lease each
 * element of rhs is in this series.
 */

bool Timerseries::operator >= (const Timerseries & rhs)  const {
    // if both series are the same, this series is a super-set of rhs
    if (this == &rhs)    // both objects are the same
    {
        return true;
    }

    // if this series is smaller than rhs, it could not be a super-set of rhs
    if (this->getSize() < rhs.getSize())
    {
        return false;
    }

    std::list<Clocker *>::iterator rhsIt , thisIt;
    int countEquals = 0;

    // check every possible combination of elements of both lists
    for (rhsIt = rhs.mTimer->begin(); rhsIt != rhs.mTimer->end(); ++rhsIt)
    {
        for (thisIt = this->mTimer->begin();
             thisIt != this->mTimer->end(); ++thisIt)
        {

            // reference Timer for simplicity
            // iterator -*-> Timer* -*-> Timer
            Clocker & rhsTimer = **rhsIt;
            Clocker & thisTimer = **thisIt;

            // if the Timer are the same, increment the number of equal elements
            if (rhsTimer.isEqual(thisTimer))
            {
                countEquals++;
            }
        }
    }

    // check if all elements of rhs are in this series
    if (countEquals == rhs.getSize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Check if rhs is a super-set of this series to know if this series is a
 * sub-set ob rhs.
 */

bool Timerseries::operator <= (const Timerseries & rhs)  const {
    return rhs >= *this;
}

/*
 * Add a new and existing Timer to this series. This method is now deprecated.
 * You can use operator+= and operator+ instead;
 */

void Timerseries::addTimer (Clocker * newTimer) {
    this->mTimer->push_back(newTimer);
}

/*
 * Returns a pointer to the internal container. This SHOULD NOT be used from
 * outside of this class.
 */
const std::list<Clocker *> & Timerseries::getTimer () const {
    return *(this->mTimer);
}

/*
 * Returns a copied list of all Timer in this series. This could take a lot of
 * memory and time since all the elements are copied sequentially.
 */
std::list<Clocker *> * Timerseries::getAllTimer () const {
    std::list<Clocker *> * allTimer = new std::list<Clocker *>();

    // for every Timer in this series, push a copy to the new list
    for (const Clocker * timer : *(this->mTimer))
    {
        allTimer->push_back(new Clocker(*timer));
    }

    return allTimer;
}

/*
 * Runs through all Timer and stops the ones, running at the moment. If a Timer
 * is not running, nothig happend to it.
 */

void Timerseries::stopAllTimer () const {
    for (Clocker * timer: *(this->mTimer))
    {
        timer->stop();
    }
}

/*
 * This destroys all elements and creates a new container for a new series of
 * Timer. Beware, since this can render pointer invalid.
 */

void Timerseries::clear () {
    for (Clocker * timer: *(this->mTimer))
    {
        delete timer;
        timer = nullptr;
    }

    delete this->mTimer;

    this->mTimer = new std::list<Clocker *>();
}

/*
 * This method traverses the container and removes the given Timer from it. If
 * this Timer is not in the series, nothing happens.
 */

void Timerseries::removeTimer (Clocker * const toDelete) {
    this->mTimer->remove(toDelete);
}

/*
 * This adds a new blank Timer to the series.
 */

Clocker * Timerseries::newTimer () {
    Clocker * newTimer = new Clocker();

    this->mTimer->push_back(newTimer);

    return newTimer;
}

/*
 * This adds a new Timer to the series and afterwards starts it. This ensures,
 * that the time measured does not contain the time needed to add the Timer to
 * the series.
 */

Clocker * Timerseries::newStartedTimer () {
    Clocker * newTimer = this->newTimer();

    newTimer->start();

    return newTimer;
}

/*
 * This returns a Timestamp for every timer in the series. The timestamp holds
 * the duration the timer ran.
 */
std::list<Timestamp> * Timerseries::getTimes () const {
    std::list<Timestamp> * times = new std::list<Timestamp>();

    for (const Clocker * timer: *(this->mTimer))
    {
        times->push_back(timer->getTime());
    }

    return times;
}

/*
 * This returns a double variable containing the time for each Timer in seconds.
 * Due to the limited precission of the variable type, this can be inaccurate
 * in the last digits.
 */
std::list<double> * Timerseries::getTimesInSeconds () const {
    std::list<double> * times = new std::list<double>();

    for (const Clocker * timer: *(this->mTimer))
    {
        times->push_back(timer->getTimeInSeconds());
    }

    return times;
}

/*
 * This returns a double variable containing the time for each Timer in
 * milliseconds. Due to the limited precission of the variable type, this can be
 * inaccurate in the last digits.
 */
std::list<double> * Timerseries::getTimesInMilliSeconds () const {
    std::list<double> * times = new std::list<double>();

    for (const Clocker * timer: *(this->mTimer))
    {
        times->push_back(timer->getTimeInMilliSeconds());
    }

    return times;
}

/*
 * This returns a double variable containing the time for each Timer in
 * microseconds. Due to the limited precission of the variable type, this can be
 * inaccurate in the last digits.
 */
std::list<double> * Timerseries::getTimesInMicroSeconds () const {
    std::list<double> * times = new std::list<double>();

    for (const Clocker * timer: *(this->mTimer))
    {
        times->push_back(timer->getTimeInMicroSeconds());
    }

    return times;
}

/*
 * This returns a double variable containing the time for each Timer in
 * nanoseconds. Due to the limited precission of the variable type, this can be
 * inaccurate in the last digits.
 */
std::list<double> * Timerseries::getTimesInNanoSeconds () const {
    std::list<double> * times = new std::list<double>();

    for (const Clocker * timer: *(this->mTimer))
    {
        times->push_back(timer->getTimeInNanoSeconds());
    }

    return times;
}

/*
 * This returns a double variable containing the frequency measured for each
 * timer. Due to the limited precission of the variable type, this can be
 * inaccurate in the last digits.
 */
std::list<double> * Timerseries::getFrequencies () const {
    std::list<double> * frequencies = new std::list<double>();

    for (const Clocker * timer: *(this->mTimer))
    {
        frequencies->push_back(timer->getFrequency());
    }

    return frequencies;
}

/*
 * Returns the number of Timer in this series.
 */

int Timerseries::getSize () const {
    return this->mTimer->size();
}
