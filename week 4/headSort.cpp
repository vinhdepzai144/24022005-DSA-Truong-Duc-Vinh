#include <iostream>
#include <utility>

using namespace std;

// ============================================================================
// THUẬT TOÁN HEAPSORT (SẮP XẾP VUN ĐỐNG TĂNG DẦN BẰNG MAX-HEAP)
// Sử dụng cây nhị phân hoàn chỉnh với mảng 1-based (chỉ số từ 1 đến n):
// - Nút cha của k là: k / 2
// - Con trái của k là: 2 * k
// - Con phải của k là: 2 * k + 1
// ============================================================================

// Hàm swim (nổi lên / shift up) trong heap
// Dùng khi thêm phần tử mới ở vị trí k và đưa nó nổi lên đúng vị trí
void swim(int a[], int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k / 2], a[k]);
        k = k / 2;
    }
}

// Hàm sink (chìm xuống / shift down) trong heap kích thước n
// Đưa phần tử tại vị trí k chìm xuống vị trí thích hợp trong đoạn a[1..n]
void sink(int a[], int k, int n) {
    while (2 * k <= n) {
        int j = 2 * k; // Con bên trái
        // Nếu có con bên phải và con phải lớn hơn con trái
        if (j < n && a[j] < a[j + 1]) {
            j++;
        }
        // Nếu nút cha đã lớn hơn hoặc bằng con lớn nhất thì dừng
        if (a[k] >= a[j]) {
            break;
        }
        swap(a[k], a[j]);
        k = j;
    }
}

// Hàm sắp xếp HeapSort tăng dần trên mảng a có n phần tử (chỉ số 1..n)
void heapSort(int a[], int n) {
    if (n <= 1) return;

    // Bước 1: Xây dựng Max-Heap từ mảng ban đầu (vun đống từ n/2 lùi về 1) - O(N)
    for (int k = n / 2; k >= 1; --k) {
        sink(a, k, n);
    }

    // Bước 2: Sortdown (đổi chỗ phần tử max ở a[1] về cuối rồi sink lại) - O(N log N)
    for (int i = n; i > 1; --i) {
        swap(a[1], a[i]);  // Đưa phần tử lớn nhất a[1] về vị trí cuối hiện tại a[i]
        sink(a, 1, i - 1); // Vun đống lại mảng còn lại từ 1 đến i - 1
    }
}

// In mảng từ chỉ số 1 đến n
void printArray(int a[], int n) {
    cout << "[ ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}

int main() {
    cout << "====================================================\n";
    cout << "      DEMO HEAPSORT (SAP XEP TANG DAN VOI MAX-HEAP)  \n";
    cout << "====================================================\n";

    // Mảng 1-based (a[0] bỏ qua không dùng, các phần tử từ a[1] đến a[n])
    int a[] = {0, 12, 11, 13, 5, 6, 7, 13, 2, 9, 1};
    int n = sizeof(a) / sizeof(a[0]) - 1; // n = 10 phần tử

    cout << "Mang ban dau (1..n):\n";
    printArray(a, n);

    // Tiến hành sắp xếp tăng dần
    heapSort(a, n);

    cout << "\nMang sau khi HeapSort (tang dan):\n";
    printArray(a, n);

    cout << "\n----------------------------------------------------\n";
    cout << "Thu nghiem voi mang khac co ca so am va trung lap:\n";
    int b[] = {0, -5, 20, 0, 15, -10, 20, 8, 3};
    int m = sizeof(b) / sizeof(b[0]) - 1;

    cout << "Mang b ban dau: ";
    printArray(b, m);

    heapSort(b, m);

    cout << "Mang b sau khi HeapSort: ";
    printArray(b, m);

    return 0;
}
