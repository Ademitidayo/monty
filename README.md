Monty Interpreter Project
Learning Objectives
At the end of this project, you are expected to be able to explain, without the help of Google:

General
The meanings of LIFO and FIFO.
What a stack is and when to use it.
What a queue is and when to use it.
Common implementations of stacks and queues.
The most common use cases of stacks and queues.
The proper way to use global variables.
Copyright - Plagiarism
You are tasked to come up with solutions for the tasks yourself to meet the learning objectives.
Avoid copying and pasting someone else’s work.
Plagiarism is strictly forbidden and will result in removal from the program.
Requirements
General
Allowed editors: vi, vim, emacs.
Compilation should be done on Ubuntu 20.04 LTS using gcc with options: -Wall -Werror -Wextra -pedantic -std=c89.
All files should end with a new line.
A README.md file, at the root of the project folder, is mandatory.
Code should use the Betty style, checked using betty-style.pl and betty-doc.pl.
A maximum of one global variable is allowed.
No more than 5 functions per file.
Use the C standard library.
Prototypes of all functions should be included in the header file called monty.h.
Don’t forget to push your header file.
All header files should be include guarded.
Follow the tasks in the order shown in the project.
GitHub
There should be one project repository per group.
Avoid creating a new repository with the same name before the second deadline.
More Information
Data structures
Use the following data structures for this project. Include them in your header file.

c
Copy code
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
Compilation & Output
Compile your code using the following command:

bash
Copy code
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Output should be printed on stdout.
Error messages should be printed on stderr.
Tests
Encourage collaboration on a set of tests.

The Monty Language
Monty Byte Code Files
Files containing Monty byte codes usually have the .m extension. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Example:

bash
Copy code
$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Monty byte code files can contain blank lines (empty or made of spaces only). Any additional text after the opcode or its required argument is not taken into account.

Example:

bash
Copy code
$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
The Monty Program
Usage:

bash
Copy code
$ monty file
file is the path to the file containing Monty byte code.

If the user does not provide any file or provides more than one argument to the program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE.

If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE.

If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE. <line_number> is the line number where the instruction appears.

Line numbers always start at 1.

The Monty program runs the bytecodes line by line and stops if either:

It executed properly every line of the file.
It finds an error in the file.
An error occurred.
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.

You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …).
