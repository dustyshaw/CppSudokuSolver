// Dusty Shaw
// Final Project for Survey of Languages
/*
	Sudoku Solver
	Recursively solves a sudoku board
	In the case of an unsolvable sudoku board, it will report an unsolvable board.
*/

#include <iostream>
#include <tuple>
#include <stdlib.h> // for clearing the screen
#include <chrono>   // for timing functions
using namespace std::chrono;

int RecursiveCallCount = 0; // global variable, pls don't tell garth

int getCurrentRow(std::tuple<int, int> coord, bool smallRow)
{
	int rtn;
	int squareRows = ((std::get<0>(coord)) / 3) % 3;
	if (smallRow)
	{
		squareRows = ((std::get<1>(coord)) / 3) % 3;
	}
	if (squareRows < 1)
	{
		rtn = 0;
	}
	if (squareRows >= 1 && squareRows < 2)
	{
		rtn = 1;
	}
	if (squareRows >= 2)
	{
		rtn = 2;
	}
	return rtn;
}

int getCurrentCol(std::tuple<int, int> coord, bool smallRow)
{
	int rtn = -1;
	int col = (std::get<0>(coord));
	if (smallRow)
	{
		col = (std::get<1>(coord));
	}
	if ((col % 3) == 0)
	{
		rtn = 0;
	}
	if ((col % 3) == 1)
	{
		rtn = 1;
	}
	if ((col % 3) == 2)
	{
		rtn = 2;
	}

	return rtn;
}

bool CheckValid2d(int candidateNumber, int board[9][9], std::tuple<int, int> coord)
{
	bool rtn = true;
	int squareNum = std::get<0>(coord);
	//std::cout << squareNum << " < Square Num";
		for (int j = 0; j < 9; j++) // check square
		{
			if (board[squareNum][j] == candidateNumber)
			{
				rtn = false; // This means it exists in the current square
			}
		}
	int squareRow = getCurrentRow(coord, false);
	int row = getCurrentRow(coord, true);

	int bigCol = getCurrentCol(coord, false);
	int smallCol = getCurrentCol(coord, true);

	int bigRowStartNum = squareRow * 3;
	int smallRowStartNum = row * 3;

	int bigColStartNum = bigCol ;
	int smallColStartNum = smallCol ;

	for (int i = bigRowStartNum; i < (bigRowStartNum + 3); i++) // check current row
	{
		for (int j = smallRowStartNum; j < (smallRowStartNum+3); j++)
		{
			if (board[i][j] == candidateNumber)
			{
				rtn = false;
			}
		}
	}

	for (int k = bigColStartNum; k < (bigColStartNum + 9); k+=3)
	{
		for (int h = smallColStartNum; h < (smallColStartNum + 3); h+=3)
		{
			if (board[k][h] == candidateNumber)
			{
				rtn = false;
			}
			if (board[k][h + 3] == candidateNumber)
			{
				rtn = false;
			}
			if (board[k][h + 6] == candidateNumber)
			{
				rtn = false;
			}
		}
	}
	
	return rtn;
}

void Print2dBoard(int board[9][9])
{
	int blockSize = 3;
	int gridDimension = 9;
	int barCounter = 1;

	for (int bigRow = 0; bigRow < gridDimension; bigRow += blockSize)
	{
		for (int bigCol = 0; bigCol < gridDimension; bigCol += blockSize)
		{
			for (int row = bigRow; row < bigRow + blockSize; row++)
			{
				for (int col = bigCol; col < bigCol + blockSize; col++)
				{
					if (board[row][col] == 0)
					{
						std::cout << " " << "-";
					}
					else
					{
						std::cout << " " << board[row][col];

					}
					if ((barCounter % 3) == 0)
					{
						std::cout << "|";
					}
					barCounter++;
				}
			}
			std::cout << "\n";
		}
		std::cout << "------------------\n";
	}
}

bool SelectValueForSquare(int board[9][9], int OgBoard[9][9])
{
	
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (board[x][y] == 0)
			{
				std::tuple<int, int> coord(x, y);
				for (int num = 1; num <= 9; num++)
				{
					if (CheckValid2d(num, board, coord))
					{
						if (OgBoard[x][y] == 0) // If it is a place you can draw on the og board
						{
							board[x][y] = num; // Set the cell to the candidate number
						}
						Print2dBoard(board);
						//system("CLS");
						std::cout << "\n\n";
						RecursiveCallCount++;	// This is a counter for fun
						if (SelectValueForSquare(board, OgBoard))
						{
							return true; // If the recursive call succeeds, return true
						}
						else
						{
							if (OgBoard[x][y] == 0) // If it is a place you can draw on the og board
							{
								board[x][y] = 0; // If the recursive call fails, backtrack by resetting the cell
								Print2dBoard(board);
								std::cout << "\n\n";
							}
						}
					}
				}
				return false; 
			}
		}
	}
	return true;
}

