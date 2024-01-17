#pragma once
#include "Header.h"

struct {
    std::string Races[5] = { "Human", "Elf", "Ork", "Goblin", "Foxling" };
} Race;

class C_Character {
protected:
    int AttackPoints = 0, HealthPoints = 0, StaminaPoints = 0, CurrentHealthPoints = 0, CurrentStaminaPoints = 0;

private:
    std::string CharacterName = "", CharacterRace = "";
    bool isHostile = false;

public:
    void setCharacterName(std::string characterName) {
        CharacterName = characterName;
    }
    std::string getCharacterName() {
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
            AttackPoints = 12;
            HealthPoints = 9;
            StaminaPoints = 6;
            break;
        case 3:
            AttackPoints = 6;
            HealthPoints = 8;
            StaminaPoints = 13;
            break;
        case 4:
            AttackPoints = 10;
            HealthPoints = 10;
            StaminaPoints = 7;
            break;
        }
    }
    std::string getCharacterRace() {
        return CharacterRace;
    }

    void setReduceAttack(int reductionPoints) {
        AttackPoints -= reductionPoints;
    }
    int getAttackPoints() {
        return AttackPoints;
    }

    void setReduceHealth(int damagePoints) {
        HealthPoints -= damagePoints;
    }

    int getHealthPoints() {
        return HealthPoints;
    }

    void setReduceStamina(int reductionPoints) {
        StaminaPoints -= reductionPoints;
    }
    int getStaminaPoints() {
        return StaminaPoints;
    }

    void setCurrentHealthPoints(int healthPoints) {
        CurrentHealthPoints = healthPoints;
    }
    int getCurrentHealthPoints() {
        return CurrentHealthPoints;
    }

    void setCurrentStaminaPoints(int staminaPoints) {
        CurrentStaminaPoints = staminaPoints;
    }
    int getCurrentStaminaPoints() {
        return CurrentStaminaPoints;
    }

    void setHostility(bool hostility) {
        isHostile = hostility;
    }
    bool getHostility() {
        return isHostile;
    }
};

class C_Player : public C_Character {
private:
    int PlayerLevel = 0;
    int UpgradePoints = 0;

public:

#pragma region MyRegion


    void setLevelUp() {
        PlayerLevel++;
        UpgradePoints++;
    }
    void setUpgradeAttack() {
        AttackPoints++;
        setUseUpgradePoints();
    }
    void setUpgradeHealth() {
        HealthPoints++;
        setUseUpgradePoints();
    }
    void setUpgradeStamina() {
        StaminaPoints++;
        setUseUpgradePoints();
    }

    void setUseUpgradePoints() {
        UpgradePoints--;
    }
    int getUpgradePoints() {
        return UpgradePoints;
    }
    int getLevel() {
        return PlayerLevel;
    }

#pragma endregion
};