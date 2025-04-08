#include "Student.h";

// Parameterized constructor
Student::Student(const char* n, int a, int c, char g, float gr) : age(a), course(c), gender(g), grade(gr) {
  name = _strdup(n);  // Duplicate the string
  if (name == nullptr) {
    cerr << "Memory allocation error!" << endl;
    // Handle the error appropriately, e.g., return
    return;
  }
}

// Copy constructor
Student::Student(const Student& other) : age(other.age), course(other.course), gender(other.gender), grade(other.grade) {
  if (other.name) {
    name = _strdup(other.name);  // Duplicate the string
    if (name == nullptr) {
      cerr << "Memory allocation error!" << endl;
      name = nullptr;
    }
  }
  else {
    name = nullptr;
  }

  cout << "Copy constructor called" << endl;
}

// Move constructor
Student::Student(Student&& other) : name(other.name), age(other.age), course(other.course), gender(other.gender), grade(other.grade) {
  name = other.name;
  other.name = nullptr; // Set source to null to prevent double deletion
  other.age = 0;
  other.course = 0;
  other.gender = *_strdup(" ");
  other.grade = 0;
  cout << "Move constructor called" << endl;
}

  // Destructor
Student::~Student() {
    delete[] getName(); // Release allocated memory
  }

  // Method to input student data from the keyboard
  void Student::inputFromKeyboard() {
    char tempName[100]; // Temporary buffer for input
    cout << "Enter full name: ";
    cin.ignore();  // Clear the buffer before reading a line
    cin.getline(tempName, 100);

    // Allocate new memory for the student and copy the data over
    name = _strdup(tempName);
    if (name == nullptr) {
      cerr << "Memory allocation error!" << endl;
      name = nullptr;
    }

    // Validate age input
    do {
      cout << "Enter age (18 to 60): ";
      cin >> age;
      if (cin.fail() || age < 18 || age > 60) {
        cout << "Invalid age. Please enter age from 18 to 60." << endl;
        cin.clear();
        //cin.ignore(1000, '\n');  // Clear input buffer
      }
    } while (age < 18 || age > 60);

    // Validate course
    do {
      cout << "Enter course (1 to 5): ";
      cin >> course;
      if (cin.fail() || course < 1 || course > 5) {
        cout << "Invalid course. Please enter course from 1 to 5." << endl;
        cin.clear();
        //cin.ignore(1000, '\n');  // Clear input buffer
      }
    } while (course < 1 || course > 5);

    // Validate gender input
    do {
      cout << "Enter gender (M/F): ";
      cin >> gender;
      gender = toupper(gender);  // Convert to uppercase for consistency
      if (gender != 'M' && gender != 'F') {
        cout << "Invalid gender. Please enter 'M' or 'F'." << endl;
        cin.clear();
        //cin.ignore(1000, '\n');  // Clear input buffer
      }
    } while (toupper(gender) != 'M' && toupper(gender) != 'F');

    // Validate average grade input
    do {
      cout << "Enter average grade (0.0 to 10.0): ";
      cin >> grade;
      if (cin.fail() || grade < 0.0 || grade > 10.0) {
        cout << "Invalid average grade. Please enter a grade from 0.0 to 10.0." << endl;
        cin.clear();
        //cin.ignore(1000, '\n');  // Clear input buffer
      }
    } while (grade < 0.0 || grade > 10.0);
  }

  // Method to load student data from a binary file
  bool Student::loadFromFile(ifstream& infile) { // Pass fstream object
    int nameLength = 0;
    infile.read(reinterpret_cast<char*>(&nameLength), sizeof(int));
    if (infile.fail()) return false;

    delete[] name;  // Delete any existing name

    name = new char[nameLength + 1];
    if (name == nullptr) {
      cerr << "Memory allocation error!" << endl;
      return false;
    }
    infile.read(name, nameLength);
    if (infile.fail()) {
      delete[] name;
      name = nullptr;
      return false;
    }

    name[nameLength] = '\0';
    infile.read(reinterpret_cast<char*>(&age), sizeof(int));
    if (infile.fail()) return false;
    infile.read(reinterpret_cast<char*>(&course), sizeof(int));
    if (infile.fail()) return false;
    infile.read(reinterpret_cast<char*>(&gender), sizeof(char));
    if (infile.fail()) return false;
    infile.read(reinterpret_cast<char*>(&grade), sizeof(float));
    if (infile.fail()) return false;

    return true;
  }

  // Method to save student data to a binary file
  void Student::saveToFile(ofstream& outfile) { // Pass fstream object
    int nameLength = (name != nullptr) ? strlen(name) : 0;
    if (name != nullptr) {
      outfile.write(name, nameLength);
    }
    else {
      return;
    }
    outfile.write(reinterpret_cast<char*>(&nameLength), sizeof(int));
    outfile.write(reinterpret_cast<char*>(&age), sizeof(int));
    outfile.write(reinterpret_cast<char*>(&course), sizeof(int));
    outfile.write(reinterpret_cast<char*>(&gender), sizeof(char));
    outfile.write(reinterpret_cast<char*>(&grade), sizeof(float));
  }

  // Method to display student data
  void Student::display() const {
    cout << "Name: " << (getName() ? getName() : "Unnamed") << ", Age: " << age << ", Course: " << course << ", Gender: "
      << gender << ", Average grade: " << grade << endl;
  }

  // Method to check if the student is failing
  bool Student::isFailing() const {
    return grade < 4.0;
  }

  // Getter for the course
  int Student::getCourse() const {
    return course;
  }

  // Getter for the grade
  float Student::getGrade() const {
    return grade;
  }

  // Getter for the name
  const char* Student::getName() const {
    return name;
  }