#include <iostream>
#include "list.h"
#include "Linked_List.h"

using namespace std;


struct QueueList {
    List L;

    bool isEmpty() {
        return L.size == 0;
    }

    void enqueue(int item) {
        chenCuoi(L, item); // Thêm vào cuối mảng
    }

    int front() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue rỗng!\n";
            return -1;
        }
        return truyCap(L, 0); // Lấy phần tử đầu tiên
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue rỗng, không thể dequeue!\n";
            return -1;
        }
        int val = front();
        xoaDau(L); // Xóa phần tử đầu tiên
        return val;
    }

    int size() {
        return L.size;
    }
};

// ==========================================
// 2. CÀI ĐẶT QUEUE DÙNG LINKED LIST (DSLK ĐƠN)
// ==========================================
struct QueueLinkedList {
    node head = NULL;

    bool isEmpty() {
        return empty(head);
    }

    void enqueue(int item) {
        insertLast(head, item); // Thêm vào cuối DSLK
    }

    int front() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue rỗng!\n";
            return -1;
        }
        return head->data; // Lấy giá trị node đầu
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue rỗng, không thể dequeue!\n";
            return -1;
        }
        int val = front();
        deleteFirst(head); // Xóa node đầu (O(1))
        return val;
    }

    int size() {
        return Size(head);
    }
};

int main() {
    cout << "========================================\n";
    cout << "     DEMO CÀI ĐẶT QUEUE TRÊN UET        \n";
    cout << "========================================\n\n";

    // Demo Queue dùng List
    cout << "--- 1. TEST QUEUE DÙNG LIST ---\n";
    QueueList qList;
    qList.enqueue(10);
    qList.enqueue(20);
    qList.enqueue(30);
    cout << "Size: " << qList.size() << endl;
    cout << "Front: " << qList.front() << endl; // 10
    cout << "Dequeue: " << qList.dequeue() << endl; // 10
    cout << "Front sau khi dequeue: " << qList.front() << endl; // 20
    cout << "isEmpty: " << (qList.isEmpty() ? "true" : "false") << endl;

    cout << "\n----------------------------------------\n\n";

    // Demo Queue dùng Linked List
    cout << "--- 2. TEST QUEUE DÙNG LINKED LIST ---\n";
    QueueLinkedList qLL;
    qLL.enqueue(100);
    qLL.enqueue(200);
    qLL.enqueue(300);
    cout << "Size: " << qLL.size() << endl;
    cout << "Front: " << qLL.front() << endl; // 100
    cout << "Dequeue: " << qLL.dequeue() << endl; // 100
    cout << "Front sau khi dequeue: " << qLL.front() << endl; // 200
    cout << "isEmpty: " << (qLL.isEmpty() ? "true" : "false") << endl;

    return 0;
}
