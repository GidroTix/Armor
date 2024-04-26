#include <iostream>
#include "main.h"

using namespace std;

Helmet::Helmet() //шлем
{
    Nazn = Nazhachenie::Ballistick;
    bool Put = false;                   //состояние (надето, или снято)
    int protect = 40;              //степень защиты
    int ClassOfArmor = 4;           //класс защиты (1-5)
    string Model = "Altin";
    bool hasVisor = false;              //забрало
    bool hasFlash = false;              //фонарик
    int weight = 4;
}

BodyArmor::BodyArmor() //жилет
{
    Nazn = Nazhachenie::Ballistick;
    bool Put = true;                   //состояние (надето, или снято)
    int protect = 50;              //степень защиты
    int ClassOfArmor = 4;           //класс защиты (1-5)
    string Model = "6B45 - Ratnik";              //цвет
    bool hasPartner = true;
    bool hasRazgruz = true;
    int weight = 10;
}

Shield::Shield() //щит
{
    Nazn = Nazhachenie::Tactical;
    bool Put = true;                   //состояние (надето, или снято)
    int protect = 30;              //степень защиты
    int ClassOfArmor = 4;           //класс защиты (1-5)
    string Model = "Matreshka";             //цвет
    bool hasGlass = false;
    bool hasFonarik = true;
    int weight = 20;

}

KneePads::KneePads() //наколенники
{
    Nazn = Nazhachenie::Shturm;
    bool Put = true;                   //состояние (надето, или снято)
    int protect = 30;              //степень защиты
    int ClassOfArmor = 4;           //класс защиты (1-5)
    string Model = "Dobrynia";
    bool hasArms = false;
    bool hasKnife = true;
    int weight = 1;
}

