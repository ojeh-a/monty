
_______________0x19. C - Stacks, Queues - LIFO, FIFO_______________

-Group project:Algorithm and Data structure

-Project Goal: The goal of this project is to create an interpreter for Monty Bytecode files.

-Projecct by: Julien Barbier

-Authors: Hassan Ibrahim and Ojeh Agbaje.

Github repository:https: "github.com/ojeh-a/monty.git"


**********Learning Objectives**********

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

-What do LIFO and FIFO mean
-What is a stack, and when to use it
-What is a queue, and when to use it
-What are the common implementations of stacks and queues
-What are the most common use cases of stacks and queues
-What is the proper way to use global variables


Copyright - Plagiarism
You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
You are not allowed to publish any content of this project.
Any form of plagiarism is strictly forbidden and will result in removal from the program.


**********Requirements**********

----------General-----------

-Allowed editors: vi, vim, emacs
-All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
-All your files should end with a new line
-A README.md file, at the root of the folder of the project is mandatory
-Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
-You allowed to use a maximum of one global variable
-No more than 5 functions per file
-You are allowed to use the C standard library
-The prototypes of all your functions should be included in your header file called monty.h
-Don’t forget to push your header file
-All your header files should be include guarded
-You are expected to do the tasks in the order shown in the project

-GitHub: There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.


..........Data structures..........

Please use the following data structures for this project. Don’t forget to include them in your header file.

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


**********Compilation & Output**********

How code is compiled: "gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty"
-Any output must be printed on stdout
-Any error message must be printed on stderr


**********The Monty language**********

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

----Monty byte code files----
-Files containing Monty byte codes usually have the '.m' extension. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

$command: cat -e bytecodes/000.m
output:
{
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
}

-Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

command: cat -e bytecodes/001.m
Output:
{
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
}
pall This is the end of our program. Monty is awesome!$


**********The monty program**********

Usage: monty file
-where file is the path to the file containing Monty byte code
-If the user does not give any file or more than one argument, program prints the error message "USAGE: monty file", followed by a new line, and exit with the status "EXIT_FAILURE"
-If, for any reason, it’s not possible to open the file, program prints the error message "Error: Can't open file <file>", followed by a new line, and exit with the status "EXIT_FAILURE"
where <file> is the name of the file
-If the file contains an invalid instruction, print the error message "L<line_number>: unknown instruction <opcode>", followed by a new line, and exit with the status "EXIT_FAILURE"
-where is the line number where the instruction appears.
-Line numbers always start at 1

--The monty program runs the bytecodes line by line and stop if either:
-it executed properly every line of the file
-it finds an error in the file
-an error occured
-Prints the error message "Error: malloc failed", followed by a new line, and exit with status "EXIT_FAILURE" if malloc fails.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)


**********Tasks**********

**push, pall**

Implement the push and pall opcodes.

-The push opcode: The opcode "push" pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, program prints the error message "L<line_number>: usage: push integer", followed by a new line, and exit with the status "EXIT_FAILURE"
-where is the line number in the file


-The pall opcode: The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage: "pall"
(Nothing is printed if stack is empty)


***pint***

-The pint opcode: The opcode "pint" prints the value at the top of the stack, followed by a new line.

Usage: "pint"
If the stack is empty, the error message "L<line_number>: can't pint, stack empty" is printed, followed by a new line, and program exits with the status "EXIT_FAILURE"


***pop***

The pop opcode: The opcode "pop" removes the top element of the stack.

Usage: "pop"
If the stack is empty, error message "L<line_number>: can't pop an empty stack" is printed, followed by a new line, and program exits with the status "EXIT_FAILURE"


***swap***

mandatory
The swap opcode: The opcode swap swaps the top two elements of the stack.

Usage: "swap"
If the stack contains less than two elements, error message "L<line_number>: can't swap, stack too short" is printed, followed by a new line, and program exits with the status "EXIT_FAILURE"


***add***

The add opcode: The opcode "add" adds the top two elements of the stack.

