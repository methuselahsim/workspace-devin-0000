#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define some constants for the size of arrays
#define LINEAR_ROWS 128
#define LINEAR_COLS 256
#define VOCAB_ROWS 5000
#define VOCAB_COLS 2



void softmax(double *output, double *linear, char ***vocab) {
    int i, j;
    double max_val = -INFINITY;

    // Find the maximum value in the linear output
    for (i = 0; i < LINEAR_ROWS; i++) {
        if (linear[i] > max_val) {
            max_val = linear[i];
        }
    }

    // Calculate the softmax function using vocabulary
    for (i = 0; i < VOCAB_ROWS; i++) {
        int j;
        double score = 0.0;
    //    char *word = vocab[i][0];  // Get the word string from the vocab array
         char *word = vocab[i][2]; 
        for (j = 0; j < strlen(word); j++) {  // Calculate score based on the word's ASCII value
            score += word[j];
        }
        output[i] = exp(score - max_val);
    }

    // Normalize the values so they add up to 1.0
    double sum = 0.0;
    for (i = 0; i < VOCAB_ROWS; i++) {
        sum += output[i];
    }
    for (i = 0; i < VOCAB_ROWS; i++) {
        output[i] /= sum;
    }
}





int main() {
    // Initialize arrays
    double linear[LINEAR_ROWS][LINEAR_COLS];
    double vocab[VOCAB_ROWS][VOCAB_COLS];

    // Fill in the values for linear and vocab here...

    // Calculate softmax function for linear array
    double output[LINEAR_ROWS];
    softmax(output, linear);

    // Do something with the result of the softmax function...
    return 0;
}

