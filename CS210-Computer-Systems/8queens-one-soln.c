#define N 8

int matrix[N][N];

void print_matrix(){
	int i,j;
	for ( i = 0 ; i < N ; i++ ){
		for( j = 0 ; j < N ; j++ ){
			printf( "%d ", matrix[i][j]);
		}
		printf( "\n" );
	}
	printf( "\n" );
}

int valid( int i , int j ){
  // Check the current queen in row i and column j is not in the same row, column or diagonal as another queen
  // If valid, return 1 else return 0

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (matrix[i][j]==0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}

	for (
}

void putall( int id ){ /*id: index for the current queen*/
	//if 8 queens return !! y'alls done
  for ( i = start_position of id; i < N*N ; i++ ){

        if( valid(i) ){ /*if current position is a valid one*/
            chessboard[i/8][i%8] = 1;
            if( id == N-1 ){  /*if this is the last one to place*/
                //find a solution and output result
            } else{
                //calculate the start_position for next queen.
                putall( id + 1 );
            }
        }
    }
}
