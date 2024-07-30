#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include   <string.h>



#define EPOCHS 4
#define LEARNING_RATE 0.1

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_prime(double x) {
    return x * (1.0 - x);
}

// Sigmoid derivative function
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}



// ReLU functions
double relu(double x) {
    return x > 0 ? x : 0.0;
}

double relu_derivative(double x) {
    return x > 0 ? 1.0 : 0.0;
}



int main(int argc, char *argv[]) {

int i, j;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
  

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

double learning_rate = 0.2 ; 
//double a_double[rows][cols];
double b_double[rows][cols]; // store result here
double c_double[rows][cols]; // weights 
double d_double[rows][cols]; // errors

int epochs = 4;

 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c_double[i][j] = rand() / (double)RAND_MAX;
            d_double[i][j] = rand() / (double)RAND_MAX;
        }
    }
   
   // Initialize weights and errors
  /*
      printf("c_rands\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", c_double[i][j]);
        }
        printf("\n");
    } 
    
       printf("d_rands\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", d_double[i][j]);
        }
        printf("\n");
    }
  
  */

  for (int i = 0; i < epochs; i++) {
    
    /*
      double dropout_probability = 0.2; // randomly set to 0 or 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((rand() / (double)RAND_MAX) < dropout_probability) {
                a_double[i][j] = 0.0;
            }
        }
    }
    */
    //   impliment Feedforward pass on a_double (use PURE C ) 


   
   if(activation_fx == 0){
   //ff relu
   printf("relu");
   //This sets all negative values in `sum` to 0, while leaving positive values unchanged.


  // FF (Feedforward)
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double sum = 0.0;
        sum += a_double[i][j] * c_double[i][j];
        b_double[i][j] = relu(sum);
    }
}

// FF (Feedforward) end

// Backpropagation
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double delta = d_double[i][j] * relu_derivative(b_double[i][j]);
        for (int k = 0; k < cols; k++) {
            c_double[i][k] -= learning_rate * a_double[i][k] * delta;
        }
    }
}

//ff relu end
}else{
//ff - 2nd
 printf("sigmoid");
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sum = 0.0;
     
                sum += a_double[i][j] * c_double[i][j];
      
            b_double[i][j] = sigmoid(sum);
        }
    }
    //ff -end
    
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double delta = d_double[i][j] * 
sigmoid_derivative(b_double[i][0]);
            for (int k = 0; k < cols; k++) {
                c_double[i][k] -= learning_rate * a_double[i][k] * delta;
            }
        }
    }
    ///ffbp end
    }

  


    //////////
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a_double[i][j] = b_double[i][j];
        }
    }
    
    
    
printf("b_fin\n");
    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
     //    fprintf(fp2, "%f ", b_double[i][j]);
            printf("%f ", b_double[i][j]);
        }
        printf("\n");
      //   fprintf(fp2, "\n");
    }


      // apply feedforward model
    }//epoch
    


//is this code correct? if so why does ReLU option return only 0?

    // Print results



    // Write the normalized matrix to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp2, "%f ", a_double[i][j]);
         //   printf("%f ", a_double[i][j]);
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










/*

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < cols; k++) {
                sum += (b_double[i][j] - a_double[i][k]) * c_double[i][k];
            }
            d_double[i][j] = sigmoid_prime(sum) * (1.0 - b_double[i][j]);
            for (int k = 0; k < cols; k++) {
                c_double[i][k] += LEARNING_RATE * a_double[i][k] * 
d_double[i][j];
            }
        }
    }

*/



  
    /*
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < cols; k++) {
                sum += a_double[i][k] * c_double[i][k];
            }
            b_double[i][j] = sigmoid(sum);
        }
    }
    */
      ///  is this a proper implimentation? (makes all rows same...
  /// maybe also rechec "MHA" could probably be better
  // with "MULTIHEADS?) were learning ALOT ;) >3
  // dont get hung up , if its wrong well find out oneday 
  // and come tighten it up <3 🪛️

