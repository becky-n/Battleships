#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 7


void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]) {
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

    

}

int TopLeftPosition(int size, int *row, int *col, int map[MAP_SIZE][MAP_SIZE]){
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
}

int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE]){
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
}

void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col) {
    
    static int shot_counter = 1;
   
    int hit=1000;
    // Check if the shot has not been fired
        if (shots[row][col] == 0) {
            // Check if the shot hits a ship on the map
            if (map[row][col] > 0) {
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
            }

}
           


int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE]) {
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
}



void PrintArray(int values[MAP_SIZE][MAP_SIZE]){
    
    int i,j;
    
    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
            printf("%d ",values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void TestCheckGameOver(void)
{
   
int map[MAP_SIZE][MAP_SIZE] = {
  {0, 4, 4, 4, 4, 0, 6},
  {5, 0, 0, 0, 0, 0, 6},
  {5, 0, 0, 0, 0, 0, 6},
  {5, 0, 0, 0, 0, 0, 6},
  {5, 0, 3, 3, 3, 0, 6},
  {5, 0, 0, 0, 0, 0, 6},
  {0, 0, 2, 2, 0, 0, 0}
};
int shots[MAP_SIZE][MAP_SIZE] = {
  {36, 4033, 4029, 4009, 4043, 19, 1013},
  {5023, 8, 11, 5, 25, 12, 1002},
  {5017, 10, 26, 41, 47, 40, 1035},
  {5031, 44, 1, 6, 30, 27, 1021},
  {5020, 3, 3028, 3022, 3038, 45, 0},
  {5015, 46, 24, 18, 32, 34, 1014},
  {4, 0, 2037, 2007, 39, 42, 16}
};
printf("Game over? %d\n", CheckGameOver(shots, map));
} 





int main(void)
{
    TestCheckGameOver();
	return 0;
}
