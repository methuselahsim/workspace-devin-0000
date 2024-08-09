#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_CORPUS_SIZE 50000

int main(int argc, char **argv) {

    int i; 
           FILE *fp1 = NULL;
    FILE *fp2 = NULL;


    if (argc == 1) { // No arguments provided
        fp1 = fopen("f$+/corpus.txt", "r");
        fp2 = fopen("f$+/index.txt", "w");
       
    } else if (argc >= 2) {
        char *filename;
      //  printf(": %s %s %s %s \n",argv[i], argv[i + 1] ,argv[i + 2],argv[i + 3]  );
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
        printf("Error opening files ss.\n");
        return 1;
    }


    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    int unique_word_count = 0;

    // Store unique words in an array of character pointers
    char *unique_words[50000];   // assuming max unique words is less than 10,000
    for (int i = 0; i < 50000; i++) {
        unique_words[i] = NULL;
    }

   
    while (fscanf(fp1, "%s\n", word) > 0) {
        if (strlen(word) == 0) continue;   // skip empty lines

        int found = 0;
        for (int i = 0; i < unique_word_count; i++) {
            if (strcmp(word, unique_words[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // Create a copy of each word and store it in the array
            char *unique_word = strdup(word);
            unique_words[unique_word_count++] = unique_word;

            fprintf(fp2, "%d %s\n", ++word_count, word);
        }
    }

    for (int i = 0; i < unique_word_count; i++) {
        free(unique_words[i]);
    }

 //   fclose(corpus_file);
   // fclose(index_file);

    return 0;
}
