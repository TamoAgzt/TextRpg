#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <random>

std::string TWOLINE = "\n\n";
std::string FOURLINE = "\n\n\n\n";

bool isPlayerTurnInBattle = false;

// Array of every action
std::string BaseActions[4] = { "CHR", "REST", "BATTLE", "UPGRADE" };
// Array of all attributes
std::string Attributes[3] = { "HEALTH", "ATTACK", "STAMINA" };
// Array of every action
std::string BattleActions[3] = { "ATTACK", "COUNTER", "BLOCK" };

