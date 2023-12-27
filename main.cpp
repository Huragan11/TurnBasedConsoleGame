#include <iostream>
#include <vector>
#include "Pokemons.h"

std::vector<Pokemon> copied_pokemons;
std::vector<Pokemon> PlayerTeam;
std::vector<Pokemon> EnemyTeam;
int player_current_fighting;
int enemy_current_fighting;


bool my_pokemons_aint_dead(const std::vector<Pokemon> &team) {
    for (Pokemon p: team) {
        if (p.getHealthPoints() > 0) {
            return true;
        }
    }
    return false;
}// Returning TRUE or FALSE whether player team lost
bool enemy_pokemons_are_dead(const std::vector<Pokemon> &team) {
    for (Pokemon p: team) {
        if (p.getHealthPoints() > 0) {
            return false;
        }
    }
    return true;
} // Returning TRUE or FALSE whether enemy team lost
void player_turn_info(Pokemon &player_pokemon) {
    std::cout << "Your turn! Choose your action:\n" <<
              "1. Attack\n" <<
              "2. Swap Pokemon\n" <<
              "3. Use SpecialPower " << player_pokemon.getPower_info() << " || remain uses: "
              << player_pokemon.getSuperPowerAvailability() << "\n" <<
              "4. Evolve\n" <<
              "5. help\n";
} // Showing player's turn menu context
void player_turn() {

    Pokemon &player_pokemon = PlayerTeam.at(player_current_fighting);
    Pokemon &enemy_pokemon = EnemyTeam.at(enemy_current_fighting);
    player_turn_info(player_pokemon);
    bool keepAsking = true;
    while (keepAsking) {
        int choice;
        std::cin >> choice;
        int j = 1;
        switch (choice) {
            case 1:
                player_pokemon.Attack(enemy_pokemon);
                if (enemy_pokemon.getHealthPoints() < 0) {
                    player_pokemon.addXP(enemy_pokemon.getXPvalue());
                }
                keepAsking = false;
                std::cout << "\nYour pokemon attacked!\n";
                break;
            case 2:
                std::cout << "Swap with: \n";
                for (Pokemon p: PlayerTeam) {
                    if (p.getName() != player_pokemon.getName()) {
                        std::cout << "\n[" << j << "] ";
                        p.getInfo();
                    }
                    j++;
                }
                int choice_of_pokemon;
                std::cin >> choice_of_pokemon;
                player_current_fighting = choice_of_pokemon - 1;
                keepAsking = false;
                break;
            case 3:
                std::cout << "\nYour pokemon is using Special Power !\n";
                player_pokemon.SpecialPower(player_pokemon, enemy_pokemon);
                keepAsking = false;
                break;
            case 4:
                std::cout << "\nYour pokemon is trying to Evolve !\n";
                if (player_pokemon.canEvolve()) {
                    player_pokemon.Evolution();
                    keepAsking = false;
                    break;
                }
            case 5:
                player_turn_info(player_pokemon);

        }
    }
} // Executing player's choice in turn
void enemy_turn() {
    Pokemon &player_pokemon = PlayerTeam.at(player_current_fighting);
    Pokemon &enemy_pokemon = EnemyTeam.at(enemy_current_fighting);

    int choice = rand() % 3;
    switch (choice) {
        case 0:
            enemy_pokemon.Attack(player_pokemon);
            std::cout << "\nEnemy pokemon attacked!\n";
            break;
        case 1:
            std::cout << "\nEnemy pokemon is using Special Power !\n";
            enemy_pokemon.SpecialPower(enemy_pokemon, player_pokemon);
            break;
        case 2:
            std::cout << "\nEnemy is trying to Evolve !\n";
            if (enemy_pokemon.canEvolve()) {
                enemy_pokemon.Evolution();
                break;
            }

    }
} //Randomized enemy turn in fight
void round_won_info() {
    std::cout << "1. Continue\n" <<
              "2. Save Game\n" <<
              "3. help\n" <<
              "4. Exit\n";
}   // Showing menu context
void round_lost_info() {
    std::cout << "\n===== GAME OVER =====\n" <<
              "1. Load Game" <<
              "2. Exit\n" <<
              "3. help\n";
}   // Showing menu context


