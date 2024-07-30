#include <stdio.h>
#include <stdlib.h>
#include   <string.h>
#include <time.h>



int main(int argc, char **argv) {
/*
 FILE *file = fopen("f$+/resultant.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }
    
    
      // Write to "qkv.txt"
    FILE *q_file = fopen("f$+/q.txt", "w");
    if (!q_file) {
        printf("Error opening file\n");
        return 1;
    }
    
       FILE *k_file = fopen("f$+/k.txt", "w");
    if (!k_file) {
        printf("Error opening file\n");
        return 1;
    }
    
       FILE *v_file = fopen("f$+/v.txt", "w");
    if (!v_file) {
        printf("Error opening file\n");
        return 1;
    }
    
    */
    int i ; 
     FILE *fp1 = NULL;
    FILE *fp2 = NULL;
      FILE *fp3 = NULL;
    FILE *fp4 = NULL;
    FILE *fp5 = NULL;

    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/add_n_norm_0.txt", "r");
        fp2 = fopen("f$+/q.txt", "w");
         fp3 = fopen("f$+/k.txt", "w");
        fp4 = fopen("f$+/v.txt", "w"); 
          fp5 = fopen("f$+/resultant_1.txt", "r");
        //https://stackoverflow.com/questions/21113919/difference-between-r-and-w-in-fopen
    } else if (argc >= 4) {
        char *filename;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-1") == 0) {
                filename = argv[i + 1];
                fp1 = fopen(filename, "r");
                i++; // Skip the filename
            } else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "-2") == 0) {
                filename = argv[i + 1];
                fp2 = fopen(filename, "w");
                i++; // Skip the filename
                }else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-3") == 0) {
                filename = argv[i + 1];
                fp3 = fopen(filename, "w");
                i++; // Skip the filename
            
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-4") == 0) {
                filename = argv[i + 1];
                fp4 = fopen(filename, "w");
                i++; // Skip the filename
            }
            else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "-5") == 0) {
                filename = argv[i + 1];
                fp5 = fopen(filename, "w");
                i++; // Skip the filename
            }
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL) ||(fp3 == NULL) || (fp4 == NULL) || (fp5 == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }
    
    
   printf("debug.\n");
    int rows = 0, cols = 0;
   char buffer[1024];   // Assume maximum line length is less than 1024 characters
    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0') break;   // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        rows++;
    }

    rewind(fp1);

    printf("Matrix size: %d x %d\n", rows, cols);
    
   // int rows_v = 0, cols_v = 0;  // do we do this for "ANSWER?" shrug
//u dont need a new size. it was cut/padded🗜️
    // Initialize random number generator
    srand(time(NULL));

    // Generate weight matrices as "wordcount x four-dimensions"
    float *W_Q = (float *)malloc((rows * cols) * sizeof(float));
    float *W_K = (float *)malloc((rows * cols) * sizeof(float));
    float *W_V = (float *)malloc((rows * cols) * sizeof(float));

    for (int i = 0; i < rows * cols; i++) {
        W_Q[i] = (rand() / (RAND_MAX + 1.0)) * 0.9f; // Random values between 0 and 0.9
        W_K[i] = (rand() / (RAND_MAX + 1.0)) * 0.9f;
        W_V[i] = (rand() / (RAND_MAX + 1.0)) * 0.9f;
    }

    // Read values from "resultant.txt"
   
    float words[rows][cols]; // Assuming 6 vectors in each row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp1, "%f ", &words[i][j]);
        }
        fscanf(fp1, "\n");
    }
    fclose(fp1);
    
     //////////////  
    float words_v[rows][cols]; // Assuming 6 vectors in each row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp5, "%f ", &words_v[i][j]);
        }
        fscanf(fp5, "\n");
    }
    fclose(fp5);

    // Generate queries, keys, and values using dot product multiplication
    float *Q = (float *)malloc((rows * cols) * sizeof(float));
    float *K = (float *)malloc((rows * cols) * sizeof(float));
    float *V = (float *)malloc((rows * cols) * sizeof(float));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Q[i * cols + j] = words[i][j] * W_Q[i * cols + j];
            K[i * cols + j] = words[i][j] * W_K[i * cols + j];
            V[i * cols + j] = words_v[i][j] * W_V[i * cols + j];
        }
    }

  
    
    
// fprintf(output_file, "Queries:\n");
//fprintf(output_file, "\n");
    for (int i = 0; i < rows; i++) {
       
        for (int j = 0; j < cols; j++) {
            fprintf(fp2, "%f ", Q[i * cols + j]);
        }
        fprintf(fp2, "\n");
        }
        
      //   fprintf(output_file, "Keys:\n");
//      fprintf(output_file, "\n");
          for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
            fprintf(fp3, "%f ", K[i * cols + j]);
        }
        fprintf(fp3, "\n");
        }
       // fprintf(output_file, "Values:\n");
     //  fprintf(output_file, "\n");
          for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
            fprintf(fp4, "%f ", V[i * cols + j]);
        }
        fprintf(fp4, "\n");
        }
        /*
       fclose(q_file);
        fclose(k_file);  
    fclose(v_file);
*/
    // Free memory
    free(W_Q);
    free(W_K);
    free(W_V);
    free(Q);
    free(K);
    free(V);

    return 0;
}

