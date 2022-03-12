#include "myshell.h"
#include <stdio.h>


char batchfile[PATH] ; //  The current batch file
char *open; 


/*   Function "clear " clears current screen */
void clear(void)
{
	pid_t newpid;
	switch (newpid=fork( ))
	{
	case -1:
		return 0; //error detected
	case 0:   // uses child process
		execlp("clear","",NULL); //
		return 0; // returns error if fails

	default:      waitpid(newpid, NULL, WUNTRACED);
		fprintf(stderr,"\nScreen has been cleared\n\n");
	}
	return;
} 


/*   Function "dir " used to change current directory   */
int dir(char **args,const Redirect *Inputs, int *states)//
{
	FILE  *inputfile ;
	   pid_t newpid;
       DIR   *pdir;
       int   i;
       char   filepath[PATH], dirpath[PATH], dirname[PATH];
	   /*    runs the directory   */
	   if(states[4])
	   {
		   if(args[1])///stops code if error
			   return 0;
		   if(--states[1])
			   return 0;

		   get_fullpath(filepath,Inputs->filename);
    	      inputfile=fopen(filepath,"r");  //  open file
			  if(inputfile==NULL)//  stops code if runs into error
			  {    return 0;}
			  fgets(dirname,PATH,inputfile);   //
			  fclose(inputfile);
			  args[1] = strtok(dirname," \b\n\r");//
			  i=2;
			  while (( args[i] = strtok(NULL," \b\n\r") ) )  i++;
	   }

	   else  if (states[1])   //  stops code if error is detected
		   return 0;

	   if(args[1])   //if pathname is given runs
	   {
		   if(args[2])   //Stops code if error
			   return 0;
		   get_fullpath(dirpath,args[1]);
	   }

       else strcpy(dirpath, ".");
       /* searches for the directory */
	   pdir=opendir(dirpath);
	   if(pdir==NULL)	//if doesn't exist exits code
	   {
		   return 0;
	   }
	   /* executes the dir command */
	   switch (newpid=fork( ))
	   {
	   case -1:
		   return 0; //if error ends code
	   case 0:       // runs in child process
		   execlp( "ls","ls" ,"-al", dirpath, NULL);     ///  ls
		   return 1;
	   default:   waitpid(newpid, NULL, WUNTRACED);
	   }  
	   return 0;
} 

/* "cd" changes the current directory to chosen inputted one  */
int cd (char **args,const Redirect *Inputs,int *states)//
{
    char dirpath[PATH], filepath[PATH], dirname[PATH];
    char  *cDir;
	int x,tag;
	FILE *inputfile;
	if(states[4])
	{
		if(args[1])///error if arguments can't be found
			return 0;
		if(--states[1])
			return 0;

		get_fullpath(filepath,Inputs->filename);
		inputfile=fopen(filepath,"r");  //reads from found file
		if(inputfile==NULL)//file cannot open
		{    
			return 0; //errors and ends code
		}

		fgets(dirname,PATH,inputfile);
		fclose(inputfile);
		args[1] = strtok(dirname," \b\n\r");
		x=2;
		while (( args[x] = strtok(NULL," \b\n\r") ) )  x++;
	}

	else  if (states[1])   //  unable to find input
		return 0;

	if(args[1])   //If pathname is entered
	{
	       if(args[2])   //too many arguments entered
		   get_fullpath(dirpath,args[1]);
	}

	else 	{
		fprintf(stdout,"%s\n",getenv("PWD"));
		return 0;
	}

	tag=chdir(dirpath);   //Redirects to new working directory
	if(tag)	//exits if error
	{
		return 0;
	}
	//directory has been changed
	cDir=(char *)malloc(BUFFER);//memory space is allocated
	if(!cDir)
		return 0; //error allocating memory space exits code
	getcwd(cDir,BUFFER);
	setenv("PWD",cDir,1);     //changes current value of PWD
	free(cDir);
	return 0;
}

/*   Function "environment" lists all environment strings */
int environment (void)
{
	char ** e = environment;
	while(*e) fprintf(stdout,"%s\n",*e++);
	return 0;
}

/*   Function "pause" pauses current actions until [ENTER] is clicked  */
void pause(int n)
{
	printf("Press ENTER to continue\n");
	getchar();
}

/*  Function "help" : display the user manual; displays help commands from help.txt*/
int help(char **args,const Redirect *Outputs,int *states)//
{
	char *filename = "help.txt";
	FILE *fp = fopen(filename, "r");
	
	if (fp == NULL){
	printf("Error opening help.txt");
	return 1;}
	
	char ch;
	while ((ch = fgetc(fp)) != EOF
		putchar(ch)
	fclose(fp);
	return 0;
	
}


/*   Function "echo " displays all items in chosen file */
int echo (char **args,const Redirect *Inputs,int *states)//
{
	FILE * inputfile;
	char filepath[PATH];
	char buf[BUFFER];
	int i,l;
	if(states[4])  // redirects path to chosen file
	{
		if(args[1])    // stops code if runs into error
			return 0;
		for(i=0;i<states[1];i++)
		{
			get_fullpath(filepath,Inputs[i].filename);
			inputfile=fopen(filepath,"r");
			if(inputfile==NULL)
			{
				return 0; //if error
			}
			if(states[2]==0&&output_num==0)//  no output file can be found
				fprintf(stderr,"Contents of file \"%s\" :\n",Inputs[i].filename);
			while (!feof(inputfile))    // outputs the contents of found file
			{
				if(fgets(buf, BUFFER, inputfile))
					fprintf(stdout,"%s",buf);
			}
			fclose(inputfile);
			fprintf(stdout,"\n");
		}
	}

   else
   {
	   if(states[1])//   stops code if runs into error
	   return 0;
	   if(args[1])
	   {
		   for(l=1;l<states[3]-1;l++)
			   fprintf(stdout,"%s ",args[l]);
		   fprintf(stdout,"%s",args[l]);
	   }
	   fprintf(stdout,"\n");
   }
   return 0;
}


