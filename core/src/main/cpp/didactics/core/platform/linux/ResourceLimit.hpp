
#ifndef RESOURCELIMIT_HPP
#define RESOURCELIMIT_HPP
#include <didactics/core/log/Logger.hpp>
#include <sys/resource.h>
#include <didactics/core/errorhandling/ErrnoMapper.hpp>

class ResourceLimit
{
public:

    ResourceLimit();
    ResourceLimit(const ResourceLimit & orig);
    virtual ~ResourceLimit();

    ResourceLimit(int);
    ResourceLimit(int , rlim_t , rlim_t);
    ResourceLimit(int , rlimit &);

    rlim_t soft_limit () const noexcept;
    rlim_t hard_limit () const noexcept;

    const rlimit & to_rlimit () const;

    void limit ();
    void apply ();

    bool operator == (const ResourceLimit &) const;
    bool operator < (const ResourceLimit &) const;

private:

    int resourceID;
    rlimit limit_;
    bool applied;
};

#endif
