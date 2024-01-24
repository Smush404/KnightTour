#include <stdio.h>

#define MAX_INDEX 5
#define MAX_SIZE 25

int start(int A[MAX_INDEX][MAX_INDEX], int B[1728][MAX_SIZE], int x, int y, int b, int b_2){

    if(x < 0 && x > 4 ||  y < 0 && y < 4 || b > 1728 || b_2 > 25){
        return 1; //error out of bounds
    }

    for(int j = 0; j <= b_2; j++){// no revists might be bug for interation 24
        if(A[x][y] == B[b][j]){
            b_2 -= 1;
            return 2; //found a repeat
        }
    }

    if(B[b][24] != -1){
        b += 1;
        b_2 = 0; 
        return 0;}

    if(b_2 < 25){ //see if it can place the cell of A in B
        B[b][b_2] = A[x][y];
    }
    // else{ //b index is full 
    //     // b += 1; //increase the indexers
    //     // b_2 = 0;
    // }

    b_2 += 1;

    if(x + 2 <= 4 && y + 1 <= 4){ //goes down and right
        start(A, B, x + 2, y + 1, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }
        // else{return 0;}
    }
    
    if(x + 2 <= 4 && y - 1 >= 0){ //goes down and left
        start(A, B, x + 2, y - 1, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }
    }

     if(x - 2 >= 0 && y + 1 <= 4){ //goes up and right
        start(A, B, x - 2, y + 1, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }
    }

     if(x - 2 >= 0 && y - 1 >= 0){ //goes up and left
        start(A, B, x - 2, y - 1, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }
    }

     if(x - 1 >= 0 && y - 2 >= 0){ //goes left and up
        start(A, B, x - 1, y - 2, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }

    }

     if(x + 1 <= 4 && y - 2 >= 0){ //goes left and down
        start(A, B, x + 1, y - 2, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }

    }

    if(x - 1 >= 0 && y + 2 <= 4){ //goes right and up
        start(A, B, x - 1, y + 2, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }   

    }

    if(x + 1 <= 4 && y + 2 <= 4){ //goes right and down
        start(A, B, x + 1, y + 2, b, b_2);
        // if (ret == 2 || ret == 3){
        //     b_2 -= 1;
        // }

    }
    
    return b; //found dead end
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

    int A[MAX_INDEX][MAX_INDEX]; //matrix of the board
    int B[1728][MAX_SIZE]; //array of all the answers

    int i, c = 1, b = 0; //i = index of current cell, c is a count to fill, b is what # tour we are on
    int x, y; //points on A

    for(i = 0; i < MAX_INDEX; i++){//fills the table
        for (int j = 0; j < MAX_INDEX; j++)
        {
           A[i][j] = c;
           c += 1;
        }
    }

    for(i = 0; i < 30; i++){//fills the table
        for (int j = 0; j < 25; j++)
        {
           B[i][j] = -1;
        }
    }

    //print_table(A); //prints the table 

    for(i = 0; i < MAX_SIZE; i++){ //finds the index of X and Y for each i
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
        b = start(A, B, x, y, b, 0);
        b += 1;
        //printf("%3d", start(A, B, x, y, b, 0)); //calls the starting methods 
    }

    for(int r = 0; r < 27; r++){
        for(int t = 0; t < 24; t++){
            printf("%3d", B[r][t]);
            printf(", ");
        }
        printf("end \n\n");
    }

    return 0;
}