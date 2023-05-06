#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);
bool validRowCol(int row, int col, int Size);

int main(void) {
  const int maxDim = 23;
  int Size = 0;
  printf("Enter size: ");
  scanf("%d", &Size);

  int copy[maxDim][maxDim] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }

  // call calculateScoreInDir here to check if it works as expected!
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      printf("Row: %d, Col: %d, in direction\n", row, col);
      printf(" 0 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 0, Size, grid));
      printf(" 1 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 1, Size, grid));
      printf(" 2 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 2, Size, grid));
      printf(" 3 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 3, Size, grid));
    }
  }

  return 0;
}

int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]) {
    
    int score = -1;
    int Rowup = row;
    int Colup = col;
    int Rowdown = row;
    int Coldown = col;
    

    if(userArray[Rowup][Colup] == '0'){
      score = 0;
    }



    while ((validRowCol(Rowup,Colup,Size))){
        if(userArray[Rowup][Colup] == '1'){
            score++;
        }
        else{
            
            break;
            
        }
        updateRowCol(&Rowup,&Colup,direction,true);
    }



    while ((validRowCol(Rowdown,Coldown,Size))){
        if(userArray[Rowdown][Coldown] == '1'){
            score++;
        }
        else{
           
            break;
        }
        updateRowCol(&Rowdown,&Coldown,direction,false);
    }
    return score;

  // Check in the forward direction how many 1s are there,
  // plus how many 1s are there in the backward direction
}

void updateRowCol(int* row, int* col, int dir, bool forward) {
  // update Row and Col in forward/backward direction given direction
  // If direction is 0: row--, 1: row-- and col++, 2: col++, 3: row-- and col--

    if (forward == true){
        if ( dir ==0){
            *row = *row-1;

        }
        else if (dir == 1){
            *row = *row-1;
            *col =*col+1;
        }
        else if (dir == 2) {
            *col =*col+1;
        }
        else{
            *row = *row-1;
            *col =*col-1;
            
        }

    }
    else {
        if ( dir ==0){
            *row = *row+1;

        }
        else if (dir == 1){
             *row = *row+1;
            *col =*col-1;
        }
        else if (dir == 2) {
             *col =*col-1;
        }
        else{
            *row = *row+1;
            *col =*col+1;
            
        }
    }

}

bool validRowCol(int row, int col, int Size) {
   bool valid =  (((row >= 0) && (col >= 0) && (row <= Size-1) &&(col<= Size-1)));
   return valid;
}