public static Cell[] FindAllEmpty(Puzzle* puzzle)
{
	Cell[] emptyList = {};
	size = puzzle->getSize();
	int count = 0;
	
		for(int row = 0; row < size; row++)
		{
			for(int col = 0; col < size; col++)
			{
				if(puzzle->getCell(row, col) == 0)
				{
					emptyList[count] = puzzle->getCell(row, col);
					count++;
				}
			}
		}
	
	return emptyList;
}