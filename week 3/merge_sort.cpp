#include <iostream>
#include<vector>
using namespace std;
// tron 2 day con : day 1 [l, m] va day 2 [m+1, r] 
// 2 day nay da duoc sap xep tang dan
void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1); // copy day 1 tu l den mid 
    vector<int> y(a+m+1, a+r+1); // copy day 2 tu mid+1 den r
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] < y[j]){
            a[l] = x[i]; // gan phan tu nho hon vao mang a
            i++; l++; // roi tang i va l len 1
        }
        else{
            a[l] = y[j]; // gan phan tu nho hon vao mang a
            j++; l++; // roi tang j va l len 1
        }
    }
    while(i < x.size()){ // neu con phan tu trong day 1
        a[l] = x[i]; // gan vao mang a
        i++; l++; // roi tang i va l len 1
    }
    while(j < y.size()){ // neu con phan tu trong day 2
        a[l] = y[j]; // gan vao mang a
        j++; l++; // roi tang j va l len 1
    }

}
void mergeSort(int a[], int l, int r ){
    if(l >= r ) return; // neu day chi co 1 phan tu thi return
    int m = (l+r)/2; // tim mid 
    mergeSort(a, l, m); // tiep tuc chia day con ben trai roi sap xep thanh day 1
    mergeSort(a, m+1, r); // tiep tuc chia day con ben phai roi sap xep thanh day 2
    merge(a, l, m, r); // tron 2 day con lai
}

int main(){
    int n; cin >>n;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = rand()%1000; // random cac phan tu trong mang
    }
    mergeSort(a, 0, n-1); // sap xep mang a tu vi tri 0 den n-1
    for(int i = 0; i < n; i++){
        cout << a[i] << " "; // in ra mang a da duoc sap xep
    }
}