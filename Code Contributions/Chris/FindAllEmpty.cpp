#include "..Anthony/Cell.h"
#include <iostream>
#include <vector>

using namespace std;

//Code Stub for the FindAllEmpty Algorithm
//NOTE: No longer uses array, instead vector for full functionality
//Uses Cell pointers due to Cell as a pointer in main, prevents errors
public vector<Cell*> FindAllEmpty(Puzzle* puzzle)
{
	//Variables
	//emptyList: Returned Value; List of type Cell that contains found empty values
	//size: Used as iterator; Puzzle size used for both row and column limits because of square puzzle
	//count: Used as iterator in emptyList; Sets location in emptyList, add for each found empty value
	vector<Cell*> emptyList;
	int size = puzzle->GetSize();
	//For loop for rows within the puzzle, using size
	for (int row = 0; row < size; row++)
	{
		//For loop for columns within the puzzle, using size
		for (int col = 0; col < size; col++)
		{
			//If statement that does the following:
			//Checks if the value of the cell is 0, this means it is empty
			//If the cell is empty...
			if (puzzle->GetCell(row, col)->GetValue() == 0)
			{
				//Add the Cell (not Cell value) to emptyList at point count
				//Then increment count for the next position in emptyList
				emptyList.push_back(puzzle->GetCell(row, col));
				//For debugging
				//cout << "Row: " << row << " " << "Col: " << col << " " << "Val: " << puzzle->GetCell(row, col).GetValue() << endl;
			}
		}
	}

	//Returns the list of Cells where empty values were found
	return emptyList;
}
