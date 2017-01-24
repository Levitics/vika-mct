
#include <didactics/core/errorhandling/Exceptions.hpp>

Exceptions::Exceptions() {
}

Exceptions::Exceptions(const Exceptions & orig) {
}

Exceptions::~Exceptions() {
}

const char * Exceptions::what () const throw ()
{
    return message.c_str();
}

const char * Exceptions::where () const throw ()
{
    return location.c_str();
}
