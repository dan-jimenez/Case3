#ifndef _QUEUE_
#define _QUEUE_ 0

#include "listadoble.h"

struct queue {
    struct listadoble queueList;

    bool isEmpty() {
        return queueList.isEmpty();
    };

    void enqueue(void* pElement) {
        queueList.addToEnd(pElement);
    };

    void* dequeue() {
        if (!queueList.isEmpty()) {
            return queueList.removeFirst();
        } else {
            return nullptr;
        }
    }

};

#endif