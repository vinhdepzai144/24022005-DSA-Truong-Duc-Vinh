#include <iostream>
#include <utility>

using namespace std;

// ============================================================================
// HÀNG ĐỢI ƯU TIÊN (PRIORITY QUEUE - MAX HEAP)
// Cây nhị phân hoàn chỉnh lưu trên mảng 1-based (bắt đầu từ chỉ số 1):
// - Nút cha của k là: k / 2
// - Con trái của k là: 2 * k
// - Con phải của k là: 2 * k + 1
// ============================================================================

const int MAX_SIZE = 100005; // Dung lượng tối đa của hàng đợi
int pq[MAX_SIZE];            // Mảng lưu các phần tử heap (chỉ số 1..n)
int n = 0;                   // Số lượng phần tử hiện tại trong MaxPQ

// Hàm swim (nổi lên / shift up) - Đưa phần tử tại vị trí k lên đúng vị trí
void swim(int k) {
    while (k > 1 && pq[k / 2] < pq[k]) {
        swap(pq[k / 2], pq[k]);
        k = k / 2;
    }
}

// Hàm sink (chìm xuống / shift down) - Đưa phần tử tại vị trí k xuống đúng vị trí
void sink(int k) {
    while (2 * k <= n) {
        int j = 2 * k; // Con bên trái
        // Nếu có con bên phải và con phải lớn hơn con trái thì chọn con phải
        if (j < n && pq[j] < pq[j + 1]) {
            j++;
        }
        // Nếu nút cha đã lớn hơn hoặc bằng con lớn nhất thì dừng lại
        if (pq[k] >= pq[j]) {
            break;
        }
        swap(pq[k], pq[j]);
        k = j;
    }
}

// 1. MaxPQ(): Khởi tạo hàng đợi ưu tiên rỗng
void init() {
    n = 0;
}

// 2. MaxPQ(Key[] a): Tạo hàng đợi ưu tiên từ một mảng cho trước
// Sử dụng thuật toán vun đống Bottom-up (sink từ n/2 lùi về 1) đạt O(N)
void create(int a[], int m) {
    n = m;
    for (int i = 0; i < m; ++i) {
        pq[i + 1] = a[i]; // Đưa vào mảng 1-based
    }
    for (int k = n / 2; k >= 1; --k) {
        sink(k);
    }
}

// 3. void insert(Key v): Thêm một phần tử vào hàng đợi ưu tiên - O(log N)
void insert(int v) {
    if (n >= MAX_SIZE - 1) {
        cout << "Hang doi uu tien da day!\n";
        return;
    }
    n++;
    pq[n] = v;
    swim(n);
}

// 4. Key delMax(): Lấy ra và xóa phần tử lớn nhất - O(log N)
int delMax() {
    if (n == 0) {
        cout << "Hang doi uu tien rong!\n";
        return -1;
    }
    int maxVal = pq[1];     // Phần tử lớn nhất nằm ở gốc (vị trí 1)
    swap(pq[1], pq[n]);     // Đổi chỗ gốc với phần tử cuối
    n--;                    // Giảm kích thước heap
    sink(1);                // bơi xuống
    return maxVal;
}

// 5. boolean isEmpty(): Kiểm tra hàng đợi có rỗng không - O(1)
bool isEmpty() {
    return n == 0;
}

// 6. Key max(): Trả về phần tử lớn nhất nhưng không xóa - O(1)
int max() {
    if (n == 0) {
        cout << "Hang doi uu tien rong!\n";
        return -1;
    }
    return pq[1];
}

// 7. int size(): Số lượng phần tử hiện có trong hàng đợi ưu tiên - O(1)
int size() {
    return n;
}

// Hàm in các phần tử trong heap hiện tại
void printHeap() {
    cout << "[ ";
    for (int i = 1; i <= n; ++i) {
        cout << pq[i] << " ";
    }
    cout << "]\n";
}

int main() {
    cout << "====================================================\n";
    cout << "         DEMO PRIORITY QUEUE (MAX-HEAP)             \n";
    cout << "====================================================\n";

    // Khởi tạo hàng đợi rỗng
    init();
    cout << "1. Khoi tao hang doi rong: isEmpty() = " << (isEmpty() ? "true" : "false") << "\n\n";

    // Chèn các phần tử vào hàng đợi (có cả phần tử trùng lặp)
    cout << "2. Chen cac phan tu: 15, 20, 7, 20, 9, 30, 25:\n";
    int data[] = {15, 20, 7, 20, 9, 30, 25};
    int m = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < m; ++i) {
        insert(data[i]);
        cout << "   -> insert(" << data[i] << ") | max = " << max() 
             << " | size = " << size() << " | Heap: ";
        printHeap();
    }
    cout << "\n";

    // Xem phần tử lớn nhất và kích thước
    cout << "3. Thong tin hien tai:\n";
    cout << "   - max(): " << max() << "\n";
    cout << "   - size(): " << size() << "\n";
    cout << "   - isEmpty(): " << (isEmpty() ? "true" : "false") << "\n\n";

    // Rút lần lượt các phần tử lớn nhất bằng delMax()
    cout << "4. Rut lan luot cac phan tu lon nhat (delMax):\n";
    while (!isEmpty()) {
        int val = delMax();
        cout << "   -> delMax() = " << val << " | size con lai = " << size() << " | Heap: ";
        printHeap();
    }
    cout << "   - Sau khi rut het: isEmpty() = " << (isEmpty() ? "true" : "false") << "\n\n";

    // Khởi tạo trực tiếp từ mảng ban đầu
    cout << "5. Tao MaxPQ truc tiep tu mang {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}:\n";
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int len = sizeof(a) / sizeof(a[0]);
    create(a, len);

    cout << "   - Heap tao boi create(): ";
    printHeap();
    cout << "   - max(): " << max() << "\n";
    cout << "   - size(): " << size() << "\n";

    return 0;
}
