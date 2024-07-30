#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main(int argc, char *argv[]) {
 int i;

   FILE *fp_query_embeds = NULL;
    FILE *fp_pos_encoding = NULL;
    FILE *fp_cat = NULL;

    if (argc == 1) { // No arguments provided
        fp_query_embeds = fopen("f$+/query_embeds.txt", "r");
        fp_pos_encoding = fopen("f$+/positional_encoding.txt", "r");
        fp_cat = fopen("f$+/resultant.txt", "w");
    } else if (argc >= 3) {
        char *filename;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-query-embeds") == 0 || strcmp(argv[i], 
"-q") == 0) {
                filename = argv[i + 1];
                fp_query_embeds = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-pos-encoding") == 0 || 
strcmp(argv[i], "-p") == 0) {
                filename = argv[i + 1];
                fp_pos_encoding = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-resultant") == 0 || 
strcmp(argv[i], "-r") == 0) {
                filename = argv[i + 1];
                fp_cat = fopen(filename, "w");
                i++; // Skip the filename
            }
        }
    }

    if ((fp_query_embeds == NULL) || (fp_pos_encoding == NULL) || 
(fp_cat == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }

/*
    FILE *fp_query_embeds = 
fopen("D.outputs_embeded.txt", "r");
    FILE *fp_pos_encoding = fopen("D.outputs_PE.txt", 
"r");

    if (fp_query_embeds == NULL || fp_pos_encoding == 
NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    
      FILE *fp_cat = fopen("D.out_cat.txt", "w");
    if (fp_cat == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    
    */

    char buffer[1024];  // Assume maximum line length is less than 1024 characters
    int rows = 0, cols = 0;
    
    rewind(fp_query_embeds);

    while (fgets(buffer, sizeof(buffer), fp_query_embeds)
!= NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0') break;  // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        rows++;
    }

    printf("Matrix size: %d x %d\n", rows, cols);

    double **embeds = (double **)malloc(rows * 
sizeof(double *));
    double **pe = (double **)malloc(rows * sizeof(double 
*));
    for (int i = 0; i < rows; i++) {
        embeds[i] = (double *)malloc(cols * 
sizeof(double));
        pe[i] = (double *)malloc(cols * sizeof(double));
    }

    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp_query_embeds)
!= NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            embeds[row][col] = atof(token);
            printf("embed[%d][%d] = %f\n", row, col, 
embeds[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }

    row = 0;
    while (fgets(buffer, sizeof(buffer), fp_pos_encoding)
!= NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            pe[row][col] = atof(token);
            printf("pe[%d][%d] = %f\n", row, col, 
pe[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }

    // Create a third array
    double **cat = (double **)malloc(rows * sizeof(double
*));
    for (int i = 0; i < rows; i++) {
        cat[i] = (double *)malloc(cols * sizeof(double));
    }

    row = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Add both arrays together
            cat[i][j] = embeds[i][j] + pe[i][j];
            printf("cat[%d][%d] = %f\n", i, j, 
cat[i][j]);
        }
    }

  

    row = 0;
    while (row < rows) {
        for (int col = 0; col < cols; col++) {
            fprintf(fp_cat, "%f ", cat[row][col]);
        }
        fprintf(fp_cat, "\n");
        row++;
    }

    fclose(fp_query_embeds);
    fclose(fp_pos_encoding);
    fclose(fp_cat);

    return 0;
}

