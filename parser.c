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
char state[1];

int stat_U(int PID){
	
	
	sprintf(path, "/proc/%d/stat", PID);
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

char* stat_s(int PID){
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	fscanf(fp, "%*s %*s %s", state);
	printf("%s\n", state);
	return state;
}

int stat_S(int PID){
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", str);
	clock = atoi(str);
	printf("%d\n", clock);
	return clock;
}



int main(int argc, char **argv)
{
	int PID= 519;
	//printf("%d\n", PID);
	stat_S(PID);
	return 0;
}

