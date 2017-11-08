//By: Andrew Jones
//This program is designed to compute tuition bills
//by calculating the cost per amount of credits.

#include <iostream>
using namespace std;
int main()
{
	double tuition_bill, credits;

	cout << "Welcome to the Tuition Bill Program!\n";
	cout << "This program is property of the Butler University Billing Office.\n";
	cout << "Please enter the amount of credits you are taking (-1 to exit)\n";	
	
	cin >> credits;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	//I used this to get the tuition_bill to print out the cents (even though there are none).
	
	if (0<=credits&&credits<=11)
		{
			cout << "The tuition bill is ";
			tuition_bill = credits * 1502.00;
			cout <<"$" << tuition_bill << ". \n";
		}	
	
	//not sure if there's any other command I could have used besides "else if"...
	else if (12<=credits&&credits<=20)
		{
			cout << "The tuition bill is ";
			tuition_bill = 18025.00;
			cout << "$" << tuition_bill << ". \n" ;
		}	
	
	else if (credits>=21)
		{
			cout << "The tuition bill is ";
			tuition_bill = 18025.00 + 1502.00 * (credits - 20.00);
			cout << "$" << tuition_bill << ". \n";
		}	
	
	else if (credits<0)
		{
			cout << "Happy check writing! \n";
		}	
	
	return 0;
}

//thomas% g++ tuition.cpp
//thomas% ./a.out
//Welcome to the Tuition Bill Program!
//This program is property of the Butler University Billing Office.
//Please enter the amount of credits you are taking (-1 to exit)
//10
//The tuition bill is $15020.00.
//thomas% 15
//15: Command not found.
//thomas% ./a.out
//Welcome to the Tuition Bill Program!
//This program is property of the Butler University Billing Office.
//Please enter the amount of credits you are taking (-1 to exit)
//15
//The tuition bill is $18025.00.
//thomas% ./a.out
//Welcome to the Tuition Bill Program!
//This program is property of the Butler University Billing Office.
//Please enter the amount of credits you are taking (-1 to exit)
//22
//The tuition bill is $21029.00.
//thomas% ./a.out
//Welcome to the Tuition Bill Program!
//This program is property of the Butler University Billing Office.
//Please enter the amount of credits you are taking (-1 to exit)
//-1
//Happy check writing!
//thomas%
