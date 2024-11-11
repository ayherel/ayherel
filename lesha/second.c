#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция для создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления узла в конец списка
void append(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);

    if (*head_ref == NULL) {
        // Если список пустой, создаем начальный узел и сразу замыкаем его на себя
        *head_ref = new_node;
        new_node->next = new_node; // Создает цикл
    } else {
        Node* last = *head_ref;
        
        // Находим последний узел, который ссылается на голову (начало цикла)
        while (last->next != *head_ref) {
            last = last->next;
        }
        
        // Добавляем новый узел в конец и замыкаем цикл на голову
        last->next = new_node;
        new_node->next = *head_ref;
    }
}


// Функция для вывода адресов узлов
void printAddresses(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    Node* pred = NULL;
    do {
        printf("Адрес узла с данными %d: %p - %p\n", current->data, current, current->next);
        pred = current;
        current = current->next;
    } while (current != head);
}

// Функция для обмена узлов, следующих за узлами с индексами t и u
void swapNodes(Node** head, int t_index, int u_index) {
    if (t_index == u_index) {
        printf("Индексы t и u должны быть разными.\n");
        return;
    }

    // Обеспечим, что t_index < u_index для упрощения логики
    if (t_index > u_index) {
        int temp = t_index;
        t_index = u_index;
        u_index = temp;
    }

    // Инициализация указателей для обхода списка
    Node *pred_t = NULL, *pred_u = NULL;
    Node *curr_t = *head, *curr_u = *head;

    // Находим узлы с индексами t и u
    for (int i = 0; i < t_index; i++) {
        pred_t = curr_t;
        curr_t = curr_t->next;
    }
    for (int i = 0; i < u_index; i++) {
        pred_u = curr_u;
        curr_u = curr_u->next;
    }

    Node *sled_t = curr_t->next;
    Node *sled_u = curr_u->next;

    // Проверка на смежные узлы
    if (curr_t->next == curr_u) {
        // Узлы смежные, t -> u
        pred_t->next = curr_u;
        curr_u->next = curr_t;
        curr_t->next = sled_u;
    } else if (curr_u->next == curr_t) {
        // Узлы смежные, u -> t
        pred_u->next = curr_t;
        curr_t->next = curr_u;
        curr_u->next = sled_t;
    } else {
        // Узлы не смежные, обобщенный случай
        if (pred_t) pred_t->next = curr_u;
        if (pred_u) pred_u->next = curr_t;

        Node* temp = curr_t->next;
        curr_t->next = curr_u->next;
        curr_u->next = temp;

        // Обновляем голову, если поменяли местами с первым узлом
        if (*head == curr_t) *head = curr_u;
        else if (*head == curr_u) *head = curr_t;
    }
}



// Основная функция
int main() {
    setlocale(LC_ALL, "RUS");
    Node* head1 = NULL;
    Node* head = head1;
    int n, data, i;

    printf("Введите количество узлов в списке: ");
    scanf("%d", &n);

    // Ввод данных для списка
    for (i = 0; i < n; i++) {
        printf("Введите значение узла %d: ", i + 1);
        scanf("%d", &data);
        append(&head, data);
    }



    // Вывод адресов узлов до обмена
    printf("Адреса узлов до обмена:\n");
    printAddresses(head);

    int t_index, u_index;
    printf("Введите индекс узла t (1 до %d): ", n);
    scanf("%d", &t_index);
    printf("Введите индекс узла u (1 до %d): ", n);
    scanf("%d", &u_index);

    // Обмен узлов
    swapNodes(&head, t_index, u_index);

    printf("Список после обмена: \n");
    printAddresses(head);


    // Освобождение памяти
    if (head != NULL) {
        Node* current = head;
        Node* next;
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }

    getch();
    return 0;
}
