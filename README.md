# Threads-Synchronization
## Overview
The News Broadcasting Simulation project is designed to provide hands-on experience with concurrent programming and synchronization mechanisms. The goal is to implement a system that simulates news broadcasting, where different types of news stories are produced, sorted, and displayed to the public. The project explores the impact of synchronization constructs under different loads.
## Scenario
In this simulation, news stories are represented by simple strings and should be displayed to the screen in the order they arrive. There are four types of active actors in the system:

1. ### __Producer__ : Generates strings in the format "producer <i> <type> <j>", where 'i' is the producer's ID, 'type' is a randomly chosen type ('SPORTS', 'NEWS', 'WEATHER'), and 'j' is the number of strings of the specified type produced. Producers communicate with the Dispatcher via their private queues.
