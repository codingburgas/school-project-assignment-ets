#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

size_t getLastIdFromFile(string fileName) {

    std::ifstream infile(fileName);

    // Check if the file is opened successfully
    if (!infile.is_open()) {
        throw std::runtime_error("File couldn't be opened");
    }
    if (infile.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }
    
    std::vector<std::vector<int>> matrix;
    std::string line;
    while (std::getline(infile, line)) {
        // Check if the line starts with '3'
        
        std::vector<int> row;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    // Close the file
    infile.close();

    // Get the number of rows and columns in the matrix
    int rows = matrix.size();
    int cols = (rows > 0) ? matrix[0].size() : 0;

    // Read the first number of the last row
    if (rows > 0 && cols > 0) {
        int firstNumberLastRow = matrix[rows - 1][0];
        std::cout << "First number of the last row: " << firstNumberLastRow << std::endl;
        return firstNumberLastRow;
    } else {
        std::cout << "Matrix is empty." << std::endl;
        return 0;
    }
}

int main() {
    std::vector<Student> students;

    for (int i = 0; i < 3; i++) {
        Student stud;
        cin >> stud.firstName;
        cin >> stud.middleName;
        cin >> stud.lastName;
        stud.id = getLastIdFromFile("students.txt") + i + 1;

        students.push_back(stud);
    }

    std::ofstream writeFile("students.txt", std::ios::app); // Open in append mode
    if (writeFile.is_open()) {
        for (const auto& stud : students) {
            writeFile << stud.id << " - " << stud.firstName << " - "
                << stud.middleName << " - " << stud.lastName << "\n";
        }
        writeFile.close();
        std::cout << "Data written to students.txt\n";
    }
    else {
        std::cout << "Unable to open file for writing\n";
    }

    return 0;
}