#include <iostream>
#include <string>

using namespace std;

string ks[100];
int vals[100];
int cnt = 0;

void ST() {
    cnt = 0;
}

void put(string key, int value) {
    for (int i = 0; i < cnt; i++) {
        if (ks[i] == key) {
            vals[i] = value;
            return;
        }
    }

    if (cnt == 100) {
        cout << "Bang da day, khong the them key moi.\n";
        return;
    }

    ks[cnt] = key;
    vals[cnt] = value;
    cnt++;
}

int get(string key) {
    for (int i = 0; i < cnt; i++) {
        if (ks[i] == key) {
            return vals[i];
        }
    }

    return -1;
}

bool contains(string key) {
    for (int i = 0; i < cnt; i++) {
        if (ks[i] == key) {
            return true;
        }
    }

    return false;
}

void deleteKey(string key) {
    for (int i = 0; i < cnt; i++) {
        if (ks[i] == key) {
            for (int j = i; j < cnt - 1; j++) {
                ks[j] = ks[j + 1];
                vals[j] = vals[j + 1];
            }
            cnt--;
            return;
        }
    }
}

bool isEmpty() {
    return cnt == 0;
}

int size() {
    return cnt;
}

void keys() {
    for (int i = 0; i < cnt; i++) {
        cout << ks[i] << '\n';
    }
}

int main() {
    ST();

    put("apple", 10);
    put("banana", 20);
    put("orange", 30);

    if (contains("banana")) {
        cout << "Gia tri cua banana: " << get("banana") << '\n';
    }

    cout << "Co apple khong? " << (contains("apple") ? "Co" : "Khong") << '\n';

    deleteKey("apple");

    cout << "So cap key-value: " << size() << '\n';
    cout << "Bang rong? " << (isEmpty() ? "Co" : "Khong") << '\n';

    cout << "Cac key trong bang:\n";
    keys();

    return 0;
}
