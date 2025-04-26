#include <iostream>
#include <string>
#include <stack>
using namespace std;

void ReverseStr(string normalStr) {
    stack<char> reversed_str;

    // Push each character onto the stack
    for (char ch : normalStr) {
        reversed_str.push(ch);
    }

    // Pop from the stack to reverse the string
    while (!reversed_str.empty()) {
        cout << reversed_str.top();
        reversed_str.pop();
    }
    cout << endl;
}

int main() {
    ReverseStr("hello");
    return 0;
}
