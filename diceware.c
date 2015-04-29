#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 7776

int genKey(); //Returns the number of words as a string

int main(int argc, char *argv[]){
  //int words = (int)*argv[2];
  //char input_line[16];
  char *token;
  char input_line2[16];
  //int diceWordList[7776][2];
  int diceNumList[7776];
  char diceWordList[7776][10]; //7776 indexes, 5 chars for the 5 digits, 10 size length char for the possible word to be retrieved
  int i,x,c,keyVal,words;
  words=i=x=c=keyVal=0;

  FILE *infile = NULL;
  //words = (int)*argv[2];
  infile=fopen(argv[1],"r");

  if(infile == NULL){
    printf("Usage: ./diceware <input file> <# of words to generate>\n");
    return (1);
  }
  for(i=0;i<MAX_WORDS;i++){
    fscanf(infile,"%d %s",&diceNumList[i],(char *)&diceWordList[i]);
    // strcpy(diceWordList[i],token);
    //token = strtok(NULL,"\n");
  }

  /*DEBUG
  for(x=0;x<7;x++){
    printf("%d %s\n",diceNumList[x],diceWordList[x]);
  }*/
  sscanf(argv[2],"%d",&words);
  printf("Number of words requested was %d\n",words);
  //keyVal = genKey();
  printf("debug, the num generated %d\n",keyVal);
  printf("Passphrase: ");
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

  char number[5];
  int m,x,max,min,key;
  max = 6;
  min = 1;
  key = 0;

  for(x=0;x<5;x++){
    number[x] = '0' + (rand()%(max-min)+min); //Take an integer value and add 0 to it, to make it it's ascii representation
  }

  //  printf("This is the string in number %s\n",number);
  sscanf(number,"%d",&key);
  // printf("THIS IS KEY VAL %d\n",key);
  return key;
}
