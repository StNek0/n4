#include "MyString.h";

// Constructor initializing with a C-style string
MyString::MyString(const char* s) {
  length = strlen(s);
  str = new char[length + 1];
  strcpy(str, s);
}

// Constructor initializing with repeated characters
MyString::MyString(unsigned int n, const char* c) {
  length = n;
  str = new char[length + 1];
  for (int i = 0; i < length; ++i) {
    str[i] = c[0];
  }
  str[length] = '\0';
}

// Constructor initializing with a part of a C-style string (first or last n chars)
MyString::MyString(const char* s, unsigned int n, bool first) {
  unsigned int sourceLength = strlen(s);
  if (n > sourceLength) {
    n = sourceLength;
  }

  length = n;
  str = new char[length + 1];

  if (first) {
    strncpy(str, s, length);
  }
  else {
    strncpy(str, s + sourceLength - length, length);
  }
  str[length] = '\0';
}

// Copy constructor
MyString::MyString(const MyString& word) {
  length = word.length;
  str = new char[length + 1];
  strcpy(str, word.str);
}

// Move constructor
MyString::MyString(MyString&& word) {
  length = word.length;
  str = word.str;
  word.str = nullptr;
  word.length = 0;
}

// Destructor
MyString::~MyString() {
  delete[] str;
}

// Method to input the string from the keyboard
void MyString::input() {
  // Using a fixed-size buffer for input
  char buffer[256];
  cout << "Enter a string: ";
  cin.getline(buffer, sizeof(buffer)); // Use cin.getline to handle spaces
  length = strlen(buffer);
  delete[] str;  // Free previous memory if any
  str = new char[length + 1];
  strcpy(str, buffer);
}

// Method to print the string
void MyString::print() {
  cout << "String: " << str << endl;
}

// Method to replace lowercase letters with their alphabet number
MyString MyString::replaceLowercaseWithAlphabetNumber() {
  char* newStr = new char[length * 2 + 1]; // Worst case: every char is lowercase, needs 2 digits + space
  unsigned int newStrIndex = 0;

  for (int i = 0; i < length; ++i) {
    if (islower(str[i])) {
      int num = str[i] - 'a' + 1;
      // Convert the number to a string and append it
      if (num < 10) {
        newStr[newStrIndex++] = num + '0';  // Convert single digit to char
      }
      else {
        newStr[newStrIndex++] = (num / 10) + '0';
        newStr[newStrIndex++] = (num % 10) + '0';
      }
    }
    else {
      newStr[newStrIndex++] = str[i];
    }
  }
  newStr[newStrIndex] = '\0';

  MyString result(newStr);
  delete[] newStr; // Free the temporary newStr
  return result;
}

// Method to get the string as a C-style string
const char* MyString::getString() {
  return str;
}