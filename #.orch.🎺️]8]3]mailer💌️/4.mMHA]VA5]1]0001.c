#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include  <string.h>



/////
int heads = 1; // adjust this value as needed*wont do anything!
//BUT i bet we can make it multiheaded by throwing it all in an epoch
// and just "UPDATING VALUES EACH TIME (dont have to store and mean later tbh...)
 int rows = 0, cols = 0;
 //  int masked_flag = 0;   // 1 = no mask, 0 = masks 
 

#define num_heads 8
#define EPSILON 1e-6


double dot_product(double a, double b) {
    return a * b;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

int main(int argc, char **argv) {
int i,j;
    
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
      FILE *fp3 = NULL;
    FILE *fp4 = NULL;
    FILE *fp5 = NULL;
    
    int flag_0 = 1;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/q.txt", "r");
        fp2 = fopen("f$+/k.txt", "r");
         fp3 = fopen("f$+/v.txt", "r");
        fp4 = fopen("f$+/mMha.txt", "w"); 
          fp5 = fopen("f$+/resultant.txt", "r"); 
        //https://stackoverflow.com/questions/21113919/difference-between-r-and-w-in-fopen
    } else if (argc >= 5) {
        char *filename;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-1") == 0) {
                filename = argv[i + 1];
                fp1 = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-2") == 0) {
                filename = argv[i + 1];
                fp2 = fopen(filename, "r");
                i++; // Skip the filename
                }else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-3") == 0) {
                filename = argv[i + 1];
                fp3 = fopen(filename, "r");
                i++; // Skip the filename
            
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-4") == 0) {
                filename = argv[i + 1];
                fp4 = fopen(filename, "w");
                i++; // Skip the filename
            }
            else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-5") == 0) {
            
             filename = argv[i + 1];
                fp5 = fopen(filename, "r");
                i++; // Skip the filename
            
        } else if (strcmp(argv[i], "--") == 0 || strcmp(argv[i], "-+") == 0) {
        
        /*    
             filename = argv[i + 1];
                fp5 = fopen(filename, "w");
                i++; // Skip the filename
            */
            printf("%s\n",argv[i]); // first debug i need from orchestrator🪄️
            if (strcmp(argv[i], "-+") == 0){
              flag_0 = 0;
            }
        }
    }
    }

    if ((fp1 == NULL) || (fp2 == NULL) ||(fp3 == NULL) || (fp4 == NULL)|| (fp5 == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }
  //📯️  
   
    //////📯️
    
/////////////////

    char buffer[1024];  // Assume maximum line length is less than 1024 characters
   


    while (fgets(buffer, sizeof(buffer), fp5) // dont need 2 rewind. 
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
    
    

    // Read Q matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp1, "%lf", &q[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    // Read K matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp2, "%lf", &k[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    // Read V matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (fscanf(fp3, "%lf", &v[i][j]) != 1) {
                perror("Error reading file");
                return 1;
            }
        }
    }

    fclose(fp1);
     fclose(fp2);
     fclose(fp3);
     
     ///////////
     double weights[rows][cols]; // weights 
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            weights[i][j] = rand() / (double)RAND_MAX;
           
        }
    }
    
     // Print output
        printf("weights :\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", weights[i][j]);
            }
            printf("\n");
        }
         ////////
    double mask[rows][cols] ;
    // can add masked fx 2 the fundamentals later
    
  //  if(flag_0 == 0){
     
            for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                double rand_val = drand48();
                if (flag_0 == 0) { // only set masks when masked_flag is 0
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
        
        /*
        }else{
        // same as no masking. (put in if(flag_set)
         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mask[i][j] = 1.0;
            }
        }
      }  
*/
///
   int heads = 4; // number of attention heads
   double out[rows][cols];
    double out_0[rows][cols];
    
  // w/o this , it outputs "NAN" something mustn't be right tbh
          for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                out_0[i][j] = 0.0;
            }
        }
      /*
           printf("out_0\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", out_0[i][j]);
            }
            printf("\n");
        }
        */
        /*
        why is one of the outputs here -nan ? and how do i fix it? 
        
     prinft =   "out_0
0.000000 0.000000 0.000000 0.000000 
0.000000 0.000000 0.000000 0.000000 
0.000000 0.000000 -nan 0.000000 
0.000000 0.000000 0.000000 0.000000 
0.000000 0.000000 0.000000 0.000000 
0.000000 0.000000 0.000000 0.000000 
0.000000 0.000000 0.000000 0.000000"
*/
    
 //////
     double wq[rows][cols], wk[rows][cols], wv[rows][cols];
 // Create multi-headed attention mechanism
    for (int h = 0; h < heads; h++) {
    

//> how to train weights on each "heads epoch"
// to learn (from masking / w/e)
//bakprop or rl ? (may skip 4now cuz phy assult 
/*
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
    
   
        wq[i][j] = q[i][j] * cos(h * M_PI / heads) * weights[i][j];
        wk[i][j] = k[i][j] * sin(h * M_PI / heads) * weights[i][j];
       wv[i][j] = v[i][j] * weights[i][j];



}}

*/


for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {

        double temp_wq = q[i][j] * cos(h * M_PI / heads) * weights[i][j];
        double temp_wk = k[i][j] * sin(h * M_PI / heads) * weights[i][j];
        double temp_wv = v[i][j] * weights[i][j];

        if (isnan(temp_wq)) {
            wq[i][j] = 0.0;
        } else {
            wq[i][j] = temp_wq;
        }

        if (isnan(temp_wk)) {
            wk[i][j] = 0.0;
        } else {
            wk[i][j] = temp_wk;
        }

        if (isnan(temp_wv)) {
            wv[i][j] = 0.0;
        } else {
            wv[i][j] = temp_wv;
        }
    }
}
/*
fix this to set any resulting -nan to zero (in pure C)
i dont have <cmath> ; must use a different way
*/
 //need to avoid "-nans" in wv[i][j] = v[i][j] * weights[i][j];
 //how to fix this? 

  printf("wq -nan's?📓️ %d:\n", h);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", wq[i][j]);
            }
            printf("\n");
        }
        
          printf("wv -nan's?📓️ %d:\n", h);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", wv[i][j]);
            }
            printf("\n");
        }
        

        // Compute attention weights
        double atn[rows][cols];
      
        //w/o dp
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
      
      double masked_weight = 0.0;
