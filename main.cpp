#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "main.h"

//конструктор родительского класса, но уже в main.cpp
ActionOfArmor::ActionOfArmor()
{
    weight = int (rand() % 40 ); //1-40 выпадание веса
    Camuflazh = bool (rand() % 2 ); // 50% вероятность выпадения камуфляжа
    Nazn = Nazhachenie::Unknown;
    bool Put;                 //состояние (надето, или снято)
    int protect;              //степень защиты
    int ClassOfArmor;          //класс защиты (1-5)
    string Model;
    bool hasVisor;              //забрало
    bool hasFlash;              //фонарик
    int weight;
}

ArmorContainer::ArmorContainer(int maxSize) //конструктор для контейнера, содержащего броню
{
    ArmorBox = new ArmorPtr[maxSize];
    for(int i=0; i<maxSize; i++)
    {
        ArmorBox[i] = NULL;
    }
    ArmorCount = 0;
    MaxSize = maxSize;
}

ArmorContainer::~ArmorContainer() //деструктор для конструктора
{
    for (int i=0; i<MaxSize; i++)
    {
        if(ArmorBox[i]!=NULL)
        {
            delete ArmorBox[i];
            ArmorBox[i]=NULL;
        }
    }
    delete[] ArmorBox;
}

wstring PrintArmorType(const TypeOfArmor type) //функция определения вида брони
{
    switch(type)
    {
        case TypeOfArmor::Helmet:return L"Шлем";
        case TypeOfArmor::BodyArmor:return L"Бронежилет";
        case TypeOfArmor::Shield:return L"Щит";
        case TypeOfArmor::KneePads:return L"Наколенники";
        default: return L"Неизвестный тип брони";
    }
}

wstring PrintArmorNaznachenie(const Nazhachenie naznach) //функция определения вида брони
{
    switch(naznach)
    {
        case Nazhachenie::Ballistick:return L"Балиcтический";
        case Nazhachenie::Fehtovanie:return L"Для фехтования";
        case Nazhachenie::Oskolki:return L"Противоосколочный";
        case Nazhachenie::Shturm:return L"Штурмовой";
        case Nazhachenie::Speecial:return L"Специальный";
        case Nazhachenie::Tactical:return L"Тактический";
        default: return L"Неизвестный тип брони";
    }
}

void ArmorContainer::ArmorAdd(ArmorPtr newArmor) //функция создания брони
{
    ArmorBox[ArmorCount++] = newArmor;
}

void VivodArmor(ArmorContainer *armorBox) // функция вывода существующей брони без использования итератора
{
    for(int i = 0; i < armorBox->GetCount(); i++)
    {
        const ArmorPtr vivodArmor = armorBox->GetByIndex(i);
        wcout << i << L" (" << PrintArmorType(vivodArmor->GetArmor()) << L" )" << endl;
    }
}

void VivodPriPomoshiIteratora(Iterator<ArmorPtr> *it) // функция вывода существующей брони с помощью итератора
{
    for(it->First(); !it->IsDone(); it->Next())
    {
        const ArmorPtr vivodArmor = it->GetNumber();
        wcout << L" " << PrintArmorType(vivodArmor->GetArmor()) << L" = ";
        wcout << L" " << PrintArmorNaznachenie(vivodArmor->GetNaznach()) << endl;
    }
}

void Nasnachenie(Iterator<ArmorPtr> *it) //назначение
{
    for (it->First(); !it->IsDone(); it->Next())
    {
        const ArmorPtr vivodArmor = it->GetNumber();
        wcout<<PrintArmorType(vivodArmor->GetArmor())<<" = ";
        wcout<<(vivodArmor->DoCamuflazh() ? L"Камуфляж присутсвует":L"Камуфляж отсутсвует")<<endl;
    }
}

void Maskirovka(Iterator<ArmorPtr> *it)//наличие маскировки
{
    for (it->First(); !it->IsDone(); it->Next())
    {
        const ArmorPtr vivodArmor = it->GetNumber();
        wcout << PrintArmorType(vivodArmor->GetArmor()) << " = ";
        Nazhachenie nazn = vivodArmor->GetNaznach();
        wcout << PrintArmorNaznachenie(nazn) << endl;
    }
}


void VES (Iterator<ArmorPtr> *it)//НАЗНАЧЕНИЕ
{
    for (it->First(); !it->IsDone(); it->Next())
    {
        const ArmorPtr vivodArmor = it->GetNumber();
        wcout << PrintArmorType(vivodArmor->GetArmor()) << " = ";
        Nazhachenie ves = vivodArmor->GetNaznach();
        wcout << PrintArmorNaznachenie(ves) << endl;
    }
}

