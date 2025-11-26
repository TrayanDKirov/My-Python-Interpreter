#pragma once
#include "ScopeException.h"

class not_in_scope_exception : public scope_exception {
public:
    not_in_scope_exception(const std::string& varName)
        : scope_exception(("name " + varName + " not in scope. ").c_str()) { }
    not_in_scope_exception(const char* msg) : scope_exception(msg) { }
};