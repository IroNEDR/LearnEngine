#pragma once

#include <iostream>
#include <string>

class Errors
{
public:
    static void fatalError(const std::string &errorText);
};
