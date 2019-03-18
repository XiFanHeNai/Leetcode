#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintString(char* s);
char* longestPalindrome(char* s) {
    int index_s=0,index_f=1;
    int i=0, j=0,id=1,mx=0;
    int str_len = strlen(s);
    int* pos_table = (int*)malloc(str_len*2+3);
    char* full_str = (char*)malloc(str_len*2+3);/* abc --> $#a#b#c#'0' */
    
    printf("strlen = %d\n",str_len);
    *(full_str) = '$';
    while(*(s+index_s) != '\0'){
        *(full_str+index_f) = '#';
        index_f++;
        *(full_str+index_f) = *(s+index_s);
        index_f++;
        index_s++;
    }
    *(full_str+index_f) = '#';
    *(full_str+index_f+1) = '\0';
    printf("full string is ");PrintString(full_str);
    str_len = strlen(full_str);
    printf("sizeof new string is %d\n",str_len);
    *(pos_table) = 1;
    for (index_f = 1; index_f < str_len; index_f++){
        printf("index_f=%d,mx=%d,id=%d\n",index_f,mx,id);
        if (index_f < mx){
            if (*(pos_table+2*id-index_f) < (mx-index_f)){
                *(pos_table+index_f) = *(pos_table+2*id-index_f);
                continue;
            } else {
                *(pos_table+index_f) = *(pos_table+2*id-index_f);
                for (index_s = mx+1; index_s < str_len; index_s++){
                    printf("index_s=%d",index_s);
                    if (*(full_str+index_f+index_s) == (*(full_str+index_f-index_s))){
                        *(pos_table+index_f) += 1;
                    }else{
                        break;
                    }
                }
                id = index_f;
                mx = index_f+index_s-1;
                continue;
            }
        } else {
            *(pos_table+index_f) = 1;
            for (index_s = 1; index_s < str_len; index_s++){
                printf("\tindex_f=%d,index_s=%d,full_str=%d \n",index_f,index_s,full_str);
                printf("\tfull_str[i]=%c, \t",*(full_str+index_f+index_s));
                printf("\tfull_str[-i]=%c \n",*(full_str+index_f-index_s));
                printf("full string is ");PrintString(full_str);
                
                if (*(full_str+index_f+index_s) == (*(full_str+index_f-index_s))){
                    *(pos_table+index_f) += 1;
                }else{
                    break;
                }
            }
            id = index_f;
            mx = index_f+index_s-1;
        }
        continue;
    }
    for (index_f = 0; index_f < str_len; index_f++){
        printf("%d",*(pos_table+index_f));
    }
    printf("\n");
    return full_str;
}

void PrintString(char* s)
{
    int index=0;
    while(*(s+index) != '\0'){
        printf("%c",*(s+index));
        index++;
    }
    printf("\n");
}

void main(void)
{
    char* s="aba";
    char* result;
    
    result = longestPalindrome(s);
    printf("This is question No.5 \n");
}