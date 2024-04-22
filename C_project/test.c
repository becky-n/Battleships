/* ENGGEN131 C Project 2023 - Battleships */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAP_SIZE 6
#define HIT 1000

// Prototype declarations of required functions
void PrintArray(int values[MAP_SIZE][MAP_SIZE]);
void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]);
void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]);
int CountValues(int value, int map[MAP_SIZE][MAP_SIZE]);
int TopLeftPosition(int size, int *row, int *col, int map[MAP_SIZE][MAP_SIZE]);
int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE]);
void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]);
void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col);
int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE]);


/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the required functions should go below
*******************************************************************************
*******************************************************************************
******************************************************************************/

void PrintArray(int values[MAP_SIZE][MAP_SIZE])
{   
    int i,j;
    
    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
            printf("%d ",values[i][j]);
        }
        printf("\n");
    }
    printf("\n");

	values[0][0] = 0; // to prevent compiler warning (you must complete this function)
}

void InitialiseMap(int map[MAP_SIZE][MAP_SIZE])
{
	int i,j;

    for(i=0;i<2;i++){
        for(j=0;j<1;j++){
            map[i][j]=2;
        }
    }

    for(i=0;i<1;i++){
        for(j=0;j<3;j++){
            map[i+2][j+1]=3;
        }
    }

    for(i=0;i<5;i++){
        for(j=0;j<1;j++){
            map[MAP_SIZE-5+i][MAP_SIZE-1+j]=5;
        }
    }

    for(i=0;i<1;i++){
        for(j=0;j<4;j++){
            map[MAP_SIZE+i-1][j]=4;
        }
    }
	map[0][0] = 0; // to prevent compiler warning (you must complete this function)
}

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE])
{
	int i,j;
    
    int rand_num=rand()%2+1;

    // vertical position
    if(rand_num==1){
        int rand_pos_y=rand()%MAP_SIZE;
        int rand_pos_x = rand() % (MAP_SIZE-size);
        for(i=0;i<size;i++){
                if(map[i+rand_pos_x][rand_pos_y]==0){   
                 map[i+rand_pos_x][rand_pos_y]=size;
                }
        }
    // horizontal position
    }else if (rand_num==2){
        int rand_pos_x=rand()%MAP_SIZE;
        int rand_pos_y = rand() % (MAP_SIZE-size);
        for(j=0;j<size;j++){
            if(map[rand_pos_x][j+rand_pos_y]==0){
                    map[rand_pos_x][j+rand_pos_y]=size;
                }        
        }
    } 
	map[0][0] = size; // to prevent compiler warning (you must complete this function)
}

int CountValues(int value, int map[MAP_SIZE][MAP_SIZE])
{
	int i,j;
    int count=0;

    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
            if (map[i][j]==value){
                count+=1;                               
            }           
        }
    }
    return count;
	return map[0][0] + value; // to prevent compiler warning (you must complete this function)
}

int TopLeftPosition(int size, int *row, int *col, int map[MAP_SIZE][MAP_SIZE])
{
	int i,j;
    // 1 is vert
    // 2 is horiz
    
    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
            if(map[i][j]==size){
                *row=i;
                *col=j;

                if(map[i+1][j]==size){
                    return 1;
                }else{
                    return 2;
                }
            }          
        }
    }
    return 0;
	return map[0][0] + size + *row + *col; // to prevent compiler warning (you must complete this function)
}

int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE])
{
	 int i, j, row, col, direction;

    direction = TopLeftPosition(size, &row, &col, map);

    // horizontal
    if(direction == 2){
        for(i = col; i < col + size; i++){
            if(row - 1 >= 0 && map[row - 1][i] != 0){
                return 0;
            }
            if(row + 1 < MAP_SIZE && map[row + 1][i] != 0){
                return 0;
            }
            if(map[row][col+size]!=0 && col+size<MAP_SIZE){
                return 0;
            }
            
            if(map[row][col-1]!=0 && col-1>=0){
                return 0;
            }
        }
    }
    // vertical
    else {
        for(j = row; j < row + size; j++){
            if(col - 1 >= 0 && map[j][col - 1] != 0){
                return 0;
            }
            if(col + 1 < MAP_SIZE && map[j][col + 1] != 0){
                return 0;
            }
            
            if(map[row+size][col]!=0 && row+size<MAP_SIZE){
                return 0;
            }
            
            if(map[row-1][col]!=0 && row-1>=0){
                return 0;
            }
            
        }
    }
    return 1;
	return map[0][0] + size; // to prevent compiler warning (you must complete this function)
}

