#pragma once

#include "Character.h"

// Globally declare player object from character header.
C_Player ObjPlayer;

#pragma region Declare functions
// Declare functions to use later
void ActionOptions();
void CharacterSheet();
void BattleSequence();
void DialogueSequence();
void Rest();
#pragma endregion

// See "Character Sheet" in Gameplay.md
void CharacterSheet() {
    // Insert four line breaks
    std::cout << FOURLINE;

    // Check if player has upgrade points
    if (ObjPlayer.getUpgradePoints() > 0) {
        // Output amount of points available
        std::cout << "You have " << ObjPlayer.getUpgradePoints() << " upgrade point(s) to spend.\n";
    }

    // Output player's info
    std::cout << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << TWOLINE << "Health: " << ObjPlayer.getCurrentHealthPoints() << "/" << ObjPlayer.getHealthPoints() << "\n" << "Attack points: " << ObjPlayer.getAttackPoints() << "\n" << "Stamina: " << ObjPlayer.getCurrentStaminaPoints() << "/" << ObjPlayer.getStaminaPoints() << TWOLINE;

    // Perform ActionOptions function 
    ActionOptions();
}

void Rest() {
    // Insert four line breaks
    std::cout << FOURLINE;
    // Set player's current health to the maximum amount
    ObjPlayer.setCurrentHealthPoints(ObjPlayer.getHealthPoints());
    // Set player's current stamina to the maximum amount
    ObjPlayer.setCurrentStaminaPoints(ObjPlayer.getStaminaPoints());
    // Output fitting message
    std::cout << "You feel healthy and energetic!";

    // Perform ActionOptions function 
    ActionOptions();
}

void BattleSequence() {
    // Attacks and heals get a "dice roll", an rng from 1 to 20, 1-3 action failed, 4-7 effect is reduced by 20 to 30%, 8-14 base effect, 15 to 19 effect is enhanced by 20 to 30$, 20 effect is doubled.
    // Or implement "dice rolls" where 1-3 = big negative multiplier, but not 0

}

void DialogueSequence() {
    // Insert four line breaks
    std::cout << FOURLINE;
}

void ActionOptions() {
    // Insert four line breaks
    std::cout << FOURLINE;

    for (int i = 0; i < 100000000; i++) {
        // Array of every base action
        std::string Actions[3] = { "CHR", "REST", "UPGRADE" };

        if (ObjPlayer.getUpgradePoints() > 0) {
            std::cout << "You have upgrade points to spend!\n";
            std::cout << "[" << Actions[2] << "], ";
        }

        // String for later input, action command
        std::string commandInput;
        // Output every base action
        std::cout << "[" << Actions[0] << "], " << "[" << Actions[1] << "]\n";
        // Input action command
        std::cin >> commandInput;

        // THIS IS A TESTING COMMAND - Check if input was f, then level up. 
        if (commandInput == "f") {
            // Perform related action
            ObjPlayer.setLevelUp();
            // Insert four line breaks
            std::cout << FOURLINE;
        }
        // Check for 1st action
        else if (commandInput == Actions[0]) {
            // Perform related action
            CharacterSheet();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for 2nd action
        else if (commandInput == Actions[1]) {
            // Perform related action
            Rest();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for upgrade action (always set it to last in the array)
        else if (commandInput == Actions[2] && ObjPlayer.getUpgradePoints() > 0) {
            // String for later input, upgrade choice
            std::string upgradeChoice;
            // Output every option
            std::cout << "Select an attribute to use 1 upgrade point on:\n[Health], [Attack], [Stamina]\n";
            // Input action command
            std::cin >> upgradeChoice;

            // Check for choice health
            if (upgradeChoice == "health") {
                // Perform upgrade health method
                ObjPlayer.setUpgradeHealth();
                // Insert four line breaks
                std::cout << FOURLINE;
                // Go to character sheet
                CharacterSheet();
            }
            // Check for choice attack
            else if (upgradeChoice == "attack") {
                // Perform upgrade attack method
                ObjPlayer.setUpgradeAttack();
                // Insert four line breaks
                std::cout << FOURLINE;
                // Go to character sheet
                CharacterSheet();
            }
            // Check for choice stamina
            else if (upgradeChoice == "stamina") {
                // Perform upgrade stamina method
                ObjPlayer.setUpgradeStamina();
                // Insert four line breaks
                std::cout << FOURLINE;
                // Go to character sheet
                CharacterSheet();
            }
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }

    }
}