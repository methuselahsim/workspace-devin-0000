/*🧿️to prevent HORN/NU-HALO/💸️ blockchain etc 💸️ , from becoming an unweildy/untestable "MONOLITH" 🔍️ 
output 2 "sol]0.txt" if not "Fs[].txt" is present. ez/tedius 2 fix but w/e 🧿️
*/
//
//BLOCK HEADER STRUCTURE : 
//[[VERSion(4by)][Previous block hash(32by)][Merkle Root(32by)][Timestamp secs from gen+date (4)][Difficulty index(4)][nonce(4)][padding(48)]]

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include <stdint.h>
#include <fcntl.h>
//🤩️
//while ( *(++binary) != 0 );
//❓️a brilliant way 2 check of "string" is done iterating
// without needing 2 pass "length of string"
// u really should rewrite some of those fx(); using this
// its fairly simple. def use it in the future⁉️
//🤩️


// #include "^.H.orn-uniHeader.h" 

//char buffer_H[409600000]; // NO LOL WOULD CLOBBER BUFFERS RACE COND ETC
//char buffer2_H[409600000];
//🧠️these cause probblesm keep them smol and scale up like u did halo .  
//int stdBufferSize_H = 512;           // 4096; // 000; ///409600000 ;
char *std_superBLockFilename_H = "disk[0000]/0000000000000000.pro";

char *std_kbdbufferFilename_H = "disk[0000]/0000000000000101.pro";
 
 int stdBlockSize_H = 256; //4096;		//4096 ; 
 
 int stdShiftBufferSize_H = 64;		//4096 ; 
 
 int stdProcNameOffset_H = 64 ; 
 //////
  int stdTidBitSize_H = 32 ;
 int stdBitByteSize_H = 32 ; //change 2 std ALL BIT SIZE
 		 //halo SHOULD be ez 2 switch bitsize(dynamically
 			   //so dont worry of that. 
 int stdProcTimeOffset_H = 96 ;//*was 94accidently? //size is 32
 
// int stdKbdInOffset_H = 160 ; //*was 126accidently?  //size is 32

// int stdBinCryOffset_H = 128 ; // ITS A STACK !🤯️

  int stdKbdAsciiSize_H = 16 ;
 
  int stdPronameSize_H = 16 ;
 

 // int stdKbdInOffset_H = 160 ; //*was 126accidently?  //size is 32
 int stdKbdBufferOffset_H = 64 ; // using 0 for debug kbd speed
 // switch back pls. 🔥️
  int stdProcLoopCountOffset_H =0 ;//256; // 128+64
  
  
  int stdProcLoopCountSize_H =64 ;
  
  int stdKbdCountOffset_H = 64;
 //
////

//🎫️
// probably gonna move strstr".pro" into here (dont need "PRO" can be anything 'past
//"." but not actually tho , huh? also .+x is a thing...
//🎫️



 int getArx() { //Get current architecture, detectx nearly every architecture. Coded by Freak
        #if defined(__x86_64__) || defined(_M_X64)
        return 8;
        #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
        return 3;
        #elif defined(__riscv)
        return 5;
        #elif defined(__arm__)
        return 9;   
        #else
        return 7;
        #endif
    }

char* changeBitCount(char *buffer0 ,char *buffer1 ,int bitsWanted, int sizeOfBuffer0){
/*
if(bitsWanted == -1){
bitsWanted = tidBitSize ; 
}
*/
//char *concat_0s = malloc(bitsWanted);
//char concat_0s[64]
if(sizeOfBuffer0 < bitsWanted ){

int i ;

for(i = 0; i < bitsWanted - sizeOfBuffer0 ; i++) {

buffer1[i] = '0'; 

}

buffer1[i] = '\0';
strcat(buffer1,buffer0 ); 


}else{

// just cut @ 
char concat_0s[64] ; // = malloc(bitsWanted);

char *b0 = buffer0 + bitsWanted; // sneaky trix! 
//https://stackoverflow.com/questions/4761764/how-to-remove-first-three-characters-from-string-with-c
strcpy(buffer1,b0);

}

return buffer1; // if this doesn't work PASS concat_0s as arg

}

//⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️
// all this stuff is kinda unecessary , its nice for debugging
//but u could be using "RAWTIME ie: 1329832 or w/e 2 bin
//1705900929 = 01100101101011011111101110000001
//(which is 31+0pad digits... so yea...), up 2 u. 
// it SHOULD return a higher number actually so w/e 
// u can parse a 48/64 bit number , but u dont need 2 . 
// the "month is never going to be more than 4 bits, so if u want
// u can make a binary parser like that...

// if u ever want u can just take "TIMERAW" from header
// convert it 2 int then do w/e [{good 2 know}+ontrack+liv4AVA <3<QLU]
//kcell keep betryaing me , but the jokes on them <QLU
int rawSeconds(char *bintime32)
{
    
   time_t seconds = time(NULL);//Unix epoch 00:00:00 UTC on 1 January 1970
    
   if (seconds == -1)
      {
        puts("The time() function failed");
        return(1);
      }

 //  printf("%ld\n", seconds);
 converttobinary(seconds, bintime32, 32);
}

char* int_to_binstr(int num, int bits_wanted)
{
	char *bin_string = malloc(bits_wanted);
	int i;

	for(i = 0; i < bits_wanted; i++) {
		bin_string[(bits_wanted - 1) - i] = (char) (int)'0' + ((num >> i) & 1);
	}
	
	bin_string[bits_wanted] = '\0';
	
	return bin_string;
}


char* get_bintime(char* bintime , int bitLength ) 
{
	//char *bintime;
	//bintime = malloc(sizeof(bintime));
	time_t rawtime;
	
	rawtime = time(NULL);
	struct tm *timeinfo = localtime(&rawtime);

// %s:%s:%s:%s:%s:%s
//%s%s%s%s%s%s
	sprintf(bintime, "%s:%s:%s:%s:%s:%s",
	int_to_binstr(timeinfo->tm_year, bitLength), 
	int_to_binstr(timeinfo->tm_mon, bitLength), 
	int_to_binstr(timeinfo->tm_mday, bitLength), 
	 int_to_binstr(timeinfo->tm_hour, bitLength), 
			int_to_binstr(timeinfo->tm_min, bitLength), 
			int_to_binstr(timeinfo->tm_sec, bitLength));
			
			//printf("%s\n",bintime);
	return bintime;
}
/*
tm_sec	int	seconds after the minute	0-61*
tm_min	int	minutes after the hour	0-59
tm_hour	int	hours since midnight	0-23
tm_mday	int	day of the month	1-31
tm_mon	int	months since January	0-11
tm_year	int	years since 1900	
tm_wday	int	days since Sunday	0-6
tm_yday	int	days since January 1	0-365
tm_isdst	int	Daylight Saving Time flag	
*/


