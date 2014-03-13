#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char element1_square[16] = { '*', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char element2_line[16] = { '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ' };
char element3_G[16] = { '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char element4_G2[16] = { ' ', '*', '*', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char element5_hui[16] = { '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ' };
char element6_hui2[16] = { ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ' };
char element7_triangle[16] = { ' ', '*', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

COORD pos_cl = { 37, 9 };


/*
HideCursor function
*/
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int getRandomElement(char *ElementBuff)
{
	int RandomElement = 0;
	int i, j;
	srand(time(NULL));
	RandomElement = 1 + rand() % 7;
	//RandomElement = 2;
	switch (RandomElement)
	{
		case 1:
			for (i = 0; i < 16; i++) ElementBuff[i] = element1_square[i];
			break;
		case 2:
			for (i = 0; i < 16; i++) ElementBuff[i] = element2_line[i];
			break;
		case 3:
			for (i = 0; i < 16; i++) ElementBuff[i] = element3_G[i];
			break;
		case 4:
			for (i = 0; i < 16; i++) ElementBuff[i] = element4_G2[i];
			break;
		case 5:
			for (i = 0; i < 16; i++) ElementBuff[i] = element5_hui[i];
			break;
		case 6:
			for (i = 0; i < 16; i++) ElementBuff[i] = element6_hui2[i];
			break;
		case 7:
			for (i = 0; i < 16; i++) ElementBuff[i] = element7_triangle[i];
			break;
	}
	return RandomElement;
}

int RotateElement(char *element, int CurrentPartnumber, int *pos_part_left, int *pos_part_right, int NumberOfRotations, int pos_newPartX, int arraySizeX, int *pos_part_down)
{
	int i, j;
	int k = 0;
	int rotate = 0;
	char RotatedElement[16];
	int passed = 0;

pass:
	switch (CurrentPartnumber)
	{
		case 1:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
				*pos_part_down = 0;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			break;
		case 2:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 0;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 3;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 0;
				*pos_part_right = 3;
			}
			break;
		case 3:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 2;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 1;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			break;
		case 4:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 2;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 1;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			break;
		case 5:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 2;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 1;
				*pos_part_right = 3;
			}
			break;
		case 6:
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 2;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 1;
				*pos_part_right = 3;
			}
			break;
		case 7: //triangle
			if (NumberOfRotations == 0)
			{
				*pos_part_left = 0;
				*pos_part_right = 2;
			}
			if (NumberOfRotations == 1)
			{
				*pos_part_left = 0;
				*pos_part_right = 1;
			}
			if (NumberOfRotations == 2)
			{
				*pos_part_left = 1;
				*pos_part_right = 3;
			}
			if (NumberOfRotations == 3)
			{
				*pos_part_left = 2;
				*pos_part_right = 3;
			}
			break;
	}
	if (passed == 1) return 0;
	passed = 1;

 	if (pos_newPartX + *pos_part_right < arraySizeX - 2)
	{
		rotate = 1;
	}

	if (rotate == 1)
	{
		for (i = 3; i >= 0; i--)  // stylb
		{
			for (j = 0; j < 4; j++) //red
			{
				RotatedElement[k++] = element[j * 4 + i];
			}
		}

		for (i = 0; i < 16; i++)
		{
			element[i] = RotatedElement[i];
		}
	}
	if (rotate == 0)
	{
 		if (NumberOfRotations == 0) NumberOfRotations = 3;
		else NumberOfRotations--;
		goto pass;
		//revert coordinates
	}
	return 0;
}


