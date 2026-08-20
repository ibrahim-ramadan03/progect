#include <iostream>
using namespace std;

int main() {
    float x, y;

    cout << "Enter value of x: ";
    cin >> x;

    cout << "Enter value of y: ";
    cin >> y;

    if (x + (y * y) == 5) {
        cout << "Correct: x + y^2 = 5" << endl;
    } else {
        cout << "Wrong: x + y^2 is not equal to 5" << endl;
    }

    return 0;
}