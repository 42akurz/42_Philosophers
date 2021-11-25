# Philosophers - 42 School Project


## About


## Threads


## Reaper


## How to use

Clone the repository:
```bash
https://github.com/42akurz/42_push_swap.git
```
Go to the repository and run make
```bash
make
```
run make bonus to compile checker files
```bash
make bonus
```
Call the executable together with a set of numbers seperated by a space
```bash
./push_swap 10 7 8 2 3 6 1 4 9 5
```
To run the checker on push swap, use the pipe operator
```bash
ARG="10 7 8 2 3 6 1 4 9 5"; ./push_swap $ARG | ./CHECKER $ARG
```
Use clean to delete all object files, fclean to remove all object files and executable and re to recompile the program
```bash
make clean / make fclean / make re
```