Usage: "add"
If the stack contains less than two elements, error message "L<line_number>: can't add, stack too short" is printed, followed by a new line, and program  exits with the status "EXIT_FAILURE"
-The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
--The top element of the stack contains the result
--The stack is one element shorter

  
***nop***

The nop opcode: The opcode "nop" doesn’t do anything.

**********Advance Tasks**********


***sub***

The sub opcode: The opcode "sub" subtracts the top element of the stack from the second top element of the stack.

Usage: "sub"
If the stack contains less than two elements, the error message "L<line_number>: can't sub, stack too short" is printed, followed by a new line, and exits with the status "EXIT_FAILURE"
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
-- The top element of the stack contains the result
-- The stack is one element shorter


***div***

The div opcode: The opcode "div" divides the second top element of the stack by the top element of the stack.

Usage: "div"
- If the stack contains less than two elements, the error message "L<line_number>: can't div, stack too short" is printed, followed by a new line, and exits with the status "EXIT_FAILURE"
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
-- The top element of the stack contains the result
--The stack is one element shorter
-If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE


***mul***

The mul opcode: The opcode "mul" multiplies the second top element of the stack with the top element of the stack.

Usage: "mul"

- If the stack contains less than two elements, the error "message L<line_number>: can't mul, stack too short" is printed, followed by a new line, and exits with the status "EXIT_FAILURE"

- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
-- The top element of the stack contains the result
-- The stack is one element shorter


***mod***

The mod opcode: The opcode "mod" computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: "mod"

If the stack contains less than two elements, the error message "L<line_number>: can't mod, stack too short" is printed, followed by a new line, and program exits with the status "EXIT_FAILURE".

- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
-- The top element of the stack contains the result
-- The stack is one element shorter
-If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE



***comments***
Every good language comes with the capability of commenting. When the first non-space character of a line is "#", line is treated as a comment.


***pchar***

The pchar opcode: The opcode "pchar prints the char at the top of the stack, followed by a new line.

Usage: pchar
- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- If the value is not in the ascii table (man ascii), error message "L<line_number>: can't pchar, value out of range" is prrinted, followed by a new line, and program exits with the status "EXIT_FAILURE".
If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE


***pstr***

The pstr opcode: The opcode "pstr" prints the string starting at the top of the stack, followed by a new line.

Usage: "pstr"

- The integer stored in each element of the stack is treated as the ascii value of the character to be printed

- The string stops when either:
-- the stack is over
-- the value of the element is 0
-- the value of the element is not in the ascii table
- If the stack is empty, print only a new line


***rotl***

The rotl opcode: The opcode "rotl" rotates the stack to the top.

Usage: "rotl"
- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- "rotl" never fails


***rotr***

The rotr opcode - The opcode "rotr" rotates the stack to the bottom.

Usage: "rotr"
- The last element of the stack becomes the top element of the stack
- "rotr" never fails

  
***stack, queue***

- Implement the "stack" and "queue" opcodes.

**The stack opcode**

- The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

Usage: "stack"

**The queue opcode**

The opcode queue sets the format of the data to a queue (FIFO).

Usage: "queue"

- When switching mode:

- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack

***Brainf*ck***

Write a Brainf*ck script that prints School, followed by a new line.

All your Brainf*ck files should be stored inside the bf sub directory
You can install the "bf" interpreter to test your code: "sudo apt-get install bf"

Read: Brainf*ck

Directory: bf, File: 1000-school.bf
  
***Add two digits***

-Add two digits given by the user.

-Read the two digits from stdin, add them, and print the result

-The total of the two digits with be one digit-long (<10)

Directory: bf, File: 1001-add.bf
 

***Multiplication***

-Multiply two digits given by the user - Read the two digits from stdin, multiply them, and print the result

-The result of the multiplication will be one digit-long (<10)

Directory: bf, File: 1002-mul.bf


***Multiplication level up***

- Multiply two digits given by the user.


Read the two digits from stdin, multiply them, and print the result, followed by a new line

Directory: bf, File: 1003-mul.bf
