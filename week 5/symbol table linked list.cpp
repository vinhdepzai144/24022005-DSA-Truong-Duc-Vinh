#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class ST {
private:
    struct Node {
        string key;
        int val;
        Node* next;

        Node(const string& k, int v, Node* n = nullptr)
            : key(k), val(v), next(n) {}
    };

    Node* head;
    int n;

    Node* findNode(const string& key) const {
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->key == key) {
                return cur;
            }
        }
        return nullptr;
    }

public:
    // ST(): create an empty symbol table
    ST() : head(nullptr), n(0) {}

    ~ST() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // void put(string key, int val): put key-value pair into the table
    void put(const string& key, int val) {
        Node* node = findNode(key);
        if (node != nullptr) {
            node->val = val; // Cập nhật nếu key đã tồn tại
            return;
        }
        head = new Node(key, val, head);
        n++;
    }

    // int get(string key): value paired with key
    int get(const string& key) const {
        Node* node = findNode(key);
        if (node != nullptr) {
            return node->val;
        }
        throw out_of_range("Key not found");
    }

    // bool contains(string key): is there a value paired with key?
    bool contains(const string& key) const {
        return findNode(key) != nullptr;
    }

    // void delete(string key): remove key (and its value) from table
    // Đổi tên thành deleteKey vì 'delete' là từ khóa trong C++
    void deleteKey(const string& key) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->key == key) {
                if (prev == nullptr) {
                    head = cur->next;
                } else {
                    prev->next = cur->next;
                }
                delete cur;
                n--;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }

    // bool isEmpty(): is the table empty?
    bool isEmpty() const {
        return n == 0;
    }

    // int size(): number of key-value pairs in the table
    int size() const {
        return n;
    }

    // vector<string> keys(): all the keys in the table
    vector<string> keys() const {
        vector<string> result;
        result.reserve(n);
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            result.push_back(cur->key);
        }
        return result;
    }
};

int main() {
    ST st;

    st.put("S", 0);
    st.put("E", 1);
    st.put("A", 2);
    st.put("R", 3);
    st.put("C", 4);
    st.put("H", 5);
    st.put("E", 6); // Ghi đè giá trị của "E" từ 1 thành 6

    cout << "=== Linked List Symbol Table ===\n";
    cout << "Size: " << st.size() << "\n";
    cout << "isEmpty: " << (st.isEmpty() ? "true" : "false") << "\n";
    cout << "Contains 'E': " << (st.contains("E") ? "true" : "false") << "\n";
    cout << "Get 'E': " << st.get("E") << "\n";

    cout << "All keys:\n";
    for (const auto& k : st.keys()) {
        cout << "  " << k << " -> " << st.get(k) << "\n";
    }

    st.deleteKey("E");
    cout << "After deleting 'E', size: " << st.size() << "\n";
    cout << "Contains 'E': " << (st.contains("E") ? "true" : "false") << "\n";

    return 0;
}
