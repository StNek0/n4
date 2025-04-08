#include "MyString.h";

int main() {
  // Creating objects of different types
  MyString str1;  // Default constructor
  cout << "Object str1 (default constructor):" << endl;
  str1.input();
  str1.print();
  cout << endl;

  //MyString str2("Hello, world!");  // Constructor initializing with a string
  cout << "Object str2 (constructor initializing with a string):" << endl;
  str1.input();
  MyString str2(str1);  // Constructor initializing with a string
  str2.print();
  cout << endl;

  unsigned int r = 5;
  cout << "Object str3 (constructor initializing with " << r << " repeated characters):" << endl;
  str1.input();
  MyString str3(r, str1.getString());  // Constructor initializing with repeated characters
  str3.print();
  cout << endl;

  cout << "Object str4 (constructor initializing with part of string - first 4 chars):" << endl;
  str1.input();
  MyString str4(str1.getString(), 4, true);  // Constructor initializing with part of string (first n chars)
  str4.print();
  cout << endl;

  cout << "Object str5 (constructor initializing with part of string - last 4 chars):" << endl;
  str1.input();
  MyString str5(str1.getString(), 4, false);  // Constructor initializing with part of string (last n chars)
  str5.print();
  cout << endl;

  MyString str6(str2);  // Copy constructor
  cout << "Object str6 (copy constructor from str2):" << endl;
  str6.print();
  cout << endl;

  MyString str7 = move(str3);  // Move constructor
  cout << "Object str7 (move constructor from str3):" << endl;
  str7.print();
  //cout << "Object str3 after moving (should be empty):" << endl;
  //str3.print();
  cout << endl;


  // Example of using replaceLowercaseWithAlphabetNumber method
  cout << "Example of using replaceLowercaseWithAlphabetNumber" << endl;
  cout << "----------------------------------------------------" << endl;
  char inputString[256];
  cout << "Enter a string to replace lowercase letters with numbers: ";
  cin.getline(inputString, sizeof(inputString));
  MyString originalString(inputString);
  MyString convertedString = originalString.replaceLowercaseWithAlphabetNumber();
  cout << "Original string: " << originalString.getString() << endl;
  cout << "Converted string: " << convertedString.getString() << endl;

  return 0;
}