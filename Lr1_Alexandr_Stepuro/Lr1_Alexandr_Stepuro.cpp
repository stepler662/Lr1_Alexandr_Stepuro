// Lr1_Alexandr_Stepuro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<string>
using namespace std;
bool PIPE_EXIST = false;
bool CS_EXIST = false;
struct Pipe    //структура трубы
{
    int identifier;
    float length;
    float diameter;
    bool repaired = false;
};

struct CS
{
    int identifier;
    string name; 
    int amount; //сумма
    int amount_work;
    float efficiency;
};
 string inputString(string msg)
{
    cout << msg;
    char ch = 0;
    char str[20];
    int i = 0;
    cin.ignore(1000, '\n');
    while ((ch = cin.get()) != '\n') {
        str[i++] = ch;

    }
    str[i] = '\0';
    return string(str);
    
}
int inputInteger(string msg)
{
    int val;
    cout << msg;
    while (((cin >> val)).fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка при вводе" << endl <<msg;

    }
    return val;
}
 float inputFloat(string msg)
{
    float val;                                 //проверка значения
    cout << msg;
    while (((cin >> val)).fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка при вводе" << endl << msg;

    }
    return val;
}
void addPipe(Pipe& newPipe) { 
    newPipe.identifier = inputInteger("Введите идентификатор ");
    newPipe.length = inputFloat("Введите длину ");
    newPipe.diameter = inputFloat("Введите диаметр");
    PIPE_EXIST = true;
    int repaired  = inputInteger("Введите 1, если в ремонте или введите 0,если не в ремонте");
    while (!(repaired == 0 || repaired == 1))
    {
        cout << "Вы ввели число не в том диапозоне" << endl;
        repaired = inputInteger("Введите 1, если в ремонте или введите 0,если не в ремонте");
    } 
    newPipe.repaired = repaired;
 }
void addCS(CS& newCS) {
    newCS.identifier = inputInteger("Введите идентификатор ");
    newCS.amount = inputInteger("Введите количество цехов");
    CS_EXIST = true;
    newCS.efficiency = inputFloat("Введите эффективность");
    newCS.name= inputString("Введите название: ");
    
    int amount_work = inputInteger("Введите количество рабочих цехов");
    while (amount_work > newCS.amount) {
        cout << "Вы ввели не правильное количество рабочих цехов";
        amount_work = inputFloat("Введите количество рабочих цехов ");
    }
    newCS.amount_work = amount_work;
}
void showObjects(const Pipe& Pipe1,const CS& CS1) {
    if (PIPE_EXIST)
    cout << endl<<"Труба" << endl << "Идентификатор: " << Pipe1.identifier << endl << "Длина: " << Pipe1.length << endl << "Диаметр: " << Pipe1.diameter << endl << (Pipe1.repaired ? "В ремонте!" : "Не в ремонте!") << endl << endl;
    if (CS_EXIST)
    cout << "КС" << endl <<"Идентификатор: " << CS1.identifier << endl << "Количество цехов: " << CS1.amount << endl << "Эффективность: " << CS1.efficiency << endl<<"Имя:"<< CS1.name <<endl<< "Количество рабочих цехов:" <<CS1.amount_work<< endl << endl;
}
void PipeModify(Pipe& Pipe1) {
    int repaired = inputInteger("Измените параметр в ремонте, если в ремонте то введите 1 или введите 0,если не в ремонте");
    while (!(repaired == 0 || repaired == 1))
    {
        cout << "Вы ввели число не в том диапозоне" << endl;
        repaired = inputInteger("Измените параметр в ремонте, если в ремонте то введите 1 или введите 0,если не в ремонте");
    }
    Pipe1.repaired = repaired;
}
void CSModify(CS& CS1) {
    int option = inputInteger("Если 1 то запустить цех,если 0 то остановить ");
    int res = (option == 1 ? CS1.amount_work + 1 : CS1.amount_work - 1);
    while (!(option == 0 || option == 1)|| res < 0 || res > CS1.amount)
    {
        cout << "Не возмжно остановить КС или запустить" << endl;
        option = inputInteger("Если 1 то запустить цех,если 0 то остановить");
        res = (option == 1 ? CS1.amount_work + 1 : CS1.amount_work - 1);
    }
    CS1.amount_work = (option == 1 ? CS1.amount_work + 1 : CS1.amount_work - 1);
}
void output(Pipe Pipe1, CS CS1)
{
    ofstream outf("file.txt");
    if (!outf.is_open()) {
        cout << "Файл не может быть открыт!\n";
    }
    else {
        if (PIPE_EXIST)
        {
            outf << 1 << endl;
            outf   << Pipe1.identifier << endl;
            outf <<  Pipe1.length << endl;
            outf <<  Pipe1.diameter << endl;
            outf <<  Pipe1.repaired << endl;
        }
        if (CS_EXIST)
        {
            outf << 2 << endl;
            
            outf <<  endl;
            outf <<  CS1.identifier << endl;
            outf <<  CS1.name << endl;
            outf <<  CS1.amount << endl;
            outf <<  CS1.amount_work << endl;
            outf <<  CS1.efficiency << endl;
        }
    }
    outf.close();
}
void input(Pipe& Pipe1, CS& CS1)
{
    ifstream fin("file.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        PIPE_EXIST = true;
        CS_EXIST = true;
        fin >> Pipe1.identifier >> Pipe1.length >> Pipe1.diameter >> Pipe1.repaired;
        fin >> CS1.identifier >> CS1.name >> CS1.amount >> CS1.amount_work >> CS1.efficiency;
    }
    fin.close();
}

int main()
{
    Pipe Pipe1;
    CS CS1;
	setlocale(LC_ALL, "Russian");
    while (true) {
        cout << "1.Добавить трубу" << endl << "2.Добавить КС" << endl << "3.Просмотр всех объектов" << endl << "4.Редактировать трубу" << endl << "5.Редактировать КС"
            << endl << "6.Сохранить" << endl << "7.Загрузить" << endl << "0.Выход" << endl;

        int Command = inputInteger("Введите команду");
        while (!(Command >= 0 && Command <= 7))
        {
            cout << "Вы ввели число не в том диапозоне" << endl;
            Command = inputInteger("Введите команду");
        }
        switch (Command) {
        case 1: {
            addPipe(Pipe1);
            break;
        }
        case 2: {
            addCS(CS1);
            break;
        }
        case 3: {
            showObjects(Pipe1,CS1);
            break;
        }
        case 4: {
            PipeModify(Pipe1);
            break;
        }
        case 5: {
            CSModify(CS1);
            break;
        }
        case 6: {
            output(Pipe1, CS1);
            break;
        }
        case 7: {
            input(Pipe1, CS1);
            break;
        }
        case 0: {
            return 0;
        }
        }
    }
}