//https://stackoverflow.com/questions/64832245/nanosleep-wait-for-at-least-15-ms
// req.tv_nsec=10000; // 10,000 ns = 10 microseconds

//⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️⏳️

//https://newton.ex.ac.uk/teaching/resources/jmr/multifile.html
//================================

// were waiting on "sudo-crystal-clock" till fs is more fleshed (else 2fake)

//
int jsonParseFull(char *buffer0 ,char *buffer1, int countedChars){

int i ; 
int objCount ; //# of {'s
while(i < countedChars){
//char object[]; 

//count "{"'s , then we will iterate counting backwards  ,and just iterate
// our strategy live , no need 2 architect . fail and go again. 
}
//return buffer1; 
}


 
int tidAsFile(){
}
long long unsigned int bin2dec(char *binary)
{
	long long unsigned int decimal = 0;
	do {
		if ( *binary == '0' ) {
			decimal <<= 1;
		} else if ( *binary == '1' ) {
			decimal <<= 1;
			decimal += 1;
	        } else if ( *binary == ' ' ) {
        	    ;
		} else {
			break;
		}
	} while ( *(++binary) != 0 );
	return decimal;
}

// we just want 2 make a nother block at end of count. 
// so u should count blocksize 
//------------------------------------
// void wont return #1 ;)
int compareBuffers(char *buffer0 , char *buffer1, char *buffer2){

// im looking at "demo.html" and will look at "git/patch w/e"  2 try 2 understand WHAT
// WE NEED DIFF FOR , cuz just getting "errors , even "nu array " is ez...
// //we CAN store ". or 0 if not a "diff" but '.' could be a period...
//❓️
// isn't there a better return formula for that? im pretty sure i saw in one of those '.c' files...
// may even be "DELTA" (i think thats an "immediate compression")
// ar we compressing all till diff patch?
//🤯️
// or are we compressing the whole string as "1" cuz their all very similiar and it zeros out diff'blocks'????
//😖️
//4example?: compress 2 , get third so decompress , deltadiffs compresses a new ? 
//😖️
//🤯️
//❓️
/*
   char ch1 = getc(file1);
   char ch2 = getc(file2);
   int error = 0, pos = 0, line = 1;
   while (ch1 != EOF && ch2 != EOF){
      pos++;
      if (ch1 == '
' && ch2 == '
'){
         line++;
         pos = 0;
      }
      if (ch1 != ch2){
         error++;
         printf("Line Number : %d \tError"
         " Position : %d 
", line, pos);
      }
      ch1 = getc(fp1);
      ch2 = getc(fp2);
   }
   printf("Total Errors : %d\t", error);
   */
}

//-----------------------------
const int blockSize0 = 4096; 

int returnblockSize0(){
return blockSize0 ;
}


int countAllBlocksInBuffer(char *buffer,int bufferSize){
// count blocks 
}

int countAllCharsInBuffer(char *buffer,int bufferSize){
//👨‍🚀️
// this is almost right, but dont loop thru entire , just go "blocksize*count(=1++) + 1" 
// and compare 2 "int=0"cuz thats wut mt is <3
// you will still get a count just *blocksize... count all 4 debug w/e
//👨‍🚀️
int i = 0 ; 
char b2s[1];
 int result;
 int number0;
 
  printf("str out: \n");

while(i < bufferSize){

 number0 = (int)(buffer[i]);
/* 
 if(i = 8){
   printf("asciidebug =%d \n", number0);
   exit(46);
 }
*/

if (number0 == 0 ){
//if (number0 != 46 ){ ] on
 printf("asciidebug cnt =%d \n", i);
 return i ; 
//exit(36);
}

i++;
 
 }

return i ; 
}
//////
///===================================📦️
 int createMtSpace(int writePosition,int writeLength,char *buffer){
 int i = 0; 
 while(i < writeLength){
 
 buffer[writePosition + i] = '0' ;  //48; 
 // is fine but would it be better as "0"'s? w/e 
 i++;
 }
// return buffer ; 
 }

 //////////------------📦️

void defragmentThe_FS(){

// if u dont like them being out of order or w/e 
// u can do like windows and "defrag FS/disk"
// and it would just align fileFS into order of ops or w/e 
// instead of being fragmented...
// (as opposed 2 doing it "live" w/e )
// then if u NEED 2 do it live for somereasno (debug...)
// u can just run "defrag()" after each write or w/e  
}
//🦸‍♂️️
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//=================================🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️🦸‍♂️️
//
//////////💾️💾️💾️💾️💾️💾️💾️💾️💾️💾️💾️


void Std_createSuperBlock_H(char *emptyFile){

//emptyFile = malloc(sizeof(std_superBLockFilenameDisk_H));
// this just causes problems i guess strcpy is good enough.

strcpy(emptyFile, std_superBLockFilename_H);


struct stat st = {0};
int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H);

//int result = mkdir("fs/00000000.pro", 0777);
if (stat("disk[0000]", &st) == -1) {
    mkdir("disk[0000]", 0700);
}else{

///////////////
printf("\n disk[0000] already exists, not making another;return0 \n");
return 0 ;
///////////////
}
//////
exit(0);
////////////
if (access(emptyFile, F_OK) == 0) {
    // file exists
    // probably just return / exit
    return 0 ;
} else {
    // file doesn't exist
}
 
 

 fd = open(emptyFile, O_RDWR | O_APPEND | O_CREAT, 0777);
int bitsRead = read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

createMtSpace(0,stdBlockSize_H,local_BlockBuffer_0);
// this can create txt file . there is only 1 
//super block per file system. 3rd links can encompass...
// make txt file and put it in "/fs/"
// do it in 101.]🪄️
//step 1 . make file
/////////
//🪜️🪜️🪜️🪜️🪜️🪜️🪜️🪜️
//
//write2Position_0000(int writePosition,char *buffer,  char *payload , int returnLength  )

