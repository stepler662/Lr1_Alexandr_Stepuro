#pragma once
#include <string>
#include <iostream>
#include "Utils.h"

using namespace std;

class CS
{
private:
    int identifier;
    string name;
    int amount;
    int amount_work;
    float efficiency;
public:
    void setIdentifier(int id); // <- Устанавливает identifier
    int getIdentifier(); // <- Получает identifier
    void setName(string Name);
    string getName();
    void setAmount(int amou);
    int getAmount();
    void setAmount_work(int amount_w);
    int getAmount_work();
    void setEfficiency(float eff);
    float getEfficiency();
    friend std::ostream& operator << (std::ostream& out, const CS& cs);
    friend std::istream& operator >> (std::istream& in, CS& cs);
    static int MaxID;
    CS();
};

