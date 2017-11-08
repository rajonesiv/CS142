//Andrew Jones
//This program is designed to choose a random number between 1 and 100
//and then asks the user to guess the number.

#include <iostream>
#include <cstdlib> //I put these headers underneath the iostream but I am not
#include <ctime> //sure what the stdlib actually is...
using namespace std;

void intro()
{
	//void function for the welcome intro
	cout<<"\n***Welcome to the GUESSING GAME!!***\n";
	cout << "I have a number between 1 and 100. Can you guess it?\n";
}

int main()
{	char choice;
	//only once the player says no will the function stop looping
	intro();//I put the intro outside of the do while since I didn't want it to keep
	//welcoming me each guess
	int number, guess;
	do
	{
		srand(time(NULL)); //this will ensure that we get a random number each time
		number = 1 + rand()%100; //this is to give a random number
		cout << "\nEnter your guess:\n\n";
		cin >> guess;
		if(guess<number)
			{
				cout << "Too low! Hey, you have something on your chin....third one down.\n";
			}
		
		else if(guess>number)
			{
				cout<<"Too high! We all sprang from apes, but you didn't spring far enough!\n";
			}
		else if(guess==number)
			{
				cout<<"\nYou may not be my equal, but you have won my respect!\n";
			}
		
	}while(guess!=number); //allows the player to keep on guessing as long as he guesses incorrectly
	
		cout<<"\nDo you want to play again? Y/N .\n";
		cin>>choice;
	return choice; //player can choose whether or not (s)he wants to continue playing
}
