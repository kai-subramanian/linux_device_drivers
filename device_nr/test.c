#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int f = open("/dev/mydevice",O_RDONLY);
	if(f==-1){
		printf("Could not open!");
		return -1;
	}

	printf("Opened Successfully !\n");
	close(f);
	return 0;

}
