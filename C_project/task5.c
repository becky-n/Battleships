# include <stdio.h>
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


void TestTopLeftPosition(void)
{
    int row, col, direction;
int map[MAP_SIZE][MAP_SIZE] = {
  {0, 0, 0, 3, 3, 3, 0},
  {0, 5, 0, 0, 0, 0, 0},
  {0, 5, 0, 0, 4, 0, 0},
  {0, 5, 0, 0, 4, 0, 0},
  {0, 5, 0, 0, 4, 0, 0},
  {0, 5, 0, 0, 4, 0, 0},
  {0, 0, 2, 2, 0, 0, 0}
};
for (int shipSize = 2; shipSize <= 5; shipSize++) {
    direction = TopLeftPosition(shipSize, &row, &col, map);
    printf("Ship %d is at (%d, %d) facing %d\n", shipSize, row, col, direction);
}
} 



int main(void)
{
    TestTopLeftPosition();

	return 0;
}