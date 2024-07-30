#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include  <string.h>

/////
int heads = 1; // adjust this value as needed*wont do anything!
//BUT i bet we can make it multiheaded by throwing it all in an epoch
// and just "UPDATING VALUES EACH TIME (dont have to store and mean later tbh...)
 int rows = 0, cols = 0;
   int masked_flag = 0;   // 1 = no mask, 0 = masks 
 


int main(int argc, char **argv) {
int i,j;
    
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
      FILE *fp3 = NULL;
    FILE *fp4 = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/q.txt", "r");
        fp2 = fopen("f$+/k.txt", "r");
         fp3 = fopen("f$+/v.txt", "r");
        fp4 = fopen("f$+/mMha.txt", "w"); 
        //https://stackoverflow.com/questions/21113919/difference-between-r-and-w-in-fopen
    } else if (argc >= 3) {
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
                fp4 = fopen(filename, "w");
                i++; // Skip the filename
            
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-4") == 0) {
                filename = argv[i + 1];
                fp4 = fopen(filename, "w");
                i++; // Skip the filename
            }
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL) ||(fp3 == NULL) || (fp4 == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }
  //📯️  
   
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
         ////////
         
         
//    double q[rows][cols], k[rows][cols], v[rows][cols]; (assume these already contain values)
    double mask[rows][cols] ;
    // can add masked fx 2 the fundamentals later
     
    
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
   int heads = 2; // number of attention heads
   double out[rows][cols];
 //////
 task: Create masked multi-headed attention mechanism
 
1. Calculate QK^T for each head

2. Calculate softmax

3. Normalize


     Write the output to file
     
     USE GCC C PURE C
    
    
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




/*
printf("mask\n");
 for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", mask[i][j]);
        }
        printf("\n");
    }
    */

