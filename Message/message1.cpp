//Andrew Jones
//This program is designed to encrypt a message by changing each individual letter
//and "adding 3" (or any random encryption key)to it.
//It will then print out the encrypted message.

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

char wraparound(char x) //need to subtract 23 in order to go back around alphabet
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

void encryptline(char s[])
{
	for(int i=0; i<strlen(s); i=i+1)
	{
		if('a'<=s[i] && s[i]<='w') //between a and w it is a normal encryption
		{
			s[i]=encrypt(s[i]);
		}
		else if('x'<=s[i] && s[i]<='z')
		{
			s[i]=wraparound(s[i]); //between x and z it must wrap back around the
			//alphabet in order to continue the encryption
		}
		if('A'<=s[i] && s[i]<='W') //did same thing as above but with capital letters
		{
			s[i]=encrypt(s[i]);
		}
		else if('X'<=s[i] && s[i]<='Z')
		{
			s[i]=wraparound(s[i]);
		}
	}
}

void decryptline(char s[])
{
	for(int i=0; i<strlen(s); i=i+1)
	{
		if('d'<=s[i] && s[i]<='z') //decryption points are different than encryption
		{
			s[i]=decrypt(s[i]);
		}
		else if('a'<=s[i] && s[i]<='c') //needed to change the letters for wraparound
		{
			s[i]=wrapback(s[i]);
		}
		if('D'<=s[i] && s[i]<='Z') //from D to Z we need to decrypt
		{
			s[i]=decrypt(s[i]);
		}
		else if('A'<=s[i] && s[i]<='C') //from A to C we need to wrapback
		{
			s[i]=wrapback(s[i]);
		}
	}
}
void save(int line[100])
{
	ofstream hf;
	hf.open("text.txt");
	
	for(int i=0; i<100; i=i+1)
	{
		hf << line[i] << endl;
	}
	hf << sentinel << endl;
	
	hf.close();
	cout<<"Line saved to the file text.txt";
}

void load(int line[100])
// sentinel version
{
	double entry;
	line[100]=0;
	
	ifstream hf;
	hf.open("text.txt");
	cout << line << endl; //not sure if this will work...
	
	hf.close();
}

int main()
{
	char s[100];
	char line[100];
	ifstream f; //reading purposes only
	char filename[100];
	char cryption;
	
	welcome();
	cout << "Please enter your filename: ";
	cin >> filename;
	
	f.open(filename); //open file
	f.getline(line,100); //reads first line of file
	
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
		encryptline(line);
		filename << line << endl;
		cout << "\nThe encrypted form of your message is\n"
			<< line << endl;
	}
	else if(cryption=='D'||cryption=='d')
	{
		decryptline(line);
		filename << line << endl;
		cout<< "\nThe decrypted form of your message is\n"
			<< line <<endl;
	}		
	
	cout<< "\nThank you for using this classified program\n";
	
	f.close(); //close the file
	return 0;
}