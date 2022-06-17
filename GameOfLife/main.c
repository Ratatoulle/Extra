#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "life.h"

int main(int argc, char const* argv[])
{
	setlocale(0, "ru");
	point world[WORLD_WIDTH][WORLD_HEIGHT];
	point prevWorld[WORLD_WIDTH][WORLD_HEIGHT];
	InitWorld(world);
	int lifePoints = -1;
	int optimal = 0;
	int count = 0;
	int cycledCount = 0;
	do
	{
		PrintWorld(world);
		CopyWorld(world, prevWorld);
		CopyWorld(world, worlds[cycledCount].w);

		NextGenerations(world, prevWorld);
		optimal = CompareWorlds(world, prevWorld);
		for (int i = 0; i < cycledCount; i++)
		{
			if (CompareWorlds(world, worlds[i].w) == 1)
			{
				optimal = 1;
				printf("Циклическая структура\n");
				break;
			}
		}
		lifePoints = getLiveCount(world);

		printf("Живых клеток %d\n", lifePoints);
		if (lifePoints == 0)
		{
			printf("Все клетки мертвы.\n");
		}
		if (cycledCount < NUM_OF_WORLDS)
		{
			cycledCount++;
		}
		else {
			cycledCount = 0;
		}
		count++;
		Sleep(150);
	} while (lifePoints != 0 && optimal < 0);

	if (optimal == 1)
	{
		printf("Устойчивая конфигурация достигнута\nКоличество итераций %d\n", count);
	}

	return 0;
}