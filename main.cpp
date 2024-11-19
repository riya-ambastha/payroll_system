#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Employee Class
class Employee {
private:
    int empID;
    string name;
    string designation;
    double basicSalary;
    double allowance;
    double deductions;

public:
    // Constructor
    Employee(int id, string n, string desig, double salary, double allow, double deduct)
        : empID(id), name(n), designation(desig), basicSalary(salary), allowance(allow), deductions(deduct) {}

    // Function to calculate net salary
    double calculateNetSalary() const {
        return basicSalary + allowance - deductions;
    }

    // Display employee details and salary
    void displayDetails() const {
        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Allowance: $" << allowance << endl;
        cout << "Deductions: $" << deductions << endl;
        cout << "Net Salary: $" << calculateNetSalary() << endl;
        cout << "------------------------------------" << endl;
    }

    int getEmpID() const {
        return empID;
    }
};

// Payroll System Class
class PayrollSystem {
private:
    vector<Employee> employees;

public:
    // Add a new employee
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    // Display all employees' payroll
    void displayPayroll() const {
        if (employees.empty()) {
            cout << "No employees in the system!" << endl;
            return;
        }

        cout << "-------- Employee Payroll ---------" << endl;
        for (const auto& emp : employees) {
            emp.displayDetails();
        }
    }

    // Search employee by ID
    void searchEmployee(int id) const {
        for (const auto& emp : employees) {
            if (emp.getEmpID() == id) {
                cout << "Employee Found!" << endl;
                emp.displayDetails();
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }
};

int main() {
    PayrollSystem payroll;

    // Example employees
    payroll.addEmployee(Employee(101, "Alice", "Manager", 5000.00, 1000.00, 500.00));
    payroll.addEmployee(Employee(102, "Bob", "Developer", 4000.00, 800.00, 300.00));
    payroll.addEmployee(Employee(103, "Charlie", "Designer", 3500.00, 700.00, 200.00));

    // Main menu
    int choice;
    do {
        cout << "\n--- Payroll System Menu ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Payroll" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name, desig;
            double salary, allowance, deductions;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Designation: ";
            getline(cin, desig);
            cout << "Enter Basic Salary: ";
            cin >> salary;
            cout << "Enter Allowance: ";
            cin >> allowance;
            cout << "Enter Deductions: ";
            cin >> deductions;
            payroll.addEmployee(Employee(id, name, desig, salary, allowance, deductions));
            cout << "Employee added successfully!" << endl;
            break;
        }
        case 2:
            payroll.displayPayroll();
            break;
        case 3: {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            payroll.searchEmployee(id);
            break;
        }
        case 4:
            cout << "Exiting the Payroll System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
