#include "..Anthony/Cell.h"
#include <iostream>
#include <vector>

using namespace std;

//Code Stub for the FindAllErrors Algorithm
//NOTE: No longer uses array, instead vector for full functionality
//Updated with class Cell as pointers from main
public vector<Cell*> FindAllErrors(Puzzle* puzzle)
{
	//Variables
	//errorList: Returned Value; List of type Cell that contains found errors
	//size: Used as iterator; Puzzle size used for both row and column limits because of square puzzle
	//count: Used as iterator in errorList; Sets location in errorList, add for each error
	vector<Cell*> errorList;
	int size = puzzle->GetSize();

	//For loop for rows within the puzzle, using size
	for (int row = 0; row < size; row++)
	{
		//For loop for columns within the puzzle, using size
		for (int col = 0; col < size; col++)
		{
			//If statements that does the following:
			//1) Checks if the value of the cell is 0, this means it is empty
			//If the cell is empty, do not add cell to errorList; otherwise,...
			//2) Checks using IsValid() to determine if the puzzle cell at row and col is not correct
			//IsValid() uses the solution and current value of the cell and returns true if correct, false if not
			//If the returned value is false...
			if (puzzle->GetCell(row, col)->GetValue() != 0 && !puzzle->isValid(row, col))
			{
				//Add the Cell (not Cell value) to errorList at point count
				//Then increment count for the next position in errorList
				errorList.push_back(puzzle->GetCell(row, col));
			}
		}
	}

	//Returns the list of Cells where errors were found
	return errorList;
}
