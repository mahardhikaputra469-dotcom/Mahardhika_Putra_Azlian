# <h1 align="center">Laporan Praktikum Modul 6 DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Doubly Linked List merupakan struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan dua pointer, yaitu next dan prev. Pointer next menunjuk ke node berikutnya, sedangkan prev menunjuk ke node sebelumnya. Setiap node menyimpan informasi dan alamat node lainnya. Struktur data ini memungkinkan proses penambahan, pencarian, penelusuran, dan penghapusan data dari dua arah. Dalam praktikum ini, Doubly Linked List digunakan untuk mengelola data buku yang terdiri dari kode buku, judul, dan tahun terbit. Operasi yang diterapkan meliputi penambahan data, pencarian data, serta penghapusan node.

## Guided 

### 1. Doublylist..h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype {
    std::string nopol; 
    std::string warna; 
    int thnBuat;      
};
typedef struct elmlist *address;
struct elmlist {
    infotype info;  
    address next;   
    address prev;   
};
struct List {
    address First; 
    address Last;  
};


// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```

### 2. Doublylist.cpp

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```

## Unguided 

### 1. 

### Buku.h

```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif
```

### Buku.cpp
```
#include "Buku.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    }else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;

    while(P != NULL) {
        cout << "Kode buku : " << P->info.kodeBuku << endl;
        cout << "Judul buku : " << P->info.judul << endl;
        cout << "Tahun terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}
```

### main.cpp
```

#include "Buku.h"

int main() {
    List L;
    infotype x;
    address P;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan kode buku: ";
        cin >> x.kodeBuku;

        cout << "Masukkan judul buku: ";
        cin >> x.judul;

        cout << "Masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        P = L.First;
        bool ada = false;

        while (P != NULL) {
            if (P->info.kodeBuku == x.kodeBuku) {
                ada = true;
                break;
            }
            P = P->next;
        }

        if (ada) {
            cout << "Kode buku sudah terdaftar!" << endl;
        } else {
            insertLast(L, alokasi(x));
        }

        cout << endl;
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%206/Soal%201/Output%20Soal%201.png)


penjelasan unguided 1 ini, cara membuat dan menggunakan ADT Doubly Linked List dengan bahasa C++. Program ini dapat digunakan untuk memasukkan data buku, mengecek apakah ada kode buku yang sama, dan menampilkan seluruh data yang sudah dimasukkan. Melalui praktikum ini, saya jadi lebih memahami bagaimana data saling terhubung menggunakan next dan prev, serta bagaimana cara mengelola data dalam Doubly Linked List.

### 2. 

### Buku.h

```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);

#endif
```

### Buku.cpp
```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    }else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;

    while(P != NULL) {
        cout << "Kode buku : " << P->info.kodeBuku << endl;
        cout << "Judul buku : " << P->info.judul << endl;
        cout << "Tahun terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}


address findElm(List L, infotype x) {
    address P = L.First;

    while (P != NULL) {
        if (P->info.kodeBuku == x.kodeBuku) {
            return P;
        }
        P = P->next;
    }

    return NULL;
}
```

### main.cpp
```C++

#include "Buku.h"

int main() {
    List L;
    infotype x, cari;
    address P;
    bool ada;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan kode buku: ";
        cin >> x.kodeBuku;

        cout << "Masukkan judul buku: ";
        cin >> x.judul;

        cout << "Masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        P = L.First;
        ada = false;

        while (P != NULL) {
            if (P->info.kodeBuku == x.kodeBuku) {
                ada = true;
                break;
            }
            P = P->next;
        }

        if (ada) {
            cout << "Kode buku sudah terdaftar!" << endl;
        } else {
            insertLast(L, alokasi(x));
        }

        cout << endl;
    }

    cout << "Masukkan kode buku yang dicari: ";
    cin >> cari.kodeBuku;

    P = findElm(L, cari);

    if (P != NULL) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Buku tidak ditemukan!" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%206/Soal%202/Output%20Soal%202.png)


penjelasan unguided 2 ini membuat fungsi findElm() untuk mencari data buku berdasarkan kode buku yang dimasukkan. Program akan memeriksa setiap elemen dalam Doubly Linked List sampai menemukan kode yang sesuai. Jika ditemukan, informasi buku seperti kode, judul, dan tahun terbit akan ditampilkan. Dari soal ini, saya jadi lebih memahami cara melakukan pencarian data menggunakan Doubly Linked List.

### 3. 

### Buku.h

```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

### Buku.cpp
```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    }else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;

    while(P != NULL) {
        cout << "Kode buku : " << P->info.kodeBuku << endl;
        cout << "Judul buku : " << P->info.judul << endl;
        cout << "Tahun terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}


address findElm(List L, infotype x) {
    address P = L.First;

    while (P != NULL) {
        if (P->info.kodeBuku == x.kodeBuku) {
            return P;
        }
        P = P->next;
    }

    return NULL;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = P->next;

    if (L.First == NULL) {
        L.Last = NULL;
    } else {
        L.First->prev = NULL;
    }

    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    L.Last = P->prev;

    if (L.Last == NULL) {
        L.First = NULL;
    } else {
        L.Last->next = NULL;
    }

    P->prev = NULL;
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;

    if (P->next != NULL) {
        P->next->prev = Prec;
    }

    P->next = NULL;
    P->prev = NULL;
}

```

### main.cpp
```C++

#include "Buku.h"

int main() {
    List L;
    infotype x, cari;
    address P, Prec;
    bool ada;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan kode buku: ";
        cin >> x.kodeBuku;

        cout << "Masukkan judul buku: ";
        cin >> x.judul;

        cout << "Masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        P = L.First;
        ada = false;

        while (P != NULL) {
            if (P->info.kodeBuku == x.kodeBuku) {
                ada = true;
                break;
            }
            P = P->next;
        }

        if (ada) {
            cout << "Kode buku sudah terdaftar!" << endl;
        } else {
            insertLast(L, alokasi(x));
        }

        cout << endl;
    }

    cout << "Masukkan kode buku yang akan dihapus: ";
    cin >> cari.kodeBuku;

    P = findElm(L, cari);

    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = L.First;

            while (Prec->next != P) {
                Prec = Prec->next;
            }

            deleteAfter(Prec, P);
        }

        dealokasi(P);
        cout << "Data dengan kode buku " << cari.kodeBuku
             << " berhasil dihapus." << endl;
    } else {
        cout << "Kode buku tidak ditemukan!" << endl;
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%206/Soal%203/Output%20Soal%203.png)

penjelasan unguided 3 ini cara menghapus data buku dari Doubly Linked List berdasarkan kode buku yang dipilih. Program menggunakan fungsi deleteFirst(), deleteLast(), dan deleteAfter() sesuai dengan posisi data yang akan dihapus. Setelah data berhasil dihapus, program menampilkan kembali daftar buku yang masih tersimpan. Dari soal ini, saya jadi lebih memahami cara mengelola dan menghapus elemen dalam Doubly Linked List.

## Kesimpulan
Dari praktikum ini, saya belajar bagaimana cara membuat dan mengelola data menggunakan ADT Doubly Linked List dengan bahasa pemrograman C++. Mulai dari memasukkan data buku, mengecek kode buku yang sama, mencari data berdasarkan kode buku, hingga menghapus data yang sudah tidak diperlukan. Saya juga memahami fungsi dari pointer next dan prev yang menghubungkan setiap elemen dalam dua arah. Melalui ketiga soal ini, saya menjadi lebih memahami bagaimana Doubly Linked List bekerja dan bagaimana penerapannya dalam mengelola data secara terstruktur.

## Referensi
[1] 1. Modul Praktikum Struktur Data. Modul 6: Doubly Linked List. Materi pembuatan ADT, penambahan data (insert), pencarian data (searching), dan penghapusan data (delete).
[2] cppreference. std::list – C++ Reference. Membahas konsep list, penambahan, penghapusan, dan pengelolaan elemen. https://en.cppreference.com/w/cpp/container/list<br>
[3] Stanford University. Pointers and Linked Nodes. Materi mengenai pointer, node, dan konsep linked list dalam C++.<br>
[4] cplusplus.com. The C++ Language Tutorial. Materi dasar bahasa C++, termasuk pointer dan pengelolaan alamat memori. <br>
