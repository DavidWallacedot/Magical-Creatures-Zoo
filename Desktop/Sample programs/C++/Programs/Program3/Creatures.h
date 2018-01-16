/*
Author: David Wallace
Date: 11/11/2017
name: Creatures.h
purpose: constructs a zoo of magical creatures for hagrid
*/
#ifndef CREATURES_H
#define CREATURES_H

# include <iostream>
# include <fstream>
# include <cmath>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <iomanip>
# include <string>
# include <cstring>
using namespace std;

struct cost{
	float hoursOfCare;
	float costPerHourOfCare;
	float weeklyFoodCost;
	float weeklyCostOfMaintenance;
};
struct creature{
	char name[30] ;
	char description[3000] ;
	float length;
	float height;
	char location[30] ;
	int dangerous;
	cost costObject;
};
int deleteMagicalCreature(int numCreatures,creature[]);
float convertToFloat(string s);
int enterCreatures(int numCreatures, creature []);
int enterCreaturesByFile(int numCreatures, creature []);//subfunction of enterCreatures()
void enterCreaturesManually(int numCreatures,creature []);//subfunction of enterCreatures()
void printCreatures(int numCreatures, creature []);
void printStatistics(int numCreatures,creature []);
void saveCreaturesToFile(int numCreatures,creature []);
#endif