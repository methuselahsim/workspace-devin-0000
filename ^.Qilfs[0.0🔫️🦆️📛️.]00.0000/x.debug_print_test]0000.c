#include <stdio.h>

int main()
{

char status[1024];
    int int_0 = 411 ;
    //
    char *char_1 = "🌍️stdCommentString_0 💪️\n";
//
   snprintf(status, sizeof(status)  ,"status = %s , %d \n", char_1,int_0 );
 //  printf("🖨️checkprinter2= %s🖨️\n",status);
   STD_debug_Print2Txt_H(status);
   
       
    
// this would go before fx call
/*
 int len = snprintf(status, sizeof(status), "%s;%s; %d; %d; @= %d",
   stdCommentString_0,stdCommentString_1,stdCommentInt_0, stdCommentInt_1,stdCommentInt_2);
   */
}



