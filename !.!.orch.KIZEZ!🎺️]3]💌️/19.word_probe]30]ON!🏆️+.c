//
#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include  <math.h>
#include <time.h>
#include <stdlib.h>
//⁉️❣️
// ur gonna wanna get the average of each (of 4 rows)
// before making "b_double"
// or this dosen't even make sense. 
// cuz ur flattening a 4dim matrix of rows representing "corpus"
// also comparing "corpus" 2 "vocab index" makes NO SENSE...
//sooo forget "QUERY" in input, just use "CORPUS" 
// query can be first output . that article was kinda jacked but u can just use
// "diagram + common sense at this point"
// if it doesnt' work its way more accurate than it should be
// and u can probably figure it out doing some other RL/ML project
// cuz all the parts are pretty much teh same cept for this part (even this part)
// !and theres probably a much simplyer/ working example of an "INDEX PICKER"
// theres tons of ML/RL/NN stuff out there so youll get it eventually ❣️

//📮️🦄️i would explor "my lil perceptron" modifying it a bit 2 pull from wordindex; but u may already be good2go tbh📮️🦄️
//⁉️❣️
int main(int argc, char *argv[]) {
    int i;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
      FILE *fp3 = NULL;
    FILE *fp4 = NULL;
char *filename_save;
    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/index.txt", "r");
        fp2 = fopen("f$+/iimha_out.txt", "r");
         fp3 = fopen("f$+/weights_matrix.txt", "w");
        fp4 = fopen("f$+/answer.txt", "r+"); 
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
                fp3 = fopen(filename, "w");
                i++; // Skip the filename
            
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-4") == 0) {
                filename_save = argv[i + 1];
                fp4 = fopen(filename_save, "r+");
                i++; // Skip the filename
            }
        }
    }

    if ((fp1 == NULL) || (fp2 == NULL) ||(fp3 == NULL) || (fp4 == NULL)) {
        printf("Error opening files.\n");
        return 1;
    }
    
    ////////////

    char buffer[1024];   // Assume maximum line length is less than 1024 characters
    int rows = 0, cols = 0;

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

 /////////
printf("Matrix A size: %d x %d\n", rows, cols);


 int m_size = rows;
 ///////
    char ***a_jagged = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        a_jagged[i] = (char *)malloc(cols * sizeof(char));
    }

    rewind(fp1);

  i = 0;
    while (fgets(buffer, sizeof(buffer), fp1) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int j = 0; j < cols; j++) {
            a_jagged[i][j] = (char *)malloc(strlen(token) + 1);
            strcpy(a_jagged[i][j], token);
            token = strtok(NULL, " \n");
        }
        i++;
        
    }

//📅️july29 -> i dont know Y this is happening? i dont "like" this code
// if u can transfer 2 18&20. try 4 that first. 
// it has more basis in science. (oll instead of just guessed)
// i didn't guess , th einstructions are in step #13🍀️
// and i followed them 2 a T. (so i "DO LIKE" this code , sorry)
// but u could double check...
    fclose(fp1);

printf("%s \n",a_jagged[3][1]);

 for (i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at row %d and column %d: %s\n", i, j, a_jagged[i][j]);

}}
     

