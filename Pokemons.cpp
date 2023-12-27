//
// Created by huber on 08.06.2022.
//
#include <iostream>
#include <utility>
#include "Pokemons.h"

Pokemon::Pokemon() {
    HealthPoints = 30;
    AttackPoints = 7;
    DexterityPoints = 0.20;
    XPearned = 0;
    EvolutionXP = 50;
    status = normal;
    SuperPowerAvailability = 1;
    defense = 0;
    XPvalue = 25;
    type = not_defined;
    power = none;
} // Default pokemon constructor. Initializes default values;




void Pokemon::SpecialPower(Pokemon &me, Pokemon &enemy) {
    if (SuperPowerAvailability > 0) {
        if (power == Ember) {
            enemy.setStatus(burning);
        } else if (power == Blaze) {
            enemy.setHealthPoints(enemy.getHealthPoints() - 10);
        } else if (power == MagmaBall) {
            enemy.setStatus(burning);
            enemy.setHealthPoints(enemy.getHealthPoints() - 5);
        } else if (power == SwiftSwim) {
            me.setDexterityPoints(me.getDexterityPoints() + 0.30);
        } else if (power == WaterVeil) {
            enemy.setHealthPoints(enemy.getHealthPoints() - 5);
            enemy.setStatus(exhausted);
            enemy.setAttackPoints(enemy.getAttackPoints() - 3);
        } else if (power == Hydration) {
            me.setHealthPoints(me.getHealthPoints() + 7);
        } else if (power == RockArmor) {
            me.addDefense(5);
        } else if (power == Earthquake) {
            enemy.setStatus(stunned);
        } else if (power == Dig) {
            me.setHealthPoints(me.getHealthPoints() + 10);
        } else if (power == HighDive) {
            enemy.setHealthPoints(enemy.getHealthPoints() - 5);
            enemy.setStatus(dizzy);
            enemy.setDexterityPoints(enemy.getDexterityPoints() - 0.15);
        } else if (power == Tornado) {
            enemy.setStatus(stunned);
        } else if (power == WingSlap) {
            enemy.setHealthPoints(enemy.getHealthPoints() - 10);
        }
        if (power == Freeze) {
            enemy.setStatus(stunned);
        } else if (power == SnowCloak) {
            me.setDexterityPoints(me.getDexterityPoints() + 0.20);
        } else if (power == IceBody) {
            me.addDefense(3);
        } else if (power == MetalFist) {
            enemy.setHealthPoints(enemy.getHealthPoints() - 10);
        } else if (power == PoisonSpike) {
            enemy.setStatus(poisoned);
        } else if (power == LightMetal) {
            me.setDexterityPoints(me.getDexterityPoints() + 0.15);
        }
        SuperPowerAvailability -= 1;
    } else {
        std::cout << "Cannot use it right now\n\n";
    }
}

double Pokemon::effectivness(Pokemon &p) {
    switch (p.getType()) {
        case water:
            if (type == water || type == fire || type == ice) {
                return 0.75;
            } else if (type == earth || type == wind) {
                return 1;
            } else {
                return 1.25;
            }

        case earth:
            if (type == wind || type == fire) {
                return 0.75;
            } else if (type == earth || type == steel) {
                return 1;
            } else {
                return 1.25;
            }
        case wind:
            if (type == earth) {
                return 0.75;
            } else if (type == water || type == wind || type == fire || type == ice) {
                return 1;
            } else {
                return 1.25;
            }
        case fire:
            if (type == ice || type == steel) {
                return 0.75;
            } else if (type == wind || type == fire) {
                return 1;
            } else {
                return 1.25;
            }
        case ice:
            if (type == ice) {
                return 0.75;
            } else if (type == steel || type == water) {
                return 1;
            } else {
                return 1.25;
            }
        case steel:
            if (type == wind || type == steel) {
                return 0.75;
            } else if (type == ice || type == water) {
                return 1;
            } else {
                return 1.25;
            }
    }
}

bool Pokemon::canEvolve() const {
    if (XPearned >= EvolutionXP) {
        return true;
    } else {
        std::cout << " Not enough XP!\n";
        return false;
    }
}

int Pokemon::getSuperPowerAvailability() const {
    return SuperPowerAvailability;
}

int Pokemon::getDefense() const {
    return defense;
}

double Pokemon::getDexterityPoints() const { return DexterityPoints; }

double Pokemon::getAttackPoints() const { return AttackPoints; }

