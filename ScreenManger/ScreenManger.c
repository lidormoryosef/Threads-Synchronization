//
// Created by lidor on 12/10/23.
//
#include "ScreenManger.h"
void* screenManger(void *arg){
    Queue *queue = (Queue *)arg;
    int counterToFinish=3;
    int index=0;
    while (counterToFinish){
        sem_wait(&queue->fullSlots);
        sem_wait(&queue->mutex);
        index++;
        article a = removeFromBounded(queue);
        if(strcmp("Done",a.header)==0)
            counterToFinish--;
        else
            printf("Producer %d %s %d\n", a.id, a.header, a.numberArticle);
        sem_post(&queue->mutex);
        sem_post(&queue->freeSlots);
    }
    printf("DONE\n");
    return NULL;
}