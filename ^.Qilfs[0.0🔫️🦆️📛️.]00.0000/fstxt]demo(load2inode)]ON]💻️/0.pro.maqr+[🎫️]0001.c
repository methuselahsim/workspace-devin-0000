//🦸‍♂️️
//dedicated to my dotti sluggi Red Velvet 레드벨벳 'Birthday' MV
//🦸‍♂️️
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

 #include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

extern char *std_superBLockFilename_H; //🤩️

extern int stdKbdAsciiSize_H;
char *stdAsciiBuffer_0;

///
int read_block_count;


int externStringInit(){

stdAsciiBuffer_0 = malloc(stdKbdAsciiSize_H);

}

//🦸‍♂️️
char* superBLock_filename_H[64];
char* blockfilename_Array_H[64][64];



//🦸‍♂️️
int main(int argc, char* argv[]){
externStringInit();


int rand_uid = std_rand(0, 65535); //0–65535

printf("rand_uid = %d \n", rand_uid);
//📮️
//still needs 2 be binary . 
// and could still collide. 
// so u probalby wanna use a hash of 
// proname and filename or w/e

// u dont have to involve hashing just 2 do this tho
//📮️
  converttobinaryMalloc(rand_uid, stdAsciiBuffer_0, stdKbdAsciiSize_H); 
   

printf("stdAsciiBuffer_0 = %s \n", stdAsciiBuffer_0);
///////////////
free(stdAsciiBuffer_0);
///////////////

strcpy(blockfilename_Array_H[0],std_superBLockFilename_H); // can get by uuid later🔭️
//read_block_count = 1 ; //  ?
read_block_count = Std_read_block_count_H(blockfilename_Array_H[0]);
  

Std_createProBlock_H(blockfilename_Array_H[read_block_count],blockfilename_Array_H[0]);//
///// can get by uuid later🔭️
Std_inc_block_count_H(blockfilename_Array_H[0]);

    return read_block_count; 
} 

//🦸‍♂️️
//dedicated to my dotti sluggi Red Velvet 레드벨벳 'Birthday' MV
//🦸‍♂️️
