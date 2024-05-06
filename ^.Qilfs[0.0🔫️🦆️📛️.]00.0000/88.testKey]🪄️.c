//🪄️
// WHAT ACTUALLY IS THIS? 
// it represents "SCREEN AND GAME"
//point being u may have enuff information at this point
// to do w/e it is ur trying 2 do w/o "practice"
// meaning u may want 2 add "kbdlogger" 2 cli now
//😇️😇️😇️😇️😇️😇️😇️😇️😇️😇️😇️
// dont i want "FD/PID/tid"'s in "BINARY"? OFC i do 
// but just sit tight, we will get there <3 , no rush

//👨🏾‍🚀️seems the answer is "gettid()" btw 
// pid is somehow the same for all pthreads tid is diff.
// if u want u can name the files ur own "TID" tho 
//* 2.check-dir-inc-xid]🛒️]0000
//😇️😇️😇️😇️😇️😇️😇️😇️😇️😇️😇️

//🚫️🍴️🚫️ (its pthread)ur good

//http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html
//http://www.csc.villanova.edu/~mdamian/threads/hello.txt

//✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️
//🥇️
//*(so first u may want menu 2 "NEVER USE EXEC" , and be polling keybd or w/e 
//u need 2 do 
//[which they are scared off cuz we didn't do first try but is important ///NOW!] / sober up and do work. 
//🥇️
//✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️✳️


//dec3 - when u strcat " arg.txt"  make sure its " ">""./

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//🦸‍♂️️
char* superBLock_filename_H[64];
char* blockfilename_Array_H[64][64];


void * PrintHello(void * data)
{
    int my_data = (int)data;  
    

   // printf("\n Hello from new thread - got %d !\n", my_data);
  //  
    
char command1[50];

  // strcpy( command1, "./1.write.down.fd+arg]🦄️" );
   //  system(command1);
  
   
   // is this "arg" gonna pass right? not being a "PURE STRING"? 
   // or is it  a "STRING LITERAL"? 
   //ezsol
   //👨🏽‍🚀️
 //  https://stackoverflow.com/questions/30305619/passing-variables-to-system-function-in-c
    //👨🏽‍🚀️
    /*
    char bufCat[128];
sprintf(buf, "./1.kb2.fs]⌨️🗃️]0000.+x %s", blockfilename_Array_H[5]);
    
system(bufCat);
*/
 system("./+x/1.kb2.fs]⌨️🗃️]0000.+x");
//printf("finished pcommand");
    
    pthread_exit(NULL);
}

void * PrintBye(void * data)
{
    int my_data = (int)data;  
    

 //   printf("\n Hello from new thread - got %d !\n", my_data);
    
    
//char command1[50];

  // strcpy( command1, "./1.write.down.fd+arg]🦄️" );
   //  system(command1);
   //  system("./^.fd28bit-log+cliop🪄️⌨️])
   //system("./1.write-up-fd+arg]🦄️" );
   system("./+x/2.qi.lngn]🖌️🦾️]0000.+x");
   
   
//printf("finished pcommand");
    
    pthread_exit(NULL);
}

extern int stdKbdAsciiSize_H;
char *stdAsciiBuffer_0;
char *stdAsciiBuffer_1;

///
int externStringInit(){

stdAsciiBuffer_0 = malloc(stdKbdAsciiSize_H);
stdAsciiBuffer_1 = malloc(stdKbdAsciiSize_H);

}
///////////////////////

