
#include <didactics/core/errorhandling/Backtrace.hpp>

#include <execinfo.h>
#include <dlfcn.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cxxabi.h>
#include <memory>

Backtrace::Backtrace() {
}

Backtrace::Backtrace(const Backtrace & orig) {
}

Backtrace::~Backtrace() {
}