//🦸🏿‍♀️️[superblock, groupdescriptors,reserved GDT blocks ] < unmoving

//🚧️ext superblock structure = 
//🚧️ext groupdescriptor structure = 

//🦹🏿‍♀️️[block bitmaps][inode bitmaps][inode tables][datablocks]<move
//🚧️ext blckbitmap structure = 
//🚧️ext inodebitmap structure = 
//🚧️ext inodetable structure = 

//⁉️where does "FILE NAME" go.
//U NEED 2 TREAT /DISK💾️ AS 'ROOT/DIR'
// THEN FILENAMES ARE STORED IN 'DIR BLOX'OPTIONAL HASHING 4
// INSTEAD OF STRING SCAN LOOKUPS *MORE THAN 64 ASCII BITS...😏️
//😍️
//💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️💯️
//https://cscie28.dce.harvard.edu/lectures/lect04/6_Extras/ext2-struct.html 
//https://www.cs.unibo.it/~renzo/doc/so/fs/ext2-walkthrough.pdf
//➕️
//Explains how directory/filenames work <3(at VERY bottom)
//http://www.science.smith.edu/~nhowe/262/oldlabs/ext2.html
//directory is a "data block" *ie file, get it? 
// u will make "root dir file when u make super block , get it?
//*we dont have any "actual files yet"
// 
//=[FIN]
//➕️
// thEsE explains EVERTHING . use thEs.//💯️💯️💯️💯️💯️💯️💯️💯️💯️

//🐠️where are "processes supposed 2 be stored" (like kbd mem etc)
// 🐠️there not "files , like save and load..."
//🐠️theoretically its ur program... so if u wanna make a dir 4 it
// 🐠️ thats on u imo , just like : `sudo cat /tmp/event*.log`

// 🐠️ surely they MUST still go in superblock
//

//📟️
// u may make a dirchek later that when u restart(load) filesystem
// if u deleted a file/dir "either it deletes from [fs] OR 
// repopulates (re-saves) physically... 
// then u can make cli commands that are auto as well... 
// so just artchitect 4 that upfront.
// process memory can be deleted from temp , it can be reused
// if not deleted (same as file . so thats ur gameplan imo
// its not complicated as it sounds 
//ur doing this anyways.(4save/load)
// temp files can intentionally remain binary 
// but save load files can auto render as ascii (
// then u can get "best of both worlds"
//🗄️{
//that is a process that can run independantly if u wanna
// move fs and get phy output (but u dont need it right now...)
//}🗄️
// just, kiss , since u would hate 2 have 2 rewrite 2 much 4 STRAP
// if u think u can just do "kernel mem with no FS, then 'no files'
// just do it right.
//🔭️(we can always steal lib fx later 4 'c.halo')🔭️
//📟️
//😍️
int std_SuperBlock_bitmapPos_H = 8; 


//✍️
//write2Position_0000(j *16 ,returnChar,local_AsciiBuffer_0,16);
//✍️
//🪜️🪜️🪜️🪜️🪜️🪜️🪜️🪜️🪜️🪜️



 fd = open(emptyFile, O_RDWR | O_TRUNC | O_CREAT, 0777); //if i dont

//write(fd, buffer2 , stdBlockSize_H); //
write(fd, local_BlockBuffer_0 , stdBlockSize_H);
close(fd); 

///////
free(local_BlockBuffer_0);

//return 0;
}

int Std_BlockInt ; 
char *Std_NewBlockString[16]; // 16+.pro ( PLUS DIR!! + mt w/e
char Std_FullBlockString[32]; //👨‍🚀️no * for 'multstrcatting"
char *Std_ProFileDir = "disk[0000]/"; //8//were not storing "EMOJI" as binary ;) 
char *Std_ProFileTag = ".pro"; 
///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️

//////////////////🦸‍♂️️
//////////////
///🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️(move this up 
int STD_txtFS_SB__indoecount_offset_H = 0; //8x4(32) in ext2
int STD_txtFS_SB_blockcount_offset_H = 16; // 

int STD_txtFS_SB_fieldlength_bin_H = 16; // 
///🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️🔝️(move this up 
//////////////////🔬️🦸‍♂️️
int Std_read_block_count_H(char *superBLock_filename_H_1){

int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H); //where FREE()?


