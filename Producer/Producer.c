//
// Created by lidor on 12/10/23.
//
#include "Producer.h"
char *news[] = {"WEATHER","NEWS","SPORTS"};
void* producer (void* arg){
    producerData *data = (producerData*)arg;
    int j=0;
    int numberOfType[3]={0};
    for (int k = 0; k < data->value->numberOfArticle; ++k) {
        sem_wait(&data->queue->freeSlots);
        sem_wait(&data->queue->mutex);
        article a = createArticle(news[j % 3], data->value->producer, numberOfType[j%3]);
        insertToBounded(data->queue, a);
        sem_post(&data->queue->mutex);
        sem_post(&data->queue->fullSlots);
        numberOfType[j%3] = numberOfType[j%3] +1;
        j++;
    }
    sem_wait(&data->queue->freeSlots);
    sem_wait(&data->queue->mutex);
    article a = createArticle("Done", data->value->producer, j);
    insertToBounded(data->queue, a);
    sem_post(&data->queue->mutex);
    sem_post(&data->queue->fullSlots);
    return NULL;

}
void freeProducer(producerData *data,Queue *queue,valueOfProducer *values,int size){
    for (int i = 0; i < size-1; ++i) {
        free(data[i].queue->array);
        sem_destroy(&data[i].queue->mutex);
        sem_destroy(&data[i].queue->fullSlots);
        sem_destroy(&data[i].queue->freeSlots);
    }

    free(queue);
    free(values);
    free(data);
}