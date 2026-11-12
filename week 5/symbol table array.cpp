#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class ST {
private:
    string* keysArr;
    int* valsArr;
    int capacity; // Sức chứa tối đa hiện tại của hai mảng đã được cấp phát.
    int n; // Số lượng cặp key - value thực tế đang lưu trong bảng

    void resize(int newCapacity) {
        // Tạo mảng mới với sức chứa mới
        // Sao chép các phần tử từ mảng cũ sang mảng mới
        // Xóa mảng cũ và cập nhật con trỏ mảng
        // Cập nhật sức chứa mới
        string* newKeys = new string[newCapacity];
        int* newVals = new int[newCapacity];
        for (int i = 0; i < n; i++) {
            newKeys[i] = keysArr[i];
            newVals[i] = valsArr[i];
        }
        delete[] keysArr;
        delete[] valsArr;
        keysArr = newKeys;
        valsArr = newVals;
        capacity = newCapacity;
    }

    // Trả về số lượng key nhỏ hơn 'key' (tìm kiếm nhị phân - O(log N))
    int rank(const string& key) const {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // (lo+hi)/2 có thể gây tràn số nguyên
            if (key < keysArr[mid]) {
                hi = mid - 1;
            } else if (keysArr[mid] < key) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return lo;
    }

public:
    // ST(): create an empty symbol table
    ST(int initialCapacity = 4)
        : keysArr(new string[initialCapacity]),
          valsArr(new int[initialCapacity]),
          capacity(initialCapacity),
          n(0) {}

    // ~ST() {
    //     delete[] keysArr;
    //     delete[] valsArr;
    // }

    // void put(string key, int val): put key-value pair into the table
    void put(const string& key, int val) {
        int i = rank(key);

        // Key đã tồn tại -> cập nhật value
        if (i < n && keysArr[i] == key) {
            valsArr[i] = val;
            return;
        }

        // Mở rộng mảng nếu đầy
        if (n == capacity) {
            resize(capacity * 2);
        }

        // Dịch các phần tử sang phải để chèn đúng thứ tự tăng dần
        for (int j = n; j > i; j--) {
            keysArr[j] = keysArr[j - 1];
            valsArr[j] = valsArr[j - 1];
        }
        keysArr[i] = key;
        valsArr[i] = val;
        n++;
    }

    // int get(string key): value paired with key
    int get(const string& key) const {
        if (isEmpty()) {
            throw out_of_range("Key not found");
        }
        int i = rank(key);
        if (i < n && keysArr[i] == key) {
            return valsArr[i];
        }
        throw out_of_range("Key not found");
    }

    // bool contains(string key): is there a value paired with key?
    bool contains(const string& key) const {
        if (isEmpty()) {
            return false;
        }
        int i = rank(key);
        return i < n && keysArr[i] == key;
    }

    // void delete(string key): remove key (and its value) from table
    // Đổi tên thành deleteKey vì 'delete' là từ khóa trong C++
    void deleteKey(const string& key) {
        if (isEmpty()) {
            return;
        }
        int i = rank(key);
        if (i == n || !(keysArr[i] == key)) {
            return; // Không tìm thấy key
        }

        // Dịch các phần tử bên phải sang trái
        for (int j = i; j < n - 1; j++) {
            keysArr[j] = keysArr[j + 1];
            valsArr[j] = valsArr[j + 1];
        }
        n--;

        // Thu nhỏ mảng khi chỉ dùng <= 1/4 dung lượng
        // if (n > 0 && n == capacity / 4 && capacity > 4) {
        //     resize(capacity / 2);
        // }
    }

    // bool isEmpty(): is the table empty?
    bool isEmpty() const {
        return n == 0;
    }

    // int size(): number of key-value pairs in the table
    int size() const {
        return n;
    }

    // vector<string> keys(): all the keys in the table (đã sắp xếp tăng dần)
    vector<string> keys() const {
        vector<string> result;
        result.reserve(n);
        for (int i = 0; i < n; i++) {
            result.push_back(keysArr[i]);
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

    cout << "=== Array (Binary Search) Symbol Table ===\n";
    cout << "Size: " << st.size() << "\n";
    cout << "isEmpty: " << (st.isEmpty() ? "true" : "false") << "\n";
    cout << "Contains 'E': " << (st.contains("E") ? "true" : "false") << "\n";
    cout << "Get 'E': " << st.get("E") << "\n";

    cout << "All keys (sorted):\n";
    for (const auto& k : st.keys()) {
        cout << "  " << k << " -> " << st.get(k) << "\n";
    }

    st.deleteKey("E");
    cout << "After deleting 'E', size: " << st.size() << "\n";
    cout << "Contains 'E': " << (st.contains("E") ? "true" : "false") << "\n";

    return 0;
}
