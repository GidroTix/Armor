#include <string>
#include <iostream>

using namespace std;
class Armor
{
public:
    string Type;
    string NameOfElement;
    string Model;
    string Material;
    string Lvl_of_protectoins;
    int Weight;


    string getType() const;
    string getName() const;
    string getMaterial() const;
    double getLVL() const;
    double getWeight() const;

    bool checkState() const;
    void repair();
    virtual void getDamage() = 0;
    virtual void specialAction()=0;
};

class helmet: public Armor
{
public:
    string purpose(); //назначение шлема
    string visor(); //наличие забрала
    helmet(const string& type,const string& nameOfElement, const string& model)
    {
        Type=type;
        NameOfElement=nameOfElement;
        Model = model;
    }
};



class ChestPlate: public Armor
{
private:
    string The_partner(); //наличие напашника
    string Armored_loading(); // наличие бронеразгрузки
};

int main()
{
    helmet Altin ("shturm","Helmet","Altin")

    cout<<Altin.Type<<Altin.NameOfElement<<Altin.Model;
}
