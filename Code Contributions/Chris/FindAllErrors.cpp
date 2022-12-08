public static Cell[] FindAllErrors(Puzzle* puzzle)
{
	Cell[] errorList = {};
	size = puzzle->getSize();
	int count = 0;
	
		for(int row = 0; row < size; row++)
		{
			for(int col = 0; col < size; col++)
			{
				if(puzzle->getCell(row, col) != 0 && puzzle->getCell(row, col)->isCorrect == false)
				{
					errorList[count] = puzzle->getCell(row, col);
					count++;
				}
			}
				
		}
	
	return valList;
}