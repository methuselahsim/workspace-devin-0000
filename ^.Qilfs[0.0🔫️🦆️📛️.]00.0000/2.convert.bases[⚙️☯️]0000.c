//2.load.asc.iinkez[⚙️☯️]0000
//= load ascii parse 2 binary inodes. should be ez. 
//📮️
//tbh theoretically u could use xxd first and just load 
// binary into inode. u may wanna do binary load 2 inode first
//u can even turn 2 "pro.c's into 1 .c file later"keep it
// loose and modular <3 
//>upfront laziness of not making another module = techdebt 
//protip , make 2 (ascii 2 bin & bin 2 inode)
// and figure out how 2 use them 2gether IF u WANT.

//❗️binary 2 'ascii.txt' is a whole diff thing  and just 4 VIZ...❗️
//📮️
//(from non inode 2 inode)
// can get fancy later

//🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️
#include <stdio.h>
#include <fcntl.h>

extern int stdBlockSize_H  ;
 int local_BlockSize_Test = 65535; // 32 bit  ;
 char* local_Block[65535]; 
 
 
 char* filename1[64]; 
 // could pass 2 header btw
 //📩️
 int openAsciiFile(){
  int fd = open("load.txt", O_RDWR | O_CREAT, 777);
  
  int bitsRead = read(fd, local_Block, local_BlockSize_Test);
close(fd); 

int numberOfChars = strlen(local_Block);
  
  printf("file : %d \n, %s \n",numberOfChars,local_Block);
  
  int returnBuffSize = 16 * numberOfChars ; 
  char *local_returnBinaryBuffer_0  = malloc(returnBuffSize ) ;
  std_RowArrayConvert(local_Block, numberOfChars,local_returnBinaryBuffer_0);//🦄️
  printf("file : %s \n",local_returnBinaryBuffer_0);

fd = open("test_conversion_out.txt", O_RDWR | O_CREAT, 0644); //if i dont TRUNC appends


write(fd, local_returnBinaryBuffer_0 ,returnBuffSize); //
close(fd);
 }
 //////////////
// int asciiFDbuffToBinaryBuffer(){}
 int STD_binaryFDbuffToAsciiBuffer_H(){}
 int writeBufferToTxtFile(){}
 
 

int main(int argc, char* argv[])
{
    
    
    if (argv[1] != NULL){ 
	//🧼️ = 0000000000110000.pro 🧼️ 
	//printf("passed arg !%s \n", argv[1]);
	//strcpy(tidStripped, argv[1]);
	strcpy(filename1, argv[1]);
	printf("filename1 : %s\n",filename1 );
}
    openAsciiFile();
    
    //🍍️just read a buffer in and print it back out 2 new file
    // ( store the filename in an empty inode?no  dont.
    // 🍍️in seperate we will do 2 inode
}
//🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️
