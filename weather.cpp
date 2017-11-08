// Andrew Jones
// this program is designed to convert temperature
// in fahrenheit to temperature in centigrade
// this program will also state whether it is
// hot or cold out depending on the temperature

#include<iostream>
using namespace std;
int main ()
{
	double temperature_fahrenheit, temperature_centigrade, condition;
	cout << "Welcome to the UNWEDGE Weather Program \n";
	cout << "Please enter the temperature in degrees Fahrenheit:";
	
	cin >> temperature_fahrenheit;
	temperature_centigrade = (temperature_fahrenheit - 32) * (5.0/9);
	
	cout << "The temperature is \n" << temperature_centigrade << " as measured in centigrade.\n";
	

	if (temperature_fahrenheit>85)
	{
		cout << "It is hot today! \n";
	}
	
	if (temperature_fahrenheit<20)
	{
		cout << "It is cold today! \n";
	}
	
	return 0;
}