#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struktur data Task
struct Task {
    char name[20];  // Nama tugas (maksimum 20 karakter)
    int duration;   // Durasi pengerjaan tugas
};

// Fungsi pembanding untuk qsort
int compareTasks(const void *a, const void *b) {
    return ((struct Task *)a)->duration - ((struct Task *)b)->duration;
}

// Fungsi untuk mengurutkan tugas dan menghitung total waktu tunggu
void scheduleTasks(struct Task tasks[], int n) {
    // Urutkan tugas berdasarkan durasi
    qsort(tasks, n, sizeof(struct Task), compareTasks);

    int totalWaitTime = 0;
    printf("Urutan pengerjaan tugas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, ", tasks[i].name);
        totalWaitTime += tasks[i].duration;
    }
    // Kurangi durasi tugas terakhir karena tidak perlu menunggu
    printf("\nWaktu tunggu: %d jam\n", totalWaitTime - tasks[n - 1].duration);
}

int main() {
    int n;
    printf("Masukkan jumlah tugas: ");
    scanf("%d", &n);

    struct Task tasks[n];  // Array untuk menyimpan tugas-tugas
    printf("Masukkan nama dan durasi tiap tugas:\n");
    for (int i = 0; i < n; i++) {
        printf("Tugas %d: ", i + 1);
        scanf("%s %d", tasks[i].name, &tasks[i].duration);
    }

    // Panggil fungsi untuk mengurutkan tugas dan menghitung total waktu tunggu
    scheduleTasks(tasks, n);

    return 0;
}