void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE])
{
	AddRandomShip(2, map);
    AddRandomShip(3, map);
    AddRandomShip(4, map);
    AddRandomShip(5, map);

    // Check if any ship is not valid, reset the map and add ships again
    while (!IsShipValid(2, map) || !IsShipValid(3, map) || !IsShipValid(4, map) || !IsShipValid(5, map)) {
        // Reset the map by iterating through and setting each element to 0
        for (int i = 0; i < MAP_SIZE; ++i) {
            for (int j = 0; j < MAP_SIZE; ++j) {
                map[i][j] = 0;
            }
        }
        // Add ships again
        AddRandomShip(2, map);
        AddRandomShip(3, map);
        AddRandomShip(4, map);
        AddRandomShip(5, map);
    }
	map[0][0] = 0; // to prevent compiler warning (you must complete this function)
}

void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col)
{
	static int shot_counter = 1;
   
    int hit=1000;
    // Check if the shot has not been fired
        if (shots[row][col] == 0) {
            // Check if the shot hits a ship on the map
            if (map[row][col] != 0) {
                // Update the shot array and add bonus score when a ship is hit
                shots[row][col] =  hit + shot_counter;

                // Check if the entire ship is destroyed
                int size = map[row][col];
                int ship_destroyed = 1;
                for (int i = 0; i < MAP_SIZE; i++) {
                    for (int j = 0; j < MAP_SIZE; j++) {
                        if (map[i][j] == size && shots[i][j] == 0) {
                            // There is still a part of the ship remaining
                            ship_destroyed = 0;
                            break;
                        }
                    }
                    if (!ship_destroyed) {
                        break;
                    }
                }

                if (ship_destroyed) {
                    shots[row][col] = shot_counter+hit;
                    // Update the shots array for the destroyed ship
                    for (int i = 0; i < MAP_SIZE; i++) {
                        for (int j = 0; j < MAP_SIZE; j++) {
                            if (map[i][j] == size) {
                                shots[i][j] += (size-1) * hit;
                            }
                        }
                    }
                }
            } else {
                shots[row][col] = shot_counter;
            }
             shot_counter++;
			 return;
            }
	shots[0][0] = map[0][0] + row + col; // to prevent compiler warning (you must complete this function)
}

int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE])
{
	 int i, j;

    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] != 0 && shots[i][j] == 0) {
                return 0;
            }
        }
    }

    // All ships have been destroyed
    return 1;
	return shots[0][0] + map[0][0]; // to prevent compiler warning (you must complete this function)
}

/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the required functions should go above
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Provided functions needed for playing the Battleships game:

// First, prototype declarations for the bots:
void GetMoveBot1(int shots[MAP_SIZE][MAP_SIZE], int *row, int *col);
void GetMoveBot2(int shots[MAP_SIZE][MAP_SIZE], int *row, int *col);

// Gets the input for one move from the human player (an alphabetic row and a numeric column)
// This function converts both inputs to numeric values
void GetMoveHuman(int *row, int *col, int player)
{
	char a = ' ';
	int b = -1;
	printf("Player %d: enter move [row/col]: ", player);
	while (!(a >= 'A' && a <= 'Z')) {
		scanf("%c", &a);
	}
	while (!(b >= 0 && b <= 25)) {
		scanf("%d", &b);
	}
	*row = (int)(a - 'A');
	*col = b;
}

