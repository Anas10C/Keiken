#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>


void *threadExec(void* vargv) {
	int thread_id = *(int *) vargv;
	int pid = syscall(SYS_gettid);
	struct sched_param sch_params;
	int priority;
	int policy = SCHED_FIFO;

	pthread_getschedparam(pthread_self(), &policy, &sch_params);	
	priority = sch_params.sched_priority;

	printf("Hello this is thread %d: pid [%d] priority [%d]\n ", thread_id, pid, priority);
}

int main(int argc, char** argv) {
	
	int numThreads;
	int result;

	if(argc != 2 || (numThreads =  atoi(argv[1])) == 0) {
		printf("Usage %s <number of threads>\n", argv[0]);
		printf("argc %d argv %s\n", argc, argv[1]);
		exit(-1);
	}
	pthread_t threads[numThreads];

	if(threads != NULL) {
		for(int i = 0; i < numThreads; i++) {
			result = pthread_create(&threads[i], NULL, threadExec, (void *) &i);
			if(result) {
				printf("Error %d\n", result);
				exit(-1);
			}
			pthread_join(threads[i], NULL);
		}
		exit(0);
	
	}

}	
