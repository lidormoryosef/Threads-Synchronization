//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_STRUCTS_H
#define THREADSSYNC_STRUCTS_H

#include <semaphore.h>

typedef struct {
    int producer;
    int numberOfArticle;
    int sizeOfQueue;
}valueOfProducer;
typedef struct{
    int id;
    int numberArticle;
    char *header;

}article;
typedef struct {
    int size;
    int indexIn;
    int indexOut;
    sem_t mutex;
    sem_t freeSlots;
    sem_t fullSlots;
    article *array;
}Queue;
typedef struct {
    Queue *queue;
    valueOfProducer *value;
    int finish;

}producerData;
typedef struct {
    Queue *queue;
    int finish;
}dispatcherBuffer;
typedef struct {
    producerData *bounded;
    dispatcherBuffer *unBounded;
    Queue *queueOnlyForDelete;
    int size;
}dispatcherData;
typedef struct {
    dispatcherBuffer *unBounded;
    Queue *bounded;
}editorData;
#endif //THREADSSYNC_STRUCTS_H
