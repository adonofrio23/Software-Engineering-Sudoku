public static Cell[] FindAllErrors(Puzzle* puzzle)
{
	Cell[] errorList = {};
	size = puzzle->GetSize();
	int count = 0;
	
		for(int row = 0; row < size; row++)
		{
			for(int col = 0; col < size; col++)
			{
				if(puzzle->GetCell(row, col) != 0 && puzzle->GetCell(row, col)->IsCorrect == false)
				{
					errorList[count] = puzzle->GetCell(row, col);
					count++;
				}
			}
				
		}
	
	return valList;
}
