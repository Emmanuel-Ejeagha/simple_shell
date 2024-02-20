#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

extern char **environ;

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // In the child process
        if (execve(command, (char *[]){command, NULL}, environ) == -1) {
            perror(command);
            _exit(EXIT_FAILURE);
        }
    } else {
        // In the parent process, wait for the child to finish
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            _exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            // Command executed successfully
            printf("Command '%s' executed with exit status %d\n", command, WEXITSTATUS(status));
        } else {
            // Command execution failed
            fprintf(stderr, "%s: %s\n", command, "not found");
        }
    }
}

int main() {
    char command[256];

    while (1) {
        printf("#cisfun$ ");
        
        // Read the command from user input
        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\nExiting shell...\n");
            break;
        }

        // Remove the newline character from the end of the command
        char *newline = strchr(command, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        // Execute the command
        execute_command(command);
    }

    return 0;
}

