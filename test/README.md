# Simple Shell

This project is a simple implementation of a shell in C. It currently supports the following features:

## Features

### Command Execution

The shell can execute commands found in the directories listed in the PATH environment variable. If a command is not found, it will print an error message and return.

### Built-in Commands

The shell supports the following built-in commands:

#### exit

The `exit` command terminates the shell.

Usage:

```bash
exit
```

#### env

The `env` command prints the current environment.

Usage:

```bash
env
```

## Implementation Details

The shell works by tokenizing the input command and its arguments, searching for the command in the PATH, and then forking a new process to execute the command.

The `exit` and `env` built-in commands are implemented by checking the command name against a list of built-in commands and calling the appropriate function if a match is found.

The shell uses the `strtok` function to tokenize the command and its arguments, the `getenv` function to get the PATH, and the `fork` and `execve` functions to create a new process and execute the command.

The shell handles errors such as command not found, fork failed, and waitpid failed by printing an error message and returning or exiting as appropriate.

## Future Work

Future versions of the shell will support more features such as command history, job control, and more built-in commands.

This README provides a brief overview of the project, describes the features it currently supports, explains how it works, and outlines future work. You can expand on this README as you continue to develop your shell.
