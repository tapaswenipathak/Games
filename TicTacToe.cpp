/*
 * Simple Tic Tac Toe Game.
 * Compile : g++ TicTacToe.cpp
 * Run : ./a.out
 */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>

using namespace std;

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int check_win();
void board_status();
void gameplay(char, int, int);
void color(int X);
void Select_character();
char showBoard(char bord);
char player1;
char player2;


/*
 * Driver Function.
 */
int main()
{
    bool play_again = true;
    int yes_or_no = 0;

    while (play_again == true){
    system("cls");
	int player = 1;
	int i, box_no;

	char mark_x_o;
    Select_character();
    //gameplay();
	do
	{
	    system("cls");
	    color(14);
        cout << endl << " Get Ready to Play Tic Tac Toe " << endl << endl;
		board_status();
		player = player % 2 ? 1 : 2;
        gameplay(mark_x_o,box_no,player);
		i = check_win();
		player++;

	}while (i == -1);

    system("CLS");
    color(14);
    cout << endl << " Get Ready to Play Tic Tac Toe " << endl << endl;
	board_status();
    color(15);
	if (i == 1)
		cout << endl << " Player " << --player << " Won" << endl;
	else
		cout << endl <<  " Game Draw!" << endl;
    cout << " Another game? Press 1 for yes or press 2 for no" << endl;
    cin >> yes_or_no;
    while (yes_or_no != 1 && yes_or_no != 2){
        cout << "Invalid number! please press again" << endl;
        cin >> yes_or_no;
    }
    if (yes_or_no == 2)
        play_again = false;
	}
	cout << "Thanks for play!" << endl;
	return 0;
}

void gameplay(char mark_x_o, int box_no,int player){

    cout << endl << " Player " << player << ", enter a number to place an " << player1 << " or " << player2 << ": ";
    cin >> box_no;
    while (cin.fail() || box_no < 1 || box_no > 9 || box_no!= (int)board[box_no]-'0'){
        cin.clear();
        cin.ignore();
        cout << " Invalid Move!" << endl;
        cout << " Player " << player << ", enter a number to " << player1 << " or " << player2 << ": ";
        cin >> box_no;
    }

    mark_x_o = player == 1 ? player1 : player2;

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

	else{
        bool done = true;
        for (int i=1;i<9;i++){
            if (i==(int)board[i]-'0'){
                done = false;
                break;
            }

        }

		if (done) return 0;
    }

	return -1;
}

/*
 * Drawing the board.
 */
void board_status ()
{
    char vertical = ((char)186);
    char horizontal = ((char)205);
    char mid = ((char)206);

    color(15);

	cout << "       " << vertical << "       " << vertical << "       " << endl;

	cout << "      " << showBoard(board[1]);

	color(15);

	cout << vertical;

	cout << "      " << showBoard(board[2]);

	color(15);

	cout << vertical;

	cout << "     " << showBoard(board[3]);

	color(15);

	cout << endl;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << mid;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << mid;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << endl;

	cout << "       " << vertical << "       " << vertical << "        " << endl;

    cout << "      " << showBoard(board[4]);

	color(15);

	cout << vertical;

	cout << "      " << showBoard(board[5]);

	color(15);

	cout << vertical;

	cout << "     " << showBoard(board[6]);

	color(15);

	cout << endl;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << mid;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << mid;

	for(int i = 0; i < 7; i ++) cout << horizontal;

	cout << endl;

    cout << "      " << showBoard(board[7]);

	color(15);

	cout << vertical;

	cout << "      " << showBoard(board[8]);

	color(15);

	cout << vertical;

	cout << "     " << showBoard(board[9]);

	color(15);

	cout << endl;

	cout << "       " << vertical << "       " << vertical << "       " << endl;



}

void color(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

char showBoard(char bord)
{

        if(bord == player1)
        {
            color(11);
        }
        else if(bord == player2)
        {
            color(12);
        }
        else
        {
            color(15);
        }
        return bord;
}
void Select_character(){

    color(15);
    cout << " Player 1 please select your character!: ";
    cin >> player1;
    while ((int)player1 >47 && (int)player1 <58){
    cout << " You can't select a number, please select another!: ";
    cin >> player1;
    }
    cout << " Player 2 please select yours too!: ";
    cin >> player2;
    while (player1 == player2){
        cout << " You can't have the same character as player 1, please select another!: ";
        cin >> player2;
        while ((int)player2 >47 && (int)player2 <58){
            cout << " You can't select a number, please select another!: ";
            cin >> player2;
    }
    }

    return;
}