if (mask[i][j] == 1.0) {
    masked_weight = atn[i][j] = wq[i][j] * wk[i][j] + 
wv[i][j];
} else {
    atn[i][j] = 0.0; // or some other value, e.g., -inf
}

      
             
            }
        }
        
        // Compute output
     
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                out[i][j] = atn[i][j] * atn[i][j];
            }
        }
        
        
       // >>> i need to know where in code to apply the mask (its already initialized)
         // Print output
         /*
        printf("ATTN OUT -nan's?📓️ %d:\n", h);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", out[i][j]);
            }
            printf("\n");
        }
        

printf("multi \n");
 
 
       
        // Print output
        printf("Head %d:\n", h);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", out[i][j]);
            }
            printf("\n");
        }
        
        */
        
          for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out_0[i][j] += out[i][j];
        }
    }
/*
        
          printf("Plus %d:\n", h);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", out_0[i][j]);
            }
            printf("\n");
        }
        */
        //////
    }
    
    

    ///
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        out[i][j] = (out_0[i][j]  / heads);
    } 
}
    
    
     printf("AVG %d:\n", heads);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%f ", out[i][j]);
            }
            printf("\n");
        }
  

    
    
   
    // Write the output to file
    
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp4, "%lf ", out[i][j]);
        }
        fprintf(fp4, "\n");
    }
    fclose(fp4);

    ///////////
    return 0;
}





/////////////////////
      //non masked
             //   atn[i][j] = wq[i][j] * wk[i][j] + wv[i][j];
             
             //mask 1
         //    atn[i][j] = wq[i][j] * wk[i][j] + wv[i][j] * mask[i][j];
      
      //mask 2  (seems 2 drop out well if thats wut u want
      

