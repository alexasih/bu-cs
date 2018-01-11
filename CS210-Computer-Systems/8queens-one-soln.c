#include<stdio.h>

#define N 8

int matrix[N][N];

void print_matrix(){ /*prints out chessboard*/
	int i,j;
	for ( i = 0 ; i < N ; i++ ){
  	for( j = 0 ; j < N ; j++ ){
	    printf( "%d ", matrix[i][j]);
    }
    printf( "\n" );
  }
	printf( "\n" );
}

int horiz_check(int i){ /*checks if any queens in the same row*/
	int l;
  for(l=0;l<N-1;l++){
  	if(matrix[i][l]==1){
      return 0;
  	}
  }
  return 1;
}

int vert_check( int j) { /*checks if any queens in the same column*/
  int k;
  for(k=0;k<N-1;k++){
  	if(matrix[k][j]==1){
      return 0;
    }
  }
  return 1;
}

int tlbr_check(int i, int j){ /*checks if any queens in the same diagonal above from top left to bottom right*/
        //don't need to check below because nothing has been placed there yet (increments one at a time)
  int k,l;
	l=j;
  if(l>=0){
    for(k=i-1;k>=0;k--){
			l--;
			if(matrix[k][l]==1){
				return 0;
			}
		}
		return 1;
	}
}

int trbl_check(int i, int j){ /*checks if any queens in the same diagonal above from top right to bottom left*/
			 //don't need to check below because nothing has been placed there yet (increments one at a time)
	int k,l;
	l=j;
	if(l<N-1) {
		for(k=i-1;k>=0;k--){
			l++;
			if(matrix[k][l]==1){
				return 0;
			}
		}
		return 1;
	}
}

int valid( int i, int j){
	if((horiz_check(i)==1) && (vert_check(j)==1) && (tlbr_check(i,j)==1) && (trbl_check(i,j)==1)) {
		return 1;
	}
	else {
		return 0;
	}
}


void putall( int id ){ /*id: queen's position*/
	int i,pos_last,prev; /*pos_last: position of previous queen*/
	for ( i = 0; i < 8*8 ; i++ ){
		if( valid(i/8,i%8)==1){ /*if current position is a valid one*/
			matrix[i/8][i%8] = 1;
			pos_last=i;
			id++;
			print_matrix(); /*take me out*/
			if( id == N - 1) {
				if( id == N - 1) {
          print_matrix();
          return;
        }

      else if (i == 63) {
        matrix[pos_last/8][pos_last%8] = 0;
        pos_last++;
				putall(id-1);

    	}
    }
		else if (valid(i/8,i%8)==1) {
	    matrix[pos_last/8][pos_las%8] = 0;
      pos_last++;
  		id++;
    }
}

int main() {
	print_matrix();
  putall(0);
  return 0;

}
