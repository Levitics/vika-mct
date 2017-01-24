
#ifndef RESOURCEUSAGE_HPP
#define RESOURCEUSAGE_HPP
#include <didactics/core/platform/linux/ResourceLimit.hpp>
class ResourceUsage
{
public:

    ResourceUsage();
    ResourceUsage(const ResourceUsage & orig);
    virtual ~ResourceUsage();
    ResourceUsage(int);

    long maximumResidentSetSize () const;
    long sharingOfTextSegmentMemory () const;
    long dataSegmentMemoryUsed () const;
    long numberOfSoftPageFaults () const;
    long numberOfHardPageFaults () const;
    long timesAProcessWasSwapped () const;
    long numberOfInputOperationsViaTheFileSystem () const;
    long numberOfOutputOperationsViaTheFileSystem () const;
    long numberOfIPCMessagesSent () const;
    long numberOfIPCMessagesReceived () const;
    long numberOfSignalsDelivered () const;
    long numberOfVoluntaryContextSwitches () const;
    long numberOfInvoluntaryContextSwitches () const;
    long stackMemoryUsed () const;
    timeval amountOfUserTimeUsed () const;
    timeval amountOfSystemTimeUsed () const;

private:

    int appUser;
    timeval tv;
    rusage rsrcUsage;
};

#endif
