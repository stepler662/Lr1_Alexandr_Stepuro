// Lr1_Alexandr_Stepuro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<string>
#include"Utils.h"
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>

using namespace std;

bool PIPE_EXIST = false;
bool CS_EXIST = false;


//struct CS
//{
//    int identifier;
//    string name; 
//    int amount; //сумма
//    int amount_work;
//    float efficiency;
//};
// string inputString(string msg)
//{
//    cout << msg;
//    char ch = 0;
//    char str[20];
//    int i = 0;
//    cin.ignore(1000, '\n');
//    while ((ch = cin.get()) != '\n') {
//        str[i++] = ch;

//    }
//    str[i] = '\0';
//    return string(str);
    
//}
//int inputInteger(string msg)
//{
//    int val;
//    cout << msg;
//    while (((cin >> val)).fail())
//    {
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << "Ошибка при вводе" << endl <<msg;

//    }
//    return val;
//}
// float inputFloat(string msg)
//{
//    float val;                                 //проверка значения
//    cout << msg;
//    while (((cin >> val)).fail())
//    {
//        cin.clear();
//        cin.ignore(1000, '\n');
//        cout << "Ошибка при вводе" << endl << msg;

//    }
//    return val;
//}
void addPipe(unordered_map<int, Pipe>& mapOfP) { 

    Pipe newPipe;
    cin >> newPipe;
    mapOfP.insert(make_pair(newPipe.getIdentifier(), newPipe));

   // newPipe.setIdentifier(inputInteger("Введите идентификатор "));
   // newPipe.setLength(inputFloat("Введите длину "));
   // newPipe.setDiameter(inputFloat("Введите диаметр"));
   //// PIPE_EXIST = true;
   // int repaired  = inputInteger("Введите 1, если в ремонте или введите 0,если не в ремонте");
   // while (!(repaired == 0 || repaired == 1))
   // {
   //     cout << "Вы ввели число не в том диапозоне" << endl;
   //     repaired = inputInteger("Введите 1, если в ремонте или введите 0,если не в ремонте");
   // } 
   // newPipe.setRepaired(repaired);
 }
void addCS(unordered_map<int, CS>& mapOfCS) 
{
    CS newCS;
    cin >> newCS;
    mapOfCS.insert(make_pair(newCS.getIdentifier(), newCS));
    //newCS.identifier = inputInteger("Введите идентификатор ");
    //newCS.amount = inputInteger("Введите количество цехов");
    //CS_EXIST = true;
    //newCS.efficiency = inputFloat("Введите эффективность");
    //newCS.name= inputString("Введите название: ");
    
    //int amount_work = inputInteger("Введите количество рабочих цехов");
    //while (amount_work > newCS.amount) {
    //    cout << "Вы ввели не правильное количество рабочих цехов";
    //    amount_work = inputFloat("Введите количество рабочих цехов ");
    //}
    //newCS.amount_work = amount_work;
}


void ShowCS(unordered_map<int, CS>& mapOfCS)
{
    if (mapOfCS.size() == 0) cout << "Нет КС!";
    for (auto& cs : mapOfCS)
    {
        cout << cs.second;
    }
}

void ShowPipes(unordered_map<int, Pipe>& mapOfP)
{
    if (mapOfP.size() == 0) cout << "Нет труб!";
    for (auto& pipe : mapOfP)
    {
        cout << pipe.second;
    }
}

