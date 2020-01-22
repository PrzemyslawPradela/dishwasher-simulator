## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
Simple dishwasher simulator based on message queues on Linux.

## Technologies
Project is created with:
* C
* Makefile

## Setup
1. Install [GCC](https://gcc.gnu.org)
2. Install MAKE for running Makefiles
3. Clone this repository
4. To run this project:
    - Run a main dishwasher controller 
        ```bash
        $ cd ../dishwasher-simulator/main
        $ mkdir bin
        $ make
        $ ./bin/main
        ```
    - Run a heater controller
        ```bash
        $ cd ../dishwasher-simulator/heater
        $ mkdir bin
        $ make
        $ ./bin/main
        ```
    - Run a water pump controller
        ```bash
        $ cd ../dishwasher-simulator/pump
        $ mkdir bin
        $ make
        $ ./bin/main
        ```
    - Run a spray arms controller
        ```bash
        $ cd ../dishwasher-simulator/sprayarms
        $ mkdir bin
        $ make
        $ ./bin/main
        ```
