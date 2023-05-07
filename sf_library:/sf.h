/* # DESIGNING A NEW OPERATING SYSTEM WAS AND WILL ALWAYS BE ONE OF THE GREATEST JOYS OF MY LIFE # */
/* # for me trundle means keep turning. . .  rock and roll# */
/*
 * PROTOTYPES
 *
*/
/*
double sf_Rnd();
int sf_getSize();
int sf_Str_toNum();
size_t sf_Length();
void sf_Print();
void sf_Fill();
int sf_isPrint();
int sf_isNum();
int sf_Pow();
int sf_strToInt();
float sf_strToFloat();
int sf_isLowerCase();
int sf_isUpperCase();
int sf_isLetter();
void sf_mkUcase();
void sf_mkLcase();
*/
//attribution https://www.geeksforgeeks.org/generating-random-number-range-c/
double sf_Rnd(int lower, int upper){	
//	srand(time(0));
	if((lower == 0) && (upper == 1))//special case, decimals 0 to 1
		return ((double)rand() / (double)RAND_MAX);
	if((lower == 0) && (upper == -1))//special case, exclude 1.0
		return ((double)rand() / ((double)RAND_MAX + 1));
	return (((rand() % (upper - lower + 1)) + lower));//integer range
}

int sf_getSize(char ch[]){
	int r = 0;
	int i =0;

	while(ch[i] != 0x00){
		if(ch[i] == '\n')
			r++;
		i++;
	}

	return r;
}

size_t sf_Length(char str[]){
	size_t len = 0;
	while(str[len] != 0){
		len++;		
	}
	return len;
}

int sf_isPrint(char str){
	int r = -1;
	if(str > 0x1F && str < 0x7F){
		r++;
	}	
		r++;
	return r;
}

int sf_isNum(char str){
	int r = -1;
	if( sf_isPrint(str) == 1 ){
		if( (str > 0x2F) && (str < 0x3A) ){
			r++;
		}
	}
		r++;	
	return r;
}

int sf_Pow(size_t b, size_t p){
	int r;
	int i;
	if( p < 0){//create negitive case
		
	}
	if( p == 0){
		r = 1;
	}
	if( p > 0){
		r = 1;
		i = p;
		while(i > 0){
			r = ( b * r );
			i--;
		}	
	}
	return r;
}

int sf_Str_toNum(char str[]){
        int x;
        int i;
        int r = 0x00;
        int p = 0;
        int a = 0;
        size_t len = 0;
        len = sf_Length(str);
        x = len;
        int y = 0;
        char X[len];

        for(i = 0; i < x; i++){
                if(sf_isNum(str[i])){
                        X[i] = str[len - i - 1];
                        r = X[i];
                        y = r - 48;
                        p =  sf_Pow(10, i);
                        a += (p*y);
                }
        }
    return a;
}

void sf_Print(char str[]){
	size_t len = sf_Length(str);

	for(int x = 0; x < len; x++){
		printf("%c",str[x]);
	}
	return;
}

void sf_Fill(char str[], size_t len){
	char X[len];
	int x = -1;
	for(x = 0; x < len; x++){
		X[x] = str[x];		
	}
	while( x > 0){
		printf("%c\n",X[len-x]);
	}
	return;
}

int sf_strToInt(char str[]) {
	int x;
	int i;
	int r = 0x00;
	int p = 0;
	int a = 0;
	size_t len = 0;
	len = sf_Length(str);	
	x = len;
	int y = 0;	
	char X[len];
	X[len] = 0x00;	
	for(i = 0; i < x; i++){	
		if(sf_isNum(str[i])){
			X[i] = str[len - i - 1];
			r = X[i];
			y = r - 48;
			p =  sf_Pow(10, i);
			a += (p*y);	
		}
	}
    return a;
}

float sf_strToFloat(char str[]) {
	float r = 0.0;
   	size_t len = sf_Length(str);
	int x = len;
	int s = 0;
	char X[len];
	int p = 0;
	int RsLen = 0; //right side length
	int LsLen = 0; //left side length

	for(int i = 0; i < x; i++){
		if((str[i] != '.') && (s < 1)){
			X[i] = str[i];
			LsLen++;	
		}else{
			s++;
		}
	}
	X[LsLen + 1] = 0;	
	char Y[LsLen];
	
	for(int i = 0; i < LsLen; i++){
		Y[i] = X[i];
	}
	Y[LsLen] = 0x00;

	RsLen = x - LsLen - 1; //Right side Length
	char Z[RsLen];
	for(int i = 0; i < RsLen; i++){
		if((str[i + LsLen + 1] != '.') && (p < 1)){
			Z[i] = str[i + LsLen + 1];
		}else{
			p++;
		}

	}
	Z[RsLen] = 0x00;

	r = sf_strToInt(Z);
       
	while( RsLen > 0){
		r /= 10;	
		RsLen--;
	}

	r += sf_strToInt(Y);
	return r;
}

