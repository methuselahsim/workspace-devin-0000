//🗃️

//🦄️
// we are just writing dummy data 2 
// first inode position 
// we can sus out the rest later 
// it isn't gonna just "dev up in a linear fashion"
// we want dummy data, we will wrap in blockchain 
// then take new change at same mem position or w/e 
// and merge diff 

//BLOCK HEADER STRUCTURE : 
//[[VERSion(4by)][Previous block hash(32by)][Merkle Root(32by)][Timestamp secs from gen+date (4)][Difficulty index(4)][nonce(4)][padding(48)]]

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/poll.h>
#include <termios.h>

#include <fcntl.h>  
#include <errno.h>
#include <stdint.h>

int buildInt;
 // wont let me malloc buffer0 size 4 w/e reason w/e
			//it means when u think its doing it , its fake...
	/*
char buffer0[40960];
char buffer1[40960]; 

char miniBuffer[64];
char miniBuffer2[64];
char kbdBuffer[64];
*/
// char countingChars[64] ;

//extern int stdKbdCountSize_H;
extern int stdBitByteSize_H ; 

extern int stdBufferSize_H ; 
//////
extern int stdProcTimeOffset_H ; 
//extern int stdKbdInOffset_H ;



///extern int stdKbdCountOffset_H;
extern int stdKbdAsciiSize_H;
extern int stdKbdBufferOffset_H;

extern int stdBlockSize_H  ;
extern int stdShiftBufferSize_H;
extern int stdProcLoopCountSize_H ;
extern int stdProcLoopCountOffset_H ; 
//////////
//🦸‍♂️️
extern char std_superBLockFilename_H ;

char *stdBlockBuffer_0;
char *stdBlockBuffer_1;
char *stdShiftBuffer_0;
char *stdAsciiBuffer_0;
char *stdProcCountString_0;
///
int externStringInit(){
stdBlockBuffer_0 = malloc(stdBlockSize_H );
stdBlockBuffer_1 = malloc(stdBlockSize_H );
stdShiftBuffer_0 = malloc(stdShiftBufferSize_H);
stdAsciiBuffer_0 = malloc(stdKbdAsciiSize_H);
stdProcCountString_0 = malloc(stdProcLoopCountSize_H);
}
///
int c ;
int length_of_buffer = 0; 
int length_of_file = 0 ; 

char growing_list[1024];
char static_list[1];

char tmp = '.';

int sz;  
char snum[5];
 char op[8];
// char opMalloc[64] ;
///
// char fileName[] ; 
//char* fileName = "foo.txt";
 char* fileName[64]; // filename has 2 have bits assigned first or doesn't work
   // 
   
   char *tidLocation;
int tidIndex; 
/////////
char bintime32[32];
///////////////////


///
/*
void set_term_quiet_input()
{
  struct termios tc;
  tcgetattr(0, &tc);
  tc.c_lflag &= ~(ICANON | ECHO | IEXTEN); //ISIG https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html (9)
  // NOT DOING THIS RIGHT NOW
  // MAYBE IF THEY TEACH US COPY PASTE BUT THEY DONT...
  // WE  CAN VISIT THIS ON OUR OWN THEN.
  raw.c_iflag &= ~(IXON); // step 10]kilo
  
   raw.c_oflag &= ~(OPOST);
  tc.c_cc[VMIN] = 0;
  tc.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &tc);
  
  
}
*/
/////////////
struct termios orig_termios;

// die is supposed 2 be global or something...
void disableRawMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("tcsetattr");
}
void enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 0.5 ; //0.777; // 7 is fast...
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}
// is die supposed 2 be global or something...?
void die(const char *s) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);
  perror(s); // this prints error, but u dont have 2 do this ...
  exit(1);
}
////////////////

void append(char* s, char c) {
        int len = strlen(s);
       // length_of = len;
        s[len] = c;
        s[len+1] = '\0';
       // tmp = c ;
}

void replace(char* s, char c) {
        int len = strlen(s);
       // length_of = len;
        s[0] = c;
        s[len+1] = '\0';
        
      //  itoa(c, snum, 10); // base 10 ? base 2 !?
        
        // sprintf(snum, "%d", c);
        //  printf("itoa : %s\n", snum);
      //   converttobinary(c, op);
       
       // tmp = c ;
}