fd = open(superBLock_filename_H_1, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

// 
//🏣️🏣️🏣️🏣️🏣️🏣️🏣️🏣️[MICRO OFFSETS]🏣️🏣️🏣️🏣️🏣️🏣️🏣️
//Table 3-3. Superblock Structure
//Offset (bytes)	Size (bytes)	Description
//0	4	s_inodes_count
//4	4	s_blocks_count  //THESE ARE SAME THING TBH USE ONLY 1
//8	4	s_r_blocks_count //THESE ARE SAME THING TBH USE ONLY 1

char *local_BlockCountBinary = malloc(STD_txtFS_SB_fieldlength_bin_H);


readFrom_Position(STD_txtFS_SB_blockcount_offset_H,local_BlockBuffer_0 ,local_BlockCountBinary,STD_txtFS_SB_fieldlength_bin_H );

//int blockCount; 
 int blockCount = bin2dec(local_BlockCountBinary); 
return blockCount;

}
/////////////////////////🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️🧠️
int Std_read_inode_count_H(char *superBLock_filename_H_1){

int fd;

printf("Std_read_inode_count_H)🧟️➕️➕️❗️\n");

printf("testMalloc_0...➕️➕️➕️ START[-0003]\n");
char *testMalloc_0 = malloc(256);
//char *testMalloc_1 = malloc(256);
free(testMalloc_0);
//free(testMalloc_1);
printf("testMalloc_0...➕️➕️➕️ END\n");

//4.12.24
//📍️this is where we are, switching these out gives diff outputs 
// but same result. something isn't being null terminated is my guess. 
// will just swap this with editor after so that should work 2 <3 
//char local_BlockBuffer_0[256];
char *local_BlockBuffer_0 = malloc(stdBlockSize_H); //where FREE()?
//corrupted top size
//❗️ ok wtf...end this folly❗️
printf("local_BlockBuffer_0)🧟️➕️➕️\n");
fd = open(superBLock_filename_H_1, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

// 
//🏣️🏣️🏣️🏣️FFF🏣️🏣️🏣️🏣️[MICRO OFFSETS]🏣️🏣️🏣️🏣️🏣️🏣️🏣️
//Table 3-3. Superblock Structure
//Offset (bytes)	Size (bytes)	Description
//0	4	s_inodes_count
//4	4	s_blocks_count  //THESE ARE SAME THING TBH USE ONLY 1
//8	4	s_r_blocks_count //THESE ARE SAME THING TBH USE ONLY 1
printf("local_BlockCountBinary)🧟️➕️➕️ 🏚️🏚️🏚️\n");

char *local_BlockCountBinary = malloc(STD_txtFS_SB_fieldlength_bin_H);
//char *local_BlockCountBinary = malloc(16);
printf("local_BlockCountBinary)🧟️➕️➕️☘️ NATTY \n");

readFrom_Position(0,local_BlockBuffer_0 ,local_BlockCountBinary,STD_txtFS_SB_fieldlength_bin_H );

//int blockCount; 
 int blockCount = bin2dec(local_BlockCountBinary); 
return blockCount;

}
////////////
//🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️
//🏴️🏴️🏴️🏴️🏴️🏴️🏴️
int Std_inc_inode_count_H(char *superBLock_filename_H_1){
printf("in task...🧟️➕️➕️\n");
int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H); //where FREE()?
char *local_BlockCountBinary = malloc(16);

/////////////////////////
int blockCount =  Std_read_inode_count_H(superBLock_filename_H_1); 

blockCount++;

converttobinaryMalloc2(blockCount,  local_BlockCountBinary , 16); 

// convert 2 decimale , incriment , convert back 2 bin , doneFX().
////////

printf("local_BlockCountBinary ❓️\n %s",local_BlockCountBinary);

fd = open(superBLock_filename_H_1, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

    write2Position_0000(0,local_BlockBuffer_0,  local_BlockCountBinary ,STD_txtFS_SB_fieldlength_bin_H );

 fd = open(superBLock_filename_H_1, O_RDWR | O_TRUNC , 0777); //if i dont TRUNC appends


write(fd, local_BlockBuffer_0 ,stdBlockSize_H); //
close(fd); 
///////////////
free(local_BlockBuffer_0);//🇺🇸️
int newReadInodeCount =  Std_read_inode_count_H(superBLock_filename_H_1); 
return newReadInodeCount ; 

}
//🏴️🏴️🏴️🏴️🏴️🏴️🏴️
//🏴️🏴️🏴️🏴️🏴️🏴️🏴️
void Std_inc_block_count_H(char *superBLock_filename_H_1){

int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H); //where FREE()?
char *local_BlockCountBinary = malloc(STD_txtFS_SB_fieldlength_bin_H);

/////////////////////////
int blockCount =  Std_read_block_count_H(superBLock_filename_H_1); 

blockCount++;

converttobinaryMalloc2(blockCount,  local_BlockCountBinary , STD_txtFS_SB_fieldlength_bin_H); 

// convert 2 decimale , incriment , convert back 2 bin , doneFX().
////////

fd = open(superBLock_filename_H_1, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

    write2Position_0000(STD_txtFS_SB_blockcount_offset_H,local_BlockBuffer_0,  local_BlockCountBinary ,STD_txtFS_SB_fieldlength_bin_H );

 fd = open(superBLock_filename_H_1, O_RDWR | O_TRUNC , 0777); //if i dont TRUNC appends


write(fd, local_BlockBuffer_0 ,stdBlockSize_H); //
close(fd); 
///////////////
free(local_BlockBuffer_0);//🇺🇸️

}
//🏴️🏴️🏴️🏴️🏴️🏴️🏴️

//🧠️🧠️🧠️®️®️®️🧠️🧠️🧠️®️®️®️🧠️🧠️🧠️®️®️®️
// confusing ; but important. better dox? 
int Std_register_block_Inode(char *returnProDirString_R){
printf("in task(Std_register_block_Inode)?🧟️➕️➕️\n");
// wuts going on here. when does inode increment? ⁉️3.25.24
printf("obv breaks here)🧟️➕️➕️\n");
// have to open first inode (blank as of now) anyways
int read_inode_count = Std_read_inode_count_H(std_superBLockFilename_H);
printf("post(Std_read_inode_count_H)🧟️➕️➕️\n");
int Std_BlockCountInt = Std_read_block_count_H(std_superBLockFilename_H);

 Std_BlockCountInt--;
int Std_inodeCountInt = Std_BlockCountInt- 1;
printf("pre(printf)🧟️➕️➕️\n");
printf("Std_inodeCountInt 4 inode -1 = %d \n", Std_inodeCountInt );
    //6 blocks b4 first inode = file name offset
                  // is this actually best way 2 get inode#000.pro??   
          // inode can move it it gets full , but is ok for now 4 SURE
          // because no more blocks will be made b4 THIS inode
          // next inode maybe we will add inode offset 
          
       //   char *inode_filebinary[stdPronameSize_H];
       char *local_BlockCountBinary = malloc(STD_txtFS_SB_fieldlength_bin_H);   
int nested_inode_offset_addr_INT = 0 ;    //🔭️(4 clarity)    
                             
                                
converttobinaryMalloc(Std_inodeCountInt  , local_BlockCountBinary, 16); 

printf("Std_NewBlockString - 1 is inode = %s \n",local_BlockCountBinary );

char local_InodenameString_0[32]; //👨‍🚀️no * for 'multstrcatting"

///////////
///////////
///////////

printf("pre(Std_createDirProStringFromBin)🧟️➕️➕️\n");
Std_createDirProStringFromBin(local_BlockCountBinary, local_InodenameString_0); 
printf("local_InodenameString_0 = %s \n",local_InodenameString_0);

int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H);

fd = open(local_InodenameString_0, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 


// dont need a filename string. just the fileNo (no .pro)
//char local_FilenameString_0[32]; //👨‍🚀️no * for 'multstrcatting"

char *local_NewBlockString[stdPronameSize_H]; 

converttobinaryMalloc(Std_BlockCountInt, local_NewBlockString, stdPronameSize_H);

local_NewBlockString[stdPronameSize_H] = '\0';

printf("local_NewBlockString @register = %s \n",local_NewBlockString);
 
 printf("local_BlockBuffer_0 = %s \n",local_BlockBuffer_0);
 
 
//strcpy(local_FilenameString_0, Std_ProFileDir);
//strcat(local_FilenameString_0, local_NewBlockString);
//strcat(local_FilenameString_0, Std_ProFileTag);

int inodeOffset = 32; //64 + 16;

int inodeMult = read_inode_count * 16 ; 

// writing 2 inode . duh . skipping 2  12 + 
// int write2Position_0000(int writePosition,char *buffer,  char *payload , int payLength  )
//write2Position_0000(inodeOffset,local_BlockBuffer_0, local_NewBlockString, STD_txtFS_SB_fieldlength_bin_H  );

//char *test16 = "1111000011110000\0";
printf("pre(write2Position_0000)🧟️➕️➕️\n");
write2Position_0000(inodeOffset,local_BlockBuffer_0, local_NewBlockString, STD_txtFS_SB_fieldlength_bin_H  );
// just relized last arg in write2 is "payload length"

// inode maybe in pre corrupt form? 

// need  to creat inode string based on "std dir ,std tag
 printf("new local_BlockBuffer_0 = %s \n",local_BlockBuffer_0);
 
 
 fd = open(local_InodenameString_0, O_RDWR | O_TRUNC | O_CREAT, 0777); //if i dont

//write(fd, buffer2 , stdBlockSize_H); //
write(fd, local_BlockBuffer_0 , stdBlockSize_H);
close(fd); 


Std_createDirProStringFromBin(local_NewBlockString,returnProDirString_R);       //

printf("out task(Std_register_block_Inode)🧟️➕️➕️\n");

return read_inode_count; 
}
//🧠️🧠️🧠️®️®️®️🧠️🧠️🧠️®️®️®️🧠️🧠️🧠️®️®️®️
//🦾️
void Std_createDirProStringFromBin(char *binString,char *dirProString ){

// this shouldn't be done manually each time 

strcpy(dirProString, Std_ProFileDir);
//strcat(Std_FullBlockString, Std_ProFileDir);

strcat(dirProString, binString);

strcat(dirProString, Std_ProFileTag);

//printf("Std_FullBlockString = %s \n",Std_FullBlockString);

}

//🦾️
// instead of doing this im just gonna ask
//Std_createProBlock_H 0 or 1 if it should go in inode (most will be 1)
// it can be  blank i believe so w/e 

// u can actually call Std_register_block_Inode, from below = redun.do out
//🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️🔧️
/////////////////////////////////////////////
//////////////////🔬️🦸‍♂️️
int Std_createProBlock_H(char *superBLock_filename_H_1,char *blockfilename_Array_Arg){

int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H);

//🦸‍♂️️


int Std_BlockCountInt = Std_read_block_count_H(blockfilename_Array_Arg);//0; //🦸‍♂️️this will read block count and make accordingly 
////🦸‍♂️️super block will be block zero etc. ez
 //🦸🏽‍♂️️,its count not bitmap . so u dont have to do "SUPER - MANUALLY)

converttobinaryMalloc(Std_BlockCountInt, Std_NewBlockString, 16); 


printf("Std_NewBlockString = %s \n",Std_NewBlockString);


//just register what u need 2 keep going
// we will check 2 see if process exists first 
//(by name / file hash < IF IT MAKES NO SENSE 
// DONT DO IT JUST MAKE NEW PROCESS
// WE WILL ONLY CHECK IF UR TRYING 2 LOAD 📰️
// BY LITERALLY PASSING AS ARG a "PRO BLOCK"(same as b4
// just take it slow u will get there 

// u may need 2 check bitmap but dont yet. 
// just make process and put it in super block
// CUZ RIGHT NOW WE HAVE --NOTHING---❗️
// we do HAVE 2 CREATE A FILE NAME(BIN#) + .PR0
// SO WE WOULD CHECK BITMAP. BUT FOR NOW ASSUME WE KNOW IT
//JUST CREATE DATABLOCK FIRST , THEN RETRO GIVE IT INODE
// ETC

//🦸🏿‍♀️️[superblock, groupdescriptors,reserved GDT blocks ] < unmoving

//🦹🏿‍♀️️[block bitmaps][inode bitmaps][inode tables][datablocks]<move


//STD_makeNewBlockString(Std_NewBlockString); //fx() that makes bin#.pro 



//Std_NewBlockString[16] = '\0';

//snprintf(Std_FullBlockString, 32,"%s%s%s",Std_ProFileDir,Std_NewBlockString,Std_ProFileTag);

strcpy(Std_FullBlockString, Std_ProFileDir);
//strcat(Std_FullBlockString, Std_ProFileDir);

strcat(Std_FullBlockString, Std_NewBlockString);

strcat(Std_FullBlockString, Std_ProFileTag);

printf("Std_FullBlockString = %s \n",Std_FullBlockString);



fd = open(Std_FullBlockString, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, local_BlockBuffer_0, stdBlockSize_H);
close(fd); 

createMtSpace(0,stdBlockSize_H,local_BlockBuffer_0);

 fd = open(Std_FullBlockString, O_RDWR | O_TRUNC | O_CREAT, 0777); //if i dont

//write(fd, buffer2 , stdBlockSize_H); //
write(fd, local_BlockBuffer_0 , stdBlockSize_H);
close(fd); 

strcpy(superBLock_filename_H_1, Std_FullBlockString);
// u can move this 2 header whenever ]✅️
//101.fs-run]🪄️]0000.c can call "Std_makeSuper , will make 00
// and bitmap can do the counting
// u can leave 100🪄️. + 11000's and just start fresh with 0000.pro
//🙄️their being kvnts cuz they can 🧹️ acting like i could have done
//all this from ground up but revngn/bootstrap is the way most of this
// will taekplace , even solpen/musicprod is like that🙄️
//👍️its coming 2 gether, ur arkatechting well <3 🎖️

free(local_BlockBuffer_0);//🇺🇸️
}

