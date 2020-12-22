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
    out << "Название: " << cs.name << std::endl;
    out << "Количество цехов всего: " << cs.amount << std::endl;
    out << "Количество цехов в работе: " << cs.amount_work << std::endl;
    out << "Эффективность: " << cs.efficiency << std::endl;
    out << std::endl;
    return out;
}
std::istream& operator >> (std::istream& in, CS& cs1)
{
    cs1.name = inputString("Введите название: ");
    cs1.amount = inputInteger("Введите количество цехов: ");
    int amount_work = inputInteger("Введите количество цехов в работе: ");
    while (amount_work > cs1.amount)
    {
        cout << "Введите число, которое будет меньше количество цехов\n";
        amount_work = inputInteger("Введите количество цехов в работе: ");
    }
    cs1.amount_work = amount_work;
    cs1.efficiency = inputFloat("Введите эффективность: ");

    return in;
}


int CS::MaxID = 0;

CS::CS()
{
    identifier = ++MaxID;
}
