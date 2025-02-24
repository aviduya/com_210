#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 10;

int ** getRandomInt() {
    int ** arr = new int*[SIZE];
    for(int i = 0; i < SIZE; i++) {
        arr[i] = new int(rand() % 100);
    }

}

void displayInt(int ** pp) {
    for(int i = 0; i < SIZE; i++) {
        cout << *pp[i] << " ";
    }
    cout << endl;
}

void deleteInt(int ** pp) {
    for(int i = 0; i < SIZE; i++) {
        delete pp[i];
    }
    delete[] pp;
}

int main() {
    int ** pp = getRandomInt();
    displayInt(pp);
    deleteInt(pp);
    return 0;
}
