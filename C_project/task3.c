# include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 6

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

void TestAddRandomShip(void)
{
 int map1[MAP_SIZE][MAP_SIZE] = {0};
 int map2[MAP_SIZE][MAP_SIZE] = {0};
 //AddRandomShip(5, map1);
 printf("Map: \n");
 PrintArray(map1);
 AddRandomShip(2, map2);
 AddRandomShip(3, map2);
 AddRandomShip(4, map2);
 AddRandomShip(5, map2);
 AddRandomShip(2, map2);


 printf("Map: \n");
 PrintArray(map2);
} 





int main(void)
{
    srand(time(NULL));
    TestAddRandomShip();

	return 0;
}