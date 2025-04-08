#include "Student.h"

int main() {
  int numStudents;
  cout << "Enter the number of students: ";
  cin >> numStudents;

  Student* students = new Student[numStudents];

  // Input data for each student
  /*for (int i = 0; i < numStudents; ++i) {
    cout << "\nEnter data for student" << i + 1 << ":" << endl;
    students[i].inputFromKeyboard();
  }

  ofstream outfile("student.bin", ios::binary);
  for (int i = 0; i < numStudents; ++i) {
    students[i].saveToFile(outfile);
  }
  outfile.close();*/

  // Load and display student data from the file
  ifstream infile("student.bin", ios::binary);

  cout << "\nLoading and displaying student data from the file:" << endl;
  Student loadedStudent;

  while (loadedStudent.loadFromFile(infile)) {
    loadedStudent.display();
  }
  infile.close();

  // Determine the number of failing students in a specified course
  int targetCourse;
  cout << "\nEnter the course number to count failing students: ";
  cin >> targetCourse;

  int failingCount = 0;
  // Load and process student data from the file
  ifstream failingInfile("student.bin", ios::binary);
  if (!failingInfile) {
    cerr << "Error opening file for reading!" << endl;
    // Deallocate memory before returning
    for (int i = 0; i < numStudents; ++i) {
      delete[] students[i].getName(); // Correct deallocation
    }
    delete[] students;
    return 1;
  }

  int studentCount = 0;
  while (loadedStudent.loadFromFile(failingInfile) && studentCount < numStudents) { // Limit to max number of students
    if (loadedStudent.getCourse() == targetCourse && loadedStudent.isFailing()) {
      failingCount++;
    }
    studentCount++;
  }
  failingInfile.close();

  cout << "Number of failing students in course " << targetCourse << ": " << failingCount << endl;

  return 0;
}