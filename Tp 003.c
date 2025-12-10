#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* تعريف هيكل المنتج */
typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

/* تعريف العقدة Node التي تحتوي على منتج ومؤشر للعقدة التالية */
typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;


/* Q1: إنشاء قائمة دائرية فارغة */
Node* createEmptyList() {
    return NULL;  // القائمة فارغة تعني أن head = NULL
}

/* Q1: التحقق إذا كانت القائمة فارغة */
int isEmpty(Node* head) {
    return (head == NULL);
}


/* Q2: إدراج عنصر في بداية القائمة الدائرية */
Node* insertAtBeginning(Node* head, Product p) {
    // إنشاء عقدة جديدة
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    // إذا كانت القائمة فارغة
    if (head == NULL) {
        newNode->next = newNode;  // تشير لنفسها
        return newNode;           // وتصبح هي head
    }

    // إذا كانت القائمة غير فارغة
    Node* temp = head;

    // البحث عن آخر عقدة (التي next تاعها يشير لـ head)
    while (temp->next != head)
        temp = temp->next;

    // ربط العقدة الأخيرة بالعقدة الجديدة
    temp->next = newNode;

    // ربط العقدة الجديدة بـ head القديم
    newNode->next = head;

    // العقدة الجديدة تصبح هي head
    return newNode;
}


/* Q2: إدراج عنصر في نهاية القائمة الدائرية */
Node* insertAtEnd(Node* head, Product p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    // إذا كانت القائمة فارغة
    if (head == NULL) {
        newNode->next = newNode;  // تشير لنفسها
        return newNode;
    }

    Node* temp = head;

    // إيجاد آخر عقدة
    while (temp->next != head)
        temp = temp->next;

    // ربط آخر عقدة بالعقدة الجديدة
    temp->next = newNode;

    // ربط العقدة الجديدة بـ head
    newNode->next = head;

    // head لا يتغير
    return head;
}


/* Q3: عرض محتويات القائمة */
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;

    printf("\n--- Products in Circular List ---\n");

    // استعمال do-while لأنها مناسبة للقوائم الدائرية
    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);

        temp = temp->next;  // التقدم للعقدة التالية

    } while (temp != head); // التوقف عند العودة إلى head
}
