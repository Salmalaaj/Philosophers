# Philosophers

This project is a simulation of the classic "Dining Philosophers" problem, implemented in C. The goal is to manage multiple philosophers who alternately eat, think, and sleep, ensuring they do not starve while sharing limited resources (forks). The challenge is to use threads and mutexes to synchronize their actions and prevent data races.

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Files Description](#files-description)

## Introduction

The "Philosophers" project simulates a group of philosophers sitting at a table, thinking, eating, and sleeping. The simulation requires careful management of threads for each philosopher and the use of mutexes to handle shared resources (forks) to prevent race conditions.

## Project Structure

```bash
.
├── Makefile
├── args_stuff.c
├── philo.c
├── philosophers.h
├── routine.c
└── timing.c
```
## Compilation
To compile the project, simply run:
```bash
make
```
This will produce an executable named philo.

## Usage
Run the program with the following command:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- **number_of_philosophers**: The number of philosophers (and forks).
- **time_to_die**: Time (in milliseconds) after which a philosopher dies if they haven't started eating.
- **time_to_eat**: Time (in milliseconds) it takes for a philosopher to eat.
- **time_to_sleep**: Time (in milliseconds) a philosopher spends sleeping.
- **number_of_times_each_philosopher_must_eat** (optional): The simulation stops if each philosopher has eaten at least this many times.

## Files Description

- **Makefile**: Script to compile the project.
- **args_stuff.c**: Handles parsing and validation of command-line arguments.
- **philo.c**: Contains the main function and initializes the simulation.
- **philosophers.h**: Header file containing definitions and function prototypes.
- **routine.c**: Defines the routines for philosophers, including eating, thinking, and sleeping.
- **timing.c**: Handles timing functions, such as getting the current time in milliseconds.
