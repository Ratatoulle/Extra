#include <stdio.h>
#include <stdlib.h>

int knightMove(int movesRemaining, int currentDigit)
{
	int totalCount = 0;

	if (movesRemaining == 0)
		return 0;
	if (currentDigit == 5)
		return 1;
	if (currentDigit == 0)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 6);
		totalCount += knightMove(movesRemaining - 1, 4);
	}
	if (currentDigit == 1)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 6);
		totalCount += knightMove(movesRemaining - 1, 8);
	}
	if (currentDigit == 2)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 7);
		totalCount += knightMove(movesRemaining - 1, 9);
	}
	if (currentDigit == 3)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 4);
		totalCount += knightMove(movesRemaining - 1, 8);
	}
	if (currentDigit == 4)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 3);
		totalCount += knightMove(movesRemaining - 1, 9);
		totalCount += knightMove(movesRemaining - 1, 0);
	}
	if (currentDigit == 6)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 1);
		totalCount += knightMove(movesRemaining - 1, 7);
		totalCount += knightMove(movesRemaining - 1, 0);
	}
	if (currentDigit == 7)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 2);
		totalCount += knightMove(movesRemaining - 1, 6);
	}
	if (currentDigit == 8)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 1);
		totalCount += knightMove(movesRemaining - 1, 3);
	}
	if (currentDigit == 9)
	{
		totalCount++;
		totalCount += knightMove(movesRemaining - 1, 2);
		totalCount += knightMove(movesRemaining - 1, 4);
	}
	return totalCount;
}

int totalCount(int n)
{
	int count = 0;
	count += knightMove(n, 0);
	count += knightMove(n, 1);
	count += knightMove(n, 2);
	count += knightMove(n, 3);
	count += knightMove(n, 4);
	count += knightMove(n, 5);
	count += knightMove(n, 6);
	count += knightMove(n, 7);
	count += knightMove(n, 9);
	return count;
}

int main()
{
	int n = 0;
	printf("Enter the number of digits:\n");
	scanf_s("%d", &n);

	int numbers = totalCount(n);
	printf("Total numbers = %d\n", numbers);

}