int main() {
    player_current_fighting = 0;
    enemy_current_fighting = 0;

    FirePokemon Charmander = FirePokemon("Charmander");
    FirePokemon Vulpix = FirePokemon("Vulpix");
    FirePokemon Growlithe = FirePokemon("Growlithe");

    WaterPokemon Squirtle = WaterPokemon("Squirtle");
    WaterPokemon Slowpoke = WaterPokemon("Slowpoke");
    WaterPokemon Horsea = WaterPokemon("Horsea");

    EarthPokemon Sandshrew = EarthPokemon("Sandshrew");
    EarthPokemon Geodude = EarthPokemon("Geodude");
    EarthPokemon Onix = EarthPokemon("Onix");

    WindPokemon Butterfree = WindPokemon("Butterfree");
    WindPokemon Pidgey = WindPokemon("Pidgey");
    WindPokemon Scyther = WindPokemon("Scyther");

    IcePokemon Lapras = IcePokemon("Lapras");
    IcePokemon Dewgong = IcePokemon("Dewgong");
    IcePokemon Glaceon = IcePokemon("Glaceon");

    SteelPokemon Magnemite = SteelPokemon("Magnemite");
    SteelPokemon Scizor = SteelPokemon("Scizor");
    SteelPokemon Aggron = SteelPokemon("Aggron");

    std::vector<Pokemon> pokemons = {Charmander, Vulpix, Growlithe,
                                     Squirtle, Slowpoke, Horsea,
                                     Sandshrew, Geodude, Onix,
                                     Butterfree, Pidgey, Scyther,
                                     Lapras, Dewgong, Glaceon,
                                     Magnemite, Scizor, Aggron};


    std::cout << "Welcome to the game!\n\n";
    std::cout << "1. New Game\n"
                 "2. Load previous game\n";

    int menu_choice;
    std::cin >> menu_choice;

    if (menu_choice == 2) {

    }
    if (menu_choice == 1) {
        std::cout << "Choose difficulty:\n"
                  << "1. Easy\n"
                  << "2. Normal\n"
                  << "3. Hard\n";
        int diff_choice;
        std::cin >> diff_choice;


        std::cout << "Choose 6 pokemons from a pool: \n";
        int i = 1;
        for (Pokemon p: pokemons) {
            std::cout << "[" << i++ << "] ";
            p.getInfo();
            std::cout << '\n';
        }
        for (int j = 0; j < 6; ++j) {
            int choice;
            std::cin >> choice;
            PlayerTeam.push_back(pokemons.at(choice - 1));
        }
        for (Pokemon &p: pokemons) {
            p.setDifficultyStats(diff_choice);
        }
        i = 1;
        std::cout << "\n===\n" << "THIS IS YOUR POKEMONS" << "\n===\n";
        for (Pokemon p: PlayerTeam) {
            std::cout << "[" << i++ << "] ";
            p.getInfo();
            std::cout << '\n';
        }
        int fight_number = 1;
        while (fight_number < 5) {
            copied_pokemons = pokemons;

            std::cout << "Round " << fight_number << "!\n";
            for (int j = 0; j < 4; j++) {
                int index = rand() % copied_pokemons.size();
                EnemyTeam.push_back(copied_pokemons.at(index));
                copied_pokemons.erase(copied_pokemons.begin() + index);
            }
            i = 1;
            std::cout << "\n===\n" << "ENEMY POKEMONS" << "\n===\n";
            for (Pokemon p: EnemyTeam) {
                std::cout << "[" << i++ << "] ";
                p.getInfo();
                std::cout << '\n';
            }
            while (my_pokemons_aint_dead(PlayerTeam) || !enemy_pokemons_are_dead(EnemyTeam)) {
                std::cout << "=========================================\n" <<
                          "Your Pokemon:\n";
                PlayerTeam.at(player_current_fighting).getInfo();
                std::cout << "\n" << "=========================================\n" <<
                          "Enemy Pokemon:\n";
                EnemyTeam.at(enemy_current_fighting).getInfo();
                std::cout << "=========================================\n";
                player_turn();
                if (EnemyTeam.at(enemy_current_fighting).getHealthPoints() <= 0) {
                    enemy_current_fighting += 1;
                    if (enemy_current_fighting == EnemyTeam.size()) {
                        break;
                    }
                }
                enemy_turn();
                if (PlayerTeam.at(player_current_fighting).getHealthPoints() <= 0) {
                    player_current_fighting += 1;
                }
                PlayerTeam.at(player_current_fighting).updateStatus();
                EnemyTeam.at(enemy_current_fighting).updateStatus();
            }
            int choice;
            bool ask = true;
            std::cout << "Round " << fight_number << " won!\n\n";
            while (ask) {
                if (my_pokemons_aint_dead(PlayerTeam)) {
                    round_won_info();
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            fight_number++;
                            ask = false;
                            break;
                        case 2:
                            break;
                        case 3:
                            round_won_info();
                            break;
                        case 4:
                            return 0;
                    }
                } else {
                    round_lost_info();
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            ask = false;
                            break;
                        case 2:
                            return 0;
                        case 3:
                            round_lost_info();
                            break;

                    }
                }
            }
        }

    }

}
