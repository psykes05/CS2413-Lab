#225
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (!queue) return NULL;
    queue->capacity = 100;
    queue->data = (int*)malloc(sizeof(int) * queue->capacity);
    if (!queue->data) {
        free(queue);
        return NULL;
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

void myQueuePush(MyQueue* queue, int element) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->data = (int*)realloc(queue->data, sizeof(int) * queue->capacity);
         if (!queue->data) return;
    }
    if (queue->size == 0) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->data[queue->rear] = element;
    queue->size++;
}

int myQueuePop(MyQueue* queue) {
    if (queue->size == 0) return -1;
    int element = queue->data[queue->front];
    if (queue->size == 1) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    queue->size--;
    return element;
}

int myQueuePeek(MyQueue* queue) {
   if (queue->size == 0) return -1;
    return queue->data[queue->front];
}

bool myQueueEmpty(MyQueue* queue) {
    return queue->size == 0;
}

void myQueueFree(MyQueue* queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

typedef struct {
    MyQueue* q1;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    if (!stack) return NULL;

    stack->q1 = myQueueCreate();
    if (!stack->q1) {
        free(stack);
        return NULL;
    }
    return stack;
}

void myStackPush(MyStack* stack, int x) {
    myQueuePush(stack->q1, x);
    int size = stack->q1->size;
    while (size > 1) {
        myQueuePush(stack->q1, myQueuePop(stack->q1));
        size--;
    }
}

int myStackPop(MyStack* stack) {
    return myQueuePop(stack->q1);
}

int myStackTop(MyStack* stack) {
    return myQueuePeek(stack->q1);
}

bool myStackEmpty(MyStack* stack) {
    return myQueueEmpty(stack->q1);
}

void myStackFree(MyStack* stack) {
    if (stack) {
        myQueueFree(stack->q1);
        free(stack);
    }
}





#232
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100;
    obj->stack1 = (int*)malloc(obj->capacity * sizeof(int));
    obj->stack2 = (int*)malloc(obj->capacity * sizeof(int));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
