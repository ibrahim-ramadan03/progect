#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    double basicSalary = 0.0;
    double taxRate = 0.0;
    double insurance = 0.0;
    double otderDeductions = 0.0;
    double allowance = 0.0;
    double bonus = 0.0;
    int absentDays = 0;

    cout << "ادخل الراتب الاساسي: ";
    cin >> basicSalary;

    cout << "ادخل نسبة الضريبة (مثال 15 لل 15%): ";
    cin >> taxRate;

    cout << "ادخل قيمة التأمين او الخصومات الثابتة: ";
    cin >> insurance;

    cout << "ادخل قيمة الخصومات الاخرى: ";
    cin >> otderDeductions;

    cout << "ادخل قيمة البدلات (مثلاً بدل سكن، بدل انتقال): ";
    cin >> allowance;

    cout << "ادخل عدد ايام الغياب: ";
    cin >> absentDays;

    cout << "ادخل قيمة المكافأة اذا وُجدت (اكتب 0 اذا لا توجد): ";
    cin >> bonus;

    double taxAmount = basicSalary * (taxRate / 100.0);
    double absenceDeduction = 0.0;
    if (absentDays > 0) {
        double dailySalary = basicSalary / 30.0;
        absenceDeduction = dailySalary * absentDays;
    }

    double totalDeductions = taxAmount + insurance + otderDeductions + absenceDeduction;
    double grossSalary = basicSalary + allowance;
    double netSalary = grossSalary - totalDeductions;
    double finalSalary = netSalary + bonus;

    cout << fixed << setprecision(2) << endl;
    cout << "----- ملخص المرتب -----" << endl;
    cout << "الراتب الاساسي: " << basicSalary << endl;
    cout << "البدلات: " << allowance << endl;
    cout << "الراتب الاجمالي قبل الخصومات: " << grossSalary << endl;
    cout << "قيمة الضريبة: " << taxAmount << endl;
    cout << "التأمين: " << insurance << endl;
    cout << "الخصومات الاخرى: " << otderDeductions << endl;
    cout << "خصم ايام الغياب: " << absenceDeduction << endl;
    cout << "اجمالي الخصومات: " << totalDeductions << endl;
    cout << "صافي المرتب بعد الخصم: " << netSalary << endl;
    cout << "المكافأة: " << bonus << endl;
    cout << "الراتب النهائي: " << finalSalary << endl;

    return 0;
}
