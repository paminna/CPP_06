//
// Created by Регина on 30.01.2022.
//

#include "A.hpp"
A::A()
{
    _type = "I'm A";
}

A::~A(){}

std::string A::getType()
{
    return _type;
}
