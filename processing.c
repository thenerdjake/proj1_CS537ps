/*
 * processing
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int empty = 0;
int unaccepted = 0;
int pid = 0;
int provided_pid = 0;
int anything_but_p = 0;
int contain_c = 0;
int contain_S = 0;
int contain_U = 0;
int contain_s = 0;
int contain_p = 0;

void arguements(int argc, char **argv)
{
	//checks if called with no arguements
	if (argc == 1){
		empty = 1;
	}
	//if there are arguements we gotta check what they are
	else{
		for (int i = 1; i< argc; i++){
			//arguements according to the assignment start with 
			if (argv[i][0] == '-'){
				//checks for accepted arguements
				switch(argv[i][1]){
					
					
					case 'p':
						if (argv[i][2] == '\0'){
							if (i < argc-1){
								i++;
								pid = atoi(argv[i]);
								printf("%d", pid);
								if (pid == 0){
									unaccepted = 1;
								}
								else{
									provided_pid=1;
								}
							}
							else {
								unaccepted = 1;
							}
							
						}
						else{
							unaccepted = 1;
						}
						break;
						
					case 's':
						if (argv[i][2] == '\0'){
							contain_s = 1;
							anything_but_p = 1;
						}
						else if ( argv[i][2] == '-'){
							
						}
						else{
							unaccepted = 1;
						}
						break;
						
					case 'U':
						if (argv[i][2] == '\0'){
							contain_U = 1;
							anything_but_p = 1;
						}
						else if ( argv[i][2] == '-'){
							
						}
						else{
							unaccepted = 1;
						}
						break;
						
					case 'S':
						if (argv[i][2] == '\0'){
							contain_S = 1;
							anything_but_p = 1;
						}
						else if ( argv[i][2] == '-'){
							
						}
						else{
							unaccepted = 1;
						}
						break;
						
					case 'c':
						if (argv[i][2] == '\0'){
							contain_c = 1;
							anything_but_p = 1;
						}
						else if ( argv[i][2] == '-'){
							
						}
						else{
							unaccepted = 1;
						}
						break;
				}
				
				
			}
			else{
				unaccepted = 1;
			}
		}
	}
}


int noarguements(){
	if (empty == 1){
		return 1;
	}
	else{
		return 0;
	}
}

int unacceptedinput(){
	if (unaccepted ==1){
		return 1;
	}
	else{
		return 0;
	}
}

int getPid(){
	return provided_pid;
}


int main(int argc, char **argv){
	arguements(argc, argv);
	printf("\n unaccepted %d", unaccepted);
}
