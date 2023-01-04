#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 30000

typedef struct node {
    char name[15];
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

int arr[N] = {0};
LinkedList list[N] = {0};

int hash(char *s);

void push(int Hash, char *input);

void check(int Hash, char *input, int m);

void compare(Node *node, char *input);

int main() {
    int m, q;
    int Hash;
    scanf("%d%d", &m, &q);
    for (int i = 0; i < m; i++) {
        char *input = calloc(1, 1000 * sizeof(char));
        scanf("%s", input);
        Hash = hash(input);
        if (Hash == 0) {
            assert(0);
        }
        push(Hash, input);
        free(input);
    }
    for (int i = 0; i < q; i++) {
        char *input = calloc(1, 1000 * sizeof(char));
        scanf("%s", input);
        Hash = hash(input);
        if (Hash == 0) {
            assert(0);
        }
        check(Hash, input, m);
        free(input);
    }
    return 0;
}

int hash(char *s) {
    int ret = 0;
    for (int i = 0; i < 13; i++) {
        ret = (ret + s[i] * (i + 1)) % N;
    }
    return ret;
}

void push(int Hash, char *input) {
    Node *node1 = malloc(sizeof(*node1));
    node1->next = NULL;
    for (int j = 0; j < N; j++) {
        if (arr[j] == 0) {
            arr[j] = Hash;
            strncpy(node1->name, input, 15);
            list[j].head = node1;
            list[j].tail = node1;
            return;
        } else if (arr[j] == Hash) {
            strncpy(node1->name, input, 15);
            list[j].tail->next = node1;
            list[j].tail = node1;
            return;
        }
    }
}

void check(int Hash, char *input, int m) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == Hash) {
            compare(list[i].head, input);
            return;
        }
    }
    printf("No\n");
}

void compare(Node *node, char *input) {
    if (strncmp(node->name, input, 15) == 0) {
        printf("Yes\n");
        return;
    }
    if (node->next == NULL) {
        printf("No\n");
        return;
    }
    compare(node->next, input);
}