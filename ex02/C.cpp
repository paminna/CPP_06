//
// Created by Регина on 30.01.2022.
//

#include "C.hpp"

C::C()
{
    _type = "I'm C";
}

C::~C(){}

std::string C::getType()
{
    return _type;
}
