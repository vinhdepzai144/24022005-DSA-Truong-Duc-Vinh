#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
typedef struct Node* node;

// Cấp phát động một node mới với dữ liệu là số nguyên x
inline node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Kiểm tra rỗng
inline bool empty(node a) {
    return a == NULL;
}

// Hàm đếm danh sách liên kết có bao nhiêu phần tử
inline int Size(node a) {
    int cnt = 0;
    while (a != NULL) {
        a = a->next;
        cnt++;
    }
    return cnt;
}

// Thêm một phần tử vào đầu danh sách liên kết
inline void insertFirst(node &a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    } else {
        tmp->next = a;
        a = tmp;
    }
}

// Thêm phần tử vào cuối dslk
inline void insertLast(node &a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

// Thêm 1 phần tử vào giữa với k là vị trí muốn thêm
inline void insertMiddle(node &a, int x, int k) {
    int n = Size(a);
    if (k <= 0 || k > n + 1) {
        cout << "vị trí ko hợp lệ";
        return;
    }
    if (n == 1) {
        insertFirst(a, x);
        return;
    } else if (n == k + 1) {
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < k - 1; i++) {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

// Xoá phần tử ở đầu
inline void deleteFirst(node &a) {
    if (a == NULL) return;
    node tmp = a;
    a = a->next;
    delete tmp;
}

// Xoá phần tử ở cuối
inline void deleteLast(node &a) {
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        delete a;
        a = NULL;
    } else {
        truoc->next = NULL;
        delete sau;
    }
}

// Xoá ở giữa
inline void deleteMiddle(node &a, int k) {
    if (k <= 0 || k > Size(a)) return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < k; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        node tmp = a;
        a = a->next;
        delete tmp;
    } else {
        truoc->next = sau->next;
        delete sau;
    }
}

// Hàm in danh sách
inline void in(node a) {
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

// Duyệt in ngược
inline void inNguoc(node a) {
    if (a == NULL) return;
    inNguoc(a->next);
    cout << a->data << " ";
}

// Sắp xếp
inline void sapxep(node &a) {
    for (node p = a; p != NULL && p->next != NULL; p = p->next) {
        node min = p;
        for (node q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        int tmp = min->data;
        min->data = p->data;
        p->data = tmp;
    }
}
