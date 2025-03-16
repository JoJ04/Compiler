#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include "init.h"
#include "parse.h"
//#include <stdio.h> // Include stdio.h for FILE

FILE *input;
FILE *output;
FILE *err;

int main(void) {
  input = fopen("C:\\Users\\gogo-\\Documents\\CS224\\inputFile.exp" , "r");
	output = fopen("C:\\Users\\gogo-\\Documents\\CS224\\outputFile.obj" , "w");
	err = fopen("C:\\Users\\gogo-\\Documents\\CS224\\errorFileile.err" , "w");
    if (input == NULL){
		printf("the file doesn't exist");
	}
    else{
    init();
    parse();
    exit(0);

    // Added return statement
}
 }