// Takes two "shots" arrays as input (which are the visible parts of the game shown to players) and formats them into a string for printing
// The player currently to move is highlighted
void GetDisplayMapString(int shots1[MAP_SIZE][MAP_SIZE], int shots2[MAP_SIZE][MAP_SIZE], int player, char *boardString)
{
	int i, j;
	char numbers[10];
	// Intialise board string to be empty:
	boardString[0] = '\0';
	strcat(boardString, "  ");

	for (i = 0; i < MAP_SIZE; i++) {
		sprintf(numbers, "%d", i%10);
		strcat(boardString, numbers);
	}
	strcat(boardString, "|");
	for (i = 0; i < MAP_SIZE; i++) {
		sprintf(numbers, "%d", i%10);
		strcat(boardString, numbers);
	}
	strcat(boardString, "\n  ");

	for (i = 0; i < MAP_SIZE; i++) {
		strcat(boardString, "-");
	}
	strcat(boardString, "|");
	for (i = 0; i < MAP_SIZE; i++) {
		strcat(boardString, "-");
	}
	strcat(boardString, "\n");

	for (i = 0; i < MAP_SIZE; i++) {
		int len = strlen(boardString);
		boardString[len] = (char)('A' + i);
		boardString[len+1] = '\0';
		strcat(boardString, "|");
		for (j = 0; j < MAP_SIZE; j++) {
			if (shots1[i][j] / HIT > 0) {
				if (shots1[i][j] / HIT == 1) {
					strcat(boardString, "X");
				} else {
					sprintf(numbers, "%d", shots1[i][j] / HIT);
					strcat(boardString, numbers);
				}
			} else if (shots1[i][j] > 0) {
				strcat(boardString, ".");
			} else {
				strcat(boardString, " ");
			}
		}
		strcat(boardString, "|");
		for (j = 0; j < MAP_SIZE; j++) {
			if (shots2[i][j] / HIT > 0) {
				if (shots2[i][j] / HIT == 1) {
					strcat(boardString, "X");
				} else {
					sprintf(numbers, "%d", shots2[i][j] / HIT);
					strcat(boardString, numbers);
				}
			} else if (shots2[i][j] > 0) {
				strcat(boardString, ".");
			} else {
				strcat(boardString, " ");
			}
		}
		strcat(boardString, "|");
		len = strlen(boardString);
		boardString[len] = (char)('A' + i);
		boardString[len+1] = '\0';
		strcat(boardString, "\n");
	}
	if (player == 1) {
		strcat(boardString, "  P1");
		for (i = 0; i < MAP_SIZE-2; i++) {
			strcat(boardString, "*");
		}
	} else {
		for (i = 0; i < MAP_SIZE; i++) {
			strcat(boardString, " ");
		}
		strcat(boardString, "   P2");
		for (i = 0; i < MAP_SIZE-2; i++) {
			strcat(boardString, "*");
		}
	}
	strcat(boardString, "\n");
}

