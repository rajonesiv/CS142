//Andrew Jones
//This program is designed to choose a random number between 1 and 100
//and then asks the user to guess the number.

#include <iostream>
#include <fstream> //for saving and loading the file
using namespace std;

//gonna make some void functions just like the mcdonalds program

void welcome()
{
	//here's the welcome intro
	cout<<"**Welcome to the Candy Database Program**\n";
	cout<< "Here is the list of commands:\n"
		<<" E - Eat a piece of candy\n"
		<<" T - Trick or Treat: get a piece of candy\n"
		<<" I - Inventory listing\n"
		<<" C - List candy types\n"
		<<" M - Print this menu of commands\n"
		<<" S - Save to the file candy.dat\n"
		<<" L - Load from the file candy.dat\n"
		<<" Q - Quit this program\n";
}

void listcommands() //print the list of possible commands 
{
	cout<< "Here is the list of commands:\n"
		<<" E - Eat a piece of candy\n"
		<<" T - Trick or Treat: get a piece of candy\n"
		<<" I - Inventory listing\n"
		<<" C - List candy types\n"
		<<" M - Print this menu of commands\n"
		<<" S - Save to the file candy.dat\n"
		<<" L - Load from the file candy.dat\n"
		<<" Q - Quit this program\n";
}

void listcandytypes () //lists the types of candy possible
{
	cout<<"Candy Types: \n"
		<<"1  Candy Corn\n"
		<<"2  Licorice\n"
		<<"3  Jaw Breakers\n"
		<<"4  Peanutbutter Cups\n"
		<<"5  M&Ms\n"
		<<"6  Other\n";
}

void inventory(int candy[7]) //display listing of counts
//of each candy type. display total amount of candy
{
	cout<<"Candy Inventory: \n";
	cout<<"Candy Corn  "<<candy[1]<<endl;
	cout<<"Licorice  "<<candy[2]<<endl;
	cout<<"Jaw Breakers  "<<candy[3]<<endl;
	cout<<"Peanutbutter Cups  "<<candy[4]<<endl;
	cout<<"M&Ms  "<<candy[5]<<endl;
	cout<<"Other  "<<candy[6]<<endl;
	double sum=0;
	sum=sum+candy[1]+candy[2]+candy[3]+candy[4]+candy[5]+candy[6];
	cout<<"You have "<<sum<<" pieces of candy.\n";
}

void trickortreat(int candy[7]) //gonna add candy to the inventory
{
	int t;
	cout<<"Please enter the candy type (1-6): \n";
	cin>>t;
	candy[t]=candy[t]+1;
}

void eat(int candy[7]) //gonna subtract candy from the inventory
{
	int t;
	cout<<"Please enter the candy type (1-6): \n";
	cin>>t;
	if(candy[t]==0)
		{
			cout<<"Error - you don't have any of that type.";
		}
	else
	{
		candy[t]=candy[t]-1;
	}
}

const double sentinel= -1000;

void save(int candy[7])
{
	ofstream hf;
	hf.open("candy.txt");
	
	for(int i=0; i<7; i=i+1)
	{
		hf << candy[i] << endl;
	}
	hf << sentinel << endl;
	
	hf.close();
	cout<<"Candy database saved to the file candy.txt";
}

void load(int candy[7])
// sentinel version
{
	double entry;
	candy[7]=0;
	
	ifstream hf;
	hf.open("candy.txt");
	double sum=0;
	sum=sum+candy[1]+candy[2]+candy[3]+candy[4]+candy[5]+candy[6];
	cout<<"Candy Inventory: \n";
	cout<<"Candy Corn  "<<candy[1]<<endl;
	cout<<"Licorice  "<<candy[2]<<endl;
	cout<<"Jaw Breakers  "<<candy[3]<<endl;
	cout<<"Peanutbutter Cups  "<<candy[4]<<endl;
	cout<<"M&Ms  "<<candy[5]<<endl;
	cout<<"Other  "<<candy[6]<<endl;
	
	hf.close();
}

int main()
{
	int candycorn, licorice, jawbreakers, peanutbuttercups, mnms, other;
	int candy[7]={0,0,0,0,0,0,0}; //start off with no candy at all
	welcome();
	char command;
	do{
		cout<<"Command-> ";
		cin>>command;
		if(command=='M'||command=='m')
		{
			//Print this menu of commands
			listcommands();
		}
		if(command=='C'||command=='c')
		{
			//Print this types of candy
			listcandytypes();
		}
		if(command=='I'||command=='i')
		{
			//Print the candy inventory
			inventory(candy);
		}
		if(command=='T'||command=='t')
		{
			//Add candy to inventory]
			trickortreat(candy);
		}
		if(command=='E'||command=='e')
		{
			//Eat candy
			eat(candy);
		}
		if(command=='S'||command=='s')
		{
			//Save to the file candy.dat
			save(candy);
		}
		if(command=='L'||command=='l')
		{
			//Load from the file candy.dat
			load(candy);
		}
	}while(command!='Q'&&command!='q');
	cout<<"Enjoy your trip to the dentist!\n";
	return 0;
}

//TEST RUN:
//thomas% ./a.out
//**Welcome to the Candy Database Program**
//Here is the list of commands:
// E - Eat a piece of candy
// T - Trick or Treat: get a piece of candy
// I - Inventory listing
// C - List candy types
// M - Print this menu of commands
// S - Save to the file candy.dat
// L - Load from the file candy.dat
// Q - Quit this program
//Command-> M
//Here is the list of commands:
// E - Eat a piece of candy
// T - Trick or Treat: get a piece of candy
// I - Inventory listing
// C - List candy types
// M - Print this menu of commands
// S - Save to the file candy.dat
// L - Load from the file candy.dat
// Q - Quit this program
//Command-> c
//Candy Types:
//1  Candy Corn
//2  Licorice
//3  Jaw Breakers
//4  Peanutbutter Cups
//5  M&Ms
//6  Other
//Command-> T
//Please enter the candy type (1-6):
//1
//Command-> t
//Please enter the candy type (1-6):
//3
//Command-> c
//Candy Types:
//1  Candy Corn
//2  Licorice
//3  Jaw Breakers
//4  Peanutbutter Cups
//5  M&Ms
//6  Other
//Command-> i
//Candy Inventory:
//Candy Corn  1
//Licorice  0
//Jaw Breakers  1
//Peanutbutter Cups  0
//M&Ms  0
//Other  0
//You have 2 pieces of candy.
//Command-> e
//Please enter the candy type (1-6):
//1
//Command-> i
//Candy Inventory:
//Candy Corn  0
//Licorice  0
//Jaw Breakers  1
//Peanutbutter Cups  0
//M&Ms  0
//Other  0
//You have 1 pieces of candy.
//Command-> e
//Please enter the candy type (1-6):
//1
//Error - you don't have any of that type.Command-> s
//Candy database saved to the file candy.txtCommand-> l
//Candy Inventory:
//Candy Corn  0
//Licorice  0
//Jaw Breakers  1
//Peanutbutter Cups  0
//M&Ms  0
//Other  0
//Command-> q
//Enjoy your trip to the dentist!
//thomas%
	