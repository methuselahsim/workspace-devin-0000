//📬️seems cool tho . the real test is " sentpiece tokens"
/*
cat f\$+/answer_i.txt 
EVO=LORE obvious. hope reactions life. EVO=LORE galaxies**: and random start Chemical duality this structures).
*/
//❤️‍🩹️kwik fix? tell "THIS" 2 go "token by token. instead of fullmat..
//❤️‍🩹️ just show it 2 oll, and tell it what u really want. 

//💪️ teh segfault happens in here, its plain 2 see where , its 
// not cause nan. it COULD BE CUZ stack is 2 big for laptop . tho...
// i find that hard 2 believe the only caveat being that 
// llama2.c processes tokens ONE AT A TIME INSTEAD OF IN MATRIX BATCHES
// that would explain why... 
// u could do that "IN THIS ONE" if thats a problem. or w/e 
//it is wut it is. 💣️ if u didnt' know. this is how u find out💣️ 
// 🥽️thats an insight i would have NEVER done so w/e 🥽️
//u can probalby fix itnow tho w/e🥽️

/*
In C, when you declare an array like `float 
weights_matrix[7684][789];`, the compiler allocates memory on 
the stack for that array. The size of the stack is limited by 
the system, typically around 8MB (but can vary depending on the 
OS and architecture).

When you try to create an array with a large number of elements 
like in your case (`7684 * 789 = 6,072,216`), you exceed the 
available stack space.
*/
// one fix is just waiting and redoing everything in binary ? 
// i think float = bloat.. good test anyways. 👩🏻‍🔬️
//💣️
#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include  <math.h>
#include <time.h>
#include <stdlib.h>
//⁉️❣️
// ur gonna wanna get the average of each (of 4 rows)
// before making "b_float"
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

    char buffer[102400];   // Assume maximum line length is less than 1024 characters
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
// but u could float check...
    fclose(fp1);

printf("%s \n",a_jagged[3][1]);

 for (i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
         //   printf("Element at row %d and column %d: %s\n", i, j, a_jagged[i][j]);

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
    float **b_float = (float **)malloc(rows * sizeof(float *));
   
    for (int i = 0; i < rows; i++) {
        b_float[i] = (float *)malloc(cols * sizeof(float));
    }

     int row = 0;

    while (fgets(buffer, sizeof(buffer), fp2) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            b_float[row][col] = atof(token);
            printf("b_float[%d][%d] = %f\n", row, col, b_float[row][col]);
            token = strtok(NULL, " \n");
        }
        row++;
    }
   // exit(11);
    ////////
           // Convert matrix to 1D array
    float *b_1_float = (float *)malloc(rows * cols * 
sizeof(float));
    i = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            b_1_float[i] = b_float[row][col];
            printf("b_1_float[%d] = %f\n", i, b_1_float[i]);
            i++;
        }
    }
     printf("Matrix B_1 size: %d x %d\n", 1, rows * cols);
     
     int n_size = rows * cols; 
   
    printf("cols wtf? %d\n",cols);
     
     free(b_float);
    ///
    
    /*
    
      // Write to file "flat.txt" for debug purposes
    FILE *fp_flat = fopen("f$+/flat.txt", "w");
    if (fp_flat == NULL) {
        fprintf(stderr, "Error opening file 'flat.txt'!\n");
        return 1;
    }

    for (int i = 0; i < rows * cols; i++) {
        fprintf(fp_flat, "%f ", b_1_float[i]);
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
     
    float **c_float = (float **)malloc(rows * sizeof(float *));
   
    for (int i = 0; i < rows; i++) {
        c_float[i] = (float *)malloc(cols * sizeof(float));
    }

     row = 0;
 while (fgets(buffer, sizeof(buffer), fp3) != NULL) {
        char *token = strtok(buffer, " \n");
        for (int col = 0; col < cols; col++) {
            c_float[row][col] = atof(token);
         //   printf("c_float[%d][%d] = %f\n", row, col, c_float[row][col]);
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
  //  float weights_matrix[n_size][m_size];
  
 //printf("n_size %d , m_size %d\n",n_size,m_size);
//  float weights_matrix[m_size][n_size];
  
 //   float weights_matrix[7684][789];
   // float weights_matrix = NULL;
   
   float **weights_matrix = malloc(n_size * m_size * sizeof(float));

//💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️
// this blows stack. anyways training these would make no sense
// cept very specific situation . w/e  

//💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️💣️
   ///////////
   /*
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < n_size; j++) {
            weights_matrix[i][j] = (float)rand() / RAND_MAX;
        }
    }
    */
    /*
     error: subscripted value is neither array nor pointer nor vector
  302 |         sum += b_1_float[j] * weights_matrix[i][j];

am i not accessing the weights_matrix correclty? do i need to add
& or something? 
*/
    
     
///🐢️<- -------------------------->🐢️⛳️
    // how is random weights supposed 2 be helfpul? i dont get it🔦️

    // Print weights_matrix as a checkpoint
    
 
   // 
   // 
   /*
    if (fp3 != NULL) {
        for (int i = 0; i < n_size; i++) {
    //    printf("test: %d \n", i  );
            for (int j = 0; j < m_size; j++) {
                fprintf(fp3, "%f ", weights_matrix[i][j]);
          //      printf("%f ", weights_matrix[i][j]); //🔦️
            }
            fprintf(fp3, "\n");
        //    printf( "\n");
        }
        fclose(fp3);
    }
*/
//

