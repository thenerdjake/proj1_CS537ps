/*
 * parser.c
 * 
 * 
 */


#include <stdio.h>
#include <dirent.h>

char* state_info;
struct dirent *myFile;
char* random;
const int path_size = 80;

char* stat_U(char* PID){
	
	char* path[80];
	char* str[80];
	
	sprintf(path, "/proc/%s/stat", PID);
	printf("%s\n", path);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	for (int i = 0; i<=13; i++){
		printf("%d\n",i);
		fscanf(fp, "%s", str);
	}
	printf("%s\n", str);
	
	
	
	return state_info;
}




int main(int argc, char **argv)
{
	char* PID= "515";
	printf("%s\n", PID);
	stat_U(PID);
	return 0;
}