char Std_defaultInodeName[64];
/////
//////////////////🧠️🧠️🧠️🧠️🧠️🧠️🧠️📌️
int Std_createInode_H(char *superBLock_filename_H_1){

// honestly u shouldnt need any args
// cuz superblock never changes name (w/e btw)
//can be a local constant tho
//if u need args add them when needed

int fd;
char *local_BlockBuffer_0 = malloc(stdBlockSize_H);

//🦸‍♂️️

// first create default file name (read++ SBinode count 
// inode[0000].txt <<can change when u 'saveFILE'
int read_block_count = Std_read_inode_count_H(superBLock_filename_H_1);

}
///////🧠️🧠️🧠️🧠️🧠️🧠️
//🧟️.4.6.24📌️ pin 📌️
// if u ever write a fx() more than once it should be in 2nd in "HEADER" 
// and 1rst-removed soon. 
//🧟️
///4.8.24 <pulled from qi. shoulda been HEADER
int stdIncInodeAddBloc_H(char *filename_arg){
printf("in task...🧟️➕️\n");
system("./+x/0.pro.maqr+[🎫️]0001.+x");
//char local_InodenameString_0[32];
char local_proDirString_0[32];


//📌️4.12.24🧟️🧟️🧟️🧟️🧟️🧟️🧟️🧟️🧟️🧟️🧟️🧟️MALLOC 
int  local_inode_ct = Std_register_block_Inode(local_proDirString_0);
strcpy(filename_arg, local_proDirString_0); // 🧠️📁️/📄️
printf("out task...🧟️➕️\n");
Std_inc_inode_count_H(std_superBLockFilename_H); 

return local_inode_ct; 
}
////////////
///4.8.24 <pulled from qi. shoulda been HEADER
///⚙️
int STD_binBuff2inodes_H(int charCount ,char *binBuff,  char *filename_arg ){ 


printf("in task...🧟️\n");


printf("fd = ..%s\n",filename_arg);


////////

  char *stdBlockBuffer_1 = malloc(stdBlockSize_H ); //👺️this is prob?
 char *local_AsciiBuffer_1 = malloc(stdKbdAsciiSize_H);
///

int debugInodeLoopInt = 0 ; //🐞️
int fd ; 

printf("⚙️binBuff = %s \n📌️",binBuff );//✅️
 fd = open(filename_arg, O_RDWR | O_APPEND | O_CREAT, 0777);
read(fd, stdBlockBuffer_1, stdBlockSize_H);
 //🚨️🤯️
close(fd); 

/////////////


long long unsigned int localDropCount = 0;
 int global_inode_ct = 1 ;  //
  int global_ezPos_Iwise = 0 ; // can make more robust later.(LOAD FILE OFC)
  
    
   int bytecount = charCount / stdKbdAsciiSize_H; //❓️ is weird if char. 
   // i dont know why tho, i haven't got 2 that
   
   printf("⚙️bytecount = %d \n📌️",bytecount );//✅️
/////////////
  int i;
    int j; //do i need 2 add 2 get the 16 each?📌️❓️4.10.24🚑️
    //📌️❓️ if u can answer this u can fix fast. 
    for ( j = 0; j < charCount; j++) {} //🔄️ < is this the fix? 
    					//char/byte needs 2 swap ?
    					
    for ( i = 0; i < bytecount ; i++) {
    //changing char count 2 "byteCount"
    
   int debugInodeLoopInt = 0 ; //🐞️



   
   readFrom_Position(i * stdKbdAsciiSize_H   ,binBuff,local_AsciiBuffer_1, stdKbdAsciiSize_H); 
   
 //  local_AsciiBuffer_1[256] = '\0';
    printf("🥷️readFrom_Position = %d, %s\n",i,local_AsciiBuffer_1 );
    

   
    //1.basically this formula is jacked up cuz its making 2 many inodes. 
    //2.and the bottom one is jacked up cuz its writign PAST buffer limit
    //📮️bottom is fixed 4 sure. so if u inc inode 2 much that would be a problem
  
///////☄️☄️☄️☄️☄️☄️☄️☄️☄️☄️☄️☄️☄️☄️
//4.14. after it hits iff things start messing up , but they shouldn't ] it should be ez. 
//fix it once and for all . make the variables more solid and i can print them
// do it from scratch if u have 2 w/e 
int nodeLimit = ((stdBlockSize_H / 16) * global_inode_ct) -1;

if(i  > nodeLimit ){

//📌️ 📌️ 📌️ 📌️ 📌️ 📌️ 📌️ 📌️ 📌️ 4.12.24

//printf("(i * stdKbdAsciiSize_H) > (stdBlockSize_H * global_inode_ct) -1 );%d, %d🏈️\n",(i * stdKbdAsciiSize_H), (stdBlockSize_H * global_inode_ct) -1 );
//
global_inode_ct = stdIncInodeAddBloc_H(filename_arg) + 1 ;

//printf("exit(101);\n");

/*
if (debugInodeLoopInt > 0 ){
exit(101); //  //🐞️
// is is making another block for some reason... this formula is bad. needs 2 be rewritten. 
//it was written completely blind so w/e . do some printf's. will be ok in no time <3 *light tunnel*
}
debugInodeLoopInt++;
//
*/
}else{
// do nothing (normal stuff)

}

///////////
 fd = open(filename_arg, O_RDWR | O_APPEND | O_CREAT, 0777);
//
int bitsRead = read(fd, stdBlockBuffer_1, stdBlockSize_H);
 //🚨️🤯️
close(fd); 
//////////

/////

int subSum = (global_inode_ct -1 )  * (stdBlockSize_H / stdKbdAsciiSize_H  )  ;

int fullSum = (i * stdKbdAsciiSize_H ) - subSum ;

global_ezPos_Iwise = fullSum;
//int newSum = ((i * stdKbdAsciiSize_H ) / global_inode_ct )-1 ;

//int newSum = ((i * global_inode_ct ) * stdKbdAsciiSize_H ) -1 ;

int sumFix = i * stdKbdAsciiSize_H ;

printf("fullSum = %s📌️\n", fullSum);//🧟️📌️
  write2Position_0000(sumFix ,stdBlockBuffer_1,local_AsciiBuffer_1,stdKbdAsciiSize_H); 
//  write2Position_0000(i * 16 ,stdBlockBuffer_1,local_AsciiBuffer_1,stdKbdAsciiSize_H); 
  //
     fd = open(filename_arg, O_RDWR | O_TRUNC , 0777); //if i dont TRUNC appendsstdDropToProKbdMemstdDropToProKbdMem
printf("stdBlockBuffer_1🧟️_END = %s\n", stdBlockBuffer_1);//🧟️📌️
write(fd, stdBlockBuffer_1 ,stdBlockSize_H); //
close(fd);//לחם הפנים 


}
printf("past 4 smash check\n");


free(local_AsciiBuffer_1);
free(stdBlockBuffer_1);
}
  				//should be ez, just proof of ON
