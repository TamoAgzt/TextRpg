#pragma once

#include "Character.h"

// Globally declare player object from character header.
C_Player ObjPlayer;
C_Character ObjNPC_TavernKeeper, ObjNPC_Borka, ObjNPC_Bookman, ObjNPC_Bandit01, ObjNPC_Bandit02, ObjNPC_Bandit03;

#pragma region Declare functions
// Declare functions to use later
void NPCDeclaration();
void NPCInitialization(C_Character& objName, std::string npcName, int race, bool hostility);
void ActionOptions();
void CharacterSheet();
void BattleSequence();
void BattlePlayerTurn();
void BattleEnemyTurn();
void CheckBattleState();
void DialogueSequence();
void Rest();
#pragma endregion

void NPCDeclaration() {
    NPCInitialization(ObjNPC_TavernKeeper, "Tavern Keeper", 0, false);
    NPCInitialization(ObjNPC_Borka, "Worm Borka", 0, false);
    NPCInitialization(ObjNPC_Bookman, "Old Bookman", 0, false);
    NPCInitialization(ObjNPC_Bandit01, "Bandit 1", 0, true);
    NPCInitialization(ObjNPC_Bandit02, "Bandit 2", 0, true);
    NPCInitialization(ObjNPC_Bandit03, "Bandit 3", 1, true);
}

void NPCInitialization(C_Character& objName, std::string npcName, int race, bool hostility) {
    objName.setCharacterName(npcName);
    objName.setCharacterRace(race);
    objName.setHealthPoints();
    objName.setHostility(hostility);
    // Set NPC's current health to the maximum amount
    objName.setCurrentHealthPoints(objName.getHealthPoints());
    // Set NPC's current stamina to the maximum amount
    objName.setCurrentStaminaPoints(objName.getStaminaPoints());
}

// See "Character Sheet" in Gameplay.md
void CharacterSheet() {
    // Insert four line breaks
    std::cout << FOURLINE;

    // Check if player has upgrade points
    if (ObjPlayer.getUpgradePoints() > 0) {
        // Output amount of points available
        std::cout << "You have " << ObjPlayer.getUpgradePoints() << " upgrade point(s) to spend." << std::endl;
    }

    // Output player's info
    std::cout << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getCharacterRace() << std::endl << 
        "Level: " << ObjPlayer.getLevel() << std::endl << 
        "Health: " << ObjPlayer.getCurrentHealthPoints() << "/" << ObjPlayer.getHealthPoints() << std::endl << 
        "Stamina: " << ObjPlayer.getCurrentStaminaPoints() << "/" << ObjPlayer.getStaminaPoints() << TWOLINE << 
        "ATTRIBUTES" << std::endl << 
        "Health: " << ObjPlayer.getHealthAttributePoints() << std::endl <<
        "Attack: " << ObjPlayer.getAttackPoints() << std::endl << "Stamina: " << ObjPlayer.getStaminaPoints() << TWOLINE;

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

    // Ccreate check for battle in progress
    bool battleInProgress = true;

    std::cout << ObjPlayer.getCharacterName() << " | " << ObjNPC_Bandit01.getCharacterName() << std::endl << "Health: " << ObjPlayer.getCurrentHealthPoints() << " / " << ObjPlayer.getHealthPoints() << " | " << ObjNPC_Bandit01.getCurrentHealthPoints() << " / " << ObjNPC_Bandit01.getHealthPoints() << TWOLINE;

    if (isPlayerTurnInBattle == true) { 
        BattlePlayerTurn();
    } else if (isPlayerTurnInBattle == false) { 
        BattleEnemyTurn();
    }
}

void BattlePlayerTurn(){
    std::cout << "Your turn..." << std::endl;
    // Set a base value of 0 for the action index
    int ActionIndex = 0;
    // String for later input, action command
    int ActionInput;

    // Loop through all actions
    for (std::string actionName : BattleActions) {
        // Output action index and name
        std::cout << "[" << ActionIndex << "] " << actionName << std::endl;
        // Add 1 to the action index until we reach the last option
        ActionIndex++;
    }

    // Input action command
    std::cin >> ActionInput;

    if (ActionInput == 0) {
        std::cout << "ATTACK";
        ObjNPC_Bandit01.setReduceCurrentHealth(ObjPlayer.getAttackPoints());
        CheckBattleState();
    }
    else if (ActionInput == 1) {
        std::cout << "COUNTER";
        CheckBattleState();
    }
    else if (ActionInput == 2) {
        std::cout << "BLOCK";
        CheckBattleState();
    }
}

void BattleEnemyTurn() {
    std::cout << "Enemy's turn..." << std::endl;
    // Decide who starts
    D(1);
    if (RandomNumber == 1) {
        std::cout << "ATTACK"; 
        ObjPlayer.setReduceCurrentHealth(ObjNPC_Bandit01.getAttackPoints());
        CheckBattleState();
    }
    else if (RandomNumber == 2) {
        std::cout << "COUNTER";
        CheckBattleState();
    }
    else if (RandomNumber == 3) {
        std::cout << "BLOCK";
        CheckBattleState();
    }
}

void CheckBattleState(){
    // Check if anyone died
    if (ObjPlayer.getCurrentHealthPoints() <= 0) {
        std::cout << "You were killed!" << std::endl;

        system("pause");
    } else if (ObjNPC_Bandit01.getCurrentHealthPoints() <= 0) {
        std::cout << "You killed your opponent!" << std::endl;
        ObjPlayer.setLevelUp();
        ActionOptions();
    } else{
        // Toggle player turn check
        isPlayerTurnInBattle = !isPlayerTurnInBattle;
        BattleSequence();
    }
}


void DialogueSequence() {
    // Insert four line breaks
    std::cout << FOURLINE;
}

void ActionOptions() {
    // Insert four line breaks
    std::cout << FOURLINE;

    for (int i = 0; i < 1;) {
        if (ObjPlayer.getUpgradePoints() > 0) {
            std::cout << "You have upgrade points to spend!" << std::endl;
            std::cout << "[" << BaseActions[3] << "], ";
        }

        // String for later input, action command
        std::string ActionInput;
        // Output every base action
        std::cout << "[" << BaseActions[0] << "], " << "[" << BaseActions[1] << "], " << "[" << BaseActions[2] << "]" << std::endl;
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
        else if (ActionInput == BaseActions[0]) {
            // Perform related action
            CharacterSheet();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for action
        else if (ActionInput == BaseActions[1]) {
            // Perform related action
            Rest();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for action
        else if (ActionInput == BaseActions[2]) {
            // Decide who starts
            // For now, player will always start with D(1), change to D(2) later
            D(1);

            if (RandomNumber == 1) {
                isPlayerTurnInBattle = true;
            }
            else if (RandomNumber == 2) {
                isPlayerTurnInBattle = false;
            }

            // Perform related action
            BattleSequence();
            // Insert four line breaks
            std::cout << FOURLINE;
            break;
        }
        // Check for upgrade action (always set it to last in the array)
        else if (ActionInput == BaseActions[3] && ObjPlayer.getUpgradePoints() > 0) {
            // String for later input, upgrade choice
            std::string UpgradeChoice;

            // Output every option
            std::cout << "Select an attribute to use 1 upgrade point on:" << std::endl << "[" << Attributes[0] << "], [" << Attributes[1] << "], [" << Attributes[2] << "]" << std::endl;
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