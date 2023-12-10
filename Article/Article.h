//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_ARTICLE_H
#define THREADSSYNC_ARTICLE_H
#include "../Structs.h"
#include "../Unbounded/Unbounded.h"
article createArticle(char *header,int i,int numberOfArticle);
void sortArticle(dispatcherBuffer *unBounded,int index,article a);
#endif //THREADSSYNC_ARTICLE_H