/////////

/*
  case 'A': return 128; //'w';
        case 'B': return 129; // 's';
        case 'C': return 130; // 'd';
        case 'D': return 131; // 'a';
*/
int myChara ; 
int myCharaCount; 
int myCharaNewCount; 
//////////////
char editorReadKey() {
myCharaCount++;
// this works on risc-v 2 but i dont want u testing it
// cuz file doesnt' transfer from hardrives well
// sometimes transfers "BLANK FILES!" yea u can see 
// how that may cause NIGHT MARES? 
// in future if we want 2 test we "MUST HAVE SSH" first. 
// so just build key-binds for x86 as "experimental" <3 



// //////
//4riscv = up = 132/D /a 
// down = 131/C / d
// left = 129/ A / w
// right = 130/B / s


//printf("buildInt = %d \n", buildInt);

  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1 && errno != EAGAIN) die("read");
    // may move die 2 header?(u dont have 2 die here...)
  }

  if (c == '\x1b') {
    char seq[3];

    if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
//if(buildInt == 8){

    if (seq[0] == '[') {
      if (seq[1] >= '0' && seq[1] <= '9') {
        if (read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
        if (seq[2] == '~') {
          switch (seq[1]) {
           case '1': myChara = 135; return 0;//return HOME_KEY;
           case '3': myChara = 137; return 0; //return DEL_KEY;
            case '4': myChara = 136; return 0;//return END_KEY;
            case '5': myChara = 133; return 0; // set 2 page up 
            case '6': myChara = 134; return 0; // set 2 page down
             case '7': myChara = 135; return 0;//return HOME_KEY;
            case '8':myChara = 136; return 0;//return END_KEY;
          }
        }
      } else {
        switch (seq[1]) {
          case 'A': //printf("A \n"); 
      myChara = 132; return 0; //'w';
        case 'B':// printf("B \n");
         myChara = 131; return 0; // 's';
        case 'C': //printf("C \n"); 
        myChara = 130; return 0; // 'd';
        case 'D':// printf("D \n"); 
        myChara = 129; return 0; // 'a';
        
        case 'H': myChara = 135; return 0;//return HOME_KEY;
          case 'F': myChara = 136; return 0;//return END_KEY;
        }
      }
    }else if (seq[0] == 'O') {
      switch (seq[1]) {
        case 'H': myChara = 135; return 0;//return HOME_KEY;
        case 'F': myChara = 136; return 0;//return END_KEY;
      }
    }





/*
 if (seq[0] == '[') {
      switch (seq[1]) {
      case 'A': //printf("A \n"); 
      myChara = 132; return 0; //'w';
        case 'B':// printf("B \n");
         myChara = 131; return 0; // 's';
        case 'C': //printf("C \n"); 
        myChara = 130; return 0; // 'd';
        case 'D':// printf("D \n"); 
        myChara = 129; return 0; // 'a';
      }
    }
*/

   // }
    
    /*
    if(buildInt == 5){
    if (seq[0] == '[') {
      switch (seq[1]) {
      case 'A': //printf("A \n"); 
      myChara = 132; return 132; //'w';
        case 'B':// printf("B \n");
         myChara = 131; return 130; // 's';
        case 'C': //printf("C \n"); 
        myChara = 130; return 129; // 'd';
        case 'D': //printf("D \n"); 
        myChara = 129; return 131; // 'a';
      }
    }}
*/
    return '\x1b';
  } else {
  myChara = c; 
    return c;
  }
}

////////////
int dropCount = 0; 

#define CTRL_KEY(k) ((k) & 0x1f)


//char * superBLockFilename_local = "fs[🗄️]/0000000000000000.pro";
char* superBLock_filename_H[64];
char* blockfilename_Array_H[64][64];

