#include <stdio.h>
#include <stdlib.h>

int KnightMoveto(int totalMovesRemaining, int currentdigit)
{
	int totalCountOfNumbers = 0;

	if (totalMovesRemaining == 0)
		return 0;
	if (currentdigit == 5)
		return 1;
	if (currentdigit == 0)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 6);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 4);
	}
	if (currentdigit == 1)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 6);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 8);
	}
	if (currentdigit == 2)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 7);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 9);
	}
	if (currentdigit == 3)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 4);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 8);
	}
	if (currentdigit == 4)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 3);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 9);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 0);
	}
	if (currentdigit == 6)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 1);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 7);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 0);
	}
	if (currentdigit == 7)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 2);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 6);
	}
	if (currentdigit == 8)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 1);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 3);
	}
	if (currentdigit == 9)
	{
		totalCountOfNumbers++;
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 2);
		totalCountOfNumbers += KnightMoveto(totalMovesRemaining - 1, 4);
	}
	return totalCountOfNumbers;
}

int totalCountOfNumbers(int n)
{
	int count = 0;
	count += KnightMoveto(n, 0);
	count += KnightMoveto(n, 1);
	count += KnightMoveto(n, 2);
	count += KnightMoveto(n, 3);
	count += KnightMoveto(n, 4);
	count += KnightMoveto(n, 5);
	count += KnightMoveto(n, 6);
	count += KnightMoveto(n, 7);
	count += KnightMoveto(n, 8);
	count += KnightMoveto(n, 9);
	count += KnightMoveto(n, 10);
	return count;
}

int main()
{
	int n = 0;
	printf("Enter count of digits:\n");
	scanf_s("%d", &n);

	int numbers = totalCountOfNumbers(n);
	printf("total numbers = %d\n", numbers);

}