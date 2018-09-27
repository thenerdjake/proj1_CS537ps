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
int not_contain_c = 0;
int contain_S = 0;
int not_contain_U = 0;
int contain_s = 0;
int contain_p = 0;
int contain_v = 0;

void arguments(int argc, char **argv)
{
	//checks if called with no arguments
	if (argc == 1){
		empty = 1;
	}
	//if there are arguments we gotta check what they are
	else{
		for (int i = 1; i< argc; i++){
			//arguments according to the assignment start with 
			if (argv[i][0] == '-'){
				//checks for accepted arguments
				switch(argv[i][1]){
					
					//checks for case P
					case 'p':
						contain_p = 1;
						//checks to see if anything after the p
						if (argv[i][2] == '\0'){
							if (i < argc-1){
								//if there is then get the PID 
								i++;
								pid = atoi(argv[i]);
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
					//checks for case s	
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
					//checks for case U
					case 'U':
						if (argv[i][2] == '\0'){
							
						}
						else if ( argv[i][2] == '-'){
							if (argv[i][3] == '\0'){
								not_contain_U = 1;
								anything_but_p = 1;	
							}
							else{
								unaccepted =1;
							}
						}
						else{
							unaccepted = 1;
						}
						break;
					//checks for case S	
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
					//checks for case v
					case 'v':
						if (argv[i][2] == '\0'){
							contain_v = 1;
							anything_but_p = 1;
						}
						else if ( argv[i][2] == '-'){
							
						}
						else{
							unaccepted = 1;
						}
						break;
					//checks for case c	
					case 'c':
						if (argv[i][2] == '\0'){
							
						}
						else if ( argv[i][2] == '-'){
							if (argv[i][3] == '\0'){
								not_contain_c = 1;
								anything_but_p = 1;
							}
						}
						else{
							unaccepted = 1;
						}
						break;
						
					default:
						unaccepted=1;
						break;
				}
				
				
			}
			else{
				unaccepted = 1;
			}
		}
	}
}


int get_empty(){
	if (empty == 1){
		return 1;
	}
	else{
		return 0;
	}
}

int get_unaccepted(){
	if (unaccepted ==1){
		return 1;
	}
	else{
		return 0;
	}
}


//functions to get variable values 
int get_pid(){
	return pid;
}

int get_provided_pid(){
	return provided_pid;
}

int get_anything_but_p(){
	return anything_but_p;
}

int get_not_contain_c(){
	return not_contain_c;
}

int get_contain_S(){
	return contain_S;
}

int get_not_contain_U(){
	return not_contain_U;
}

int get_contain_s(){
	return contain_s;
}

int get_contain_p(){
	return contain_p;
}

int get_contain_v(){
	return contain_v;
}
/*
//main function for testing purposes
int main(int argc, char **argv){
	arguments(argc, argv);
	printf("\n unaccepted %d", unaccepted);
	printf("\n provided_pid %d", provided_pid);
	printf("\n pid %d", pid);
	printf("\n anything but p %d", anything_but_p);
}
*/
