#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include  <string.h>

/////
int heads = 8; // adjust this value as needed
 int rows = 0, cols = 0;
 
 
 double dot_product(double *q, double *k) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        sum += q[i] * k[i];
    }
    return sum;
}

double weighted_sum(double *v, double *q, double 
*attention_weights) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += v[i] * attention_weights[i][j];
        }
    }
    return sum;
}




// softmax: computes the softmax of a single value
double softmax(double x) {
    double exp_x = exp(x);
    double sum_exp_x = 0.0;
    for (int i = 0; i < heads; i++) {
        sum_exp_x += exp_x;
    }
    return exp_x / sum_exp_x;
}



int main(int argc, char **argv) {

    */
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
     
  
 //optional
     
     var masked_ flag = 1;   // 1 = no mask, 0 = masks 
     
     for (int i = 0; i < heads; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                double rand_val = drand48();
                if (masked_flag == 0) { // only set masks when masked_flag is 0
                    if (rand_val < 0.5) { // or some other threshold
                        mask[i][j][k] = 1.0;
                     } else {
                        mask[i][j][k] = 0.0;
                     }
                } else { // when masked_flag is 1, fill with 1.0
                    mask[i][j][k] = 1.0;
                }
            }
        }
    }


 
     
     /*
     i am now going to use these matrixes to do 
     (optionally masked) multi headed attention. 
     what are the next steps as a numbered outline? 
     (last step will return output as "4.out.txt")
     */
////////////////
    
    double attention_weights[heads][rows][cols];
    for (int i = 0; i < heads; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                // Initialize with random values, e.g.
                attention_weights[i][j][k] = drand48();
            }
        }
    }

    // Calculate query-key similarity
    double sim[heads][rows][cols];
    for (int i = 0; i < heads; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                sim[i][j][k] = dot_product(q[i][j], k[i][k]);
            }
        }
    }

  // Compute attention weights with masking
for (int i = 0; i < heads; i++) {
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++) {
            double sim_val = sim[i][j][k];
            if (mask[i][j][k] == 0.0) {
                sim_val = -INFINITY;
            }
            attention_weights_softmax[i][j][k] = 
softmax(sim_val);
        }
    }
}


    // Calculate context vectors
    double context_vectors[heads][rows][cols];
    for (int i = 0; i < heads; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                context_vectors[i][j][k] = weighted_sum(v[i][j],
attention_weights_softmax[i][j][k]);
            }
        }
    }

    // Compute the output
    double output[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[i][j] = weighted_sum(context_vectors, 
q[i][j], attention_weights_softmax);
        }
    }

    // Write the output to file
    FILE *fp_resultant;
    fp_resultant = fopen("f$+/mMha.txt", "w");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp_resultant, "%lf ", output[i][j]);
        }
        fprintf(fp_resultant, "\n");
    }
    fclose(fp_resultant);



    return 0;
}




////////////////////






