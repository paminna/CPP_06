//
// Created by Регина on 30.01.2022.
//

#ifndef CPP_05_A_HPP
#define CPP_05_A_HPP


#include <iostream>
#include "Base.hpp"

class A : public Base {
public:
    A();
    ~A();
    void identify(Base& p);
    void setType();
    std::string getType();
private:
    std::string _type;
};


#endif //CPP_05_A_HPP
