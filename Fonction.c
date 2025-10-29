#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *LoadString(int N);
int StringLength(char *str);
void LoadArray(char *p, char arr[]);
void ReverseArray(char arr[], char rev[], int n);
void DisplayArray(char arr[], int n);
int SumStringASCII(char *p);
void ReverseString(char *start, char *end);

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar(); // لتنظيف الـ buffer

    str = LoadString(n);
    int len = StringLength(str);
    char arr[len + 1], rev[len + 1];

    LoadArray(str, arr);

    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("Reversed array: ");
    DisplayArray(rev, len);

    printf("\nSum of ASCII values (recursive): %d\n", SumStringASCII(str));

    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);

    free(str);
    return 0;
}
