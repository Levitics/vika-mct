
#ifndef CALLBACKHANDLER_HPP
#define CALLBACKHANDLER_HPP

template <typename C , typename R , typename P>
class CallbackHandler
{
public:

    typedef R (C::* function)(P);
    CallbackHandler();
    CallbackHandler(const C * aClass , const function aFunction);
    virtual ~CallbackHandler(); // = default;
    void registerCallback (const C * aclass , const function aFunction);
    R operator () (const P & param);

protected:

private:

    C * aTclass;
    function func;
};

template <typename R , typename P>
class
    CallbackHandler <void , R , P>
{
protected:

    typedef R (* function)(P);

public:

    CallbackHandler(const function function_);
    CallbackHandler();
    virtual ~CallbackHandler();

public:

    void registerCallback (const function function_);
    R operator () (const P & param);

private:

    function func;
};

#endif
