//https://codingbat.com/prob/p194781
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