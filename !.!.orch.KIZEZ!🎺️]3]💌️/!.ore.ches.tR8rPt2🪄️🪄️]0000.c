#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// this is "LOTS OF STUFF HAPPENING"
// try 2 walk thru it like the "MACRO_EPOCH" is supposed 2 
// and make sure things are going ok
/*
🤫️🤫️🤫️
🤫️😭️🤫️
🤫️🤫️🤫️

*/
// i cant wait to change "corpus" to vocab
// query to corpus
// and output to query 

#define EPOCHS 1
int main(int argc, char *argv[]) {


  
  //➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️ 
   for (int i = 0; i < EPOCHS; i++) {
   

///////
printf(":./+x/1.5.query.embed]6]RARE.+x✔️\n");
system("./+x/1.5.query.embed]6]RARE.+x -1 f$+/answer_I.txt -2 f$+/query_embeds_2.txt");  //.txt only


printf(":./+x/2.pe]FIX]ON+.+x✔️\n");  //.txt only
system("./+x/2.pe]FIX]ON+.+x -1 f$+/answer_I.txt -2 f$+/positional_encoding_2.txt");  //.txt only
///////



///🥷️(sneaky cuz this one has "-tags"🔖️
printf(":3.concat]0]ON+.+x\n");  //.txt only
system("./+x/3.concat]0]ON+.+x -1 f$+/query_embeds_2.txt -2 f$+/positional_encoding_2.txt -3 f$+/resultant_2.txt");
//////////
 
///
 printf(":./+x/4.encode_qkv]32]+.+x✔️\n");  //.txt only
  system("./+x/4.encode_qkv]32]+.+x -1 f$+/resultant_2.txt -2 f$+/q_2.txt -3 f$+/k_2.txt -4 f$+/v_2.txt");  //.txt only
//
//✅️

 

///⁉️ isn't "V" supposed to come from "somewhere else? <yes🗜️
//⁉️ are they supposed 2 be same size ? padd/cutt? (not yet🗜️✳️
  //  maskED FLAG ! ADD IT . DO IT  ⛳️
   printf(":./+x/4.mMHA]VA5]1]0000.+x✔️\n");  //.txt only
  system("./+x/4.mMHA]VA5]1]0000.+x -1 f$+/q_2.txt -2 f$+/k_2.txt -3 f$+/v_2.txt -4 f$+/mha_2.txt -5 f$+/resultant_2.txt -+");



 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/mha_2.txt -2 f$+/resultant_2.txt -3 f$+/add_n_norm_2a.txt");
  ///////


////✳️NOW DO "THIS"🗜️

printf(":../+x/17.pad_cut]TOOL]2]FULL+.c.+x\n");  //.txt only
    system("./+x/17.pad_cut]TOOL]2]FULL+.+x -1 f$+/add_n_norm_0b.txt -2 f$+/add_n_norm_2a.txt -3 f$+/pad_cut_v_2.txt");  //.txt only
   //////////
 
   
    printf(":./+x/4.encode_qkv]32]de.+x✔️\n");  //.txt only
  system("./+x/4.encode_qkv]32]de.+x -1 f$+/add_n_norm_2a.txt -2 f$+/q_2b.txt -3 f$+/k_2b.txt -4 f$+/v_2b.txt -5 f$+/pad_cut_v_2.txt");  //.txt only
   

 // no mask
   printf(":./+x/4.mMHA]VA5]1]0000.+x✔️\n");  //.txt only
  system("./+x/4.mMHA]VA5]1]0000.+x -1 f$+/q_2b.txt -2 f$+/k_2b.txt -3 f$+/v_2b.txt -4 f$+/mha_2b.txt -5 f$+/resultant_2.txt --");
  
   
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/mha_2b.txt -2 f$+/resultant_2.txt -3 f$+/add_n_norm_2a.txt");
  ////
  
  
    printf(":./+x/6.feedforw]0002.+x✔️\n");
  system("./+x/6.feedforw]0002.+x -1 f$+/add_n_norm_2a.txt -2 f$+/ff_2.txt");
  //
  
  //
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/ff_2.txt -2 f$+/add_n_norm_2a.txt -3 f$+/add_n_norm_2b.txt");
  ////
  
  
  ///]
// did we do a linear and a softmax?!?! and ... how does it compare 2 
//20.? just for science purposes? very intersting phenom after all...
//20.soft.max=wordprob.c
// yes i will just fork "llout here 
  printf(":./+x/18.linear_n_softmax.+x✔️\n");  //.txt only
  system("./+x/18.linear_n_softmax.+x -1 f$+/add_n_norm_2b.txt -2 f$+/smout_2.txt -3 f$+/llout_2.txt");
  

  
  printf(":./+x/19.word_probe]30]ON!🏆️+.+x✔️\n");  //.txt only
  system("./+x/19.word_probe]30]ON!🏆️+.+x -1 f$+/index_0.txt -2 f$+/add_n_norm_2b.txt -3 f$+/weights_matrix_0.txt -4 f$+/answer_I.txt");
  
  
  printf("debug🏆️");
  exit(9);
  // were doing 2 diff word prob generators and comparing them 
  // tiny bit more work but DEF worth it! love it. 👩‍❤️‍👨️ 👩🏼‍❤️‍👨🏼️
   printf(":./+x/20.soft.maxISwordprob👩🏼‍❤️‍👨🏼️.+x✔️\n");  //.txt only
  system("./+x/20.soft.maxISwordprob👩🏼‍❤️‍👨🏼️.+x -1 f$+/llout.txt -2 f$+/index_2.txt -3 f$+/answer_2.txt");
  
}
// make a n "optionally masked, optionally multi head attn. either from 9.11 or from scratch <3
}



