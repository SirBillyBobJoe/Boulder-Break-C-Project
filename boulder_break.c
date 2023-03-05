/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

// Your function definitions should go here...
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element)
{
	int players = 0, i, j;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'X')
			{
				players++;
			}
		}
	}
	if ((row < CAVE_SIZE) && (row >= 0) && (col < CAVE_SIZE) && (col >= 0)) {
		if ((cave[row][col] == 0))
		{
			if (strcmp(element, "player") == 0)
			{
				if (players == 0)
				{
					cave[row][col] = 'X';
				}
			}
			if (strcmp(element, "hole") == 0)
			{
				cave[row][col] = '*';
			}
			if (strcmp(element, "treasure") == 0)
			{
				cave[row][col] = '+';
			}
			if (strcmp(element, "boulder") == 0)
			{
				cave[row][col] = 'O';
			}
		}
	}
	return;
}
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	int i, j, k = 0;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (layout[k] == '1')
			{
				cave[i][j] = 1;
			}
			if (layout[k] == '0')
			{
				cave[i][j] = 0;
			}
			if (layout[k] == 'E')
			{
				cave[i][j] = 'E';
			}
			k++;
		}
	}
	return;
}
void InitialiseStory(char* story)
{
	story = strcat(story, "Huh ? !? !Where Am I ? !? Why is it so Dark ?\n\
Let me turn the flashlight on my phone.\n\
Oh... I'm in a cave!!!\n\
How did I get here ? ? ? There's no signal.\n\
I NEED TO GET OUT!!!\n\
I see some writing on the wall.\n\
It reads :\n\
\"Hello Brave adventurer, you have been sent\n\
here to collect the treasure and escape the cave.\n\
Beware within the cave lies many dangerous obstacles.\n\
Use the Boulders to help you overcome the obstacles\n\
and collect the treasure before escaping.\n\
Treasure='+',Boulder='O',Hole='*',Wall='#',You are 'X'\"\n");
}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (i == 0 || i == CAVE_SIZE - 1)
			{

				if (cave[i][j] == 0)
				{
					printf("%d ", cave[i][j]);
					return 0;
				}
			}
			else
			{

				if (cave[i][0] == 0 || cave[i][CAVE_SIZE - 1] == 0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j, count = 0;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'E')
			{
				count++;
				if ((i == 0 || i == CAVE_SIZE - 1) && (j == 0 || j == CAVE_SIZE - 1))
				{
					return 0;
				}
				if ((i != 0) && (i != CAVE_SIZE - 1))
				{
					if ((j != 0) && (j != CAVE_SIZE - 1))
					{
						return 0;
					}
				}
			}
		}
	}
	if (count != 1) {
		return 0;
	}
	return 1;
}
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j, count = 0;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'E')
			{
				count++;
			}
		}
	}
	if (count == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	int i, j, PosRow, PosCol;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 'X')
			{
				PosRow = i;
				PosCol = j;

			}
		}
	}
	int n = 2;
	if (move == 's')
	{
		if (cave[PosRow + 1][PosCol] == 0)
		{

			cave[PosRow + 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow + 1][PosCol] == '+')
		{
			cave[PosRow + 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow + 1][PosCol] == 'O')
		{
			while (cave[PosRow + n][PosCol] == 0)
			{
				cave[PosRow + n - 1][PosCol] = 0;
				cave[PosRow + n][PosCol] = 'O';
				n++;
			}
			if (cave[PosRow + n][PosCol] == '*')
			{
				cave[PosRow + n - 1][PosCol] = 0;
				cave[PosRow + n][PosCol] = 0;
			}
			return 0;
		}
		else if (cave[PosRow + 1][PosCol] == 'E')
		{
			cave[PosRow + 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 2;
		}
		else if (cave[PosRow + 1][PosCol] == '*')
		{
			cave[PosRow][PosCol] = 0;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (move == 'a')
	{
		if (cave[PosRow][PosCol - 1] == 0)
		{
			cave[PosRow][PosCol - 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow][PosCol - 1] == '+')
		{
			cave[PosRow][PosCol - 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow][PosCol - 1] == 'O')
		{
			while (cave[PosRow][PosCol - n] == 0)
			{
				cave[PosRow][PosCol - n + 1] = 0;
				cave[PosRow][PosCol - n] = 'O';
				n++;

			}
			if (cave[PosRow][PosCol - n] == '*')
			{
				cave[PosRow][PosCol - n + 1] = 0;
				cave[PosRow][PosCol - n] = 0;
			}
			return 0;
		}
		else if (cave[PosRow][PosCol - 1] == 'E')
		{
			cave[PosRow][PosCol - 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 2;
		}
		else if (cave[PosRow][PosCol - 1] == '*')
		{
			cave[PosRow][PosCol] = 0;
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (move == 'w')
	{
		if (cave[PosRow - 1][PosCol] == 0)
		{
			cave[PosRow - 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow - 1][PosCol] == '+')
		{

			cave[PosRow - 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow - 1][PosCol] == 'O')
		{
			while (cave[PosRow - n][PosCol] == 0)
			{
				cave[PosRow - n + 1][PosCol] = 0;
				cave[PosRow - n][PosCol] = 'O';
				n++;
			}
			if (cave[PosRow - n][PosCol] == '*')
			{
				cave[PosRow - n + 1][PosCol] = 0;
				cave[PosRow - n][PosCol] = 0;
			}
			return 0;
		}
		else if (cave[PosRow - 1][PosCol] == 'E')
		{
			cave[PosRow - 1][PosCol] = 'X';
			cave[PosRow][PosCol] = 0;
			return 2;
		}
		else if (cave[PosRow - 1][PosCol] == '*')
		{
			cave[PosRow][PosCol] = 0;
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (move == 'd')
	{
		if (cave[PosRow][PosCol + 1] == 0)
		{
			cave[PosRow][PosCol + 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow][PosCol + 1] == '+')
		{

			cave[PosRow][PosCol + 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 0;
		}
		else if (cave[PosRow][PosCol + 1] == 'O')
		{
			while (cave[PosRow][PosCol + n] == 0)
			{
				cave[PosRow][PosCol + n - 1] = 0;
				cave[PosRow][PosCol + n] = 'O';
				n++;

			}
			if (cave[PosRow][PosCol + n] == '*')
			{
				cave[PosRow][PosCol + n - 1] = 0;
				cave[PosRow][PosCol + n] = 0;
			}
			return 0;
		}
		else if (cave[PosRow][PosCol + 1] == 'E')
		{
			cave[PosRow][PosCol + 1] = 'X';
			cave[PosRow][PosCol] = 0;
			return 2;
		}
		else if (cave[PosRow][PosCol + 1] == '*')
		{
			cave[PosRow][PosCol] = 0;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	for (i = 0; i < CAVE_SIZE; i++)
	{
		for (j = 0; j < CAVE_SIZE; j++)
		{
			if (cave[i][j] == 1) {
				printf("#");
			}
			if (cave[i][j] == 0) {
				printf(" ");
			}
			if (cave[i][j] == 'E') {
				printf(" ");
			}
			if (cave[i][j] == 'X') {
				printf("X");
			}
			if (cave[i][j] == '*') {
				printf("*");
			}
			if (cave[i][j] == '+') {
				printf("+");
			}
			if (cave[i][j] == 'O') {
				printf("O");
			}
		}
		printf("\n");
	}
	return;
}
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int temp[10000][10000] = { 0 }, i, j;
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			temp[i][j] = cave[j][i];
		}
	}
	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			cave[i][j] = temp[i][CAVE_SIZE - 1 - j];
		}
	}
}




/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 4, "boulder");
	AddItem(cave, 5, 6, "boulder");
	AddItem(cave, 4, 8, "hole");
	AddItem(cave, 1, 4, "treasure");
	AddItem(cave, 4, 5, "player");

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}