#ifndef _LIFE
#define _LIFE


#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20
#define NUM_OF_WORLDS 10

typedef struct point
{
	unsigned int isLive : 1;
}point;

typedef struct cycleWorld
{
	point w[WORLD_WIDTH][WORLD_HEIGHT];
}cycleWorld;

point world[WORLD_WIDTH][WORLD_HEIGHT];
cycleWorld worlds[NUM_OF_WORLDS];


unsigned int Randomize(int min, int max);
void InitWorld(point world[WORLD_WIDTH][WORLD_HEIGHT]);
void PrintWorld(point world[WORLD_WIDTH][WORLD_HEIGHT]);
void ReadPointNeighbors(signed int nb[][2], unsigned int x, unsigned int y); //Получение координат соседей клетки
unsigned int CountLiveNeighbors(point world[WORLD_WIDTH][WORLD_HEIGHT], unsigned int x, unsigned int y); //Сколько живых соседей у клетки (x,y)
void NextGenerations(point world[WORLD_WIDTH][WORLD_HEIGHT], point prevWorld[WORLD_WIDTH][WORLD_HEIGHT]); //Следующее поколение клеток
void CopyWorld(point src[WORLD_WIDTH][WORLD_HEIGHT], point dest[WORLD_WIDTH][WORLD_HEIGHT]); //Копировать мир
int CompareWorlds(point world[WORLD_WIDTH][WORLD_HEIGHT], point prevWorld[WORLD_WIDTH][WORLD_HEIGHT]); //Сравнить миры 


#endif