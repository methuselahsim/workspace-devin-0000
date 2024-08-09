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
FILE *fp = fopen("f$+/answer_i.txt", "w"); // clears old answers
FILE *fp1 = fopen("f$+/answer_ii.txt", "w"); // clears old answers
///

//🦘️this is weird. should we "ONLY USE VOCAB" as "CORPUS"
//🦘️ there telling u 2 make both , then pull probabilites from vocab...
//🦘️ but theres not embeddings for vocab... {gonna look @ code}

printf(":./+x/0.sol.count]2]xp]ON+.+x✔️\n");
system("./+x/0.sol.count]2]xp]ON+.+x -1 f$+/corpus.txt -2 f$+/index_0.txt"); //.txt only

//💪🏿️ big-corp on 

 
///////thats not it either? 
// this is an important step. 
// u should even train embeddings 
//printf(":./+x/1.cbow]1]NOW!🏹️.+x✔️\n");
//system("./+x/1.cbow]1]NOW!🏹️.+x -1 f$+/corpus.txt -2 f$+/query_embeds_0.txt");  //.txt only

printf(":./+x/1.5.query.embed]0005.+x✔️\n");
system("./+x/1.5.query.embed]6]RARE.+x -1 f$+/corpus.txt -2 f$+/query_embeds_0.txt");  //.txt only

//💪🏿️ big-corp on 



// having 2 redo
//https://medium.com/@louiserigny/a-guide-to-understanding-positional-encoding-for-deep-learning-models-fdea4ee938f3
printf(":./+x/2.pe]FIX]ON+.+x✔️\n");  //.txt only
system("./+x/2.pe]FIX]ON+.+x -1 f$+/corpus.txt -2 f$+/positional_encoding_0.txt");  //.txt only
//💪🏿️ big-corp on 
  

///🥷️(sneaky cuz this one has "-tags"🔖️
printf(":3.concat]0]ON+.+x\n");  //.txt only
system("./+x/3.concat]0]ON+.+x -1 f$+/query_embeds_0.txt -2 f$+/positional_encoding_0.txt -3 f$+/resultant_0.txt");  //the other concat doesn't work , it never did!

//💪🏿️ big-corp on 

 //🇦🇷️arg swap still NECESSARY (4)
 printf(":./+x/4.encode_qkv]32]+.+x✔️\n");  //.txt only
  system("./+x/4.encode_qkv]32]+.+x -1 f$+/resultant_0.txt -2 f$+/q_0.txt -3 f$+/k_0.txt -4 f$+/v_0.txt");  //.txt only
//

//💪🏿️ big-corp on 


  // no mask
  //⬛️
   printf(":./+x/4.mMHA]VA5]1]0001.+x✔️\n");  //.txt only
  system("./+x/4.mMHA]VA5]1]0001.+x -1 f$+/q_0.txt -2 f$+/k_0.txt -3 f$+/v_0.txt -4 f$+/mha_0.txt -5 f$+/resultant_0.txt --");
  //⛳️
 //💪🏿️ big-corp on 
  
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/mha_0.txt -2 f$+/resultant_0.txt -3 f$+/add_n_norm_0a.txt");
  
  //💪🏿️ big-corp on 

  //////
  printf(":./+x/6.feedforw]0002.+x✔️\n");
  system("./+x/6.feedforw]0002.+x -1 f$+/add_n_norm_0a.txt -2 f$+/ff_0.txt");
  //
  
  
   //💪🏿️ big-corp on 
 
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/ff_0.txt -2 f$+/add_n_norm_0a.txt -3 f$+/add_n_norm_0b.txt");
  
  //🔰️
  //////
  ////
  
   //💪🏿️ big-corp on 

  //
   
  //🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️
printf(":./+x/0.sol.count]2]xp]ON+.+x✔️\n");
system("./+x/0.sol.count]2]xp]ON+.+x -1 f$+/outputs.txt -2 f$+/index_1.txt"); //.txt only

//💪🏿️ big-corp on 

///////
printf(":./+x/1.5.query.embed]6]RARE.+x✔️\n");
system("./+x/1.5.query.embed]6]RARE.+x -1 f$+/outputs.txt -2 f$+/query_embeds_1.txt");  //.txt only

