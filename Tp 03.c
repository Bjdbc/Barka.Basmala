#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
}Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
}Node;

/* ============================
   Q1: إنشاء قائمة فارغة
   ============================ */
Node* createList() {
    return NULL;  // قائمة فارغة
}

/* فحص إن كانت القائمة فارغة */
int isEmpty(Node *head) {
    return (head == NULL);
}

/* ============================
   Q2: إدراج منتج في بداية القائمة
   ============================ */
Node* insertAtBeginning(Node *head, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (isEmpty(head)) {
        // القائمة فارغة → العقدة تشير إلى نفسها
        newNode->next = newNode;
        return newNode;
    }

    // إيجاد آخر عقدة
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;  // الجديد يشير للأول
    temp->next = newNode;  // الأخير يشير للجديد

    return newNode; // الجديد يصبح الرأس
}

/* ============================
   إدراج منتج في نهاية القائمة
   ============================ */
Node* insertAtEnd(Node *head, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (isEmpty(head)) {
        newNode->next = newNode; // يشير لنفسه
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;   // ربط الأخير بالجديد
    newNode->next = head;   // الجديد يشير للرأس

    return head; // الرأس لا يتغير
}

/* ============================
   Q3: عرض عناصر القائمة
   ============================ */
void displayList(Node *head) {
    if (isEmpty(head)) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;

    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);

        temp = temp->next;
    } while (temp != head); // نوقف عندما نرجع للرأس
}

/* ============================
         MAIN للتجريب
   ============================ */
int main() {
    Node *head = createList();

    Product p1 = {1, "Milk", 120};
    Product p2 = {2, "Bread", 15};
    Product p3 = {3, "Juice", 80};

    head = insertAtBeginning(head, p1);
    head = insertAtEnd(head, p2);
    head = insertAtBeginning(head, p3);

    printf("Circular Linked List:\n");
    displayList(head);

    return 0;
}
