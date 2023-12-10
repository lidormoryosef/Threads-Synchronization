//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_UNBOUNDED_H
#define THREADSSYNC_UNBOUNDED_H
#include "../Structs.h"
#include <stdlib.h>
void initUnBounded(dispatcherBuffer *data);
void insertToUnBounded(Queue *queue ,article a);
article removeFromUnBounded(Queue *queue);
#endif //THREADSSYNC_UNBOUNDED_H