int proSetupUUIDs_0(){

  Std_createSuperBlock_H(blockfilename_Array_H[0]); // can pass in mt char here...
   
  Std_inc_block_count_H(blockfilename_Array_H[0]);
  
 Std_createProBlock_H(blockfilename_Array_H[1],blockfilename_Array_H[0]);// Group Descriptor🦸🏽‍♂️️

 Std_inc_block_count_H(blockfilename_Array_H[0]);
 
 Std_createProBlock_H(blockfilename_Array_H[2],blockfilename_Array_H[0]);//block bitmaps🦹🏿‍♀️️
 Std_inc_block_count_H(blockfilename_Array_H[0]);
 
 Std_createProBlock_H(blockfilename_Array_H[3],blockfilename_Array_H[0]);//inode bitmaps🦹🏿‍♀️️
 Std_inc_block_count_H(blockfilename_Array_H[0]);
 
 Std_createProBlock_H(blockfilename_Array_H[4],blockfilename_Array_H[0]);//inode tables🦹🏿‍♀️️
 Std_inc_block_count_H(blockfilename_Array_H[0]);
 
 Std_createProBlock_H(blockfilename_Array_H[5],blockfilename_Array_H[0]);//data block_0🦹🏿‍♀️️
 Std_inc_block_count_H(blockfilename_Array_H[0]);
 
 Std_createProBlock_H(blockfilename_Array_H[6],blockfilename_Array_H[0]);//data block_0🦹🏿‍♀️️
 Std_inc_block_count_H(blockfilename_Array_H[0]);

// i have realized that for now we dont need "UUID's"
// u can pass this proc 🤝️ blockfilename_Array_H[5] 🤝️ (4now)
}
//
int local_multiheadRunner(){

//⚠️this is off now. where is "FS" being made?
//system("./0.$&b.maqr[🦸‍♂️️🎫️]0001.+x");// does this even work this fast? 
// or do we need 2 do it seperate? / w8
// it can only pass out 1 uuid at a time, 
// u can check if fs exist and auto make, 
// or just do 2(3) diff functions is prob better
//ie make superblock first, then make "pro blocks, and pass uuid
// 2 the proc so they can self id, + if they need "parent uuid, 
// this was ALWAYS THE PLAN (cuz u dont need filename if u have uuid
// since their the same...
// im assuming inode keeps track of "filename 2 uuid"? 
//📮️DONT CARE
//I DUNNO IF EXTUSES UUID LIKE THAT BUT U SHOULD IF U WANT. 
// IT ACTUALLY UNDPINS THE IDEAS OF OUR ORIGINAL ARCHITECTURE
//(IT MAYBE A KERNLY THING OR W/E BUT W/E JUST DO IT
// THERES TOSN OF EXT2 FREESPACE, AND THINGS WE MAY NEVER USE
//📮️
// can pass in rand uuid later🔭️
int exit_status_0 = WEXITSTATUS(system("./+x/0.sb.maqr[🦸‍♂️️🎫️]0001.+x"));
//Std_inc_block_count_H(disk[0000]/0000000000000000.pro); // can get by uuid later🔭️

int std_sb_count = 4 ; 
int desired_procs = 1 ;  // for kbd buffer/all else =inodes 
// using kbd as a "KNOWN GLOBAL DEFAULT" 4 all prgs 4 now
for(int i = 0; i < std_sb_count + desired_procs  ; i++){
system("./+x/0.pro.maqr+[🎫️]0001.+x");
//Std_inc_block_count_H(disk[0000]/0000000000000000.pro);
}
//🧠️🧠️🧠️🧠️📌️
// inode maker. can start with header fx, then 
// move into a .c file if u need for some reason
//system("./0.inode.maqr[🧠️🎫️]0000.+x");

// moving this into "pro " it can make its own INODE
// by reading SB.inode count. w/e ez
//SB.addr NEVER CHANGES btw
///🦾️moving, shouldn't be here ideally
//system("./+x/0.inode.maqr[🧠️🎫️]0000.+x"); //110
///🦾️
//📅️2.23.24
//system("./+x/0.pro.maqr+[🎫️]0001.+x"); // first (and only) REAL PRO //111
// 📌️(i just turned ^this OFF , i think we need 2 do it "IN PRO"
//📅️2.23.24

//❗️ i didn't see this! (but i saw it register in inode, it just does nothing now...
//Std_register_block_Inode(); //®️🦄️

// i moved it 2 2.qi.lngn]🖌️🦾️]0000.c but i just remembered the reason we did i here and not in "PROC" is cuz there is a race condition "SOMEWHERE"
//👨🏽‍🚀️
///®️🦄️its not the end of the world, we can always move it back. & do externaly
//👨🏽‍🚀️
//📅️2.23.24
printf("test4key]🪄️] :exit 411 \n");

//exit(411);

//🧠️🧠️🧠️🧠️

}
//////////////
int main(int argc, char* argv[]){
externStringInit();
// to delete a dir? 2 lazy right now. maybe if we need it twice
// also u can literally call a bash script from here no one cares...
system("./#.delete.disk🧼️.sh"); // string should be put in header if it keeps changing/ regardless as
//https://stackoverflow.com/questions/5467725/how-to-delete-a-directory-and-its-contents-in-posix-c
//
int exit_status = WEXITSTATUS(system("./+x/0.fsmaqr]💾️🗄️.+x"));

//local_multiheadRunner();
//exit(11);

    int rc;
    pthread_t thread_id;
    
     int rc2;
    pthread_t thread_id2;

    int t = 11;

    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t);
    if(rc)
    {
//      printf("\n ERROR: return code from pthread_create is %d \n", rc);
      exit(1);
    }
  //  printf("\n Created new thread (%u)... \n", thread_id);
    
    
     rc2 = pthread_create(&thread_id2, NULL, PrintBye, (void*)t);
    if(rc)
    {
   //   printf("\n ERROR: return code from pthread_create is %d \n", rc);
      exit(1);
    }
 //   printf("\n Created new thread (%u)... \n", thread_id);
    
    
    
    
    
char command[50];

  // strcpy( command, "./1.write-up-fd+arg]🦄️" );
 // strcpy( command,  thread_id);
 ///    system(command);
// system("./^.fd28bit-log+cliop🪄️⌨️])
//system("./1.write.down.fd+arg]🦄️");
printf("100.mom4key]🪄️]0002 :finished commands \n");
    pthread_exit(NULL);
    
    
 ///////////////
free(stdAsciiBuffer_0);
free(stdAsciiBuffer_1);
///////////////
    return 0; 
}

