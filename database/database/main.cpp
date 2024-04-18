#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::cin;

struct StudentSubjectsGrades
{
    size_t id;
    size_t studentId;
    size_t subjectId;

    float grade;
};

struct Subject
{
    size_t id;
    string name;
};

struct Student {
    size_t id;
    string firstName, middleName, lastName;
};

size_t getLastIdFromFile(const string& fileName) {
    std::ifstream infile(fileName);

    if (!infile.is_open()) {
        throw std::runtime_error("File couldn't be opened");
    }

    size_t lastId = 0;
    string line;
    while (getline(infile, line)) {
        size_t id;
        // Assuming the file format is "id - firstName - middleName - lastName"
        std::istringstream iss(line);
        if (iss >> id) {
            lastId = id;
        }
    }

    infile.close();
    return lastId;
}

 Subject getSubjectById(const string& fileName, size_t targetId) {
    std::ifstream infile(fileName);

    if (!infile.is_open()) {
        throw std::runtime_error("File couldn't be opened");
    }

    Subject sub;
    string line;
    while (getline(infile, line)) {
        std::istringstream iss(line);
        char separator;
        if (iss >> sub.id >> separator >> sub.name) {
            if (sub.id == targetId) {
                infile.close();
                return sub;
            }
        }
    }

    infile.close();
    // If the ID is not found, return a student with ID 0
    return { 0, ""};
}

 StudentSubjectsGrades getStudentSubjectGradeById(const string& fileName, size_t targetId) {
     std::ifstream infile(fileName);
     if (!infile.is_open()) {
         throw std::runtime_error("File couldn't be opened");
     }

     StudentSubjectsGrades ssg;
     string line;
     while (getline(infile, line)) {
         std::istringstream iss(line);
         char separator;
         if (iss >> ssg.id >> separator >> ssg.studentId >> separator >> ssg.subjectId >> separator >> ssg.grade) {
             if (ssg.id == targetId) {
                 infile.close();
                 return ssg; // Return the found StudentSubjectsGrades object
             }
         }
     }

     infile.close();
     // If the ID is not found, return an empty StudentSubjectsGrades object
     return { 0, 0, 0, 0.0 };
 }

Student getStudentById(const string& fileName, size_t targetId) {
    std::ifstream infile(fileName);

    if (!infile.is_open()) {
        throw std::runtime_error("File couldn't be opened");
    }

    Student stud;
    string line;
    while (getline(infile, line)) {
        std::istringstream iss(line);
        char separator;
        if (iss >> stud.id >> separator >> stud.firstName >> separator >> stud.middleName >> separator >> stud.lastName) {
            if (stud.id == targetId) {
                infile.close();
                return stud;
            }
        }
    }

    infile.close();
    // If the ID is not found, return a student with ID 0
    return { 0, "", "", "" };
}

int main() {

        Student stud;
        cin >> stud.firstName;
        cin >> stud.middleName;
        cin >> stud.lastName;
        stud.id = getLastIdFromFile("students.txt") + 1;  

    std::ofstream writeFile("students.txt", std::ios::app); // Open in append mode
    if (writeFile.is_open()) {
            writeFile << stud.id << " - "<< stud.firstName << " - "
                << stud.middleName << " - " << stud.lastName << "\n";
        writeFile.close();
        std::cout << "Data written to students.txt\n";
    }
    else {
        std::cout << "Unable to open file for writing\n";
    }

    StudentSubjectsGrades ssg;
    cin >> ssg.studentId;
    cin >> ssg.subjectId;
    cin >> ssg.grade;
    ssg.id = getLastIdFromFile("StudentSubjectsGrades.txt") + 1;

    std::ofstream writeFile1("StudentSubjectsGrades.txt", std::ios::app);
    if (writeFile1.is_open()) {
        writeFile1 << ssg.id << " - " << ssg.studentId << " - " << ssg.subjectId << " - " << ssg.grade << "\n";
        writeFile1.close();
        std::cout << "Data written to StudentSubjectsGrades.txt\n";
    }
    else {
        std::cout << "Unable to open file for writing\n";
    }

    // Searching for a student by ID
    size_t targetId;
    std::cout << "Enter the ID to search for: ";
    std::cin >> targetId;

    try {
        Student foundStudent = getStudentById("students.txt", targetId);
        if (foundStudent.id != 0) {
            std::cout << "Student found:\n";
            std::cout << "ID: " << foundStudent.id << "\n";
            std::cout << "Name: " << foundStudent.firstName << " " << foundStudent.middleName << " " << foundStudent.lastName << "\n";
        }
        else {
            std::cout << "Student with ID " << targetId << " not found.\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    try {
        Subject foundSubject = getSubjectById("subjects.txt", targetId);
        if (foundSubject.id != 0) {
            std::cout << "subjects found:\n";
            std::cout << "ID: " << foundSubject.id << "\n";
            std::cout << "Name: " << foundSubject.name <<"\n";
        }
        else {
            std::cout << "Student with ID " << targetId << " not found.\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }


    try {
        // Retrieve the StudentSubjectsGrades object by ID
        StudentSubjectsGrades foundSSG = getStudentSubjectGradeById("StudentSubjectsGrades.txt", targetId);

        if (foundSSG.id != 0) {
            std::cout << "StudentSubjectGrade found:\n";
            std::cout << "ID: " << foundSSG.id << "\n";
            std::cout << "Student ID: " << foundSSG.studentId << "\n";
            std::cout << "Subject ID: " << foundSSG.subjectId << "\n";
            std::cout << "Grade: " << foundSSG.grade << "\n";
        }
        else {
            std::cout << "StudentSubjectGrade with ID " << targetId << " not found.\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}