//
// Created by lidor on 12/10/23.
//
#include "Dispatcher.h"
dispatcherData* createDispatcher(producerData *data,int size){
    dispatcherData *array = malloc(sizeof (dispatcherData));
    array->size=size;
    array->bounded=data;
    array->unBounded= malloc((sizeof (dispatcherBuffer))*3);
    Queue *queue = malloc(sizeof (Queue)*3);
    array->queueOnlyForDelete=queue;
    for (int i = 0; i < 3; ++i) {
        array->unBounded[i].queue=&queue[i];
        initUnBounded(&array->unBounded[i]);
    }
    return array;
}
void* dispatcher (void *arg){
    dispatcherData *data = (dispatcherData*)arg;
    int toContinue=1;
    int index=0;
    while (toContinue){
        toContinue=0;
        for (int i = 0; i < data->size-1; ++i) {
            if(!data->bounded[i].finish) {
                toContinue = 1;
                sem_wait(&data->bounded[i].queue->fullSlots);
                sem_wait(&data->bounded[i].queue->mutex);
                article a = removeFromBounded(data->bounded[i].queue);
                if(strcmp("Done",a.header)==0)
                    data->bounded[i].finish=1;
                sem_post(&data->bounded[i].queue->mutex);
                sem_post(&data->bounded[i].queue->freeSlots);
                index++;
                if(strcmp("WEATHER",a.header)==0){
                    sortArticle(data->unBounded,WEATHER,a);
                }
                else if(strcmp("NEWS",a.header)==0){
                    sortArticle(data->unBounded,NEWS,a);
                }
                else if(strcmp("SPORTS",a.header)==0){
                    sortArticle(data->unBounded,SPORTS,a);
                }

            }
        }

    }
    article a0 = createArticle("Done",WEATHER,-1);
    sortArticle(data->unBounded,WEATHER,a0);
    article a1 = createArticle("Done",NEWS,-1);
    sortArticle(data->unBounded,NEWS,a1);
    article a2 = createArticle("Done",SPORTS,-1);
    sortArticle(data->unBounded,SPORTS,a2);
    return NULL;
}
void freeDispatcher(dispatcherData *dispData){
    for (int i = 0; i < 3; ++i) {
        free(dispData->queueOnlyForDelete[i].array);
        sem_destroy(&dispData->queueOnlyForDelete[i].mutex);
        sem_destroy(&dispData->queueOnlyForDelete[i].fullSlots);

    }
    free(dispData->queueOnlyForDelete);
    free(dispData->unBounded);
    free(dispData);


}