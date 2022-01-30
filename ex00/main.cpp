//
// Created by Регина on 29.01.2022.
//

#include <iostream>
#include <iomanip>

void ft_out(std::string one, std::string two, std::string three, std::string four)
{
    std::cout << "char: " + one << std::endl;
    std::cout << "int: " + two << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << std::stof(three) << 'f' <<std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << std::stod(four) << std::endl;
}

bool check_nan_inf(std::string str)
{
    if (str == "nan")
    {
        ft_out("impossible", "impossible", "nanf", "nan");
        return 1;
    }
    if (str == "nanf")
    {
        ft_out("impossible", "impossible", "nanff", "nanf");
        return 1;
    }
    if (str == "-inf")
    {
        ft_out("impossible", "impossible", "-inff", "-inf");
        return 1;
    }
    if (str == "-inff")
    {
        ft_out("impossible", "impossible", "-inff", "-inff");
        return 1;
    }
    if (str == "+inf")
    {
        ft_out("impossible", "impossible", "+inff", "+inf");
        return 1;
    }
    if (str == "+inff")
    {
        ft_out("impossible", "impossible", "+inff", "+inff");
        return 1;
    }
    return 0;
}

bool checkArg(std::string str)
{
    if (str.length() == 1 && !std::isdigit(str[0])) {
        int value = str[0] - '0';
        ft_out("'" + str + "'", std::to_string(value), std::to_string(value), std::to_string(value));
        return 1;
    }
    return 0;
}

void parse(std::string str)
{
    int value;
    double four;
    float three;
    int two;
    char one;

    if (check_nan_inf(str) || checkArg(str)  || (std::isalpha(str[0]) && str.length() > 1))
        return;
    try
    {
        four = std::stod(str);
    }
    catch(std::exception &e)
    {
        ft_out("impossible", "impossible", "impossible", "impossible");
        return;
    }
    try
    {
        value = std::stof(str);
        three = static_cast<float>(value);
    }
    catch (std::exception &e)
    {
        ft_out("impossible", "impossible", "impossible", str);
        return;
    }
    try
    {
        value = std::stoi(str);
        if (value <= std::numeric_limits<int>::max() || value >= std::numeric_limits<int>::min())
            two = static_cast<int>(value);
        else
            return;
    }
    catch (std::exception &e)
    {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  " << std::fixed << std::setprecision(1) << std::stof(str) << 'f' << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << std::stod(str) << std::endl;
        return;
    }
    if ((value >= -128 && value < 128) && !std::isalpha(str[0]))
    {
        int tmp = static_cast<int>(value);
        one = tmp;
        if (std::isprint(one))
            std::cout << "char:   '" << one << "'" << std::endl;
        else
            std::cout << "char:   Not displayable" << std::endl;
    }
    if (!(value >= -128 && value < 128))
        std::cout << "char:   Not displayable" << std::endl;
    std::cout << "int:    " << two << std::endl;
    std::cout << "float:  " << std::fixed << std::setprecision(1) << std::stof(str) << 'f' <<  std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << four << std::endl;
}


int main(int argc, char *argv[])
{
    if (argc <= 1 || argc > 2)
        std::cout << "Wrong arguments" << std::endl;
    else
    {
        parse(argv[1]);
    }
}
