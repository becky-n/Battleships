# include <stdio.h>
#define MAP_SIZE 6


void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]) {
    int i,j;

    for(i=0;i<MAP_SIZE;i++){
        for(j=0;j<MAP_SIZE;j++){
             map[i][j]=0;
        }   
    }

    // size 2 vertical ship
    for(i=0;i<2;i++){
        for(j=0;j<1;j++){
            map[i][j]=2;
        }
    }

    // size 3 horizontal ship
    for(i=0;i<1;i++){
        for(j=0;j<3;j++){
            map[i+2][j+1]=3;
        }
    }

    // size 5 vertical ship
    for(i=0;i<5;i++){
        for(j=0;j<1;j++){
            map[MAP_SIZE-5+i][MAP_SIZE-1+j]=5;
        }
    }

    // size 4 horizontal ship
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

void TestInitialiseMap(void)
{
 int map1[MAP_SIZE][MAP_SIZE];
 InitialiseMap(map1);
 printf("Map: \n");
 PrintArray(map1);
}

int main(void)
{
    TestInitialiseMap();

	return 0;
}