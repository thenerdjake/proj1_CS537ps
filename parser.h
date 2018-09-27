#ifndef __PARSER_H__
#define __PARSER_H__

#define BUFSIZE 1000
#define BUFFER 80

/* Defined in parser.c */

//Returns an int for uptime when given PID
//used for the U arguement
int stat_U(int PID);


//Returns a char pointer to the character that represents the current
//state of a process when given a PID
//used for the lowercase s arguement
char* stat_s(int PID);

//Returns an int representing the 
//amount of system time consumed by the process when given the proccess PID
//used for the uppercase S arguement
int stat_S(int PID);

//returns an int representing the virtual memory used when given PID
//used in v arguement
int stat_v(int PID);

//returns a char pointer to the arguements used to call the process
//when given the proccess PID, note: still has null terminators 
//This will be sorted out in the main file so that's okay though
//used in the c arguement
char* stat_c(int PID);

#endif
