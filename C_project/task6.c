# include <stdio.h>
#define MAP_SIZE 6



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

int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE])
{
    #define newRow (MAP_SIZE + 2)
    #define newCol (MAP_SIZE + 2)
    int row, col;
    TopLeftPosition(size, &row, &col, map);
    int check = 0; 

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == size)
            check = 1;
        }
    }
    if (check == 0) {
        return(0);
    }


    //const int newRow = MAP_SIZE + 2;
   // const int newCol = MAP_SIZE + 2;

    int newMap[newRow][newCol];

    for (int i = 0; i < newRow; i++) {
    for (int j = 0; j < newCol; j++) {
        newMap[i][j] = 0;
    }
}

    for (int i = 1; i <  newRow - 1; i++) {
        for (int j = 1; j < newCol - 1; j++) {
            newMap[i][j] = map[i-1][j-1]; 
        }
    }



    for (int i = 1; i < newRow - 1; i++) {
        for (int j = 1; j < newCol - 1; j++) {
            if(newMap[i][j] == size) {
                if (!((newMap[i-1][j] == 0 || newMap[i-1][j] == size) &&
                (newMap[i + 1][j] == 0 || newMap[i + 1][j] == size) &&
                (newMap[i][j+1] == 0 || newMap[i][j+1] == size) &&
                (newMap[i][j-1] == 0 || newMap[i][j-1] == size))) {
                return(0);
            }
            }
        }
    }
    return(1);
 

}


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

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]){
    int i,j;
    
    int rand_num=rand()%2+1;

    // vertical position
    if(rand_num==2){
        int rand_pos_y=rand()%MAP_SIZE;
        int rand_pos_x = rand() % (MAP_SIZE-size);
        for(i=0;i<size;i++){
                if(map[i+rand_pos_x][rand_pos_y]==0){   
                 map[i+rand_pos_x][rand_pos_y]=size;
                }
        }
    // horizontal position
    }else if (rand_num==1){
        int rand_pos_x=rand()%MAP_SIZE;
        int rand_pos_y = rand() % (MAP_SIZE-size);
        for(j=0;j<size;j++){
            if(map[rand_pos_x][j+rand_pos_y]==0){
                    map[rand_pos_x][j+rand_pos_y]=size;
                }        
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

void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]){
    AddRandomShip(2, map);
    AddRandomShip(3, map);
    AddRandomShip(4, map);
    AddRandomShip(5, map);

    // Check if any ship is not valid, reset the map and add ships again
    while (!IsShipValid(2, map) || !IsShipValid(3, map) || !IsShipValid(4, map) || !IsShipValid(5, map)) {
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

void TestIsShipValid(void)
{
  int valid, shipSize;
int map[6][6] = {
  {0, 0, 2, 2, 0, 0},
  {0, 0, 3, 0, 0, 0},
  {0, 0, 3, 0, 0, 0},
  {0, 4, 3, 4, 4, 0},
  {0, 5, 5, 5, 5, 5},
  {0, 0, 0, 0, 0, 0}
};
for (shipSize = 2; shipSize <= 5; shipSize++) {
   valid = IsShipValid(shipSize, map);
   printf("Is ship %d valid? %d\n", shipSize, valid);
}
}



int main(void)
{
    TestIsShipValid();


    return 0;
}
