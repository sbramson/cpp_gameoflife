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

void fatal(string msg)
{
	cout << msg << endl;
	exit();
}

char[][] load_board_from_file(string filepath)
{	
	ifstream myfile;
	myfile.open(filepath);
	if (!myfile.is_open()) return null;
	
	int height;
	int width;
	
	if (getline(myfile, line))
		height = std::stoi(line);
	else
		fatal("Could not parse height of board from file " + filepath);
	
	if (getline(myfile, line))
		width = std::stoi(line);
	else
		fatal("Could not parse width of board from file " + filepath);
	
	char result [height][width];
	int currentRow = 0;
	
	while(getline(myfile, line))
	{
		if (line.length() < width)
			fatal("Malformed input file: line " + currentRow + " does not match stated board width");

		for (int i = 0; i < width; i++)
		{
			if (line[i] != LIVECELL && line[i] != DEADCELL)
				fatal("Malformed input file: line " + currentRow + " contains non-cell character");

			result[currentRow][i] = line[i];
		}
		currentRow++;
	}
	
	return result;
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