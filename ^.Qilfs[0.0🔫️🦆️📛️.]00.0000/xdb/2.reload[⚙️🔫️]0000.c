//wussup?
//🔫️ probably doesn't need 2 be a "FILE" just a(few) header fx()
//☝️ however were using this 2 "CALL FROM " 2 test modularly☝️
//🗓️
//📆️
//🗓️
//🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️🏁️
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
////////////🦄️
////////
extern char *std_superBLockFilename_H; //🤩️
extern char *STD_txtFS_SB_fieldlength_bin_H; //🤩️
/////////////

///////////////
int main(int argc, char* argv[]){


    printf("reload🔫️ \n");
    
     int exit_status = WEXITSTATUS( system("./+x/2.load.asc.iinkez[⚙️☯️]0000.+x"));
    // system("./#.delete.disk🧼️.sh");
   //📍️this is just proof "DOX AS CODE" that u can reload, dont over think it. (u will rite new fxs)
     
     //system("./+x/0.pro.maqr+[🎫️]0001.+x");
     //📕️
     // maybe nice 2 have some dev-documentation on how 2 remake these etc.
     
     // ez ? 🔖️
     //0. get inode count? 
     //1. make new indoe 
     //2. load into inode 
     // 🐡️(by file name at some point?)
     //📕️
     //🔖️
    int inodeCountDubious = Std_read_iblox_count_H(std_superBLockFilename_H);
    //is it inode count or just iblock count? {now maybe time 2 clarify fx names+}
    // not sure cuz i didn't load more than 1 inode but i can.
    printf("inodeCountDubious? = %d\n", inodeCountDubious);
    //📮️it is indeed showing "block count for 1rst inode and not "INODE COUNT"
    //📮️📌️NOW! would be the time 2 fix that / nip in bud 🌹️no choice.
  
int read_block_count_XS = Std_read_block_count_H(std_superBLockFilename_H);
// is this always the same? if so just replace with "iblox ?📌️4.27.24
  printf("read_block_count_XS = %d\n", read_block_count_XS);
     //🔖️
     
     
     int realInodeCount = Std_read_FD_POS_count_H(std_superBLockFilename_H, 32,STD_txtFS_SB_fieldlength_bin_H); //📌️
// should we just MAKE a generic "file position reader?"⁉️
// is this always the same? if so just replace with "iblox ?📌️4.27.24
  printf("realInodeCount🧠️ = %d\n", realInodeCount);
  
 realInodeCount = Std_inc_FD_POS_count_H(std_superBLockFilename_H, 32,STD_txtFS_SB_fieldlength_bin_H);
   printf("realInodeCount,inc'd🧠️ = %d\n", realInodeCount);
   
   /*
    realInodeCount = Std_inc_FD_POS_count_H(std_superBLockFilename_H, 32,STD_txtFS_SB_fieldlength_bin_H);
   printf("realInodeCount,inc'd🧠️ = %d\n", realInodeCount);
   */
     
}
