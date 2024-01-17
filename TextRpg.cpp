// TextRpg.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Character.h"



#pragma region Declare functions
void ActionOptions();
void CharacterSheet();
void BattleSequence();
void DialogueSequence();   
void Rest();
#pragma endregion

// Globally declare player object from header.
C_Player ObjPlayer;

int main() {
#pragma region NPC Declaration
    C_Character ObjNPC_TavernKeeper, ObjNPC_Borka, ObjNPC_Bookman, ObjNPC_Bandit01, ObjNPC_Bandit02, ObjNPC_Bandit03;
    ObjNPC_TavernKeeper.setCharacterName("Tavern Keeper");
    ObjNPC_TavernKeeper.setCharacterRace(0);
    ObjNPC_TavernKeeper.setHostility(false);

    ObjNPC_Borka.setCharacterName("Worm Borka");
    ObjNPC_Borka.setCharacterRace(0);
    ObjNPC_Borka.setHostility(false);

    ObjNPC_Bookman.setCharacterName("Old Bookman");
    ObjNPC_Bookman.setCharacterRace(1);
    ObjNPC_Bookman.setHostility(false);

    ObjNPC_Bandit01.setCharacterName("Bandit 1");
    ObjNPC_Bandit01.setCharacterRace(0);
    ObjNPC_Bandit01.setHostility(true);

    ObjNPC_Bandit02.setCharacterName("Bandit 2");
    ObjNPC_Bandit02.setCharacterRace(0);
    ObjNPC_Bandit02.setHostility(true);

    ObjNPC_Bandit03.setCharacterName("Bandit 3");
    ObjNPC_Bandit03.setCharacterRace(1);
    ObjNPC_Bandit03.setHostility(true);
#pragma endregion

#pragma region Intro
    std::cout << "Guard) Halt, stranger. Before entering Blue Watertown, I need you to fill out a form.\nJust state your name and race and you are good to go.\n";

    std::string inputName;
    std::cout << "State your name, traveler: ";
    std::cin >> inputName;

    ObjPlayer.setCharacterName(inputName);

    int raceIndex = 0;
    for (std::string raceName : Race.Races)
    {
        std::cout << "[" << raceIndex << "] " << raceName << "\n";
        raceIndex++;
    }

    int raceChoice;
    std::cout << "Your race: ";
    std::cin >> raceChoice;

    // Check if choice is available, else repeat
    while (raceChoice > raceIndex - 1 || raceChoice < 0) {
        std::cout << "Your race: ";
        std::cin >> raceChoice;
    }

    ObjPlayer.setCharacterRace(raceChoice);
    //int maxHp = ObjPlayer.getHealthPoints();
    //ObjPlayer.getCurrentHealthPoints(maxHp);

    std::cout << "Guard) Alright, " << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << ". You may enter Blue Watertown.\n";
    ObjPlayer.setCurrentHealthPoints(ObjPlayer.getHealthPoints());
    ObjPlayer.setCurrentStaminaPoints(ObjPlayer.getStaminaPoints());

#pragma endregion

    ActionOptions();

    return 0;
}

void CharacterSheet() {
    std::cout << FOURLINE;
    if (ObjPlayer.getUpgradePoints() != 0) {
        std::cout << "You have " << ObjPlayer.getUpgradePoints() << " upgrade point(s) to spend.\n";
    }

    std::cout << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << TWOLINE << "Health: " << ObjPlayer.getCurrentHealthPoints() << "/" << ObjPlayer.getHealthPoints() << "\n" << "Attack points: " << ObjPlayer.getAttackPoints() << "\n" << "Stamina: " << ObjPlayer.getCurrentStaminaPoints() << "/" << ObjPlayer.getStaminaPoints() << TWOLINE;
    std::string upgradeChoice;

    if (ObjPlayer.getUpgradePoints() != 0) {
        std::cout << "Select an attribute to use 1 upgrade pointon.\n[Health], [Attack], [Stamina]\n";
        std::cin >> upgradeChoice;
        if (upgradeChoice == "health") {
            ObjPlayer.setUpgradeHealth();
            std::cout << FOURLINE;
            CharacterSheet();
        } else if (upgradeChoice == "attack") {
            ObjPlayer.setUpgradeAttack();
            std::cout << FOURLINE;
            CharacterSheet();
        } else if (upgradeChoice == "stamina") {
            ObjPlayer.setUpgradeStamina();
            std::cout << FOURLINE;
            CharacterSheet();
        }
    }
    ActionOptions();
}

void Rest() {
    std::cout << FOURLINE;
    ObjPlayer.setCurrentHealthPoints(ObjPlayer.getHealthPoints());
    ObjPlayer.setCurrentStaminaPoints(ObjPlayer.getStaminaPoints());
    std::cout << "You feel healthy and energetic!";
    ActionOptions();
}

void BattleSequence() {
// Attacks and heals get a "dice roll", an rng from 1 to 20, 1-3 action failed, 4-7 effect is reduced by 20 to 30%, 8-14 base effect, 15 to 19 effect is enhanced by 20 to 30$, 20 effect is doubled.
// Or implement "dice rolls" where 1-3 = big negative multiplier, but not 0

}

void DialogueSequence() {}

void ActionOptions() {
    std::cout << FOURLINE;

    for (int i = 0; i < 100000000; i++) {
        if (ObjPlayer.getUpgradePoints() != 0) {
            std::cout << "You can level up, open your character sheet to assign your upgrade point(s)!\n[CHR]\n";
        }
        std::string commandInput;
        std::cout << "[CHR], [REST], ";
        std::cin >> commandInput;
        std::cout << commandInput;

        if (commandInput == "f") {
            ObjPlayer.setLevelUp();
            std::cout << FOURLINE;
        }
        else if (commandInput == "chr") {
            CharacterSheet();
            std::cout << FOURLINE;
            break;
        }
        else if (commandInput == "rest") {
            Rest();
            std::cout << FOURLINE;
            break;
        }

    }
}