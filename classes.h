#ifndef ARMOR_H
#define ARMOR_H

#include <string>

class Armor {
protected:
    std::string type;
    std::string name;
    std::string material;
    std::string levelOfProtection;
    int weight;

public:
    Armor(std::string t, std::string n, std::string m, std::string lp, int w);

    std::string getType() const;
    std::string getName() const;
    std::string getMaterial() const;
    std::string getLevelOfProtection() const;
    int getWeight() const;

    bool checkState() const;
    void repair();
    virtual void getDamage() = 0;
    virtual void specialAction() = 0;
};

class Helmet : public Armor {
private:
    bool hasVisor;

public:
    Helmet(std::string t, std::string n, std::string m, std::string lp, int w, bool visor);

    void getDamage() override;
    void specialAction() override;
};

class ChestPlate : public Armor {
private:
    int armorLoading;

public:
    ChestPlate(std::string t, std::string n, std::string m, std::string lp, int w, int loading);

    void getDamage() override;
    void specialAction() override;
};

#endif // ARMOR_H
