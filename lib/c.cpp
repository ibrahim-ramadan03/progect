#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class person
{
private:
    int id;
    string name;
    int age;

public:
    person()
    {
        id = 0;
        name = "";
        age = 0;
    }
    person(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    int GetId()
    {
        return id;
    }
    string GetName()
    {
        return name;
    }
    int GetAge()
    {
        return age;
    }

    void SetId(int id)
    {
        this->id = id;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    void SetAge(int age)
    {
        this->age = age;
    }
};
class student : public person
{
private:
    int years;
    string semester;
    int gpa;

public:
    student()
    {
        years = 0;
        semester = "";
        gpa = 0;
    }
    student(int id, string name, int age, int years, string semester, int gpa)
        : person(id, name, age)
    {
        this->years = years;
        this->semester = semester;
        this->gpa = gpa;
    }
    // GETTER
    int GetYears()
    {
        return years;
    }
    string GetSemester()
    {
        return semester;
    }
    int GetAGpa()
    {
        return gpa;
    }
    // SETTER
    void SetYears(int years)
    {
        this->years = years;
    }
    void SetSemester(string semester)
    {
        this->semester = semester;
    }
    void SetGpa(int gpa)
    {
        this->gpa = gpa;
    }
    void Input()
    {
        int id, age;
        string name;
        cout << " Enter Id : ";
        cin >> id;
        cin.ignore();

        cout << " Enter Name : ";
        getline(cin, name);

        cout << " Enter Age : ";
        cin >> age;

        cout << " Enter Years : ";
        cin >> id;
        cin.ignore();
        SetId(id);
        SetName(name);
        SetAge(age);

        cout << " Enter Semester : ";
        getline(cin, semester);

        cout << " Enter Gpa : ";
        cin >> gpa;
    }

    void Display()
    {

        cout << " Enter Id : " << GetId() << endl;
        cout << " Enter Name : " << GetName() << endl;
        cout << " Enter Age : " << GetAge() << endl;
        cout << " Enter Years : " << years << endl;
        cout << " Enter Semester : " << semester << endl;
        cout << " Enter Gpa : " << gpa << endl;
    };

    void Update()
    {
        int id, age;
        string name;
        cout << " Enter New Id : ";
        cin >> id;
        cin.ignore();

        cout << " Enter New Name : ";
        getline(cin, name);

        cout << " Enter New Age : ";
        cin >> age;

        cout << " Enter New Years : ";
        cin >> id;
        cin.ignore();

        cout << " Enter New Semester : ";
        getline(cin, semester);

        cout << " Enter New Gpa : ";
        cin >> gpa;

        SetId(id);
        SetName(name);
        SetAge(age);
    };
};

class school
{
private:
    vector<student> std;

public:
    void InputStudent()
    {
        student stud;
        stud.Input();
        std.push_back(stud);
    }
    void DisplayStudent()
    {
        int id;
        cout << " Enter id : ";
        cin >> id;
        for (auto &s : std)
        {
            if (s.GetId() == id)
            {
                s.Display();
            }
        }
    }
    void UpdateStudent()
    {
        int id;
        cout << " Enter id : ";
        cin >> id;
        for (auto &s : std)
        {
            if (s.GetId() == id)
            {
                s.Update();
            }
        }
    }

    void menu()
    {
        int choice;
        do
        {
            cout << "Enter 1 addStudent :\n ";
            cout << "Enter 2 disStudent :\n ";
            cout << "Enter 3 upStudent :\n ";
            cout << "Exit 0  : \n";
            cout << "Enter choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                InputStudent();
                break;

            case 2:
                DisplayStudent();
                break;

            case 3:
                UpdateStudent();
                break;

            default:
                cout << "error : ";
                break;
            }
        } while (choice != 0);
    }
};

int main()
{
    school s;
    s.menu();

    return 0;
}