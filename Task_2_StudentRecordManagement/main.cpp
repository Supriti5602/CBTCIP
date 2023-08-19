#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

// Structure to hold student information
class Student
{

private:
    string firstName, lastName, age, gender, roll, course, department, address, email, phno, collegeName, percentage;

public:
    void menu();
    void addStudentRecords();
    void displayStudentRecords();
    void modifyStudentRecords();
    void searchStudentRecords();
    void deleteStudentRecords();
};

void Student::menu()
{
menustart:
    int choice;
    char x;

    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t| **STUDENT RECORD MANAGEMENT SYSTEM** |" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t1. Add Student Record" << endl;
    cout << "\t\t\t2. Display Student Records" << endl;
    cout << "\t\t\t3. Modify Student Record" << endl;
    cout << "\t\t\t4. Search Student Record" << endl;
    cout << "\t\t\t5. Delete Student Record" << endl;
    cout << "\t\t\t6. Exit" << endl;

    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t| Choose Option :[1/2/3/4/5/6] |" << endl;
    cout << "\t\t\t--------------------------------------" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:

        do
        {
            addStudentRecords();
            cout << "\n\t\t\tAdd Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'Y' || x == 'y');

        break;
    case 2:
        displayStudentRecords();
        break;
    case 3:
        modifyStudentRecords();
        break;
    case 4:
        searchStudentRecords();
        break;
    case 5:
        deleteStudentRecords();
        break;
    case 6:
        cout << "Exiting program......." << endl;
        exit(0);
        break;
    default:
        cout << "\t\t\tInvalid choice....... Please try again....." << endl;
    }
    // getch();
    goto menustart;
}

// Function to add a new student record

void Student::addStudentRecords()
{

    fstream file;
    cout << "\t\t\t------------------------------" << endl;
    cout << "\t\t\tAdd Student Details" << endl;
    cout << "\t\t\t------------------------------" << endl;

    cout << "\t\t\tEnter Student's First Name: ";
    cin >> firstName;

    cout << "\t\t\tEnter Student's Last Name: ";
    cin >> lastName;

    cout << "\t\t\tEnter Student's Age: ";
    cin >> age;

    cout << "\t\t\tEnter Student's Gender: ";
    cin >> gender;

    cout << "\t\t\tEnter Student's Roll Number: ";
    cin >> roll;

    cout << "\t\t\tEnter Student's Course Name: ";
    cin >> course;

    cout << "\t\t\tEnter Student's Department: ";
    cin >> department;

    cout << "\t\t\tEnter the Adress of Student(City Name): ";
    cin >> address;

    cout << "\t\t\tEnter the Email Id of Student: ";
    cin >> email;

    cout << "\t\t\tEnter the Contact Number of Student: ";
    cin >> phno;

    cout << "\t\t\tEnter Student's College Name: ";
    cin >> collegeName;

    cout << "\t\t\tEnter Student's Average Percentage: ";
    cin >> percentage;

    file.open("studentRecord.txt", ios::app | ios::out);
    file << "  " << firstName << "  " << lastName << "  " << age << "  " << gender << "  " << roll << "  " << course << "  " << department << "  " << address << "  " << email << "  " << phno << "  " << collegeName << "  " << percentage << "\n";
    file.close();
}

// Function to display all student records

void Student::displayStudentRecords()
{

    fstream file;
    int total = 1;

    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\tStudent Record Details" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo records found..." << endl;
        file.close();
    }
    else
    {

        file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;

        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No : " << total++;
            cout << "\n\n\t\t\t Student's First Name : " << firstName;
            cout << "\n\t\t\t Student's Last Name : " << lastName;
            cout << "\n\t\t\t Student's Age : " << age;
            cout << "\n\t\t\t Student's Gender : " << gender;
            cout << "\n\t\t\t Student's Roll No : " << roll;
            cout << "\n\t\t\t Student's Course : " << course;
            cout << "\n\t\t\t Student's department : " << department;
            cout << "\n\t\t\t Student's Address : " << address;
            cout << "\n\t\t\t Student's Email ID : " << email;
            cout << "\n\t\t\t Student's Contact Number : " << phno;
            cout << "\n\t\t\t Student's College Name : " << collegeName;
            cout << "\n\t\t\t Student's Percentage : " << percentage <<"%"<< endl;
            file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo records found..." << endl;
        }
    }
    file.close();
}