int main()
{
	int Dead = 0;
	char *arr;
	int isHit = 0;
	int Current_position_down = 0;
	int Key;
	int pos_part_left = 0;
	int pos_part_down = 0;
	int pos_part_right = 0;
	int Score = 0;
	int CurrentPartnumber = 0;
	int checkElementNumber = 0;
	//int PartDir;
	int i, j, k;
	int FrameKounter = 0;
	int Speed;
	int isPause = 0;
	int isSpace = 0;
	int CurrentElemCoordinates[8] = {2, 2, 2, 2, 2, 2, 2, 2};
	int NewPieceBuff[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int YourChoice = 0;
	int arraySizeX = 26;
	int arraySizeY = 24;
	int scoreIncrease = 0;
	int NumberOfRotations = 0;
	int MoveDoubleleft = 1;
	int PieceIsDown = 1;
	int LineToDelete = 0;
	int RandElement = 0;
	char bla[255];
	int hui = 0;
	int initialPosX = 0;
	int initialPosY = 0;
	COORD pos = { 0, 0 };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_newPart = { arraySizeX/2, 0 };
	HANDLE output_newPart = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_newPart_image = { arraySizeX + 4, 3 };
	HANDLE output_newPart_image = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_clear = { 0, 0 };
	HANDLE output_clear = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_score = { arraySizeX + 4, 6 };
	HANDLE output_score = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos_clearPart = { 0, 0 };
	COORD pos_margins = { arraySizeX + 4, 17 };
	COORD pos_margins2 = { arraySizeX + 4, 18 };
	COORD pos_margins3 = { arraySizeX + 4, 19 };
	HANDLE output_margins = GetStdHandle(STD_OUTPUT_HANDLE);
	char element[16];
	char ElementBuff[16];
	
	/*
	7 types of blocks:

	...........*...........**.........**..............................
	....**.....*............**.......**........*.......*........*.....
	....**.....*...............................*.......*.......***....
	...........*..............................**.......**.............
	all of them are constructed with 4 pieces.
	*/

	arr = malloc(arraySizeX * arraySizeY * sizeof(char));
	if (arr == NULL)
	{
		printf("cannot allocate memory\n"); _getch();
	}

	hidecursor();
	while (1)
	{ // new game cycle
		Dead = 0;
		Score = 0;
		FrameKounter++;
		k = 0;
		isSpace = 0;
		PieceIsDown = 1;
		srand(time(NULL));
		while (1)
		{
			system("cls");
			printf("During the game- press ESC to exit.. or DIE !\nSpeed level: (1-30)\n");
			fflush(stdin);
			scanf("%d", &Speed);
			if (Speed > 30) Speed = 30;
			if (!(Speed <= 0)) break; /* challenging levels up to speed = 30*/
		}

		/* Create the frame arraySizeX * arraySizeY - BORDERS*/
		for (i = 0; i < arraySizeX * arraySizeY; i++)
		{
			arr[i] = ' ';
			if (i % arraySizeX == 0) { arr[i] = '|'; }
			if (i % arraySizeX == (arraySizeX-1)) arr[i] = '|';
			if (i > arraySizeX * (arraySizeY - 1)) arr[i] = '-';
		}

		pos_part_left = 0;
		pos_part_right = 0;
		checkElementNumber = getRandomElement(ElementBuff);
		system("cls");
		SetConsoleCursorPosition(output_score, pos_score);
		printf("Score: %d", Score);
		CurrentPartnumber = checkElementNumber;
		
		while (1)
		{		/*
				element1_square[16] =
				element2_line[16] = {
				element3_G[16] = { '*
				element4_G2[16] = { '
				element5_hui[16] = { 
				element6_hui2[16] = {
				element7_triangle[16]
				
				*/
			k = 0;
			switch (CurrentPartnumber)
			{
				case 1:
					Current_position_down = 1;
					break;
				case 2:
					Current_position_down = 3;
					break;
				case 3:
					Current_position_down = 1;
					break;
				case 4:
					Current_position_down = 1;
					break;
				case 5:
					Current_position_down = 2;
					break;
				case 6:
					Current_position_down = 2;
					break;
				case 7:
					Current_position_down = 1;
					break;
			}
			SetConsoleCursorPosition(output_margins, pos_margins);
			printf("left: %d, right: %d", pos_part_left, pos_part_right);
			/* uncomment the following ~20 lines to improve flickering for higher speed games*/

			/* clear previous element */
			/*			for (i = 0; i < 8;)
			{
				pos_clearPart.X = CurrentElemCoordinates[i++];
				pos_clearPart.Y = CurrentElemCoordinates[i++];
				SetConsoleCursorPosition(output, pos_clearPart);
				printf(" ");
			}
*/
			SetConsoleCursorPosition(output, pos);
			/* print the matrix- skip the empty spaces and set the kursor for the next character */
//			initialPosX = pos.X;
//			initialPosY = pos.Y;
			for (i = 0; i < arraySizeY; i++)
			{
				for (j = 0; j < arraySizeX; j++)
				{
//					if (arr[i * arraySizeX + j] != ' ') 
//					{
						printf("%c", arr[i * arraySizeX + j]);
//						pos.X += 1;
//					}
//					else { pos.X += 1;  SetConsoleCursorPosition(output, pos); }
				}
				printf("\n"); //
//				pos.X = initialPosX;
				pos.Y += 1;
				SetConsoleCursorPosition(output, pos);
			}
			pos.Y = initialPosY;

			pos_newPart_image.Y = 2;
			pos_newPart_image.X = arraySizeX + 3;
			/* Visualize new element on the right */
			SetConsoleCursorPosition(output_newPart_image, pos_newPart_image);

			// print matrix 4 by 4
			if (PieceIsDown)
			{
				CurrentPartnumber = checkElementNumber;
				NumberOfRotations = 0;
				switch (CurrentPartnumber)
				{
				case 1:
					pos_part_left = 0;
					pos_part_right = 1;
					break;
				case 2:
					pos_part_left = 0;
					pos_part_right = 0;
					break;
				case 3:
					pos_part_left = 0;
					pos_part_right = 2;
					break;
				case 4:
					pos_part_left = 0;
					pos_part_right = 2;
					break;
				case 5:
					pos_part_left = 0;
					pos_part_right = 1;
					break;
				case 6:
					pos_part_left = 0;
					pos_part_right = 1;
					break;
				case 7:
					pos_part_left = 0;
					pos_part_right = 2;
					break;
				}
				for (i = 0; i < 16; i++) element[i] = ElementBuff[i];
				checkElementNumber = getRandomElement(ElementBuff);
				PieceIsDown = 0;
				pos_newPart.Y = 0;
				pos_newPart.X = arraySizeX / 2;
			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					printf("%c", ElementBuff[i * 4 + j]);
				}
				printf("\n");
				pos_newPart_image.Y += 1;
				SetConsoleCursorPosition(output_newPart_image, pos_newPart_image);
			}
		
			/* if condition Dead is satisfied -> break */
			
			Key = 0;
			isHit = 0;
			if (GetAsyncKeyState(VK_DOWN) & 0x8000 != 0)
			{
				// down
				if (pos_newPart.Y + 1 < arraySizeY - 4)
				pos_newPart.Y += 1;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000 != 0)
			{
				// left
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (element[i * 4 + j] == '*')
						{
							if ((arr[(pos_newPart.Y + i-1)*arraySizeX + pos_newPart.X + j-1]) == '#')
							{
								isHit = 1;
							}
						}
						if (isHit) break;
					}
				}
				if ((pos_newPart.X + pos_part_left > 1) && isHit ==0)
				{
					pos_newPart.X -= 1;
					MoveDoubleleft = 1;
				}
			}
			if (GetAsyncKeyState(VK_UP) & 0x8001)
			{
				if (MoveDoubleleft)
				{
					// left + UP = double move
					if (pos_newPart.X + pos_part_left > 1)
					{
						pos_newPart.X -= 1;
					}
					//fflush(stdin);
				}
			}
			MoveDoubleleft = 0;
			isHit = 0;
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000 != 0)
			{
				// right
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (element[i * 4 + j] == '*')
						{
							if ((arr[(pos_newPart.Y + i - 1)*arraySizeX + pos_newPart.X + j + 1]) == '#')
							{
								isHit = 1;
							}
						}
						if (isHit) break;
					}
				}

				if ((pos_newPart.X + pos_part_right + 1 < arraySizeX - 1) && isHit == 0)
				{
					pos_newPart.X += 1;
					MoveDoubleleft = 1;
				}
			}
			if (GetAsyncKeyState(VK_UP) & 0x8001)
			{
				if (MoveDoubleleft)
				{
					// right + UP = double move
					if (pos_newPart.X + pos_part_right + 1 < arraySizeX - 1)
						pos_newPart.X += 1;
					//fflush(stdin);
				}
			}
			MoveDoubleleft = 0;
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 != 0)
			{
				// Space
				isSpace = 1;
				NumberOfRotations++;
				if (NumberOfRotations / 4 == 1) 
					NumberOfRotations = 0;
 				RotateElement(element, CurrentPartnumber, &pos_part_left, &pos_part_right, NumberOfRotations, pos_newPart.X, arraySizeX, &pos_part_down);

//				SetConsoleCursorPosition(output_margins, pos_margins2);
//				printf("left: %d, right: %d", pos_part_left, pos_part_right);
//				SetConsoleCursorPosition(output_margins, pos_margins3);
//				printf("cur: %d, check: %d", CurrentPartnumber, checkElementNumber);
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 != 0)
			{
				isPause = 360;
				while (isPause)
				{
					SetConsoleCursorPosition(output_margins, pos_margins2);
					printf("Pause END in: %d sec (Press ESC to continue)  ", isPause);
					Sleep(1000); 
					isPause--;
					if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 != 0) break;
				}
				SetConsoleCursorPosition(output_margins, pos_margins2);
				printf("                                             ", isPause);
			}
			
			fflush(stdin);
			isHit = 0;
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (element[i * 4 + j] == '*')
					{
						CurrentElemCoordinates[k++] = pos_newPart.X + j;
						CurrentElemCoordinates[k++] = pos_newPart.Y + i;
						if (((arr[(pos_newPart.Y + i)*arraySizeX + pos_newPart.X + j]) == '*') || 
							((arr[(pos_newPart.Y + i)*arraySizeX + pos_newPart.X + j]) == '-') || 
							((arr[(pos_newPart.Y + i)*arraySizeX + pos_newPart.X + j]) == '#'))
						{
							isHit = 1;	
						}
					}
					if (isHit) break;
				}
			}
			if (!isHit)
			{
				k = pos_newPart.X;
				SetConsoleCursorPosition(output_newPart, pos_newPart);
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (element[i * 4 + j] == '*') printf("%c", element[i * 4 + j]);
						else
						{
							pos_newPart.X += 1;
							SetConsoleCursorPosition(output_newPart, pos_newPart);
						}
					}
					printf("\n");
					pos_newPart.Y += 1;
					pos_newPart.X = k;
					SetConsoleCursorPosition(output_newPart, pos_newPart);
				}
				/* Check if the element reached the floor (Y) or other '*' in the arr */
				pos_newPart.Y -= 3;
			}
			else // if isHit = 1
			{
				

				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (element[i * 4 + j] == '*')
						{
							arr[(pos_newPart.Y + i - 1)*arraySizeX + pos_newPart.X + j] = '#';
						}
					}
				}

				PieceIsDown = 1;
