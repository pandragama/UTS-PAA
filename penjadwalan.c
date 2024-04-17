#include <stdio.h>
#include <stdbool.h>

#include "penjadwalan.h"

// BRUTE FORCE - START ------------------------------------------

// Prosedur untuk menyimpan jadwal dengan urutan terbaik / tersingkat (ASC)
void jadwalTerbaik(struct Jadwal *terbaik, struct Jadwal *tugas, int jumlahTugas)
{
    for(int i = 0; i < jumlahTugas; i++) {
      terbaik[i] = tugas[i];
    }
}

// Prosedur untuk memeriksa apakah jam jadwal terurut secara asc
void jadwalPeriksa(struct Jadwal *tugas, int jumlahTugas, struct Jadwal *terbaik)
{
    int durasi = 0;
    bool ascending = false;
    for(int i = 0; i < jumlahTugas-1; i++)
    {
      if (tugas[i].jam <= tugas[i+1].jam) {
        ascending = true;
      } else {
        ascending = false;
        break;
      }
    }
    if (ascending == true) {
      jadwalTerbaik(terbaik, tugas, jumlahTugas);
    }
}

// Prosedur untuk menukar posisi elemen dalam array Jadwal
void jadwalSwap(struct Jadwal *a, struct Jadwal *b)
{
    struct Jadwal temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur permutasi untuk mendapatkan semua kemungkinan urutan elemen array
void jadwalPermutasi(struct Jadwal *tugas, int start, int end, struct Jadwal *terbaik) 
{
    // bool ascending = false;
    if(start==end) {
        jadwalPeriksa(tugas, end+1, terbaik);
    }

    for(int i = start; i <= end; i++) {
        // Menukar posisi elemen
        jadwalSwap((tugas+i), (tugas+start));
        // Menyesuaikan elemen awal
        // dan memanggil fungsi permutasi
        // untuk elemen yang tersisa
        jadwalPermutasi(tugas, start+1, end, terbaik);
        jadwalSwap((tugas+i), (tugas+start));
    }
}

// Prosedur untuk menghitung dan menampilkan solusi (BF)
void jadwalBF(struct Jadwal *tugas, int jumlahTugas, struct Jadwal *terbaik) 
{
    int durasi = 0;
    jadwalPermutasi(tugas, 0, jumlahTugas-1, terbaik);
    
    printf("\nSolusi (urutan tugas) terbaik:\n [");
    for(int i = 0; i < jumlahTugas-1; i++)
    {
      printf("%s-%d, ", &terbaik[i].kegiatan, terbaik[i].jam);
      durasi += terbaik[i].jam;
    }
    printf("%s-%d]\n", &terbaik[jumlahTugas-1].kegiatan, terbaik[jumlahTugas-1].jam);

    printf("Durasi tunggu: %d jam", durasi);
}

// BRUTE FORCE - END --------------------------------------------

// GREEDY - START -----------------------------------------------

// Prosedur bubble sort untuk mengurutkan jadwal secara ASC
void jadwalBubbleSort(struct Jadwal *tugas, int jumlahTugas)
{
    int i, j;
    bool swapped;
    for (i = 0; i < jumlahTugas - 1; i++) {
        swapped = false;
        for (j = 0; j < jumlahTugas - i - 1; j++) {
            if (tugas[j].jam > tugas[j + 1].jam) {
                jadwalSwap(&tugas[j], &tugas[j + 1]);
                swapped = true;
            }
        }

        // Jika tidak ada elemen yang di tukar
        if (swapped == false)
            break;
    }
}

// Prosedur untuk menghitung dan menampilkan solusi (Greedy)
void jadwalGreedy(struct Jadwal *tugas, int jumlahTugas) 
{
    int durasi = 0;
    jadwalBubbleSort(tugas, jumlahTugas);
    
    printf("\nSolusi (urutan tugas) terbaik:\n [");
    for(int i = 0; i < jumlahTugas-1; i++)
    {
      printf("%s-%d, ", &tugas[i].kegiatan, tugas[i].jam);
      durasi += tugas[i].jam;
    }
    printf("%s-%d]\n", &tugas[jumlahTugas-1].kegiatan, tugas[jumlahTugas-1].jam);
    printf("Durasi tunggu: %d jam", durasi);
}

// GREEDY - END -------------------------------------------------

void taskScheduling() {
  int jumlahTugas, algoritmaTerpilih;

	printf("Masukkan jumlah tugas: ");
	scanf("%d", &jumlahTugas);
  
  struct Jadwal tugas[jumlahTugas];
  struct Jadwal terbaik[jumlahTugas];

  printf("Masukkan tugas: ");
	for (int i = 0; i < jumlahTugas; i++)
	{
		scanf("%s %d", &tugas[i].kegiatan, &tugas[i].jam);
	}
  
  while (true) {
    printf("Dapatkan solusi terbaik dengan algoritma berikut:\n");
    printf("1. Brute Force \n");
    printf("2. Greedy \n");
    printf("Pilih Algoritma: ");
    scanf("%d", &algoritmaTerpilih);

    if (algoritmaTerpilih == 1) {
      jadwalBF(tugas, jumlahTugas, terbaik);
      break;
    }
    else if (algoritmaTerpilih == 2) {
      jadwalGreedy(tugas, jumlahTugas);
      break;
    }
    else{
      printf("Harap pilih algoritma yang tersedia\n");
    }
  }

}