
#ifndef ASYNCTASKS_HPP
#define ASYNCTASKS_HPP
#include <functional>
#include <algorithm>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>
#include <string>

template<class T>
class ReadOnlyProperty
{
    const T & mValue;

public:

    ReadOnlyProperty<T>() = delete;
    ReadOnlyProperty<T>(const ReadOnlyProperty<T>&) = delete;
    ReadOnlyProperty<T> & operator = (const ReadOnlyProperty<T> &) = delete;
    ReadOnlyProperty<T>(const T &pValue) : mValue(pValue)
    {
    }
    const T & value () const {
        return mValue;
    }

    operator const T & () const { return mValue; }
    bool operator == (const T & pVal) {
        return mValue == pVal;
    }

    bool operator != (const T & pVal) {
        return mValue != pVal;
    }

};

class AsyncTasks
{
public:

    AsyncTasks();
    AsyncTasks(const AsyncTasks & orig);
    virtual ~AsyncTasks();

private:

};

#endif
