#ifndef ArmorH
#define ArmorH
#include <string>
#include <vector>
#include <list>

using namespace std;

#include "Patterns.h"

//нумерованный класс по типу брони
enum class TypeOfArmor: int //перечисление видов брони
{
    Helmet,     //шлем
    BodyArmor,  //бронежилет
    Shield,     //щит
    KneePads,//наколенники
    Unknown
};
//нумерованный класс по назначению
enum class Nazhachenie: int
{
    Shturm,
    Tactical,
    Speecial,
    Ballistick,
    Oskolki,
    Fehtovanie,
    Unknown
};

//базовый класс брони (родительский)
class ActionOfArmor //возможности всех видов брони
{
protected:
    bool Put;                   //состояние (надето, или снято)
    int protect;                //степень защиты
    int ClassOfArmor;           //класс защиты (1-5)
    string Model;               //назначение брони (тип, модель)
    int weight;                 //вес
    bool Camuflazh;            //камуфляж
    Nazhachenie Nazn;        //тип брони по назначению

    ActionOfArmor();            //возможности брони
public:

    virtual ~ActionOfArmor() {};
    virtual void PutOn() = 0;           //надеть
    virtual void PutOut() = 0;          //снять
    virtual void FishkaDa() = 0;        //наличие фишки
    virtual void FishkaNet() = 0;       //отсутствие фишки
    virtual void FishkaDvaDa() = 0;     //вторая фишка
    virtual void FishkaDvaNet() = 0;    //отсутствие второй фишки
    virtual void Brak() = 0;            //брак
    int Wes() const {return weight;}
    int DoCamuflazh() const {return Camuflazh;}           //степень маскировки/камуфляжа
    virtual int OtechestvoRazrabotalo()const = 0; //год разработки
    virtual TypeOfArmor GetArmor() const = 0; //определяем броню
    virtual Nazhachenie GetNaznach() {return Nazn;}
};

typedef ActionOfArmor * ArmorPtr;

class Helmet : public ActionOfArmor //создаем класс "Шлем"
{
private:

    bool Put;                   //состояние (надето, или снято)
    int protect;              //степень защиты
    //прописать в Armor.cpp
    int ClassOfArmor;           //класс защиты (1-5)
    string Model;
    bool hasVisor;              //забрало
    bool hasFlash;              //фонарик

public:

    Helmet();
    virtual ~Helmet() {};
    void PutOn() {wcout << L"Надеть шлем" << endl;
    Put=true;protect+=10;}                                                                              //надели шлем
    void PutOut() {wcout << L"Ай, ай, ай, Мама бы сказала, что надо надеть!" << endl;
    Put = false;protect-=5;}           //сняли шлем
    void FishkaDa() {wcout << "Визор присутствует" << endl;
    hasVisor=true; protect+=10; }                                                            //наличие забрала у шлема
    void FishkaNet() {wcout << L"Визора нет " << endl;
    hasVisor=false; protect-=5;}                                                             //отсутствие забрала у шлема
    void FishkaDvaDa() {wcout << L"Фонарик присутствует" << endl;                             //фонарик есть
    hasFlash=true;}
    void FishkaDvaNet() {wcout << L"Фонарика нет " << endl;
    hasFlash=false;}                                                                        //фонарика нет
    void Brak() {wcout<< L"Попался БУ шлем, но пользоватсья можно" << endl; protect-=5;}       //попался брак

    int OtechestvoRazrabotalo() const
    {
        return rand() %15 + 2000 ;
    }


    TypeOfArmor GetArmor() const {return TypeOfArmor::Helmet;}                              //определяем непосредственно сам шлем

};

class BodyArmor : public ActionOfArmor //создаем класс "Жилет"
{
private:
    bool Put;                   //состояние (надето, или снято)
    int protect;              //степень защиты
    //прописать в Armor.cpp
    int ClassOfArmor;           //класс защиты (1-5)
    string Model;
    bool hasPartner;            //напашник
    bool hasRazgruz;            //разгрузка

public:

