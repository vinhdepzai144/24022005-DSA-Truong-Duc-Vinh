#include <iostream>
#include <string>

using namespace std;

struct Node {
    string k;
    int v;
    Node* next;

    Node(string key, int value) {
        k = key;
        v = value;
        next = nullptr;
    }
};

Node* head = nullptr;
int cnt = 0;

void ST() {
    while (head != nullptr) {
        Node* p = head;
        head = head->next;
        delete p;
    }

    cnt = 0;
}

void put(string k, int v) {
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->k == k) {
            p->v = v;
            return;
        }
    }

    Node* p = new Node(k, v);
    p->next = head;
    head = p;
    cnt++;
}

int get(string k) {
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->k == k) {
            return p->v;
        }
    }

    return -1;
}

bool contains(string k) {
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->k == k) {
            return true;
        }
    }

    return false;
}

void deleteKey(string k) {
    Node* prev = nullptr;
    Node* p = head;

    while (p != nullptr) {
        if (p->k == k) {
            if (prev == nullptr) {
                head = p->next;
            } else {
                prev->next = p->next;
            }

            delete p;
            cnt--;
            return;
        }

        prev = p;
        p = p->next;
    }
}

bool isEmpty() {
    return cnt == 0;
}

int size() {
    return cnt;
}

void keys() {
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->k << '\n';
    }
}

int main() {
    ST();

    put("apple", 10);
    put("banana", 20);
    put("orange", 30);

    cout << "Gia tri cua banana: " << get("banana") << '\n';
    cout << "Co apple khong? " << (contains("apple") ? "Co" : "Khong") << '\n';

    deleteKey("apple");

    cout << "So cap key-value: " << size() << '\n';
    cout << "Bang rong? " << (isEmpty() ? "Co" : "Khong") << '\n';

    cout << "Cac key trong bang:\n";
    keys();

    ST();
    return 0;
}
