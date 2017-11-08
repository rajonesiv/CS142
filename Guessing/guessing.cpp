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
	do
	{
		int number, guess;
		srand(time(NULL)); //this will ensure that we get a random number each time
		number = 1 + rand()%100; //this is to give a random number
		do
		{	
			int insult;
			srand(time(NULL));
			insult = 1 + rand()%3;//there are three possible insults to choose from for each if statement
			cout << "\nEnter your guess: ";
			cin >> guess;
			if(guess<number)
				{
					if(insult==1)
						{
							cout << "Too low! Do you accept defeat?\n";
						}
					else if(insult==2)
						{
							cout << "Too low! I would ask how old you are, but I know you can't count that high...\n";
						}
					else if (insult==3)
						{
							cout << "too low! Hey, you have something on your chin....third one down.\n";
						}
				}
		
			else if(guess>number)
				{
					if(insult==1)
						{
							cout << "Too high! You're killing me, smalls! "<<"You dare compare yourself to me!\n";
						}
					else if(insult==2)
						{
							cout<<"Too high! If you were twice as smart, you'd still be stupid!\n";
						}
					else if(insult==3)
						{
							cout<<"Too high! We all sprang from apes, but you didn't spring far enough!\n";
						}
				}
			else if(guess==number)
				{
					cout<<"\nYou may not be my equal, but you have won my respect!\n";
				}
		
		}while(guess!=number); //allows the player to keep on guessing as long as he guesses incorrectly
	
		cout<<"\nDo you want to play again? Y/N .\n";
		cin>>choice;
	} while(choice=='Y');
	cout<<"\nHasta la vista, baby!\n\n";
	return choice; //player can choose whether or not (s)he wants to continue playing
}

//SAMPLE RUN:

//thomas% ./a.out

//***Welcome to the GUESSING GAME!!***
//I have a number between 1 and 100. Can you guess it?

//Enter your guess: 50
//too low! Hey, you have something on your chin....third one down.

//Enter your guess: 75
//Too low! I would ask how old you are, but I know you can't count that high...

//Enter your guess: 80
//Too low! I would ask how old you are, but I know you can't count that high...

//Enter your guess: 90
//Too low! Do you accept defeat?

//Enter your guess: 95
//Too low! I would ask how old you are, but I know you can't count that high...

//Enter your guess: 99
//Too high! You're killing me, smalls! You dare compare yourself to me!

//Enter your guess: 98
//Too high! You're killing me, smalls! You dare compare yourself to me!

//Enter your guess: 97
//Too high! If you were twice as smart, you'd still be stupid!

//Enter your guess: 96

//You may not be my equal, but you have won my respect!

//Do you want to play again? Y/N .
//Y

//Enter your guess: 96
//Too high! You're killing me, smalls! You dare compare yourself to me!

//Enter your guess: 50
//Too high! You're killing me, smalls! You dare compare yourself to me!

//Enter your guess: 10
//Too high! You're killing me, smalls! You dare compare yourself to me!

//Enter your guess: 5
//too low! Hey, you have something on your chin....third one down.

//Enter your guess: 7
//too low! Hey, you have something on your chin....third one down.

//Enter your guess: 8
//Too low! I would ask how old you are, but I know you can't count that high...

//Enter your guess: 9

//You may not be my equal, but you have won my respect!

//Do you want to play again? Y/N .
//N

//Hasta la vista, baby!

//thomas%
