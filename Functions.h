#pragma once

#include "Character.h"

// Globally declare player object from character header.
C_Player ObjPlayer;
C_Character ObjNPC_TavernKeeper, ObjNPC_Borka, ObjNPC_Bookman, ObjNPC_Bandit01, ObjNPC_Bandit02, ObjNPC_Bandit03;

#pragma region Declare functions
// Declare functions to use later
void NPCDeclaration();
void ActionOptions();
void CharacterSheet();
void BattleSequence();
void BattlePlayerTurn();
void BattleEnemyTurn();
void DialogueSequence();
void Rest();
#pragma endregion

void NPCDeclaration() {
#pragma region NPC Declaration
    // Declare NPCs and assign values
    // !!! Move to separate header !!!
    ObjNPC_TavernKeeper.setCharacterName("Tavern Keeper");
    ObjNPC_TavernKeeper.setCharacterRace(0);
    ObjNPC_TavernKeeper.setHostility(false);
    // Set NPC's current health to the maximum amount
    ObjNPC_TavernKeeper.setCurrentHealthPoints(ObjNPC_TavernKeeper.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_TavernKeeper.setCurrentStaminaPoints(ObjNPC_TavernKeeper.getStaminaPoints());

    ObjNPC_Borka.setCharacterName("Worm Borka");
    ObjNPC_Borka.setCharacterRace(0);
    ObjNPC_Borka.setHostility(false);
    // Set NPC's current health to the maximum amount
    ObjNPC_Borka.setCurrentHealthPoints(ObjNPC_Borka.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_Borka.setCurrentStaminaPoints(ObjNPC_Borka.getStaminaPoints());

    ObjNPC_Bookman.setCharacterName("Old Bookman");
    ObjNPC_Bookman.setCharacterRace(1);
    ObjNPC_Bookman.setHostility(false);
    // Set NPC's current health to the maximum amount
    ObjNPC_Bookman.setCurrentHealthPoints(ObjNPC_Bookman.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_Bookman.setCurrentStaminaPoints(ObjNPC_Bookman.getStaminaPoints());

    ObjNPC_Bandit01.setCharacterName("Bandit 1");
    ObjNPC_Bandit01.setCharacterRace(0);
    ObjNPC_Bandit01.setHostility(true);
    // Set NPC's current health to the maximum amount
    ObjNPC_Bandit01.setCurrentHealthPoints(ObjNPC_Bandit01.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_Bandit01.setCurrentStaminaPoints(ObjNPC_Bandit01.getStaminaPoints());

    ObjNPC_Bandit02.setCharacterName("Bandit 2");
    ObjNPC_Bandit02.setCharacterRace(0);
    ObjNPC_Bandit02.setHostility(true);
    // Set NPC's current health to the maximum amount
    ObjNPC_Bandit02.setCurrentHealthPoints(ObjNPC_Bandit02.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_Bandit02.setCurrentStaminaPoints(ObjNPC_Bandit02.getStaminaPoints());

    ObjNPC_Bandit03.setCharacterName("Bandit 3");
    ObjNPC_Bandit03.setCharacterRace(1);
    ObjNPC_Bandit03.setHostility(true);
    // Set NPC's current health to the maximum amount
    ObjNPC_Bandit03.setCurrentHealthPoints(ObjNPC_Bandit03.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    ObjNPC_Bandit03.setCurrentStaminaPoints(ObjNPC_Bandit03.getStaminaPoints());
#pragma endregion
}

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
    std::cout << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << "\n" << 
        "Level: " << ObjPlayer.getLevel() << "\n" << 
        "Health: " << ObjPlayer.getCurrentHealthPoints() << "/" << ObjPlayer.getHealthPoints() << "\n" << 
        "Stamina: " << ObjPlayer.getCurrentStaminaPoints() << "/" << ObjPlayer.getStaminaPoints() << TWOLINE << 
        "ATTRIBUTES\n" << "Health: " << ObjPlayer.getHealthAttributePoints() << "\n" << 
        "Attack: " << ObjPlayer.getAttackPoints() << "\n" << "Stamina: " << ObjPlayer.getStaminaPoints() << TWOLINE;

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

int RandomNumber;

int D(int max) {
    // Declare random device, a random number generator
    std::random_device RandomDevice;
    // Declare an int distribution with max value as the max parameter
    std::uniform_int_distribution<int> RandomDistribution(1, max);
    // Set our RandomNumber the distribution
    RandomNumber = RandomDistribution(RandomDevice);

    return RandomNumber;
}

void BattleSequence() {
    // Insert four line breaks
    std::cout << FOURLINE;

    // Array of every action
    std::string Actions[3] = { "ATTACK", "COUNTER", "BLOCK"};
    // Ccreate check for battle in progress
    bool battleInProgress = true;

    // String for later input, action command
    int ActionInput;

    // Define fighters

    // Decide who starts
    D(2);

    // For now, player will always start

    // Battle loop
    while(battleInProgress){
        std::cout << ObjPlayer.getCharacterName() << " | " << ObjNPC_Bandit01.getCharacterName() << "\nHealth: " << ObjPlayer.getCurrentHealthPoints() << " / " << ObjPlayer.getHealthPoints() << " | " << ObjNPC_Bandit01.getCurrentHealthPoints() << " / " << ObjNPC_Bandit01.getHealthPoints();

        // Player 1's turn
    // Set a base value of 0 for the action index
        int ActionIndex = 0;
        // Loop through all Races
        for (std::string actionName : Actions)
        {
            // Output race index and name, player can later choose one of these races to play as
            std::cout << "[" << ActionIndex << "] " << actionName << "\n";
            // Add 1 to the race index until we reach the last option
            ActionIndex++;
        }
        // Input action command
        std::cin >> ActionInput;

        if (ActionInput == 0) {
            std::cout << "ATTACK";
        }else if(ActionInput == 1) {
            std::cout << "COUNTER";
        }
        else if (ActionInput == 2) {
            std::cout << "BLOCK";
        }

        // Check if anyone died
        if (ObjPlayer.getCurrentHealthPoints() <= 0) {
            std::cout << "You were killed!\n";
            break;
        } else if (ObjNPC_Bandit01.getCurrentHealthPoints() <= 0) {
            std::cout << "You killed your opponent!\n";
            break;
        }

        // Player 2's turn

        // Check if anyone died
        if (ObjPlayer.getCurrentHealthPoints() <= 0) {
            std::cout << "You were killed!\n";
            break;
        }
        else if (ObjNPC_Bandit01.getCurrentHealthPoints() <= 0) {
            std::cout << "You killed your opponent!\n";
            break;
        }
    }
}

void BattlePlayerTurn(){}
void BattleEnemyTurn() {}


void DialogueSequence() {
    // Insert four line breaks
    std::cout << FOURLINE;
}

void ActionOptions() {
    // Insert four line breaks
    std::cout << FOURLINE;

    for (int i = 0; i < 1;) {
        // Array of every action
        std::string Actions[4] = { "CHR", "REST", "BATTLE", "UPGRADE" };

        if (ObjPlayer.getUpgradePoints() > 0) {
            std::cout << "You have upgrade points to spend!\n";
            std::cout << "[" << Actions[2] << "], ";
        }

        // String for later input, action command
        std::string ActionInput;
        // Output every base action
        std::cout << "[" << Actions[0] << "], " << "[" << Actions[1] << "], " << "[" << Actions[2] << "]\n";
        // Input action command
        std::cin >> ActionInput;

        // Convert all characters to uppercase 
        for (char& characters : ActionInput) {
            characters = std::toupper(characters);
        }

        // THIS IS A TESTING COMMAND - Check if input was f, then level up. 
        if (ActionInput == "F") {
            // Perform related action
            ObjPlayer.setLevelUp();
            // Insert four line breaks
            std::cout << FOURLINE;
        }
        // Check for action
        else if (ActionInput == Actions[0]) {
            // Perform related action
            CharacterSheet();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for action
        else if (ActionInput == Actions[1]) {
            // Perform related action
            Rest();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for action
        else if (ActionInput == Actions[2]) {
            // Perform related action
            BattleSequence();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for upgrade action (always set it to last in the array)
        else if (ActionInput == Actions[3] && ObjPlayer.getUpgradePoints() > 0) {
            // Array of all attributes
            std::string Attributes[3] = { "HEALTH", "ATTACK", "STAMINA" };
            // String for later input, upgrade choice
            std::string UpgradeChoice;

            // Output every option
            std::cout << "Select an attribute to use 1 upgrade point on:\n[" << Attributes[0] << "], [" << Attributes[1] << "], [" << Attributes[2] << "]\n";
            // Input action command
            std::cin >> UpgradeChoice;

            // Convert all characters to uppercase 
            for (char& characters : UpgradeChoice) {
                characters = std::toupper(characters);
            }

            // Check for choice health
            if (UpgradeChoice == Attributes[0]) {
                // Perform upgrade health method
                ObjPlayer.setUpgradeHealth();
                // Insert four line breaks
                std::cout << FOURLINE;
                // Go to character sheet
                CharacterSheet();
            }
            // Check for choice attack
            else if (UpgradeChoice == Attributes[1]) {
                // Perform upgrade attack method
                ObjPlayer.setUpgradeAttack();
                // Insert four line breaks
                std::cout << FOURLINE;
                // Go to character sheet
                CharacterSheet();
            }
            // Check for choice stamina
            else if (UpgradeChoice == Attributes[2]) {
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