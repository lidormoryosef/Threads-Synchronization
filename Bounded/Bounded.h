//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_BOUNDED_H
#define THREADSSYNC_BOUNDED_H
#include "../Structs.h"
#include <stdlib.h>
void initBounded(producerData *data);
void insertToBounded(Queue *queue ,article a);
article removeFromBounded(Queue *queue);
#endif //THREADSSYNC_BOUNDED_H
