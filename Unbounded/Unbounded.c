//
// Created by lidor on 12/10/23.
//
#include "Unbounded.h"
void initUnBounded(dispatcherBuffer *data){
    data->finish=0;
    data->queue->size=2;
    data->queue->array= malloc(sizeof(article)*2);
    data->queue->indexIn=0;
    data->queue->indexOut=0;
    sem_init(&data->queue->mutex, 1, 1);
    sem_init(&data->queue->fullSlots, 1, 0);
}
void insertToUnBounded(Queue *queue ,article a){
    if(queue->indexIn>=queue->size)
    {
        queue->size=queue->size*2;
        queue->array = (article *)realloc(queue->array,sizeof (article)*(queue->size));
    }
    queue->array[queue->indexIn] = a;
    queue->indexIn = queue->indexIn+1;
}
article removeFromUnBounded(Queue *queue){
    article a = queue->array[queue->indexOut];
    queue->indexOut = queue->indexOut+1;
    return a;
}
