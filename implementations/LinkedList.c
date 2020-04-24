//
// Example input:
// 0 2
// 0 3
// 0 5
// 1 1
// 1 0
// 2 3
// 3 4
// 4 2
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int value_t;

// Representa um nó da lista encadeada
typedef struct Node {
    value_t value;
    struct Node* next;
} Node;

// Aloca um nó e coloca o valor desejado.
// Retorna um ponteiro para o nó alocado
Node* node_from(value_t value) {
    Node* n = (Node*)calloc(1, sizeof(Node));
    n->value = value;
    return n;
}


// Representa uma lista encadeada
// Possui apenas um ponteiro para o primeiro e o último elementos da lista
typedef struct LinkedList {
    Node* front;
    Node* back;
} LinkedList;

// Cria uma nova lista encadeada
LinkedList ll_new() {
    return (LinkedList) {
        .front = NULL,
        .back = NULL
    };
}

// Coloca um nó no final da lista (push back)
void ll_pushb(LinkedList* ll, Node* node) {
    if (!ll->front) {
        ll->front = ll->back = node;
    } else {
        Node* oldBack = ll->back;
        ll->back = node;
        oldBack->next = ll->back;
    }
}

// Coloca um nó no início da lista (push front)
void ll_pushf(LinkedList* ll, Node* node) {
    if (!ll->front) {
        ll->front = ll->back = node;
    } else {
        Node* oldFront = ll->front;
        ll->front = node;
        ll->front->next = oldFront;
    }
}

// Printa os elementos da lista
void ll_print(LinkedList* ll) {
    Node* n = ll->front;
    while (n) {
        printf("%d -> ", n->value);
        n = n->next;
    }
    puts("*");
}

// Coloca um nó "node" depois do nó "it"
void ll_insert(LinkedList* ll, Node* it, Node* node) {
    if (it == NULL) return;
    else if (it == ll->front) ll_pushf(ll, node);
    else if (it == ll->back)  ll_pushb(ll, node);
    else {
        Node* next = it->next;
        it->next = node;
        node->next = next;
    }
}

// Retorna um ponteiro para o nó com valor "value" ou NULL se esse nó não existe
Node* ll_find(LinkedList* ll, value_t value) {
    Node* n = ll->front;
    while (n) {
        if (n->value == value)
            return n;
        n = n->next;
    }
    return NULL;
}

// Deleta o nó com valor "value"
void ll_erase(LinkedList* ll, value_t value) {
    Node* n = ll->front;
    Node* last = NULL;
    while (n) {
        if (n->value == value) {
            // Nó encontrado!

            // Mudamos os "nexts", "front" e "back" conforme o necessário
            bool ismid = n != ll->front && n != ll->back;
            if (n == ll->front) ll->front = ll->front->next;
            if (n == ll->back) ll->back = last;
            if (ismid) last->next = n->next;

            // Liberamos o nó da memória
            free(n);

            // E saímos da função
            return;
        }
        last = n;
        n = n->next;
    }
    // Nó não foi encontrado
}

// Não gosto de escrever scanf toda hora
#define read(x) scanf("%d ", &x)

int main() {
    LinkedList ll = ll_new();

    Node* ans = NULL;

    int t, x;
    while (read(t) != -1) {
        read(x);

        // Nota: perceba que eu nunca fico com um ponteiro para um nó aqui na main!
        // Eu sempre crio os nós com node_from(x) e nunca salvo o retorno dessa função.
        // Isso evita que eu apague um nó com ll_erase (que dá free() no ponteiro pro nó!) e
        // depois tente usar o ponteiro (um dangling pointer).
        // Curiosidade: Esse é um conceito semelhante ao de "ownership" do Rust

        if (t == 0) {
            ll_pushb(&ll, node_from(x));
        } else if (t == 1) {
            ll_pushf(&ll, node_from(x));
        } else if (t == 2) {
            ans = ll_find(&ll, x);
        } else if (t == 3) {
            ll_insert(&ll, ans, node_from(x));
        } else if (t == 4) {
            ll_erase(&ll, x);
        }

        ll_print(&ll);
    }

    return 0;
}

