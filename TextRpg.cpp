// TextRpg.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Functions.h"

int main() {
#pragma region Intro
    // Game start
    // Guard message 1
    std::cout << "Guard) Halt, stranger. Before entering Blue Watertown, I need you to fill out a form." << std::endl << "Just state your name and race and you are good to go." << std::endl;
    // Pause, press any key to continue
    system("pause");

    // String for later input, this will be the player's name
    std::string InputName;
    // Text indicating the player can interact
    std::cout << "State your name, traveler: ";
    // Player name input
    std::cin >> InputName;

    // Convert all characters to uppercase 
    for (char& characters : InputName) {
        characters = std::toupper(characters);
    }

    // Set the player object character's name: InputName
    ObjPlayer.setCharacterName(InputName);

    // Set a base value of 0 for the race index
    int RaceIndex = 0;
    // Loop through all Races
    for (std::string raceName : Race.Races)
    {
        // Output race index and name, player can later choose one of these races to play as
        std::cout << "[" << RaceIndex << "] " << raceName << std::endl;
        // Add 1 to the race index until we reach the last option
        RaceIndex++;
    }

    // Number for later input, this will be the player's race
    int RaceChoice;
    // Text indicating the player can interact
    std::cout << "Your race: ";
    // Race choice input
    std::cin >> RaceChoice;

    // Check if choice is available, else repeat
    while (RaceChoice > RaceIndex - 1 || RaceChoice < 0) {
        // Text indicating the player can interact
        std::cout << "Your race: ";
        // Player race input
        std::cin >> RaceChoice;
    }

    // Set the player object character's race: RaceChoice
    ObjPlayer.setCharacterRace(RaceChoice);

    // Acknowledgement of player's info
    std::cout << "Guard) Alright, " << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << ". You may enter Blue Watertown." << std::endl << "May luck guide you, bravery lead you.";
    ObjPlayer.setHealthPoints();
    // Set player's current health to the maximum amount
    ObjPlayer.setCurrentHealthPoints(ObjPlayer.getHealthPoints());
    // Set player's current stamina to the maximum amount
    ObjPlayer.setCurrentStaminaPoints(ObjPlayer.getStaminaPoints());

    // Initialize NPCs
    NPCDeclaration();

    // Perform ActionOptions function 
    ActionOptions();
#pragma endregion
    return 0;
}
