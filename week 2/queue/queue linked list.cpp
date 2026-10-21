#include <iostream>
#include "Linked_List.h"

using namespace std;

// =========================================================================
// CÀI ĐẶT QUEUE (HÀNG ĐỢI - FIFO) DÙNG LINKED LIST (DSLK ĐƠN)
// - Đầu hàng đợi (front): là head của danh sách liên kết
// - Cuối hàng đợi (rear): là đuôi của danh sách liên kết
// Sử dụng các hàm có sẵn trong Linked_List.h:
// - empty(head): kiểm tra queue rỗng
// - Size(head): lấy kích thước queue
// - insertLast(head, item): thêm vào cuối queue (enqueue)
// - deleteFirst(head): xóa ở đầu queue (dequeue - O(1))
// =========================================================================
struct Queue {
    node head = NULL;

    // bool isEmpty(): trả về true nếu queue rỗng, ngược lại false
    bool isEmpty() {
        return empty(head); // Sử dụng hàm có sẵn
    }

    // int size(): trả về số lượng phần tử trong queue
    int size() {
        return Size(head); // Sử dụng hàm có sẵn
    }

    // void enqueue(int item): thêm phần tử vào cuối queue
    void enqueue(int item) {
        insertLast(head, item); // Sử dụng hàm có sẵn
    }

    // int front(): xem giá trị phần tử ở đầu queue
    int front() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue đang rỗng!\n";
            return -1;
        }
        return head->data;
    }

    // int dequeue(): xóa phần tử ở đầu queue và trả về giá trị đó
    int dequeue() {
        if (isEmpty()) {
            cout << "[Lỗi] Queue đang rỗng, không thể dequeue!\n";
            return -1;
        }
        int val = front();
        deleteFirst(head); // Xóa ở đầu bằng hàm có sẵn (O(1))
        return val;
    }
};

int main() {
    Queue q;

    cout << "--- DEMO QUEUE DÙNG LINKED LIST ---\n";
    cout << "1. Kiểm tra ban đầu:\n";
    cout << "isEmpty(): " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << q.size() << endl;

    cout << "\n2. Enqueue các phần tử 100, 200, 300, 400 vào queue:\n";
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);

    cout << "size() sau khi enqueue: " << q.size() << endl;
    cout << "front() hiện tại: " << q.front() << endl; // 100
    cout << "isEmpty(): " << (q.isEmpty() ? "true" : "false") << endl;

    cout << "\n3. Dequeue phần tử ra khỏi queue:\n";
    cout << "Dequeue ra: " << q.dequeue() << endl; // 100
    cout << "front() sau khi dequeue: " << q.front() << endl; // 200
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
