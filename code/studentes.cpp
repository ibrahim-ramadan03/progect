#include <iostream>
#include <vector>
using namespace std;

void calculate(int hours, int minutes, string name)
{
    int full_time = hours * 60 + minutes;

    if (full_time <= 9 * 60 + 30)
    {
        cout << "Your Name: " << name << endl;
        cout << "Degree: 95\n" << endl;
    }
    else if (full_time <= 9 * 60 + 40)
    {
        cout << "Your Name: " << name << endl;
        cout << "Degree: 80\n" << endl;
    }
    else if (full_time <= 9 * 60 + 45)
    {
        cout << "Your Name: " << name << endl;
        cout << "Degree: 60\n" << endl;
    }
    else
    {
        cout << "Your Name: " << name << endl;
        cout << "Degree: 50\n" << endl;
    }
}

int main()
{
    vector<int> hours = {9, 9, 9};
    vector<int> minutes = {30, 40, 45};
    vector<string> names = {"Ibrahim", "Yousef", "ahmed"};

    for (int i = 0; i < hours.size(); i++)
    {
        calculate(hours[i], minutes[i], names[i]);
    }

    return 0;
}