    BodyArmor();
    virtual ~BodyArmor() {}; //виртуальный диструктор
    void PutOn() {cout << "Надеть жилет" << endl;
    Put=true;protect+=15;}                                                                                  //надели жилет
    void PutOut() {cout << "Ай, ай, ай, Мама бы сказала, что надо надеть!" << endl;
    Put = false;protect-=10;}           //сняли жилет
    void FishkaDa() {cout << "Напашник присутствует" << endl;
    hasPartner=true; protect+=20;}                                                               //наличие напашника у жилета
    void FishkaNet() {cout << "Напашника нет " << endl;
    hasPartner=false; protect-=10;}                                                              //отсутствие напашника у жилета
    void FishkaDvaDa() {cout << "Разгрузка присутствует" << endl;                               //разгрузка есть
    hasRazgruz=true;}
    void FishkaDvaNet() {cout << "Разгрузки нет " << endl;
    hasRazgruz=false;}                                                                          //разгрузки нет
    void Brak() {cout<< "Попался БУ Жилет, но пользоватсья можно" << endl; protect-=5;}          //попался брак

    int OtechestvoRazrabotalo() const
    {
        return rand() %15 + 2000 ;
    }

    TypeOfArmor GetArmor() const {return TypeOfArmor::BodyArmor;}                               //определяем непосредственно сам жилвет

};

class Shield : public ActionOfArmor //создаем класс "Щит"
{
private:
    bool Put;                   //состояние (надето, или снято)
    int protect;              //степень защиты
    //прописать в Armor.cpp
    int ClassOfArmor;           //класс защиты (1-5)
    string Model;
    bool hasGlass;
    bool hasFonarik;

public:
    Shield();
    virtual ~Shield() {};
    void PutOn() {cout << "Взять щит" << endl;
    Put=true;}                                                                              //взяли щит
    void PutOut() {cout << "Ай, ай, ай, Мама бы сказала, что надо брать!" << endl;
    Put = false;}           //не стали брать щит
    void FishkaDa() {cout << "Стекло присутствует" << endl;
    hasGlass=true; protect+=10; }                                                            //наличие стекла у щита
    void FishkaNet() {cout << "Стекла нет " << endl;
    hasGlass=false; protect-=5; }                                                             //отсутствие стекла у щита
    void FishkaDvaDa() {cout << "Фонарик присутствует" << endl;                             //фонарик есть
    hasFonarik=true;}
    void FishkaDvaNet() {cout << "Фонарика нет " << endl;
    hasFonarik=false;}                                                                      //фонарика нет
    void Brak() {cout<< "Попался БУ щит, но пользоватсья можно" << endl; protect-=5; }        //попался брак

    int OtechestvoRazrabotalo() const
    {
        return rand() %15 + 2000 ;
    }

    TypeOfArmor GetArmor() const {return TypeOfArmor::Shield;}                              //определяем непосредственно сам щит
};

class KneePads : public ActionOfArmor //создаем класс "Наколенники"
{
private:
    bool Put;                   //состояние (надето, или снято)
    int protect;              //степень защиты
    //прописать в Armor.cpp
    int ClassOfArmor;           //класс защиты (1-5)
    string Model;
    bool hasArms;
    bool hasKnife;
public:

    KneePads();
    virtual ~KneePads() {};
    void PutOn() {cout << "Надеть наколенники" << endl;
    Put=true;}                                                                              //надели наколенники
    void PutOut() {cout << "Ай, ай, ай, Мама бы сказала, что надо всегда надевать!" << endl;
    Put = false;}  //сняли наколенники
    void FishkaDa() {cout << "Усиленные наколенники" << endl;
    hasArms=true; protect+=10; }                                                            //усиленные наколенники
    void FishkaNet() {cout << "Дешевые, китайские наколенники " << endl;
    hasArms=false; protect-=5; }
    void FishkaDvaDa() {cout << "Нож присутствует" << endl;                             //фонарик есть
    hasKnife=true;}
    void FishkaDvaNet() {cout << "Ножа нет " << endl;
    hasKnife=false;}                                                              //плохие наколенники
    void Brak() {cout<< "Попались БУ наколенники, но пользоватсья можно" << endl; protect-=5; }   //попался брак

    int OtechestvoRazrabotalo() const
    {
        return rand() %15 + 2000 ;
    }

    TypeOfArmor GetArmor() const {return TypeOfArmor::KneePads;}                            //определяем непосредственно сами наколенники
};

