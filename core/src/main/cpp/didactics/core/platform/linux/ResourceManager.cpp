
#include <didactics/core/platform/linux/ResourceManager.hpp>
/*
   ResourceManager::ResourceManager() {
   }

   ResourceManager::ResourceManager(const ResourceManager & orig) {
   }

   ResourceManager::~ResourceManager() {
   }
 */

bool ResourceManager::resourceLimit (const ResourceLimit & limit)
{
    return this->rsrcLimits.insert(limit).second;
}

ResourceLimit ResourceManager::resourceLimit (int rsrID) const
{
    return (*rsrcLimits.find(ResourceLimit(rsrID)));
}

ResourceUsage ResourceManager::resourceUsage (int who) const
{
    return ResourceUsage(who);
}

void ResourceManager::applyLimits ()
{
    for (ResourceLimit limit : rsrcLimits)
    {
        limit.apply();
    }
}
