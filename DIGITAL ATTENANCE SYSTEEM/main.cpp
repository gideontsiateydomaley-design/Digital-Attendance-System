#include <iostream>
#include <fstream>
using namespace std;
#include <fstream>
class AttendanceSession {
public:
    string courseCode;
    string date;
    string startTime;
    int duration;

    void createSession() {
        cout << "Enter Course Code: ";
        cin >> courseCode;

        cout << "Enter Date: ";
        cin >> date;

        cout << "Enter Start Time: ";
        cin >> startTime;

        cout << "Enter Duration (Hours): ";
        cin >> duration;
    }

    void displaySession() {
        cout << "\nSession Created Successfully\n";
        cout << "Course: " << courseCode << endl;
        cout << "Date: " << date << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "Duration: " << duration << " hours\n";
    }
};
class Student {
public:
    string name;
    string indexNumber;

    void registerStudent() {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Index Number: ";
        cin >> indexNumber;
    }

    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Index Number: " << indexNumber << endl;
    }
};

class AttendanceSession {
public:
    string courseCode;
    string date;
    string startTime;
    int duration;

    void createSession() {
        cout << "Enter Course Code: ";
        cin >> courseCode;

        cout << "Enter Date: ";
        cin >> date;

        cout << "Enter Start Time: ";
        cin >> startTime;

        cout << "Enter Duration (Hours): ";
        cin >> duration;
    }

    void displaySession() {
        cout << "\nSession Created Successfully\n";
        cout << "Course: " << courseCode << endl;
        cout << "Date: " << date << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "Duration: " << duration << " hours\n";
    }
};

Student students[100];
string attendanceStatus[100];
int studentCount = 0;
AttendanceSession session;
string attendanceStatus[100];
void loadStudents() {
    ifstream file("students.txt");
    while(file >> students[studentCount].name
               >> students[studentCount].indexNumber) {
        studentCount++;
    }
    file.close();
}

void saveStudents() {
    ofstream file("students.txt");
    for(int i=0;i<studentCount;i++) {
        file << students[i].name << " "
             << students[i].indexNumber << endl;
    }
    file.close();
}

void addStudent() {
    void markAttendance() {
    for(int i = 0; i < studentCount; i++) {
        cout << "Mark attendance for " << students[i].name << endl;
        cout << "P = Present, A = Absent, L = Late: ";
        cin >> attendanceStatus[i];
    }
}
    students[studentCount].registerStudent();
    studentCount++;
}

void viewStudents() {
    cout << "\nRegistered Students\n";
    cout << "-------------------\n";
    for(int i = 0; i < studentCount; i++) {
        students[i].displayStudent();
        cout << "-------------------\n";
    }
}

void markAttendance() {
    for(int i = 0; i < studentCount; i++) {
        cout << "Mark attendance for " << students[i].name << endl;
        cout << "P = Present, A = Absent, L = Late: ";
        cin >> attendanceStatus[i];
    }
}

void attendanceSummary() {
    void saveAttendanceToFile() {

    ofstream file("attendance.txt");

    if(!file) {
        cout << "Error saving file!" << endl;
        return;
    }

    file << "Attendance Record\n";

    for(int i=0; i<studentCount; i++) {
        file << students[i].id << " "
             << students[i].name << " "
             << attendanceStatus[i] << endl;
    }

    file.close();

    cout << "Attendance saved to file successfully!\n";
}
    int present=0, absent=0, late=0;

    for(int i=0; i<studentCount; i++) {
        if(attendanceStatus[i]=="P") present++;
        else if(attendanceStatus[i]=="A") absent++;
        else if(attendanceStatus[i]=="L") late++;
    }

    cout << "\nATTENDANCE SUMMARY\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;
}

int main() {

    loadStudents();

    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Lecture Session\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Attendance Summary\n";
        cout << "6. Save Students\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: session.createSession(); session.displaySession(); break;
            case 4: markAttendance(); break;
            case 5: attendanceSummary(); break;
            case 6: saveStudents(); cout << "Saved Successfully!\n"; break;
        }

    } while(choice != 0);

    return 0;

}


