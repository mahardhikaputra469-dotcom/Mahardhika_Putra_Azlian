# <h1 align="center">Laporan Praktikum Modul - 4 SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Linked List adalah struktur data yang terdiri dari beberapa node yang saling terhubung melalui pointer. Setiap node menyimpan data dan alamat node berikutnya. Operasi Linked List meliputi penambahan, penghapusan, pencarian, dan penelusuran data. Linked List memiliki keunggulan dalam penyisipan dan penghapusan data, terutama ketika posisi data sudah diketahui. Namun, struktur ini membutuhkan memori tambahan untuk pointer dan memiliki akses data yang lebih lambat dibandingkan array [1]. Dengan demikian, Linked List cocok digunakan untuk mengelola data yang jumlahnya dapat berubah secara dinamis.

## Guided 

### 1. list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam satu program

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```


### 2. list.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// Fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// Pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// Pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isi data sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// Prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

// Prosedur-prosedur untuk delete / menghapus node
void delFirst(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next,
       menghapus Prev->next dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// Prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                << ", NIM : " << nodeBantu->isidata.nim
                << ", Usia : " << nodeBantu->isidata.umur
                << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// Function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```


### 3. main.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

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
guided Program ini menggunakan struktur data Singly Linked List untuk mengelola data mahasiswa yang terdiri dari nama, NIM, dan umur. Program memiliki fungsi untuk membuat list, menambahkan node di awal, tengah, dan akhir, menghapus node, menampilkan data, menghitung jumlah node, serta menghapus seluruh list. Dengan adanya pointer dan manajemen memori dinamis, data mahasiswa dapat dikelola secara fleksibel sesuai kebutuhan.
## Unguided 

### 1.1 Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address prev);
int nbList(List L);
void deleteList(List &L);

#endif
```

### 1.2 Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first->next == nullptr) {
        dealokasi(L.first);
        return;
    }

    address P = L.first;

    while (P->next->next != nullptr) {
        P = P->next;
    }

    address H = P->next;
    P->next = nullptr;
    dealokasi(H);
}

void deleteAfter(List &L, address prev) {
    if (prev != nullptr && prev->next != nullptr) {
        address P = prev->next;
        prev->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }

    cout << "- List Berhasil Terhapus -" << endl;
}
```

### 1.3 main.cpp
```C++

#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%204/soal%201/p1.png)

penjelasan unguided 1 

### 2.1 Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address prev);
int nbList(List L);
void deleteList(List &L);

#endif
```

### 2.2 Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first->next == nullptr) {
        dealokasi(L.first);
        return;
    }

    address P = L.first;

    while (P->next->next != nullptr) {
        P = P->next;
    }

    address H = P->next;
    P->next = nullptr;
    dealokasi(H);
}

void deleteAfter(List &L, address prev) {
    if (prev != nullptr && prev->next != nullptr) {
        address P = prev->next;
        prev->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }

    cout << "- List Berhasil Terhapus -" << endl;
}
```

### 2.3 main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, L.first);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%204/soal%202/p2.png)

penjelasan unguided 2


## Kesimpulan
Berdasarkan praktikum Struktur Data, Singly Linked List merupakan struktur data yang terdiri dari node yang saling terhubung menggunakan pointer. Pada program ini, Linked List digunakan untuk menyimpan data berupa bilangan integer dengan fungsi CreateList(), alokasi(), dealokasi(), insertFirst(), dan printInfo(). Melalui praktikum ini, dapat dipahami cara membuat list kosong, mengalokasikan memori untuk node baru, menambahkan node di awal list, serta menampilkan data sesuai urutan yang terbentuk. Dengan demikian, praktikum ini membantu memahami konsep dasar Singly Linked List dan penerapannya dalam bahasa C++.

## Referensi
[1] Morin, P. (2013). Open Data Structures: An Introduction. Athabasca University Press. Bab 3: Linked Lists. 
<br>[2] Harvard University. (2026). CS 61: C++ Notes — Patterns. Harvard Computer Science.
<br>[3] Vijayalakshmi Pai, G. A. (2023). Linked Lists. Dalam A Textbook of Data Structures and Algorithms 1. Wiley. https://doi.org/10.1002/9781394192076.ch6<br>
