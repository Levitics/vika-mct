
#include <didactics/core/platform/linux/ResourceLimit.hpp>
#include <didactics/core/Defines.hpp>

ResourceLimit::ResourceLimit() {
}

ResourceLimit::ResourceLimit(const ResourceLimit & orig) {
}

ResourceLimit::~ResourceLimit() {
}

ResourceLimit::ResourceLimit(int resource_id)
    : resourceID(resource_id)
    , applied(false)
{
    if (getrlimit(resourceID , &limit_) == OS_ERROR)
    {
        throw std::system_error(errno , std::system_category());
    }
    else
    {

    }
}

ResourceLimit::ResourceLimit(int resource_id ,
                             rlim_t soft_limit ,
                             rlim_t hard_limit)
    : resourceID(resource_id)
    , applied(false)
{
    limit_.rlim_cur = soft_limit;
    limit_.rlim_max = hard_limit;
}

ResourceLimit::ResourceLimit(int resource_id ,
                             rlimit & limit)
    : resourceID(resource_id)
    , limit_(limit) ,
    applied(false)
{
}

rlim_t ResourceLimit::soft_limit () const noexcept
{
    return limit_.rlim_cur;
}

rlim_t ResourceLimit::hard_limit () const noexcept
{
    return limit_.rlim_max;
}

void ResourceLimit::limit ()
{
    if (getrlimit(resourceID , &limit_) == OS_ERROR)
    {
        throw std::system_error(errno , std::system_category());
    }
}

void ResourceLimit::apply ()
{
    if (setrlimit(resourceID , &limit_) == OS_ERROR)
    {
        throw std::system_error(errno , std::system_category());
    }

    applied = true;
}

bool ResourceLimit::operator == (const ResourceLimit & other) const
{
    return resourceID == other.resourceID;
}

bool ResourceLimit::operator < (const ResourceLimit & other) const
{
    return resourceID < other.resourceID;
}
