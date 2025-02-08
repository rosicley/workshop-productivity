#pragma once

#include <stdexcept>
#include <string>

class SystemSizeMismatchException : public std::runtime_error
{
public:
    explicit SystemSizeMismatchException(const std::string &msg) : std::runtime_error(msg)
    {
    }
};

class NoSolutionException : public std::runtime_error
{
public:
    explicit NoSolutionException(const std::string &msg) : std::runtime_error(msg)
    {
    }
};
