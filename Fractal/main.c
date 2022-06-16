#include "raylib.h"
#include "raymath.h"
#include <math.h>
#define WIDTH 1920
#define HEIGHT 1020
#define LINELENGTH 500
#define SYMORDER 10
#define COMPRESSION 1.8

int symIteration = 0;

typedef struct Line
{
	Vector2 start;
	Vector2 end;
	float length;
}line;

void drawTree(line, int, int);
void rotateBranch(line, int, int, float, float, float);
void initTree(line*);
void rectangularBranches(line, int, int, float, float, float);

int main()
{
	line tree;
	InitWindow(WIDTH, HEIGHT, "Fractal wood");
	static int FPS = 10;
	while (!WindowShouldClose())
	{
		SetTargetFPS(FPS);
		if (symIteration > SYMORDER)
			symIteration = 0;
		++symIteration;
		BeginDrawing();
		ClearBackground(GREEN);
		initTree(&tree);
		drawTree(tree, 1, 1);
		EndDrawing();
	}
}
void rotateBranch(line branch, int symOrder, int dir, float offset, float x, float y)
{
	DrawLineEx(branch.start, branch.end, 3.0f, BLACK);
	branch.length /= COMPRESSION;
	offset = branch.length / sqrt(2);
	x += offset;
	y -= offset;
	branch.start.x = branch.end.x;
	branch.start.y = branch.end.y;
	branch.end.x = x;
	branch.end.y = y;
	drawTree(branch, symOrder + 1, 1);
	x -= 2 * offset;
	branch.end.x = x;
	drawTree(branch, symOrder + 1, -1);
}
void initTree(line* tree)
{
	tree->start.x = (float)WIDTH / 2;
	tree->start.y = (float)HEIGHT;
	tree->end.y = (float)HEIGHT - LINELENGTH;
	tree->end.x = (float)WIDTH / 2;
	tree->length = LINELENGTH;
}
void drawTree(line branch, int symOrder, int Dir)
{
	float Offset = 0;
	float x = branch.end.x;
	float y = branch.end.y;
	if (symOrder == symIteration)
		return;
	else if (symOrder % 2)
		rotateBranch(branch, symOrder, Dir, Offset, x, y);
	else if (symOrder % 2 == 0 && symOrder != 0)
		rectangularBranches(branch, symOrder, Dir, Offset, x, y);
}
void rectangularBranches(line branch, int symOrder, int dir, float offset, float x, float y)
{
	DrawLineEx(branch.start, branch.end, 3.0f, BLACK);
	branch.length /= COMPRESSION;
	branch.start.x = branch.end.x;
	branch.start.y = branch.end.y;
	branch.end.x += dir * branch.length;
	drawTree(branch, symOrder + 1, 1);
	branch.end.x -= dir * branch.length;
	branch.end.y -= branch.length;
	drawTree(branch, symOrder + 1, 1);
}