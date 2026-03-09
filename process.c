#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    
    printf("Parent process (PID: %d) started\n", getpid());
    
    pid = fork();
    
    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls' command...\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        printf("exec() failed!\n");
        return 1;
    }
    else {
        // Parent process
        printf("Parent waiting for child (PID: %d) to complete...\n", pid);
        wait(&status);
        printf("Child process completed. Parent exiting.\n");
    }
    
    return 0;
}

