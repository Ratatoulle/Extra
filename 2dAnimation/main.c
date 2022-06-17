#include <stdio.h>
#include <Windows.h>

int main()
{

	const char rocket[] =
		"           ^ \n\
          /^\\\n\
          |-|\n\
          |S|\n\
          |P|\n\
          |A|\n\
          |C|\n\
          |E|\n\
         /|X|\\\n\
        / |-| \\\n\
       |  |||  |\n\
        `-\"\"\"-`\n\
	  \/|\\\n\
	 /|||\\\n\
	";

	int jumpControlAtBottom = 0;
	int shifControl = 0;


	for (jumpControlAtBottom = 0; jumpControlAtBottom <	30; ++jumpControlAtBottom)
		printf("\n");
	fputs(rocket, stdout);
	for (shifControl = 0; shifControl < 60; ++shifControl)
	{
		Sleep(100);
		printf("\n");
	}
	return 0;
}