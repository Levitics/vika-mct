
#ifndef CLOCKERSTATISTICS_HPP
#define CLOCKERSTATISTICS_HPP
#include <list>
#include <cmath>
#include <didactics/core/chronos/Timerseries.hpp>

/*!
 * @brief This class calculates statistical values of series of times.
 *
 * This class provides an easy interface for statistical evaluation of complete
 * series of times.
 *
 * @attention The calculation of the values is done while creating the object
 * or assigning and adding new values to the object. Be careful when you do
 * this, since this can take a long time.
 */
class ClockerStatistics
{
public:

    /*!
     * @brief Standard constructor
     *
     * This constructor creates an empty Statistic object and initializes all
     * values to 0.0
     */
    ClockerStatistics();

    /*!
     * @brief Construct a Statistic object from a series of doubles.
     *
     * This constructor creates an object from a list of doubles. These doubles
     * can come from a Timerseries an represent times. It then calculates the
     * basic statistical values from this list.
     *
     * The newly created object handles the series of doubles. It will delete
     * this series upon deletion.
     * @param series
     */
    ClockerStatistics(std::list<double> * series);

    /**
     * brief Constructs a deep copy from another Statistic object
     *
     * This method deep copies the values of the original object and calculates
     * the statistical values afterwards. Both objects are independend, since
     * all values are copied.
     * @param orig
     */
    ClockerStatistics(const ClockerStatistics & orig);

    /**
     * \brief Delete the object.
     *
     * This also deletes all series of elements within this object. Be careful
     * not to delete the series twice.
     */
    virtual ~ClockerStatistics();

    /**
     * \brief Creates a sliding mean over the data set.
     *
     * This calculates a sliding mean, i.e. a series of values with the mean of
     * the last meanWidth values. The meanWidth - 1 first values are set to 0.0,
     * because there are not enough values to calculate a correct mean for the
     * given width.
     * @param meanWidth
     */
    std::list<double> * calculateSlidingMean (int meanWidth) const;

    /**
     * \brief Assign the rhs objects values to this object.
     *
     * This object deletes its values before deep copying the values of rhs.
     * Afterwards both objects are independent. Beware of deleting the series of
     * values originally contained in this object since it will be deleted by
     * this operation.
     * @param rhs
     */
    ClockerStatistics & operator = (const ClockerStatistics & rhs);

    /**
     * \brief Adds all the values to this object and recalculate the statistical
     * values.
     *
     * This adds all the values to this objects series. The original list will
     * be deleted after all values are added to this objects series.
     * @param listToAdd
     */
    ClockerStatistics & operator += (const std::list<double> * listToAdd);

    /**
     * \brief Adds together both series of values and calculate the statistic
     *
     * This also does not modify the additional list of values. The original
     * list will be deleted after all values are added to this objects series.
     * @param listToAdd
     */
    const ClockerStatistics operator + (const std::list<double> * listToAdd);

    /**
     * \brief Compares both series for equal size.
     *
     * This only compares the size of the series.
     * @param rhs
     */
    bool operator == (const ClockerStatistics & rhs) const;

    /**
     * \brief Checks for inequality by using operator==.
     * @param rhs
     */
    bool operator != (const ClockerStatistics & rhs) const;

    /**
     * \brief Checks whether this object has more or equal values than rhs.
     * @param rhs
     */
    bool operator >= (const ClockerStatistics & rhs) const;

    /**
     * \brief Checks whether this object has less or equal values than rhs.
     * @param rhs
     */
    bool operator <= (const ClockerStatistics & rhs) const;

    /**
     * \brief Checks whether this object has more values than rhs.
     * @param rhs
     */
    bool operator > (const ClockerStatistics & rhs) const;

    /**
     * \brief Checks whether this object has less values than rhs.
     * @param rhs
     */
    bool operator < (const ClockerStatistics & rhs) const;

    /**
     * \brief Returns the minimum value.
     */
    double getMin () const;

    /**
     * \brief Returns the maximum value.
     */
    double getMax () const;

    /**
     * \brief Returns the mean of the series of values.
     */
    double getMean () const;

    /**
     * \brief Returns the median, i.e. the second quartile of the series of
     * values.
     */
    double getMedian () const;

    /**
     * \brief Returns the standard deviation of the values.
     */
    double getStddev () const;

    /**
     * \brief Returns the variance of the values.
     */
    double getVariance () const;

    /**
     * \brief Returns the first quartile of the series of values.
     */
    double getFirstQuartile () const;

    /**
     * \brief Returns the third quartile of the values.
     */
    double getThirdQuartile () const;

    /**
     * \brief Returns the number of elements stored in this object.
     */
    int getNumberOfElements () const;

private:

    void calculateStatistics ();
    double getPercentile (int percentile , const std::list<double> * sortedValues) const;

    std::list<double> * mSeries;
    std::list<double> * mSortedSeries;

    int mNumberOfElements;

    double mMean ,
           mMin ,
           mMax ,
           mStddev ,
           mVariance ,
           mMedian ,
           mFirstQuartile ,
           mThirdQuartile;
    /*!
     * @brief Class logger.
     */
    log4cxx::LoggerPtr logger;
};

#endif
