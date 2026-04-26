#pragma once
#include <stdexcept>

class file_not_found_error : public error
{
public:
    file_not_found_error(const char* msg) : error(msg) { }
};