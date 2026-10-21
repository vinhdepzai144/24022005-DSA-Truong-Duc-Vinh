#pragma once
#include <iostream>
using namespace std;

struct List {
    int data[100];
    int size = 0;
};

// 1. TRUY CAP VA DUYET
inline int truyCap(List L, int pos) {
    if (pos < 0 || pos >= L.size) return -1;
    return L.data[pos];
}

inline void duyetXuoi(List L) {
    for (int i = 0; i < L.size; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

inline void duyetNguoc(List L) {
    for (int i = L.size - 1; i >= 0; i--) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 2. CHEN PHAN TU
inline void chenDau(List &L, int x) {
    for (int i = L.size; i > 0; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[0] = x;
    L.size++;
}

inline void chenCuoi(List &L, int x) {
    L.data[L.size] = x;
    L.size++;
}

inline void chenGiua(List &L, int pos, int x) {
    for (int i = L.size; i > pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos] = x;
    L.size++;
}

// 3. XOA PHAN TU
inline void xoaDau(List &L) {
    if (L.size == 0) return;
    for (int i = 0; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

inline void xoaCuoi(List &L) {
    if (L.size == 0) return;
    L.size--;
}

inline void xoaGiua(List &L, int pos) {
    if (pos < 0 || pos >= L.size) return;
    for (int i = pos; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}
