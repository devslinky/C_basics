#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Part 3: 4 marks
// Using calculateScoreInDir, it checks for each row/col,
// if it sees a line of 1's resulting from that startRow and startCol
// that is equal to difficulty level! Amazing it should return gameOver
bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

// You need to have implemented to proceed! But on Examify, we will add ours
void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;
  printf("Enter size and difficulty level: ");
  scanf("%d %d", &Size, &difficultyLevel);

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

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    printf("Enter row and col: ");
    scanf("%d %d", &userInputRow, &userInputCol);

    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);  
    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!");
  }

  return 0;
}

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  // you will need to call calculateScoreInDir

  bool check = false;

for (int directionum = 0; directionum > 4; directionum++){
    for (int rows = 0; rows < Size; rows++){
        for (int cols = 0; cols< Size; cols++){
            if(calculateScoreInDir(rows,cols,directionum,Size,userArray) >= difficultyLevel){
                check = true;
            }
        }
    }
  
}
    return check;
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
}

bool validRowCol(int row, int col, int Size) {
  bool valid =  (((row >= 0) && (col >= 0) && (row <= Size-1) &&(col<= Size-1)));
   return valid;

}
void updateRowCol(int* row, int* col, int dir, bool forward) {
  // update Row and Col in forward/backward direction given direction
  // If direction is 0: row--, 1: row--, col++, 2: col++, 3: row--, col--
  // from part 2
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

void printBoard(int Size, char grid[][Size]) {
  for(int i = 0; i < Size; i++){
        for (int j = 0; j< Size; j++){
            printf("%d",grid[i][j]);
        }
        printf("\n");   
     }
}