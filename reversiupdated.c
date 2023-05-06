/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
// Author: Devraj Solanki
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void printBoard(char board[][26], int n) {
    printf("  ");
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int line = 0; line < n; line++){
        printf("%c", alphabet[line]);
    }
    printf("\n");

   for (int row = 0; row < n; row++) {
    printf("%c", alphabet[row]);
    printf(" ");
    for (int col = 0; col < n; col++) {
      printf("%c",board[row][col]);
    }
    printf("\n");
  }
}

// does the initial set up of the gameboard 
void configurateboard(char board[][26], int n){
    for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
       if (row == (floor(n/2) -1) && col == (floor(n/2) - 1)){
        board[row][col] = 'W';
      }
      else if (row == (floor(n/2)-1) && col == ((n/2))){
        board[row][col] = 'B';
      }
      else if (row == (n/2) && col == (floor(n/2)-1)){
        board[row][col] = 'B';
      }
      else if (row == (n/2) && col == (n/2)){
        board[row][col] = 'W';
      }
      else{
        board[row][col] = 'U';
      }
    }
  }
}


bool positionInBounds(int n, int row, int col) {
    bool validity= false;
    if ( row <= n && row >= 0 && col <= n && col >= 0){
        validity = true;
    }

return validity;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
bool istrue = false;    
int currentrow = row;
int currentcol = col;

row += deltaRow;
col += deltaCol;

while(board[currentrow][currentcol] == 'U' && board[row][col] != colour && board[row][col] != 'U'  && (positionInBounds(n,row + deltaRow,col + deltaCol)) == true){
    row += deltaRow;
    col += deltaCol;
    if(board[row][col] == colour){
          istrue = true;
    }

}
return istrue;
}

bool movelegality(char board[][26], int n, int row, int col, char colour){
  bool checks = false;
      // north
     if(checkLegalInDirection(board,n,row,col,colour,-1,0) == true){
             checks = true;
     }
     // NorthEast
     if(checkLegalInDirection(board,n,row,col,colour,-1,+1) == true){
             checks = true;
     }
     // East
     if(checkLegalInDirection(board,n,row,col,colour,0,+1) == true){
             checks = true;
     }
     // NorthWest
     if(checkLegalInDirection(board,n,row,col,colour,-1,-1) == true){
             checks = true;
     }
     //South
     if(checkLegalInDirection(board,n,row,col,colour,1,0) == true){
             checks = true;
     }
     // SouthWest
     if(checkLegalInDirection(board,n,row,col,colour,1,-1) == true){
             checks = true;
     }
     // West
     if(checkLegalInDirection(board,n,row,col,colour,0,-1) == true){
             checks = true;
     }
     // SouthEast
     if(checkLegalInDirection(board,n,row,col,colour,1,1) == true){
             checks = true;
     }
     return checks;
}

void printlegalmoves(char board[][26], int n){
    printf("Available moves for W:\n");
    for(int i = 0; i < n; i++){
        for (int j = 0; j< n; j++){
            if (movelegality(board,n,i,j,'W') == true){
                printf("%c%c",i + 'a', j +'a');
                printf("\n");
            }
        }
    }
    // printf("\n");

    printf("Available moves for B:\n");
    for(int i = 0; i < n; i++){
        for (int j = 0; j< n; j++){
            if (movelegality(board,n,i,j,'B') == true){
                printf("%c%c",i + 'a', j +'a');
                printf("\n");
            }
        }
    }
}

void printnewgame(char board[][26], int n, int row, int col,
                           char colour, int e, int f) {
             if(checkLegalInDirection(board,n,row,col,colour,e,f) == true){
                // printnewgame(gameboard,n,usermove[1]-'a',usermove[2]-'a',usermove[0],e,f);
                row += e;
                col += f;

                while(board[row][col] != colour){
                board[row][col] = colour;
                row += e;
                col += f;
                }
             }
}


int sumlegalindirection(char board[26][26], int n, int row, int col, char colour){
int sum = 0;
    for(int rowdelt = -1; rowdelt < 2; rowdelt++){
        for(int coldelt = -1; coldelt < 2; coldelt++){
              if(checkLegalInDirection(board,n,row,col,colour,rowdelt,coldelt) == true){
                  
                    row += rowdelt;
                    col += coldelt;

                    while(board[row][col] != colour){
                    sum = sum +1;
                    row += rowdelt;
                    col += coldelt;
                }
             }
    }
    }
    return sum;

}

//////////////////////////////////////////////////////////
//////////////       Computer moves
////////////////////////////////////////////////////////////
int makeMove(char board[26][26], int n, char turn, int *row, int *col){
    int maxscore = 0;
    int bestrow;
    int bestcol;
    
    
    int score[26][26];
    int count = 0;
    // firts finds all legal moves that computer can play, then
    // it will find the move that gives highest score and saves
    // the row and col
    for(int Row = 0; Row<n; Row++){
        for(int Col = 0; Col<n; Col++){
            // only legal moves are considered
            score[Row][Col]= sumlegalindirection(board,n,Row,Col,turn);
            if(sumlegalindirection(board,n,Row,Col,turn) > maxscore){
                maxscore = sumlegalindirection(board,n,Row,Col,turn);
            }
        }
    }
    ///////
  
    return maxscore;
}

