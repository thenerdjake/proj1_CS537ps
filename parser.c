/*
 * parser.c
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

char* state_info;
struct dirent *myFile;
const int path_size = 80;
int sec;
int min;
int hour;
int clock;
char* time[80];
char path[80];
char str[80];

int stat_U(char* PID){
	
	
	sprintf(path, "/proc/%s/stat", PID);
	//printf("%s\n", path);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	for (int i = 0; i<=13; i++){
		fscanf(fp, "%s", str);
	}
	//printf("%s\n", str);
	clock = atoi(str);
	//printf("%d\n", sysconf(_SC_CLK_TCK));
	//sec = clock / sysconf(_SC_CLK_TCK);
	//printf("%d\n", sec);
	return clock;
}




int main(int argc, char **argv)
{
	char* PID= "519";
	//printf("%s\n", PID);
	stat_U(PID);
	return 0;
}

