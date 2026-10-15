//****************************************************************************************************
//     Concept:               Password/Passphrase Generator
// 
//     Developer:             CreatedbyChev
// 
//     Start Date:            April 27, 2026
//
//     End Date:			  October 15, 2026
//
//     The following programs generate passwords or passphrases for the user & tests the strength of an existing password
//     for users based on a set of predefined algorithms and defined functions.
// 
//****************************************************************************************************

#include <iomanip>
#include <random>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int getLength();
string genPassword(int);
string genPassphrase(string);
int checkStrength(string);
void displayMessage();
void displayInvalid();
//****************************************************************************************************

int main()
{
	string newPword,
		existPword,
		existPhrase,
		newPhrase;
	int length = 0,
		choice;

	cout << "======================================================" << endl;
	cout << setw(40) << "WELCOME TO PASS GEN - 200!!!" << endl;
	cout << "======================================================" << endl;
	cout << endl;

	cout << setw(40) << "WHAT CAN I HELP YOU WITH?:" << endl;
	cout << endl;
	cout << setw(15) << "1. Generate New Password" << endl;
	cout << setw(15) << "2. Check Password Strength" << endl;
	cout << setw(15) << "3. Generate Passphrase" << endl; 
	cout << setw(15) << "4.. Exit Program" << endl;
	cout << endl;

	cout << setw(20) << "Enter Choice (1,2 or 3): ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		// user wants a new password, get length & generate
		length = getLength();
		newPword = genPassword(length);
		cout << endl;
		cout << newPword;
		break;

	case 2:
		//user wants to check password strength, get password & calc score
		cout << "PERFECT! I CAN HELP DETERMINE THE STRENGTH!";
		cout << "FIRST, WHATS THE PASSWORD?:";
		cin >> existPword;
		checkStrength(existPword);
		break;

	case 3:
		// generate a passphrase for the user by encoding the text
		cout << "ENTER 3 TO 5 WORDS YOU CAN EASILY REMEMBER..." << endl;
		cin.ignore();
		getline(cin, existPhrase);
		newPhrase = genPassphrase(existPhrase);
		cout << "YOUR NEW PASSPHRASE IS: " << newPhrase << endl;
		break;

	case 4: 
		//call display message function
		displayMessage();
		break;

	default:
		// call invalid function
		displayInvalid();
		break;

	}

	return 0;

}

//******************************************************************************************************

int getLength()
{
	int length;

	do
	{
		cout << endl;
		cout << "WHAT IS THE DESIRED PASSWORD LENGTH (8 TO 20 CHARACTERS): ";
		cin >> length;

		if (length < 8)
		{
			cout << "LENGTH MUST BE 8 CHARACTERS OR MORE, TRY AGAIN!" << endl;
		}
	} while (length < 8);

	return length;
}

//****************************************************************************************************

string genPassword(int length)
{
	const char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
	const char digits[] = "1234567890";
	const char symbols[] = "!@#$%&*_-+=[]{}|~,./?";

	const char* groups[] = { upperCase, lowerCase, digits, symbols };

	string pool = "";
	for (const char* g : groups)
		pool += g;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, pool.size() - 1);

	string newPassword = "";
	for (int i = 0; i < length; i++)
		newPassword += pool[dist(gen)];


	return newPassword;

}

//****************************************************************************************************
string genPassphrase(string existPhrase)
{
	// Each letter maps to a list of possible substitutions (single ASCII
	// characters only, so length and system compatibility stay predictable).
	static const unordered_map<char, vector<char>> subs = {
		{ 'a', { '@', '4', '^' } },
		{ 'b', { '8', '6' } },
		{ 'e', { '3', '&' } },
		{ 'g', { '9', '6' } },
		{ 'i', { '1', '!', '|' } },
		{ 'l', { '1', '|' } },
		{ 'o', { '0', '*' } },
		{ 's', { '$', '5', 'z' } },
		{ 't', { '7', '+' } },
		{ 'z', { '2', '%', 's' } }
	};

	// One RNG reused for the whole function
	static mt19937 gen(random_device{}());

	string newPhrase = "";

	// Character substitutions
	for (char c : existPhrase)
	{
		char lower = tolower(c);
		auto it = subs.find(lower);

		if (it != subs.end())
		{
			const vector<char>& options = it->second;
			uniform_int_distribution<> dist(0, options.size() - 1);
			newPhrase += options[dist(gen)];
		}
		else
		{
			newPhrase += c;
		}
	}

	// Random capitalization
	uniform_int_distribution<> coin(0, 1);
	for (size_t i = 0; i < newPhrase.size(); i++)
	{
		if (isalpha(newPhrase[i]) && coin(gen) == 0)
			newPhrase[i] = toupper(newPhrase[i]);
	}

	return newPhrase;
}

//****************************************************************************************************

int checkStrength(string password)
{
	const char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
	const char digits[] = "1234567890";
	const char symbols[] = "!@#$%&*_-+=[]{}|~,./?";


	int score = 0;                 //score points grading includes length, upper case, lower case,
	//digits & symbols. +20 points for each criteria meet, total 100.
	bool hasUpper = false,
		hasLower = false,
		hasDigits = false,
		hasSymbol = false;

	for (char c : password)
	{
		if (upperCase[c])
		{
			hasUpper = true;
			score += 10;
		}

		if (lowerCase[c])
		{
			hasLower = true;
			score += 10;
		}

		if (digits[c])
		{
			hasDigits = true;
			score += 10;
		}

		if (symbols[c])
		{
			hasSymbol = true;
			score += 10;
		}

		cout << score;
	}

	return score;

}
//****************************************************************************************************

void displayMessage()
{
	cout << "THANKS FOR USING PASS GEN! SEE YOU NEXT TIME :)" << endl;
	cout << endl;
	return;
}

//****************************************************************************************************

void displayInvalid()
{
	cout << "WOOPS - THAT ENTRY IS INVALID. TRY AGAIN!" << endl;
	cout << endl;
	return;
}
