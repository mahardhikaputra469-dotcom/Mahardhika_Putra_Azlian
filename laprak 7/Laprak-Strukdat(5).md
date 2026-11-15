# <h1 align="center">Laporan Praktikum Modul 7 Stack</h1>
<p align="center">Mahardhika Putra Azlian - 109082500025</p>

## Dasar Teori
Stack merupakan struktur data yang menggunakan prinsip LIFO (Last In First Out), yaitu data yang terakhir masuk akan menjadi data pertama yang keluar. Dalam bahasa C++, Stack dapat dibuat menggunakan Array dengan bantuan variabel top. Beberapa operasi yang digunakan yaitu Push() untuk menambahkan data, pop() untuk mengambil data, dan printInfo() untuk menampilkan isi Stack. Selain itu, terdapat fungsi pushAscending() untuk memasukkan data secara berurutan, getInputStream() untuk menerima input dari pengguna, serta balikStack() untuk membalik urutan data.

## Guided 

### 1. Stack.h

```C++
/* file : stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};
struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/******** pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */

/******** pembuatan Stack ********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */

/******** penambahan elemen pada Stack ********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */

/******** penghapusan elemen pada Stack ********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */

/******** proses semua elemen Stack *********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/
#endif // STACK_H_INCLUDED
```

### 2. Stack.cpp

```C++
#include "stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```

## Unguided 

### 1. 

### Stack.h

```C++

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### Stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        return -1;
    }

    infotype x = S.info[S.top];
    S.top--;

    return x;
}

void printInfo(Stack S) {
    cout << "[TOP]";

    for (int i = S.top; i >= 0; i--) {
        cout << " " << S.info[i];
    }

    cout << endl;
}

void balikStack(Stack &S) {
    int awal = 0;
    int akhir = S.top;

    while (awal < akhir) {
        infotype temp = S.info[awal];
        S.info[awal] = S.info[akhir];
        S.info[akhir] = temp;

        awal++;
        akhir--;
    }
}
```

### main.cpp
```C++

#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;

    createStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 8);

    pop(S);

    Push(S, 2);
    Push(S, 3);

    pop(S);

    Push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra_Azlian/blob/main/laprak%207/soal%20modul%206/output%201.png)


penjelasan unguided 1 ini, Menggunakan konsep LIFO (Last In First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Fungsi balikStack() digunakan untuk membalik urutan elemen Stack sehingga menghasilkan output sesuai gambar soal.

### 2. 

### Stack.h

```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```

### Stack.cpp
```C++

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        return -1;
    }

    infotype x = S.info[S.top];
    S.top--;

    return x;
}

void printInfo(Stack S) {
    cout << "[TOP]";

    for (int i = S.top; i >= 0; i--) {
        cout << " " << S.info[i];
    }

    cout << endl;
}

void balikStack(Stack &S) {
    int awal = 0;
    int akhir = S.top;

    while (awal < akhir) {
        infotype temp = S.info[awal];
        S.info[awal] = S.info[akhir];
        S.info[akhir] = temp;

        awal++;
        akhir--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top < 19) {
        int i = S.top;

        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }

        S.info[i + 1] = x;
        S.top++;
    }
}

void getInputStream(Stack &S) {
    char x;

    while (cin.get(x) && x != '\n') {
        if (x >= '0' && x <= '9') {
            Push(S, x - '0');
        }

        if (S.top == 19) {
            break;
        }
    }
}
```

### main.cpp
```C++

#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;

    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal2.png)


penjelasan unguided 2 menggunakan Array dapat digunakan untuk menyimpan dan mengelola data dengan konsep LIFO (Last In First Out). Pada praktikum ini, fungsi Push() digunakan untuk memasukkan data, pop() untuk mengeluarkan data, dan printInfo() untuk menampilkan isi Stack. Selain itu, prosedur pushAscending() digunakan untuk memasukkan data secara terurut berdasarkan nilai terkecil hingga terbesar, sedangkan balikStack() berfungsi membalik urutan elemen Stack. Dengan praktikum ini, dapat dipahami cara kerja Stack serta penerapan pengurutan data menggunakan Array dalam bahasa C++.

### 3. 

### Stack.h

```C++

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```

### Stack.cpp
```C++

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        return -1;
    }

    infotype x = S.info[S.top];
    S.top--;

    return x;
}

void printInfo(Stack S) {
    cout << "[TOP]";

    for (int i = S.top; i >= 0; i--) {
        cout << " " << S.info[i];
    }

    cout << endl;
}

void balikStack(Stack &S) {
    int awal = 0;
    int akhir = S.top;

    while (awal < akhir) {
        infotype temp = S.info[awal];
        S.info[awal] = S.info[akhir];
        S.info[akhir] = temp;

        awal++;
        akhir--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top < 19) {
        int i = S.top;

        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }

        S.info[i + 1] = x;
        S.top++;
    }
}


void getInputStream(Stack &S) {
    char x;

    while (cin.get(x) && x != '\n') {
        if (x >= '0' && x <= '9') {
            if (S.top < 19) {
                Push(S, x - '0');
            }
        }
    }
}
```

### main.cpp
```C++

#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Stack S;

    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mahardhikaputra469-dotcom/Mahardhika_Putra-Azlian/blob/main/laprak%201/soal3.png)

penjelasan unguided 3 Dari praktikum ini, menggunakan Array, terutama dalam menerima dan menyimpan data yang dimasukkan oleh pengguna. Pada percobaan ini, fungsi getInputStream() digunakan untuk membaca angka yang dimasukkan sampai tombol Enter ditekan. Setelah itu, data ditampilkan menggunakan printInfo() dan urutannya dibalik dengan balikStack(). Melalui praktikum ini, saya bisa memahami bagaimana konsep LIFO (Last In First Out) diterapkan dalam pengelolaan data menggunakan bahasa C++.

## Kesimpulan
ari seluruh praktikum yang telah dilakukan, saya jadi lebih memahami cara kerja ADT Stack menggunakan Array dalam bahasa C++. Pada percobaan pertama, saya mempelajari cara membuat Stack serta menggunakan fungsi Push() untuk menambahkan data dan pop() untuk mengambil data. Kemudian, pada percobaan kedua, saya mempelajari penggunaan pushAscending() untuk memasukkan data secara berurutan. Pada percobaan ketiga, saya mencoba menggunakan getInputStream() untuk menerima angka yang dimasukkan langsung melalui keyboard sampai tombol Enter ditekan.

Selain itu, saya juga memahami penggunaan printInfo() untuk menampilkan isi Stack dan balikStack() untuk membalik urutan data. Dari ketiga percobaan tersebut, saya menjadi lebih paham bahwa Stack menggunakan konsep LIFO (Last In First Out), yaitu data yang terakhir masuk akan menjadi data pertama yang keluar. Praktikum ini juga membantu saya memahami bagaimana setiap fungsi dalam Stack saling berhubungan dan digunakan dalam pengolahan data.

## Referensi
[1] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.<br>
[2]Lippman, S. B., Lajoie, J., & Moo, B. (2012). C++ Primer (5th ed.). Addison-Wesley Professional.<br>
[3] cppreference.com. C++ Language: Arrays. https://en.cppreference.com/w/cpp/language/array<br>
[4] cppreference.com. std::basic_istream::get. https://en.cppreference.com/w/cpp/io/basic_istream/get<br>