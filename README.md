# Simple Shell Project

## Synopsis
A recreation of a shell with a basic Unix command-line interpretor.

## Description
BENRON shell takes in simple Unix commands and inliments them in the shell one command at a time. After the command is typed the shell will execute the command and print the output to the terminal with a new commandline for another set of arguments.
## Usage
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:

<code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</code>

Once compiled, to start the program, run:

<code>$ ./hsh</code>

To exit the program, run:

<code>BENRON $ exit</code>

## Built-Ins

The following built-in is supported by BENRON Shell

<code>env</code> -Prints the current working environment

## Return Value

BENRON Shell will run with a return value of 0, or a 1 if command failed.

### List of Functions

These functions make up the main file. Helper functions are not included.
| Function | Description |
| -------  | ------      |
|tokenize_string |  tokenizes a string into an array of strings based on the delimiter provided |
|check_path | checks all possible paths with the input and assigns the path |
| create_child | creates a child process that executes the argument for the main process to wait on |

