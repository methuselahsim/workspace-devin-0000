#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DIMENSIONS 4
#define MAX_LENGTH 1024
#define MAX_TOKENS 1000



int main(int argc, char **argv) {


  int i,j; 
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


////////////

 char buffer[MAX_LENGTH];
    char *token = NULL;

 float **pe_0;

    // Read the file and tokenize each word
    pe_0 = (float **)malloc(MAX_LENGTH * sizeof(float 
*));
    for (i = 0; i < MAX_LENGTH; i++) {
        pe_0[i] = (float *)malloc(DIMENSIONS * 
sizeof(float));
    }
    int pos = 0;
    while (fgets(buffer, MAX_LENGTH, fp1) != NULL) {
        token = strtok(buffer, " \n");
        while (token != NULL) {
            // Calculate sine and cosine values for thecurrent word
            float sin_val = sin(pos);
            float cos_val = cos(pos);

            // Map sine and cosine values to [-0.5, 0.5]
            sin_val = fmin(fmax(sin_val, -1.0f), 1.0f) * 0.5f;
            cos_val = fmin(fmax(cos_val, -1.0f), 1.0f) * 0.5f;

            // Set the positional encoding for the current word
            pe_0[pos][0] = sin_val;
            pe_0[pos][1] = cos_val;
            pos++;
            token = strtok(NULL, " \n");
        }
    }

    // Print the final outcome for sanity check
    for (i = 0; i < pos; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            printf("%f ", pe_0[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_LENGTH; i++) {
        free(pe_0[i]);
    }
    free(pe_0);

/////////////

    return 0;
}

