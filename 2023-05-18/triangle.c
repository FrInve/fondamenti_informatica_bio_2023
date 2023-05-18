/*
 * We have triangle made of blocks. The topmost row has 1 block,
 * the next row down has 2 blocks, the next row has 3 blocks, and so on.
 * Compute recursively (no loops or multiplication) the total number of blocks 
 * in such a triangle with the given number of rows.
 *
 * triangle(0) → 0
 * triangle(1) → 1
 * triangle(2) → 3 
 * https://codingbat.com/prob/p194781
 */
int triangle(int rows) {
  if(rows==0){
    return 0;
  }
  else return rows + triangle(rows-1);
}

int triangle_tail(int rows){
    return triangle_helper(rows, 0);
}

int triangle_helper(int rows, int acc){
    if(rows == 0){
        return acc;
    } else return triangle_helper(rows-1, acc+rows);
}