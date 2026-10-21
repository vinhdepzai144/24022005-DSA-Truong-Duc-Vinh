#include <iostream>
using namespace std;

struct List {
    int data[100];
    int size = 0;
};

// 1. TRUY CAP VA DUYET
int truyCap(List L, int pos) {
    if (pos < 0 || pos >= L.size) return -1;
    return L.data[pos];
}

void duyetXuoi(List L) {
    for (int i = 0; i < L.size; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void duyetNguoc(List L) {
    for (int i = L.size - 1; i >= 0; i--) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 2. CHEN PHAN TU
void chenDau(List &L, int x) {
    for (int i = L.size; i > 0; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[0] = x;
    L.size++;
}

void chenCuoi(List &L, int x) {
    L.data[L.size] = x;
    L.size++;
}

void chenGiua(List &L, int pos, int x) {
    for (int i = L.size; i > pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos] = x;
    L.size++;
}

// 3. XOA PHAN TU
void xoaDau(List &L) {
    if (L.size == 0) return;
    for (int i = 0; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

void xoaCuoi(List &L) {
    if (L.size == 0) return;
    L.size--;
}

void xoaGiua(List &L, int pos) {
    if (pos < 0 || pos >= L.size) return;
    for (int i = pos; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

int main() {
    List L;

    chenDau(L, 10);
    chenCuoi(L, 40);
    chenGiua(L, 1, 20);
    chenCuoi(L, 50);

    cout << "Duyet xuoi: ";
    duyetXuoi(L);

    cout << "Duyet nguoc: ";
    duyetNguoc(L);

    cout << "Phan tu vi tri 2: " << truyCap(L, 2) << endl;

    xoaDau(L);
    xoaGiua(L, 1);
    xoaCuoi(L);

    cout << "Sau khi xoa: ";
    duyetXuoi(L);

    return 0;
}
