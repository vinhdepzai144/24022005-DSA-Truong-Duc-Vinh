#include <iostream>
#include "list.h"

using namespace std;

// ==========================================
// CÀI ĐẶT STACK BẰNG LIST (MẢNG)
// Sử dụng các hàm có sẵn trong list.h:
// - chenCuoi(L, item): thêm phần tử vào đỉnh stack
// - xoaCuoi(L): xóa phần tử ở đỉnh stack
// - truyCap(L, pos): lấy phần tử ở đỉnh stack
// ==========================================
struct Stack {
    List L;

    // bool isEmpty(): trả về true nếu stack rỗng và false nếu ngược lại
    bool isEmpty() {
        return L.size == 0;
    }

    // void push(int item): chèn một phần tử vào stack
    void push(int item) {
        chenCuoi(L, item);
    }

    // int top(): trả về giá trị phần tử cuối (đỉnh stack)
    int top() {
        if (isEmpty()) {
            cout << "[Lỗi] Stack đang rỗng!\n";
            return -1;
        }
        return truyCap(L, L.size - 1);
    }

    // int pop(): xóa phần tử cuối khỏi stack và trả về phần tử đó
    int pop() {
        if (isEmpty()) {
            cout << "[Lỗi] Stack đang rỗng, không thể pop!\n";
            return -1;
        }
        int val = top();
        xoaCuoi(L);
        return val;
    }

    // int size(): trả về kích thước của stack
    int size() {
        return L.size;
    }
};

int main() {
    Stack s;

    cout << "--- DEMO STACK DÙNG LIST ---\n";
    cout << "1. Kiểm tra ban đầu:\n";
    cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << s.size() << endl;

    cout << "\n2. Push các phần tử 10, 20, 30, 40 vào stack:\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "size() sau khi push: " << s.size() << endl;
    cout << "top() hiện tại: " << s.top() << endl;
    cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << endl;

    cout << "\n3. Pop phần tử ra khỏi stack:\n";
    cout << "Pop ra: " << s.pop() << endl; // 40
    cout << "top() sau khi pop: " << s.top() << endl; // 30
    cout << "size() hiện tại: " << s.size() << endl; // 3

    cout << "\n4. Pop tất cả các phần tử còn lại:\n";
    while (!s.isEmpty()) {
        cout << "Pop: " << s.pop() << endl;
    }

    cout << "\n5. Kiểm tra sau khi pop hết:\n";
    cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << s.size() << endl;

    return 0;
}
