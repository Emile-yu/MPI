CC=mpicc
RUN=mpirun

all:GATHER REDUCE SCATTER BCAST

GATHER: gather.c
	$(CC) $^ -o $@
REDUCE: reduce.c
	$(CC) $^ -o $@
SCATTER: scatter.c
	$(CC) $^ -o $@

BCAST: bcast.c
	$(CC) $^ -o $@
clean:
	rm -f GATHER REDUCE SCATTER BCAST
bench:
	@echo "## GATHER ##"
	${RUN} -n 4 ./GATHER

	@echo "## REDUCE ##"
	${RUN} -n 4 ./REDUCE

	@echo "## SCATTER ##"
	${RUN} -n 4 ./SCATTER

	@echo "## BCAST ##"
	${RUN} -n 4 ./BCAST

