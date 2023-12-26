#pragma once
#include "sports.h"

bool isOnlyLetters(const std::string& str);
void createAthleteArray(Athlete*& athletes, int& size);
void viewAthleteArray(const Athlete* athletes, int size);
void addAthlete(Athlete*& athletes, int& size);
void searchAthlete(const Athlete* athletes, int size, int searchAge);
void deleteAthlete(Athlete*& athletes, int& size, int searchAge);
void sortAthleteArray(Athlete* athletes, int size);
void shellSort(Athlete* athletes, int size);
void menu();
