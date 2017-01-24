
#include <didactics/core/exple/CallbackHandler.hpp>
template <typename C , typename R , typename P>
CallbackHandler<C , R , P>::CallbackHandler()
    : aTclass(nullptr)
    , func(nullptr)
{

}

template <typename C , typename R , typename P>
CallbackHandler<C , R , P>::CallbackHandler(const C * aClass ,
                                            const function aFunction)
    : aTclass(const_cast<C *>(aClass) , func(aFunction))
{
}

template <typename C , typename R , typename P>
CallbackHandler<C , R , P>::~CallbackHandler()
{
    aTclass = nullptr;
    func = nullptr;
}

template <typename C , typename R , typename P>
void CallbackHandler<C , R , P> :: registerCallback (const C * aclass ,
                                                     const function afunction)
{
    this->aTclass = const_cast<C *>(aclass);
    this->func = afunction;
}

template <typename C , typename R , typename P>
R CallbackHandler<C , R , P> :: operator () (const P & param)
{
    return (aTclass->*func)(param);
}
