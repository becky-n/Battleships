#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 6


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

int CountValues(int value, int map[MAP_SIZE][MAP_SIZE]){
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
}



void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col) {
    int shot_counter = 1;

    for(int i=0;i<MAP_SIZE;i++){
        for(int j=0;j<MAP_SIZE;j++){
            if(shots[i][j]!=0)
                shot_counter++;                                                  
        }
    }
    
    int hit=1000;
    // Check if the shot has not been fired
        if (shots[row][col] == 0) {
            shots[row][col]=shot_counter;
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
            }      
            }

}

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]){
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

}


void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]){
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


void TestFireShot(void)
{
int shots[MAP_SIZE][MAP_SIZE] = {0};
int map[MAP_SIZE][MAP_SIZE] = {
  {0, 5, 5, 5, 5, 5},
  {0, 0, 0, 0, 0, 0},
  {4, 4, 4, 4, 0, 0},
  {0, 0, 0, 0, 2, 0},
  {0, 0, 0, 0, 2, 0},
  {3, 3, 3, 0, 0, 0}
};
FireShot(shots, map, 5, 1);
FireShot(shots, map, 1, 1);
FireShot(shots, map, 3, 5);
FireShot(shots, map, 3, 0);
FireShot(shots, map, 0, 0);
FireShot(shots, map, 4, 5);
FireShot(shots, map, 2, 4);
FireShot(shots, map, 2, 0);
FireShot(shots, map, 4, 0);
FireShot(shots, map, 5, 2);

printf("Shots:\n");
PrintArray(shots);

}




int main(void)
{
    srand(time(NULL));
    TestFireShot();
	return 0;
}
