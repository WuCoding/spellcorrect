#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *ThreadFunc(void *pArg){
	int i=0;
	for(;i<10;i++){
		printf("Hi,I'm child thread,arg is:%d\n",(int)pArg);
		sleep(1);
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_t thdID;
	pthread_create(&thdID,NULL,ThreadFunc,(void*)123);
	int i=0;
	for(;i<10;i++){
		printf("Hi,I'm main thread,child thread id is:%x\n",thdID);
		sleep(1);
	}
	return 0;
}