bool playbestmoves(char board[26][26], int n, char turn, int *row, int*col) {
    bool doeswork = true;
    int maxscores = makeMove(board,n, turn, row, col);
    int bestAI[2];
    char score[26][26];
    
     for(int Row2lol = 0; Row2lol<n; Row2lol++){
        for(int Col2lol = 0; Col2lol<n; Col2lol++){
            score[Row2lol][Col2lol]= sumlegalindirection(board,n,Row2lol,Col2lol,turn);
            if(score[Row2lol][Col2lol] == maxscores){
                maxscores++;
                bestAI[0] = Row2lol;
                bestAI[1] = Col2lol;
            }
        }
    }
    // basically if the computer can play its turn then it will if not this function
    // will do nothing
    if(maxscores != 0){
   
   printf("Computer places %c at %c%c\n",turn,bestAI[0] + 'a',bestAI[1] + 'a');
 
    for(int e = -1; e <= 1; e++){
        for(int f = -1; f <= 1; f++){
            if(checkLegalInDirection(board, n, bestAI[0], bestAI[1], turn, e, f) == true){
                    printnewgame(board,n,bestAI[0], bestAI[1],turn,e,f);
                    }
                }
            }
            board[bestAI[0]][bestAI[1]] = turn;
            printBoard(board,n);
    }
    else if (maxscores == 0){
        printf("%c player has no valid move.\n", turn);
        doeswork = false;
    }
    return doeswork;
}


/////////////////////////////////////////////////////////////////
//////     this will place moves for player              ////////
/////////////////////////////////////////////////////////////////

// can player make a move?
bool canmove (char board[26][26], int n, char colour){
    bool virtue = true;
    for (int row = 0; row > n ; row++){
        for (int col = 0; col > n; col++){
            if (movelegality(board, n, row, col,colour ) == false){
                virtue = false;
            }
        }
    }
    return virtue;
}

char* scanner(int size){
    char* usermove = (char*)malloc(size*sizeof(char));
    printf("Enter move for colour B (RowCol): ");
    scanf("%s",usermove);
    return usermove;
}



void makeamove(char board[26][26], int n, int row, int col,char colour){
    
    for(int e = -1; e <= 1; e++){
        for(int f = -1; f <= 1; f++){
            if(checkLegalInDirection(board, n, row, col, colour, e, f) == true){
                    printnewgame(board,n,row, col,colour,e,f);
                    }
                }
            }
            board[row][col] = colour;
            printBoard(board,n);
                
}
// this is just a continuation of the prev function

bool playergodamnmoves(char board[26][26],int n, int row, int col, char colour, char compmove){
    bool doeswork = true;
    // checks if player can even make a move
    if (canmove(board, n, colour) == true){
        if (movelegality(board,n,row,col,colour) == true){
             makeamove(board,n,row, col,colour);
         }
         else{
             printf("Invalid move.\n");
             printf("%c player wins.",compmove);
             exit(0);
         }
    }
    else {
        printf("%c player has no valid move",colour);
        doeswork = false;
    }
    
       return doeswork; 
}
///////////////////////////////////////////////////////////////////////////
///////////////////////// just continues the rest of the gameboard
/////////////////////////////////////////////////////////////////////////////



int main(void) {
    int fu[2] = {0,0};
    char gameboard[26][26];
    char playermove[2];
    
///////////////    intitial game set up    ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
    // size of gameboard
    int n;
    printf("Enter the board dimension: ");
    scanf("%d",&n);

    // makes sure size of board is not greater than 26 x 26 and that the inputed size of board is an even number
  if (n> 26){
    printf("Enter the board dimension: ");
    scanf("%d",&n);
  }
  else if (n %2 != 0){
    printf("Enter the board dimension: ");
    scanf("%d",&n);
  }
    
   char firstmove[2];
   printf("Computer plays (B/W): ");
   scanf("%s",firstmove);
    // so its easier to put what color is the player and computer
    if(firstmove[0] == 'W'){
        firstmove[1] = 'B';
    }
    else{
        firstmove[1] = 'W';
    }
    
    // printing initial setup of board
    configurateboard(gameboard,n);
    printBoard(gameboard,n);
    
/////////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////////   
    
    char*usermove;
// firstmove[0] == comp move
//firstmove[1] == player move
    if(firstmove[0] == 'W'){
        usermove = scanner(2);
        int prow = *usermove;
        int pcol = *(usermove+1);
        
    while( playergodamnmoves(gameboard,n,prow-'a',pcol - 'a',firstmove[1],firstmove[0]) == true && playbestmoves(gameboard,n,firstmove[0], &fu[0] , &fu[1]) == true ){
        usermove[0] = scanner(2);
        playergodamnmoves(gameboard,n,prow-'a',pcol - 'a',firstmove[1],firstmove[0]);
        playbestmoves(gameboard,n,firstmove[0], &fu[0] , &fu[1]);
    }
    // no one can play a move
    }
    else {
        playbestmoves(gameboard,n,firstmove[0], &fu[0] , &fu[1]);
    }
    
    
     
   
   
   
   
   
   

   
   
    //computer goes first instead
    // comp go first
    //comp
    //
  free(usermove);
  return 0;
}







