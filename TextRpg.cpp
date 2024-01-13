// TextRpg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


/*struct {
    int AttackPoints;
    int HealthPoints;
    int StaminaPoints;
} Stats;
*/

struct {
    string Races[3] = { "Human", "Elf", "Ork" };
    // The base points should all add up to 27 for each race
    // Human attack 9 health 9 stamina 9
    // Elf attack 7 health 10 stamina 10
    // Ork attack 11 health 10 stamina 6
} Race;

/*
class C_Race {
public:
    string Races[3] = {"Human", "Elf", "Ork"};
    // The base points should all add up to 27 for each race
    // Human attack 9 health 9 stamina 9
    // Elf attack 7 health 10 stamina 10
    // Ork attack 11 health 10 stamina 6
};

class C_Player: public C_Race {
*/

class C_Character {
private:
    string CharacterName;
    string CharacterRace;
    bool isHostile;

    int AttackPoints;
    int HealthPoints;
    int StaminaPoints;

public:
    void setCharacterName(string characterName) {
        CharacterName = characterName;
    }
    string getCharacterName() {
        return CharacterName;
    }

    void setCharacterRace(int chosenRace) {
        CharacterRace = Race.Races[chosenRace];
        switch (chosenRace) {
        case 0:
            AttackPoints = 9;
            HealthPoints = 9;
            StaminaPoints = 9;
            break;
        case 1:
            AttackPoints = 7;
            HealthPoints = 10;
            StaminaPoints = 10;
            break;
        case 2:
            AttackPoints = 11;
            HealthPoints = 10;
            StaminaPoints = 6;
            break;
        }
    }
    string getCharacterRace() {
        return CharacterRace;
    }

    void setHostility(bool hostility) {
        isHostile = hostility;
    }
    bool getHostility() {
        return isHostile;
    }
};

class C_Player {
private:
    string CharacterName;
    string PlayerRace;
    int PlayerLevel;

    int AttackPoints;
    int HealthPoints;
    int StaminaPoints;

public:
    void setCharacterName(string characterName) {
        CharacterName = characterName;
    }
    string getCharacterName() {
        return CharacterName;
    }

    void setPlayerRace(int chosenRace) {
        PlayerRace = Race.Races[chosenRace];
        switch (chosenRace) {
        case 0:
            AttackPoints = 9;
            HealthPoints = 9;
            StaminaPoints = 9;
            break;
        case 1:
            AttackPoints = 7;
            HealthPoints = 10;
            StaminaPoints = 10;
            break;
        case 2:
            AttackPoints = 11;
            HealthPoints = 10;
            StaminaPoints = 6;
            break;
        }
    }
    string getPlayerRace() {
        return PlayerRace;
    }

#pragma region MyRegion


    void setLevelUp() {
        PlayerLevel++;
    }
    int getLevel() {
        return PlayerLevel;
    }

    void setAttackUp() {
        AttackPoints;
    }
    int getAttackPoints() {
        return AttackPoints;
    }

    void setHealthUp() {
        HealthPoints;
    }
    int getHealthPoints() {
        return HealthPoints;
    }

    void setStaminaUp() {
        StaminaPoints++;
    }
    int getStaminaPoints() {
        return StaminaPoints;
    }
#pragma endregion
};

int main() {
#pragma region NPC Declaration
    C_Character ObjNPC_TavernKeeper, ObjNPC_Borka, ObjNPC_Bookman, ObjNPC_Bandit01, ObjNPC_Bandit02, ObjNPC_Bandit03;
    ObjNPC_TavernKeeper.setCharacterName("Tavern Keeper");
    ObjNPC_TavernKeeper.setCharacterRace(0);
    ObjNPC_TavernKeeper.setHostility(false);

    ObjNPC_Borka.setCharacterName("Borka");
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

#pragma region SelectName

    string x;
    cout << "What is your name, traveler? \n";
    cin >> x;
    C_Player ObjPlayer;
    ObjPlayer.setCharacterName(x);

    /*
    string agreement;
    cout << "Are you sure? (y/n)\n";
    cin >> agreement;
    if (agreement == "y") {
        C_Player ObjPlayer;
        ObjPlayer.setCharacterName(x);
    }
    else if(agreement == "n")
    {

    }
    else {
        cout << "oh no";
    }
    */

#pragma endregion

#pragma region SelectRace

    int i = 0;
    for (string raceName : Race.Races)
    {
        cout << "[" << i << "] " << raceName << "\n";
        i++;
    }

    int raceChoice;
    cout << "What is your name, traveler? \n";
    cin >> raceChoice;

    // Add a check to see if the choice is available, else repeat

    ObjPlayer.setPlayerRace(raceChoice);


#pragma endregion

    cout << "Pleasure to meet you, " << ObjPlayer.getCharacterName() << " the " << ObjPlayer.getPlayerRace() << "!\n";

    string action, target;
    cin >> action >> target;
    cout << action << " " << target;

    return 0;
}

// Gameplay loop: prompt - options - choice - repeat
// Options will be like custom commands and should look like: ACTION TARGET
// Example: Interact TavernKeeper, Attack Bandit1
// Dialogue loops should look similar: prompt, response/choice, repeat
// Response structure should be like the race picking at the start.

// Implement "dice rolls" where 1 = big negative multiplier; 2,3,4,5,6,7 is small negative multiplier; 8,9,10,11,12 is neutral; 13,14,15,16,17,18,19 is a small positive multiplier; 20 is a big positive multiplier,