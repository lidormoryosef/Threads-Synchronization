//
// Created by lidor on 12/10/23.
//

#ifndef THREADSSYNC_EDITOR_H
#define THREADSSYNC_EDITOR_H
#include "../Structs.h"
#include <stdlib.h>
#include "../Unbounded/Unbounded.h"
#include <string.h>
#include <unistd.h>
#include "../Bounded/Bounded.h"
editorData* createEditors(dispatcherBuffer *unBounded,int coEditorSize);
void* editor(void *arg);
void freeEditor(editorData *ediData);
#endif //THREADSSYNC_EDITOR_H
