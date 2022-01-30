//
// Created by Регина on 30.01.2022.
//

#ifndef CPP_05_C_HPP
#define CPP_05_C_HPP

#include "Base.hpp"
#include <iostream>

class C  : public Base {
public:
    C();
    ~C();
    void identify(Base& p);
    void setType();
    std::string getType();
private:
    std::string _type;
};


#endif //CPP_05_C_HPP
