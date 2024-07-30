#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIMENSIONS 4
#define MAX_LENGTH 1024
#define MAX_TOKENS 1000


int main(int argc, char **argv) {

/*
    FILE *fp = NULL;
    FILE *output_file = NULL;

    // Default filenames if no command-line arguments are provided
    const char *input_filename = "f$+/query.txt";
    const char *output_filename = "f$+/positional_encoding.txt";

    // Check for command-line arguments and set custom filenames if present
    if (argc > 1) {
        input_filename = argv[1];
        if (argc > 2) {
            output_filename = argv[2];
        }
    }
*/
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

    char *token = NULL;
    char buffer[MAX_LENGTH];
    int words = 0; // declare and initialize


   ////////////////////
     float pe_0[100][4]; // assume maximum 100 words

while (fgets(buffer, MAX_LENGTH, fp1) != NULL) {
        token = strtok(buffer, " \n"); // tokenize eachword
        int i = 0;
        while (token != NULL) {
            // Create 4-dimensional positional encodings for the word
            float pe[4] = {(float)i / strlen(token), (float)(i % strlen(token)) / strlen(token), ((i + 1) % strlen(token)) / strlen(token), 0.5f};
            for (int j = 0; j < 4; j++) {
                pe_0[words][j] = pe[j];
            }
            printf("%s\n", token); // print the word
            for (int k = 0; k < 4; k++) {
                printf("PE[%d][%d]: %f\n", words, k, pe[k]);
            } // print positional encodings
            token = strtok(NULL, " \n"); // get the next token
            i++;
        }
        words++; // increment words here
    }




/////////////

    return 0;
}

