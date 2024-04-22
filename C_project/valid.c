# include <stdio.h>
#define MAP_SIZE 6


void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]){
    int i, j;
    int rand_num = rand() % 2;
    int max_x = MAP_SIZE - 1;
    int max_y = MAP_SIZE - 1;
    int valid_placement = 0;

    while (!valid_placement) {
        int rand_pos_x = rand() % (max_x + 1);
        int rand_pos_y = rand() % (max_y + 1);
        valid_placement = 1; // Assume the placement is valid

        // vertical position
        if (rand_num == 1 && rand_pos_x >= size - 1) {
            for (i = 0; i < size; i++) {
                if (map[rand_pos_x - i][rand_pos_y] != 0) {
                    // Collision, retry placement
                    valid_placement = 0;
                    break;
                }
            }
            if (valid_placement) {
                for (i = 0; i < size; i++) {
                    map[rand_pos_x - i][rand_pos_y] = size;
                }
            }
        }
        // horizontal position
        else if (rand_pos_y >= size - 1) {
            for (j = 0; j < size; j++) {
                if (map[rand_pos_x][rand_pos_y - j] != 0) {
                    // Collision, retry placement
                    valid_placement = 0;
                    break;
                }
            }
            if (valid_placement) {
                for (j = 0; j < size; j++) {
                    map[rand_pos_x][rand_pos_y - j] = size;
                }
            }
        } else {
            valid_placement = 0;
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
 AddRandomShip(5, map1);
 printf("Map: \n");
 PrintArray(map1);
 AddRandomShip(2, map2);
 AddRandomShip(3, map2);
 AddRandomShip(4, map2);
 AddRandomShip(5, map2);
 printf("Map: \n");
 PrintArray(map2);
} 



int main(void)
{
    TestAddRandomShip();

	return 0;
}