int main()
{
	std::cout << "Sudoku Solver\nSelect A Board:\n";

	int boardNums2d[9][9] = {
	{ 5, 3, 0, 6, 0, 0, 0, 9, 8 },
	{ 0, 7, 0, 1, 9, 5, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 6, 0 },
	{ 8, 0, 0, 4, 0, 0, 7, 0, 0 },
	{ 0, 6, 0, 8, 0, 3, 0, 2, 0 },
	{ 0, 0, 3, 0, 0, 1, 0, 0, 6 },
	{ 0, 6, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 4, 1, 9, 0, 8, 0 },
	{ 2, 8, 0, 0, 0, 5, 0, 7, 9 } };
	int EzBoard[9][9] = {
				{ 5, 3, 4, 6, 0, 2, 1, 9, 8 },
				{ 6, 7, 0, 1, 9, 5, 0, 4, 2 },
				{ 9, 1, 0, 3, 4, 8, 0, 6, 7 },
				{ 8, 0, 9, 4, 2, 6, 7, 1, 0 },
				{ 7, 6, 1, 8, 5, 3, 0, 2, 4 },
				{ 4, 2, 3, 7, 0, 1, 8, 5, 6 },
				{ 9, 6, 1, 0, 8, 7, 3, 4, 5 },
				{ 5, 3, 0, 4, 1, 9, 0, 8, 6 },
				{ 2, 8, 4, 0, 3, 5, 1, 7, 9 } };
	std::cout << "Board [1] - The Not So EZ Board\n";
	Print2dBoard(boardNums2d);
	std::cout << "\n\nBoard [2] - The EZ Board \n";
	Print2dBoard(EzBoard);
	int choice;
	std::cin >> choice;
	if (choice == 2)
	{
		int boardNums2d[9][9] = {
				{ 5, 3, 4, 6, 0, 2, 1, 9, 8 },
				{ 6, 7, 0, 1, 9, 5, 0, 4, 2 },
				{ 9, 1, 0, 3, 4, 8, 0, 6, 7 },
				{ 8, 0, 9, 4, 2, 6, 7, 1, 0 },
				{ 7, 6, 1, 8, 5, 3, 0, 2, 4 },
				{ 4, 2, 3, 7, 0, 1, 8, 5, 6 },
				{ 9, 6, 1, 0, 8, 7, 3, 4, 5 },
				{ 5, 3, 0, 4, 1, 9, 0, 8, 6 },
				{ 2, 8, 4, 0, 3, 5, 1, 7, 9 } };
	}
	int unsolvable[9][9] = {
				{ 5, 1, 6, 3, 0, 7, 8, 0, 9 },
				{ 8, 4, 9, 6, 0, 5, 7, 0, 0 },
				{ 7, 3, 2, 0, 0, 0, 0, 6, 5 },
				{ 1, 3, 5, 4, 7, 2, 9, 6, 8 },
				{ 0, 6, 0, 5, 9, 1, 3, 7, 0 },
				{ 9, 0, 7, 0, 0, 6, 0, 5, 0 },
				{ 2, 5, 3, 6, 8, 4, 7, 9, 1 },
				{ 1, 8, 6, 2, 0, 7, 0, 5, 0 },
				{ 0, 7, 4, 5, 0, 0, 6, 0, 8 } };

	int TwoSolutions[9][9] = {
				{ 0, 8, 0, 0, 5, 0, 0, 1, 0 },
				{ 0, 0, 9, 0, 0, 8, 0, 0, 0 },
				{ 7, 4, 3, 0, 1, 0, 0, 0, 0 },
				{ 8, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 5, 8, 0, 4, 3, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 6 },
				{ 0, 0, 0, 0, 3, 0, 9, 7, 2 },
				{ 0, 0, 0, 5, 0, 0, 4, 0, 0 },
				{ 0, 7, 0, 0, 8, 0, 0, 5, 0 } };

	// An easier board
	/*int boardNums2d[9][9] = {
				{ 5, 3, 4, 6, 0, 2, 1, 9, 8 },
				{ 6, 7, 0, 1, 9, 5, 0, 4, 2 },
				{ 9, 1, 0, 3, 4, 8, 0, 6, 7 },
				{ 8, 0, 9, 4, 2, 6, 7, 1, 0 },
				{ 7, 6, 1, 8, 5, 3, 0, 2, 4 },
				{ 4, 2, 3, 7, 0, 1, 8, 5, 6 },
				{ 9, 6, 1, 0, 8, 7, 3, 4, 5 },
				{ 5, 3, 0, 4, 1, 9, 0, 8, 6 },
				{ 2, 8, 4, 0, 3, 5, 1, 7, 9 } };*/

	Print2dBoard(TwoSolutions);
	std::cout << "\n";
	int OgBoard[9][9] = {};

	RecursiveCallCount = 0;
	auto start = high_resolution_clock::now(); // start clock before recursion starts

	if (SelectValueForSquare(TwoSolutions, OgBoard))
	{
		auto stop = high_resolution_clock::now(); // End as soon as SolveSudoku == true meaning it found a solution
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "Sudoku Solved Successfully!\nRun Time: " << duration.count() / 1000000 << " Seconds\nNumber of Recursive Calls: " << RecursiveCallCount;
	}
	else
	{
		auto stop = high_resolution_clock::now(); // End as soon as SolveSudoku == true meaning it found a solution
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "\n\nNo solution exists.\n\nRun Time: " << duration.count() / 1000000 << " Seconds\nNumber of Recursive Calls: " << RecursiveCallCount;
	}

	return 0;
}
