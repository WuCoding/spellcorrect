#include "func.h"

void *ThreadFunc(void *pArg){
	int* iArg=(int*)pArg;
	sleep(*iArg);
	if(*iArg<3){
		return (void*)(&(*iArg)*2));
	}else{
		pthread_exit((void*)(&(iArg*2)));
	}
}

int main(){
	pthread_t thdID;
	int iRet=0;
	pthread_create(&thdID,NULL,ThreadFunc,(void))

