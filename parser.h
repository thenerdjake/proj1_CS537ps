#ifndef __PARSER_H__
#define __PARSER_H__

#define BUFSIZE 1000
#define BUFFER 80

/* Defined in parser.c */

//Returns an int for uptime when given PID
//used for the U argument
int stat_U(int PID);


//Returns a char pointer to the character that represents the current
//state of a process when given a PID
//used for the lowercase s argument
char* stat_s(int PID);

//Returns an int representing the 
//amount of system time consumed by the process when given the proccess PID
//used for the uppercase S argument
int stat_S(int PID);

//returns an int representing the virtual memory used when given PID
//used in v argument
int stat_v(int PID);

//returns a char pointer to the arguments used to call the process
//and prints them out
//used in the c argument
void stat_c(int PID);

//returns 1 if the PID exists in /proc, a zero otherwise
int exist_PID(int PID);

#endif
