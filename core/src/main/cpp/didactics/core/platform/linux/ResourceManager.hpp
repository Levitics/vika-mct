
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <set>
#include <didactics/core/utils/Singleton.hpp>
#include <didactics/core/platform/linux/ResourceUsage.hpp>
#include <didactics/core/platform/linux/ResourceLimit.hpp>

/*
   void resMonitor ()
   {
    ResourceManager & rsrcManager = ResourceManager::instance();

    try
    {
        rsrcManager.resourceLimit(ResourceLimit(RLIMIT_CPU , 3 , 3));
        rsrcManager.resourceLimit(ResourceLimit(RLIMIT_RTTIME , 3 , 3));
        rsrcManager.applyLimits();
    }
    catch (const std::system_error & err)
    {
        std::cerr << "Error (" << err.code() << "): " << err.code().message() << std::endl;
    }
    // some processing
    ResourceUsage usage = rsrcManager.resourceUsage(RUSAGE_SELF);
    std::cout << "User Time (sec): " << usage.amountOfUserTimeUsed().tv_sec<< std::endl;
    std::cout << "User Time (usec): " << usage.amountOfUserTimeUsed().tv_usec << std::endl;
    std::cout << "System Time (sec): " << usage.amountOfSystemTimeUsed().tv_sec << std::endl;
    std::cout << "System Time (usec): " << usage.amountOfSystemTimeUsed().tv_usec << std::endl;
   }

   //*/

class ResourceManager : public Singleton<ResourceManager>
{
public:

    ResourceManager();
    ResourceManager(const ResourceManager & orig);
    virtual ~ResourceManager();

    bool resourceLimit (const ResourceLimit &);
    ResourceLimit resourceLimit (int) const;
    ResourceUsage resourceUsage (int) const;
    void applyLimits ();

private:

    std::set<ResourceLimit> rsrcLimits;
};

#endif
