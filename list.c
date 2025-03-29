#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data; // Puntero al dato
    Node * next; // Puntero al siguiente nodo
    Node * prev; // Puntero al nodo previo
};

struct List {
    Node * head; // Puntero al primer elemento
    Node * tail; // Puntero al ultimo elemento
    Node * current; // Puntero para poder recorrer la lista
} List;


typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* list = (List*) malloc(sizeof(List));
    if (list == NULL) 
        exit(EXIT_FAILURE);
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

void * firstList(List * list) {
    if (list == NULL || list->head == NULL)
        return NULL;
    list->current =list->head;
    return list->current->data;
}

void * nextList(List * list) {
    if (list == NULL || list->current == NULL || list->current->next == NULL) 
        return NULL;
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if (list == NULL || list->tail == NULL)
        return NULL;
    list->current = list->tail;
    return list->current->data;
}

void * prevList(List * list) {
    if (list == NULL || list->current == NULL || list->current->prev == NULL)
        return NULL;
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    nuevoNodo = createNode(data);
    if (list->head == NULL) {
        list->head = nuevoNodo;
        list->tail = nuevoNodo;
        list->current = nuevoNodo;
    }
    else {
        nuevoNodo->next = list->head;
        list->head->prev = nuevoNodo;
        list->head = nuevoNodo;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if (list == NULL || list->current == NULL)
        return;
    
    nuevoNodo = createNode(data);

    nuevoNodo->next = list->current->next;
    if (list->current->next != NULL)
        list->current->next->prev = nuevoNodo;
    
    list->current->next = nuevoNodo;
    nuevoNodo->prev = list->current;

    if (list->current == list->tail)
        list->tail = nuevoNodo;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if (list == NULL || list->current == NULL)
        return NULL;
    
    tempo = list->current;
    data = temp.data;

    if (tempo->prev != NULL)
        tempo->prev->next = tempo->next;
    else
        list->head = tempo->next;
    
    if (tempo->next != NULL)
        tempo->next->prev = tempo->prev;
    else
        list->tail = tempo->prev;
    
    list->current = tempo->next;

    free(tempo);
    return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}