score:
				scoreIncrease = 0;

				if (pos_newPart.Y < 1) Dead = 1;

				/* check if the line is full with '*'   |**********************| */
				for (i = 0; i < arraySizeY; i++)
				{
					hui = 0;
					for (j = 0; j < arraySizeX; j++)
					{
						if (arr[(i)*arraySizeX + j] == '*' || arr[(i)*arraySizeX + j] == 178 || arr[(i)*arraySizeX + j] == '#')
							hui++;
					}
					if (hui == arraySizeX - 2)
					{
						Score++;
						scoreIncrease = 1; break; // check all the lines.. not just a single line
					}
				}
				LineToDelete = i;
				/* check for full lines, delete them and increase the score */
				if (scoreIncrease)
				{
					for (i = LineToDelete; i >= 0; i--) // i = arraySizeY-2; i >= ....
					{
						for (j = 0; j < arraySizeX; j++)
						{
							if (i == 0)
							{ 
								if (j!=0 && j!= (arraySizeX-1))
									arr[i*arraySizeX + j] = ' '; 
								else
									arr[i*arraySizeX + j] = '|';
								continue; 
							}
							arr[i*arraySizeX + j] = arr[(i - 1)*arraySizeX + j];
						}
					}
					/* do something with arr */
					SetConsoleCursorPosition(output_score, pos_score);
					printf("                        ");
					SetConsoleCursorPosition(output_score, pos_score);
					printf("Score: %d", Score * 100);
					
					goto score;
				}
			}

			/* Put the element in the array, clear the old position - IF the element cannot be moved more */
			Sleep(1000 / Speed);
			if (Dead) break;
		}
	
		if (Dead)
		{
			while (1)
			{
				Sleep(1000);
				system("cls");
				printf("Wanna start a new game?\n1: yes\n2: No\n ");
				scanf("%d", &YourChoice);
				if (YourChoice == 2 || YourChoice == 1) break;
			}
			if (YourChoice == 2) break;
		}
	}
	return 0;
}