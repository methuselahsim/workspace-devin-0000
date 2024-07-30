#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//🤔️can we add learned embeddings ?(internal NN, oll will know wut u mean)/ or is that even necessary? 
//
//🤔️coulnd't hurt imo...


#define MAX_VOCAB 10000 // maximum vocabulary size
#define MAX_WORD_LENGTH 50 // maximum word length
#define EMBEDDING_DIM 4 // dimension of the embeddings

// function to read a line from the corpus file and return a word vector
unsigned int* read_word(char* word) {
    static char buffer[MAX_WORD_LENGTH];
    static unsigned int hash_table[26] = {0};

    strcpy(buffer, word);

    unsigned int* result = (unsigned int*)malloc((MAX_WORD_LENGTH + 1) * 
sizeof(unsigned int));
    for(int i = 0; i < strlen(word); i++) {
        result[i] = buffer[i];
    }
    return result;
}

// function to calculate the hash value of a word
unsigned int hash_function(char* word) {
    unsigned int hash = 5381;
    for(int i = 0; i < strlen(word); i++) {
        hash = ((hash << 5) + hash) ^ (word[i]);
    }
    return hash % MAX_VOCAB;
}

// function to calculate the cosine similarity between two vectors
double cosine_similarity(unsigned int* v1, unsigned int* v2) {
    double dot_product = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;

    for(int i = 0; i < EMBEDDING_DIM; i++) {
        dot_product += (double)v1[i] * (double)v2[i];
        magnitude1 += (double)v1[i] * v1[i];
        magnitude2 += (double)v2[i] * v2[i];
    }

    return dot_product / sqrt(magnitude1) / sqrt(magnitude2);
}

void update_embeddings(unsigned int** embeddings, char* word, unsigned int* hash_value) {
  // Loop through the text data multiple times (e.g., 10-20 iterations)
  for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
    // Calculate the similarity between the current word and its context words
    double similarity = calculate_similarity(word, hash_value);

    // Update the word embeddings based on the co-occurrence patterns
    for (int i = 0; i < EMBEDDING_DIM; i++) {
      embeddings[i] += learning_rate * similarity * (hash_value[i] - embeddings[i]);
    }
  }
}


i
int main(int argc, char **argv) {

     int i; 
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
///////////+

    char line[1024];
    while (fgets(line, sizeof(line), corpus_file)) {
        char word[MAX_WORD_LENGTH];
        int i = 0;

        // Read a word from the line
        while (i < strlen(line) && !isspace(line[i])) {
            word[i++] = tolower(line[i]);
        }
        word[i] = '\0';

        unsigned int* hash_value = read_word(word);
        unsigned int* embedding = (unsigned 
int*)malloc(EMBEDDING_DIM * sizeof(unsigned int));

        // Initialize the embedding vector with random values
        for (int j = 0; j < EMBEDDING_DIM; j++) {
            embedding[j] = rand() & 0xFFFFFFFF;
        }

        // Store the word and its corresponding embedding in the file
        fprintf(embeddings_file, "%s ", (char*)hash_value);
        for (int j = 0; j < EMBEDDING_DIM; j++) {
            fprintf(embeddings_file, "%u ", embedding[j]);
        }
        fprintf(embeddings_file, "\n");

        // Read the context words from the line
        while (i < strlen(line) && isspace(line[i])) {
            i++;
        }

        char context_word[MAX_WORD_LENGTH];
        while (i < strlen(line) && !isspace(line[i])) {
            strcpy(context_word, &line[i]);
            int context_word_length = strlen(context_word);

            // Store the context word and its corresponding embedding in the file
            fprintf(embeddings_file, "%s ", context_word);
            for (int j = 0; j < EMBEDDING_DIM; j++) {
                embedding[j] += rand() & 0xFFFFFFFF;
            }
            fprintf(embeddings_file, "\n");

            i += context_word_length + 1; // skip over the context word
        }

        update_embeddings(embedding, word, hash_value);

        free(hash_value);
        free(embedding);
    }

    fclose(corpus_file);
    fclose(embeddings_file);

    return 0;
}



/*
This code will store each word and its corresponding embedding in the 
file, followed by the context words and their embeddings. The context 
words are separated from the original word by a newline character.

Please note that this is still a simplified version of Word2Vec and does 
not include any learning mechanism to generate the embeddings. You would 
need to add more functionality to implement the actual Word2Vec algorithm.


*/
/* just need to be in "token format" (corpus just each word seperated by newline)

then u can ask it for the values 2 be in binary instead of dec, its ez af. 

but wut does it mean by  : "does not include any learning mechanism to generate the embeddings. You would 
need to add more functionality to implement the actual Word2Vec algorithm?"
can we add that as a seperate function without modifying the original codebase? 
*/

/*post 
```
The `update_embeddings()` function is not shown here as it's a 
separate logic that needs to be implemented. You can implement this
function based on the Word2Vec algorithm you want to use.

Please note that this code assumes you have already implemented the
`read_word()` and `calculate_similarity()` functions, which are not
included in this example.

>>> Send a mess

wut?!
*/