//💪🏿️ big-corp on 


printf(":./+x/2.pe]FIX]ON+.+x✔️\n");  //.txt only
system("./+x/2.pe]FIX]ON+.+x -1 f$+/outputs.txt -2 f$+/positional_encoding_1.txt");  //.txt only
///////

//💪🏿️ big-corp on 

printf(":3.concat]0]ON+.+x\n");  //.txt only
system("./+x/3.concat]0]ON+.+x -1 f$+/query_embeds_1.txt -2 f$+/positional_encoding_1.txt -3 f$+/resultant_1.txt");
//////////
 
 //💪🏿️ big-corp on
 
///
 printf(":./+x/4.encode_qkv]32]+.+x✔️\n");  //.txt only
  system("./+x/4.encode_qkv]32]+.+x -1 f$+/resultant_1.txt -2 f$+/q_1.txt -3 f$+/k_1.txt -4 f$+/v_1.txt");  //.txt only
//
//✅️
 //💪🏿️ big-corp on 
 
 

///⁉️ isn't "V" supposed to come from "somewhere else? <yes🗜️
//⁉️ are they supposed 2 be same size ? padd/cutt? (not yet🗜️✳️
  //  maskED FLAG ! ADD IT . DO IT  ⛳️
   printf(":./+x/4.mMHA]VA5]1]0001.+x✔️\n");  //.txt only
  system("./+x/4.mMHA]VA5]1]0001.+x -1 f$+/q_1.txt -2 f$+/k_1.txt -3 f$+/v_1.txt -4 f$+/mha_1.txt -5 f$+/resultant_1.txt -+");
  
  




 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/mha_1.txt -2 f$+/resultant_1.txt -3 f$+/add_n_norm_1a.txt");
  ///////


////✳️NOW DO "THIS"🗜️

printf(":../+x/17.pad_cut]TOOL]2]FULL+.c.+x\n");  //.txt only
    system("./+x/17.pad_cut]TOOL]2]FULL+.+x -1 f$+/add_n_norm_0b.txt -2 f$+/add_n_norm_1a.txt -3 f$+/pad_cut_v_1.txt");  //.txt only
   //////////
   
    //💪🏿️ big-corp on 


// 🔦️aug3. < this is proper size. someone is ignoring the zeros? 
//🅰️YES ITS IMMEDIATELY BEING UNPADDED BY ./+x/4.encode_qkv]32]de.+x
 //🆎️(u were giving non-padded value, even tho u gave padded size...  
 //its either wanting add_n_norm_0b OR pad_cut_v_1 OR BOTH? 
    printf(":./+x/4.encode_qkv]32]de.+x✔️\n");  //.txt only
 // system("./+x/4.encode_qkv]32]de.+x -1 f$+/add_n_norm_1a.txt -2 f$+/q_1b.txt -3 f$+/k_1b.txt -4 f$+/v_1b.txt -5 f$+/pad_cut_v_1.txt");  //.txt only
 
 system("./+x/4.encode_qkv]32]de.+x -1 f$+/add_n_norm_0b.txt -2 f$+/q_1b.txt -3 f$+/k_1b.txt -4 f$+/v_1b.txt -5 f$+/pad_cut_v_1.txt");  //.txt only
 
  //💪🏿️ big-corp on  // zero tail...
  
   // exit(11);
     //🔬️ why is q_1b.txt (etc) shorter? < theres some shenanigans going on
///🔬️  y would we have padded it if its just going to be shorter? 
// printf("debug👻️-nan's = yES* HERE! 🧨️\n");
 // exit(9);
 // no mask
   printf(":./+x/4.mMHA]VA5]1]0001.+x✔️\n");  //.txt only
  system("./+x/4.mMHA]VA5]1]0001.+x -1 f$+/q_1b.txt -2 f$+/k_1b.txt -3 f$+/v_1b.txt -4 f$+/mha_1b.txt -5 f$+/pad_cut_v_1.txt --");
