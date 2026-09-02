#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Person {
public:
    virtual void showDetails() {
        cout << "This is a person." << endl;
    }
};

// Derived class
class Student : public Person {
private:
    string name;
    int rollNo;
    int marks;
    int attendance;

public:
    // Encapsulation: controlled access via public functions
    void getDetails(string n, int r, int m, int a) {
        name = n;
        rollNo = r;
        marks = m;
        attendance = a;
    }

    // Function overloading (compile-time polymorphism)
    void calculateGrade() {
        if (marks >= 90) cout << "Grade: A+" << endl;
        else if (marks >= 75) cout << "Grade: A" << endl;
        else if (marks >= 60) cout << "Grade: B" << endl;
        else cout << "Grade: C" << endl;
    }

    void calculateGrade(int bonusAttendance) {
        int finalMarks = marks + bonusAttendance;
        if (finalMarks >= 90) cout << "Grade (with attendance): A+" << endl;
        else if (finalMarks >= 75) cout << "Grade (with attendance): A" << endl;
        else if (finalMarks >= 60) cout << "Grade (with attendance): B" << endl;
        else cout << "Grade (with attendance): C" << endl;
    }

    // Function overriding (runtime polymorphism)
    void showDetails() override {
        cout << "----------------------------------" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
        cout << "Attendance: " << attendance << "%" << endl;
    }
};

int main() {
    vector<Student> students;

    // Adding multiple student records
    Student s1, s2, s3;
    s1.getDetails("Arun", 101, 85, 90);
    s2.getDetails("Priya", 102, 92, 95);
    s3.getDetails("Rahul", 103, 70, 80);

    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    // Classic for loop (works in all compilers)
    for (int i = 0; i < students.size(); i++) {
        students[i].showDetails();
        students[i].calculateGrade();
        students[i].calculateGrade(5); // attendance bonus
        cout << "----------------------------------" << endl;
    }

    return 0;
}


