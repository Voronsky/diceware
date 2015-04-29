#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 7776
#define DICE_ROLLS 5 //diceware method uses 5 die rolls to get 5 different numbers 1-6

int genKey(); //Returns the number of words as a string

int main(int argc, char *argv[]){
  int diceNumList[7776];
  char diceWordList[7776][10]; //7776 indexes, 5 chars for the 5 digits, 10 size length char for the possible word to be retrieved
  int i,x,c,keyVal,words;
  i=x=c=keyVal=0;

  FILE *infile = NULL;
  infile=fopen(argv[1],"r");
  sscanf(argv[2],"%d",&words);

  //Check to see if an argument is NULL or missing
  if(infile == NULL || words <= 0){
    printf("Usage: ./diceware <input file.txt> <# of words to generate>\n");
    return (1);
  }

  for(i=0;i<MAX_WORDS;i++){
    fscanf(infile,"%d %s",&diceNumList[i],(char *)&diceWordList[i]);
  }

  printf("Number of words requested was %d\n",words);
  printf("Passphrase: ");
  /*loop enough times per # of words requested*/
  for(c=0;c<words;c++){ //Generate the words based on the number of words wanted
    keyVal = genKey(); //Generate the key value
    for(x=0;x<(sizeof(diceNumList)/4);x++){
      if(diceNumList[x] == keyVal){ //If the index contains the key value
        printf(" %s ",diceWordList[x]); //Print the char array index that contains the string
      }
    }
  }
  printf("\n");
  fclose(infile);
  return 0;
}

int genKey(){

  char number[5]; //5 bytes to hold a byte per number generated from the 'die' roll
  int m,x,max,min,key;
  max = 6; //up to number 6, six sided die
  min = 1; //lowest number is 1
  key = 0; 

  for(x=0;x<DICE_ROLLS;x++){
    number[x] = '0' + (rand()%(max-min)+min); //Take an integer value and add 0 to it, to make it it's ascii representation
  }

  sscanf(number,"%d",&key);
  return key;
}
