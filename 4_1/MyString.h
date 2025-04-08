#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

class MyString {
  char* str;
  unsigned int length;

public:
  // Default constructor
  MyString() {}

  // Constructor initializing with a C-style string
  MyString(const char* s);

  // Constructor initializing with repeated characters
  MyString(unsigned int n, const char* c);

  // Constructor initializing with a part of a C-style string (first or last n chars)
  MyString(const char* s, unsigned int n, bool first);

  // Copy constructor
  MyString(const MyString& word);

  // Move constructor
  MyString(MyString&& word);

  // Destructor
  ~MyString();

  // Method to input the string from the keyboard
  void input();

  // Method to print the string
  void print();

  // Method to replace lowercase letters with their alphabet number
  MyString replaceLowercaseWithAlphabetNumber();

  // Method to get the string as a C-style string
  const char* getString();
};