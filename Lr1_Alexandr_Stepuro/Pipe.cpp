#include "Pipe.h"
void Pipe::setIdentifier(int id)
{
	identifier = id;
}
int Pipe::getIdentifier()
{
	return identifier;
}
void Pipe::setLength(float leng)
{
	length = leng;
}
float Pipe::getLength()
{
	return length;
}
void Pipe::setDiameter(float diam)
{
	diameter = diam;
}
float Pipe::getDiameter()
{
	return diameter;
}
void Pipe::setRepaired(bool rep)
{
	repaired = rep;
}
bool Pipe::getRepaired()
{
	return repaired;
}
std::ostream& operator << (std::ostream& out, const Pipe& p)
{
    out << "ID: " << p.identifier << std::endl;
    out << "�����: " << p.length << std::endl;
    out << "�������: " << p.diameter << std::endl;
    out << (p.repaired ? "� ������� !" : "�� � �������!") << std::endl;
    out << std::endl;
    return out;
}
std::istream& operator >> (std::istream& in, Pipe& pipe1)
{
    pipe1.length = inputFloat("������� �����: ");
    pipe1.diameter = inputFloat("������� �������: ");
    return in;
}


int Pipe::MaxID = 0;

Pipe::Pipe()
{
    identifier = ++MaxID;
}

