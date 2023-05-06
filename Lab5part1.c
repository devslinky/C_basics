#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);
int main(void) {
  
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
  return 0;
}
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
  a :;
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1 </
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
      for (int i = choiceInd - 1; i > 0;i--){
        if (userOne[choiceInd] == userOne[i]){
            goto a; 
        }
      }
      if(userOne[choiceInd] < 1 || userOne[choiceInd] > BoxesNum -1 ){
        goto a;
      }
    }

  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));

    b: ;

  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
      for (int i = choiceInd - 1; i > 0;i--){
        if (userTwo[choiceInd] == userTwo[i]){
            goto b; 
        }
      }
      if(userTwo[choiceInd] < 1 || userTwo[choiceInd] > BoxesNum -1 ){
        goto b;
      }
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
}
void populateBoxes(int boxes[], const int BoxesNum) { 
    boxes[BoxesNum];
    for (int i = 0; i< 20; i++){
        boxes[i] = rand() % 3 + 1;
    if (boxes[i] == 1){
        boxes[i] = -10;
    }
    else if (boxes[i] == 2){ 
        boxes[i] = 10;
    }
    else{
        boxes[i] = 0;
    }
    }
    for (int j = 0; j<20;j++){
        printf(" %d: %d, ",j,boxes[j]);
    }
  // Fill each element randomly by either </
  // 0 empty </
  // -10 bomb </
  // 10 candy </
  // Print the contents of the boxes </
  printf("\n");
}
bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) {
  bool valid = true;

   for (int i = ChoicesNum ; i > 0 ; i-- ){
    if (choices[i] == choices[i-1]){
        valid = false;
    if(choices[i] > BoxesNum-1 || choices[i] < 0){
        valid = false;
    }
    }
   }
  // Check if elements in choices is between 0 and BoxesNum - 1
  // Check if elements in choices is distinct
  return valid;
}