void showObjects(unordered_map<int, Pipe>& mapOfP, unordered_map<int, CS>& mapOfCS) {
    ShowCS(mapOfCS);
    ShowPipes(mapOfP);
}
void PipeModify(unordered_map<int, Pipe>& mapOfP) {
    int ID = inputInteger("Введите ID: ");
    while (mapOfP.find(ID) == mapOfP.end())
    {
        ID = inputInteger("Введите ID: ");
    }
    mapOfP[ID].setRepaired(!mapOfP[ID].getRepaired());
}
void CSModify(unordered_map<int, CS>& mapOfCS) {

    int ID = inputInteger("Введите ID: ");
    while (mapOfCS.find(ID) == mapOfCS.end())
    {
        ID = inputInteger("Введите ID: ");
    }

    int option = inputInteger("Если 1 то запустить цех,если 0 то остановить ");
    int res = (option == 1 ? mapOfCS[ID].getAmount_work() + 1 : mapOfCS[ID].getAmount_work() - 1);
    while (!(option == 0 || option == 1)|| res < 0 || res > mapOfCS[ID].getAmount())
    {
        cout << "Не возмжно остановить КС или запустить" << endl;
        option = inputInteger("Если 1 то запустить цех,если 0 то остановить");
        res = (option == 1 ? mapOfCS[ID].getAmount_work() + 1 : mapOfCS[ID].getAmount_work() - 1);
    }

    mapOfCS[ID].setAmount_work(res);
}
//void output(Pipe Pipe1, CS CS1)
//{
//    ofstream outf("file.txt");
//    if (!outf.is_open()) {
//        cout << "Файл не может быть открыт!\n";
//    }
//    else {
//        if (PIPE_EXIST)
//        {
//           // outf << 1 << endl;
//            outf   << Pipe1.identifier << endl;
//            outf <<  Pipe1.length << endl;
//            outf <<  Pipe1.diameter << endl;
//            outf <<  Pipe1.repaired << endl;
//        }
//        if (CS_EXIST)
//        {
//           // outf << 2 << endl;
            
//            outf <<  endl;
//            outf <<  CS1.identifier << endl;
//            outf <<  CS1.name << endl;
//            outf <<  CS1.amount << endl;
//            outf <<  CS1.amount_work << endl;
//            outf <<  CS1.efficiency << endl;
//        }
//    }
//    outf.close();
//}
//void input(Pipe& Pipe1, CS& CS1)
//{
//    ifstream fin("file.txt");
//    if (!fin.is_open())
//        cout << "Файл не может быть открыт!\n";
//    else
//    {
//        PIPE_EXIST = true;
//        CS_EXIST = true;
//        fin >> Pipe1.identifier >> Pipe1.length >> Pipe1.diameter >> Pipe1.repaired;
//        fin >> CS1.identifier >> CS1.name >> CS1.amount >> CS1.amount_work >> CS1.efficiency;
//    }
//    fin.close();
//}
void deleteCS(unordered_map<int, CS>& mapOfCS)
{
    int ID = inputInteger("Введите ID: ");
    while (mapOfCS.find(ID) == mapOfCS.end())
    {
        ID = inputInteger("Введите ID: ");
    }
    mapOfCS.erase(mapOfCS.find(ID));
}

void deletePipes(unordered_map<int, Pipe>& mapOfP)
{
    int ID = inputInteger("Введите ID: ");
    while (mapOfP.find(ID) == mapOfP.end())
    {
        ID = inputInteger("Введите ID: ");
    }
    mapOfP.erase(mapOfP.find(ID));
}

vector<int> CSFilterByName(unordered_map<int, CS>& mapCS, string str)
{
    vector<int> res;
    for (auto& cs1 : mapCS) {
        if (cs1.second.getName() == str) {
            res.push_back(cs1.first);
        }
    }
    return res;
}

vector<int> PipeFilter_Repaired(unordered_map<int, Pipe>& mapPipe, bool repaired)
{
    vector<int> res;
    for (auto& pipe1 : mapPipe) {
        if (pipe1.second.getRepaired()) {
            res.push_back(pipe1.first);
        }
    }
    return res;
}
float percent(CS cs1)
{
    return ((float)cs1.getAmount() - (float)cs1.getAmount_work()) / (float)cs1.getAmount() * 100;
}

vector<int> CSFilterByPerc(unordered_map<int, CS>& mapCS, float perc)
{
    vector<int> res;
    for (auto& cs1 : mapCS) {
        if (abs(percent(cs1.second) - perc) <= 1e-5) {
            res.push_back(cs1.first);
        }
    }
    return res;
}

