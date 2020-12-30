#include <stdio.h>
#include <stdlib.h>
#include <clocale> //Обязательно для функции setlocale()
#include <ctime>

#define STACK_INIT_SIZE 100

// Дерево будет состоять из узлов.
typedef struct Node { // Структура узла дерева.
    int data; // Значение узла дерева - число.
    struct Node* head; // Указатель на корневой узел.
    struct Node* left; // Указатель на левый подузел.
    struct Node* right; // Указатель на правый полузел.
} Node;

Node* createNode() {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = NULL;
    tmp->head = NULL;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}

// Стек представляет из себя массив всех узлов дерева для обхода.
typedef struct Stack {
    size_t size; // Размер стека.
    size_t limit; // Лимит размера стека.
    Node** data; // Наполнение стека - узлы дерева.
} Stack;

Stack* createStack() { // Функция создания стека.
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    tmp->limit = STACK_INIT_SIZE;
    tmp->size = 0;
    tmp->data = (Node**)malloc(tmp->limit * sizeof(Node*));
    return tmp;
}

void freeStack(Stack** stack) { // Функция очистки стека.
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void push(Stack* stack, Node* nodeItem) { // Функция заполнения стека.
    if (stack->size >= stack->limit) { // Если итоговое значение стека превышает лимит размера, то стек переаллоцируется под больший лимит.
        stack->limit *= 2;
        stack->data = (Node**)realloc(stack->data, stack->limit * sizeof(Node*));
    }
    stack->data[stack->size++] = nodeItem; // Добавление элемента в конец стека.
}

Node* pop(Stack* s) { // Функция выдачи последнего узла стека с его удалением.
    if (s->size == 0) { // Если стек пустой, вызов ошибки.
        exit(7);
    }
    s->size--; // Уменьшение размера стека.
    return s->data[s->size]; // Возрват последнего узла стека.
}

// Прямой обход дерева и подсчет суммы всех узлов - обход дерева в порядке: 1. Посещение корня дерева. 2. Посещение левого подузла. 3. Посещение правого подузла. 
int calculateTreeSum(Node* nodeRoot) { // Входные данные - указатель на корень верхнего узла.
    Stack* ps = createStack(); // Создание стека для обхода дерева.
    int totalSum = 0;
    while (ps->size != 0 || nodeRoot != NULL) { // Условие цикла - Размер стека не равен 0 И Значение корня не равно NULL (Индикация завершения обхода узла - конца узла).
        if (nodeRoot != NULL) {  // Если корень не равен NULL (Индикация завершения обхода узла - конца узла).
            printf("Значение узла %d\n", nodeRoot->data); // Вывод значения корня - число.
            totalSum += nodeRoot->data;
            if (nodeRoot->right) { // Если есть правый узел - заносим его в стек.
                push(ps, nodeRoot->right); // Запись в стек правого подузла.
            }
            nodeRoot = nodeRoot->left; // Перевод указателя на левый подузел.
        }
        else { // Иначе обход узла завершается.
            nodeRoot = pop(ps); // В значение узла записывается указатель на последнюю вершину стека. 
        }
    }
    freeStack(&ps); // По завершении обхода дерева освобождение используемого стека.
    return totalSum;
}

Node* initNodeWithUserData() {
    int graphNodeData; // Значение корня графа.
    int graphNodeDirection; // Расположение узла графа относительно вершины.
    Node* startNode = createNode(); // Вершина графа.
    Node* temporaryHeadNode = startNode; // Изменяемая переменная для хранения родительского узла.
    Node* temporaryNode = createNode(); // Изменяемая переменная для хранения узла.

    printf("Количество вершин графа регулируется количеством ввода данных пользователем.\nВведите значение корня вершины графа:\t");
    scanf_s("%d", &graphNodeData);
    startNode->data = graphNodeData;

    printf("Введите расположение следующего узла графа относительно текущего. 0 - расположение справа, 1 - расположение слева.\nВведите расположение:\t");
    scanf_s("%d", &graphNodeDirection);
    if (graphNodeDirection != 0 & graphNodeDirection != 1) {
        return startNode;
    }
    printf("Введите значение следующего узла графа:\t");
    scanf_s("%d", &graphNodeData);
    temporaryNode->data = graphNodeData;
    if (graphNodeDirection == 0) {
        temporaryHeadNode->right = temporaryNode;
    }
    else {
        temporaryHeadNode->left = temporaryNode;
    }
    temporaryNode->head = temporaryHeadNode;
    temporaryHeadNode = temporaryNode;
    temporaryNode = createNode();

    while (true) {
        if (temporaryHeadNode->right == NULL & temporaryHeadNode->left == NULL) { // Если не задано значение правого и левого подузлов.
            printf("Выберите расположение следующего узла. Доступные расположения: 0 - расположение справа, 1 - расположение слева. Либо же введите 2 для подъема к верхнему узлу графа. Введите расположение: \t");
            scanf_s("%d", &graphNodeDirection);
            if (graphNodeDirection == 2 & temporaryHeadNode->head != NULL) { // Если выбран переход к верхнему узлу и узел доступен. 
                temporaryHeadNode = temporaryHeadNode->head;
                continue;
            }
            else if (graphNodeDirection != 0 & graphNodeDirection != 1) {
                break;
            }
            printf("Введите значение следующего узла графа:\t");
            scanf_s("%d", &graphNodeData);
            temporaryNode->data = graphNodeData;
            if (graphNodeDirection == 0) {
                temporaryHeadNode->right = temporaryNode;
            }
            else {
                temporaryHeadNode->left = temporaryNode;
            }
        }

        else { // Иначе проверяем доступность подузлов по отдельности.
            if (temporaryHeadNode->right == NULL) { // Если не задано значение правого подузла.
                printf("Выберите расположение следующего узла. Доступные расположения: 0 - расположение справа. Либо же введите 2 для подъема к верхнему узлу графа. Введите расположение: \t");
                scanf_s("%d", &graphNodeDirection);
                if (graphNodeDirection == 2 & temporaryHeadNode->head != NULL) { // Если выбран переход к верхнему узлу и узел доступен. 
                    temporaryHeadNode = temporaryHeadNode->head;
                    continue;
                }
                else if (graphNodeDirection != 0) {
                    break;
                }
                printf("Введите значение следующего узла графа:\t");
                scanf_s("%d", &graphNodeData);
                temporaryNode->data = graphNodeData;
                temporaryHeadNode->right = temporaryNode;
            }

            else {
                if (temporaryHeadNode->left == NULL) { // Если доступен левый узел.
                    printf("Выберите расположение следующего узла. Доступные расположения: 1 - расположение слева. Либо же введите 2 для подъема к верхнему узлу графа. Введите расположение: \t");
                    scanf_s("%d", &graphNodeDirection);
                    if (graphNodeDirection == 2 & temporaryHeadNode->head != NULL) { // Если выбран переход к верхнему узлу и узел доступен. 
                        temporaryHeadNode = temporaryHeadNode->head;
                        continue;
                    }
                    else if (graphNodeDirection != 1) {
                        break;
                    }
                    printf("Введите значение следующего узла графа:\t");
                    scanf_s("%d", &graphNodeData);
                    temporaryNode->data = graphNodeData;
                    temporaryHeadNode->left = temporaryNode;
                }

                else { // Иначе предлагаем перемещение между узлами.
                    printf("Выберите расположение доступных расположений для узлов нет. Введите: 0 для перехода к правому узлу графа. 1 для перехода к левому узлу графа. 2 для подъема к верхнему узлу графа.\nВведите расположение: \t");
                    scanf_s("%d", &graphNodeDirection);
                    if (graphNodeDirection == 0) {
                        temporaryHeadNode = temporaryHeadNode->right;
                    }
                    else if (graphNodeDirection == 1) {
                        temporaryHeadNode = temporaryHeadNode->left;
                    }
                    else if (graphNodeDirection == 2 & temporaryHeadNode->head != NULL) { // Если выбран переход к верхнему узлу и узел доступен. 
                        temporaryHeadNode = temporaryHeadNode->head;
                    }
                    else {
                        break;
                    }
                    continue;
                }
            }
        }
        temporaryNode->head = temporaryHeadNode;
        temporaryHeadNode = temporaryNode;
        temporaryNode = createNode();
    }

    return startNode;
}


Node* initNodeWithRandomData() {
    Node* startNode = createNode(); // Вершина графа.

    srand((unsigned int)time(NULL));

    Node* subNode0 = createNode();
    subNode0->data = rand() % 100;
    subNode0->head = startNode;
    startNode->right = subNode0;
    Node* subNode00 = createNode();
    subNode00->data = rand() % 100;
    subNode00->head = subNode0;
    subNode0->right = subNode00;
    Node* subNode000 = createNode();
    subNode000->data = rand() % 100;
    subNode000->head = subNode00;
    subNode00->right = subNode000;
    Node* subNode001 = createNode();
    subNode001->data = rand() % 100;
    subNode001->head = subNode00;
    subNode00->left = subNode001;
    Node* subNode01 = createNode();
    subNode01->data = rand() % 100;
    subNode01->head = subNode0;
    subNode0->left = subNode01;
    Node* subNode010 = createNode();
    subNode010->data = rand() % 100;
    subNode010->head = subNode01;
    subNode01->right = subNode010;
    Node* subNode0100 = createNode();
    subNode0100->data = rand() % 100;
    subNode0100->head = subNode010;
    subNode010->right = subNode0100;

    Node* subNode1 = createNode();
    subNode1->data = rand() % 100;
    subNode1->head = startNode;
    startNode->left = subNode1;
    Node* subNode10 = createNode();
    subNode10->data = rand() % 100;
    subNode10->head = subNode1;
    subNode1->right = subNode10;
    Node* subNode11 = createNode();
    subNode11->data = rand() % 100;
    subNode11->head = subNode1;
    subNode1->left = subNode11;
    Node* subNode110 = createNode();
    subNode110->data = rand() % 100;
    subNode110->head = subNode11;
    subNode11->right = subNode110;

    return startNode;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int inputDataMode; // Режим ввода входных данных. 1 - ручной ввод. Любое другое число - автоматический ввод.
    Node* inputNode;
    int treeSum;

    printf("Выберите режим ввода данных о дереве:\nВведите '1' для ручного ввода. Любое другое число выбирает автоматический ввод.\nРежим ввода данных:\t");
    scanf_s("%d", &inputDataMode);
    if (inputDataMode == 1) {
        inputNode = initNodeWithUserData();
    }
    else {
        inputNode = initNodeWithRandomData();
        // RESULT NODE STRUCTURE
        //                                      inputNode
        //                          subNode0                          subNode1
        //              subNode00               subNode01       subNode10   subNode11
        //      subNode000  subNode001          subNode010                  subNode110
        //                                      subNode0100
    }

    treeSum = calculateTreeSum(inputNode);
    printf("Конечная сумма всех узлов %d\n", treeSum); // Вывод значения корня - число.

}
