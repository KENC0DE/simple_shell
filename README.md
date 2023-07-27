# Simple Shell

This is a simple UNIX shell implementation written in C. It provides basic functionality of a shell such as executing commands, handling signals, and managing processes.

## Getting Started

To get started, clone this repository:

```
git clone https://github.com/your-username/simple_shell.git
```

Compile the shell using the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

To run the shell, simply execute the resulting `hsh` binary:

```
./hsh
```

## Usage

Once the shell is running, you can enter commands just like you would in a regular UNIX shell. The shell supports the following features:

- Running commands with arguments
- Running commands in the background by appending `&` to the command
- Printing the current working directory using the `pwd` command
- Exiting the shell using the `exit` command or by pressing `Ctrl-D`

## Built-in Commands

The shell supports the following built-in commands:

- 'ls': displays all files in the working dir.
- `help`: Prints a brief usage message for the shell.
- `exit`: Exits the shell.
and many others.

## Authors

- taju siraj ([taju7798@gmail.com↗](https://github.com/tajukasim))
- Ken Nguse ([kenansameseret@gmail.com>↗](https://github.com/KENC0DE))

## Acknowledgments

don't copy it.
