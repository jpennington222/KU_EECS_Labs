/*
 * Joseph Pennington (2912079) & Megan Rajagopal (2915076)
 * EECS 678 Project 1 Quash
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 
 //Process Structure
 struct process
 {
 	int pid;
 	int ID;
 	char* command;
 };


//Global Variables
 static struct process m_process[1024];
 static int m_nextID;
 static int m_jobs;

 static pid_t processID;
 static int m_pipeIndex = 0;
 static int m_pipeFound = 0;
 static int m_andIndex = 0;
 static int m_andFound = 0;
 static int m_totalArgs = 0;
 static int m_redirect = 0;
 static int m_redirectIndex = 0;
 static char m_symbol = '\0';
 char* m_inputLine;
 char* m_inputFileLine;
 char* m_homePath;
 extern char** m_environmentPath;
 
 //Declare this function early because of compile error
 int runFromFile(char *file_command);


//Parse the input from the command line or file and save necessary requirements
void parseInput(char* input, char** arguments)
{
	int index = 0;
 	m_totalArgs = 0;

 	char* isParsed = strtok(input, " \n\t");

 	while(isParsed != NULL)
 	{
 		arguments[index] = isParsed;

		//Pipe command
 		if(strcmp(arguments[index], "|") == 0)
 		{
 			m_pipeFound = 1;
 			m_pipeIndex = index;
		}

		//Background process
		if(strcmp(arguments[index], "&") == 0)
		{
			m_andFound = 1;
			m_andIndex = index;
		}

		//Input redirection
		if(strcmp(arguments[index], "<") == 0)
		{
			m_redirect = 1;
			m_redirectIndex = index;
			m_symbol = '<';
		}

		//Output redirection
		if(strcmp(arguments[index], ">") == 0)
		{
			m_redirect = 1;
			m_redirectIndex = index;
			m_symbol = '>';
		}

		isParsed = strtok(NULL, " \n\t");
		index++;
	}

	if(isParsed == NULL)
	{
		arguments[index] = NULL;
	}

	m_totalArgs = index - 1;
}

//Change directory
void changeDir(char* newDir)
{
	if(newDir == NULL)
	{
		printf("No Arguments Given - changed directory to HOME\n");
		chdir(getenv("HOME"));
	}

	else
	{
		if(chdir(newDir) == 0)
		{
			printf("Changed Directory to: %s\n", newDir);
		}

		else
		{
			printf("Directory not found\n");
		}
	}
}

//Print Foreground Jobs
void printJobs(char* dir)
{
	for(int i = 0; i < m_jobs; i++)
	{
		pid_t pid = getpid();
		printf("[%d] PID: %d; COMMAND: %s\n", m_process[i].ID, m_process[i].pid, m_process[i].command);
	}
}


//Set Environment Variables
void setNewPath(char* newPath)
{
	char* temp = strtok(newPath, "=");
	char* setPath = strtok(NULL, "\0");
	int set = setenv(temp, setPath, 1);

	if(set < 0)
	{
		printf("Set Failed for %s\n", temp);
	}
	else
	{
		printf("Set %s Successfully\n", temp);
	}
}

//Run Unix Commands
void runCommand(char **arguments)
{
	int status;
	pid_t pid;
	pid = fork();

	//child
	if(pid == 0)
	{
		if(arguments[1] == NULL)
		{
			execlp(*arguments, *arguments, NULL);
			printf("Executable not found for %s\n", arguments[0]);
			exit(0);
		}
		else
		{
			execvp(arguments[0], arguments);
			printf("Executable not found for %s\n", arguments[0]);
			exit(0);
		}
	}
	
	//Error when forking
	else if(pid < 0)
	{
		fprintf(stderr, "Failure to Fork");
		exit(-1);
	}
	
	//Parent
	else
	{
		waitpid(pid, &status,0);
	}
}


//Run Processes
void runPID(char **arguments, pid_t pid)
{
	int status;

	//Child
   	if (pid == 0)
	{
		if (arguments[1] == NULL)
		{
			execvp(arguments[0], arguments);
			printf("Executable not found for %s\n", arguments[0]);
			exit(0);
		}
		
		else
		{
			execvp(arguments[0], arguments);
			printf("Executable not found for %s\n", arguments[0]);
			exit(0);
		}
	}
	
	//Error when forking
	else if (pid < 0)
	{
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}

	//Parent
	else
	{
		waitpid(pid, &status, 0);
	}

}


//Run Background Process (& command)
void runBackgroundProcess(char **argument_input)
{
	if (m_andIndex > 0 && strcmp(argument_input[0], "jobs") != 0)
	{
		char* command[m_andIndex];
    		command[m_andIndex] = NULL;
    		
    		for (int i = 0; i < m_andIndex; i++)
    		{
      			command[i] = argument_input[i];
      		
      			while((command[i][strlen(command[i])-1]==' ' || command[i][strlen(command[i])-1]=='\t'))
			{
        			command[i][strlen(command[i])-1] = '\0';
      			}
    		}
    	
    		m_andFound=0;
	    	int exit_status;
	    	pid_t pid;
	    	pid=fork();
	    	processID=pid;

		//Child (print running and finishing)
		if(pid==0)
		{
      			printf("[%d] PID: %d running in background\n", m_nextID, getpid());
      			sleep(2);
      			runCommand(command);
      			printf("\n[%d] PID: %d finished COMMAND: %s\n\nQuash$ ", m_nextID, getpid(), command[0]);
      			exit(exit_status);
    		}
    		
    		//Error when forking
    		else if (pid < 0)
		{
      			fprintf(stderr, "Fork Failed for run process in background\n");
      			exit(-1);
    		}
    		
    		//Parent (remove background from array)
    		else
		{
      			m_jobs++;
      			m_process[m_jobs-1].ID=m_nextID;
     			m_process[m_jobs-1].pid=pid;
     			m_nextID++;
    		}

  	}
  	
  	else
  	{
    		printf("Syntax Error: Invalid use of '&' command\n");
  	}
}

//Run Pipe Command (| command)
void makePipe()
{
	if (m_pipeIndex != 0 && m_pipeIndex != m_totalArgs)
  	{
    		char *first_command[50];
    		char *second_command[50];
	    	char *first_parse = strtok(m_inputLine, "|");
	    	char *second_parse = strtok(NULL, "\0");
	    	int i = 0;
	    	int j = 0;
    		char* parser = strtok(first_parse, " \n\t");

    		while (parser != NULL)
    		{
      			first_command[i] = parser;
      			parser = strtok(NULL, " \n\t");
      			i++;
    		}

    		if (parser == NULL)
    		{
      			first_command[i] = NULL;
    		}

    		parser = strtok(second_parse, " \n\t");

    		while (parser != NULL)
    		{
      			second_command[j] = parser;
      			parser = strtok(NULL, " \n\t");
      			j++;
    		}

    		if (parser == NULL)
    		{
      			second_command[j] = NULL;
    		}

    		int fds[2];
    		pipe(fds);

    		pid_t pid1;
    		pid_t pid2;
    		pid1 = fork();

    		int status1;
    		int status2;

		//Error
    		if (pid1 < 0)
    		{
      			fprintf(stderr, "Fork Failed to Make Pipe for pid1\n");
      			exit(-1);
    		}
    
    		//Child
    		else if (pid1 == 0)
    		{
      			dup2(fds[1], STDOUT_FILENO);
      			close(fds[0]);
      			runPID(first_command, pid1);
      			exit(0);
    		}
    
    		//Parent
    		else
    		{
      			waitpid(pid1, &status1, 0);
    		}

    		pid2 = fork();

		//Error
    		if (pid2 < 0)
    		{
      			fprintf(stderr, "Fork Failed to Make Pipe for pid2\n");
      			exit(-1);
   		}

		//Child
    		else if (pid2 == 0)
    		{
      			dup2(fds[0], STDIN_FILENO);
      			close(fds[1]);
      			runPID(second_command, pid2);
      			exit(0);
    		}

		//Parent
    		else
    		{
      			waitpid(pid2, &status2, 0);
      			close(fds[0]);
      			close(fds[1]);
    		}
  	}
  	
  	else
  	{
    		printf("Syntax Error: Invalid use of '|' command.\n");
  	}
}


//Catch Redirect Commands (< or >)
void redirect()
{
	if (m_redirectIndex != 0 && m_redirectIndex != m_totalArgs)
  	{
    		char *first_command[50];
    		char *second_command[50];
    		char *first_parse = strtok(m_inputLine, "<>");
    		char *second_parse = strtok(NULL, "\0");
    		int i = 0;
    		int j = 0;
    		char* parser = strtok(first_parse, " \n\t");

    		while (parser != NULL)
    		{
      			first_command[i] = parser;
      			parser = strtok(NULL, " \n\t");
      			i++;
    		}

    		if (parser == NULL)
    		{
      			first_command[i] = NULL;
    		}

    		parser = strtok(second_parse, " \n\t");

    		while (parser != NULL)
    		{
      			second_command[j] = parser;
      			parser = strtok(NULL, " \n\t");
      			j++;
    		}

    		if (parser == NULL)
    		{
      			second_command[j] = NULL;
    		}

		//Output Redirection
    		if (m_symbol == '>')
    		{
      			int status;
      			pid_t pid;
      			pid = fork();

			//Error
      			if (pid < 0)
      			{
        			fprintf(stderr, "Fork Failed!\n");
        			exit(-1);
      			}

			//Child
      			else if (pid == 0)
      			{
        			char *second_command_name = second_command[0];
        			int outfd = open(second_command_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);

        			dup2(outfd, STDOUT_FILENO);
        			runCommand(second_command);

        			close(outfd);
        			exit(0);
      			}

			//Parent
      			else
      			{
        			waitpid(pid, &status, 0);
      			}
    		}

		//Input Redirection
    		else if (m_symbol == '<')
    		{
      			if (strcmp(first_command[0], "quash") == 0)
      			{
    	  			char *file_name = second_command[0];
          			FILE *file_pointer;
          			char *file_command;
          			file_pointer = fopen(file_name, "r");

          			if (file_pointer == NULL)
          			{
            				fprintf(stderr, "Command file not found!\n");
            				fclose(file_pointer);
          			}

          			while (fgets(file_command, 1024, file_pointer))
          			{
            				runFromFile(file_command);
          			}
          			
          			fclose(file_pointer);
			}

      			else
      			{
        			pid_t myPid;
        			myPid = fork();
        			int stat;

				//Error
        			if (myPid < 0)
        			{
          				fprintf(stderr, "Fork failed in '<' if-else block\n");
          				exit(-1);
        			}

				//Child
        			else if (myPid == 0)
        			{
          				char *file_name = second_command[0];
          				int infd;
          				infd = open(file_name, O_RDONLY);
          				dup2(infd, STDIN_FILENO);
          				runPID(first_command, myPid);
          				close(infd);
          				exit(0);
        			}

				//Parent
        			else
        			{
          				waitpid(myPid, &stat, 0);
        			}
      			}
    		}
  	}

  	else
  	{
    		printf("Invalid use of '%c' command\n", m_symbol);
  	}
}

//Run Commands From File (use < symbol)
int runFromFile(char *file_command)
{
	printf("Quash$ %s\n", file_command);
	file_command[strlen(file_command)-1] = '\0';
	
	while(file_command[strlen(file_command)-1] == '\t' || file_command[strlen(file_command)-1] == ' ')
	{
		file_command[strlen(file_command)-1] = '\0';
	}
	
	m_inputFileLine = strdup(file_command);
	
	char* fileArguments[100];
	parseInput(file_command, fileArguments);
	
	int status;
	pid_t returnpid = waitpid(processID, &status, WNOHANG);
	char* temp = fileArguments[0];
	if(returnpid == processID)
	{
		m_jobs--;
		while(m_jobs > 1)
		{
			m_jobs--;
		}
	}
	
	//Exit
	if(strcmp(temp, "exit") == 0 || strcmp(temp, "quit") == 0)
	{
		printf("Exiting QUASH\n");
		exit(0);
	}

	//Print Jobs
	else if(strcmp(temp,"jobs") == 0)
	{
		printJobs(fileArguments[1]);
	}

	//Change Directory
	else if(strcmp(temp,"cd") == 0)
	{
		changeDir(fileArguments[1]);
	}

	//Set Envrionment Variables
	else if(strcmp(temp, "set") == 0)
	{
		setNewPath(fileArguments[1]);
	}

	//Redirection
	else if(m_redirect == 1)
	{
		redirect();
		m_redirect = 0;
		m_redirectIndex = 0;
		m_symbol = '\0';
	}

	//Pipe Command
	else if(m_pipeFound == 1)
	{
		makePipe();
		m_pipeFound = 0;
		m_pipeIndex = 0;
	}

	//Background Process
	else if(m_andFound == 1)
	{
		char* backgroundProcess = strdup(fileArguments[0]);
		m_process[m_jobs].command = backgroundProcess;

		runBackgroundProcess(fileArguments);
		m_andFound = 0;
		m_andIndex = 0;
	}
	
	//Run Other Command
	else
	{
		runCommand(fileArguments);
	}
}

//Main - handles command line inputs
int main(int argc, char** argv, char** envp)
{
 	printf("Starting QUASH - Type 'exit' or 'quit' to stop QUASH\n");

 	char input[1024];
 	char* inputArguments[100];

 	m_jobs = 1;
 	m_nextID = 1;

 	m_process[0].ID = m_nextID;
 	m_process[0].pid = getpid();
 	m_process[0].command = "./quash";
 	m_nextID++;

 	while(1)
 	{
 		printf("Quash$ ");
 		fgets(input, 1024, stdin);

 		input[strlen(input)-1] = '\0';

 		while(input[strlen(input)-1] == '\t' || input[strlen(input)-1] == ' ')
 		{
 			input[strlen(input)-1] = '\0';
 		}

 		m_inputLine = strdup(input);

 		if(strlen(input) > 0)
 		{
 			parseInput(input, inputArguments);
 			printf("\n");
 			int status;
 			pid_t returnpid = waitpid(processID, &status, WNOHANG);
 			char* temp = inputArguments[0];

 			if(returnpid == processID)
 			{
 				m_jobs--;
 				while(m_jobs > 1)
 				{
 					m_jobs--;
 				}
			}

			//Exit
			if(strcmp(temp, "exit") == 0 || strcmp(temp, "quit") == 0)
			{
				printf("Exiting QUASH\n");
				exit(0);
			}

			//Print Jobs
			else if(strcmp(temp,"jobs") == 0)
			{
				printJobs(inputArguments[1]);
			}

			//Change Directory
			else if(strcmp(temp,"cd") == 0)
			{
				changeDir(inputArguments[1]);
			}

			//Set Environment Variables
			else if(strcmp(temp, "set") == 0)
			{
				setNewPath(inputArguments[1]);
			}

			//Redirection
			else if(m_redirect == 1)
			{
				redirect();
				m_redirect = 0;
				m_redirectIndex = 0;
				m_symbol = '\0';
			}

			//Pipe Command
			else if(m_pipeFound == 1)
			{
				makePipe();
				m_pipeFound = 0;
				m_pipeIndex = 0;
			}

			//Background Process
			else if(m_andFound == 1)
			{
				char* backgroundProcess = strdup(inputArguments[0]);
				m_process[m_jobs].command = backgroundProcess;

				runBackgroundProcess(inputArguments);
				m_andFound = 0;
				m_andIndex = 0;
			}
			
			//Run Other Command
			else
			{
				runCommand(inputArguments);
			}
			printf("\n");
		}
	}

	return(0);
}
