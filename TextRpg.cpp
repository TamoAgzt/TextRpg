// TextRpg.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Functions.h"

int main() {
#pragma region NPC Declaration
    // Declare NPCs and assign values
    // !!! Move to separate header !!!
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
    // Game start
    // Guard message 1
    std::cout << "Guard) Halt, stranger. Before entering Blue Watertown, I need you to fill out a form.\nJust state your name and race and you are good to go.\n";
    // Pause, press any key to continue
    system("pause");

    // String for later input, this will be the player's name
    std::string inputName;
    // Text indicating the player can interact
    std::cout << "State your name, traveler: ";
    // Player name input
    std::cin >> inputName;

    // Convert all characters to uppercase 
    for (char& characters : inputName) {
        characters = std::toupper(characters);
    }

    // Set the player object character's name: inputName
    ObjPlayer.setCharacterName(inputName);

    // Set a base value of 0 for the race index
    int raceIndex = 0;
    // Loop through all Races
    for (std::string raceName : Race.Races)
    {
        // Output race index and name, player can later choose one of these races to play as
        std::cout << "[" << raceIndex << "] " << raceName << "\n";
        // Add 1 to the race index until we reach the last option
        raceIndex++;
    }

    // Number for later input, this will be the player's race
    int raceChoice;
    // Text indicating the player can interact
    std::cout << "Your race: ";
    // Race choice input
    std::cin >> raceChoice;

    // Check if choice is available, else repeat
    while (raceChoice > raceIndex - 1 || raceChoice < 0) {
        // Text indicating the player can interact
        std::cout << "Your race: ";
        // Player race input
        std::cin >> raceChoice;
    }

    // Set the player object character's race: raceChoice
    ObjPlayer.setCharacterRace(raceChoice);

    // Acknowledgement of player's info
    std::cout << "Guard) Alright, " << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << ". You may enter Blue Watertown.\n";
    // Set player's current health to the maximum amount
    ObjPlayer.setCurrentHealthPoints(ObjPlayer.getHealthPoints());
    // Set player's current stamina to the maximum amount
    ObjPlayer.setCurrentStaminaPoints(ObjPlayer.getStaminaPoints());

    // Perform ActionOptions function 
    ActionOptions();
#pragma endregion
    return 0;
}