int sf_isLowerCase(char str){
	int r = -1;
	if(sf_isPrint(str) == 1){	
		if(str > 0x60 && str < 0x7B){
			r++;
		}
	}
		r++;
	return r;
}


int sf_isUpperCase(char str){
	int r = -1;
	if(sf_isPrint(str) == 1){	
		if(( str > 0x40) && (str < 0x5B) ){
			r++;
		}
		r++;
	}
	return r;
}

int sf_isLetter(char str){
	int r = -1;
	if(sf_isPrint(str) == 1){	
		if(sf_isLowerCase(str) == 1 || sf_isUpperCase(str) == 1){
			r++;
		}
	}
		r++;
	return r;
}

void sf_mkUcase(char str){
	if(sf_isUpperCase(str) == 0){;
		str -= 0x20;
		printf("%c", str);
	}
	return;
}

void sf_mkLcase(char str){
	if(sf_isUpperCase(str) == 1){
		str += 0x20;
		printf("%c", str);
	}
	return;
}


// ***************************************
// ****** SHIA AARON LLOYD FISHER ********
// ********* FEBUARY 19, 2023 ************
// ************** PROJECT 3 **************
// *************  SubRoutines  ***********
// ***************************************

#define BUFSIZE 1080
#define DELIMITER ";"
#define PIPE "|"
#define REDIR ">"
 size_t bufsize = BUFSIZE;
 int c = 0;
 int argnum;

int sf_run();

//flags
    int fexit;
    int fcd;
    int fpwd;
    int floop;
    int fPtest = 1;//RUN IN TEST MODE TURN TO 1

//control variables
    char *getchdir;
	char *getpwd;
    int getloop;


/// description: Takes a line and splits it into args similar to how argc
///              and argv work in main
/// line:        The line being split up. Will be mangled after completion
///              of the function<
/// args:        a pointer to an array of strings that will be filled and
///              allocated with the args from the line
/// num_args:    a point to an integer for the number of arguments in args
/// return:      returns 0 on success, and -1 on failure
int lexer(char *line, char ***args, int *num_args){
    *num_args = 0;
    // count number of args
    char *l = strdup(line);
    if(l == NULL){
        return -1;
    }
    char *token = strtok(l, " \t\n");
    while(token != NULL){
        (*num_args)++;
        token = strtok(NULL, " \t\n");
    }
    free(l);
    // split line into args
    *args = malloc(sizeof(char **) * *num_args);
    *num_args = 0;
    token = strtok(line, " \t\n");
    while(token != NULL){
        char *token_copy = strdup(token);
        if(token_copy == NULL){
            return -1;
        }
        (*args)[(*num_args)++] = token_copy;
        token = strtok(NULL, " \t\n");
    }
    return 0;
}


int sf_reset(){
	printf("trundle ? > ");
	fflush(stdout);
    fexit = 0;
    fcd = 0;
    fpwd = 0;
    floop = 0;
    getloop = -1;
    argnum = 0;
/*
    if(c!=1){//free if !c
		free(getpwd);
		free(getchdir);
	}*/
	return 0;
}

int sf_err(){
	char error_message[30] = "An error has occurred\n";
	write(STDERR_FILENO, error_message, strlen(error_message));
	return 0;
}

int sf_isBuiltIn(char* sfCMD){
	if((strcmp(sfCMD,"loop") == 0) || (strcmp(sfCMD,"exit") == 0) || (strcmp(sfCMD,"pwd") == 0) || (strcmp(sfCMD,"cd") == 0))
		return 1;

	return 0;
}

int sf_cmd(char *sfCMD){

	if(fexit){
		if(strcmp(sfCMD,DELIMITER) != 0){
			sf_err();
			fexit = 0;
		}
	}
	if(fcd == -1){
		getchdir = malloc(strlen(sfCMD)*sizeof(char));
		getchdir = sfCMD;
		fcd = 1;
	}
	if(floop == -1){
		if(!(getloop = atoi(sfCMD)))
			sf_err();
		else
			floop = 1;
	}

	if(strcmp(sfCMD,"exit") == 0)
		fexit = 1;
	if(strcmp(sfCMD,"cd") == 0)
		fcd = -1;
	if(strcmp(sfCMD,"pwd") == 0)
		fpwd = 1;
	if(strcmp(sfCMD,"loop") == 0)
		floop = -1;
	return 0;
}

