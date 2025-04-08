#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Vector {
  const int MAX_SIZE = 100; // ����������� ��������� ������ �������
  double* elements; // ��������� �� ������ ���������
  int size;      // ���������� ��������� � �������

public:
  // ����������� ��� ����������
  Vector();

  // ����������� � �����������
  Vector(int n);

  // ����������� �����������
  Vector(const Vector& other);

  // ����������� �����������
  Vector(Vector&& other);

  // ����������
  ~Vector();

  // ������� ����������� �������
  void setSize(int n);

  // ����������� ���������� ��������� � �������
  int getSize();

  // ��������� �������� ������� �� �������
  double getElement(int index);

  // ��������� �������� �������� ������� �� �������
  void setElement(int index, double value);

  // �������� ���� ��������� ������� �� ������
  void addScalar(double scalar);

  // ��������� ���� ��������� ������� �� ������
  void subtractScalar(double scalar);

  // ��������� ���� ��������� ������� �� ������
  void multiplyByScalar(double scalar);

  // ������� ���� ��������� ������� �� ������
  void divideByScalar(double scalar);

  // ����������� ����� �������
  double length();

  // ������������ �������� � ������ ��������
  Vector add( Vector& other);

  // ������������ ��������� � ������ ��������
  Vector subtract( Vector& other);

  // ������������ ��������� � ������ ��������
  Vector multiply( Vector& other);

  // ������������ ������� � ������ ��������
  Vector divide( Vector& other);

  // ����� �������� ��������� ������� �� �����
  void print();

  // ���� �������� ��������� ������� � ����������
  void input();

  // ���������� ��������� ������� ���������� �������
  void fillRandom();

  // ����� ��� ��������� ������������ �������� �������
  double minValue();
};