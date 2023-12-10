//
// Created by lidor on 12/10/23.
//
#include "Article.h"
article createArticle(char *header,int i,int numberOfArticle){
    article a;
    a.id = i;
    a.numberArticle = numberOfArticle;
    a.header= header;
    return a;
}

void sortArticle(dispatcherBuffer *unBounded,int index,article a){
    sem_wait(&unBounded[index].queue->mutex);
    insertToUnBounded(unBounded[index].queue,a);
    sem_post(&unBounded[index].queue->fullSlots);
    sem_post(&unBounded[index].queue->mutex);
}