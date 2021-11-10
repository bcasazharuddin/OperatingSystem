/* Write a Program in C that creates a child process , waits for the termination of the  child and lists its PID */
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>   
 
int main(void) {
    /* creating process using fork */
    int pid = fork();
    if(pid == 0) /* child is created */
    {
    
        /*the printing childs and parents process id */
        printf("Child process => PPID=%d, PID=%d\n\n", getppid(), getpid());
        for(int i=0;i<10;i++)
        {
            printf("Child process running...\n");
            sleep(1);
        }
        exit(EXIT_SUCCESS);
    }
    else if(pid > 0) // parents is created
    {   
        printf("Parent ID : %d\n\n",getpid());
        for(int i=0;i<5;i++)
        {
            printf("Parent process running...\n");
            sleep(1);
        }
        
        printf("Waiting for child process to finish.\n");
        wait(NULL);
        printf("Child process finished.\n");
    }
    else 
    {
        printf("Unable to create child process.\n");
    }
 
    return EXIT_SUCCESS;
}
