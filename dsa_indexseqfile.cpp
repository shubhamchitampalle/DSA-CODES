#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct employee {
    int empIdNo;
    char name[50];
    char designation[50];
    int salary;
} employee;

class employeeDatabase {
    string fileName = "employee_data.dat";

   public:
    employeeDatabase() {
        fstream fileObj(fileName);
        if (fileObj.fail()) {
            fileObj.open(fileName, ios::out);
            cout << "New File Created" << endl;
        } else {
            cout << "Existing File Found" << endl;
        }
        fileObj.close();
    }

    void addEmployee();
    void searchEmployee();
    void deleteEmployee();
    void displayAll();
};

void employeeDatabase::searchEmployee() {
    int empId;
    employee emp;
    bool status = false;

    
    cout << "Enter Employee Id to delete:";
    cin >> empId;

    
    ifstream readFile;
    readFile.open(fileName, ios::in | ios::binary);

    
    while (readFile.read((char*)&emp, sizeof(employee))) {
        if (emp.empIdNo == empId) {
            status = true;
            break;
        }
    }
    readFile.close();

    if (status) {
        cout << "Found record with details" << endl;
        cout << "Employee ID:" << emp.empIdNo << endl;
        cout << "Name:" << emp.name << endl;
        cout << "Designation:" << emp.designation << endl;
        cout << "Salary:" << emp.salary << endl;
    } else {
        cout << "No record found" << endl;
    }
}

void employeeDatabase::deleteEmployee() {
    int empId;
    employee emp;
    bool status = false;

    
    cout << "Enter Employee Id to delete:";
    cin >> empId;

    
    ifstream readFile;
    readFile.open(fileName, ios::in | ios::binary);
    ofstream writeFile;
    writeFile.open("~" + fileName, ios::out | ios::binary);
    writeFile.clear();

    
    while (readFile.read((char*)&emp, sizeof(employee))) {
        if (emp.empIdNo == empId) {
            status = true;
        } else {
            writeFile.write((char*)&emp, sizeof(employee)) << flush;
        }
    }
    readFile.close();
    writeFile.close();

    
    if (status) {
        readFile.open("~" + fileName, ios::in | ios::binary);
        writeFile.open(fileName, ios::out | ios::binary);
        writeFile.clear();

        writeFile << readFile.rdbuf();
        readFile.close();
        writeFile.close();

        
        cout << "Deleted record" << endl;
    } else {
        cout << "No record found" << endl;
    }
}

void employeeDatabase::addEmployee() {
    employee emp;
    cout << "Enter Employee Id of employee:";
    cin >> emp.empIdNo;
    cout << "Enter Name of employee:";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter Designation of employee:";

    cin.getline(emp.designation, 50);
    cout << "Enter Salary of employee:";
    cin >> emp.salary;
    
    ofstream file(fileName, ios::out | ios::binary | ios::app);
    
    file.write((char*)&emp, sizeof(employee)) << flush;
    if (file.fail()) {
        cout << "Failed to add record" << endl;
    } else {
        cout << "Employee record added successfully" << endl;
    }
    file.close();
}

void employeeDatabase::displayAll() {
    ifstream file;
    employee emp;
    int count = 0;
    file.open(fileName, ios::in | ios::binary);
    while (file.read((char*)&emp, sizeof(employee))) {
        count++;
        cout << count << ") ";
        cout << emp.empIdNo << "|";
        cout << emp.name << "|";
        cout << emp.designation << "|";
        cout << emp.salary << endl;
    }
    if (count == 0) {
        cout << "No records Found" << endl;
    }
    file.close();
}
int main() {
    int ch;
    employeeDatabase db;

    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Display All Records" << endl;
        cout << "0. Exit" << endl << endl;
        cout << "Enter Your Choice :";
        cin >> ch;
        switch (ch) {
            case 0:
                cout << "Thank You" << endl;
                break;
            case 1:
                db.addEmployee();
                break;
            case 2:
                db.deleteEmployee();
                break;
            case 3:
                db.searchEmployee();
                break;
            case 4:
                cout << "Records in File are" << endl;
                db.displayAll();
                break;

            default:
                cout << "Enter a valid Choice" << endl;
                break;
        }
    } while (ch != 0);

    return 0;
}
/*sudo rm -rf /var/log/kern
sudo rm -rf /var/log/syslog*
cat /dev/null > ~/.bash_history && history -c*/