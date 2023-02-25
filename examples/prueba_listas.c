#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    /* data */
    char *name;
    struct s_node *next;
} t_node;

t_node *initializeNode(t_node *node) {
    node = NULL;
    return node;
}

t_node *addNode(t_node *node, char *name) {
    t_node *newNode;
    t_node *aux;
    newNode = malloc(sizeof(t_node));
    newNode->name = name;
    newNode->next = NULL;
    if (node == NULL) {
        node = newNode;
    } else {
        aux = node;
        while(aux->next != NULL){
            printf("%s -> ", aux->name);
            aux = aux->next;
        }
        printf("\n");
        aux->next = newNode;
    }
    return node;
}

int main() {
    t_node *node = initializeNode(node);
    node = addNode(node, "a");
    node = addNode(node, "b");
    node = addNode(node, "c");
    node = addNode(node, "d");
    node = addNode(node, "e");


    while (node != NULL)
    {
        printf("%s\n", node->name);
        node = node->next;
    }
    return 0;
}