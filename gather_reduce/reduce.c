#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define n 4
int main(int argc, char* argv[]) {
	int size, my_rank;
	int *send, *recv;
	int i;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	send = calloc(n,sizeof(int));
	recv = calloc(n,sizeof(int));
	for(i=0;i<n;i++) {
		send[i]=my_rank;
	}

	MPI_Reduce(send, recv, n, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(my_rank == 0) {
		for(i=0;i<n;i++) {
			printf("%d\n",recv[i]);
		}
	}
	MPI_Finalize();

}