///////////////
///////🧠️🧠️🧠️🧠️🧠️🧠️

int std_rand(int lo , int hi){
srand(time(NULL));   // Initialization, should only be called once.(SEEDER)
//int r = (rand() % (0 - 100 + 1)) + 0  ;      // Returns a pseudo-random integer between 0 and RAND_MAX.
//  (upper - lower + 1)) + lower; 
int r =  rand() % (hi - lo + 1) + lo ;

//printf("ran = %d  \n",r );

return r ; 
}
///////////////////


///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️///🦔️🦔️🦔️🦔️🦔️🦔️🦔️🦔️
//int Std_createLinkedBlock_H(){}
////////////////////💱️
 int converttobinary(int number, char *returnPayload,int payloadBitsize){
 
// memset(returnPayload, 8, sizeof(returnPayload));
// returnPayload = malloc(payloadBitsize);
    int auxiliar = number;
    int i;
    int opSize = payloadBitsize -1 ; 

    for (i = 0; i < payloadBitsize; i++) {
    
        auxiliar = auxiliar >> i;
        if (auxiliar & 1 == 1){
            returnPayload[opSize-i] = '1';
        } else{
            returnPayload[opSize-i] = '0';
        }
        auxiliar = number;
    }
    returnPayload[payloadBitsize] = '\0';

return 0 ; 
}



 int converttobinary2args(int n, char *op){
    int auxiliar = n;
    int i;
//might wanna use size of instead. or w/e somehow these work...
    for (i = 0; i < strlen(op); i++) {
        auxiliar = auxiliar >> i;
        if (auxiliar & 1 == 1){
            op[strlen(op)-1 -i] = '1';
        } else{
            op[strlen(op)-1 -i] = '0';
        }
        auxiliar = n;
    }

}
////

