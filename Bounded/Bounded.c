//
// Created by lidor on 12/10/23.
//
#include "Bounded.h"
void initBounded(producerData *data){
    data->finish=0;
    data->queue->size=data->value->sizeOfQueue;
    data->queue->array= malloc(sizeof(article)*data->value->sizeOfQueue);
    data->queue->indexIn=0;
    data->queue->indexOut=0;
    sem_init(&data->queue->mutex, 1, 1);
    sem_init(&data->queue->fullSlots, 1, 0);
    sem_init(&data->queue->freeSlots, 1, data->value->sizeOfQueue);
}
void insertToBounded(Queue *queue ,article a){
    queue->array[queue->indexIn] = a;
    queue->indexIn = (queue->indexIn+1)%queue->size;
}
article removeFromBounded(Queue *queue){
    article a = queue->array[queue->indexOut];
    queue->indexOut = (queue->indexOut+1)%queue->size;
    return a;
}