#include <stdio.h>
#include <string.h>

void compress(char *source, char *dest, char lastChar, int counter){
    if(source[0]!=lastChar){
        if(counter>1){
            dest[0] = counter + '0'; // Massimo 9 ripetizioni! Altrimenti usare strlen ed sprintf per gestire la lunghezza della stringa
            dest[1] = source[0];
            return compress(source+1,dest+2,source[0],1);
        }
        dest[0] = source[0];
        return compress(source+1,dest+1,source[0],1);
    }else if(source[0]=='\0'){
        return;
    }else{
        return compress(source+1,dest, source[0], counter+1);
    }
}

int main(){
    char src[100] = {"aabbcccc"};
    char dest[100];
    compress(src,dest, '0', 0);
    printf("%s",dest);
}