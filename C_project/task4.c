# include <stdio.h>
#define MAP_SIZE 8

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


void TestCountValues(void)
{
 int map1[MAP_SIZE][MAP_SIZE];
// Initialise the array
for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
        map1[i][j] = i+j;    
    }
}

int count = CountValues(5, map1);
printf("Count = %d\n", count);
}


int main(void)
{
    TestCountValues();

	return 0;
}