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
extern int std_iNodeCountOffset_H;
///////////////
int main(int argc, char* argv[]){


    printf("reload🔫️ \n");
    
      int exit_status = WEXITSTATUS( system("./+x/2.load.asc.iinkez[⚙️☯️]0000.+x"));
    // system("./#.delete.disk🧼️.sh");
   //📍️this is just proof "DOX AS CODE" that u can reload, dont over think it. (u will rite new fxs)
     
     //system("./+x/0.pro.maqr+[🎫️]0001.+x");
     //📕️
     // maybe nice 2 have some dev-documentation on how 2 remake these etc.
      //📕️
     // ez 🔍️🔖️
     //0. get inode count? 
     //1. make new indoe 
     //2. load into inode 
     // 🐡️(by file name at some point?)
     //3. after u do this we can load 1rst filename (or default) but do this 1rst ;its riteway
    //4. fix inode code in 🦾️/🦄️ that auto sets 2 "1"
     //📕️
     //🔖️
    int inodeCountDubious = Std_read_iblox_count_H(std_superBLockFilename_H);
    //is it inode count or just iblock count? {now maybe time 2 clarify fx names+}
    // not sure cuz i didn't load more than 1 inode but i can.
    printf("iblox_count = %d\n", inodeCountDubious);
    //📮️it is indeed showing "block count for 1rst inode and not "INODE COUNT"
    //📮️📌️NOW! would be the time 2 fix that / nip in bud 🌹️no choice.
  
int read_block_count_XS = Std_read_block_count_H(std_superBLockFilename_H);
// is this always the same? if so just replace with "iblox ?📌️4.27.24
  printf("read_block_count_XS = %d\n", read_block_count_XS);
     //🔖️
     
     //📕️0.
     int realInodeCount = Std_read_FD_POS_count_H(std_superBLockFilename_H, std_iNodeCountOffset_H,STD_txtFS_SB_fieldlength_bin_H); //📌️
// should we just MAKE a generic "file position reader?"⁉️
// is this always the same? if so just replace with "iblox ?📌️4.27.24
  printf("realInodeCount🧠️ = %d\n", realInodeCount);
 
   /*
    realInodeCount = Std_inc_FD_POS_count_H(std_superBLockFilename_H, 32,STD_txtFS_SB_fieldlength_bin_H);
   printf("realInodeCount,inc'd🧠️ = %d\n", realInodeCount);
   */
    //📕️1.
    system("./+x/0.inode.maqr[🧠️🎫️]0000.+x");
    //
   realInodeCount = Std_read_FD_POS_count_H(std_superBLockFilename_H, std_iNodeCountOffset_H,STD_txtFS_SB_fieldlength_bin_H); //📌️
  printf("realInodeCount🧠️ = %d\n", realInodeCount);
        //2. load (first) into (new)inode 
     // 🐡️(by file name at some point?) [probably hash of file name but tbh same file names aren't allowed so maybe not. w/e u want.. where does it go u need 2look@ legend.]
     
     
     //📛️NAME? = directory . basically "1rst" inode is directory(technically 2nd 1rst is blank?)
     //then when it fills up u will link 2 next one the same way...
     //also what was all that "direct/ 1inderect 2indirect 3 indirect" stuff allabout? 
     //*not quite?(yes. quite)there can be mult directories (OFC)(not same as "GroupDescriptor")
     //📛️
}
 //📕️ //🏓️if ur every confused about "HOW 2 DO" u should probably look @ 🗺️ LEGEND🗺️  //🏓️
 //🌐️ https://wiki.osdev.org/Ext2 🌐️
 //🌐️ https://cscie28.dce.harvard.edu/lectures/lect04/6_Extras/ext2-struct.html 🌐️
 //🥽️ inode.pdf]7.0003 🥽️
 //https://docs.google.com/document/d/1PCPGKyO8nK70yoHv-qRD0PDSDwX3IUl1dDXGLJ33Yeo/edit
 //🥽️ inode.pdf]7.0003 🥽️
     // ez 🔍️🔖️
     //0. get inode count? 
     //1. make new indoe  
     //+. also make inode needs 2 inc in "module" (doesnt' currently)
     //2. load (chosen) into (new) inode 
     //4. fix inode code in 🦾️/🦄️ that auto sets 2 "1"
     
     // 🐡️(by file name at some point?)
     //📕️
