# <h1 align="center">Laporan Praktikum Modul 5 SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.


## Guided 

### 1. listBuah..h

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;


struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; 

typedef struct node *address; 

struct node{ 
    dataBuah isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "listBuah.h"

  #include<iostream>
  using namespace std;

  int main(){
      linkedlist List;
      address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
      createList(List);

      dataBuah dtBuah;

      nodeA = alokasi("Jeruk", 100, 3000);
      nodeB = alokasi("Apel", 75, 4000);
      nodeC = alokasi("Pir", 87, 5000);
      nodeD = alokasi("Semangka", 43, 11500);
      nodeE = alokasi("Durian", 15, 31450);

      insertFirst(List, nodeA);
      insertLast(List, nodeB);
      insertAfter(List, nodeC, nodeA);
      insertAfter(List, nodeD, nodeC);
      insertLast(List, nodeE);

      cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      updateFirst(List);
      printList(List);
      updateLast(List);
      printList(List);
      updateAfter(List, nodeD);
      printList(List);

      cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      FindNodeByData(List, "kelapa");
      FindNodeByAddress(List, nodeC);
      FindNodeByRange(List, 5000, 10000);

      delFirst(List);
      printList(List);
      delLast(List);
      printList(List);
      delAfter(List, nodeD, nodeC);
      printList(List);

      cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      deleteList(List);
      cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      return 0;
  }
```
guided Program ini menggunakan struktur data Singly Linked List dalam bahasa C++ untuk mengelola data buah yang terdiri dari nama, jumlah, dan harga. Setiap data disimpan dalam sebuah node yang saling terhubung menggunakan pointer next, sedangkan pointer first digunakan untuk menunjukkan node pertama dalam list. Program ini memiliki beberapa operasi utama, yaitu menambahkan data (insert), menampilkan data (print), mengubah data (update), mencari data (searching), dan menghapus data (delete). Selain itu, program dapat menghitung jumlah node serta menghapus seluruh isi list. Melalui program ini, kita dapat memahami cara kerja Singly Linked List dalam mengelola data secara dinamis, termasuk penggunaan pointer dan manajemen memori untuk menambah maupun menghapus node.

## Unguided 

### 1. membuat program yang menerima input dua buah bilangan bertipe float.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian   = " << a * b << endl;
    cout << "Pembagian   = " << a / b << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal1.png)

penjelasan unguided 1 

### 2. sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukan Angka (0-100): ";
    cin >> angka;

    string satuan[] {
        "nol", "satu", "dua", "tiga", "empat", "lima",
        "enam", "tujuh", "delapan", "sembilan"
    };

    if (angka < 0 || angka > 100){
        cout << "angka harus 0-100";
    }
    else if (angka < 10){
        cout << satuan[angka];
    }
    else if (angka == 10){
        cout << "sepuluh";
    }
    else if (angka == 11){
        cout << "sebelas";
    }
    else if (angka < 20){
        cout << satuan[angka - 10] <<"belas";
    }
    else if (angka < 100){
        cout << satuan[angka / 10] << "puluh";

        if (angka % 10 != 0){
            cout << " " << satuan[angka % 10];
        }
    }
    else {
        cout << "seratus";
    }
    cout << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal2.png)

penjelasan unguided 2

### 3. meminta kita membuat program yang menerima input berupa sebuah angka, kemudian menghasilkan pola output berbentuk mirror.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;
    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {

        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal3.png)

penjelasan unguided 3

## Kesimpulan
Dari ketiga soal tersebut, dapat disimpulkan bahwa latihan ini mengajarkan dasar-dasar pemrograman C++. Soal pertama melatih penggunaan input, output, dan operasi aritmatika. Soal kedua melatih penggunaan percabangan untuk mengubah angka 0–100 menjadi bentuk tulisan. Soal ketiga melatih penggunaan perulangan untuk membuat pola angka berbentuk mirror. Dengan mengerjakan ketiga soal ini, kita dapat memahami cara menggunakan beberapa konsep dasar C++ untuk menyelesaikan permasalahan sederhana.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
