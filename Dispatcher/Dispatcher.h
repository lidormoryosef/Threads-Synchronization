//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_DISPATCHER_H
#define THREADSSYNC_DISPATCHER_H
#include "../Structs.h"
#include "../Unbounded/Unbounded.h"
#include "../Bounded/Bounded.h"
#include "../Article/Article.h"
#define WEATHER 0
#define NEWS 1
#define SPORTS 2
#include <string.h>
dispatcherData* createDispatcher(producerData *data,int size);
void* dispatcher (void *arg);
void freeDispatcher(dispatcherData *dispData);
#endif //THREADSSYNC_DISPATCHER_H