//    printf("debug👻️-nan's\n");
//  exit(9);
  
  //💪🏿️ big-corp on 
  /////////this is where IO IS DEAD WRonG u need 2 examine EVERY IO , SHOULD PROBABLY
  // be using "pad_cut_v_1" 
   //🚨️< V now this outputs NOTHING add_n_norm_1a
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/mha_1b.txt -2 f$+/pad_cut_v_1.txt -3 f$+/add_n_norm_1b.txt");
  ////
    //💪🏿️ big-corp on 

  
  //printf("debug👻️-nan's\n");
 // exit(9);
    printf(":./+x/6.feedforw]0002.+x✔️\n");
  system("./+x/6.feedforw]0002.+x -1 f$+/add_n_norm_1b.txt -2 f$+/ff_1.txt");
  //
      //💪🏿️ big-corp on 
  
  
  //
 printf(":./+x/5.add_n_norm]+]0000.+x✔️\n");  //.txt only
  system("./+x/5.add_n_norm]+]0000.+x -1 f$+/ff_1.txt -2 f$+/add_n_norm_1b.txt -3 f$+/add_n_norm_1c.txt");
  ////
   //💪️ -nan found in file search  (first?) yes first spotted
    //💪🏿️ big-corp on  (supposedly fixed
  
  ///]
// did we do a linear and a softmax?!?! and ... how does it compare 2 
//20.? just for science purposes? very intersting phenom after all...
//20.soft.max=wordprob.c
// yes i will just fork "llout here 
  printf(":./+x/18.linear_n_softmax.+x✔️\n");  //.txt only
  system("./+x/18.linear_n_softmax.+x -1 f$+/add_n_norm_1c.txt -2 f$+/smout_1.txt -3 f$+/llout_1.txt");
  

//
//💪🏿️ big-corp on 
  
 
    printf("debug🏆️\n");
 // printf(":./+x/19.word_probe]30]ON!🏆️+.+x✔️\n");  //.txt only
 // system("./+x/19.word_probe]30]ON!🏆️+.+x -1 f$+/index_0.txt -2 f$+/add_n_norm_1b.txt -3 f$+/weights_matrix_0.txt -4 f$+/answer_i.txt");
  
  // f$+/add_n_norm_1b.txt 🔦️
  system("./+x/19.word_probe]30]fix🥽️]0003.+x -1 f$+/index_0.txt -2 f$+/add_n_norm_1c.txt -3 f$+/weights_matrix_0.txt -4 f$+/answer_i.txt");
  
  
  //fixing = f$+/add_n_norm_1b.txt is giving off -nans (IN FILE)
  // where does this start?
 //💪🏿️ big-corp on = NO  //💪️ segfault is "HERE" 
 // printf("debug🏆️💪🏿️\n");
  exit(9);
  // were doing 2 diff word prob generators and comparing them 
  // tiny bit more work but DEF worth it! love it. 👩‍❤️‍👨️ 👩🏼‍❤️‍👨🏼️
 //  printf(":./+x/20.soft.maxISwordprob👩🏼‍❤️‍👨🏼️.+x✔️\n");  //.txt only
 // system("./+x/20.soft.maxISwordprob👩🏼‍❤️‍👨🏼️.+x -1 f$+/llout.txt -2 f$+/index_1.txt -3 f$+/answer_2.txt");
  
  
  
  //🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️🔂️
  //🤯️ instead of doign this im gonna detatch it 
  // still "run BOTH from here " AND
  // we will get 2 outputs 
  //👾️ ALSO MAYBE WE CAN DO "MANUAL EPOCHS"? 4 STARTERS👾️
  //➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️➿️ 
  for (int i = 0; i < EPOCHS; i++) {
   
   printf(":./+x/!.ore.ches.tR8rPt2🪄️🪄️]0001.+x✔️\n");
system("./+x/!.ore.ches.tR8rPt2🪄️🪄️]0001.+x -1 f$+/answer_i.txt");  //.txt only

///🥷️its going 2 overright EVERYTHING BUT "answer arg" but thats ok...
// its not parallel so it wont matter. 
 //////////🥷🏿️
 /*
printf(":../+x/!.ore.ches.tR8rPt2🪄️🪄️]0000.+x✔️\n");  //.txt only
system("./+x/!.ore.ches.tR8rPt2🪄️🪄️]0000.+x -1 f$+/answer_ii.txt");  //.txt only
*/
///////

}

}

///🥷️🥷🏿️

  



