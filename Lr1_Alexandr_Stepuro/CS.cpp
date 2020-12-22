#include "CS.h"

void CS::setIdentifier(int id)
{
    identifier = id;
}
int CS::getIdentifier()
{
    return identifier;
}
void CS::setName(string Name)
{
    name = Name;
}
string CS::getName()
{
    return name;
}
void CS::setAmount(int amou)
{
    amount = amou;
}
int CS::getAmount()
{
    return amount;
}
void CS::setAmount_work(int amount_w)
{
    amount_work = amount_w;
}
int CS::getAmount_work()
{
    return amount_work;
}
void CS::setEfficiency(float eff)
{
    efficiency = eff;
}
float CS::getEfficiency()
{
    return efficiency;
}
std::ostream& operator << (std::ostream& out, const CS& cs)
{
    out << "ID: " << cs.identifier << std::endl;
    out << "��������: " << cs.name << std::endl;
    out << "���������� ����� �����: " << cs.amount << std::endl;
    out << "���������� ����� � ������: " << cs.amount_work << std::endl;
    out << "�������������: " << cs.efficiency << std::endl;
    out << std::endl;
    return out;
}
std::istream& operator >> (std::istream& in, CS& cs1)
{
    cs1.name = inputString("������� ��������: ");
    cs1.amount = inputInteger("������� ���������� �����: ");
    int amount_work = inputInteger("������� ���������� ����� � ������: ");
    while (amount_work > cs1.amount)
    {
        cout << "������� �����, ������� ����� ������ ���������� �����\n";
        amount_work = inputInteger("������� ���������� ����� � ������: ");
    }
    cs1.amount_work = amount_work;
    cs1.efficiency = inputFloat("������� �������������: ");

    return in;
}


int CS::MaxID = 0;

CS::CS()
{
    identifier = ++MaxID;
}
