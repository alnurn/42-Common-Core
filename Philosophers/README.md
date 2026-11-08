*This project has been created as part of the 42 curriculum by anurmach.*

# Philosophers

## Description

**Philosophers** is a concurrency project from the 42 curriculum.

The goal is to simulate the classic dining philosophers problem. Each philosopher alternates between eating, thinking and sleeping. To eat, a philosopher must hold two forks at the same time. The simulation must avoid data races, keep the output readable, and detect death precisely when a philosopher does not start eating within `time_to_die` milliseconds. The program can also stop early when every philosopher has eaten a required number of times.

This repository contains:

- `philo/` - mandatory implementation with threads and mutexes
- `philo_bonus/` - bonus implementation with processes and semaphores

## Mandatory Part

The mandatory version uses:

- one thread per philosopher
- one mutex per fork
- one shared monitor thread
- a mutex-protected `death` stop flag `dead`
- a mutex-protected `message` logging system
- per-philosopher meal mutexes to protect `eaten (number_of_times_each_philosopher_must_eat)`, `lasteat (philosopher's last meal time)` and `eating (The philosopher is currently eating)`

Each philosopher repeatedly:

1. takes two forks
2. eats
3. sleeps
4. thinks

A dedicated monitor thread checks whether a philosopher has exceeded `time_to_die` since the start of their last meal and if he is not currently eating. If so, the simulation stops and the death is printed. If the optional `number_of_times_each_philosopher_must_eat` argument is provided, the simulation also stops once every philosopher has eaten at least that many times.

To reduce deadlock risk, fork acquisition order is asymmetric. The single philosopher case is handled separately: the philosopher takes one fork and eventually dies because a second fork does not exist.

## Bonus Part

The bonus version uses:

- one process per philosopher
- The main process acts only as the simulation initializer and terminator. It also has an additional thread that kills all philosopher processes when the death of a philosopher is detected. A binary semaphore is used to signal a death event: a philosopher's child process performs a sem_post(), and the thread in the main process detects it and terminates all remaining processes.
- one semaphore representing the total number of forks
- a semaphore-protected logging system
- A binary semaphore `sem_dead`, acts as a trigger for the `killer` thread in the parent process, which terminates all child processes.
- one meal semaphore per philosopher to protect `eaten (number_of_times_each_philosopher_must_eat)`, `lasteat (philosopher's last meal time)` and `eating (The philosopher is currently eating)`

In the bonus version, the main process creates philosopher processes using `fork`. After that, the main process creates a `killer` thread that waits on the `sem_dead` semaphore and terminates all child processes if a philosopher dies. The main process then waits for the child processes using `waitpid()`.

Each philosopher process monitors its own death condition. If a philosopher dies, the process prints `died`, locks the `sem_print` semaphore, and performs a `sem_post` on `sem_dead` to notify the `killer` thread in the main process, which then terminates all child processes.

If each philosopher has eaten `number_of_times_each_philosopher_must_eat` times, the child processes exit normally, and the parent process waits for them using `waitpid()`.

## Instructions

### Mandatory Compilation

```bash
cd philo
make
```

### Mandatory Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Bonus Compilation

```bash
cd philo_bonus
make
```

### Bonus Execution

```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments

- `number_of_philosophers` - number of philosophers and forks
- `time_to_die` - time in milliseconds before a philosopher dies if they do not start eating
- `time_to_eat` - eating duration in milliseconds
- `time_to_sleep` - sleeping duration in milliseconds
- `number_of_times_each_philosopher_must_eat` - optional stop condition

### Example Runs

```bash
./philo 1 800 200 200
./philo 5 800 200 200
./philo 5 800 200 200 7
./philo 4 410 200 200
./philo 4 310 200 100
```

```bash
./philo_bonus 1 800 200 200
./philo_bonus 5 800 200 200
./philo_bonus 5 800 200 200 7
./philo_bonus 4 410 200 200
./philo_bonus 4 310 200 100
```

## Resources

References:

- https://www.youtube.com/@CodeVault
- `man pthread_create`
- `man pthread_join`
- `man pthread_mutex_init`
- `man pthread_mutex_lock`
- `man pthread_mutex_unlock`
- `man fork`
- `man waitpid`
- `man kill`
- `man sem_open`
- `man sem_wait`
- `man sem_post`
- `man sem_close`
- `man sem_unlink`
- `man gettimeofday`
