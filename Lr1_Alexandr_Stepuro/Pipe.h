#pragma once
#include <iostream>
#include"Utils.h"

class Pipe
{ 
    private: 
        int identifier;
        float length;
        float diameter;
        bool repaired = false;
    public:
        void setIdentifier(int id); // <- Устанавливает identifier
        int getIdentifier(); // <- Получает identifier
        void setLength(float leng);
        float getLength();
        void setDiameter(float diam);
        float getDiameter();
        void setRepaired(bool rep);
        bool getRepaired();
        friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
        friend std::istream& operator >> (std::istream& in, Pipe& pipe);
        static int MaxID;
        Pipe();
};

