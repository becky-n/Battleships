# include <stdio.h>
#define MAP_SIZE 6


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
   

void TestPrintArray(void)
{

int map1[MAP_SIZE][MAP_SIZE];
// Initialise the array
for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
        map1[i][j] = 0;    
    }
}

PrintArray(map1);

} 


int main(void)
{
    TestPrintArray();

	return 0;
}



# include <stdio.h>
# include <stdlib.h>





