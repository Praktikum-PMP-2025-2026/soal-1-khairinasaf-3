/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Khairina Safira Nurazizah (13224021)
 *   Nama File           : soal1
 *   Deskripsi           : menjumlahkan waktu tunggu seluruh pasien dan mencetak ID pasien,
 *   dengan waktu tunggu pasien berikutnya = total durasi semua pasien sebelumnya
 * 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    char id[10];
    int durasi;
} Pasien;

typedef struct{
    int front;
    int rear;
    Pasien data[MAX];
} Queue;

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, char id[], int durasi){
    q->rear++;
    strcpy(q->data[q->rear].id, id);
    q->data[q->rear].durasi = durasi;
}

Pasien dequeue(Queue *q){
    Pasien p;
    p = q->data[q->front++];
    return p;
}

int main(){
    Queue q;
    initQueue(&q);

    int N;
    int durasi;
    char id[10];

    int totalDurasi = 0;
    int durasiSekarang = 0;

    scanf("%d ", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", id);
        scanf("%d", &durasi);
        enqueue(&q, id, durasi);
    }

    printf("ORDER");
    for(int i = 0; i < N; i++){
        Pasien p = dequeue(&q);
        printf(" %s", p.id);

        totalDurasi = totalDurasi + durasiSekarang;

        durasiSekarang = durasiSekarang + p.durasi;
    }

    printf("\n");

    int total = totalDurasi;

    printf("WAIT ");
    printf("%d", total);

    return 0;
}


/*

sources:
https://www.geeksforgeeks.org/c/queue-in-c/
https://www.geeksforgeeks.org/c/strcpy-in-c/
https://www.w3resource.com/c-programming-exercises/queue/c-queue-exercise-7.php
https://www.w3schools.com/c/c_typedef.php


*/
