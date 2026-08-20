#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;


//================================================
// كلاس يمثل الطالب
//================================================

class Student
{

private:

    int id;
    string name;
    string major;
    double gpa;


public:


    // إدخال بيانات الطالب
    void input()
    {
        cout << "Enter student ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter student name: ";
        getline(cin, name);


        cout << "Enter student major: ";
        getline(cin, major);


        cout << "Enter student GPA: ";
        cin >> gpa;
    }



    // عرض بيانات الطالب
    void display()
    {
        cout << "\nID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Major : " << major << endl;
        cout << "GPA : " << gpa << endl;
        cout << "----------------------\n";
    }



    // الحصول على رقم الطالب
    int getId()
    {
        return id;
    }



    // الحصول على الاسم
    string getName()
    {
        return name;
    }



    // الحصول على التخصص
    string getMajor()
    {
        return major;
    }



    // الحصول على المعدل
    double getGpa()
    {
        return gpa;
    }

};





//================================================
// كلاس إدارة الجامعة
//================================================


class University
{

private:

    sqlite3* db;


public:


    // فتح قاعدة البيانات
    University()
    {

        int result = sqlite3_open("university.db",&db);


        if(result == SQLITE_OK)
        {
            cout << "Database connected\n";
        }
        else
        {
            cout << "Database connection failed\n";
        }

    }



    // إغلاق قاعدة البيانات
    ~University()
    {
        sqlite3_close(db);
    }





    // إنشاء جدول الطلاب
    void createTable()
    {

        string sql =

        "CREATE TABLE IF NOT EXISTS Students("
        "id INTEGER PRIMARY KEY,"
        "name TEXT,"
        "major TEXT,"
        "gpa REAL);";


        char* error;


        int result = sqlite3_exec(
            db,
            sql.c_str(),
            nullptr,
            nullptr,
            &error
        );


        if(result != SQLITE_OK)
        {
            cout << error << endl;
            sqlite3_free(error);
        }

    }
    //================================================
// إضافة طالب جديد إلى قاعدة البيانات
//================================================

void addStudent()
{
    Student s;

    s.input();


    string sql =
    "INSERT INTO Students(id,name,major,gpa) VALUES("
    + to_string(s.getId()) +
    ",'" + s.getName() +
    "','" + s.getMajor() +
    "'," + to_string(s.getGpa()) +
    ");";


    char* error;


    int result = sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &error
    );


    if(result == SQLITE_OK)
    {
        cout << "Student added successfully\n";
    }
    else
    {
        cout << "Error : " << error << endl;
        sqlite3_free(error);
    }

}




//================================================
// عرض جميع الطلاب
//================================================

void displayStudents()
{

    string sql =
    "SELECT * FROM Students;";


    sqlite3_stmt* stmt;


    sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr
    );


    while(sqlite3_step(stmt) == SQLITE_ROW)
    {

        cout << "\nID : "
             << sqlite3_column_int(stmt,0)
             << endl;


        cout << "Name : "
             << sqlite3_column_text(stmt,1)
             << endl;


        cout << "Major : "
             << sqlite3_column_text(stmt,2)
             << endl;


        cout << "GPA : "
             << sqlite3_column_double(stmt,3)
             << endl;


        cout << "---------------------\n";

    }


    sqlite3_finalize(stmt);

}






//================================================
// البحث عن طالب بالرقم
//================================================

void searchStudent()
{

    int id;


    cout << "Enter student ID: ";
    cin >> id;



    string sql =
    "SELECT * FROM Students WHERE id="
    + to_string(id) + ";";



    sqlite3_stmt* stmt;


    sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr
    );



    if(sqlite3_step(stmt)==SQLITE_ROW)
    {

        cout << "\nID : "
        << sqlite3_column_int(stmt,0)
        << endl;


        cout << "Name : "
        << sqlite3_column_text(stmt,1)
        << endl;


        cout << "Major : "
        << sqlite3_column_text(stmt,2)
        << endl;


        cout << "GPA : "
        << sqlite3_column_double(stmt,3)
        << endl;

    }
    else
    {
        cout << "Student not found\n";
    }


    sqlite3_finalize(stmt);

}






//================================================
// تعديل بيانات طالب
//================================================

void updateStudent()
{

    int id;


    cout << "Enter student ID: ";
    cin >> id;


    string name;
    string major;
    double gpa;



    cin.ignore();


    cout << "New name: ";
    getline(cin,name);



    cout << "New major: ";
    getline(cin,major);



    cout << "New GPA: ";
    cin >> gpa;



    string sql =
    "UPDATE Students SET name='"
    + name +
    "', major='"
    + major +
    "', gpa="
    + to_string(gpa)
    +
    " WHERE id="
    + to_string(id)
    + ";";



    sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        nullptr
    );


    cout << "Student updated\n";

}






//================================================
// حذف طالب
//================================================

void deleteStudent()
{

    int id;


    cout << "Enter student ID: ";
    cin >> id;



    string sql =
    "DELETE FROM Students WHERE id="
    + to_string(id)
    + ";";



    sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        nullptr
    );


    cout << "Student deleted\n";

}






//================================================
// حساب عدد الطلاب
//================================================

void countStudents()
{

    string sql =
    "SELECT COUNT(*) FROM Students;";


    sqlite3_stmt* stmt;


    sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr
    );



    if(sqlite3_step(stmt)==SQLITE_ROW)
    {

        cout<<"Number of students : "
        <<sqlite3_column_int(stmt,0)
        <<endl;

    }


    sqlite3_finalize(stmt);

}






//================================================
// القائمة الرئيسية
//================================================

void menu()
{

    int choice;


    do
    {

        cout << "\n===== University System =====\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Count Students\n";
        cout << "0. Exit\n";


        cout << "Choose : ";
        cin >> choice;



        switch(choice)
        {

        case 1:
            addStudent();
            break;


        case 2:
            displayStudents();
            break;


        case 3:
            searchStudent();
            break;


        case 4:
            updateStudent();
            break;


        case 5:
            deleteStudent();
            break;


        case 6:
            countStudents();
            break;


        case 0:
            cout<<"Exit...\n";
            break;


        default:
            cout<<"Wrong choice\n";

        }


    }while(choice!=0);

}


};




//================================================
// Main
//================================================

int main()
{

    University uni;


    uni.createTable();


    uni.menu();


    return 0;

}