#pragma once
#include "Header.h"

struct {
    std::string Races[5] = { "Human", "Elf", "Ork", "Goblin", "Foxling" };
} Race;

class C_Character {
protected:
    int AttackPoints = 0, HealthAttributePoints = 0, StaminaPoints = 0, HealthPoints = 0, CurrentHealthPoints = 0, CurrentStaminaPoints = 0;

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
            HealthAttributePoints = 9;
            StaminaPoints = 9;
            break;
        case 1:
            AttackPoints = 7;
            HealthAttributePoints = 10;
            StaminaPoints = 10;
            break;
        case 2:
            AttackPoints = 12;
            HealthAttributePoints = 9;
            StaminaPoints = 6;
            break;
        case 3:
            AttackPoints = 6;
            HealthAttributePoints = 8;
            StaminaPoints = 13;
            break;
        case 4:
            AttackPoints = 10;
            HealthAttributePoints = 10;
            StaminaPoints = 7;
            break;
        }
    }
    std::string getCharacterRace() {
        return CharacterRace;
    }

    int setReduceAttack(int reductionPoints) {
        AttackPoints -= reductionPoints;
        return AttackPoints;
    }
    int getAttackPoints() {
        return AttackPoints;
    }

    int setReduceCurrentHealth(int reduction) {
        CurrentHealthPoints -= reduction;
        return CurrentHealthPoints;
    }

    int setHealthPoints() {
        HealthPoints = getHealthAttributePoints() * 2;
        return HealthPoints;
    }

    int getHealthPoints() {
        return HealthPoints;
    }
    int getHealthAttributePoints() {
        return HealthAttributePoints;
    }

    int setCurrentHealthPoints(int healthPoints) {
        CurrentHealthPoints = healthPoints;
        return CurrentHealthPoints;
    }
    int getCurrentHealthPoints() {
        return CurrentHealthPoints;
    }

    int setReduceCurrentStamina(int reduction) {
        CurrentStaminaPoints -= reduction;
        return CurrentStaminaPoints;
    }
    int setCurrentStaminaPoints(int staminaPoints) {
        CurrentStaminaPoints = staminaPoints;
        return CurrentStaminaPoints;
    }
    int getCurrentStaminaPoints() {
        return CurrentStaminaPoints;
    }
    int getStaminaPoints() {
        return StaminaPoints;
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
        HealthAttributePoints++;
        setUseUpgradePoints();
        setHealthPoints();
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
