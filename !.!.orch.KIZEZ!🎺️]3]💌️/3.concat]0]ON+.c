#include <stdio.h>
#include   <stdlib.h>
#include   <string.h>

int main(int argc, char **argv) {
    int i, j;
    /*
    FILE *fp_query_embeds = fopen("f$+/query_embeds.txt", "r");
    FILE *fp_pos_encoding = fopen("f$+/positional_encoding.txt", "r");
    FILE *fp_resultant = fopen("f$+/resultant.txt", "w");

    if (fp_query_embeds == NULL || fp_pos_encoding == NULL || fp_resultant == 
NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    
    */
    
        FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fout = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/query_embeds.txt", "r");
        fp2 = fopen("f$+/positional_encoding.txt", "r");
        fout = fopen("f$+/resultant.txt", "w");
    } else if (argc >= 3) {
        char *filename;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-1") == 0) {
                filename = argv[i + 1];
                fp1 = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-2") ==
0) {
                filename = argv[i + 1];
                fp2 = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-3") ==
0) {
                filename = argv[i + 1];
                fout = fopen(filename, "w+");
                i++; // Skip the filename
            }
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL) || (fout == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }
    ///
    
      printf("debug.\n");
    int rows = 0, cols = 0;
   char buffer[1024];   // Assume maximum line length is less than 1024 characters
    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0') break;   // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        rows++;
    }

    rewind(fp1);

    printf("Matrix size: %d x %d\n", rows, cols);
    
    /////////////

    float query_values[rows][cols]; // swap for rows or cols first?= i&j ;)
for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
        float val1, val2;
        fscanf(fp1, "%f ", &val1);
        fscanf(fp2, "%f ", &val2);
        query_values[i][j] = val1 + val2; // Add the values
    }
}
///

for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
        
        fprintf(fout, "%f ", query_values[i][j]);
        printf("%f ", query_values[i][j]);
    }
    fprintf(fout, "\n");//  ITS F PRINT. 
      printf("\n");
}

  // printf("debug.\n");
  /*
    fclose(fp_query_embeds);
    fclose(fp_pos_encoding);
    fclose(fp_resultant);
*/
    return 0;
}

