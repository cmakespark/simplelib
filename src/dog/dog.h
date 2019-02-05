#pragma once

#include <memory>
#include "simplelib.h"


class Dog
{
public:
    CCSIMPLELIB_EXPORT explicit Dog();
    CCSIMPLELIB_EXPORT ~Dog();

    CCSIMPLELIB_EXPORT int weight() const;

    CCSIMPLELIB_EXPORT void bark();
    CCSIMPLELIB_EXPORT int numberOfBarks() const;

private:
    Dog(const Dog &other) = delete;
    Dog& operator=(const Dog &other) = delete;

    class Impl;
    std::unique_ptr<Impl> d;
};
