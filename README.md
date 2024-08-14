# push_swap
Push_swap project for 42cursus

Currently works only on macOS and linux systems.

Problem:
Given a set of integers, sort it in ascending order using a predefined set of instructions using two stacks and the smallest number of moves. At the start, stack ```a``` recieves a random number of integer values and stack ```b``` that is used for sorting is empty. The instruction set is defined below. This program outputs a set of push_swap instructions that sorts the input integers in ascending order.

```sa``` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. \
```sb``` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. \
```ss``` : ```sa``` and ```sb``` at the same time. \
```pa``` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. \
```pb``` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. \
```ra``` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one. \
```rb``` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one. \
```rr``` : ```ra``` and ```rb``` at the same time. \
```rra``` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one. \
```rrb``` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one. \
```rrr``` : ```rra``` and ```rrb``` at the same time.

Bonus part:
A checker program that recieves a set of unsorted integers as an argument and then it opens the read from console that must recieve instructions for sorting the given stack. If the given instructions are correct and in the end the stack is sorted, checker will return an "OK", else it will return a "KO".

All of the following actions must be done inside the copied project's directory, in the command line.

Compilation:
- run "make"

Compilation for bonus part:
- run "make bonus"

Clean object files:
- run "make clean"

Full clean object and library files:
- run "make fclean"

Recompilation:
- run "make re"
