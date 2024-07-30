#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include   <string.h>

 //////////🍍️jul22

/*
how does the linear layer for decoder only transformer 
work , 
does it simply take the output of add & norm? 
are the weights for self training? why are there
weights and biases if the only data is the input data?

*/

int main(int argc, char *argv[]) {

int i, j;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
       FILE *fp3 = NULL;
  

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/add_n_norm.txt", "r");
        fp2 = fopen("f$+/smout.txt", "w");
         fp3 = fopen("f$+/llout.txt", "w");
     
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
            else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-3") ==
0) {
                filename = argv[i + 1];
                fp3 = fopen(filename, "w");
                i++; // Skip the filename
            } 
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL) || (fp3 == NULL)) {
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

   
//
    /*
    double a_double[rows][cols]; //input
     double b_double[rows][cols]; // weights
      double c_double[rows][cols]; // bias
      

 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            b_double[i][j] = rand() / (double)RAND_MAX;
            c_double[i][j] = rand() / (double)RAND_MAX;
        }
    }
   
    assume the doubles are already initialized.
    next steps . apply simple linear layer to a_double
    using b_double and c_double
    
    code this in PURE GCC C 
readability rules : [ NEVER use structs, dont use seperate functions, NEVER use nested loops, avoid segfaults];

(if using epochs , keep it to 4)
 proceed.   
 
 then softmax
 
 *lin lay is much more complex than soft,
 *can even do soft seperate w/e
 
 
*/

   double b_double[rows][cols]; // weights
      double c_double[rows][cols]; // bias
      

 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            b_double[i][j] = rand() / (double)RAND_MAX;
            c_double[i][j] = rand() / (double)RAND_MAX;
        }
    }
       // Linear layer (weights and biases)
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
         a_double[i][j] = a_double[i][j] * b_double[i][j] + c_double[i][j];
        }
    }
    
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp3, "%lf ", a_double[i][j]);
         //   printf("%lf ", c_double[i][j]);
        }
        fprintf(fp3, "\n");
      //  printf("\n");
    }


    // Softmax transformation
    double max_val = -INFINITY; // initialize maximum value
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a_double[i][j] > max_val) {
                max_val = a_double[i][j];
            }
        }
    }

    // Normalize using exponential and sum
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            a_double[i][j] = exp(a_double[i][j] -
max_val); // exponential
            sum += a_double[i][j]; // accumulate values
        }
        for (int j = 0; j < cols; j++) {
            a_double[i][j] /= sum; // normalize
        }
    }

    // Print the result
    printf("After linear layer and softmax transformations:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", a_double[i][j]);
        }
        printf("\n");
    }




    // Write the normalized matrix to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp2, "%lf ", a_double[i][j]);
         //   printf("%lf ", c_double[i][j]);
        }
        fprintf(fp2, "\n");
      //  printf("\n");
    }
/*
    fclose(fp1);
    fclose(fp2);
    fclose(fout);
*/
    return 0;
}

