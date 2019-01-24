#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define n 4

int main(int argc, char* argv[]) {
	int size, my_rank;
	int send[n],*recv;
	int i;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	if(my_rank == 0) {
		recv = calloc(n*size,sizeof(int));
	}
	for(i=0;i<n;i++) {
		send[i]=i+my_rank;
	}

	MPI_Gather(send, n ,MPI_INT, recv, n, MPI_INT, 0, MPI_COMM_WORLD);
	
	if(my_rank == 0) {
		for(i=0;i<size*n;i++) {
			printf("%d\n",recv[i]);
		}
	}	
	MPI_Finalize();
}
