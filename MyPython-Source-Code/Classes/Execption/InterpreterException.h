#include <exception>

class interpreter_exception : public std::exception
{
public:
    interpreter_exception(const char* msg) : std::exception(msg) { }
};