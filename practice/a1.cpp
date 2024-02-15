#include <iostream>
#include <string>

using namespace std;

// Student structure
struct Student{
    int rollNo;
    string name;
    float sgpa;
};

// Function to swap two students
void swapStudents(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Bubble Sort to arrange students by roll number in ascending order
void bubbleSortByRoll(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swapStudents(students[j], students[j + 1]);
            }
        }
    }
}

// Insertion Sort to arrange students alphabetically by name
void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

// Quick Sort to find first ten toppers by SGPA
void quickSortBySGPA(Student students[], int low, int high) {
    if (low < high) {
        float pivot = students[high].sgpa;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (students[j].sgpa >= pivot) {
                i++;
                swapStudents(students[i], students[j]);
            }
        }
        swapStudents(students[i + 1], students[high]);

        quickSortBySGPA(students, low, i);
        quickSortBySGPA(students, i + 2, high);
    }
}

// Function to print students with the given SGPA
void searchBySGPA(Student students[], int n, float sgpa) {
    bool found = false;
    cout << "Students with SGPA " << sgpa << ":\n";
    for (int i = 0; i < n; i++) {
        if (students[i].sgpa == sgpa) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << sgpa << endl;
    }
}

// Binary Search to search a student by name
void binarySearchByName(Student students[], int n, string name) {
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (students[mid].name == name) {
            found = true;
            // Display all students with the same name
            for (int i = mid; i >= 0 && students[i].name == name; i--) {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }
            for (int i = mid + 1; i < n && students[i].name == name; i++) {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }
            break;
        } else if (students[mid].name < name) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "No student found with name " << name << endl;
    }
}

int main() {
    const int maxStudents = 15;
    Student students[maxStudents];

    // Input student records
    cout << "Enter details for " << maxStudents << " students:\n";
    for (int i = 0; i < maxStudents; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore(); // Clear newline from the buffer
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    // a) Bubble Sort by Roll Number
    bubbleSortByRoll(students, maxStudents);

    cout << "\na) Roll Call List (Sorted by Roll Number):\n";
    for (int i = 0; i < maxStudents; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }

    // b) Insertion Sort by Name
    insertionSortByName(students, maxStudents);

    cout << "\nb) Roll Call List (Sorted Alphabetically):\n";
    for (int i = 0; i < maxStudents; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }

    // c) Quick Sort to find First Ten Toppers by SGPA
    quickSortBySGPA(students, 0, maxStudents - 1);

    cout << "\nc) First Ten Toppers:\n";
    for (int i = 0; i < min(maxStudents, 10); i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }

    // d) Search by SGPA
    float searchSGPA;
    cout << "\nd) Enter SGPA to search: ";
    cin >> searchSGPA;
    searchBySGPA(students, maxStudents, searchSGPA);

    // e) Binary Search by Name
    string searchName;
    cout << "\ne) Enter Name to search: ";
    cin.ignore(); // Clear newline from the buffer
    getline(cin, searchName);
    binarySearchByName(students, maxStudents, searchName);

    return 0;
}