void OutputToFile(unordered_map<int, CS>& mapOfCS, unordered_map<int, Pipe>& mapOfP, string str)
{

    ofstream fout;
    fout.open(str + ".txt");
    if (!fout.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {

        for (auto& it : mapOfCS)
        {
            fout << "cs" << endl;
            fout << it.second.getIdentifier() << endl;
            fout << it.second.getName() << endl;
            fout << it.second.getAmount() << endl;
            fout << it.second.getAmount_work() << endl;
            fout << it.second.getEfficiency() << endl << endl;
        }



        for (auto& it : mapOfP)
        {
            fout << "pipe" << endl;
            fout << it.second.getIdentifier() << endl;
            fout << it.second.getLength() << endl;
            fout << it.second.getDiameter() << endl;
            fout << (it.second.getRepaired() ? 1 : 0) << endl;
        }
        cout << "Вывели трубы и КС в файл";

        fout.close();
    }
}

void InputFromFile(unordered_map<int, CS>& mapCS, unordered_map<int, Pipe>& mapPipe, string str)
{
    ifstream fin(str + ".txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        mapPipe.clear();
        mapCS.clear();
        string buff;
        int maxid1 = -1;
        int maxid2 = -1;
        while (fin >> buff)
        {
            Pipe pipe1;
            Pipe::MaxID--;
            CS cs1;
            CS::MaxID--;
            if (buff == "pipe")
            {
                int id;
                fin >> id;
                pipe1.setIdentifier(id);
                float length;
                fin >> length;
                pipe1.setLength(length);
                float diameter;
                fin >> diameter;
                pipe1.setDiameter(diameter);
                int repaired;
                fin >> repaired;
                pipe1.setRepaired(repaired);
                mapPipe.insert(make_pair(pipe1.getIdentifier(), pipe1));
                if (maxid1 < id) maxid1 = id;
            }
            else
            {
                int id;
                fin >> id;
                cs1.setIdentifier(id);
                string name;
                fin >> name;
                cs1.setName(name);
                int amount;
                fin >> amount;
                cs1.setAmount(amount);
                int amount_work;
                fin >> amount_work;
                cs1.setAmount_work(amount_work);
                float efficiency;
                fin >> efficiency;
                cs1.setEfficiency(efficiency);
                mapCS.insert(make_pair(cs1.getIdentifier(), cs1));
                if (maxid2 < id) maxid2 = id;
            }
            Pipe::MaxID = maxid1;
            CS::MaxID = maxid2;
        }
    }
    cout << "Ввели из файла данные";
    fin.close();
}




void dfs(int v, unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, bool>& count, vector<int>& ans) {
    count[v] = true;
    vector<pair<int, int>> arr;
    if (g.find(v) != g.end()) {

        arr = g[v];
        for (auto& el : arr) {
            int to = el.first;

            if (!count[to])
                dfs(to, g, count, ans);
        }
    }
    ans.push_back(v);
}

unordered_map<int, bool> countCS(unordered_map<int, vector<pair<int, int>>>& g)
{
    unordered_map<int, bool> countArr;
    for (auto& el : g)
    {
        countArr[el.first] = false;
        for (auto& p1 : el.second)
        {
            countArr[p1.first] = false;
        }
    }
    return countArr;
}

void topologicalSort( unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, bool>& count, vector<int>& ans) {
    count = countCS(g);
       
    ans.clear();
    for (auto & el: count)
        if (!el.second)
            dfs(el.first, g, count, ans);
    reverse(ans.begin(), ans.end());
}


unordered_map<int, int> visitedCS(unordered_map<int, vector<pair<int, int>>>& g)
{
    unordered_map<int, int> countArr;
    for (auto& el : g)
    {
        countArr[el.first] = 0;
        for (auto& p1 : el.second)
        {
            countArr[p1.first] = 0;
        }
    }
    return countArr;
}

bool dfs2(int v, unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, int>& cl,  int& cycle_st) {
    if (g.find(v) == g.end())
    {
        return false;
    }
    cl[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to;
        to = g[v][i].first;
        if (cl[to] == 0) {
            if (dfs2(to, g, cl, cycle_st))  return true;
        }
        else if (cl[to] == 1) {
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}



bool searchForCycle(unordered_map<int, vector<pair<int, int>>>& graph)
{
    unordered_map<int, int> p;
    int cycle_st, cycle_end;
    p = visitedCS(graph);
    cycle_st = -1;
    for (auto& el : p)
            if (dfs2(el.first, graph, p, cycle_st)) break;
    if (cycle_st == -1) return false;
    else return true;
}

void addConnection(unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, CS>& mapCS, unordered_map<int, Pipe>& mapPipe, int idPipe, int idCS1, int idCS2)
{
    pair<int, int> p1;
    p1.second = idPipe;
    p1.first = idCS2;
    g[idCS1].push_back(p1);
}
void displayGraph(unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, CS>& mapOfCS, unordered_map<int, Pipe>& mapOfP)
{
    for (auto& el: g)
    {
        cout << "КС с ID " << el.first << " соединен с: ";
        for (auto cs = el.second.begin(); cs != el.second.end(); cs++)
        {
            cout << cs->first  << " кс длиной " << mapOfP[cs->second].getLength();
            if (cs + 1 != el.second.end()) cout << ", ";
        }
        cout << endl;
    }
}

bool check(unordered_map<int, vector<pair<int, int>>>& graph, unordered_map<int, CS>& mapOfCS, unordered_map<int, Pipe>& mapOfP, int& idCS)
{
    
    bool exist = false;
    vector<int> toDelete;
    if (graph.find(idCS) != graph.end())
    {
        graph.erase(idCS);
        exist = true;
    }
    for (auto el = graph.begin(); el != graph.end(); el++)
    {
        for (auto it = 0; it < el->second.size(); it++)
        {
            if (el->second[it].first == idCS) {
                el->second.erase(el->second.begin() + it);
                exist = true;
                toDelete.push_back(el->first);
            }
        }
    }
    return exist;
}

void deleteConnection(unordered_map<int, vector<pair<int, int>>>& g, unordered_map<int, CS> mapOfCS, unordered_map<int, Pipe>& mapOfP)
{
    int idCS = inputInteger("Введите ID КС: ");

    while (mapOfCS.find(idCS) == mapOfCS.end())
    {
        cout << "Введите еще раз, в сети нет такой КС!\n";
        idCS = inputInteger("Введите ID КС: ");
    }
    if (check(g, mapOfCS, mapOfP, idCS))
    {
        cout << "Успешно удален!\n";
    }
    else
    {
        cout << "Вершина не является истоком\n";
    }


}


void OutputGraphToFile(unordered_map<int, vector<pair<int, int>>> graph, string str)
{

    ofstream fout;
    fout.open(str + ".txt");
    if (!fout.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {

        for (auto& el : graph)
        {
            fout << el.second.size() << " ";
            fout <<  el.first << " ";
            for (auto cs = el.second.begin(); cs != el.second.end(); cs++)
            {
                fout << cs->first << " " << cs->second << " ";
            }
            fout << endl;
        }
        cout << "Вывели в файл данные";
        fout.close();
    }
}


void displayGraph(unordered_map<int, vector<pair<int, int>>>& graph)
{
    for (auto& el: graph)
    {
        cout << "КС с ID " << el.first << " соединен с: ";
        for (auto cs = el.second.begin(); cs != el.second.end(); cs++)
        {
            cout << cs->first  << " кс трубой " << cs->second;
            if (cs + 1 != el.second.end()) cout << ", ";
        }
        cout << endl;
    }
}


void InputGraphFromFile(unordered_map<int, vector<pair<int, int>>>& graph, string str)
{

    ifstream fin(str + ".txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        int buff;
        while (fin >> buff)
        {
            int CSid1;
            fin >> CSid1;
            for (int i = 0; i < buff; i++)
            {
                int CSid2;
                fin >> CSid2;
                int Pipeid;
                fin >> Pipeid;
                pair<int, int> pair1;
                pair1.first = CSid2;
                pair1.second = Pipeid;
                graph[CSid1].push_back(pair1);
            }
        }
        cout << "Ввели из файла данные";
        fin.close();
    }

}


int main()
{
    //Pipe Pipe1;
    unordered_map<int, Pipe> mapOfP;
    unordered_map<int, CS> mapOfCS;
    unordered_map<int, vector<pair<int, int>>> g;
    //CS CS1;
	setlocale(LC_ALL, "Russian");
    while (true) {
        cout << "1.Добавить трубу" << endl << "2.Добавить КС" << endl << "3.Просмотр всех объектов" << endl << "4.Редактировать трубу" << endl << "5.Редактировать КС"
            << endl << "6.Сохранить" << endl << "7.Загрузить" << endl << "8.Удалить трубу" << endl << "9.Удалить КС" << endl << "10.Фильтр по названию"   <<endl
            << "11.Фильтр по признаку в ремонте" << endl <<  "12.Фильтр по количеству незадействованных цехов" <<endl<<"13.Топологическая сортировка"<< endl << "14. Добавить КС и трубы" <<endl
            <<"15.Удалить граф"<<endl<<"16.Удалить ребро"<<endl<<"17.Удалить вершину" <<endl<<"18.Загрузить в граф файл"<<endl<<"19.Загрузить из файла" 
            <<endl<<"20.Показать граф"<<endl << "0.Выход" << endl;

        int Command = inputInteger("Введите команду: ");
        while (!(Command >= 0 && Command <= 20))
        {
            cout << "Вы ввели число не в том диапозоне" << endl;
            Command = inputInteger("Введите команду: ");
        }
        switch (Command) {
        case 1: {
            addPipe(mapOfP);
            break;
        }
        case 2: {
            addCS(mapOfCS);
            break;
        }
        case 3: {
            showObjects(mapOfP, mapOfCS);
            break;
        }
        case 4: {
            PipeModify(mapOfP);
            break;
        }
        case 5: {
            CSModify(mapOfCS);
            break;
        }
        case 6: {
            string str = inputString("Введите название: ");
            OutputToFile(mapOfCS, mapOfP, str);
            break;
        }
        case 7: {
            string str = inputString("Введите название: ");
            InputFromFile(mapOfCS, mapOfP, str);
            system("pause");
            break;
        }
        case 8: {
            deletePipes(mapOfP);
            break;
        }
        case 9: {
            deleteCS(mapOfCS);
            break;
        }
        case 10: {
            string str = inputString("Введите название: ");
            auto res = CSFilterByName(mapOfCS, str);
            for (auto& cs : res)
            {
                cout << mapOfCS[cs];
            }
            break;
        }
        case 11:
        {
            bool rep = inputInteger("Введите 1 или 0: соответственно в ремонте или не в ремонте");
            while (rep < 0 || rep > 1)
            {
                rep = inputInteger("Введите 1 или 0: соответственно в ремонте или не в ремонте");
            }
            auto res = PipeFilter_Repaired(mapOfP, rep);
            for (auto& pipe1 : mapOfP)
            {
                cout << pipe1.second;
            }
            break;
        }
        case 12:
        {
            float p = inputFloat("Введите процент незадействованных цехов: ");
            auto res = CSFilterByPerc(mapOfCS, p);
            for (auto& cs : res)
            {
                cout << mapOfCS[cs];
            }
            break;
        }
        case 13:
        {
            if (!searchForCycle(g))
            {
                unordered_map<int, bool> count;
                vector<int> ans;
                topologicalSort(g, count, ans);
                for (auto index = ans.begin(); index != ans.end(); index++)
                {
                    cout << *index;
                    if (index + 1 != ans.end()) cout << " -> ";
                }
            }
            else
            {
                cout << "Граф цикличный!";
            }
            break;
        }
        case 14:
        {
            if (mapOfCS.size() >= 2)
            {
                unordered_map<int, bool> usedPipes;

                for (auto& el : mapOfP)
                {
                    usedPipes.insert(make_pair(el.first, false));
                }
                for (auto& el : g)
                {
                    for (auto& p1 : el.second)
                    {
                        usedPipes[p1.first] = true;
                    }
                }
                int times = inputInteger("Сколько раз Вы собираетесь вводить?");
                int idPipe = 0, idCS1 = 0, idCS2 = 0;
                while (times > 0)
                {
                    idPipe = inputInteger("Введите ID трубы (введите 0, чтобы выйти): ");
                    if (idPipe == 0) break;
                    while (mapOfP.find(idPipe) == mapOfP.end() || usedPipes[idPipe] || mapOfP[idPipe].getRepaired())
                    {
                        cout << "Введите еще раз!\n";
                        idPipe = inputInteger("Введите ID трубы (введите 0, чтобы выйти): ");
                        if (idPipe == 0) break;
                    }
                    if (idPipe == 0) break;
                    usedPipes[idPipe] = true;
                    idCS1 = inputInteger("Введите ID КС1, от которой идет труба (введите 0, чтобы выйти): ");
                    if (idCS1 == 0) break;
                    while (mapOfCS.find(idCS1) == mapOfCS.end())
                    {
                        cout << "Введите еще раз!\n";
                        idCS1 = inputInteger("Введите ID КС1, от которой идет труба (введите 0, чтобы выйти): ");
                        if (idCS1 == 0) break;
                    }
                    if (idCS1 == 0) break;
                    idCS2 = inputInteger("Введите ID КС2, к которой идет труба (введите 0, чтобы выйти): ");
                    if (idCS2 == 0) break;
                    while (mapOfCS.find(idCS2) == mapOfCS.end())
                    {
                        cout << "Введите еще раз!\n";
                        idCS2 = inputInteger("Введите ID КС2, к которой идет труба (введите 0, чтобы выйти): ");
                        if (idCS2 == 0) break;
                    }
                    if (idCS2 == 0) break;
                    times--;
                    addConnection(g, mapOfCS, mapOfP, idPipe, idCS1, idCS2);
                }
                if (idPipe != 0 || idCS1 != 0 || idCS2 != 0) displayGraph(g, mapOfCS, mapOfP);
            }
            else
            {
                cout << "Недостаточно КС";
            }
            break;
        }
        case 15:
        {
            g.clear();
            cout << "Граф удалён!\n";
        }
        case 16:
        {
            int i = 1;
            for (auto& el : g)
            {
                for (auto it = el.second.begin(); it != el.second.end(); ++it)
                {
                    cout << "Номер ребрa: " << i << endl;
                    cout << el.first << " -> " << it->first << endl;
                    i++;
                }
            }
            int num = inputInteger("Введите номер ребра, который нужно удалить:");
            while (num <= 0 || num > i)
            {
                cout << "Неверный ввод:\n";
                num = inputInteger("Введите номер ребра, который нужно удалить:");
            }
            int i2 = 1;
            int res;
            int resI;
            bool fetched = false;
            for (auto& el : g)
            {
                if (fetched) break;
                for (auto it = 0; it < el.second.size() && !fetched; ++it)
                {
                    if (i2 == num)
                    {
                        res = it;
                        resI = el.first;
                        fetched = true;
                    }
                    i2++;
                }
            }
            g[resI].erase(g[resI].begin() + res);
            break;
        }
        case 17:
        {
            deleteConnection(g, mapOfCS, mapOfP);
            break;
        }
        case 18:
        {
            string str = inputString("Введите название: ");

            OutputGraphToFile(g, str);
            break;
        }
        case 19:
        {
            string str = inputString("Введите название: ");

            InputGraphFromFile(g, str);
            break;
        }
        case 20:
        {
            displayGraph(g);
        }
        case 0: {
            return 0;
        }
        }
    }
}

