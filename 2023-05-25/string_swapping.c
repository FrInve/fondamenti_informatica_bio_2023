#include <string.h>
#include <stdio.h>

void scambia(char* stringa){
    if(*stringa == '\0'){
        return;
    }else{
        char tmp;
        tmp = stringa[0];
        stringa[0] = stringa[1];
        stringa[1] = tmp;
        return scambia(stringa+2);
    }
}

int main(){
    char stringa[10] = "cane";
    printf("%s\n",stringa);
    scambia(stringa);
    printf("%s\n",stringa);
}