double Pokemon::getHealthPoints() const { return HealthPoints; }

int Pokemon::getXPvalue() const { return XPvalue; }

std::string Pokemon::getType_info() const {
    switch (type) {
        case fire:
            return "Fire";
        case water:
            return "Water";
        case earth:
            return "Earth";
        case wind:
            return "Wind";
        case ice:
            return "Ice";
        case steel:
            return "Steel";
    }
}

std::string Pokemon::getPower_info() const{

    switch (type) {
        case fire:
            if (power == Ember)
                return "Ember";
            if (power == Blaze)
                return "Blaze";
            if (power == MagmaBall)
                return "Magma Ball";
        case water:
            if (power == SwiftSwim)
                return "SwiftSwim";
            if (power == WaterVeil)
                return "WaterVeil";
            if (power == Hydration)
                return "Hydration";
        case earth:
            if (power == RockArmor)
                return "Rock Armor";
            if (power == Earthquake)
                return "Earthquake";
            if (power == Dig)
                return "Dig";
        case wind:
            if (power == WingSlap)
                return "Wing Slap";
            if (power == Tornado)
                return "Tornado";
            if (power == HighDive)
                return "High Dive";
        case ice:
            if (power == Freeze)
                return "Freeze";
            if (power == SnowCloak)
                return "Snow Cloak";
            if (power == IceBody)
                return "Ice Body";
        case steel:
            if (power == MetalFist)
                return "Metal Fist";
            if (power == PoisonSpike)
                return "Iron Thorns";
            if (power == LightMetal)
                return "Light Metal";
    }
}

Type Pokemon::getType() const {
    return type;
}

std::string Pokemon::getStatus_info() const{
    switch (status) {
        case normal:
            return "Normal";
        case dizzy:
            return "Dizzy";
        case exhausted:
            return "Exhausted";
        case poisoned:
            return "Poisoned";
        case burning:
            return "Burning";
        case stunned:
            return "Stunned";
    }
}

std::string Pokemon::getName() const {
    return name;
}

void Pokemon::getInfo() const {
    std::cout << "Name: " << name <<
              '\n' << "HealthPoints: " << HealthPoints <<
              '\n' << "AttackPoints: " << AttackPoints <<
              '\n' << "DexterityPoints: " << DexterityPoints <<
              '\n' << "XP: " << XPearned << '/' << EvolutionXP <<
              '\n' << "Pokemon type: " << getType_info() <<
              '\n' << "Status: " << getStatus_info() <<
              '\n' << "Super Power: " << getPower_info() <<
              '\n' << "Defense: " << getDefense() <<
              '\n' << "Super Power uses available: " << SuperPowerAvailability << std::endl;

}

FirePokemon::FirePokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    HealthPoints -= 5;
    AttackPoints += 2;
    type = fire;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = Ember;
            break;
        case 1:
            power = Blaze;
            break;
        case 2:
            power = MagmaBall;
            break;
    }

}

WaterPokemon::WaterPokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    DexterityPoints += 0.20;
    AttackPoints -= 2;
    type = water;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = SwiftSwim;
            break;
        case 1:
            power = WaterVeil;
            break;
        case 2:
            power = Hydration;
            break;
    }
}

EarthPokemon::EarthPokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    HealthPoints += 15;
    AttackPoints -= 4;
    DexterityPoints -= 0.10;
    type = earth;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = RockArmor;
            break;
        case 1:
            power = Earthquake;
            break;
        case 2:
            power = Dig;
            break;
    }
}

WindPokemon::WindPokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    HealthPoints -= 10;
    DexterityPoints += 0.35;
    type = wind;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = HighDive;
            break;
        case 1:
            power = Tornado;
            break;
        case 2:
            power = WingSlap;
            break;
    }

}

IcePokemon::IcePokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    HealthPoints += 5;
    DexterityPoints += 0.10;
    AttackPoints -= 2;
    type = ice;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = Freeze;
            break;
        case 1:
            power = SnowCloak;
            break;
        case 2:
            power = IceBody;
            break;
    }
}

SteelPokemon::SteelPokemon(std::string name) : Pokemon() {
    this->name = std::move(name);
    HealthPoints += 20;
    DexterityPoints -= 0.15;
    AttackPoints -= 5;
    type = steel;
    int rand_power = rand() % 3;
    switch (rand_power) {
        case 0:
            power = MetalFist;
            break;
        case 1:
            power = PoisonSpike;
            break;
        case 2:
            power = LightMetal;
            break;
    }
}




