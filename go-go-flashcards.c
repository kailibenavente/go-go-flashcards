/* Program to practice making functions and for user flashcard study.
 *
 * @assignment ICS 212 Assignment 9
 * @author Benavente, Ka'ili
 * @date 10/3/24
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "getdouble.h"

int MULTIPLY(int a, int b);
int MULTIPLY(int a, int b) {
  return a*b;
}
int ADD(int a, int b);
int ADD(int a, int b) {
  return a+b;
}
int SUBTRACT(int a, int b);
int SUBTRACT(int a, int b) {
   return a-b;
}

int main(void){

  //Seeding random number generator
  srand(time(NULL));

  //Correct answers
  int correct = 0;

  //Incorrect answers
  int incorrect = 0;

  //Program intro
  puts("Prepare to lock-in and study with Math Flashcards!");
  puts("This program is designed for single digit multiplication, addition, and subtraction.");

  //Asking for type of study 
  printf("Subjects to practice:\n1. Multiplication\n2. Addition\n3. Subtraction\n");
  printf("What would you like to study? ");
  
  //Receiving type of study
  int type = (int) getdouble();

  //Display error message
  if (type < 1 || type > 3) {
    puts("Error. Please enter a integer of 1, 2, or 3.");
    return 0;
  } //if close

  //Ask for amount of questions
  printf("How many questions would you like to answer? ");

  //Variable to hold desired # of questions
  int qs = (int) getdouble();

  //Error message displays if int is <1
  if (qs < 1) {
    puts("Error. Please enter a number greater than or equal to 1.");
    return 0;
  } //if close

  switch (type) {
  case 1: //multiplication
    for (int i = 0; i < qs; i++) {
      int rnd1 = rand() % 9;
      int rnd2 = rand() % 9;

      printf("What is %d times %d? ", rnd1, rnd2);
      
      int answerM = (int) getdouble();

      if (MULTIPLY(rnd1, rnd2) == answerM){
	printf("That's correct!\n");
	correct++;
      } else {
	printf("Oops! That's incorrect. The right answer was %d.\n",
	       MULTIPLY(rnd1, rnd2));
        incorrect++;
      } //if else close

//printf("Question %d of %d done\n", i + 1, qs);  // Debug print
     
    } //loop close
    break;
  case 2: //addition
    for (int i = 0; i < qs; i++) {
      int rnd1 = rand() % 9;
      int rnd2 = rand() % 9;

      printf("What is %d plus %d? ", rnd1, rnd2);

      int answerM = (int) getdouble();

      if (ADD(rnd1, rnd2) == answerM){
        printf("That's correct!\n");
        correct++;
      } else {
        printf("Oops! That's incorrect. The right answer was %d.\n",
               ADD(rnd1, rnd2));
        incorrect++;
      } //if else close                                                           
//printf("Question %d of %d done\n", i + 1, qs);  // Debug print             

    } //loop close   
    break;
  case 3: //subtraction
    for (int i = 0; i < qs; i++) {
      int rnd1 = rand() % 9;
      int rnd2 = rand() % 9;

      printf("What is %d minus %d? ", rnd1, rnd2);

      int answerM = (int) getdouble();

      if (SUBTRACT(rnd1, rnd2) == answerM){
        printf("That's correct!\n");
        correct++;
      } else {
        printf("Oops! That's incorrect. The right answer was %d.\n",
               SUBTRACT(rnd1, rnd2));
        incorrect++;
      } //if else close                                                           
   //printf("Question %d of %d done\n", i + 1, qs)
 
   } //loop close   
    break;
  } //switch close


  //printf("# of correct answers: %d\n# of incorrect answers: %d\n",
  //  correct, incorrect);

  //Calculating correct percent
  double perCorr = 100.0 * correct / qs;
  
  printf("You got a total score of %.2f%!\n", perCorr); 

  return 0;

} //main close
