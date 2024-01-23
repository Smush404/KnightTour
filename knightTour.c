#include <stdio.h>

#define MAX_INDEX 5
#define MAX_SIZE 25

int start(int A[MAX_INDEX][MAX_INDEX], int B[1728][MAX_SIZE], int x, int y, int b){
    if(x >= 0 && x <= 4 ||  y >= 0 && y <= 4 || b > 1728){
        return 1; //error out of bounds
    }

    for(int j = 0; j < sizeof(B[b]); j++){// no revists
        if(A[x][y] == B[b][j]){
            return 1;
        }
    }

    if(sizeof(B[b]) != 25){
        B[b][sizeof(B[b]) + 1] = A[x][y];
    }
    else{
        b += 1;
        B[b][sizeof(B[b]) + 1] = A[x][y];
    }

    if(x + 2 <= 4 && y + 1 <= 4){ //goes down and right
        return start(A, B, x + 2, y + 1, b);
    }

     if(x + 2 <= 4 && y - 1 >= 0){ //goes down and left
        return start(A, B, x + 2, y - 1, b);
    }

     if(x - 2 >= 0 && y + 1 <= 4){ //goes up and right
        return start(A, B, x - 2, y + 1, b);
    }

     if(x - 2 >= 0 && y - 1 >= 0){ //goes up and left
        return start(A, B, x - 2, y - 1, b);
    }

     if(x - 1 >= 0 && y - 2 >= 0){ //goes left and up
        return start(A, B, x - 1, y - 2, b);
    }

     if(x + 1 <= 4 && y - 2 >= 0){ //goes left and down
        return start(A, B, x - 1, y - 2, b);
    }

    if(x - 1 >= 0 && y + 2 <= 4){ //goes right and up
        return start(A, B, x - 1, y - 2, b);
    }

     if(x + 1 <= 4 && y + 2 <= 4){ //goes right and down
        return start(A, B, x - 1, y - 2, b);
    }



    return 0;
}



void print_table(int A[MAX_INDEX][MAX_INDEX]){
    for(int i = 0; i < MAX_INDEX; i++){ //prints the table
        for (int j = 0; j < MAX_INDEX; j++)
        {
          printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int A[MAX_INDEX][MAX_INDEX];
    int B[1728][MAX_SIZE];
    int i, c = 1, b = 0; //i = index of current cell, c is a count to fill, b is what # tour we are on
    int x, y; //points on A
    for(i = 0; i < MAX_INDEX; i++){//fills the table
        for (int j = 0; j < MAX_INDEX; j++)
        {
           A[i][j] = c;
           c += 1;
        }
    }

    print_table(A);

    for(i = 0; i < MAX_SIZE; i++){
        if(i < 5){
            x = 0;
            y = i;
        }
        else if(i < 10 ){
            x = 1;
            y = i - 5;
        }
        else if(i < 15 ){
            x = 2;
            y = i - 10;
        }
        else if(i < 20 ){
            x = 3;
            y = i - 15;
        }
        else if(i < 25 ){
            x = 4;
            y = i - 20;
        }

        start(A, B, x, y, b);
    }

    for(int r = 0; r <= sizeof(B); r++){
        for(int t = 0; t < sizeof(B[r]); t++){
            printf("%3d", B[r][t]);
            printf(" , ");
        }
        printf("\n");
    }

    return 0;
}