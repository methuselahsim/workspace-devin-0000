#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define DIM 4  // rather change this once as arg
#define EPOX 4

#define MAX_LENGTH 102400
#define MAX_TOKENS 100000


int main(int argc, char **argv) {


  int i,j; 
           FILE *fp1 = NULL;
    FILE *fp2 = NULL;


    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/query.txt", "r");
        fp2 = fopen("f$+/query_embeds.txt", "w");
       
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

  char *token = NULL ;
  int word_count = 0;
////////////
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, fp1) != NULL) {
         token = strtok(buffer, " \n"); // tokenize each word
        while (token != NULL) {
            printf("%s\n", token);
            //tokenArray[i] = strdup(token);
            token = strtok(NULL, " \n"); // get the next token
           word_count++;
        }
    }

rewind(fp1);

char ***tokenArray[word_count];
/////////////
int count = 0 ; 
  while (fgets(buffer, MAX_LENGTH, fp1) != NULL) {
         token = strtok(buffer, " \n"); // tokenize each word
        while (token != NULL) {
            printf("%s\n", token);
            tokenArray[count] = strdup(token);
            token = strtok(NULL, " \n"); // get the next token
           count++;
        }
    }
// print stored tokens for sanity check
for (int i = 0; i < word_count; i++) {
    printf("TokenArray[%d]: %s\n", i, tokenArray[i]);
}

//int dimensions = DIM;
 double w2v[word_count][DIM];

/*
assume ascii word tokens are stored as a jagged array in "char ***tokenArray[word_count];"
calculate  word embeddings using hashing

*/

 // initialize word-to-vec embeddings array
   

    // calculate word-to-vec embeddings and store them in w2v
    // these are just weights. right now
    // also how tf is random always the same numbers?!?!🎲️[EZ FIX TBH
    // im kinda glad cuz it shows nothing got embedded ]🎰️
    
    for (i = 0; i < word_count; i++) {
        for (j = 0; j < DIM; j++) {
            w2v[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // print initial word-to-vec embeddings as checkpoint
    printf("Initial Word-To-Vec Embeddings:\n");
    for (i = 0; i < word_count; i++) {
        for (j = 0; j < DIM; j++) {
            printf("%f ", w2v[i][j]);
        }
        printf("\n");
    }
//💭️
// can add training here if u want. currently its just adding more rand
// w/o doing back prop or anything ie : that code below is bogus
// just do a feed foward and back prop in epochs 
////💭️
/*
    // train learned embeddings for 'epochs' number of epochs
    int epoch;
    for (epoch = 0; epoch < EPOX; epoch++) {
        // training logic goes here...
        printf("Epoch %d:\n", epoch);
        for (i = 0; i < word_count; i++) {
            for (j = 0; j < DIM; j++) {
                w2v[i][j] += (double)rand() / RAND_MAX;
            }
        }
    }
    */

    // print learned word-to-vec embeddings as checkpoint
    printf("Learned Word-To-Vec Embeddings:\n");
    for (i = 0; i < word_count; i++) {
        for (j = 0; j < DIM; j++) {
            printf("%f ", w2v[i][j]);
             fprintf(fp2, "%f ", w2v[i][j]);
        }
        printf("\n");
         fprintf(fp2, "\n");
    }
    



    return 0;
}

