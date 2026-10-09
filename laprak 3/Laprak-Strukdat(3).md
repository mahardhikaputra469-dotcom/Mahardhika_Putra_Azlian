# <h1 align="center">Laporan Praktikum Modul 3 - ADT</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Dari praktikum ini dapat dipahami beberapa konsep dasar struktur data dalam C++, yaitu struct, array, ADT, fungsi, dan pointer. Struct digunakan untuk menggabungkan beberapa data, array digunakan untuk menyimpan banyak data, ADT digunakan untuk membuat struktur program yang lebih terorganisir, fungsi digunakan untuk membagi tugas dalam program, sedangkan pointer digunakan untuk mengakses dan mengubah data melalui alamat memorinya.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. mahasiswa.h

```C++ 
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif

```
### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1+m.nilai2)/2;
}
```
### 3. main.cpp

```C++ 
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}
```
guided 3 menjelaskan Program menerima sebuah angka, kemudian menggunakan perulangan untuk membuat pola angka yang berbentuk mirror, dengan tanda * sebagai bagian tengahnya.

## Unguided 

### 1. membuat program yang menerima input dua buah bilangan bertipe float.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Jumlah mahasiswa (maks. 10): ";
    cin >> jumlah;
    cin.ignore();

    if (jumlah > 10)
        jumlah = 10;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        getline(cin, mhs[i].nama);

        cout << "NIM   : ";
        getline(cin, mhs[i].nim);

        cout << "UTS   : ";
        cin >> mhs[i].uts;

        cout << "UAS   : ";
        cin >> mhs[i].uas;

        cout << "Tugas : ";
        cin >> mhs[i].tugas;
        cin.ignore();

        mhs[i].nilaiAkhir =
            hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n===== DATA MAHASISWA =====" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal1.png)

penjelasan unguided 1 Menggunakan struct dan array untuk menyimpan data maksimal 10 mahasiswa, serta fungsi untuk menghitung nilai akhir berdasarkan nilai UTS, UAS, dan tugas.

### 2. sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan.

pelajaran.h
```C++ 
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal2.png)


penjelasan unguided 2 ini meminta kita membuat ADT (Abstract Data Type) bernama pelajaran yang memiliki dua data, yaitu namaMapel dan kodeMapel. Selain itu, kita diminta membuat fungsi untuk membentuk data pelajaran dan prosedur untuk menampilkannya. Inti dari program ini adalah memahami cara membuat ADT dan memisahkan program menjadi beberapa file agar lebih terstruktur.

### 3. meminta kita membuat program yang menerima input berupa sebuah angka, kemudian menghasilkan pola output berbentuk mirror.

```C++

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal3.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
Dari ketiga soal tersebut, dapat disimpulkan bahwa latihan ini mengajarkan dasar-dasar pemrograman C++. Soal pertama melatih penggunaan input, output, dan operasi aritmatika. Soal kedua melatih penggunaan percabangan untuk mengubah angka 0–100 menjadi bentuk tulisan. Soal ketiga melatih penggunaan perulangan untuk membuat pola angka berbentuk mirror. Dengan mengerjakan ketiga soal ini, kita dapat memahami cara menggunakan beberapa konsep dasar C++ untuk menyelesaikan permasalahan sederhana.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
