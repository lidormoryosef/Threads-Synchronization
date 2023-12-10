//
// Created by lidor on 12/10/23.
//
#include "Editor.h"
editorData* createEditors(dispatcherBuffer *unBounded,int coEditorSize){
    editorData *array = malloc(sizeof (editorData)*3);
    Queue *queue = malloc(sizeof (Queue));
    queue->array= malloc(sizeof (article)*coEditorSize);
    queue->indexIn=0;
    queue->indexOut=0;
    queue->size=coEditorSize;
    sem_init(&queue->mutex, 0, 1);
    sem_init(&queue->fullSlots, 0, 0);
    sem_init(&queue->freeSlots, 0, coEditorSize);
    for (int i = 0; i < 3; ++i) {
        array[i].unBounded=&unBounded[i];
        array[i].bounded=queue;
    }
    return array;
}
void* editor(void *arg){
    editorData *data = (editorData *)arg;
    int toContinue=1;
    while (toContinue){
        sem_wait(&data->unBounded->queue->fullSlots);
        sem_wait(&data->unBounded->queue->mutex);
        article a= removeFromUnBounded(data->unBounded->queue);
        if(strcmp("Done",a.header)==0)
            toContinue=0;
        sem_post(&data->unBounded->queue->mutex);
        usleep(100000);
        sem_wait(&data->bounded->freeSlots);
        sem_wait(&data->bounded->mutex);
        insertToBounded(data->bounded,a);
        sem_post(&data->bounded->mutex);
        sem_post(&data->bounded->fullSlots);
    }
    return NULL;
}
void freeEditor(editorData *ediData){
    free(ediData->bounded->array);
    sem_destroy(&ediData->bounded->mutex);
    sem_destroy(&ediData->bounded->fullSlots);
    sem_destroy(&ediData->bounded->freeSlots);
    free(ediData->bounded);
    free(ediData);
}