////////////
    rows = 0, cols = 0;

    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
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


    printf("Matrix B size: %d x %d\n", rows, cols);
 rewind(fp2);
    double **b_double = (double **)malloc(rows * sizeof(double *));
   
    for (int i = 0; i < rows; i++) {
        b_double[i] = (double *)malloc(cols * sizeof(double));
    }

     int row = 0;

    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            b_double[row][col] = atof(token);
            printf("b_double[%d][%d] = %f\n", row, col, b_double[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }
    
           // Convert matrix to 1D array
    double *b_1_double = (double *)malloc(rows * cols * 
sizeof(double));
    i = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            b_1_double[i] = b_double[row][col];
            printf("b_1_double[%d] = %f\n", i, b_1_double[i]);
            i++;
        }
    }
     printf("Matrix B_1 size: %d x %d\n", 1, rows * cols);
     
     int n_size = rows * cols; 
   
    
     
    ///
    /*
      // Write to file "flat.txt" for debug purposes
    FILE *fp_flat = fopen("flat.txt", "w");
    if (fp_flat == NULL) {
        fprintf(stderr, "Error opening file 'flat.txt'!\n");
        return 1;
    }

    for (int i = 0; i < rows * cols; i++) {
        fprintf(fp_flat, "%f ", b_1_double[i]);
    }
    fprintf(fp_flat, "\n");

*/

    //////////
    /*
     rows = 0, cols = 0;

    while (fgets(buffer, sizeof(buffer), fp3) != NULL) {
        // Count number of columns and rows
        cols = 0;
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            if (*token == '\0' ) break;    // End of line
            cols++;
            token = strtok(NULL, " \n");
        }
        rows++;
    }

 printf("Matrix C size: %d x %d\n", rows, cols);
    
     rewind(fp3);
     
    double **c_double = (double **)malloc(rows * sizeof(double *));
   
    for (int i = 0; i < rows; i++) {
        c_double[i] = (double *)malloc(cols * sizeof(double));
    }

     row = 0;
 while (fgets(buffer, sizeof(buffer), fp3) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            c_double[row][col] = atof(token);
         //   printf("c_double[%d][%d] = %f\n", row, col, c_double[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }
    
    */

  
    //🙏️ add code 2 , generate new weights only if no w8s present or w/ei just didn't prune the code cuz rush w/e etc🙏️ 

 // Generate random weight matrix
    srand(time(NULL));  // Seed the random number generator
   ///
    // Generate random weight matrix 0-0.99
    double weights_matrix[n_size][m_size];
    for (int i = 0; i < n_size; i++) {
        for (int j = 0; j < m_size; j++) {
            weights_matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Print weights_matrix as a checkpoint
  
    if (fp3 != NULL) {
        for (int i = 0; i < n_size; i++) {
            for (int j = 0; j < m_size; j++) {
                fprintf(fp3, "%f ", weights_matrix[i][j]);
            }
            fprintf(fp3, "\n");
        }
        fclose(fp3);
    }

//
double predicted_word[m_size];
for (int i = 0; i < m_size; i++) {
    double sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += b_1_double[j] * weights_matrix[i][j];
    }
    predicted_word[i] = sum;
    printf("Predicted word[%d] = %.2f\n", i, 
predicted_word[i]);
}

////
  // Apply softmax function
    double prob_sum = 0;
    for (int k = 0; k < m_size; k++) {
        prob_sum += exp(predicted_word[k]);
    }
    double p_words[m_size];
    for (int i = 0; i < m_size; i++) {
        p_words[i] = exp(predicted_word[i]) / prob_sum;
    }

    printf("Probability distribution: ");
    for (int i = 0; i < m_size; i++) {
        printf("%.2f ", p_words[i]);
    }
    printf("\n");
    
    //////////
    int max_idx = -1;
double max_prob = -INFINITY;
for (int i = 0; i < m_size; i++) {
    if (p_words[i] > max_prob) {
        max_prob = p_words[i];
        max_idx = i;
    }
}

printf("Maximum probability index: %d\n", max_idx);

printf("%s\n", a_jagged[max_idx][1]);

//fprintf(fp4, a_jagged[max_idx][1]);
//fclose(fp4);
char sent_form[1024];

// Read contents of fp4 and print to console as checkpoint. dont

//FILE *fptr = NULL ;
// fptr = fopen("answer.txt", "r");

// Store the content of the file
char myString[100];
//fp4 = fopen("answer.txt", "w");
// Read the content and store it inside myString
fgets(myString, 100, fp4);
fclose(fp4);
// Print the file content
printf("fiel : %s \n", myString);

strcat(myString, a_jagged[max_idx][1]); // Append the string to myString

// Print the result
printf("K. I. S. S.: %s\n", myString);

//fp4 = fopen("f$+/answer_I.txt", "w"); // Open the file in write mode (for overwrite)
 fp4 = fopen(filename_save, "w");

    // Write the modified myString back to the file
    fprintf(fp4, "%s ", myString);
    fclose(fp4); // Close the file pointer
    
    int reCheck = strcmp (a_jagged[max_idx][1], "<~>");
    
     printf("strcmp(str1, str3) = %d\n", reCheck);
    if(reCheck == 0 ){
    
    return 119;
    }

/*
read contents of fp4
print to console as checkpoint.
store in sent_form
print sent_form to console as checkpoint.

*/

// Store in sent_form
//strcpy(sent_form, a_jagged[max_idx][1]);

// Print sent_form to console as checkpoint
//printf("Checkpoint: Sent form: %s\n", sent_form);

    return 100;

//
}



