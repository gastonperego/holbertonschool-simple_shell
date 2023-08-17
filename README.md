# C - Simple shell - Foudations part 1 final project.

The shell is the Linux command line interpreter. It provides an interface between the user and the kernel and executes programs called commands. For example, if a user enters ls then the shell executes the ls command.

This project, simple_shell, is a custom implementation of a simple UNIX shell as a requirement to complete the first sprint in the <em></emHolberton>Holberton school Uruguay</em>. Taking a minimalistic approach, the many functions have been implemented, example:  <strong>execve, exit, fork, free, getline, malloc, perror, signal, stat, wait, etc.</strong>

### General.
***
- All files were compiled on Ubuntu 20.04 LTS using gcc, using the options: `` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 ``

- Betty coding style is followed.

### Installation.
***
- Designed to run on Ubuntu 20.04 LTS, the simple_shell can be installed as follows:
- Clone Git repository: ```https://github.com/gastonperego/holbertonschool-simple_shell```
- Move to the cloned directoy.
- Compile program using: `` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ``
- Run the progam in interative mode using ``./hsh`` or non-interactive mode with ``echo "ls" | ./hsh``

### Examples
***
- Running  on interactive mode
```
root@a106cf6bc0304aa6abf84137b82fb33d-2377118072:~/dev/shell# ./hsh
$ ls
README.md  hsh  shell.h  shell1.c
$ 
```

- Running  on non-interactive mode
```
root@a106cf6bc0304aa6abf84137b82fb33d-2377118072:~/dev/shell# echo "ls" | ./hsh
README.md  hsh  shell.h  shell1.c
root@a106cf6bc0304aa6abf84137b82fb33d-2377118072:~/dev/shell# 
```

### Used functions.
***


#### Main Function
- The `main` function initializes the shell loop, reads user input, tokenizes the input, and executes commands.
#### Prompt
- The `prompt` function displays a prompt symbol (`$`) to indicate that the shell is ready for user input.
#### Exiting the Shell
- The `_EOF` and `shell_exit` functions handle shell exit scenarios. The `_EOF` function frees memory and exits gracefully. The `shell_exit` function allows exiting the shell with an optional status code.
#### Tokening
- The `tokening` function tokenizes a given input string based on a specified delimiter. It returns an array of tokens.
#### Creating Child Processes
- The `create_child` function is responsible for creating and managing child processes to execute commands. It supports executing commands both with absolute paths and within directories listed in the PATH environment variable.
#### Getting the PATH
- The `get_path` function retrieves the PATH environment variable, tokenizes it, and returns an array of directory paths.
#### Printing Environment Variables
- The `print_env` function displays the current environment variables.
#### Freeing Memory
- The `free_dp` and `free_exit` functions are used to free memory allocated for arrays of strings.
#### Error Handling
- The `msgerror` function is used to display error messages when a command is not found.
#### Changing Directory
- The `change_dir` function attempts to change the current working directory to the specified path.
