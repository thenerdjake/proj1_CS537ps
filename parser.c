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

char* stat_U(char* PID){
	
	char* path;
	char* str1;
	char* str2;
	char* str3;
	char* str4;
	
	sprintf(path, "/Proc/%s", PID);
	FILE* fp = fopen(path, "r");
	fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);
	
	
	return state_info;
}




int main(int argc, char **argv)
{
	
	return 0;
}

