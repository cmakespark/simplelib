#pragma once

class Dog::Impl
{
public:
    explicit Impl();

    const int m_weight;
    int m_barks;
};
