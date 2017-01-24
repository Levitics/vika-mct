
#include <didactics/core/chronos/ClockerStatistics.hpp>


ClockerStatistics::ClockerStatistics()
    : logger (log4cxx::Logger::getLogger(std::string("didactics.core.chrono.ClockerStatistics")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mSeries = nullptr;
    this->mSortedSeries = nullptr;
    this->mMean = 0;
    this->mMin = 0;
    this->mMax = 0;
    this->mStddev = 0;
    this->mVariance = 0;
    this->mNumberOfElements = 0;
    this->mMedian = 0;
    this->mFirstQuartile = 0;
    this->mThirdQuartile = 0;
}

/*!
 * @brief This creates an empty object with the standard constructor, copies the
 *          elements of the list of values to this objects series and calculates the
 *          statistical values. This could take a long time.
 */
ClockerStatistics::ClockerStatistics(std::list<double> * series)
    : ClockerStatistics()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mSeries = series;
    this->mSortedSeries = nullptr;
    this->mMean = 0;
    this->mMin = 0;
    this->mMax = 0;
    this->mStddev = 0;
    this->mVariance = 0;
    this->mNumberOfElements = 0;
    this->mMedian = 0;
    this->mFirstQuartile = 0;
    this->mThirdQuartile = 0;
    this->calculateStatistics();
}

/*
 * This also creates a new empty object and copies all values from the original
 * object to this. This is a deep copy, so the objects remain independent. If
 * the original object has already sorted the series, this object do not have to
 * re-sort it.
 */
ClockerStatistics::ClockerStatistics(const ClockerStatistics & orig)
    : ClockerStatistics()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->mSeries = new std::list<double>( *(orig.mSeries) );
    this->mSortedSeries = new std::list<double>( *(orig.mSortedSeries) );

    this->calculateStatistics();
}

/*
 * This destructor deletes all lists in this object. If the list is still used
 * outside of this object, this can be a problem. Please ensure, you don't use
 * these series outside of the object.
 */
ClockerStatistics::~ClockerStatistics() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    /*delete all values and set the pointer to nullptr*/
    if (this->mSeries != nullptr)
    {
        delete this->mSeries;
        this->mSeries = nullptr;
    }

    /*delete all values and set the pointer to nullptr*/
    if (this->mSortedSeries != nullptr)
    {
        delete this->mSortedSeries;
        this->mSortedSeries = nullptr;
    }
}

/*
 * This calculates an arbitrary percentile from the sorted list of values. This
 * method does not change anything outside.
 */

double ClockerStatistics::getPercentile (int percentile ,
                                         const std::list<double> * sortedValues) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this->mSeries->size() <= 1)   // this series is to small
    {
        return 0;
    }

    double position;
    bool even;

    if (percentile > 100 or percentile < 0)    // wrong parameter
    {
        return 0;
    }
    else
    {
        /*calculate the position in the list*/
        double pos = percentile / 100.0 * (this->mNumberOfElements);

        /*check if pos points exactly to an element*/
        if ( modf(pos , &position) == 0.0 )
        {
            even = true;
        }
        else
        {
            even = false;
        }
    }

    std::list<double>::const_iterator valIter = sortedValues->cbegin();
    double percentileValue = 0;

    /*move to the right element*/
    for (int i = 0; i < position - 1; ++i)
    {
        ++valIter;
    }

    if (even)   // percentile lies between to elements
    {   /*calculate mean of these to elements*/
        percentileValue += *valIter / 2.0;
        ++valIter;
        percentileValue += *valIter / 2.0;
    }
    else      // use this exact element
    {
        ++valIter;
        percentileValue = *valIter;
    }

    return percentileValue;
}

/*
 * This method does the heavy calculation and sorting. Herein all statistical
 * values are calculated. Sorting is only done, if the pointer to the sorted
 * list is set to nullptr.
 */

void ClockerStatistics::calculateStatistics ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    /*set the number to the size*/
    this->mNumberOfElements = this->mSeries->size();

    /*initialize the minimum and maximum values to the first*/
    this->mMin = *(this->mSeries->begin());
    this->mMax = this->mMin;

    /*go through all elements*/
    for (double element: *(this->mSeries))
    {
        /*set mMin or mMax to the current if they need to change*/
        if (element > this->mMax)
        {
            this->mMax = element;
        }
        else
        if (element < this->mMin)
        {
            this->mMin = element;
        }

        /*sum all elements*/
        this->mMean += element;
    }

    /*devide by the number of elements to get the mean value*/
    this->mMean /= this->mNumberOfElements;

    /*calculate the variance*/
    for (double element: *(this->mSeries))
    {
        double difference = element - this->mMean;

        /*sum all squares of differences*/
        this->mVariance += difference * difference;
    }

    /*if this series is to small*/
    if (this->mNumberOfElements <= 1)   // to small
    {
        this->mVariance = 0.0;
    }
    else
    {
        /*calculate the variance by deviding by N-1*/
        this->mVariance /= this->mNumberOfElements - 1;
    }

    /*calculate standard deviation from variance*/
    this->mStddev = sqrt(this->mVariance);

    /*if there is no sorted list, copy and sort it*/
    if (this->mSortedSeries == nullptr)
    {
        this->mSortedSeries = new std::list<double>(*(this->mSeries));
        this->mSortedSeries->sort();
    }

    /*calculate the percentiles 25, 50 and 75*/
    this->mFirstQuartile = this->getPercentile(25 , this->mSortedSeries);
    this->mMedian = this->getPercentile(50 , this->mSortedSeries);
    this->mThirdQuartile = this->getPercentile(75 , this->mSortedSeries);
}

