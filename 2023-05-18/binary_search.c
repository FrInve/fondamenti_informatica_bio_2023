#include <stdio.h>

int binary_search(int *array, int n, int query){
    int left = 0;
    int right = n-1;
    int center;
    while (left < right){
        center = (left + right)/2;
        if(array[center] < query){
            left = center+1;
        } else if(array[center]>query){
            right=center-1;
        }else{
            return center;
        }
    }
    return -1;
}

int binary_search_recursive(int *array, int left, int right, int query){
    if(left<=right){
        int center = left + (right-left)/2;
        if(array[center]==query){
            return center;
        }else if(array[center]<query){
            return binary_search_recursive(array,center+1,right,query);
        }else{
            return binary_search_recursive(array,left,center-1,query);
        }
    }
    return -1;
}

int main(){
    int a[] = {0,1,2,3,4,5};
    //printf("%d\n",binary_search(a,6,4));
    printf("%d\n",binary_search_recursive(a,0,5,4));
    
    return 0;
}