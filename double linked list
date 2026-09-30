#include <bits/stdc++.h>
using namespace std;
struct Dnode{
    int data;
    Dnode *prev; // con tro chi phia truoc
    Dnode *next; // con tro chi phia sau
};
typedef struct Dnode *dnode;
dnode makeNode(int x){
    dnode tmp = new Dnode();
    tmp -> data = x;
    tmp -> prev = NULL;
    tmp -> next = NULL;
    return tmp;
}
// dem so luong phan tu;
int Size(dnode a){
    int cnt = 0;
    while (a != NULL){
        a = a-> next;
        cnt ++; 
    }
    return cnt;
}
//1. them vao dau danh sach
void insertFirst(dnode &a, int x){
    dnode tmp = makeNode(x);
    if ( a == NULL){
        a = tmp;
    }
    else {
        tmp -> next = a;
        a -> prev = tmp;// Nối liên kết ngược từ nút đầu cũ về tmp
        a = tmp;
    }
}
// 2. them vao cuoi dslk
void insertLast(dnode &a, int x){
    dnode tmp = makeNode(x);
    dnode p = a;
    if ( a == NULL){
        a = tmp;
        return;
    }
    while (p -> next != NULL){
        p = p->next;
    }
    p -> next = tmp;
    tmp -> prev = p;
}
// 3. them vao vi tri k;
void insertMiddle(dnode &a, int x, int k){
    int n = Size(a);
    if (k <= 0 || k > n+1){
        cout << " vi tri ko hop le " << endl;
        return;
    }
    if (k == 1){
        insertFirst(a,x);
        return;
    }
    if( k == n+1){
        insertLast(a,x);
        return;
    }
    dnode tmp = makeNode(x);
    dnode p = a;
    for(int i=1; i<k-1; i++){
        p = p->next;
    }
    tmp -> next = p->next;
    tmp ->prev = p;
    if (p->next != NULL) {
        p->next->prev = tmp; 
    }
    p->next = tmp;
}
//4. xoá phần tử ở đầu
void deleteFirst(dnode &a){
    if(a == NULL){
        return; // Nếu a == NULL, không có gì để xóa nên thoát hàm ngay lập tức để tránh lỗi.
    }
    dnode tmp = a;
    a = a-> next;
    if(a!= NULL){
        a-> prev = NULL;
        // Trong danh sách liên kết đôi, nút đầu tiên (head) không được phép có nút phía trước (prev phải bằng NULL).
    }
    delete tmp;
}
// 5. xoá phần tử ở cuối
void deleteLast(dnode &a){
    if ( a == NULL ) return; // th rỗng
    // th danh sách chỉ có 1 phần tử
    if ( a->next == NULL){
        delete a;
        a = NULL;
        return;
    }
    dnode tmp = a;
    while (tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> prev -> next = NULL; // cho thẳng trước đó trỏ vào NULL
    delete tmp;
}
//6. xoá ở vị trí k 
void deleteMiddle(dnode &a, int k){
   int n = Size(a);
   if(k <= 0 || k > n){
       cout << " vị trí ko hợp lệ " << endl;
       return;
   }
   if (k == 1){
       deleteFirst(a);
       return;
   }
   if(k == n){
       deleteLast(a);
       return;
   }
   dnode tmp = a;
   for(int i = 1; i < k; i++){
       tmp = tmp-> next;
   }
   tmp -> prev -> next = tmp ->next;
   tmp -> next -> prev = tmp ->prev;
   delete tmp;
}
//7. duyệt in xuôi 
void inXuoi(dnode a){
    while(a != NULL){
        cout << a-> data << " ";
        a = a-> next;
    }
    cout << endl;
}
//8. duyệt in ngược 
void inNguoc(dnode a){
    if ( a == NULL) return;
    dnode tmp = a;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main(){
    dnode head = NULL;

    insertFirst(head, 30);
    insertFirst(head, 10);
    insertLast(head, 50); // 10 30 50
    insertMiddle(head, 20, 2); // 10 20 30 50
    insertMiddle(head, 40, 4); // 10 20 30 40 50

    cout << "Danh sach in xuoi: ";
    inXuoi(head);

    cout << "Danh sach in nguoc: ";
    inNguoc(head);

    deleteMiddle(head, 3); // Xóa số 30
    cout << "Sau khi xoa vi tri 3: ";
    inXuoi(head);
}
