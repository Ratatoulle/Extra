#include "raylib.h"
#include "raymath.h"
#include <math.h>
#define WIDTH 1920
#define HEIGHT 1020
#define LINELENGTH 500
#define SYMORDER 10
int SymIteration = 0;
#define COMPRESSION 1.8

typedef struct Line
{
	Vector2 start;
	Vector2 end;
	float length;
}line;

void drawTree(line Branch, int SymOrder, int Dir);
void rotatedBranch(line Branch, int SymOrder, int Dir, float Offset, float x, float y);
void initTree(line* Tree);
void rectangularBranches(line Branch, int SymOrder, int Dir, float Offset, float x, float y);

int main()
{
	line Tree;
	InitWindow(WIDTH, HEIGHT, "Fractal's wood");
	static int FPS = 10;
	while (!WindowShouldClose())
	{
		SetTargetFPS(FPS);
		if (SymIteration > SYMORDER)
			SymIteration = 0;
		++SymIteration;
		BeginDrawing();
		if (IsKeyDown(KEY_UP) && FPS < 60)
			FPS++;
		else if (IsKeyDown(KEY_DOWN) && FPS > 5)
			FPS--;
		ClearBackground(WHITE);
		initTree(&Tree);
		drawTree(Tree, 1, 1);
		DrawText(TextFormat("FPS: %i", FPS), 10, 10, 25, BLACK);
		DrawText("Press Up/Down to change rendering speed", 20, 30, 25, BLACK);
		EndDrawing();
	}
}
void rotatedBranch(line Branch, int SymOrder, int Dir, float Offset, float x, float y)
{
	DrawLineEx(Branch.start, Branch.end, 3.0f, BLACK);
	Branch.length /= COMPRESSION;
	Offset = Branch.length / sqrt(2);
	x += Offset;
	y -= Offset;
	Branch.start.x = Branch.end.x;
	Branch.start.y = Branch.end.y;
	Branch.end.x = x;
	Branch.end.y = y;
	drawTree(Branch, SymOrder + 1, 1);
	x -= 2 * Offset;
	Branch.end.x = x;
	drawTree(Branch, SymOrder + 1, -1);
}
void initTree(line* Tree)
{
	Tree->start.x = (float)WIDTH / 2;
	Tree->start.y = (float)HEIGHT;
	Tree->end.y = (float)HEIGHT - LINELENGTH;
	Tree->end.x = (float)WIDTH / 2;
	Tree->length = LINELENGTH;
}
void drawTree(line Branch, int SymOrder, int Dir)
{
	float Offset = 0;
	float x = Branch.end.x;
	float y = Branch.end.y;
	if (SymOrder == SymIteration)
		return;
	else if (SymOrder % 2)
		rotatedBranch(Branch, SymOrder, Dir, Offset, x, y);
	else if (SymOrder % 2 == 0 && SymOrder != 0)
		rectangularBranches(Branch, SymOrder, Dir, Offset, x, y);
}
void rectangularBranches(line Branch, int SymOrder, int Dir, float Offset, float x, float y)
{
	DrawLineEx(Branch.start, Branch.end, 3.0f, BLACK);
	Branch.length /= COMPRESSION;
	Branch.start.x = Branch.end.x;
	Branch.start.y = Branch.end.y;
	Branch.end.x += Dir * Branch.length;
	drawTree(Branch, SymOrder + 1, 1);
	Branch.end.x -= Dir * Branch.length;
	Branch.end.y -= Branch.length;
	drawTree(Branch, SymOrder + 1, 1);
}