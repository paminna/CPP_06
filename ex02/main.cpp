//
// Created by Регина on 30.01.2022.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    switch (rand() % 3) {
        case 0:
            std::cout << "Class A" << std::endl;
            return new A;
        case 1:
            std::cout << "Class B" << std::endl;
            return new B;
        case 2:
            std::cout << "Class C" << std::endl;
            return new C;
    }
    return nullptr;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
    {
        A *a = dynamic_cast<A *>(p);
        std::cout << a->getType() << std::endl;
    }
    if (dynamic_cast<B *>(p))
    {
        B *b = dynamic_cast<B *>(p);
        std::cout << b->getType() << std::endl;
    }
    if (dynamic_cast<C *>(p))
    {
        C *c = dynamic_cast<C *>(p);
        std::cout << c->getType() << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << a.getType() << std::endl;
    }
    catch (std::exception e) { std::cout << "Cannot cast to A type try another type" << std::endl;}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << b.getType() << std::endl;
    }
    catch (std::exception e){ std::cout << "Cannot cast to B type try another type" << std::endl;}
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << c.getType() << std::endl;
    }
    catch (std::exception e) { std::cout << "Cannot cast to C type try another type" << std::endl;}
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        Base *base = generate();

        std::cout << "by ptr" << std::endl;
        identify(base);
        std::cout << "by ptr" << std::endl;
        identify(*base);
        std::cout << "-------------------" << std::endl;
    }
}