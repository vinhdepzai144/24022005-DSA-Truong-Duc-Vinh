#include <iostream>
#include <vector>

using namespace std;
// phan hoach lomuto
// Hàm phân hoạch (Partition) mảng
int partition(int a[], int l, int r) {
    int pivot = a[r]; // Chọn phần tử chốt là phần tử cuối
    int i = (l - 1);     // Chỉ số của phần tử nhỏ hơn

    for (int j = l; j <= r - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (a[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); // Đặt pivot vao giua
    return (i + 1);
}

// Hàm đệ quy thực hiện Quick Sort
void quickSort(int a[], int l, int r) {
    if(l >= r) return; // Nếu mảng chỉ có 1 phần tử thì return
    int pi = partition(a, l, r); // Phân hoạch mảng
    quickSort(a, l, pi - 1); // Gọi đệ quy cho mảng bên trái của pivot
    quickSort(a, pi + 1, r); // Gọi đệ quy cho mảng bên phải của pivot  
}

// phan hoach Hoare

int main() {
    int a[100];
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        a[i] = rand() % 1000; // Random các phần tử trong mảng
    }
    quickSort(a, 0, n - 1); // Sắp xếp mảng a từ vị trí 0 đến n-1
    for(int i = 0; i < n; i++){
        cout << a[i] << " "; // In ra mảng a đã được sắp xếp
    }
    
}