int converttobinaryMalloc(long long unsigned int n, char *op, long long unsigned int mallocSize){

char *mallocCopy = malloc(mallocSize);
//op = malloc(mallocSize);
    long long unsigned int auxiliar = n;
    long long unsigned int i;

    for (i = 0; i < mallocSize; i++) {
        auxiliar = auxiliar >> i;
        if (auxiliar & 1 == 1){
            mallocCopy[mallocSize-1 -i] = '1';
        } else{
            mallocCopy[mallocSize-1 -i] = '0';
        }
        auxiliar = n;
    }
    
 //   printf("strlen = %ld \n",strlen(op)); 
    strcpy(op, mallocCopy ); 
   //  printf("strlen = %ld \n",strlen(op)); 
   free(mallocCopy);
    return 0; 

}

///
int converttobinaryMalloc2(long long unsigned int n, char *op,long long unsigned int mallocSize){

char *mallocCopy = malloc(mallocSize);
//op = malloc(mallocSize);
    long long unsigned int auxiliar = n;
  long long unsigned int i;

    for (i = 0; i < mallocSize; i++) {
        auxiliar = auxiliar >> i;
        if (auxiliar & 1 == 1){
            mallocCopy[mallocSize-1 -i] = '1';
        } else{
            mallocCopy[mallocSize-1 -i] = '0';
        }
        auxiliar = n;
    }
    
 //   printf("strlen = %ld \n",strlen(op)); 
    strcpy(op, mallocCopy ); 
   //  printf("strlen = %ld \n",strlen(op)); 
   free(mallocCopy);
    return 0; 

}
///////
////////////////////

///////////////////
//🏗️
//⚠️change name 2 : STD_asciiBufferToBinaryBuffer_16_H
std_RowArrayConvert(char *input, int original_size ,char *returnChar){
int j; 
char *local_AsciiBuffer_0[16];
for (j = 0; j < original_size ;  j++){
//char *local_AsciiBuffer_0  = malloc(16) ;
   //[16] ;
converttobinaryMalloc2(input[j] , local_AsciiBuffer_0, 16); 

//local_AsciiBuffer_0 = "1234567812345678";
write2Position_0000(j *16 ,returnChar,local_AsciiBuffer_0,16);


//free(local_AsciiBuffer_0);
}


}
//🏗️


//😃️😃️😃️😃️😃️😃️😃️
int std_binaryBuffer2Ascii(char *input, int returnChar_size ,char *returnChar){

int j; 
long long unsigned int c; 
char local_AsciiBuffer_0[16] ;


for (j = 0; j < returnChar_size ;  j++){
//fault!!🐞️
 std_getAsciiFromBuffer(j * 16,input,local_AsciiBuffer_0);
 //fault!!🐞️
 c = bin2dec(local_AsciiBuffer_0);
//fault!!🐞️ 
//printf("c = %c\n",c);
returnChar[j] = c ; 

//exit(99);
//write2Position_0000(j ,returnChar,c,returnChar_size);
// is times instead of division 2 make way easier
}
//printf("returnChar = %s\n",returnChar);
//exit(99);
}

int std_getAsciiFromBuffer( int position ,char *input,char *returnAscii){

int j; 
for (j = 0; j < 16 ;  j++){

returnAscii[j] = input[position + j] ;

}

//return 
}
//😃️😃️😃️😃️😃️😃️😃️






 //😇️ READPOS/WRITE POS ARE 'THE PRIMATIVES' ON WHICH HALO CAN BE BUILT😇️
 //😇️ JUST KEEP BUILDING OUT MEM FIRST CUZ ITS "PRIMATIVE" AND WE WILL HAVE 2 WRITE LESS CODE 4EVER😇️ 
  //wana new 1 that uses only 1 buffer not right now tho
  // and if u do , save old till 'monolith'
 int readFrom_Position(int readPosition,char *buffer ,char *returnChar, int returnLength ){
  int copyCount = 0; 
 while(copyCount < returnLength){
 returnChar[copyCount] = buffer[copyCount + readPosition] ; 
copyCount++;
//countDownDebug--; 
}};