void getPicture() {
    string answer;

    while (true) {
        cout << "What about Picture? (yes/no) ";
        getline(cin, answer);

        if (answer == "yes") {
            cout << "=====================================================" << endl;
            cout << "=====================================================" << endl;
            cout << "====================*#@@@@@@@@@@@@@@%#+==============" << endl;
            cout << "=================#@@@@@@@@@@@@@@@@@@@@@@@%+==========" << endl;
            cout << "===============%@@@@@@@@@@@@@@@@@@@@@@@@@@@@#========" << endl;
            cout << "=============#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#======" << endl;
            cout << "==============+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=====" << endl;
            cout << "========*@@@@@@%#*++*%@@@@@@@@@@@@@@@@@@@@@@@@@@@+===" << endl;
            cout << "===*%%%#*+===+*%@@@@@@#+=*@@@@@@@@@@@@@@@@@@@@@@@%===" << endl;
            cout << "===****#%@@@@@@%#+=+*#@@@@%#**%@@@@@@@@@@@@@@@@@@@#==" << endl;
            cout << "==============+#%@@@@%*+=*%@@@@%*%@@@@@@@@@@@@@@@@@+=" << endl;
            cout << "====================+*@@@@@#++%@@@@@@@@@@@@@@@@@@@@#=" << endl;
            cout << "======================*@@@@@@@@%#@@@@@@@@@%@@@@@@@@%=" << endl;
            cout << "#@@@@@%#*=============@@@@%=%@@@@@@@@@@@@#*%*@@@@@@%=" << endl;
            cout << "#****#%%@@@@@%#*+====%@@@@@@@@@@@@@@@@@@###+%@@@@@@@+" << endl;
            cout << "====+++=====+*%@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@+" << endl;
            cout << "===@@@@@@@@@@%#+==++#@@@@*@@@@@@@@@@@@@@++@@@@###***=" << endl;
            cout << "==%@@@@@@@@@@@@@@@@@#*++#%@@@@@@@@@%+@@@@@@@@+@@@@@@%" << endl;
            cout << "=*@@@@@@@@@@@@@@@@@@@@@@@@%*%@@@@@@+#@@+%@@@@*%@@@@@@" << endl;
            cout << "+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@#%@@@@@" << endl;
            cout << "#*=+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@#=*#%%%#*==#@==" << endl;
            cout << "=========++*%@@@@@@@@@@@@@@@@@@@@#===*@@@@@@@@@@@*===" << endl;
            cout << "================+#%@@@@@@@@@@@@@%========++*++=======" << endl;
            cout << "=====================+*@@@@@@@@+=====================" << endl;
            cout << "===========================+=========================" << endl;
            cout << "=====================================================" << endl;
            cout << "=====================================================" << endl;

            return;
        } else if (answer == "no") {
            cout << "yes" << endl;
            return;
        } else {
            cout << "enter 'yes'" << endl;
        }
    }
}


//ФАБРИКА
ActionOfArmor *createArmor(TypeOfArmor type)
{
  switch(type)
    {
        case TypeOfArmor::Helmet:return new Helmet;
        case TypeOfArmor::BodyArmor:return new BodyArmor;
        case TypeOfArmor::Shield:return new Shield;
        case TypeOfArmor::KneePads:return new KneePads;
        default: return NULL;
    }
}

int main()
{
   //ArmorContainer armorBox(60);
    setlocale(LC_ALL, "Russian");
    SuperArmorContainerDVA armorBox;

    // Добавление брони в контейнер
    for (int i = 0; i < 15; i++)
    {
        armorBox.ArmorAdd(createArmor(TypeOfArmor(rand() % 4))); //выводим фабрику при помощи декоратора (4 т.к. у нас четыре класса брони)
    }
   /* for (int i = 0; i < 15; i++)
    {
        armorBox.ArmorAdd(new BodyArmor());
    }
    for (int i = 0; i < 15; i++)
    {
        armorBox.ArmorAdd(new Shield());
    }
    for (int i = 0; i < 15; i++)
    {
        armorBox.ArmorAdd(new KneePads());
    }
*/
    // Получение итератора и вывод брони
    Iterator<ArmorPtr>* it = new firstDECORATOR
    (new thirdDECORATOR(armorBox.GetIterator(), true),
    Nazhachenie::Ballistick); //вывести все элементы брони по типу назначения "Балистический"
    VivodPriPomoshiIteratora(it);
    delete it;

    getPicture();

    return 0;
}