/*
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            wq[i][j] = q[i][j] * cos(h * M_PI / heads) + 
weights[i][j];
            wk[i][j] = k[i][j] * sin(h * M_PI / heads) + 
weights[i][j];
            wv[i][j] = v[i][j];
        }
    }
    */

/*
printf("mask\n");
 for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", mask[i][j]);
        }
        printf("\n");
    }
    */
    
    
    
    // heads same. no need
        /*
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                wq[i][j] = q[i][j] * cos(h * M_PI / heads);
                wk[i][j] = k[i][j] * sin(h * M_PI / heads);
                wv[i][j] = v[i][j];
            }
        }
*/


   //scaled dp (is all zeros)
        // or even dumber
      /*  
        for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double sum = 0;
        for (int k = 0; k < heads; k++) {
            sum += atn[i][j] * v[i][k]; // weighted sum with value matrix
        }
        out[i][j] = sum; // output is the weighted sum of all heads
    }
}
*/

        /*
         for  (int i = 0; i < rows; i++) {
        for  (int j = 0; j < cols; j++) {
            atn[i][j] = wq[i][j] *wk[i][j]; // compute scaled dot product
        }
    }

     */   
     
     
      /*
    modify this code to average the scores from the 
    last (out[i][j]) with the scores of the latest
    out[i][j] each time the head loops
    */
    


  //double out_1[rows][cols];
// double out_2[rows][cols];
 /*
compute the mean of out_0 and out_1 and store
the result in out_2
*/
/*
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        out_2[i][j] = (out_0[i][j] + out_1[i][j]) / 2.0;
    }
}
*/





///❓️
/*
To train the attention mechanism's weights using a masking strategy, you 
can use backpropagation or reinforcement learning. Here are some ideas:

**Backpropagation (BP)**

1. Define a loss function that measures the difference between the 
predicted output and the true output.
2. Compute the gradients of the loss function with respect to the 
attention weights (`wq`, `wk`, and `wv`).
3. Use these gradients to update the attention weights using an optimizer 
(e.g., stochastic gradient descent, Adam).

In your code, you can modify the computation of `masked_weight` as 
follows:
```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double masked_weight = 0.0;
        if (mask[i][j] == 1.0) {
            masked_weight = atn[i][j] = wq[i][j] * wk[i][j] + wv[i][j];
            // Compute gradients of loss function with respect to 
attention weights
            double dwq = ...;
            double dwk = ...;
            double dwv = ...;
            // Update attention weights using optimizer (e.g., SGD, Adam)
            wq[i][j] -= learning_rate * dwq;
            wk[i][j] -= learning_rate * dWK;
            wv[i][j] -= learning_rate * dwv;
        } else {
            atn[i][j] = 0.0; // or some other value, e.g., -inf
        }
    }
}
```
**Reinforcement Learning (RL)**

1. Define a reward function that measures the quality of the attention 
weights.
2. Use RL algorithms (e.g., Q-learning, policy gradient) to update the 
attention weights based on the rewards.

In your code, you can modify the computation of `masked_weight` as 
follows:
```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        double masked_weight = 0.0;
        if (mask[i][j] == 1.0) {
            masked_weight = atn[i][j] = wq[i][j] * wk[i][j] + wv[i][j];
            // Compute reward for current attention weight
            double reward = ...;
            // Update attention weights using RL algorithm (e.g., 
Q-learning, policy gradient)
            wq[i][j] += learning_rate * reward * dwq;
            wk[i][j] += learning_rate * reward * dWK;
            wv[i][j] += learning_rate * reward * dwv;
        } else {
            atn[i][j] = 0.0; // or some other value, e.g., -inf
        }
    }
}
```
These are just a few ideas to get you started. The specifics of how to 
implement BP or RL will depend on your specific use case and problem 
formulation.

Remember to keep track of the gradients (or policy parameters) and update 
the attention weights accordingly. You may also want to consider using 
techniques like mini-batching, regularization, or early stopping to 
improve training stability and convergence.
*/
