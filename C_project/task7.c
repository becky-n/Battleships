#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 7

int TopLeftPosition(int size, int *row, int *col, int map[MAP_SIZE][MAP_SIZE]){
    int i,j;
    // 1 is horiz
    // 2 is vert
    
    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
            if(map[i][j]==size){
                *row=i;
                *col=j;

                if(map[i+1][j]==size){
                    return 2;
                }else{
                    return 1;
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
    if(direction == 1){
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

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]){
    int i,j;
    
    int rand_num=rand()%2+1;

    // vertical position
    if(rand_num==2){
        int rand_pos_y=rand()%MAP_SIZE;
        int rand_pos_x = rand() % (MAP_SIZE-size+1);
        for(i=0;i<size;i++){
                if(map[i+rand_pos_x][rand_pos_y]==0){   
                 map[i+rand_pos_x][rand_pos_y]=size;
                }
        }
    // horizontal position
    }else if (rand_num==1){
        int rand_pos_x=rand()%MAP_SIZE;
        int rand_pos_y = rand() % (MAP_SIZE-size+1);
        for(j=0;j<size;j++){
            if(map[rand_pos_x][j+rand_pos_y]==0){
                    map[rand_pos_x][j+rand_pos_y]=size;
                }        
        }
    } 

}


void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE])
{
    int check;
    int arraycheck[4];
    int number; 

    while (1) {
        check = 0;
        for (int i = 0; i < 4; i++) {
            arraycheck[i] = 0;
        }

        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                map[i][j] = 0; 
            }
        }

        for (int i = 2; i < 6; i++) {
        AddRandomShip(i, map); 
        }

        for (int i = 2; i < 6; i++) {
            number = IsShipValid(i, map);
            arraycheck[i-2] = number;
        }
        for (int i = 0; i < 4; i++){
            if (arraycheck[i] == 1) {
                check++;
            }
        } 

        if (check == 4){
            break;
        }

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

void TestInitialiseRandomMap(void)
{
 int map[MAP_SIZE][MAP_SIZE] = {0};
 InitialiseRandomMap(map);
 PrintArray(map);
}




int main(void)
{
    srand(time(NULL));
    TestInitialiseRandomMap();
	return 0;
}
