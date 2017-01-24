
#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

class Backtrace
{
    struct BacktraceInfo
    {
        static const int maxFrames = 128;
        int numFrames;
        void * addressList[maxFrames];
    };

public:

    Backtrace();
    Backtrace(const Backtrace & orig);
    virtual ~Backtrace();

private:

};

#endif
