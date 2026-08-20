#include <iostream>
using namespace std;

int main() {

    int callTry = 1;

    while (callTry <= 3) {

        cout << "Yousef is calling Ibrahim" << endl;

        if (callTry == 1) {
            cout << "No answer" << endl;
        }

        else if (callTry == 2) {
            cout << "Phone is off" << endl;
        }

        else {
            cout << "Ibrahim answered" << endl;
        }

        cout << "----------------" << endl;

        callTry++;
    }

    return 0;
}