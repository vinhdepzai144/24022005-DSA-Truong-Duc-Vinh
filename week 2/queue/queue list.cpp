#include <iostream>
#include "list.h"

using namespace std;

// ==========================================
// CÀI ĐẶT QUEUE (HÀNG ĐỢI - FIFO) DÙNG LIST
// - Đầu hàng đợi (front): phần tử ở vị trí 0
// - Cuối hàng đợi (rear): phần tử ở vị trí L.size - 1
// Sử dụng các hàm có sẵn trong list.h:
// - chenCuoi(L, item): thêm vào cuối hàng đợi (enqueue)
// - xoaDau(L): xóa ở đầu hàng đợi (dequeue)
// - truyCap(L, 0): lấy phần tử ở đầu hàng đợi (front)
// ==========================================
struct Queue {
    List L;

    // bool isEmpty(): trả về true nếu queue rỗng, ngược lại false
    bool isEmpty() {
        return L.size == 0;
    }

    // int size(): trả về số lượng phần tử trong queue
    int size() {
        return L.size;
    }

    // void enqueue(int item): thêm phần tử vào cuối queue
    void enqueue(int item) {
        chenCuoi(L, item); // Sử dụng hàm có sẵn
    }

    // int front(): xem giá trị phần tử ở đầu queue
    int front() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue đang rỗng!\n";
            return -1;
        }
        return truyCap(L, 0); // Sử dụng hàm có sẵn (lấy phần tử đầu tiên)
    }

    // int dequeue(): xóa phần tử ở đầu queue và trả về giá trị đó
    int dequeue() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue đang rỗng, không thể dequeue!\n";
            return -1;
        }
        int val = front();
        xoaDau(L); // Sử dụng hàm có sẵn
        return val;
    }
};

int main() {
    Queue q;

    cout << "--- DEMO QUEUE DÙNG LIST (MẢNG) ---\n";
    cout << "1. Kiểm tra ban đầu:\n";
    cout << "isEmpty(): " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << q.size() << endl;

    cout << "\n2. Enqueue các phần tử 10, 20, 30, 40 vào queue:\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "size() sau khi enqueue: " << q.size() << endl;
    cout << "front() hiện tại: " << q.front() << endl; // 10 (phần tử vào đầu tiên)
    cout << "isEmpty(): " << (q.isEmpty() ? "true" : "false") << endl;

    cout << "\n3. Dequeue phần tử ra khỏi queue:\n";
    cout << "Dequeue ra: " << q.dequeue() << endl; // 10
    cout << "front() sau khi dequeue: " << q.front() << endl; // 20
    cout << "size() hiện tại: " << q.size() << endl; // 3

    cout << "\n4. Dequeue tất cả các phần tử còn lại (theo thứ tự FIFO):\n";
    while (!q.isEmpty()) {
        cout << "Dequeue: " << q.dequeue() << endl;
    }

    cout << "\n5. Kiểm tra sau khi queue rỗng:\n";
    cout << "isEmpty(): " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << q.size() << endl;

    return 0;
}
