#include <pthread.h>
#include "Structs.h"
#include "Bounded/Bounded.h"
#include "Producer/Producer.h"
#include "Dispatcher/Dispatcher.h"
#include "Editor/Editor.h"
#include "ScreenManger/ScreenManger.h"
#include <stdio.h>
int size=1;
valueOfProducer* createData(char *conf);

int main(int argc, char* argv[]) {
    if(argc!=2)
    {
        printf("Error in the number of parameters\n");
        exit(-1);
    }
    valueOfProducer *values=createData(argv[1]);
    Queue *queue = malloc(sizeof (Queue)*(size-1));
    producerData *data = malloc(sizeof (producerData)*(size-1));
    int coEditorSize = values[size-1].producer;
    pthread_t threadsProducer[size-1],threadsEditors[3],threadDispatcher,threadScreen;
    for (int i = 0; i < size-1; ++i) {
        data[i].queue=&queue[i];
        data[i].value=&values[i];
        initBounded(&data[i]);
    }
    for (int i = 0; i < size-1; ++i) {
        pthread_create(&threadsProducer[i],NULL,producer,(void *)&data[i]);
    }
    dispatcherData *dispData = createDispatcher(data,size);
    pthread_create(&threadDispatcher,NULL,dispatcher,(void *)dispData);
    editorData *ediData=createEditors(dispData->unBounded,coEditorSize);
    Queue *screen = ediData->bounded;
    for (int j = 0; j < 3; ++j) {
        pthread_create(&threadsEditors[j],NULL,editor,(void *)&ediData[j]);
    }
    pthread_create(&threadScreen,NULL,screenManger,(void *)screen);
    for (int j = 0; j < size-1; ++j) {
        pthread_join(threadsProducer[j],NULL);
    }
    pthread_join(threadDispatcher,NULL);
    for (int j = 0; j < size-1; ++j) {
        pthread_join(threadsEditors[j],NULL);
    }
    pthread_join(threadScreen,NULL);
    freeProducer(data,queue,values,size);
    freeDispatcher(dispData);
    freeEditor(ediData);
    return 0;
}
valueOfProducer* createData(char *conf){
    FILE *file= fopen(conf,"r");
    if(file==NULL){
        printf("Error in: open\n");
        exit(-1);
    }
    valueOfProducer *data = (valueOfProducer*)malloc(sizeof (valueOfProducer));
    int producer,numberOfArticle,sizeOfQueue,result;
    while((result=fscanf(file,"%d\n %d\n %d\n",&producer,&numberOfArticle,&sizeOfQueue))==3){
        data[size-1].producer=producer-1;
        data[size-1].numberOfArticle=numberOfArticle;
        data[size-1].sizeOfQueue=sizeOfQueue;
        size = size +1;
        data = (valueOfProducer*)realloc(data,sizeof (valueOfProducer)*(size));
    }
    fscanf(file,"%d",&data[size-1].producer);
    data[size-1].producer=producer;
    fclose(file);
    return data;

}