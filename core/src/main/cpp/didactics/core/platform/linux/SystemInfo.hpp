
#ifndef SYSTEMINFO_HPP
#define SYSTEMINFO_HPP
#include <iostream>
#include <sigar.h>
#include <string>
#include <time.h>
#include <cstdint>
class SystemInfo
{
public:

    SystemInfo();
    SystemInfo(const SystemInfo & orig);
    virtual ~SystemInfo();
    std::string description ();
    std::string arch ();
    uint64_t gmtTime ();

private:

    std::string SystemDescription;
    std::string SystemArch;
};

#endif
