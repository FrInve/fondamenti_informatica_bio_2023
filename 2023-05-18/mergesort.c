#include <stdio.h>

void merge(int*,int,int,int);

void print_array(int *a,int s){
    int i=0;
    for(i=0;i<s;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
   
}

void mergesort(int *array, int left, int right){
    int center;
    if(left<right){
        center = (left+right)/2;
        mergesort(array, left, center);
        mergesort(array, center+1, right);
        merge(array, left, center, right);
    }
}

void merge(int *array, int left, int center, int right){
    int i = left;
    int j = center+1;
    int k = 0;
    int tmp[right-left+1];
    //print_array(array,6);

    while(i <= center && j<=right){ // Sono ancora da riordinare?
        if(array[i] <= array[j]){   // Sono in ordine
            tmp[k] = array[i];
            i++;
        }else{                      // Sono in disordine
            tmp[k] = array[j];
            j++;
        }
        k++;
    }

    while(i<=center){               // Copio i valori disordinati rimasti
        tmp[k] = array[i];          // all'inizio
        i++;
        k++;
    }   

    while(j<=right){                // Copio i valori disordinati rimasti
        tmp[k] = array[j];          // Alla fine
        j++;
        k++;
    }
    //print_array(tmp,right-left+1);
    for(k=left; k<=right;k++){      // Copio quello che ho riordinato nel mio array
        array[k] = tmp[k-left];
    }
}

int main(){
    int a[]={5,4,3,2,1,0};
    mergesort(a,0,5);
    
    print_array(a,6);
}