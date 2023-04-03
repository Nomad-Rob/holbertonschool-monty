0x19. C - Stacks, Queues - LIFO, FIFO
Description
The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

Environment
Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

Instructions
Resources📚
Read or watch:

Google
Create dynamic libraries on Linux
Learning Objectives💡
What you should learn from this project:

What do LIFO and FIFO mean
What is a stack, and when to use it
What is a queue, and when to use it
What are the common implementations of stacks and queues
What are the most common use cases of stacks and queues
What is the proper way to use global variables
Intructions basics
Compiling the program: gcc -Wall -Werror -Wextra -pedantic *.c -o monty

File Monty:

julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
            	   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
Struct:
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
Example
vagrant@vagrant-ubuntu-trusty-64:~/monty$ cat bytecodes/00.m
push 1
push 2
push 3
pall
vagrant@vagrant-ubuntu-trusty-64:~/monty$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty -g
vagrant@vagrant-ubuntu-trusty-64:~/monty$ ./monty bytecodes/00.m
3
2
1
vagrant@vagrant-ubuntu-trusty-64:~/monty$
