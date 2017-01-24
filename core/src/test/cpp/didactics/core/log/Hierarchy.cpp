
#include <didactics/core/log/Hierarchy.hpp>

// using cxx::Hierarchy;
// using cxx::Hierarchy2;
// using cxx::Hierarchy3;
using namespace cxx;

// log4cxx::LoggerPtr cxx::Hierarchy::logger = log4cxx::Logger::getLogger("cxx.Hierarchy");
// log4cxx::LoggerPtr cxx::Hierarchy2::logger = log4cxx::Logger::getLogger("cxx.Hierarchy2");
// log4cxx::LoggerPtr cxx::Hierarchy3::logger = log4cxx::Logger::getLogger("cxx.Hierarchy3");
//
// log4cxx::LoggerPtr cxx::cxx2::Hierarchy::logger = log4cxx::Logger::getLogger("cxx.cxx2.Hierarchy");
// log4cxx::LoggerPtr cxx::cxx2::Hierarchy2::logger = log4cxx::Logger::getLogger("cxx.cxx2.Hierarchy2");
// log4cxx::LoggerPtr cxx::cxx2::Hierarchy3::logger = log4cxx::Logger::getLogger("cxx.cxx2.Hierarchy3");

Hierarchy::Hierarchy()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.Hierarchy")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy::Hierarchy(const Hierarchy & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy::~Hierarchy() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void Hierarchy::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");
    LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy");
    LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy");
    LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy");
    LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy");
}

Hierarchy2::Hierarchy2()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.Hierarchy2")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy2::Hierarchy2(const Hierarchy2 & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy2::~Hierarchy2() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void Hierarchy2::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");
    LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy2");
    LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy2");
    LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy2");
    LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy2");
}

Hierarchy3::Hierarchy3()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.Hierarchy3")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy3::Hierarchy3(const Hierarchy3 & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Hierarchy3::~Hierarchy3() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void Hierarchy3::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");
    LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy3");
    LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy3");
    LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy3");
    LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy3");
}

cxx::cxx2::Hierarchy::Hierarchy()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.cxx2.Hierarchy")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy::Hierarchy(const Hierarchy & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy::~Hierarchy() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void cxx::cxx2::Hierarchy::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");
    LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy");
    LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy");
    LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy");
    LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy");
}

cxx::cxx2::Hierarchy2::Hierarchy2()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.cxx2.Hierarchy2")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy2::Hierarchy2(const Hierarchy2 & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy2::~Hierarchy2() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void cxx::cxx2::Hierarchy2::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");
    LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy2");
    LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy2");
    LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy2");
    LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy2");
}

cxx::cxx2::Hierarchy3::Hierarchy3()
    : logger (log4cxx::Logger::getLogger(std::string("cxx.cxx2.Hierarchy3")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy3::Hierarchy3(const Hierarchy3 & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

cxx::cxx2::Hierarchy3::~Hierarchy3() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void cxx::cxx2::Hierarchy3::logme ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    LOG4CXX_DEBUG(logger , "*************************************");

    for (int i = 0; i < 200; i++)
    {
        LOG4CXX_INFO(logger , " INFO message from CLASS Hierarchy3");
        LOG4CXX_WARN(logger , " WARN message from CLASS Hierarchy3");
        LOG4CXX_ERROR(logger , "ERROR message from CLASS Hierarchy3");
        LOG4CXX_FATAL(logger , "FATAL message from CLASS Hierarchy3");
        // LOGF_INFO("Format %1% %2% %3%" % 3 % 2.71828 % "foo c++");
    }
}
