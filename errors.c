#include "main.h"

/**
 * _printerr - print error msg to stderr and set exit status accordingly
 * @status: int representing status of the error
 * @cmd: char ** to the cmd that fails
 * @input: user input, cmd only
 * @pname: name of the program
 * Return: err status
 */
int _printerr(int status, char **cmd, char *pname, char *input)
{
	int errorCode;

	if (status == 127 && cmd)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", pname, cmd[0]);
		return (status);
	}
	else if (status == 127 && !cmd)
	{
		errorCode = _pfilerr(status, pname, input);
	}
	else if (status == 126)
	{
		errorCode = _pcmdisfolder(pname, cmd);
	}
	else if (_strcmp(cmd[0], "exit") == 0)
	{
		errorCode = _pxiterr(cmd, pname);
	}
	else if (_strcmp(input, "/bin/ls") == 0 || _strcmp(input, "ls") == 0)
	{
		return (status);
	}
	else if (_strcmp(cmd[0], "cd") == 0)
	{
		errorCode = _pcderr(cmd, pname);
	}
	else
	{
		perror(pname);
		return (status);
	}

	return (errorCode);
}

/**
 * _pxiterr - print exit cmd errors
 * @cmd: cmd and list of string args
 * @pname: name of the program
 * Return: err status, 2
 */
int _pxiterr(char **cmd, char *pname)
{
	dprintf(STDERR_FILENO, "%s: 1: exit: Illegal number: %s\n", pname, cmd[1]);

	return (2);
}

/**
 * _pcderr - print cd cmd errors
 * @cmd: cmd and list of string args
 * @pname: name of the program
 * Return: err status, 2
 */
int _pcderr(char **cmd, char *pname)
{
	dprintf(STDERR_FILENO, "%s: 1: cd: can't cd to %s\n", pname, cmd[1]);

	return (2);
}


/**
 * _pfilerr - print file errors
 * @status: err status code
 * @pname: name of the program
 * @filename: name of the file to open
 * Return: err status, 2
 */
int _pfilerr(int status, char *pname, char *filename)
{
	dprintf(STDERR_FILENO, "%s: 0: Can't open %s\n", pname, filename);

	return (status);
}

/**
 * _pcmdisfolder - user entered folder name as cmd, print err
 * @pname: program name
 * @cmd: user cmd
 * Return: err status
 */
int _pcmdisfolder(char *pname, char **cmd)
{
	dprintf(STDERR_FILENO, "%s: 1: %s: Permission denied\n", pname, cmd[0]);

	return (126);
}
