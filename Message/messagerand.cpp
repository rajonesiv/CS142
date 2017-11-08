//Andrew Jones
//This program is designed to encrypt a message by changing each individual letter
//and "adding 3" to it. It will then print out the encrypted message.

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

char encrypt(char x)
{
	return x+3;
}

char decrypt(char x)
{
	return x-3;
}

char wraparound(char x)
{
	return x-23;
}

char wrapback(char x)
{
	return x+23;
}

void welcome()
{
	cout<< "Welcome. You know what to do."<< endl;
}

void encrypt(char s[])
{
	for(int i=0; i<strlen(s); i=i+1)
	{
		if('a'<=s[i] && s[i]<='w')
		{
			s[i]=encrypt(s[i]);
		}
		else if('x'<=s[i] && s[i]<='z')
		{
			s[i]=wraparound(s[i]);
		}
		if('A'<=s[i] && s[i]<='W')
		{
			s[i]=encrypt(s[i]);
		}
		else if('X'<=s[i] && s[i]<='Z')
		{
			s[i]=wraparound(s[i]);
		}
	}
}

void decrypt(char s[])
{
	for(int i=0; i<strlen(s); i=i+1)
	{
		if('a'<=s[i] && s[i]<='w')
		{
			s[i]=decrypt(s[i]);
		}
		else if('x'<=s[i] && s[i]<='z')
		{
			s[i]=wrapback(s[i]);
		}
		if('A'<=s[i] && s[i]<='W')
		{
			s[i]=decrypt(s[i]);
		}
		else if('X'<=s[i] && s[i]<='Z')
		{
			s[i]=wrapback(s[i]);
		}
	}
}

int main()
{
	char s[100];
	char line[100];
	ifstream f;
	char filename[100];
	char cryption;
	
	welcome();
	cout << "Please enter your filename: ";
	cin >> filename;
	
	f.open(filename);
	f.getline(line,100);
	f.close();
	
	cin.getline(s,100);
	
	
	cout<< "Please choose either encryption (e) or decryption (d)\n";
	cin>>cryption;
	
	char t[strlen(s)+1];
		for(int i=0; i<strlen(s); i=i+1)
		{
			int j=strlen(s)+i;
			t[j]=s[i];
		}
		t[strlen(s)]=0;
		
	if(cryption=='E'||cryption=='e')
	{
		encrypt(line);
		cout<< "\nThe encrypted form of your message is\n"
			<< line << endl;
	}
	else if(cryption=='D'||cryption=='d')
	{
		decrypt(line);
		cout<< "\nThe decrypted form of your message is\n"
			<< line <<endl;
	}		
	
	cout<< "\nThank you for using this classified program\n";
	
	return 0;
}