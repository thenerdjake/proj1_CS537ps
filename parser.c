/*
 * parser.c
 * 
 * 
 */


#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

char* state_info;
struct dirent *myFile;
char* random;
const int path_size = 80;
int sec;
int min;
int hour;
int clock;
char* time[80];

char* stat_U(char* PID){
	
	char* path[80];
	char* str[1000];
	
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
	clock = atoi(str);
	printf("%d\n", clock);
	printf("%d\n", sysconf(_SC_CLK_TCK));
	sec = clock / sysconf(_SC_CLK_TCK);
	printf("%d\n", sec);
	while(sec > 60){
		sec = sec-60;
		min++;
	}
	/*while(min > 60){
		min = min-60;
		hour++;
	}
	* */
	if ( min < 10){
		sprintf(time, "%d:0%d", hour, min);
	}
	else{
		sprintf(time, "%d:%d", hour, min);
	}
	printf("%s\n",time);
	return time;
}




int main(int argc, char **argv)
{
	char* PID= "519";
	printf("%s\n", PID);
	stat_U(PID);
	return 0;
}

