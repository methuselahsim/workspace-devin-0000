#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include   <string.h>



#define EPOCHS 4
#define LEARNING_RATE 0.1


int main(int argc, char *argv[]) {

int i, j;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fout = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/add_n_norm.txt", "r");
        fp2 = fopen("f$+/ffout.txt", "w");
     
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



int activation_fx = 1 ; // 0 for ReLU, 1 for Sigmoid

double learning_rate = 0.1 ; 

double b_double[rows][cols];
double c_double[rows][cols];
double d_double[rows][cols];

int epochs = 2;

 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            d_double[i][j] = rand() / (double)RAND_MAX;
            c_double[i][j] = rand() / (double)RAND_MAX;
        }
    }
   
     printf("d_rands\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", d_double[i][j]);
        }
        printf("\n");
    }
    
      printf("c_rands\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", c_double[i][j]);
        }
        printf("\n");
    } 
    

for (int i = 0; i < epochs; i++) {
     
     
       // Initialize weights and errors
   

  // Dropout
  /*
    double dropout_probability = 0.5; // randomly set to 0 or 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((rand() / (double)RAND_MAX) < dropout_probability) {
                a_double[i][j] = 0.0;
            }
        }
    }
    */
    /*
    printf("a_drop\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", a_double[i][j]);
        }
        printf("\n");
    }
    */
    // Feedforward

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (activation_fx == 0) { // ReLU
                b_double[i][j] = fmax(a_double[i][j], 0.0);
            } else if (activation_fx == 1) { // Sigmoid
                b_double[i][j] = 1.0 / (1.0 + exp(-a_double[i][j]));
            }
        }
    }
    
    printf("b_ff\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", b_double[i][j]);
        }
        printf("\n");
    }

     // Backpropagation

/*original double formula, but wtf is going on storing in a?
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double error = c_double[i][j];
            if (activation_fx == 0) { // ReLU
                d_double[i][j] -= learning_rate * error;
                a_double[i][j] = fmax(a_double[i][j], 0.0);
            } else if (activation_fx == 1) { // Sigmoid
                double sigmoid_derivative = b_double[i][j] * (1.0 - 
b_double[i][j]);
                d_double[i][j] -= learning_rate * error * 
sigmoid_derivative;
                a_double[i][j] = log(sigmoid_derivative 
/ (1.0 - sigmoid_derivative));
            }
        }
    }


    

        
    }//epoch


//is this code correct? if so why does ReLU option return only 0?

    // Print results






/*
    // Write the normalized matrix to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fout, "%f ", a_double[i][j]);
         //   printf("%f ", a_double[i][j]);
        }
        fprintf(fout, "\n");
      //  printf("\n");
    }
    */
/*
    fclose(fp1);
    fclose(fp2);
    fclose(fout);
*/
    return 0;
}

