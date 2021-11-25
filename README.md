# Philosophers - 42 School Project

[![akurz's 42Project Score](https://badge42.herokuapp.com/api/project/akurz/Philosophers)](https://github.com/JaeSeoKim/badge42)


## About

* Global variables are forbidden!
* One or more philosophers are sitting at a round table either eating, either thinking, either sleeping.
* The number of forks on the table is equal to the number of philosophers at the table.
* Philosophers will eat with two forks, one for each hand.
* Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops when a philosopher dies.
* Every philosopher needs to eat and they should never starve.
* The program should take the following arguments:  
number_of_philosophers   time_to_die time_to_eat   time_to_sleep   [number_of_times_each_philosopher_must_eat].  
1. number_of_philosophers: is the number of philosophers and also the number of forks.  
2. time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting their last meal or the beginning of the simulation, it dies.  
3. time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.  
4. time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.  
5. number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.  

## How to use

Clone the repository:
```bash
git clone https://github.com/42akurz/42_Philosophers.git
```
Go to the repository and run make
```bash
make
```
Call the executable together with a set of numbers seperated by a space (test cases in repository)
```bash
./philo 4 410 200 200
```
Use clean to delete all object files, fclean to remove all object files and executable and re to recompile the program
```bash
make clean / make fclean / make re
```