int main(int argc, char* argv[]){


  //strcpy(fileName,"foo.txt\0");
 // printf("start!");
  if (argv[1] != NULL){ 
//👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️👨🏽‍🚀️
   strcpy(fileName,argv[1]);
   }else{
   strcpy(fileName,"disk[0000]/0000000000000101.pro");
   }
   //🪄️🪄️🪄️🪄️🪄️🪄️
//exit(11);

buildInt = getArx();
   externStringInit();
//🗃️dont need args...
//🗃️ u can throw it but why?
//🗃️ if its not in the dir. make it using same fx header used...
//🗃️  or u can just scrap "FS maker in "99. but , theres no need.
/*
//🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️
	  if (argv[1] != NULL){ 
	//strcpy(argv1_st, argv[1]);
	//need to append .txt HERE not in other file
	//https://www.educative.io/blog/concatenate-string-c
	
	//strcat(fileName, txt); 
	//printf("%s \n", pid_argv1);
	tidLocation = strstr(argv[1], ".pro"); 
	
	// printf("Found string at index = %ld\n", tidLocation - argv[1]);
	  if (tidLocation != NULL){  
	  
	  strcpy(fileName,argv[1]);
	  
	  // then its a file , just write 2 " DEFAULT KBD POSITION
// otherwise we will add offset 2 "DEFAULT" ez=pz;)
	  // here we should just "set default file position and set argv as filename
	  }else{ 
	 // if not , then its a "mem address WAIT ON THIS RIGHT NOW < jan23
	 // and we will use "txt.0000]
	 // if "NO ARG. will use debug0000 ;) 
	 
	// strcpy(fileName,fileName_default);
	 exit(91);
	 }
     
	 }else{
	printf("no arg (exiting program? no mem alloc'd...)using debug \n");
	
	strcpy(fileName,"foo.pro");
	 exit(91);
	//strcpy(fileName,fileName_debug);
	// theres no "..."s so it wont write, but dont touch keys just ingnore <3❣️
	// theoretically we would have 2 create mem. 
	// but i longterm may have u just "exit(91);"
	//strcpy(fileName, superBLockFilename_local); //demo text 🧻️📌️
	};
//🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️🗃️❌️	
*/

    int fd = open(fileName, O_RDWR | O_APPEND | O_CREAT, 0777);
  //O_APPEND
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
    //    printf("\nFile %s opened sucessfully!@Q\n");
    }



   // int bitsRead = read(fd, responsibleBuffer_H, strlen(responsibleBuffer_H));
   read(fd, stdBlockBuffer_0, stdBlockSize_H);
 //int bitsRead = read(fd, buffer0, sizeof(buffer0));
     close(fd);
     
//printf("%d bf size!\n", sizeof(buffer0));
 //   printf("%d bytes read!\n", bitsRead);
 //   printf("File Contents: %s\n", stdBlockBuffer_0);
//printf("File Contents: %s\n", buffer0);
   ////////////////
    /////////
int flags = fcntl(fd, F_GETFL, 0);
fcntl(fd, F_SETFL, flags | O_NONBLOCK);


  struct pollfd pfd = { .fd = 0, .events = POLLIN };
