#pragma once
#include <string>
using namespace std;

enum Chest { Wood = 1, Iron = 2, Gold = 5, Platinum = 8 };

enum class Coin { Silver, Gold };
enum class LootType { Weapon = 'W', Armor = 'A', Potion = 'P'};

string lootTypeToString(LootType type) {
    switch(type) {
        case LootType::Weapon:
            return "Weapon";
        case LootType::Armor:
            return "Armor";
        case LootType::Potion:
            return "Potion";
    }
    return "";
}

struct Loot {
    string name;
    LootType type;
    int value;
};

Loot openChest(Chest chest, Loot loot) {
    Loot retLoot = {"", LootType::Weapon, loot.value * static_cast<int>(chest)};
    return retLoot;

    //this also works and is more simple, auto has values already instead of resetting
    //loot.value *= chest;
    //return loot;
}

namespace Merchant {
    int offer(const Loot& loot);
}

namespace Blacksmith {
    int offer(const Loot& loot) {
        if(loot.type == LootType::Potion) {
            return 0;
        }
            return loot.value * 2;
    }
}
// merchant
int Merchant::offer(const Loot& loot) {
    switch(loot.type) {
        case LootType::Weapon:
            return loot.value;
        case LootType::Armor:
            return loot.value / 2;
        case LootType::Potion:
            return loot.value * 2;
    }
    return 0;
}

