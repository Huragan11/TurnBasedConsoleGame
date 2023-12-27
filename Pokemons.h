//
// Created by huber on 07.06.2022.
//

#ifndef GRA_TUROWA_POKEMONS_H
#define GRA_TUROWA_POKEMONS_H

enum Status {
    normal, //clean, no modifier
    dizzy, //lower dodge chance
    exhausted, //lower attack points
    poisoned, //getting hit each round
    burning, //getting hit each round
    stunned, //stun for round

};
enum SuperPower {
    Ember,  //setting enemy on fire
    Blaze,  //hitting enemy big HP
    MagmaBall,  //making enemy burning and hit

    SwiftSwim,  //making myself more capable od dodge
    WaterVeil,  //hit enemy and makes him exhausted
    Hydration,  //heal myself a little

    RockArmor,  //taking less dmg
    Earthquake, //making enemy stunned
    Dig,    //heal myself

    HighDive,   // hit enemy and makes him dizzy
    Tornado,    //making enemy stunned
    WingSlap,   //hit enemy

    Freeze, //making enemy stunned
    SnowCloak,  //makes me more capable of dodging
    IceBody,    //taking less dmg

    MetalFist, //hitting enemy big DMG
    PoisonSpike, //making enemy poisoned
    LightMetal, //makes me more capable of dodging

    none,

};
enum Type {
    water,
    earth,
    wind,
    fire,
    ice,
    steel,
    not_defined,
};


class Pokemon {
public:

protected:
    std::string name;
    double HealthPoints;
    double AttackPoints;
    double DexterityPoints;
    int XPearned;
    int defense;
    double EvolutionXP;
    Type type;
    Status status;
    SuperPower power;
    int SuperPowerAvailability;
    int XPvalue;

public:
    Pokemon();
    //================Setters================
    void setDifficultyStats(int diff_choice) {
        switch (diff_choice) {
            case 1:
                HealthPoints *= 0.75;
                AttackPoints *= 0.75;
                DexterityPoints *= 0.75;
                EvolutionXP *= 1.25;
                break;
            case 3:
                HealthPoints *= 1.25;
                AttackPoints *= 1.25;
                DexterityPoints *= 1.25;
                EvolutionXP *= 0.75;
                break;
            case 2:
                break;
            default:
                break;
        }
    } // Changes statistics of a pokemon based on value given as argument

    void setStatus(Status s) { status = s; } // Sets status of this pokemon to status given as argument

    void setHealthPoints(int i) { HealthPoints = i; } // Sets HealthPoints value to value given as argument

    void setAttackPoints(int i) { AttackPoints = i; } // Sets AttackPoints value to value given as argument

    double setDexterityPoints(double i) { DexterityPoints = i; } // Sets dexterity value

    //================Getters================
    int getXPvalue() const; // Returns XP value of this pokemon

    double getHealthPoints() const; // Returns current HealthPoints value

    double getAttackPoints() const; // Returns current AttackPoints value

    double getDexterityPoints() const; // Returns current dexterity value

    Type getType() const;  // Returns pokemon type as enum

    std::string getType_info() const; // Returns info about pokemon type

    std::string getStatus_info() const; // Returns current pokemon status indo

    std::string getPower_info() const; // Returns name of pokemon's Super Power

    int getSuperPowerAvailability() const; // Returns number of Super Powers uses left

    std::string getName() const; // Returns name

    int getDefense() const; // Returns defense value

    void getInfo() const;// Showing info about pokemon


    //================Methods================
    void addDefense(int i) {
        defense += i;
    }// Adding value given as agrument to this pokemon's defense value

    void updateStatus() {
        if (status == burning) {
            setHealthPoints(getHealthPoints() - 2);
        } else if (status == poisoned)
            setHealthPoints(getHealthPoints() - 4);
    }// Checks if pokemon has a specified status that needs an update

    void addXP(int xp) {
        XPearned += xp;
    } //Increasing XP earned value;

    void Attack(Pokemon &p) {
        p.setHealthPoints(p.getHealthPoints() - (AttackPoints * effectivness(p) - p.defense));
    } //Executes an Attack on pokemon given as argument multiplied by effectivness

    double effectivness(Pokemon &p); // Return double value which indicates effectivness

    bool canEvolve() const; // Returns whether Pokemon can evolve or not

    void Evolution() {
        int choice;
        int choice_counter = 0;
        std::cout << "Choose 2 stats to upgrade: \n" <<
                  "1. HealthPoints + 15\n" <<
                  "2. AttackPoints + 5\n" <<
                  "3. Defense + 5\n";
        while (choice_counter < 2) {
            std::cin >> choice;
            switch (choice) {
                case 1:
                    HealthPoints += 15;
                    break;
                case 2:
                    AttackPoints += 5;
                    break;
                case 3:
                    defense += 5;
                    break;
            }
            choice_counter++;
        }
        XPearned = 0;
        EvolutionXP += 30;
        XPvalue += 10;
        std::cout << "Pokemon evolved!\n";
    } // Changing stats of pokemon pointed by player

    void SpecialPower(Pokemon &me, Pokemon &enemy); //Executing 1. pokemon super power on himself or enemy's
};


class FirePokemon : public Pokemon {
public:
    FirePokemon(std::string name);

};

class WaterPokemon : public Pokemon {
public:
    WaterPokemon(std::string name);
};

class EarthPokemon : public Pokemon {
public:
    EarthPokemon(std::string name);
};

class WindPokemon : public Pokemon {
public:
    WindPokemon(std::string name);
};

class IcePokemon : public Pokemon {
public:
    IcePokemon(std::string name);
};

class SteelPokemon : public Pokemon {
public:
    SteelPokemon(std::string name);
};


#endif //GRA_TUROWA_POKEMONS_H