int sf_exe(){
	char setpwd[bufsize];

	if(fcd){
		if(fcd == 1){
			if(chdir(getchdir))
				sf_err();
			fcd = 0;
		}
	}

	if(fpwd){
		getcwd(setpwd,bufsize);
		getpwd = malloc(strlen(setpwd)*sizeof(char));
		getpwd = setpwd;
		printf("%s\n",getpwd);
		fpwd = 0;
	}
	return 0;
}

int sf_printcmd(char** sfCMDs, int pid){
	if(sfCMDs == NULL)
		return 1;

	c++;
	printf("%d.) ",c);
	for(int i = 0; sfCMDs[i - 1] != NULL; i++){
		//printf("%s - %d",sfCMDs[i], i);
		printf("%s ",sfCMDs[i]);
		if(sfCMDs[i] != NULL)
			printf(" ");
	}
	//printf("\t (pid: %d)\n", pid);
	printf("\n");
	return 0;
}

int sf_myArg(int *length, int start, char*** sfCmdArg, char** sfCMD){
	int k = 0;
	*sfCmdArg = (char**)malloc(sizeof(char*) * bufsize * *length);
	while(k < (*length+1)){
		if(strcmp(sfCMD[(start- *length) + k],DELIMITER) != 0){
			(*sfCmdArg)[k] = (char*)malloc(sizeof(char*) * bufsize);
			(*sfCmdArg)[k] = sfCMD[(start- *length) + k];
//			printf("[%s], \n", (*sfCmdArg)[k]);
		}else{
			(*sfCmdArg)[*length] = NULL;
		}
		k++;
	}

	*length = 0;
	return 0;
}


char* sf_addbin(char** myARG){
	if(fPtest){
		char *addBins = "/bin/";
		if(strncmp(myARG[0],addBins,5) != 0){
			char *temp = malloc(sizeof(char*) * sizeof(addBins) + sizeof(myARG[0]));
			strcat(temp,addBins);
			strcat(temp,myARG[0]);
			addBins = malloc(sizeof(temp));
			strcpy(addBins,temp);
		}else{
			addBins = malloc(sizeof(myARG[0]));
			strcpy(addBins,myARG[0]);
		}

		return addBins;
	}
	else{
		return myARG[0];
	}
}

