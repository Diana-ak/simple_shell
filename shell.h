#ifndef _SHELL_H_                                                                                                                       
#define _SHELL_H_                                                                                                                       
                                                                                                     
#include <stdlib.h>                                                                                                                     
#include <unistd.h>
#include <string.h>                                                                                                                     
#include <sys/types.h>                                                                                                                  
#include <sys/wait.h>                                                                                                                   
#include <sys/stat.h>                                                                                                                   
#include <limits.h>                                                                                                                     
#include <fcntl.h>                                                                                                                      
#include <errno.h>

#define BUFSIZE 1024                                                                                                                    
#define TOK_BUFSIZE 128                                                                                                                 
#define TOK_DELIM " \t\r\n\a"                                                                                                           
#define COMMAND_SEPARATOR ";\n"                                                                                                         
#define COMMENTS "#"
#define PROMPT "$ "

/* pointers to array of string environment*/                                                                                            
extern char **environ;                                                                                                                  

/**
 * struct env_s- variable of environmet
 * @name: name of environment
 * @value: value of environment vaiable
 * @next: pointer to next node
 */
typedef struct env_s
{
	char *name;
	char *value;
	char *global;
	struct env_s *next;
}env_t

/**
 * struct data_s - struct containing all data variables at runtime
 * @argv: argument vector
 * @argc: argument counter
 *@input: user input
 *@_environ: variable of environmnet
 *@status: status of previous shell
 *@pid: process ID
 *@args: arguments
 */
typedef struct data_s
{
	char **argv;
	char *input;
	char **_environ;
	char **args;
	int status;
	int argc;
	char *pid;
}data_t

void free_data(data_t *datast);
void set_data(data_t *datast char **argv);
int builtins_checker(char **args);


/* writes unix commandline interpreter*/
int hsh_loop(char *line, char **args, int status);
int main(int argc, char *argv[]);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
int execve(const char *pathname, char *const argv[], char *const envp[]);

/* handles PATH */
char *find_path(char *filename, char *tmp, char *error);
int _splitPATH(char *str);

/* environmental functions*/
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/*handles alias */
/**
 * struct aliases - contains list of aliases
 * @alias: alias name used
 * @real: real name used
 */

typedef struct aliases
{
	char *alias;
	char *real;
}alias_t

void _prompt(void);

#endif
