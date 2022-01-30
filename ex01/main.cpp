//
// Created by Регина on 30.01.2022.
//

#include <iostream>

struct Data
{
    std::string data_information;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data *ptr = new Data();
    uintptr_t tmp;
    Data tmp_data;
    ptr->data_information = "some data";

    std::cout << "Default data      " << ptr->data_information << std::endl;
    tmp = serialize(ptr);
    std::cout << "Serialized data   " << &tmp << std::endl;
    tmp_data = *deserialize(tmp);
    std::cout << "Deserialized data " << tmp_data.data_information << std::endl;
}