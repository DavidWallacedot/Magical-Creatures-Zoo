/*
Author: David Wallace
Date: 11/11/2017
name: Functions.cpp
purpose: constructs a zoo of magical creatures for hagrid
*/
#include "Creatures.h"
int deleteMagicalCreature(int numCreatures,creature tempArray[]){
	string nameChoice;
	int removedFromZoo = 0;
	cout << endl<<"Choose creature to remove from the zoo!"<<endl;
	for(int i=0; i<numCreatures; i++)
	{
		cout << tempArray[i].name << "\n";
	}
	cout <<endl<< " Enter the creature's name you wish to delete:  ";
	cin.ignore();
	getline(cin, nameChoice);
	for(int i=0; i<numCreatures; i++)
	{
		if(nameChoice == tempArray[i].name)//name is found
		{
			removedFromZoo = 1;
			for(int j=i; j<(numCreatures-1); j++)//updates array from pos where name is found to end of array
			{
				tempArray[j] = tempArray[j+1];
			}
		}
	}
	if(removedFromZoo == 1)
	{
		cout << nameChoice << " was removed from the zoo.\n\n";
		numCreatures-=2;
return numCreatures;
	}
else{
cout<<nameChoice<<" was not found in the zoo"<<endl<<endl;
return numCreatures;
}
	 }

int enterCreatures(int numCreatures, creature tempArray[]){
		int userChoice;
		int creaturesInFile=0;//tracks how many creatures were added from the file
	cout<<"What do you want to do?\n";
	 cout<<"     1.   Load my creatures from a file.\n";
	 cout<<"     2.   Enter one creature manually.\n";
	 cout<<"CHOICE: ";
	 cin>>userChoice;
	 while(userChoice>2 || userChoice<0){
		 cout<<"Please enter a valid choice of 1(to load from file) or 2(manual insertion of creature)";
	 }
	 if(userChoice == 1){
		creaturesInFile += enterCreaturesByFile(numCreatures,tempArray);//increments numCreatures by amount in file
		 if(creaturesInFile >0){
		 cout<<creaturesInFile-1<<" creature(s) was/were added to the zoo"<<endl<<endl;}
		 return --creaturesInFile;//function could end here

	 }
		 else{
			enterCreaturesManually(numCreatures,tempArray);
			numCreatures++;				
			cout<<"1 creature was added to the zoo"<<endl<<endl;
			return 1;//function could end here by returning 1 
		 }
			
	 
	 
 }
 
 int enterCreaturesByFile(int numCreatures,creature tempArray[]){
	 ifstream file;
	 creature creatureFromFile;
	 string fileName="";
	 string temp="";//temporarily holds values in string type
	 char nameArray [30];//medium through which values pass to creature attributes
	 char descriptionArray[3000];//medium through which values pass to creature attributes
	 char locationArray[30];//medium through which values pass to creature attributes
	 cout<<"What is the name of the file with your list of creatures?(ex: filename)\n";
	 cout<<"FILENAME:";
	 cin.ignore();
	 getline(cin,fileName);
	 file.open(fileName.c_str());
	
	 if(!file.is_open()){
		 cout<<file<<" does not exist or is corrupt. Sorry. Can't load creatures.";
	 }
	 else{
		while(numCreatures < 100){
			getline(file,temp,'#');
			strncpy(creatureFromFile.name, temp.c_str(),sizeof(temp));//converts string to char
			getline(file,temp,'#');
			strncpy(creatureFromFile.description, temp.c_str(),temp.length());//converts string to char
			getline(file,temp,'#');
			creatureFromFile.length = convertToFloat(temp);
			getline(file,temp,'#');
			creatureFromFile.height = convertToFloat(temp);
			getline(file,temp,'#');
			strncpy(creatureFromFile.location, temp.c_str(),temp.length());//converts string to char
			getline(file,temp,'#');
			creatureFromFile.dangerous = convertToFloat(temp);
			getline(file,temp,'#');
			creatureFromFile.costObject.hoursOfCare = convertToFloat(temp);
			getline(file,temp,'#');
			creatureFromFile.costObject.costPerHourOfCare = convertToFloat(temp);
			getline(file,temp,'#');
			creatureFromFile.costObject.weeklyFoodCost = convertToFloat(temp);
			getline(file,temp,'#');
			creatureFromFile.costObject.weeklyCostOfMaintenance = convertToFloat(temp);
			tempArray[numCreatures]=creatureFromFile;
			numCreatures++;
			if(file.eof()){
				break;
			}
		}
	 }
	 file.close();
	 return numCreatures;
	 }
 
 void enterCreaturesManually(int numCreatures,creature tempArray[]){
	 creature creatUre;
	 string tempName;//medium through which values pass to creature attributes
	 string tempDescription;//medium through which values pass to creature attributes
	 string tempLocation;//medium through which values pass to creature attributes
	 char danger='y';
	 if(numCreatures < 100){
	 cout<<"NAME: ";
	 cin.ignore();
	 getline(cin,tempName);
	 strncpy(creatUre.name, tempName.c_str(),tempName.length());//converts string to char
	 cout<<endl<<"DESCRIPTION: ";
	 getline(cin,tempDescription);
	 strncpy(creatUre.description, tempDescription.c_str(),tempDescription.length());//converts string to char
	 cout<<endl<<"AVERAGE LENGTH (in feet): ";
	 cin>>creatUre.length;
	 cout<<endl<<"AVERAGE HEIGHT (in feet): ";
	 cin>>creatUre.height;
	 cout<<endl<<"LOCATION: ";
	 cin.ignore();
	 getline(cin,tempLocation);
	strncpy(creatUre.location, tempLocation.c_str(),tempLocation.length());//converts string to char
	 cout<<endl<<"IS IT A DANGEROUS CREATURE(y or n): ";
	 cin>>danger;
	 if(tolower(danger)=='y'){//converts allows userInput char to be stored as int
		 creatUre.dangerous = 1;
	 }
	 else
	 {
		 creatUre.dangerous = 0;
	 }
	 cout<<endl<< "How many hours per week do you spend caring for the "<<creatUre.name<<"?\nNUM HOURS: ";
	 cin>> creatUre.costObject.hoursOfCare;
	 cout<<endl<<"What is the cost per hour for caring for the "<<creatUre.name<<"?\nCOST PER HOUR: ";
	 cin>>creatUre.costObject.costPerHourOfCare;
	 cout<<endl<<"How much money do you spend on food for the "<<creatUre.name<<" per week?\nFOOD COST: ";
	 cin>>creatUre.costObject.weeklyFoodCost;
	 cout<<"How much money do you spend on grooming and medical supplies for the "<<creatUre.name<<" per week?\nSUPPLY COST: ";
	 cin>>creatUre.costObject.weeklyCostOfMaintenance;
	 cout<<endl;
	 tempArray[numCreatures]= creatUre;//initializes tempArray[index] to creature
	 }
	 else {
		 cout<<"Zoo maximum exceeded.";
	 }
	 
	 }