//  set_term_quiet_input();
int loopState = 1; 
enableRawMode();
  while (loopState = 1) {
    if (poll(&pfd, 1, 0)>0) {
      // c = getchar();
     c = editorReadKey();
       ////////
       if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
       /////////
       
   //  printf("Key pressed: %c \n", c);
  // printf("Key myChara: %d \n", myChara);
    //   printf("Key pressedVAK+L: %d \n", c);
      //🗄️❌️there was NEVER an "argv[2] " 
      //🗄️❌️ so... i guess thisV never ran?
      /*
     if (argv[2] != NULL){ 
     
     fd = open(argv[2], O_RDWR | O_APPEND | O_CREAT, 0777);
int bitsRead = read(fd, stdBlockBuffer_1, stdBlockSize_H);
close(fd); 
    // myChara
   
    char cInt2Char[1] = "0\0" ; 
 cInt2Char[0] = (char) myChara ;
    
    write2Position_0000(dropCount,stdBlockBuffer_1,cInt2Char,1); 
       dropCount++;
        fd = open(argv[2], O_RDWR | O_TRUNC , 0777); //if i dont TRUNC appends

 printf("%c",cInt2Char);
write(fd, stdBlockBuffer_1 ,stdBlockSize_H); //
close(fd);
     }
     */
//append(growing_list, tmp);
//append(growing_list, c);
//replace(static_list, c);
 //converttobinary(c, op, sizeof(op)); 
   converttobinaryMalloc(myChara, stdAsciiBuffer_0, stdKbdAsciiSize_H); 
   
   
       
       // printf("binary : %s\n", opMalloc);
//printf("%s\n", growing_list);
//length_of_buffer = strlen(growing_list); // want prv ln
length_of_buffer++;
//printf("length = %d \n", length_of_buffer);
    
 
    }
    usleep(2222); // Some work 
    
    // putc(c, file);
    // check if char array is greater than 
    // last stored length if so print 2 file 
    // if not ignore this 
   
   // putc(c, file); /// works (2 often) (doesnt' work in while loop tho even tho while loop works !?!? 
    //
 
if(myCharaCount > myCharaNewCount){ 
// FILE *file = fopen("mt.txt", "w");
  length_of_file++; 
  
    converttobinaryMalloc2(myCharaCount,  stdProcCountString_0 , stdProcLoopCountSize_H); 
   // printf("myCharaCount %d\n",myCharaCount);
   //  printf("countingChars= %s \n",countingChars);
     
   // write2Position(stdKbdCountOffset_H , buffer0, buffer1 , countingChars , sizeof(countingChars));
   
   write2Position_0000(stdProcLoopCountOffset_H , stdBlockBuffer_0 , stdProcCountString_0, stdProcLoopCountSize_H);
   
   //stdProcCountString_0 = malloc(stdProcLoopCountSize_H);
   
    myCharaNewCount++;
  //
  //  strcpy(buffer0,buffer1);

//😇️🦄️
/*
rawSeconds(bintime32);
//int stdProcTimeOffset_H = 96 ; (was 94, accidently i assume
write2Position(stdProcTimeOffset_H , buffer0, buffer1 , bintime32 , sizeof(bintime32));

strcpy(buffer0,buffer1);
*/

//  char *stdBlockBuffer_0;
//char *stdShiftBuffer_0;
//readFrom_Position(0  , responsibleBuffer_H ,miniBuffer, 64);
readFrom_Position(stdKbdBufferOffset_H  , stdBlockBuffer_0 ,stdShiftBuffer_0,stdShiftBufferSize_H );
 //    printf("stdShiftBuffer_0= %s \n",stdShiftBuffer_0);	//🤩️
    
    
 //🗃️ commenting this out 4 "FS"
   rotate_str_right(stdShiftBuffer_0, stdShiftBufferSize_H,stdKbdAsciiSize_H );
   
   //🗃️
 //   printf("stdShiftBuffer_0x2= %s \n",stdShiftBuffer_0); //🤩️
  
  //🌋️currently messing up here. writing old buffer way 2 many times
  
 //  write2Position(stdKbdBufferOffset_H , miniBuffer, miniBuffer2 , opMalloc , 16);    
write2Position_0000(0 , stdShiftBuffer_0 , stdAsciiBuffer_0, stdKbdAsciiSize_H);
//miniBuffer2[64] = '\0';
//printf("write2Position= %s \n",stdShiftBuffer_0);//
//printf("write2Position= %s \n",stdAsciiBuffer_0);//🤩️

write2Position_0000(stdKbdBufferOffset_H , stdBlockBuffer_0 , stdShiftBuffer_0, stdShiftBufferSize_H);
 




 fd = open(fileName, O_RDWR | O_TRUNC , 0777); //if i dont TRUNC appends


write(fd, stdBlockBuffer_0 ,stdBlockSize_H); //
close(fd); 
//exit(11);
 

   if (c == 17){
   //17
   printf("escaping manually loopstate \n");
   die("read");
    //  break;
 //  end(91);
 //  loopState = 0 ; 
    }
    
// this is cute , and "ON" but it want scancodes in binary
//write(fd, tmp, sizeof(tmp));
  };
// update the lengthVAR here , or it will loop 
//forever 
           if (myChara == 17){
   //17
   printf("escaping manually loopstate \n");
   die("read");
    //  break;
 //  end(91);
 //  loopState = 0 ; 
    }
  }
//free(opMalloc);

/*
stdBlockBuffer_0 = malloc(stdBlockSize_H );
stdShiftBuffer_0 = malloc(stdShiftBufferSize_H);
stdAsciiBuffer_0 = malloc(stdKbdAsciiSize_H);
stdProcCountString_0 = malloc(stdProcLoopCountSize_H);
*/

free(stdBlockBuffer_0 );
free(stdShiftBuffer_0);
free(stdAsciiBuffer_0);
free(stdProcCountString_0);
    return 0;
  

}
