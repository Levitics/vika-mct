
#ifndef EXPECTED_HPP
#define EXPECTED_HPP
#include <stdexcept>
#include <typeinfo>

template <typename T>
class Expected
{
    union
    {
        T ham;
        std::exception_ptr spam;
    };

public:

    Expected(const T & rhs);
    Expected(T && rhs);
    Expected(const Expected & rhs);
    Expected(Expected && rhs);
    virtual ~Expected();
    void swap (Expected & rhs);


    template <class E>
    static Expected<T> fromException (const E & exception)
    {
        if (typeid(exception) != typeid(E))
        {
            throw std::invalid_argument("slicing detected");
        }

        return fromException(std::make_exception_ptr(exception));
    }

    static Expected<T> fromException (std::exception_ptr p)
    {
        Expected<T> result;
        result.gotHam = false;
        new (&result.spam) std::exception_ptr(std::move(p));
        return result;
    }

    static Expected<T> fromException () {
        return fromException(std::current_exception());
    }

    bool valid () const {
        return gotHam;
    }

    T & get ()
    {
        if (!gotHam)
        {
            std::rethrow_exception(spam);
        }

        return ham;
    }

    const T & get () const {
        if (!gotHam)
        {
            std::rethrow_exception(spam);
        }

        return ham;
    }

    template <class E>
    bool hasException () const
    {
        try
        {
            if (!gotHam)
            {
                std::rethrow_exception(spam);
            }
        }
        catch (const E & object)
        {
            return true;
        }
        catch (...)
        {
        }
        return false;
    }

    template <class F>
    static Expected fromCode (F fun)
    {
        try
        {
            return Expected(fun());
        }
        catch (...)
        {
            return fromException();
        }
    }

    // auto r = Expected<std::string>::fromCode([]{...});

private:

    Expected();

    bool gotHam;
};

#endif
