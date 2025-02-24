#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int STEPS = 10;

struct Node {
    char data;
    Node* link1 = nullptr;
    Node* link2 = nullptr;
    Node* link3 = nullptr;
};

int main() {
    srand(time(0));

    Node L, I, V, E;

    L.data = 'L';
    I.data = 'I';
    V.data = 'V';
    E.data = 'E';

    L.link1 = &I;
    L.link2 = &V;
    L.link3 = &E;

    I.link1 = &L;
    I.link2 = &V;
    I.link3 = &E;

    V.link1 = &L;
    V.link2 = &I;
    V.link3 = &E;

    E.link1 = &L;
    E.link2 = &I;
    E.link3 = &V;

    Node* head = &L;

    for (int i = 0; i < STEPS; i++) {
        cout << head->data << " ";

        int choice = rand() % 3;
        switch (choice) {
            case 0:
            head = head->link1;
            break;

            case 1:
            head = head->link2;
            break;

            case 2:
            head = head->link3;
            break;
        }
    }

    cout << endl;
    return 0;
}
