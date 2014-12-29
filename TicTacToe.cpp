/*
 * Simple Tic Tac Toe Game.
 * Compile : g++ TicTacToe.cpp
 * Run : ./a.out
 */

#include <iostream>
#include <cstdlib>
using namespace std;

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int check_win();
void board_status();

/*
 * Driver Function.
 */
int main()
{
	int player = 1;
	int i, box_no;

	char mark_x_o;

	do
	{
		board_status();
		player = player % 2 ? 1 : 2;

		cout << "Player" << player << ", enter a number to mark_x_o: ";
		cin >> box_no;

		mark_x_o = player == 1 ? 'X' : 'O';

		if (box_no == 1 && board[1] == '1')
			board[1] = mark_x_o;

		else if (box_no == 2 && board[2] == '2')
			board[2] = mark_x_o;

		else if (box_no == 3 && board[3] == '3')
			board[3] = mark_x_o;

		else if (box_no == 4 && board[4] == '4')
			board[4] = mark_x_o;

		else if (box_no == 5 && board[5] == '5')
			board[5] = mark_x_o;

		else if (box_no == 6 && board[6] == '6')
			board[6] = mark_x_o;

		else if (box_no == 7 && board[7] == '7')
			board[7] = mark_x_o;

		else if (box_no == 8 && board[8] == '8')
			board[8] = mark_x_o;

		else if (box_no == 9 && board[9] == '9')
			board[9] = mark_x_o;

		else
		{
			cout << "Invalid Move!";

			player --;
			cin.ignore();
			cin.get();
		}

		i = check_win();
		player++;

	}while (i == -1);

	board_status();

	if (i == 1)
		cout << "~~~Player " << --player << "Won";
	else
		cout << "~~~Game Draw!";

	cin.ignore();
	cin.get();
	return 0;
}


/* -1 : Game in progress.
 *  0 : Game over. No result.
 *  1 : Game over. with result.
 */
int check_win ()
{
	if (board[1] == board[2] && board[2] == board[3])
		return 1;

	else if (board[4] == board[5] && board[5] == board[6])
		return 1;

	else if (board[7] == board[8] && board[8] == board[9])
		return 1;

	else if (board[1] == board[4] && board[4] == board[7])
		return 1;

	else if (board[2] == board[5] && board[5] == board[8])
		return 1;

	else if (board[3] == board[6] && board[6] == board[9])
		return 1;

	else if (board[1] == board[5] && board[5] == board[9])
		return 1;

	else if (board[3] == board[5] && board[5] == board[7])
		return 1;

	else if (board[1] != '1' && board[2] != '2' && board[3] != '3'&&
			 board[4] != 4 && board[5] != 5 && board[6] != '6'&&
			 board[7] != '7' && board[8] != '8' && board[9] != '9')
		return 0;

	return -1;
}

/*
 * Drawing the board.
 */
void board_status ()
{
	cout << endl << endl << " Get Ready to Play Tic Tac Toe " << endl << endl;

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

	cout << "       |       |       " << endl;

	cout << "      " << board[1] << "|      " << board[2] << "|     " << board[3] << endl;

	cout << "_______|_______|________" << endl;
	cout << "       |       |        " << endl;

	cout << "      " << board[4] << "|      " << board[5] << "|     " << board[6] << endl;

	cout << "_______|_______|________" << endl;
	cout << "       |       |        " << endl;

	cout << "      " << board[7] << "|      " << board[8] << "|     " << board[9] << endl;

	cout << "       |       |        " << endl << endl;
}
