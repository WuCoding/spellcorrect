#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *ThreadFunc(void *pArg){
	int i=0;
	for(;i<10;i++){
		cout<<"Hi,I'm child thread,arg is"<<static_cast<int>(pArg)<<endl;
		sleep(1);
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t thdID;
	pthread_create(&thdID,NULL,ThreadFunc,(void*)123);
	int i=0;
	for(;i<10;i++){
		cout<<"Hi,I'm main thread,child thread id is"<<thdID<<endl;
		sleep(2);
	}
	return 0;
}
