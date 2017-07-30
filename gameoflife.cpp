#include <iostream>
using namespace std;

/* Output choices */
const char LIVECELL = '#';
const char DEADCELL = '.';


/* Internal representation choices */
const char BOARDSIZE = 20;

/* Initial state choices */

/* Output */

void print_board(char (&board)[BOARDSIZE][BOARDSIZE]) // yes, can manipulate referenced data
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	
	for (int j = 0; j < BOARDSIZE; j++)
		cout << '='; // separate consecutive entire-board printouts
	cout << endl;
}

int main()
{
	/* Internal representation */
	char board [BOARDSIZE][BOARDSIZE];
	
	/* Initial state */
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			board[i][j] = DEADCELL;
		}
	}
	
	print_board(board);
}