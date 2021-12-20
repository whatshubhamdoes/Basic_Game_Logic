#include <iostream>
using namespace std;
string tboard[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
int player = 1;
int position = 0;

void intro()
{
	cout << "Press <Enter> to begin: ";
	getchar(); //haulting the screen  
	cout << "\n";

	cout << "\n";
	cout << "* * * * * * * * * * *\n";
	cout << "Tic - Tac - Toe\n";
	cout << "* * * * * * * * * * *\n";

	cout << "Player 1]- X\n";
	cout << "Player 2]- O\n";

	cout << "The 3x3 tic tac toe grid is shown below:\n\n";

	cout << "     |     |      \n";
	cout << "  1  |  2  |  3   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  4  |  5  |  6   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  7  |  8  |  9   \n";
	cout << "     |     |      \n\n";

}

bool is_winner()
{
	bool winner = false;
	//checking rows for the win
	if ((tboard[0] == tboard[1]) && (tboard[1] == tboard[2]) && tboard[0] != " ")
	{
		winner = true;
	}
	else if ((tboard[3] == tboard[4]) && (tboard[4] == tboard[5]) && tboard[3] != " ")
	{
		winner = true;
	}

	else if ((tboard[6] == tboard[7]) && (tboard[7] == tboard[8]) && tboard[6] != " ")
	{
		winner = true;
	}

	//checking columns for the win

	else if ((tboard[0] == tboard[3]) && (tboard[3] == tboard[6]) && tboard[0] != " ")
	{
		winner = true;
	}

	else if ((tboard[1] == tboard[4]) && (tboard[4] == tboard[7]) && tboard[1] != " ")
	{
		winner = true;
	}

	else if ((tboard[2] == tboard[5]) && (tboard[5] == tboard[8]) && tboard[2] != " ")
	{
		winner = true;
	}

	//checking diagonals for the win

	else if ((tboard[0] == tboard[4]) && (tboard[4] == tboard[8]) && tboard[0] != " ")
	{
		winner = true;
	}

	else if ((tboard[2] == tboard[4]) && (tboard[4] == tboard[6]) && tboard[2] != " ")
	{
		winner = true;
	}

	return winner;

}

bool filled_up()
{
	bool filled = true;

	for (int i = 0; i < 9; i++)
	{
		if (tboard[i] == " ")
		{
			filled = false;
		}
	}

	return filled;
}

void draw()
{
	cout << "     |     |      \n";
	cout << "  " << tboard[0] << "  |  " << tboard[1] << "  |  " << tboard[2] << "\n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  " << tboard[3] << "  |  " << tboard[4] << "  |  " << tboard[5] << "\n";
	cout << "_____|_____|_____ \n";
	cout << "  " << tboard[6] << "  |  " << tboard[7] << "  |  " << tboard[8] << "\n";
	cout << "     |     |      \n";
	cout << "\n";

}

void set_position()
{
	cout << "Player " << player << "'s turn (Enter: 1-9 as shown at the start)";   //1-9 (Enter: (1-9))
	while (!(cin >> position))
	{
		cout << "Please enter a valid number between (1-9 as shown at the start)" << endl;
		cin.clear();  //flushing the buffer
		cin.ignore();
	}
	cout << endl;

	while (tboard[position - 1] != " ") {
		cout << "Oops, that position is already filled\nTry again\n";
		cout << "Player " << player << "'s Turn (Enter 1-9): ";
		cin >> position;
		cout << "\n";


	}

}

void update_tboard()
{

	if (player % 2 == 1) {
		tboard[position - 1] = "X";
	}
	else
	{
		tboard[position - 1] = "O";
	}
}


void change_player() {
	if (player == 1) {
		player++;
	}
	else {
		player--;
	}
}


void take_turn()
{
	while (!is_winner() && !filled_up())
	{
		//invoking the functions
		set_position();
		update_tboard();
		change_player();
		draw();
	}
}

void end_game()
{
	if (is_winner())
	{
		cout << "There is a winner!" << endl;

	}

	else if (filled_up())
	{
		cout << "There is a tie!" << endl;
	}
}
int main()
{
	intro();
	take_turn();
	end_game();
	return 0;
}