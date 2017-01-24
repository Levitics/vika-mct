
#ifndef CALLABLECOLLECTION_HPP
#define CALLABLECOLLECTION_HPP
#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>
template <typename FunctionType>
class CallableCollection
{
public:

    CallableCollection();
    CallableCollection(const CallableCollection & orig);
    virtual ~CallableCollection();

    template <typename Callable>
    auto insert (Callable && callable)
    {
        auto callable_id = compute_id(callable);
        functions_.emplace_back(callable_id , std::forward<Callable>(callable));

        return callable_id;
    }

private:

};

#endif
