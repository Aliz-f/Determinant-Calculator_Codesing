#include <stdio.h>

struct fifo_vector {
    int *f;
    int * readPointer;
    int * wrtiePointer;
};

void fifo_vector_empty(struct fifo_vector * v);

void fire_det2_actor(struct fifo_vector * dataInput, struct fifo_vector * output);

void init_fifo_vector(struct fifo_vector * v, int * position);

void fifo_vector_push(struct fifo_vector * v, int value);

int univerctor_pop(struct fifo_vector * v);


void main() {
    int numbers1[5] = {1, 2, 3, 4, 5};
    int numbers2[5] = {1, 2, 3, 4, 5};

    struct fifo_vector dataQueue;
    struct fifo_vector outputQueue;
    
    init_fifo_vector(&dataQueue, numbers1);
    init_fifo_vector(&outputQueue, numbers2);

    while (1) {
        int a, b, c, d;
        
        printf("enter the first data: ");
        scanf("%d", &a);
        fifo_vector_push(&dataQueue, a);
        printf("enter the second data: ");
        scanf("%d", &b);
        fifo_vector_push(&dataQueue, b);
        printf("enter the third data: ");
        scanf("%d", &c);
        fifo_vector_push(&dataQueue, c);
        printf("enter the forth data: ");
        scanf("%d", &d);
        fifo_vector_push(&dataQueue, d);
        
        fire_det2_actor(&dataQueue, &outputQueue);

        printf("the token on the output queue is: %d\n", univerctor_pop(&outputQueue));
    }
    fifo_vector_empty(&dataQueue);
    fifo_vector_empty(&outputQueue);
}


void init_fifo_vector(struct fifo_vector *v, int * position) {
    v->f = position;
    v->readPointer = v->f;
    v->wrtiePointer = v->f;
}

void fifo_vector_push(struct fifo_vector *v, int value) {
    *v->wrtiePointer = value;
    v->wrtiePointer +=  1;
}

int univerctor_pop(struct fifo_vector *v) {
    int value = *v->readPointer;
    v->readPointer += 1;
    return value;
}

void fifo_vector_empty(struct fifo_vector * v) {
    v->readPointer = v->f;
    v->wrtiePointer = v->f;
}

void fire_det2_actor(struct fifo_vector * dataInput, struct fifo_vector * output) {
    int a_in = univerctor_pop(dataInput);
    int b_in = univerctor_pop(dataInput);
    int c_in = univerctor_pop(dataInput);
    int d_in = univerctor_pop(dataInput);
    int result = (a_in*d_in) - (b_in*c_in);
    fifo_vector_push(output, result);
}