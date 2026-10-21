#include <iostream>
#include "Linked_List.h"

using namespace std;

// =========================================================================
// CÀI ĐẶT STACK BẰNG LINKED LIST (DANH SÁCH LIÊN KẾT ĐƠN)
// Trong DSLK đơn, quy ước ĐỈNH STACK là ĐẦU DANH SÁCH (head) để đạt độ phức tạp O(1)
// Sử dụng các hàm có sẵn trong Linked_List.h:
// - empty(head): kiểm tra dslk rỗng
// - Size(head): lấy số lượng phần tử
// - insertFirst(head, item): chèn vào đỉnh stack (O(1))
// - deleteFirst(head): xóa khỏi đỉnh stack (O(1))
// =========================================================================
struct Stack {
    node head = NULL;

    // bool isEmpty(): trả về true nếu stack rỗng và false nếu ngược lại
    bool isEmpty() {
        return empty(head);
    }

    // void push(int item): chèn một phần tử vào stack (vào đầu dslk)
    void push(int item) {
        insertFirst(head, item);
    }

    // int top(): trả về giá trị phần tử cuối được thêm vào (đỉnh stack)
    int top() {
        if (isEmpty()) {
            cout << "[Lỗi] Stack đang rỗng!\n";
            return -1;
        }
        return head->data;
    }

    // int pop(): xóa phần tử khỏi stack và trả về phần tử đó
    int pop() {
        if (isEmpty()) {
            cout << "[Lỗi] Stack đang rỗng, không thể pop!\n";
            return -1;
        }
        int val = top();
        deleteFirst(head);
        return val;
    }

    // int size(): trả về kích thước của stack
    int size() {
        return Size(head);
    }
};

int main() {
    Stack s;

    cout << "--- DEMO STACK DÙNG LINKED LIST ---\n";
    cout << "1. Kiểm tra ban đầu:\n";
    cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << s.size() << endl;

    cout << "\n2. Push các phần tử 100, 200, 300, 400 vào stack:\n";
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);

    cout << "size() sau khi push: " << s.size() << endl;
    cout << "top() hiện tại: " << s.top() << endl;
    cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << endl;

    cout << "\n3. Pop phần tử ra khỏi stack:\n";
    cout << "Pop ra: " << s.pop() << endl; // 400
    cout << "top() sau khi pop: " << s.top() << endl; // 300
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
