#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"
#include <string.h>

char* newString(){
    char* String = (char*)malloc(sizeof(char));
    *String = '\0';
    char a = getchar();
    while(a != EOF && a != ' ' && a != '\n'){
        int length = strlen(String);
        String = realloc(String, length + 2);
        if(String == NULL){
            printf("Error");
            exit(1);
        }
        String[length] = a;
        String[length+1] = '\0';
        a = getchar();
    }
    return String;
}


int main(){

    StrList* newList = StrList_alloc();

    int func = -1;
    int num;
    int index;

    while (func != 0){
        scanf("%d", &func);
        if(func == 1){
            if(scanf("%d", &num) != 1){
                printf("error");
                break;
            }
            for(int i = 0; i < num; i++){
                char* String = newString();   
                StrList_insertLast(newList, String);
            }
        }
        else if(func == 2){
            if(scanf("%d", &index) != 1){
                printf("error");
                break;  
            }
            char* String = newString();
            StrList_insertAt(newList, String, index);
        }
        else if(func == 3){
            StrList_print(newList);
        }
        else if(func == 4){
            int length = StrList_size(newList);
            printf("%d\n", length);
        }
        else if(func == 5){
            if(scanf("%d", &index) != 1){
                printf("error");
                break;  
            }
            StrList_printAt(newList, index);
        }
        else if(func == 6){
            int numOfChar = StrList_printLen(newList);
            printf("%d\n", numOfChar);
        }
        else if(func == 7){
            char* String = newString();
            printf("%d\n", StrList_count(newList, String));
        }
        else if(func == 8){
            char* String = newString();
            StrList_remove(newList, String);
        }
        else if(func == 9){
            if(scanf("%d", &index) != 1){
                printf("error");
                break;  
            }
            StrList_removeAt(newList, index);
        }
        else if(func == 10){
            StrList_reverse(newList);
        }
        else if(func == 11){ 
            while(StrList_size(newList) != 0){
                StrList_removeAt(newList, 0);
            }  
        }
        else if(func == 12){
            StrList_sort(newList);
        }
        else if(func == 13){
            if(StrList_isSorted(newList) == 1){
                printf("true\n");
            }
            else{
                printf("false\n");
            }
        }
    }
    StrList_free(newList);
}