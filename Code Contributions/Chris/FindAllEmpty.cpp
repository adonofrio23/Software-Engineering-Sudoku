public static Cell[] FindAllEmpty(Puzzle* puzzle)
{
	Cell[] emptyList = {};
	size = puzzle->GetSize();
	int count = 0;
	
		for(int row = 0; row < size; row++)
		{
			for(int col = 0; col < size; col++)
			{
				if(puzzle->GetCell(row, col).GetValue() == 0)
				{
					emptyList[count] = puzzle->GetCell(row, col);
					count++;
				}
			}
		}
	
	return emptyList;
}
