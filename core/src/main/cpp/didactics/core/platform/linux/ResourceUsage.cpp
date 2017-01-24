
#include <didactics/core/platform/linux/ResourceUsage.hpp>

ResourceUsage::ResourceUsage() {
}

ResourceUsage::ResourceUsage(const ResourceUsage & orig) {
}

ResourceUsage::~ResourceUsage() {
}

ResourceUsage::ResourceUsage(int app)
    : appUser(app)
{
    if (getrusage(appUser , &rsrcUsage))
    {

    }
}

long ResourceUsage::maximumResidentSetSize () const
{
    return rsrcUsage.ru_maxrss;
}

long ResourceUsage::sharingOfTextSegmentMemory () const
{
    return rsrcUsage.ru_ixrss;
}

long ResourceUsage::dataSegmentMemoryUsed () const
{
    return rsrcUsage.ru_idrss;
}

long ResourceUsage::numberOfSoftPageFaults () const
{
    return rsrcUsage.ru_minflt;
}

long ResourceUsage::numberOfHardPageFaults () const
{
    return rsrcUsage.ru_majflt;
}

long ResourceUsage::timesAProcessWasSwapped () const
{
    return rsrcUsage.ru_nswap;
}

long ResourceUsage::numberOfInputOperationsViaTheFileSystem () const
{
    return rsrcUsage.ru_inblock;
}

long ResourceUsage::numberOfOutputOperationsViaTheFileSystem () const
{
    return rsrcUsage.ru_oublock;
}

long ResourceUsage::numberOfIPCMessagesSent () const
{
    return rsrcUsage.ru_msgsnd;
}

long ResourceUsage::numberOfIPCMessagesReceived () const
{
    return rsrcUsage.ru_msgrcv;
}

long ResourceUsage::numberOfSignalsDelivered () const
{
    return rsrcUsage.ru_nsignals;
}

long ResourceUsage::numberOfVoluntaryContextSwitches () const
{
    return rsrcUsage.ru_nvcsw;
}

long ResourceUsage::numberOfInvoluntaryContextSwitches () const
{
    return rsrcUsage.ru_nivcsw;
}

long ResourceUsage::stackMemoryUsed () const
{
    return (this->rsrcUsage.ru_isrss);
}

timeval ResourceUsage::amountOfSystemTimeUsed () const
{
    return (this->rsrcUsage.ru_utime);
}

timeval ResourceUsage::amountOfUserTimeUsed () const
{
    return (this->rsrcUsage.ru_stime);
}
