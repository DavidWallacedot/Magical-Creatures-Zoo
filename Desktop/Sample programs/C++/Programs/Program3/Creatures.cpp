/*
Author: David Wallace
Date: 11/11/2017
name: Creatures.cpp
purpose: constructs a zoo of magical creatures for hagrid
*/
#include "Creatures.h"
int main(){
	 creature creaturez;
	 int numCreatures=0;
	 char userInput = 'y';
	 while (tolower(userInput) == 'y' ){
	 creature zoo[100];//array of type creature
	 cout<<"What would you like to do?\n";
	 cout<<"1. Enter new magical creatures or load from a file.\n";
	 cout<<"2. Remove magical creature from the zoo\n";
	 cout<<"3. Print all creatures.\n";
	 cout<<"4. Print statistics on creature cost.\n";
	 cout<<"5. End program.\n";
	 cout<<"Enter 1, 2, 3, 4 or 5.\n";
	 cout<<"CHOICE: ";
	 int input =0;
	 cin>>input;
	 while(input<0 || input>5){//validates userInput
		cout<<"Your choice was invalid. Choose a number 1 - 5\nCHOICE: ";
		cin>>input;	
	 }
	 switch(input){//determines which function to call
		 case 1:
		 cout<<endl;
		 numCreatures += enterCreatures(numCreatures,zoo);
		 break;
		 case 2:
		 numCreatures = deleteMagicalCreature(numCreatures,zoo);
		 break;
		 case 3:
		 cout<<endl;
		  printCreatures(numCreatures,zoo);
		 break;
		 case 4:
		 cout<<endl;
		  printStatistics(numCreatures,zoo);
		 break;
		 case 5:
		 cout<<endl;
		  saveCreaturesToFile(numCreatures,zoo);
		  userInput = 'n';
		 break;
		 
		}
	 }
	 return 0;
 }