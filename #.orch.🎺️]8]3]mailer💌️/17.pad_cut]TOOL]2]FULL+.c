#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

int main(int argc, char *argv[]) {
    int i;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fout = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/resultant.txt", "r");
        fp2 = fopen("f$+/D.out+norm.txt", "r");
        fout = fopen("f$+/pad_cut_v.txt", "w+");
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

    char buffer[1024];    // Assume maximum line length is less than 1024 characters
    int rows = 0, cols = 0;

    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0') break;    // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        rows++;
    }

    rewind(fp1);

    printf("Matrix A size: %d x %d\n", rows, cols);

    double **a_double = (double **)malloc(rows * sizeof(double *));
   
    for (int i = 0; i < rows; i++) {
        a_double[i] = (double *)malloc(cols * sizeof(double));
    }

    int row = 0;
    
    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            a_double[row][col] = atof(token);
            printf("a_double[%d][%d] = %f\n", row, col, a_double[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }

    int b_rows = 0;
    rewind(fp2);
    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0') break;    // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        b_rows++;
    }

    rewind(fp2);
    printf("Matrix B size: %d x %d\n", b_rows, cols);

    double **b_double = (double **)malloc(b_rows * sizeof(double *));
   
    for (int i = 0; i < b_rows; i++) {
        b_double[i] = (double *)malloc(cols * sizeof(double));
    }

    row = 0;
    
    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            b_double[row][col] = atof(token);
            printf("b_double[%d][%d] = %f\n", row, col, b_double[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }

    if (b_rows > rows) {
    printf("cutting \n");
        // Cut off excess rows of b_double
        double **c_double = (double **)malloc(rows * sizeof(double *));
   
        for (int i = 0; i < rows; i++) {
            c_double[i] = (double *)malloc(cols * sizeof(double));
        }

        row = 0;
        while (row < rows) {
            for (int col = 0; col < cols; col++) {
                c_double[row][col] = b_double[row][col];
            }
            row++;
        }

        printf("Matrix C size: %d x %d\n", rows, cols);

        rewind(fout);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fprintf(fout, "%f ", c_double[i][j]);
            }
            fprintf(fout, "\n");
        }

    } else if (b_rows < rows) {
     printf("padding \n");
        // Create c_double with the same amount of rows as a_double
        double **c_double = (double **)malloc(rows * sizeof(double *));
   
        for (int i = 0; i < rows; i++) {
            c_double[i] = (double *)malloc(cols * sizeof(double));
        }

        row = 0;
        while (row < b_rows) {
            for (int col = 0; col < cols; col++) {
                c_double[row][col] = b_double[row][col];
            }
            row++;
        }

        // Add padding
        for (int i = b_rows; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                c_double[i][j] = 0.0;
            }
        }

        printf("Matrix C size: %d x %d\n", rows, cols);
        // works but isn't printf'ing just fprinting <3 

        rewind(fout);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fprintf(fout, "%f ", c_double[i][j]);
            }
            fprintf(fout, "\n");
        }

    } else {
    printf("no change \n");
        // Simply print b_double
        rewind(fout);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fprintf(fout, "%f ", b_double[i][j]);
            }
            fprintf(fout, "\n");
        }

    }

    return 0;
}

