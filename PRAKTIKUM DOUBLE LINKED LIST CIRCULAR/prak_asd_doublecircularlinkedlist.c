#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Tidak bisa membuat Node!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

void printList()
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *temp = head;
    do
    {
        printf("Address: %p, Data: %d\n", (void *)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
}

void swap(Node *node1, Node *node2)
{
    if (node1->next == node2)
    {
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev->next = node2;
        node2->next->prev = node1;
        node2->next = node1;
        node1->prev = node2;
    }
    else if (node2->next == node1)
    {
        node2->next = node1->next;
        node1->prev = node2->prev;
        node2->prev->next = node1;
        node1->next->prev = node2;
        node1->next = node2;
        node2->prev = node1;
    }
    else
    {
        Node *tempNext = node1->next;
        Node *tempPrev = node1->prev;
        node1->next = node2->next;
        node1->prev = node2->prev;
        node2->next = tempNext;
        node2->prev = tempPrev;
        node1->next->prev = node1;
        node1->prev->next = node1;
        node2->next->prev = node2;
        node2->prev->next = node2;
    }

    if (head == node1)
        head = node2;
    else if (head == node2)
        head = node1;

    if (tail == node1)
        tail = node2;
    else if (tail == node2)
        tail = node1;
}

void sortList()
{
    if (head == NULL || head->next == head)
        return;

    int swapped;
    Node *ptr;

    do
    {
        swapped = 0;
        ptr = head;

        do
        {
            Node *nextNode = ptr->next;
            if (ptr->data > nextNode->data)
            {
                swap(ptr, nextNode);
                swapped = 1;
            }
            ptr = nextNode;
        } while (ptr->next != head);
    } while (swapped);
}

int main()
{
    int b;
    printf("Masukkan jumlah data: ");
    scanf("%d", &b);

    for (int i = 0; i < b; i++)
    {
        int data;
        printf("Masukkan data %d: ", i + 1);
        scanf("%d", &data);
        addNode(data);
    }

    printf("List sebelum pengurutan:\n");
    printList();

    sortList();

    printf("List setelah pengurutan:\n");
    printList();

    return 0;
}