class ArmorContainerIteratorOdin : public Iterator<ArmorPtr>  //Итератор для первого контейнера
{
private:
    const ArmorPtr *ArmorBox;
    int Pos;
    int Count;
public:
    ArmorContainerIteratorOdin (const ArmorPtr *armorBox, int count)
    {
        ArmorBox = armorBox;
        Count = count;
        Pos = 0;
    }

    void First() {Pos = 0;}
    void Next() {Pos++;}
    bool IsDone() const {return Pos >= Count;}
    ArmorPtr GetNumber() const {return ArmorBox[Pos]; }
};

class ArmorContainer //первый контейнер, где используется итератор, который написан выше
{
private:
    ArmorPtr * ArmorBox;
    int ArmorCount;
    int MaxSize;
public:
    ArmorContainer(int maxSize);
    virtual ~ArmorContainer(); //это деструктор
    void ArmorAdd (ArmorPtr newArmor);
    int GetCount() const {return ArmorCount;}
    ArmorPtr GetByIndex(int index) const { return ArmorBox[index]; }

    Iterator<ArmorPtr> *GetIterator()
    {
        return new ArmorContainerIteratorOdin(ArmorBox, ArmorCount);
    }

};

//итератор для второго контейнера

class SuperArmorContainerIteratorDVA : public Iterator<ArmorPtr>
{
private:
    const list<ArmorPtr> *ArmorBox;
    list<ArmorPtr>::const_iterator it; //итератор, который не может изменить содержимое списка (говорилось на лекции!)

public:
    SuperArmorContainerIteratorDVA(const list<ArmorPtr> *armorBox)
    {
        ArmorBox = armorBox;
        it = ArmorBox->begin();
    }

    void First() { it = ArmorBox->begin(); }
    void Next() { it++; }
    bool IsDone() const { return it == ArmorBox->end(); }
    ArmorPtr GetNumber() const { return *it; }

};

//второй контейнер
class SuperArmorContainerDVA //будем добавлять снаряжение
{
private:
    list<ArmorPtr> ArmorBox;

public:
    void ArmorAdd (ArmorPtr newArmor) { ArmorBox.push_back(newArmor); }
    int GetCount() const {return ArmorBox.size(); }
    Iterator<ArmorPtr> *GetIterator()
    {
        return new SuperArmorContainerIteratorDVA(&ArmorBox);
    }

};

//декоратор вывода типа брони (ПЕРВЫЙ)
class firstDECORATOR : public IteratorDecorator <ArmorPtr>
{
private:
    Nazhachenie SearchNazn;
public:
    firstDECORATOR(Iterator<ArmorPtr> *it, Nazhachenie nazn): IteratorDecorator(it) { SearchNazn = nazn; }

    void First()
    {
        It->First();
        while (!It->IsDone() && It->GetNumber()->GetNaznach() != SearchNazn)
        {
            It->Next();
        }
    }
    void Next()
    {
        do
        {
            It->Next();
        }
        while (!It->IsDone() && It->GetNumber()->GetNaznach() != SearchNazn);

    }
};

//декоратор вывода веса  (ВТОРОЙ)
class secondDECORATOR : public IteratorDecorator<ArmorPtr>
{
private:
    int Ves;
public:
    secondDECORATOR(Iterator<ArmorPtr>* it, int ves) : IteratorDecorator(it) { Ves = ves; }

    void First()
    {
        It->First();
        while (!It->IsDone() && It->GetNumber()->Wes() != Ves)
        {
            It->Next();
        }
    }

    void Next()
    {
        do
        {
            It->Next();
        } while (!It->IsDone() && It->GetNumber()->Wes() != Ves);
    }

    bool IsDone() const
    {
        return It->IsDone();
    }

    ArmorPtr GetNumber() const
    {
        return It->GetNumber();
    }
};


//декоратор вывода камуфляжа (ТРЕТИЙ)
class thirdDECORATOR : public IteratorDecorator <ArmorPtr>
{
private:
    bool Kamufl;
public:
    thirdDECORATOR(Iterator<ArmorPtr> *it, bool kam): IteratorDecorator(it) { Kamufl = kam; }

    void First()
    {
        It->First();
        while (!It->IsDone() && It->GetNumber()->DoCamuflazh() != Kamufl)
        {
            It->Next();
        }
    }
    void Next()
    {
        do
        {
            It->Next();
        }
        while (!It->IsDone() && It->GetNumber()->DoCamuflazh() != Kamufl);
    }
};



#endif

