//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_PRODUCER_H
#define THREADSSYNC_PRODUCER_H
#include "../Structs.h"
#include "../Bounded/Bounded.h"
#include "../Article/Article.h"
void* producer (void* arg);
void freeProducer(producerData *data,Queue *queue,valueOfProducer *values,int size);
#endif //THREADSSYNC_PRODUCER_H
