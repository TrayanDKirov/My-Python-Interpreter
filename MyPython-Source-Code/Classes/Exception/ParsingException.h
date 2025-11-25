#include <stdexcept>

class parsing_exception : public std::runtime_error {
public:
    parsing_exception(const char* msg) : std::runtime_error(msg) { }
};