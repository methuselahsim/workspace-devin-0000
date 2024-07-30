#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIMENSIONS 4
#define MAX_LENGTH 1024
#define MAX_TOKENS 1000



int main(int argc, char **argv) {


  int i; 
           FILE *fp1 = NULL;
    FILE *fp2 = NULL;


    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/query.txt", "r");
        fp2 = fopen("f$+/positional_encoding.txt", "r");
       
    } else if (argc >= 2) {
        char *filename;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-1") == 0) {
                filename = argv[i + 1];
                fp1 = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-2") ==
0) {
                filename = argv[i + 1];
                fp2 = fopen(filename, "w");
                i++; // Skip the filename
            } 
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }

  char *token = NULL ;
  int word_count = 0;
////////////
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, fp1) != NULL) {
         token = strtok(buffer, " \n"); // tokenize each word
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " \n"); // get the next token
           word_count++;
        }
    }


    // Initialize the positional encoding array
    double *positional_encoding = malloc(word_count * DIMENSIONS * 
sizeof(double));

    for (int i = 0; i < word_count; i++) {
        // Calculate the positional encoding for each word
        int pos = i;
        for (int j = 0; j < DIMENSIONS; j++) {
            if ((pos & 1) == 0) {   // even position
                positional_encoding[i * DIMENSIONS + j] = sin((double)pos 
/ pow(10000.0, (2 * j) / DIMENSIONS));
            } else {   // odd position
                positional_encoding[i * DIMENSIONS + j] = cos((double)pos 
/ pow(10000.0, (2 * j + 1) / DIMENSIONS));
            }
        }
    }

// printf("wut formula is THAT? \n");

  //  output_file = fopen(fp2, "w+");
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            fprintf(fp2, "%f ", positional_encoding[i * DIMENSIONS+ j]);
            printf("%f ", positional_encoding[i * DIMENSIONS+ j]);
        }
        fprintf(fp2, "\n");
         printf("\n");
    }


/////////////

    return 0;
}

