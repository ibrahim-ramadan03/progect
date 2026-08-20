#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x ;
    cout<< " enter number : ";
    cin>>x;
    for (int  i = 0; i <= 10; i++)
    {
        cout << i * x << "=" << i << "x" << x <<endl;
    }
    
    return 0;
}