/*
 * This method calculates a sliding mean. Therefore for every value a mean is
 * calculated from the meanWidth-1-th value upto this value. If the number of
 * values is to small to calculate a mean, i.e. for the first meanWidth-1
 * values, 0.0 is added to the list.
 */
std::list<double> * ClockerStatistics::calculateSlidingMean (int meanWidth) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    std::list<double> * slidingMean = new std::list<double>();

    double currentMean = 0;
    /*create to boundaries to calculate the mean within*/
    std::list<double>::iterator upperValueIter = this->mSeries->begin();
    std::list<double>::iterator lowerValueIter = this->mSeries->begin();

    /*go through all elements*/
    for (int i = 0; i < this->mNumberOfElements; ++i)
    {

        /*calculate the actual mean*/
        currentMean += *upperValueIter / meanWidth;

        /*move upper bound to next element*/
        ++upperValueIter;

        /*check if the distance between both boundaries has reached meanWidth*/
        if (i < (meanWidth - 1))  // not yet reached
        {
            slidingMean->push_back(0.0);
            continue;
        }

        /*this mean value is valid since it contains enough values*/
        slidingMean->push_back(currentMean);

        /*check whether the difference between both boundaries is to big*/
        if (i >= meanWidth)   // the difference is to big
        {   /*reduce the mean by the lower bound*/
            currentMean -= *lowerValueIter / meanWidth;
        }

        /*move the lower bound forwards*/
        ++lowerValueIter;
    }

    return slidingMean;
}

/*
 * This returns the minimum value.
 */

double ClockerStatistics::getMin () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mMin;
}

/*
 * This returns the maximum value.
 */

double ClockerStatistics::getMax () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mMax;
}

/*
 * This returns the mean value.
 */

double ClockerStatistics::getMean () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mMean;
}

/*!
 * This returns the number of values.
 */

int ClockerStatistics::getNumberOfElements () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mNumberOfElements;
}

/*!
 * @brief This returns the standard deviation of the values.
 */

double ClockerStatistics::getStddev () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mStddev;
}

/*!
 * @brief  This returns the variance of the values.
 */

double ClockerStatistics::getVariance () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mVariance;
}

/*!
 * @brief  This returns the median value.
 */

double ClockerStatistics::getMedian () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mMedian;
}

/*!
 * @brief This returns the value of the first quartile.
 */

double ClockerStatistics::getFirstQuartile () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mFirstQuartile;
}

/*!
 * @brief  This returns the value of the third quartile.
 */

double ClockerStatistics::getThirdQuartile () const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mThirdQuartile;
}

/*!
 * @brief  This assigns the values of the rhs object to this object. Therefore this
 *         object first deletes every value it contains. Afterwards the statistical
 *         values are calculated.
 */

ClockerStatistics & ClockerStatistics::operator = (const ClockerStatistics & rhs) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (this == &rhs)   // the objects are the same
    {
        return *this;
    }

    /*delete the old values of this object*/
    if (this->mSeries != nullptr)
    {
        delete this->mSeries;
        this->mSeries = nullptr;
    }

    if (this->mSortedSeries != nullptr)
    {
        delete this->mSortedSeries;
        this->mSortedSeries = nullptr;
    }

    /*copy and assign the new values*/
    this->mSeries = new std::list<double>(*(rhs.mSeries));
    this->mSortedSeries = new std::list<double>(*(rhs.mSortedSeries));

    /*calculate the new statistics*/
    this->calculateStatistics();

    return *this;
}

/*!
 * @brief  This adds a list of values to this object. The statistical values are re-
 *         calculated afterwards.
 */

ClockerStatistics & ClockerStatistics::operator += (const std::list<double> * listToAdd) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    /*add all new elements to this series*/
    for (double element: *(listToAdd))
    {
        this->mSeries->push_back(element);
    }

    /*delete the old sorted list*/
    if (this->mSortedSeries != nullptr)
    {
        delete this->mSortedSeries;
        this->mSortedSeries = nullptr;
    }

    /*re-calculate the statistical values.*/
    this->calculateStatistics();

    /*delete the input list*/
    delete listToAdd;
    listToAdd = nullptr;

    return *this;
}

/*!
 * @brief This adds a list of values to a new object. The statistical values are re-
 *        calculated afterwards.
 */

const ClockerStatistics ClockerStatistics::operator + (const std::list<double> * listToAdd) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    ClockerStatistics newStatistic = *this;

    /*add the input list to the new Statistic object. This deletes the list.*/
    newStatistic += listToAdd;

    return newStatistic;
}

/*!
 * @brief  Checks for the same size of the series of values.
 */

bool ClockerStatistics::operator == (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mNumberOfElements == rhs.mNumberOfElements;
}

/*!
 * @brief  Checks whether the sizes differ.
 */

bool ClockerStatistics::operator != (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return !(*this == rhs);
}

/*!
 * @brief  Checks if this object holds more values as rhs.
 */

bool ClockerStatistics::operator > (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mNumberOfElements > rhs.mNumberOfElements;
}

/*!
 * @brief Checks if rhs holds more values as this object.
 */

bool ClockerStatistics::operator < (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return rhs > *this;
}

/*!
 * @brief Checks if this object holds more or the same amount of values as rhs.
 */

bool ClockerStatistics::operator >= (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return this->mNumberOfElements >= rhs.mNumberOfElements;
}

/*!
 * @brief Checks if rhs holds more or the same amount of values as this object.
 */

bool ClockerStatistics::operator <= (const ClockerStatistics & rhs) const {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return rhs >= *this;
}
