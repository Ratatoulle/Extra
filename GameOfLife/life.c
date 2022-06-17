#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "life.h"


size_t Randomize(int min, int max)
{
	return min + rand() % (max - min);
}

void InitWorld(point world[WORLD_WIDTH][WORLD_HEIGHT])
{
	srand(time(NULL));
	for (int i = 1; i < WORLD_WIDTH; i++)
	{
		for (int j = 1; j < WORLD_HEIGHT; j++)
		{
			int random = Randomize(0, 1001);
			if (random % 2 == 0)
				world[i][j].isLive = 0;
			else
			{
				world[i][j].isLive = 1;
			}
		}
	}
}
void PrintWorld(point world[WORLD_WIDTH][WORLD_HEIGHT])
{
	for (int i = 1; i < WORLD_WIDTH; i++)
	{
		printf("\n");
		for (int j = 1; j < WORLD_HEIGHT; j++)
		{
			if (world[i][j].isLive == 1)
			{
				printf(" * ");
			}
			else {
				printf(" ");
			}
		}
	}
	printf("\n---------------------------------------------\n");
	system("cls");
}
size_t getLiveCount(point world[WORLD_WIDTH][WORLD_HEIGHT])
{
	int count = 0;
	for (int i = 1; i < WORLD_WIDTH; i++)
	{
		for (int j = 1; j < WORLD_HEIGHT; j++)
		{
			if (world[i][j].isLive == 1)
			{
				count++;
			}
		}
	}
	return count;
}
void ReadPointNeighbors(signed int neighbors[][2], size_t x, size_t y)
{
	int k = 0;
	for (size_t i = x - 1; i <= x + 1; i++)
	{
		for (size_t j = y - 1; j <= y + 1; j++)
		{
			if (i == x && j == y)
			{
				continue;
			}
			neighbors[k][0] = i;
			neighbors[k][1] = j;
			k++;
		}
	}
}
size_t CountLiveNeighbors(point world[WORLD_WIDTH][WORLD_HEIGHT], size_t x, size_t y)
{
	size_t count = 0;
	signed int neighbors[8][2];
	signed int _x, _y;
	ReadPointNeighbors(neighbors, x, y);
	for (size_t i = 0; i < 8; i++)
	{
		_x = neighbors[i][0];
		_y = neighbors[i][1];
		if (_x < 0 || _y < 0)
		{
			continue;
		}
		if (_x >= WORLD_WIDTH || _y >= WORLD_HEIGHT)
		{
			continue;
		}
		if (world[_x][_y].isLive == 1)
		{
			count++;
		}
	}
	return count;
}

void NextGenerations(point world[WORLD_WIDTH][WORLD_HEIGHT], point prevWorld[WORLD_WIDTH][WORLD_HEIGHT])
{
	size_t aliveNeighbors;
	point p;
	for (size_t i = 0; i < WORLD_WIDTH; i++)
	{
		for (size_t j = 0; j < WORLD_HEIGHT; j++)
		{
			p = prevWorld[i][j];
			aliveNeighbors = CountLiveNeighbors(prevWorld, i, j);
			if (p.isLive == 0)
			{
				if (aliveNeighbors == 3)
				{
					world[i][j].isLive = 1;
				}
			}
			else
			{
				if (aliveNeighbors < 2 || aliveNeighbors > 3)
				{
					world[i][j].isLive = 0;
				}
			}
		}
	}
}


void CopyWorld(point src[WORLD_WIDTH][WORLD_HEIGHT], point dest[WORLD_WIDTH][WORLD_HEIGHT])
{
	for (size_t i = 0; i < WORLD_WIDTH; i++)
	{
		for (size_t j = 0; j < WORLD_HEIGHT; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

int CompareWorlds(point world[WORLD_WIDTH][WORLD_HEIGHT], point prevWorld[WORLD_WIDTH][WORLD_HEIGHT])
{
	for (size_t i = 0; i < WORLD_WIDTH; i++)
	{
		for (size_t j = 0; j < WORLD_HEIGHT; j++)
		{
			if (world[i][j].isLive != prevWorld[i][j].isLive)
			{
				return -1;
			}
		}
	}
	return 1;
}