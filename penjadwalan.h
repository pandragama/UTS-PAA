#ifndef PENJADWALAN_H
#define PENJADWALAN_H

struct Jadwal {
  char* kegiatan;
  int jam;
};


// interface - brute force jadwal
void jadwalTerbaik(struct Jadwal *terbaik, struct Jadwal *tugas, int jumlahTugas);
void jadwalPeriksa(struct Jadwal *tugas, int jumlahTugas, struct Jadwal *terbaik);
void jadwalSwap(struct Jadwal *a, struct Jadwal *b);
void jadwalPermutasi(struct Jadwal *tugas, int start, int end, struct Jadwal *terbaik);
void jadwalBF(struct Jadwal *tugas, int jumlahTugas, struct Jadwal *terbaik);

// interface - greedy jadwal
void jadwalBubbleSort(struct Jadwal *tugas, int jumlahTugas);
void jadwalGreedy(struct Jadwal *tugas, int jumlahTugas);

void taskScheduling();

#endif