/*
 * Given a non-negative int n, compute recursively (no loops) the count of the occurrences of 8 as a digit,
 * except that an 8 with another 8 immediately to its left counts double, so 8818 yields 4.
 * Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
 * while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
 * 
 * count8(8) → 1
 * count8(818) → 2
 * count8(8818) → 4
 */
#include <stdio.h>
int count8(int n) {
  if(n == 0){
    return 0;
  }else if(n % 100 == 88){
    return 2 + count8(n/10);
  }else if(n % 10 == 8){
    return 1 + count8(n/10);
  }else{
    return count8(n/10);
  }
}

int count8_helper(int n, int count) {
    if (n == 0) {
        return count;
    } else if (n % 100 == 88) {
        return count8_helper(n / 10, count + 2);
    } else if (n % 10 == 8) {
        return count8_helper(n / 10, count + 1);
    } else {
        return count8_helper(n / 10, count);
    }
}

int count8_tail(int n) {
    return count8_helper(n, 0);
}

int main(){
    printf("%d",count8(812));
}