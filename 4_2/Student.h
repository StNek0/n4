#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

class Student {
  char* name;   // Full name
  int age;          // Age
  int course;       // Course
  char gender;      // Gender (M/F)
  float grade;      // Average grade

public:
  // Default constructor
  Student() {}

  Student(const char* n, int a, int c, char g, float gr);

  // Copy constructor
  Student(const Student& other);

  // Move constructor
  Student(Student&& other);

  // Destructor
  ~Student();

  // Method to input student data from the keyboard
  void inputFromKeyboard();

  // Method to load student data from a binary file
  bool loadFromFile(ifstream& infile);

  // Method to save student data to a binary file
  void saveToFile(ofstream& outfile);

  // Method to display student data
  void display() const;

  // Method to check if the student is failing
  bool isFailing() const;

  // Getter for the course
  int getCourse() const;

  // Getter for the grade
  float getGrade() const;

  // Getter for the name
  const char* getName() const;
};