#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
int main()
{
	int restart = 0;
	char op;

	do {

		srand(time(NULL));  //use to change the random number after each turn 
		int comp = rand() % 3 + 1; //random number between 1-3
		int user;
		cout << "\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
		cout << "\tROCK PAPER SCISSORS!" << endl;
		cout << "\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
		cout << "Enter your option" << endl;
		cout << "1) Rock" << endl;
		cout << "2) Paper" << endl;
		cout << "3) Scissors" << endl;
		cout << "Choose carefully!" << endl;
		cin >> user;

		if (user == 1)
		{
			cout << "-You choose Rock-" << endl;
		}
		else if (user == 2)
		{
			cout << "-You choose Paper-" << endl;
		}
		else{
			cout << "-You choose Scissors-" << endl;
		}

		if (comp == 1)
		{
			cout << "-CPU chooses Rock-" << endl;
		}
		else if (comp == 2)
		{
			cout << "-CPU chooses Paper-" << endl;
		}
		else{
			cout << "-CPU chooses Scissors-" << endl;
		}
		
		//if the user==comp
		if (comp == user)
		{
			cout << "Ladies and Gentlemen!" << endl;
			cout << "We have a tie!" << endl;
		}


		//user chooses rock
		else if (user == 1)
		{
			if (comp == 2)
			{
				cout << "You Lose!" << endl;
				cout << "Paper covers Rock!" << endl;
			}
			else
			{
				cout << "You Win!" << endl;
				cout << "Rock smashes Scissors!" << endl;
			}
		}

		//user chooses paper
		else if (user == 2)
		{
			if (comp == 1)
			{
				cout << "You Win!" << endl;
				cout << "Paper covers Rock!" << endl;
			}
			else
			{
				cout << "You Lose!" << endl;
				cout << "Scissors cuts Paper!" << endl;
			}


		}
		//user chooses scissors

		else if (user == 3)
		{
			if (comp == 1)
			{
				cout << "You Lose!" << endl;
				cout << "Rock smashes Scissors!" << endl;
			}
			else
			{
				cout << "You Win!" << endl;
				cout << "Scissors cuts Paper!" << endl;
			}
		}
		cout << "Want to play another round?(y/n)" << endl;
		cin >> op;
		if (op == 'y' || op == 'Y')
		{
			restart = 1;
		}

		else {
			restart = 0;
		}


	} while (restart == 1);

	return 0;
}