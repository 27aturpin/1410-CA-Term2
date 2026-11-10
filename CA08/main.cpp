#include <iostream>
#include "Loot.hpp"

using namespace std;

int main() {

    std::cout << "Chest value: ";
    // add Chest variable and output here
    Chest chest = Platinum;
    cout << chest << endl;

    //int x = c;
    //cout << x << endl;
    // implicit conversion
    std::cout << "Loot type number: ";
    // add LootType variable and output here
    LootType loot = LootType::Weapon;
    cout << static_cast<char>(loot) << endl;
    cout << lootTypeToString(loot) << endl;


    std::cout << "Loot in hand: ";
    // add Loot variable and output here
    Loot sword = {"Rusty Sword", LootType::Weapon, 10};
    cout << sword.name << " worth " << sword.value << endl;

    std::cout << "Loot from the chest: ";
    // add call to openChest and output here
    Loot drop = openChest(chest, sword);
    cout << drop.name << " worth " << drop.value << endl;
    cout << "Sword still worth " << sword.value << endl;


    std::cout << "Merchant offers: ";
    // add call to Merchant's offer here
    cout << Merchant::offer(drop) << endl;


    std::cout << "Blacksmith offers: ";
    // add call to Blacksmith's offer here
    cout << Blacksmith::offer(drop) << endl;
    std::cout << "End of Program.";
    return 0;
}