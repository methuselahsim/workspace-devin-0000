#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include  <string.h>

/////
int heads = 1; // adjust this value as needed*wont do anything!
 int rows = 0, cols = 0;
   int masked_flag = 0;   // 1 = no mask, 0 = masks 
 
 

int main(int argc, char **argv) {

    
  //📯️  
    FILE *fp_q = fopen("f$+/q.txt", "r");
    if (!fp_q) {
        perror("Error opening file + arg man prev ORCH<3");
        return 1;
    }
    FILE *fp_k = fopen("f$+/k.txt", "r");
    if (!fp_k) {
        perror("Error opening file + arg man prev ORCH<3");
        return 1;
    }
    FILE *fp_v = fopen("f$+/v.txt", "r");
    if (!fp_v) {
        perror("Error opening file + arg man prev ORCH<3");
        return 1;
    }
    //////📯️
    FILE *fp0 = fopen("f$+/resultant.txt", "r");
    if (!fp0) {
        perror("Error opening file + arg man prev ORCH<3");
        return 1;
    }
/////////////////

    char buffer[1024];  // Assume maximum line length is less than 1024 characters
   


    while (fgets(buffer, sizeof(buffer), fp0) // dont need 2 rewind. 
    						//its an appendage. 
    						// using 2 get "real size";)
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
    //////////////////
    

    double q[rows][cols], k[rows][cols], 
v[rows][cols];
    double tp[cols][rows];

    

    int i, j;

    // Read Q matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp_q, "%lf", &q[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    // Read K matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp_k, "%lf", &k[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    // Read V matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp_v, "%lf", &v[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    fclose(fp_q);
     fclose(fp_k);
     fclose(fp_v);
     
     ///////////
          printf("tp k mat \n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            tp[i][j] = k[j][i];
            printf("%f ", tp[i][j]);
        }
        printf("\n");
    }

  
     



    // Calculate Query-Key Scaled Dot Product
    double pro[rows][rows], scaledPro[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            double sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += q[i][k] * tp[k][j];
            }
            pro[i][j] = sum;
        }
    }

    // Scale the resultant matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            scaledPro[i][j] = pro[i][j] / rows;
        }
    }

    // Print the result as a checkpoint
    printf("Query-Key Scaled Dot Product (Scaled):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", scaledPro[i][j]);
        }
        printf("\n");
    }

      // Apply Softmax
    double sum, expSum;
    double softPro[rows][cols];

    
    for (int i = 0; i < rows; i++) {
    double maxVal = -INFINITY;
    for (int j = 0; j < cols; j++) {
        maxVal = fmax(maxVal, scaledPro[i][j]);
    }
    sum = 0.0;
    for (int j = 0; j < rows; j++) {
        expSum = exp(scaledPro[i][j] - maxVal);
        sum += expSum;
    }
    for (int j = 0; j < rows; j++) {
        softPro[i][j] = exp(scaledPro[i][j] - maxVal) / sum;
    }
}

    
   // Matrix multiplication with v matrix
    double matMult[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            double sum = 0;
            for (int k = 0; k < rows; k++) {
                sum += scaledPro[i][k] * v[k][j];
            }
            matMult[i][j] = sum;
        }
    }

    // Print the matrix multiplication result
    printf("Matrix Multiplication Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matMult[i][j]);
        }
        printf("\n");
    }

    
    ///////////
    return 0;
}

/*
next step: 
Calculate query-key similarity q k & v are all 2d arrays (not 3d)
impliment "Calculate query-key similarity" 
avoid segfaults. proceed
*/
////////////////////


 //optional
     /*
     
      ////////
    double mask[rows][cols] ;
     
    
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                double rand_val = drand48();
                if (masked_flag == 0) { // only set masks when masked_flag is 0
                    if (rand_val < 0.5) { // or some other threshold
                        mask[j][k] = 1.0;
                     } else {
                        mask[j][k] = 0.0;
                     }
                } else { // when masked_flag is 1, fill with 1.0
                    mask[j][k] = 1.0;
                }
            }
        }

///
printf("mask\n");
 for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", mask[i][j]);
        }
        printf("\n");
    }
 //////

*/

//🗑️
/*

 printf("attention_weights\n");
     double attention_weights[rows][cols];
    
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                // Initialize with random values, e.g.
                attention_weights[j][k] = drand48();
            }
        }
        
         for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", attention_weights[i][j]);
        }
        printf("\n");
    }
*/    
///
  

