# Threads-Synchronization
## Overview
The News Broadcasting Simulation project is designed to provide hands-on experience with concurrent programming and synchronization mechanisms. The goal is to implement a system that simulates news broadcasting, where different types of news stories are produced, sorted, and displayed to the public. The project explores the impact of synchronization constructs under different loads.
## Scenario
In this simulation, news stories are represented by simple strings and should be displayed to the screen in the order they arrive. There are four types of active actors in the system:

1. __Producer__ : Generates strings in the format "producer <i> <type> <j>", where 'i' is the producer's ID, 'type' is a randomly chosen type ('SPORTS', 'NEWS', 'WEATHER'), and 'j' is the number of strings of the specified type produced. Producers communicate with the Dispatcher via their private queues.
2. __Dispatcher__: Accepts messages from Producer queues, sorts them, and inserts them into Dispatcher queues based on their type. It uses a Round Robin algorithm to scan Producer queues. Once all Producers are done, the Dispatcher sends a "DONE" message through each queue.
3. __Co-Editor__: Edits messages received from the Dispatcher queues and passes them to the Screen Manager via a shared queue. Editing involves blocking for 0.1 seconds. When a Co-Editor receives a "DONE" message, it immediately passes it through the shared queue.
4. __Screen Manager__: Displays messages received from Co-Editors to the screen (stdout). After printing all messages and receiving three "DONE" messages, the Screen Manager displays a final 'DONE' statement.

## System Design
The system follows the communication flow as depicted in the chart below:

![systemdesign](https://github.com/lidormoryosef/Threads-Synchronization/assets/118112616/fb7f008b-4334-42aa-8c4d-42c28ebc529d)
