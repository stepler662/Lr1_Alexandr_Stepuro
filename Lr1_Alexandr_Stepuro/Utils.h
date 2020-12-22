#pragma once
#include <iostream>

inline std::string inputString(std::string msg)
{
    std::cout << msg;
    char ch = 0;
    char str[20];
    int i = 0;
    std::cin.ignore(1000, '\n');
    while ((ch = std::cin.get()) != '\n') {
        str[i++] = ch;

    }
    str[i] = '\0';
    return std::string(str);

}
inline int inputInteger(std::string msg)
{
    int val;
    do
    {
        std::cout << msg;
        while (((std::cin >> val)).fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ошибка при вводе" << std::endl << msg;

        }
    } while (val < 0);
    return val;
}
inline float inputFloat(std::string msg)
{
    float val;                                 //проверка значения
    do
    {
        std::cout << msg;
        while (((std::cin >> val)).fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ошибка при вводе" << std::endl << msg;

        }
    } while (val < 0);
    return val;
}