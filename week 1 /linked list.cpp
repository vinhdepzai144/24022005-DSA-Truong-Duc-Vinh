#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next;
};
typedef struct Node* node;
node makeNode(int x){
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL; //nullptr
	return tmp;
}
//hàm đếm danh sách liên kết có bao nhiêu phần tử 
int Size(node a){
    int cnt = 0;
    while(a!= NULL){
        a = a -> next; 
        cnt ++;
    }
    return cnt;
}
// 1. thêm một phần tử vào đầu danh sách liên kết
void insertFirst(node &a, int x){
    node tmp = makeNode(x);
    if ( a == NULL){
        a = tmp;
    }
    else {
        tmp -> next = a;// trỏ tmp vào địa chỉ thằng a ( phân tử đầu)
        a = tmp;
    }
    
}
// 2. thêm phần tử vào cuối dslk
void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else {
        node p = a;
        while( p -> next != NULL){
            p = p->next;
        }
        p -> next = tmp;
    }
}
// 3. thêm 1 phần tử vào giữa với k là vị trí muốn thêm
void insertMiddle(node &a, int x, int k){ 
    int n = Size(a);
    if (k <=0 || k > n+1){
        cout << "vị trí ko hợp lệ";
        return;
    }
    if( n == 1){
        insertFirst(a, x);
        return;
    }
    else if(n == k + 1 ){ 
        insertLast(a,x);
        return;
        }
    node p = a;
    for(int i = 1; i < k-1; i++){
        p = p-> next;
        // chỉ chạy đến k - 1 vì p = p-> next là cho p ở vị trị trước đó của k rồi;
    } 
    // lúc này p ở vị trí k - 1 rồi;
    node tmp = makeNode(x);
    tmp -> next = p -> next; // cho tmp chỉ vào k;
    p -> next = tmp;
}
// 4. xoá phần tử ở đầu
void deleteFirst(node &a){
    if ( a == NULL){
        return;
    }
    a = a->next;
}
// 5. xoá phần tử ở cuối
void deleteLast(node &a){
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau -> next != NULL ){
        truoc = sau;
        sau = sau->next; 
    }
    // sau while ta xác định được vị trị trước NULL, và vị trí trước đó mà mình muốn xoá ở cuối ( là truoc)
    if(truoc == NULL ){
        a = NULL; // sau while truoc vẫn bằng NULL thì tức là dslk có 1 phần tử, ta cho a = NULL hay xoá phần tử đó luôn
    }
    else {
        truoc ->next = NULL;
    }
}
// 6. xoá ở giữa 
void deleteMiddle(node &a, int k){
    if(k<=0 || k > Size(a) ){
        return;
    }
    node truoc = NULL, sau = a;
    for(int i = 1; i < k; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) {
        a = a->next; // hay ở đây là xoá ở đầu
    }
    else {
        truoc -> next = sau->next;
    }
}
// 7. duyệt in xuôi in
void inXuoi(node a){
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
}
// 8. duyệt in ngược
void inNguoc(node a) {
    if (a == NULL) return;     // Điều kiện dừng khi chạm đuôi danh sách

    inNguoc(a->next);     // Gọi đệ quy bước tiếp sang nút sau
    cout << a->data << " ";    // Khi hàm quay lui (backtrack) thì in ra
}
int main() {
	// khai bảo danh sách liên kết trong main thì chỉ cần khai bao Node
	// đầu tiên của nó thôi
	node head = NULL;
	while(1){
		cout << "1. Chen phan tu vao dau danh sach\n";
		cout << "2. Chen phan tu vao cuoi danh sach\n";
		cout << "3. Chen phan tu vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet xuoi danh sach lient ket\n";
    cout << "8. Duyet nguoc danh sach lien ket \n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertFirst(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			insertLast(head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap gia tri can chen :"; cin >> x;
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, x, pos);
		}
		else if(lc == 4){
			deleteFirst(head);
		}
		else if(lc == 5){
			deleteLast(head);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(lc == 7){
			inXuoi(head);
		}
    else if(lc == 8){
      inNguoc(head);
    }
		else if(lc == 0){
			break;
		}
	}
	

}
