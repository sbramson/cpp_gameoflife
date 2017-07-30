#include <iostream>
using namespace std;

/* Output choices */
const char LIVECELL = '#';
const char DEADCELL = '.';

/* Internal representation choices */
const char BOARDSIZE = 20;

/* Initial state choices */


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
}