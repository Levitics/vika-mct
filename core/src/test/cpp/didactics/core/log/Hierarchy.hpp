
#ifndef HIERARCHY_HPP
#define HIERARCHY_HPP
#include <didactics/core/log/Logger.hpp>
namespace cxx
{
    static log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("cxx");
    class ThreadedLogging
    {
public:

        ThreadedLogging();
        ThreadedLogging(const ThreadedLogging & orig);
        virtual ~ThreadedLogging();

private:

        long nThreadCount;
        log4cxx::LoggerPtr logger;
    };

    class Hierarchy
    {
public:

        Hierarchy();
        Hierarchy(const Hierarchy & orig);
        virtual ~Hierarchy();
        virtual void logme ();

private:

        log4cxx::LoggerPtr logger;
    };

    class Hierarchy2 : public Hierarchy
    {
public:

        Hierarchy2();
        Hierarchy2(const Hierarchy2 & orig);
        virtual ~Hierarchy2();
        virtual void logme ();

private:

        log4cxx::LoggerPtr logger;
    };

    class Hierarchy3 : public Hierarchy2
    {
public:

        Hierarchy3();
        Hierarchy3(const Hierarchy3 & orig);
        virtual ~Hierarchy3();
        virtual void logme ();

private:

        log4cxx::LoggerPtr logger;
    };

    namespace cxx2
    {
        static log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("cxx2");
        class Hierarchy
        {
public:

            Hierarchy();
            Hierarchy(const Hierarchy & orig);
            virtual ~Hierarchy();
            virtual void logme ();

private:

            log4cxx::LoggerPtr logger;
        };

        class Hierarchy2 : public Hierarchy
        {
public:

            Hierarchy2();
            Hierarchy2(const Hierarchy2 & orig);
            virtual ~Hierarchy2();
            virtual void logme ();

private:

            log4cxx::LoggerPtr logger;
        };

        class Hierarchy3 : public Hierarchy2
        {
public:

            Hierarchy3();
            Hierarchy3(const Hierarchy3 & orig);
            virtual ~Hierarchy3();
            virtual void logme ();

private:

            log4cxx::LoggerPtr logger;
        };

    }
}


#endif
