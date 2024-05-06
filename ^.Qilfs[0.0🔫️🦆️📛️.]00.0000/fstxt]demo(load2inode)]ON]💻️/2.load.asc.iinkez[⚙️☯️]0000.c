//2.load.asc.iinkez[⚙️☯️]0000
//= load ascii parse 2 binary inodes. should be ez. 
//📮️
// we are doing str8 2 inode. 4 filename{MUST HAVE} + hash(optional)
// (we can take filename as arg , (or type in ) and call this /+x/ from '2.qi.lngn]🖌️🦾️]0000'
// later, we will just mod "THIS FILE , to "2 inode  2 return w/e"
// 🧐️this file is "EZ" and can be called in fx's instead. once inode thingy is done.  🧐️
//📮️
//(from non inode 2 inode)
// can get fancy later

//🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
////////
extern char *std_superBLockFilename_H; //🤩️

/////////////


extern int stdBlockSize_H  ;
 int local_BlockSize_Test = 65535; // 32 bit  ;
 char* local_Block[65535]; 
 
 
 char* filename1[64]; 
 
 // could pass 2 header btw
char* filename2[64];//actual filename should be collected as "ARG" and put in "INODE"
char* filename3[64]; //actual filename should be collected as "ARG" and put in "INODE"
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

createNewInodeFromBinFD_T(returnBuffSize,local_returnBinaryBuffer_0);
// u should iterate over return binary pushing it into inodes. 
free(local_returnBinaryBuffer_0);
 }
 //🦄️think this wuold be better in header longterm. (and other using fs names as args? 
 int createNewInodeFromBinFD_T(int arg_binBuffSize, char *arg_returnBinaryBuffer){
 //📌️4.5.24
 //⚠️u may wanna make "fs+-inode"outside of fx🪄️, if u areant already kuz "KISS"⚠️
 //🚨️it should either "MAKE IF NONE", or W8 4 u 2 make 
 //int exit_status = WEXITSTATUS(system("./+x/0.fsmaqr]💾️🗄️.+x"));
 // exists already..., so w/e
 //system("./#.delete.disk🧼️.sh"); 
 int exit_status = WEXITSTATUS( system("./+x/0.fsmaqr]💾️🗄️.+x"));
 //////wont make if it doesnt' need so u should beable 2 move on for now...
 //🍍️V> i dont know what any of this is doing tbh (4.5.24)
 // i think its making a 2nd inode (or 1rst) . u need 2 pass inode / file name 2 
 // assoc with the bin-stuffing were about2 do...
 //🍍️
 system("./+x/0.inode.maqr[🧠️🎫️]0000.+x"); //110
//
system("./+x/0.pro.maqr+[🎫️]0001.+x");

char local_proDirString_0[32];

//📌️(this needs 2 save 64 bit +- "FILENAME",from arg)
int newInodeCt = Std_register_block_Inode(local_proDirString_0); //®️🦄️  returns string & int
			// it would just be blank otherwise if no arg
			// its not a "DEP"
		// u may wanna "STD" dir name later tho :/ 
		//®️
printf("responsibleREAL {inodeStr?no, ✍️blok 4 inode} from FX()🦾️ = %s \n",local_proDirString_0);
//int newInodeCt =  Std_read_inode_count_H(std_superBLockFilename_H); 

printf("newInodeCt = %d\n", newInodeCt);

//🍍️4.5.24 = w/e , we have "inodes 1rst block = local_proDirString_0"
// start filling up block now. , then we will load in 2.qi🦾️ however ;(will biggest{meaningfully} job ever 4 a while probably.😴️
//🍍️4.6.24 
// void stdDropToProKbdMem(char *c){
//🍍️something from here could be refactord 2 header? 
strcpy(filename3, local_proDirString_0); // 🧠️📁️/📄️

//////////////////🦄️⚙️
printf("🦄️⚙️ \n");
//🏚️🧟‍♂️️lets assum MALLOC ISSUES START POST V HERE ...
printf("testMalloc_0...➕️➕️➕️ START[----☄️]\n");
char *testMalloc_0 = malloc(512);
char *testMalloc_1 = malloc(512);
free(testMalloc_0);
free(testMalloc_1);
printf("testMalloc_0...➕️➕️➕️ END[----]\n");
// ☄️makes it past this one so im pretty sure it aint corrupt till later☄️
STD_binBuff2inodes_H(arg_binBuffSize,arg_returnBinaryBuffer,local_proDirString_0); ///🦄️
///4.8.24📌️ i think ur ready 2 run this..., u can always cut off head
// and make sure it still compiles/runs first !
//////////////////🦄️
 }
 
// int STD_binBuff2inodes_L(int charCount , char *binBuff){ }
 //////////////
// int asciiFDbuffToBinaryBuffer(){}
 int STD_binaryFDbuffToAsciiBuffer_H(){}
 int writeBufferToTxtFile(){}
 
 

int main(int argc, char* argv[])
{
    printf("in ⚙️\n");
    system("./#.delete.disk🧼️.sh"); // can remove later its fast..
    
    if (argv[1] != NULL){ 
	//🧼️ = 0000000000110000.pro 🧼️ 
	//printf("passed arg !%s \n", argv[1]);
	//strcpy(tidStripped, argv[1]);
	strcpy(filename1, argv[1]);
	printf("filename1 : %s\n",filename1 );
}else{

strcpy(filename1, "default2do]0000.txt");//⚠️not done yet...
}
    openAsciiFile();
    
    //🍍️just read a buffer in and print it back out 2 new file
    // ( store the filename in an empty inode?no  dont.
    // 🍍️in seperate we will do 2 inode
}
//🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️