////////
   int write2Position_0000(int writePosition,char *buffer,  char *payload , int payloadLength  ){

// this is write 2 position with no overwrites. ]2.13]24
// but maybe u wanted 2 overright the rest with zeros? shouldn't cuz it only writes payload size. 
// anyways we never really sorted this so just do wuts best given ur experience. 
// try 2 keep it simple as possible or this gets confusing FAST

  int copyCount = 0; 
while(copyCount < payloadLength){
buffer[copyCount + writePosition] = payload[copyCount] ; 
copyCount++;
}
 }
 ///
 
 write2Position_Malloc(int writePosition,char *buffer,  char *payload ){
 
 char *buffer2  = malloc(sizeof(buffer));
 ///strcpy(buffer2,buffer);
   int copyCount = 0; 
 
while(copyCount < strlen(payload)){

buffer2[copyCount + writePosition] = payload[copyCount] ; 
copyCount++;
}


strcpy(buffer,buffer2);
 free(buffer2);
 
// buffer[copyCount] = '\0';
 }
 
 
 
 // u may actually get the write position (from a multi block) doing some lseek magic  or something similar
  int write2Position(int writePosition,char *buffer,char *buffer2 ,  char *payload,int payloadLength ,int countedChars ){
  /*
  if(payloadLength == -1){
payloadLength = tidBitSize ; 
}
  */
  //❗️jan22
  //so many args!
  //bitsRead is "complete bs" if u want 'THAT' use 'countAllCharsInBuffer()'
  //payloadLength seems naivly redundant
  //❗️
  //❕️i NEVER use 3rd arg 4 "strncpy" = strcpy(buffer1,b0);
  strcpy(buffer2, buffer);
//  strncpy(buffer2, buffer, countedChars);//doing here maybe overkill if u can do it once in "src" but its auto here... w/e <3
  			//it also just makes sure we have "all the vars we need" 4 now...
  
  int copyCount = 0; 
  int countDownDebug = payloadLength ; 
while(copyCount < payloadLength){
//buffer2[copyCount] = buffer[copyCount + writePosition] // buffer[miniBufferOffset + copyCount];
buffer2[copyCount + writePosition] = payload[copyCount] ; 
copyCount++;
countDownDebug--; 
}
  
 // return buffer2;
  // it will just globally replace what was in minibuffer, u dont need to ="return val"
 }
 /*
 int writeToSpecificMemoryLocation(chain , block , ){
 
 //the kbd can "be in the blockchain, and blockchain in "ext2"how?
 //we want the "fs blockchain protect but were not actually gonna "mine it or inc it 2 next blk
 // its all for "show/safety"
 //we will do real blockchain "IN FS" does that make sense?(mimicing macro blkchain...
 }
 */
 
 // FOR BLOCKSIZE CREATION ? 
 // irather use MEMORY HEADER TO SET "LOCAL CONSTANT"
 //blocksize can change, in same blockchain afterall
 //(its good 2 know how 2 program blockchain well. <3
 // were creating something new so dont sweat it.
 // u can read blocksize*blocksminted and see if theirs empty dots, or else run 2 make more
 //
 
 
// Funtion removing spaces from string


// u can make these headers at ur leisure. 
// the theory is that their just "tangential fx"
// i think the messed up thing is when headers include other headers
// that are literally in another file in a c file etc. u would'nt do that
// altho i dont hate the fx being local either


 int bufferCutter(char *buffer,char *miniBuffer , int miniBufferOffset, int size){
/// we cut off "front and back of kbd mem" from buffer , then we dont "NEED"
// 2 "add offsets in "circularBufferKbd()", and we can use "SHIFTING"
int copyCount = 0; 

while(copyCount < size){
miniBuffer[copyCount] = buffer[miniBufferOffset + copyCount];
copyCount++;
}
miniBuffer[size] = '\0';
}


void rotate_str_right(char str[], int len, int n)
{
	char *tmp_str = (char*)malloc(n * sizeof(char));
	memcpy(tmp_str, str + len - n, n * sizeof(char)); // temporarily save tailing n characters
	memmove(str + n, str, (len - n) * sizeof(char)); // shift char array to the right
	memcpy(str, tmp_str, n * sizeof(char)); // prepend saved
	free(tmp_str);
}

/* rotate string to the left by n characters */
void rotate_str_left(char str[], int len, int n)
{
	char *tmp_str = (char*)malloc(n * sizeof(char));
	memcpy(tmp_str, str, n * sizeof(char)); // temporarily save leading n characters
	memmove(str, str + n, (len - n) * sizeof(char)); // shift char array to the left
	memcpy(str + len - n, tmp_str, n * sizeof(char)); // append saved
	free(tmp_str);
}
 
///

int bufferCutterHeader( char *buffer ,char *miniBuffer,int miniBufferOffset , int miniBufferLength ){
/// we cut off "front and back of kbd mem" from buffer , then we dont "NEED"
// 2 "add offsets in "circularBufferKbd()", and we can use "SHIFTING"
int copyCount = 0; 
while(copyCount < miniBufferLength){
miniBuffer[copyCount] = 'i';// buffer[miniBufferOffset + copyCount];
copyCount++;
}
//return miniBuffer;
}
//

int globalIntPrintTest(int globalTestInt){

//globalTestInt = 929;

printf(" globalTestInt = %d \n", globalTestInt);
}

///---------------
void removeSubstr (char *string, char *sub) {
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub))) {
        *match = '\0';
        strcat(string, match+len);
    }
    
    string[sizeof(string) - sizeof(sub) ] = '\0';
}


//////////=-------------------
char * removeSpacesFromStr(char *string)
{
    // non_space_count to keep the frequency of non space characters
    int non_space_count = 0;
 
    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != '.' && string[i] != ',' )
        {
            string[non_space_count] = string[i];
            non_space_count++;//non_space_count incremented
        }    
    }
    
    //Finally placing final character at the string end
    string[non_space_count] = '\0';
    return string;
}
 
 /*
int main()
{
    char string[] = "Edpresso:.Dev.,,.-Shot";
    printf("%s \n",string);
    printf("%s \n",removeSpacesFromStr(string));
    return 0;
}
*/
