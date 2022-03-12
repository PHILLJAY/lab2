#include "fillshell.h" 

int main (int argc, char *argv[])
{
	char buf[BUFFER], pwd[MAX_ARGS];
	char shell_path[MAX_ARGS]="shell=";
	char readme_path[MAX_ARGS]="readme_path=";
	char newpath[MAX_ARGS*1000];
	int k;  
	strcpy(newpath,getenv("PATH"));
	strcat(newpath,":");
	if(strcmp(argv[0],"./myshell")&&strcmp(argv[0],"myshell")) 
	{                 
		k=strlen(argv[0]);  
		while(k&&argv[0][k]!='/')
		 k-- ; 
		argv[0][k]='\0';           
		strcpy(pwd,argv[0]);    
		get_fullpath(pwd, argv[0]);  
		printf("%s\n",pwd);  
	}
	else
		strcpy(pwd,getenv("PWD"));    
	//environments and directories
	strcat(newpath,pwd);   
	setenv("PATH",newpath,1);// adds PATH as an environment variable
	strcat(shell_path,pwd);
	strcat(shell_path,"/myshell");
	putenv(shell_path);           
	strcat(readme_path, pwd);
	
	
	else
	{
		clear( );
		fprintf(stderr, "This is fillshell, the shell that fills your needs");          
	}
    return 0 ; 
} 