int sf_rdir(char* addBins, char** myArg, char* outputfile){
	int fdr;
	if ((fdr = open(outputfile, O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
	    sf_err(); 
		exit(1);
	}		

	dup2(fdr,1);
	close(fdr);	
	if(execv(addBins,myArg)<0){
		sf_err();
		exit(0);
	}
	return 0;
}

int sf_pipe(char* addBinsL, char** LArg, char* addBinsR, char** RArg, pid_t pid){
	int fd[2];// File Descriptor
	
	if(pipe(fd) == -1){//PIPE FAILED///////////////////////////////
		sf_err();
		exit(0);
	}
		pid = fork(); //child PID for the operator args

	if(pid < 0){//FORK FAILED/////////////////////////////////
		sf_err();
		exit(0);
	}else{
		if(pid > 0){//PARENT PROCESS////////////////////////
			dup2(fd[1],1);
			close(fd[0]);

			if(execv(addBinsL,LArg)<0){
				sf_err();
				exit(0);
			}
		}else{//CHILD PROCESS///////////////////////////////////////
			dup2(fd[0],0);
			close(fd[1]);

			if(execv(addBinsR,RArg)<0){
				sf_err();
				exit(0);
			}
		}
	}
	return 0;
}


int sf_operator(char** LArg, char** RArg, char Operator){
	if(fPtest){
		printf("\t\t\tL: "); sf_printcmd(LArg, getpid()); printf("\t\t\tR: "); sf_printcmd(RArg, getpid());
	//	printf("~~~~~~~~~~>The O = %c \n",Operator);	
	}

	char *addBinsL = sf_addbin(LArg);	
	char *addBinsR = sf_addbin(RArg);
	int status;
	pid_t pid = fork();

	if(pid < 0){
		sf_err();
		exit(0);
	}else if(pid > 0){//P	
		waitpid(pid, &status, 0);
	}else{//C
			int Ostatus;
			int fdpr = 0;
			pid_t o_pid = fork(); //child PID for the operator args
			if(o_pid < 0){
				sf_err();
				exit(0);
			}else if(o_pid > 0){//parent////////////////////////////////////////////////////
				dup2(fdpr,0);
				close(fdpr);	

				if(Operator == '>'){
					if ((fdpr = open(RArg[0], O_WRONLY | O_CREAT | O_TRUNC,
				    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
					    sf_err(); 
					}
					int fd =0;

					if(fork()==0){
						dup2(fd,1);
						sf_run(LArg);
						exit(0);
					}else{
						exit(0);
					}

				}
				waitpid(o_pid, &Ostatus, 0);
			}else{//child////////////////////////////////////////////////////////////////////
				dup2(fdpr,1);
				close(fdpr);

				if(Operator == '|')
					sf_pipe(addBinsL, LArg, addBinsR, RArg, o_pid);
			}
		exit(0);
	}
	return 0;
}

int sf_runbuiltin(char** myARG){

//BUILT IN FUNCTION////////////////////////////////////////////////////////
		for(int j = 0; myARG[j] != NULL; j++){
			sf_cmd(myARG[j]);
			sf_exe();		
		}
		if(fexit)
			exit(0);
//LOOP ROUTINE////////////////////////////////////////////////////////////
		if(floop){
		    int intLA = 0;
		    while(myARG[intLA] != NULL)
		    	intLA++;

		   char **loopARG = malloc(sizeof(char*) * (intLA));
		   for(int j = 0; myARG[j+2] != NULL ; j++){
		   		loopARG[j] = malloc((sizeof(char*)));
				strcpy(loopARG[j],myARG[j+2]);
		   }

			//sf_myArg(&intLA,4, &loopARG, myARG);
		   if(fPtest){
				printf("\n"); sf_printcmd(loopARG, getpid());
			}
			while(getloop){
				if(fPtest){
					printf("\t\tLoop counter (%d):\n",getloop);printf("\t"); sf_printcmd(loopARG, getpid());//PRINT COMMANDS
				}
				sf_run(loopARG);

			getloop--;
			}
			floop = 0;
		}
	
	return 0;
}

int sf_syscalls(char **myARG){
//SYSTEM CALL FUNCTIONS////////////////////////////////////////////////////
	int status = 0;
	char *addBins = sf_addbin(myARG);

	pid_t child_pid;

		child_pid = fork();

		if(child_pid < 0){
			sf_err();
			exit(0);
		}
		if(child_pid == 0){
//CHILD PROCESS////////////////////////////////////////////////////////////
		if(execv(addBins,myARG) < 0){
				sf_err();
				exit(0);
			}
		}else{
//PARENT FUNCTIONS/////////////////////////////////////////////////////////
			waitpid(child_pid, &status, 0);
		}
	return 0;
}

int sf_run(char **myARG){

//	int hasOperator = 0; //number of commands after operator
	int beforeOperator = 0;
	int afterOperator = 0;
	char Operator = 0;
	char **LArg;
	char **RArg;
//Check for Loop //////////////////////////////////////////////////////////////////////////
	if(strcmp("loop",myARG[0]) != 0){
//Check for operator/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int h = 0;
	for(int i = 0; myARG[i] != NULL; i++){
		h++;
	}
	while(h){
		if(Operator){
			afterOperator++;
			//if((strcmp(myARG[h],PIPE) == 0) || (strcmp(myARG[h],REDIR) == 0) )
			//	Operator = myARG[h][0];

		}else{
			if((strcmp(myARG[h-1],PIPE) == 0) || (strcmp(myARG[h-1],REDIR) == 0) )
				Operator = myARG[h-1][0];
			else
				beforeOperator++;
		}
		h--;
	}
	LArg = (char**)malloc(sizeof(char*)*(afterOperator+1));
	RArg = (char**)malloc(sizeof(char*)*(beforeOperator+1));

	if(fPtest && Operator){
		printf("# of cmds before operator: %d\n",beforeOperator); printf("# of cmds after operator: %d\n",afterOperator);
	}

	for(int i = 0; myARG[i] != NULL; i++){
		if(i < afterOperator){
			LArg[i] = (char*)malloc((sizeof(char*)));
			LArg[i] = (char*)myARG[i];
		}else{
			RArg[i-afterOperator] = (char*)malloc((sizeof(char*)));
			RArg[i-afterOperator] =(char*)myARG[i+1];
		}
	}
}

	if(!Operator){//DO NOT LAUNCH COMMANDS WITH OPERATORS///////////////////////////////////////////////////////////////////////////////
		if(sf_isBuiltIn(myARG[0]))
			sf_runbuiltin(myARG);
		else
			sf_syscalls(myARG);

	}else{
		sf_operator(LArg, RArg, Operator);
		}
	return 0;
}

void addUser(char* input){
	printf("%s",input);
}