// ***************************************
// ****** SHIA AARON LLOYD FISHER ********
// ********* FEBUARY 13, 2023 ************
// ************** PROJECT 3 **************
// ****** SUPER MADISON SHELL SMASH  *****
// ***************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //OPTing
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h> //fork wait
#include <time.h> //for randomization
#include <math.h>
#include "sf_library:/sf.h"

int main(){
	while(1){
//access variables
	    char *argv;
	    char **exec;

	    int argc;
//PROGRAM START
		sf_reset();
//INSTANTIATION
	    getline(&argv,&bufsize,stdin);
		lexer(argv, &exec, &argc);

//MAIN STRING TRAVERSAL
		for(int i = 0; i < argc; i++){
				char **myARG;
			progCtrl:
				if((i+1) == argc){
					sf_myArg(&argnum, i, &myARG, exec);
					if(fPtest){
//						sf_printcmd(myARG, getpid());
						//printf("T = %s ?\n", exec[i]);
					}
					goto runMe;
				} else if( (strcmp(exec[i],DELIMITER) == 0) ){
//MY ARG FORMATION
					sf_myArg(&argnum, i, &myARG, exec);
					if(fPtest){
	//					sf_printcmd(myARG, getpid());
						//printf("B\n");
					}
					goto runMe;
				}
				else{//////////////END OF ARGUMENT INPUT STREAM BY DELIMITER
					argnum++;
					i++;
					goto progCtrl;
				}
runMe:
	if(fPtest){
		sf_printcmd(myARG, getpid());
	}
	sf_run(myARG);
		}
	}
	return 0;
}