// Modify Student Records
void Student::modifyStudentRecords()
{

    fstream file, file1;
    int find = 0;
    string rollno;
    cout << "\n\n\t\t\t--------------------------------------" << endl;
    cout << "\t\t\tStudent Record Modification" << endl;
    cout << "\t\t\t--------------------------------------" << endl;

    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo records found..." << endl;
        file.close();
    }
    else
    {
        cout << "\nEnter Roll Number of the student which you want to Modify : ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);

        file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;

        while (!file.eof())
        {
            if (rollno != roll)
            {
                file1 << "  " << firstName << "  " << lastName << "  " << age << "  " << gender << "  " << roll << "  " << course << "  " << department << "  " << address << "  " << email << "  " << phno << "  " << collegeName << "  " << percentage << "\n";
            }
            else
            {
                cout << "\t\t\tEnter Student's First Name: ";
                cin >> firstName;

                cout << "\t\t\tEnter Student's Last Name: ";
                cin >> lastName;

                cout << "\t\t\tEnter Student's Age: ";
                cin >> age;

                cout << "\t\t\tEnter Student's Gender: ";
                cin >> gender;

                cout << "\t\t\tEnter Student's Roll Number: ";
                cin >> roll;

                cout << "\t\t\tEnter Student's Course Name: ";
                cin >> course;

                cout << "\t\t\tEnter Student's Department: ";
                cin >> department;

                cout << "\t\t\tEnter the Adress of Student: ";
                cin >> address;

                cout << "\t\t\tEnter the Email Id of Student: ";
                cin >> email;

                cout << "\t\t\tEnter the Contact Number of Student: ";
                cin >> phno;

                cout << "\t\t\tEnter Student's College Name: ";
                cin>>collegeName;

                cout << "\t\t\tEnter Student's Average Percentage: ";
                cin >> percentage;

                file1 << "  " << firstName << "  " << lastName << "  " << age << "  " << gender << "  " << roll << "  " << course << "  " << department << "  " << address << "  " << email << "  " << phno << "  " << collegeName << "  " << percentage << "\n";

                find++;
            }
            file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;

            
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

// Search from Student Record

void Student::searchStudentRecords()
{

    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t----------------" << endl;
        cout << "\t\t\t Search Record" << endl;
        cout << "\t\t\t---------------" << endl;
        cout << "\n\t\t\tNo records found..." << endl;
    }
    else
    {
        string roll_no;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t Search Record" << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\n \n Enter Roll No. of Student which you want to search: ";
        cin >> roll_no;
        file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;
        while (!file.eof())
        {
            if (roll_no == roll)
            {
                cout << "\n\n\t\t\t Student's First Name : " << firstName;
                cout << "\n\t\t\t Student's Last Name : " << lastName;
                cout << "\n\t\t\t Student's Age : " << age;
                cout << "\n\t\t\t Student's Gender : " << gender;
                cout << "\n\t\t\t Student's Roll No : " << roll;
                cout << "\n\t\t\t Student's Course : " << course;
                cout << "\n\t\t\t Student's department : " << department;
                cout << "\n\t\t\t Student's Address : " << address;
                cout << "\n\t\t\t Student's Email ID : " << email;
                cout << "\n\t\t\t Student's Contact Number : " << phno;
                cout << "\n\t\t\t Student's College Name : " << collegeName;
                cout << "\n\t\t\t Student's Percentage : " << percentage << endl;
                found++;
            }
            file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent roll No not found..." << endl;
        }
        file.close();
    }
}

// Delete from Student records

void Student::deleteStudentRecords()
{

    fstream file, file1;
    string rollNo;
    int found = 0;

    cout << "\t\t\t--------------------------------------" << endl;
    cout << "\t\t\tDelete from Student Record" << endl;
    cout << "\t\t\t--------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo records found..." << endl;
        file.close();
    }
    else
    {
        cout << "\n Enter Roll No which you want to delete :  ";
        cin >> rollNo;
        file1.open("Record.txt", ios::app | ios::out);
        file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;
        while (!file.eof())
        {
            if (rollNo != roll)
            {
                file1 << "  " << firstName << "  " << lastName << "  " << age << "  " << gender << "  " << roll << "  " << course << "  " << department << "  " << address << "  " << email << "  " << phno << "  " << collegeName << "  " << percentage << "\n";
            }
            file >> firstName >> lastName >> age >> gender >> roll >> course >> department >> address >> email >> phno >> collegeName >> percentage;
        }

        if (found == 0)
        {
            cout << "\n\t\t\tStudent's Record Deleted Successfully..." << endl;
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

int main()
{
    Student project;
    project.menu();

    return 0;
}
