//
// Created by Регина on 30.01.2022.
//

#include "B.hpp"

B::B()
{
    _type = "I'm B";
}

B::~B(){}

std::string B::getType()
{
    return _type;
}

