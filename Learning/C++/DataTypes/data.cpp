#include <iostream>
using namespace std;

struct Sword
{
    int damage;
    string name;
    string enchant;
};


int main()
{
    Sword katana;
    katana.name = "Katana";
    katana.damage = 99;
    katana.enchant = "Flame";

    cout << "Name: " << katana.name << endl;
    cout << "Damage: " << katana.damage << endl;
    cout << "Enchant: " << katana.enchant << endl;
    system("pause>0");
}