#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
//
#include <string.h>
///////////////////

char testBuffer[8] = "12345678";

int main(int argc, char* argv[]){
//
//shiftBufferLeftMemmove(testBuffer, 4); // ON
//shiftBufferRightMemmove(testBuffer, 1);
rotate_str_right(testBuffer, 8, 4);

printf("testBuffer = %s \n",testBuffer);
}


// answer here 
//https://gist.github.com/hyunmoon/4c3ee53b9d040abfd746
