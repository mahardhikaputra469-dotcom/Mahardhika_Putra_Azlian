
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