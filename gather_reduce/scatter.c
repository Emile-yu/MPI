#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define n 4
int main(int argc, char* argv[]) {
	int size, my_rank;
	int *send,*recv;
	int i;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

	send = calloc(n*size, sizeof(int));
	recv = calloc(n, sizeof(int));

	if(my_rank == 0) {
		for(i=0;i<size*n;i++) {
			send[i] = i;
		}
	}

	MPI_Scatter(send, n, MPI_INT, recv, n, MPI_INT, 0, MPI_COMM_WORLD);

	for(i=0;i<n;i++) {
		printf("my_rank %d:[%d] ",my_rank,recv[i]);
	}
	printf("\n");
	MPI_Finalize();
}