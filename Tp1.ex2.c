#include <stdio.h>   // مكتبة الإدخال والإخراج القياسية

// دالة ترجع مجموع عددين
int add(int a, int b) {
    return a + b;   // نرجع نتيجة الجمع
}

// دالة ترجع العدد الأكبر بين عددين
int max(int a, int b) {
    if (a > b)
        return a;   // إذا كان a أكبر نرجعه
    else
        return b;   // وإلا نرجع b
}

// دالة ترجع المعدل الحسابي لعناصر مصفوفة
float average(int arr[], int n) {
    int sum = 0;    // متغير لتخزين المجموع
    for (int i = 0; i < n; i++) {
        sum = add(sum, arr[i]);   // نجمع كل عنصر باستخدام دالة add
    }
    return (float)sum / n;   // نحسب المعدل (تحويل إلى float لتفادي القسمة الصحيحة)
}

int main() {
    int n;   // عدد العناصر
    printf("ادخل عدد العناصر: ");
    scanf("%d", &n);   // إدخال عدد العناصر

    int arr[100];   // مصفوفة لتخزين الأعداد (حجم أقصى 100)

    // قراءة عناصر المصفوفة من المستخدم
    printf("ادخل %d عدد:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // إيجاد أكبر عدد باستعمال دالة max
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        largest = max(largest, arr[i]);   // مقارنة كل عنصر مع الحالي
    }

    // حساب المعدل باستعمال average
    float mean = average(arr, n);

    // عرض النتائج
    printf("أكبر عدد هو: %d\n", largest);
    printf("المعدل الحسابي هو: %.2f\n", mean);

    return 0;   // نهاية البرنامج
}
