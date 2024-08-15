#pragma once

#include <sstream>
#include <iostream>

class Log : public std::stringstream
{
public:

    void print();

    void disable();

    void enable();

private:

    bool enabled = true;

};

#ifdef COMMON_IMPL
void Log::print()
{
    if (enabled) std::cout << this->str();
    this->str("");
}

void Log::disable()
{
    enabled = false;
}

void Log::enable()
{
    enabled = true;
}
#endif