///jul30 🏋‍♀️️im guessing that u could train this 2 predict
//word even better. using weights, turning this into FF and doing 
// back prop epocs, where add "bias? " < ask oll. but
// im guessing this works "just as well as a 1d NN/FF" cuz
// i def saw results .


// what is weight matrix size? this could cause bads


float *predicted_word = (float *)malloc(m_size * 
sizeof(float));

// i switched m and n size and it no longer breaks... hmmm
// but how can that be right? maybe it is tho...
// cuz i remember the og code was like that in a way... wut? 
// yes was actually using msize and cols (are those the same? 
printf("m_size %d\n",m_size);

for (int i = 0; i < m_size; i++) {
    float sum = 0;
    for (int j = 0; j < cols; j++) {
 //     for (int j = 0; j < n_size ; j++) {
        sum += b_1_float[j] * (float)rand() / RAND_MAX; //* weights_matrix[i][j];
      
   //   sum += b_1_float[j] * weights_matrix[i][j];
    }

    if (!isfinite(sum)) { // check if sum is finite
        printf("Warning: Predicted word[%d] will be set to zero due to NaN\n", i);
        predicted_word[i] = 0; // or some other default value you prefer
    } else {
        predicted_word[i] = sum;
    }
   // printf("Predicted word[%d] = %.2f\n", i, predicted_word[i]);
}
free(predicted_word); 

//how do i stop this from setting predicted_word[i] to -nan (i have math.h but not cmath.h)? : < oll


   //  sum += fmin(fmax(b_1_float[j] * weights_matrix[i][j], -10.0), 10.0);
    //fixing 
    //  sum += (j == 0) ? 0 : b_1_float[j] * weights_matrix[i][j];

printf("debug1 softmax \n");
////
  // Apply softmax function
  float prob_sum = 0;
for (int k = 0; k < m_size; k++) {
    float temp = exp(predicted_word[k]);
    if(isinf(temp)) {
        // replace with a different number, e.g. 1e-10
        temp = 1e-10;
    }
    
    
    if (!isfinite(temp)) { // check if sum is finite
        printf("Warning: Predicted word[%d] will be set to zero due to NaN\n", i);
        temp = 0; // or some other default value you prefer
    } 
    
    
    prob_sum += temp;
}
///
       printf("prob_sum: %.2f  \n" , prob_sum);

 ///////////////   
    
    float p_words[m_size];
    for (int i = 0; i < m_size; i++) {
        p_words[i] = exp(predicted_word[i]) / prob_sum;
    }
    
    printf("please give me tru size of og index here : %d \n",m_size);

    printf("Probability distribution: \n");
    for (int i = 0; i < m_size; i++) {
        printf("%.2f ", p_words[i]);
    }
    printf("\n");
    
    //////////
    int max_idx = -1;
float max_prob = -INFINITY;
//float max_prob = -19999;
for (int i = 0; i < m_size; i++) {
    if (p_words[i] > max_prob) {
        max_prob = p_words[i];
        max_idx = i;
    }
}

// i dont like saying "m&n size its opaque. give them better names pls)
printf("Maximum probability index: %d\n", max_idx);

printf("%s\n", a_jagged[max_idx][1]);

//fprintf(fp4, a_jagged[max_idx][1]);
//fclose(fp4);
char sent_form[10240];

// Read contents of fp4 and print to console as checkpoint. dont

//FILE *fptr = NULL ;
// fptr = fopen("answer.txt", "r");

// Store the content of the file
char myString[1000];
//fp4 = fopen("answer.txt", "w");
// Read the content and store it inside myString
fgets(myString, 1000, fp4);
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



