// --- Function definitions ---
char *LoadString(int N) {
    char *str = (char *) malloc((N + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter a string (max %d characters): ", N);
    fgets(str, N + 1, stdin);
    return str;
}

int StringLength(char *str) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n')
        len++;
    return len;
}

void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0' && p[i] != '\n') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}

void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);
    printf("\n");
}

void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++)
        rev[i] = arr[n - i - 1];
    rev[n] = '\0';
}

int SumStringASCII(char *p) {
    if (*p == '\0' || *p == '\n')
        return 0;
    else
        return (*p) + SumStringASCII(p + 1);
}

void ReverseString(char *start, char *end) {
    if (start >= end)
        return;
    char temp = *start;
    *start = *end;
    *end = temp;
    ReverseString(start + 1, end - 1
}
