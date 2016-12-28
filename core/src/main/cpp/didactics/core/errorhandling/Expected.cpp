
#include <didactics/core/errorhandling/Expected.hpp>

template <typename T>
Expected<T>::Expected()
{
}

template <typename T>
Expected<T>::~Expected()
{
}

template <typename T>
Expected<T>::Expected(const T& rhs)
    : ham(rhs)
    , gotHam(true)
{

}

template <typename T>
Expected<T>::Expected(T&& rhs)
    : ham(std::move(rhs))
    , gotHam(true)
{
}

template <typename T>
Expected<T>::Expected(const Expected& rhs)
    : gotHam(rhs.gotHam)
{
    if (gotHam)
    {
        new (&ham)T(rhs.ham);
    }
    else
    {
        new (&spam) std::exception_ptr(rhs.spam);
    }
}

template <typename T>
Expected<T>::Expected(Expected&& rhs)
    : gotHam(rhs.gotHam)
{
    if (gotHam)
    {
        new (&ham)T(std::move(rhs.ham));
    }
    else
    {
        new (&spam) std::exception_ptr(std::move(rhs.spam));
    }
}

template <typename T>
void Expected<T>::swap (Expected& rhs)
{
    if (gotHam)
    {
        if (rhs.gotHam)
        {
            using std::swap;
            swap(ham , rhs.ham);
        }
        else
        {
            auto t = std::move(rhs.spam);
            new (&rhs.ham)T(std::move(ham));
            new (&spam) std::exception_ptr(t);
            std::swap(gotHam , rhs.gotHam);
        }
    }
    else
    {
        if (rhs.gotHam)
        {
            rhs.swap(*this);
        }
        else
        {
            spam.swap(rhs.spam);
            std::swap(gotHam , rhs.gotHam);
        }
    }
}
