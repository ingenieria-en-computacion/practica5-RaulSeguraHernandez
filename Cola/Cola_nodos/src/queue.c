#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail =NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d){
    Node *new = new_node(d);
    if(queue_is_empty(q)){
        q->head=q->tail=new;
        return;
    }
    q->tail->next=new;
    q->tail = new;
}

Data queue_dequeue(Queue* q){
    if(!queue_is_empty(q)){
        Node* temp = q->head;
        int data = temp->data;
        if(q->head->next = NULL){
            
            q->head = NULL;
            q->tail =NULL;
            return data;
        }
        q->head = q->head->next;
        temp->next = NULL;
        delete_node(temp);
        return data;
     }
}

bool queue_is_empty(Queue* q){
    return q->tail ==NULL;
}

Data queue_front(Queue* q){
    if((q==NULL) ||(queue_is_empty(q)) ){
        printf("hubo un error");
        return  -100;
    }
    return q->head->data;
}

void queue_empty(Queue* q){
    if (q==NULL){
        printf("Cola inválida\n");
        return;
    }
    while(q->head!=NULL){
        queue_dequeue(q);
    }
    return;
}

void queue_delete(Queue* q){
    queue_empty(q);
    free(q);
    q = NULL;
}