float convertToFloat(string s)
{
istringstream mystring(s);
float myfloat;
if (!(mystring >> myfloat))
myfloat = 0;
return myfloat;
}
void printCreatures(int numCreatures, creature tempArray[]){
	creature creatureToBePrinted;
	string dangerous;
	numCreatures-=2;
	if(numCreatures == 0){
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<< "THERE ARE NO CREATURES AT YOUR ZOO!"<<endl;	
	}
	else{
	for(int i = 0; i<numCreatures;i++){
		creatureToBePrinted = tempArray[i];
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"Creature "<<i+1<<endl;
		cout<<setw(45)<<left<<"Name:"<<right<<creatureToBePrinted.name;;
		cout<<endl<<setw(45)<<left<<"Description:"<<right<<creatureToBePrinted.description;;
		cout<<endl<<setw(45)<<left<<"Length:"<<right<<creatureToBePrinted.length<<endl;
		cout<<setw(45)<<left<<"Height:"<<right<<creatureToBePrinted.height<<endl;
		cout<<setw(45)<<left<<"Location:"<<right<<creatureToBePrinted.location; ;
		if(creatureToBePrinted.dangerous == 1){
			dangerous = "yes";
			}
			else
				dangerous = "no";
		cout<<endl<<setw(45)<<left<<"Dangerous? "<<right<<dangerous<<endl;
		cout<<setw(21)<<left<< "Number of hours to care for the creature:    "<<right<<creatureToBePrinted.costObject.hoursOfCare<<endl;
		cout<<setw(20)<<left<< "Cost Per Hour of taking care the creature:   "<<right<<"$"<<creatureToBePrinted.costObject.costPerHourOfCare<<endl;
		cout<<setw(45)<<left<<"Cost to feed the creature:"<<right<<"$"<<creatureToBePrinted.costObject.weeklyFoodCost<<endl;
	cout<<setw(45)<<left<<    "Grooming and supplies cost:"<<right<<"$"<<creatureToBePrinted.costObject.weeklyCostOfMaintenance<<endl<<endl;
		}
	}
}
 void printStatistics(int numCreatures, creature tempArray[]){
	 creature costOfCreature;
	 int totalOfAllCreatures;
	 int runningTotal =0;
	 int sizing = 50; 
	 if(numCreatures == 0){
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<< "THERE ARE NO CREATURES AT YOUR ZOO!"<<endl;	
	}
	else{
		cout<<"Cost of each creature for 1 week"<<endl<<endl;
		
	for(int i =0; i<numCreatures;i++){
	costOfCreature = tempArray[i];
	runningTotal = costOfCreature.costObject.hoursOfCare * costOfCreature.costObject.costPerHourOfCare + costOfCreature.costObject.weeklyFoodCost+costOfCreature.costObject.weeklyCostOfMaintenance;
	cout<<costOfCreature.name<<endl;
	cout<<setw(50)<<right<<"$"<<runningTotal<<endl;
	totalOfAllCreatures+=runningTotal;
	
	}
	cout<<"Total Cost"<<endl;
	cout<<setw(50)<<right<<"$"<<totalOfAllCreatures<<endl<<endl;
	}
 }
 void saveCreaturesToFile(int numCreatures,creature tempArray[]){
	 string fileName;
	 char userInput;
if(numCreatures>1)
numCreatures--;	 
cout<<"Would you like to save your creatures to a file?Select 'Y' or 'y' if so."<<endl;
	 cin>>userInput;
	 if(tolower(userInput)=='y'){
		 ofstream outFile;
		creature creatureToBeAddedToFile;
		 cout<<"Please enter the name of the file you wish to save your creatures to."<<endl;
		 cin>>fileName;
		  ifstream infile(fileName.c_str());
    if(infile.good()) {//checks if file has already been created if so prepends '#'
			 outFile.open(fileName.c_str(), ios::app);
		 for(int i = 0; i<numCreatures;i++){
		creatureToBeAddedToFile = tempArray[i];
		outFile<<"#"<<creatureToBeAddedToFile.name<<"#";
		outFile<<creatureToBeAddedToFile.description<<"#";
		outFile<<creatureToBeAddedToFile.length<<"#";
		outFile<<creatureToBeAddedToFile.height<<"#";
		outFile<<creatureToBeAddedToFile.location<<"#";
		outFile<<creatureToBeAddedToFile.dangerous<<"#";
		outFile<<creatureToBeAddedToFile.costObject.hoursOfCare<<"#";
		outFile<<creatureToBeAddedToFile.costObject.costPerHourOfCare<<"#";
		outFile<<creatureToBeAddedToFile.costObject.weeklyFoodCost<<"#";
		if(i<numCreatures-1){//checks to see if there are any additional creatures to add
		outFile<<creatureToBeAddedToFile.costObject.weeklyCostOfMaintenance<<"#";}//if so append'#'
		else{
			outFile<<creatureToBeAddedToFile.costObject.weeklyCostOfMaintenance;
		}
	} outFile.close();
			 
		 }
		 else{//if file has just been created no '#'
		 outFile.open(fileName.c_str());
		 for(int i = 0; i<numCreatures;i++){
		creatureToBeAddedToFile = tempArray[i];
		outFile<<creatureToBeAddedToFile.name<<"#";
		outFile<<creatureToBeAddedToFile.description<<"#";
		outFile<<creatureToBeAddedToFile.length<<"#";
		outFile<<creatureToBeAddedToFile.height<<"#";
		outFile<<creatureToBeAddedToFile.location<<"#";
		outFile<<creatureToBeAddedToFile.dangerous<<"#";
		outFile<<creatureToBeAddedToFile.costObject.hoursOfCare<<"#";
		outFile<<creatureToBeAddedToFile.costObject.costPerHourOfCare<<"#";
		outFile<<creatureToBeAddedToFile.costObject.weeklyFoodCost<<"#";
		if(i<numCreatures-1){
		outFile<<creatureToBeAddedToFile.costObject.weeklyCostOfMaintenance<<"#";}
		else{
			outFile<<creatureToBeAddedToFile.costObject.weeklyCostOfMaintenance;
		}
		 } outFile.close();}
		
	cout<<"Your creature(s) were successfully saved to "<<fileName<<".\n\n";
	 }
	cout<<"Goodbye!";
	 
 }