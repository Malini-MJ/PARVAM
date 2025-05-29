#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstring>

struct Student {
    std::string name;
    int grade;
};

// Logging Function
void logActivity(const std::string &activity, const std::string &filename) {
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        std::time_t now = std::time(nullptr);
        char *dt = std::ctime(&now);
        dt[strcspn(dt, "\n")] = '\0';
        outfile << "[" << dt << "] " << activity << "\n";
        outfile.close();
    } else {
        std::cout << "Unable to open log file.\n";
    }
}

// Display All Students
void displayStudents(const std::vector<Student> &students) {
    std::cout << "\nStudent Records:\n";
    for (const auto &s : students) {
        std::cout << "Name: " << s.name << ", Grade: " << s.grade << "\n";
    }
}

// Add Student
void addStudent(std::vector<Student> &students, const std::string &logFile) {
    Student s;
    std::cout << "Enter student's name: ";
    std::getline(std::cin, s.name);
    std::cout << "Enter student's grade: ";
    std::cin >> s.grade;
    std::cin.ignore(); // Clear newline
    students.push_back(s);
    logActivity("Added student: " + s.name, logFile);
}

// Search Student
void searchStudent(const std::vector<Student> &students) {
    std::string name;
    std::cout << "Enter student name to search: ";
    std::getline(std::cin, name);
    bool found = false;
    for (const auto &s : students) {
        if (s.name == name) {
            std::cout << "Found: " << s.name << " with Grade: " << s.grade << "\n";
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "Student not found.\n";
}

// Update Grade
void updateGrade(std::vector<Student> &students, const std::string &logFile) {
    std::string name;
    std::cout << "Enter student name to update grade: ";
    std::getline(std::cin, name);
    bool found = false;
    for (auto &s : students) {
        if (s.name == name) {
            std::cout << "Current grade: " << s.grade << ". Enter new grade: ";
            int newGrade;
            std::cin >> newGrade;
            std::cin.ignore(); // Clear newline
            s.grade = newGrade;
            logActivity("Updated grade for: " + name, logFile);
            std::cout << "Grade updated.\n";
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "Student not found.\n";
}

int main() {
    std::vector<Student> students;
    std::string logFile = "activity.log";
    logActivity("User started the program", logFile);

    int choice;
    do {
        std::cout << "\nMenu:\n1. Add Student\n2. Search Student\n3. Update Grade\n4. Display All Students\n5. Exit\nEnter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                addStudent(students, logFile);
                break;
            case 2:
                searchStudent(students);
                break;
            case 3:
                updateGrade(students, logFile);
                break;
            case 4:
                displayStudents(students);
                break;
            case 5:
                logActivity("User exited the program", logFile);
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}