// Plays one game of Battleships, beginning with the specified starting player
// Game type = 1 (human vs human) or 2 (human vs bot) or 3 (bot vs bot)
int PlayOneGame(int startingPlayer, int gameType)
{
	int row, col, player, gameOver;

	// String to display the boards
	char displayBoardString[(2*MAP_SIZE+5)*(MAP_SIZE+5)];

	// The maps containing the locations of the ships
	int mapPlayer1[MAP_SIZE][MAP_SIZE] = {0};
	int mapPlayer2[MAP_SIZE][MAP_SIZE] = {0};

	// The locations of the shots
	int shotsPlayer1[MAP_SIZE][MAP_SIZE] = {0};
	int shotsPlayer2[MAP_SIZE][MAP_SIZE] = {0};

	player = startingPlayer;
	gameOver = 0;

	// Create random maps for each player
	InitialiseRandomMap(mapPlayer1);
	InitialiseRandomMap(mapPlayer2);

	// Display the board if a human is playing
	if (gameType != 3) {
		GetDisplayMapString(shotsPlayer1, shotsPlayer2, player, displayBoardString);
		printf("%s", displayBoardString);
	}

	// Process one move for the current player
	while (!gameOver) {
		if (gameType == 1) {
			GetMoveHuman(&row, &col, player);
			if (player == 1) {
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			} else {
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		} else if (gameType == 2) {
			if (player == 1) {
				GetMoveHuman(&row, &col, player);
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			} else {
				GetMoveBot1(shotsPlayer2, &row, &col);
				printf("Player 2 (bot) moves: %c%d\n", (char)(row+'A'), col);
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		} else {
			if (player == 1) {
				GetMoveBot1(shotsPlayer1, &row, &col);
				FireShot(shotsPlayer1, mapPlayer2, row, col);
				gameOver = CheckGameOver(shotsPlayer1, mapPlayer2);
			} else {
				GetMoveBot2(shotsPlayer2, &row, &col);
				FireShot(shotsPlayer2, mapPlayer1, row, col);
				gameOver = CheckGameOver(shotsPlayer2, mapPlayer1);
			}
		}

		// Swap players
		if (!gameOver) {
			player = 3 - player;
		}
		if (gameType != 3) {
			GetDisplayMapString(shotsPlayer1, shotsPlayer2, player, displayBoardString);
			printf("%s", displayBoardString);
		}
	}
	return player;
}

// Play a Battleships tournament
// If the tournament is between a human and a bot, only one game is played
// If the tournament is between two bots, the number of games is requested
void PlayBattleships(void)
{
	int gameType, numberOfGames, result;
	int i, wins1, wins2, player;

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;

	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	// Set win counts to zero
	wins1 = 0;
	wins2 = 0;

	// Player 1 will always start the first game
	// If a tournament is played (between two bots), the starting player alternates
	player = 1;

	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, gameType);
		if (result == 1) {
			wins1++;
		} else {
			wins2++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}

	// Show the outcome (of a single game or tournament)
	if (numberOfGames == 1) {
		printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
	} else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d\n\n", numberOfGames, wins1, wins2);
	}
}

// The main function for the Battleships program
int main(void)
{
	// Initialise the seed for the random number generator
	srand((unsigned int)time(NULL));

	printf("ENGGEN131 - C Project 2023\n");
	printf("                          ... presents ...\n");
	printf(" ___    __   _____ _____  _     ____  __   _     _   ___   __  \n");
	printf("| |_)  / /\\   | |   | |  | |   | |_  ( (` | |_| | | | |_) ( (` \n");
	printf("|_|_) /_/--\\  |_|   |_|  |_|__ |_|__ _)_) |_| | |_| |_|   _)_) \n");
	printf("\n                __/___            \n");
	printf("          _____/______|           \n");
	printf("  _______/_____\\_______\\_____     \n");
	printf("  \\              < < <       |    \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n");

	PlayBattleships();

	return 0;
}

/******************************************************************************
*******************************************************************************
*******************************************************************************
// Implementations of the two bots can be provided below
// The existing implementations are naive:
// - Bot 1 simply takes random shots (without checking for repeated shots)
// - Bot 2 also takes random shots (but makes a single test on each turn for a repeated shot)
*******************************************************************************
*******************************************************************************
******************************************************************************/

// Strategy for Bot 1
void GetMoveBot1(int shots[MAP_SIZE][MAP_SIZE], int *row, int *col)
{
	int rand_row;
	int rand_col;

	rand_row = shots[0][0]; // to prevent compiler warning (because otherwise "shots" array is not accessed)
	rand_row = rand() % MAP_SIZE;
	rand_col = rand() % MAP_SIZE;

	*row = rand_row;
	*col = rand_col;
}

// Strategy for Bot 2
void GetMoveBot2(int shots[MAP_SIZE][MAP_SIZE], int *row, int *col)
{
	int rand_row;
	int rand_col;

	rand_row = shots[0][0]; // to prevent compiler warning (because otherwise "shots" array is not accessed)
	rand_row = rand() % MAP_SIZE;
	rand_col = rand() % MAP_SIZE;

	// If the shot has been tried before, try one more time
	if (shots[rand_row][rand_col] > 0) {
		rand_row = rand() % MAP_SIZE;
		rand_col = rand() % MAP_SIZE;
	}

	*row = rand_row;
	*col = rand_col;
}













