#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> numbers;
    int num;
    int size ;
    cout << "How many numbers do you want to enter? ";
    cin >> size;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter number: ";
        cin >> num;

        numbers.push_back(num);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Number " << i + 1 << ": " << numbers[i] << endl;
    }
    
    return 0;
}