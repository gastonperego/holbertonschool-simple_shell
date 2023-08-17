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
### Flow chart.
***
![Flowchart](https://github.com/gastonperego/holbertonschool-simple_shell/assets/135220699/a8b62edc-3e22-4ef9-b551-dfc351b66c09)

### Used functions.
***



#### Main Function
- The `main` function initializes the shell loop, reads user input, tokenizes the input, and executes commands.
#### Prompt
- The `prompt` function displays a prompt symbol (`$`) to indicate that the shell is ready for user input.
#### Handle
- A signal handler function that takes a signal parameter but doesn't perform any action in the given code. This function can be used to handle signals, but it's not used extensively in the current implementation.
#### _EOF
- This function handles the end of input (EOF) scenario. It frees the memory allocated for the input buffer and prints a newline if the input was read from a terminal before exiting.
#### shell_exit
- Handles the `exit` command. It takes an array of arguments (`command`) and, if provided, converts the first argument to an integer and exits the shell with the given status code. It also frees memory allocated for the command.
#### print_env
- Prints the current environment variables by iterating through the `environ` array.
#### free_dp
- Frees the memory allocated for an array of command arguments (`command`). It iterates through the array and then frees the array itself.
#### free_exit
- Frees the memory allocated for an array of command arguments (`command`) and exits the shell with a failure status.
#### msgerror(cicles, command)
- Prints an error message when a command is not found. It takes the count of cycles (`cicles`) and the array of command arguments (`command`) as parameters.
#### change_dir
- Attempts to change the current directory to the provided path. Returns 1 on success and prints an error message if unsuccessful.
#### tokening
- Tokenizes an input string (`input`) based on a delimiter string (`delim`). Returns an array of tokens.
#### create_child
- Creates a child process to execute a command. Checks whether the command is an external command or a built-in command (`env`), and then forks and executes accordingly.
#### get_path
- Extracts the `PATH` environment variable, tokenizes it, and returns an array containing the directories in the `PATH`.
#### forker
- Forks a child process to execute an external command (`command`) by searching for the command in the provided directories (`path`).
#### forker2
- Searches for an external command (`command`) in the provided directories (`path`). If found, forks a child process to execute the command.

###Authors
***
This shell program was created by Gaston Perego and Martin Abreu as a project for Holberton School Uruguay. You can contact the authors at 6754@holbertonstudents.com and 6757@holbertonstudents.com.

