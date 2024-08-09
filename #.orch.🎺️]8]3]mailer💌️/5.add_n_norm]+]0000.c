#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include   <string.h>

 //////////🍍️jul22



int main(int argc, char *argv[]) {

int i, j;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fout = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/mMha.txt", "r");
        fp2 = fopen("f$+/resultant.txt", "r");
        fout = fopen("f$+/add_n_norm.txt", "w+");
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
/*
    FILE *fp1 = fopen("f$+/shatt+.txt", "r");
    FILE *fp2 = fopen("f$+/resultant.txt", "r");
    FILE *fout = fopen("f$+/shatt_mbed.txt", "w");
    */
//////🍍️jul22

    
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

//



 // Add matrices a and b
    double c_double[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c_double[i][j] = a_double[i][j] + b_double[i][j];
        }
    }
    /*
    next step . apply normalization to c_double using row wise mean and standard deviation.
    any questions? if not proceed
*/
printf("c_added\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", c_double[i][j]);
        }
        printf("\n");
    }

////////
/*
 // Calculate row-wise means and standard deviations for matrix c
for (int i = 0; i < rows; i++) {
    double sum = 0.0;
    double sum_squared = 0.0;
    for (int j = 0; j < cols; j++) {
        sum += c_double[i][j];
        sum_squared += pow(c_double[i][j], 2);
    }
    double mean = sum / cols;
    double variance = (sum_squared / cols) - pow(mean, 2);
    double std_dev = sqrt(variance);

    // Normalize each row of matrix c using the calculated mean and standard deviation
    for (int j = 0; j < cols; j++) {
        c_double[i][j] = (c_double[i][j] - mean) / std_dev;
    }
}
*/

// Normalize matrix c (additive normalization)
double c_mean[rows]; // array to store row-wise means
double c_stddev[rows]; // array to store row-wise standard deviations

for (int i = 0; i < rows; i++) {
    double sum = 0.0;
    for (int j = 0; j < cols; j++) {
        sum += c_double[i][j];
    }
    c_mean[i] = sum / cols; // calculate row-wise mean
}

for (int i = 0; i < rows; i++) {
    double sum = 0.0;
    for (int j = 0; j < cols; j++) {
        sum += (c_double[i][j] - c_mean[i]) * (c_double[i][j] - c_mean[i]);
    }
    c_stddev[i] = sqrt(sum / (cols - 1)); // calculate row-wise standard deviation
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        c_double[i][j] -= c_mean[i]; // subtract mean from each element
        c_double[i][j] /= c_stddev[i]; // divide by standard deviation
    }
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (isnan(c_double[i][j])) { // check if NaN
            c_double[i][j] = 0.0; // replace with 0.0
        }
    }
}

//in this loop find out of if value of c_double[i][j] = -nan (isnan()) w/e
//then simply set it to 0.0 instead ; 



printf("c_norm\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", c_double[i][j]);
        }
        printf("\n");
    }



    // Write the normalized matrix to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fout, "%lf ", c_double[i][j]);
         //   printf("%lf ", c_double[i][j]);
        }
        fprintf(fout, "\n");
      //  printf("\n");
    }
/*
    fclose(fp1);
    fclose(fp2);
    fclose(fout);
*/
    return 0;
}

