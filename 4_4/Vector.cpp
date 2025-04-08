#include "Vector.h";
  // ����������� ��� ����������
  Vector::Vector() {
    elements = new double[MAX_SIZE];
    size = 0;
  }

  // ����������� � �����������
  Vector::Vector(int n) : elements(new double[MAX_SIZE]), size(n) {
    if (n > MAX_SIZE) {
      n = MAX_SIZE; // ������������ ������ �� MAX_SIZE
    }
    fillRandom(); // ���������� ���������� ������� ��� �������������
  }

  // ����������� �����������
  Vector::Vector(const Vector& other) : elements(new double[MAX_SIZE]), size(other.size) {
    for (int i = 0; i < size; ++i) {
      elements[i] = other.elements[i];
    }
  }

  // ����������� �����������
  Vector::Vector(Vector&& other) : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
  }

  // ����������
  Vector::~Vector() {
    delete[] elements;
  }

  // ������� ����������� �������
  void Vector::setSize(int n) {
    if (n > MAX_SIZE) {
      n = MAX_SIZE; // ������������ ������ �� MAX_SIZE
    }
    size = n;
  }

  // ����������� ���������� ��������� � �������
  int Vector::getSize() {
    return size;
  }

  // ��������� �������� ������� �� �������
  double Vector::getElement(int index) {
    if (index >= size || index < 0) {
      throw out_of_range("Index outside vector boundaries");
    }
    return elements[index];
  }

  // ��������� �������� �������� ������� �� �������
  void Vector::setElement(int index, double value) {
    if (index >= size || index < 0) {
      throw out_of_range("Index outside vector boundaries");
    }
    elements[index] = value;
  }

  // �������� ���� ��������� ������� �� ������
  void Vector::addScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] += scalar;
    }
  }

  // ��������� ���� ��������� ������� �� ������
  void Vector::subtractScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] -= scalar;
    }
  }

  // ��������� ���� ��������� ������� �� ������
  void Vector::multiplyByScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] *= scalar;
    }
  }

  // ������� ���� ��������� ������� �� ������
  void Vector::divideByScalar(double scalar) {
    if (scalar == 0) {
      throw invalid_argument("Division by zero");
    }
    for (int i = 0; i < size; i++) {
      elements[i] /= scalar;
    }
  }

  // ����������� ����� �������
  double Vector::length() {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
      sum += elements[i] * elements[i];
    }
    return sqrt(sum);
  }

  // ������������ �������� � ������ ��������
  Vector Vector::add( Vector& other) {
    if (size != other.size) {
      throw invalid_argument("The sizes of the vectors do not match");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      result.setElement(i, this->getElement(i) + other.getElement(i));
    }
    return result;
  }

  // ������������ ��������� � ������ ��������
  Vector Vector::subtract( Vector& other) {
    if (size != other.size) {
      throw invalid_argument("The sizes of the vectors do not match");
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
      result.setElement(i, this->getElement(i) - other.getElement(i));
    }
    return result;
  }

  // ������������ ��������� � ������ ��������
  Vector Vector::multiply( Vector& other) {
    if (size != other.size) {
      throw invalid_argument("The sizes of the vectors do not match");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      result.setElement(i, this->getElement(i) * other.getElement(i));
    }
    return result;
  }

  // ������������ ������� � ������ ��������
  Vector Vector::divide( Vector& other) {
    if (size != other.size) {
      throw invalid_argument("The sizes of the vectors do not match");
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
      if (other.getElement(i) == 0) {
        throw invalid_argument("Division by zero");
      }
      result.setElement(i, this->getElement(i) / other.getElement(i));
    }
    return result;
  }

  // ����� �������� ��������� ������� �� �����
  void Vector::print() {
    for (int i = 0; i < size; ++i) {
      cout << elements[i] << " ";
    }
    cout << endl;
  }

  // ���� �������� ��������� ������� � ����������
  void Vector::input() {
    cout << "Enter " << size << " elements of vector: ";
    for (int i = 0; i < size; ++i) {
      cin >> elements[i];
    }
  }

  // ���������� ��������� ������� ���������� �������
  void Vector::fillRandom() {

    for (int i = 0; i < size; ++i) {
      elements[i] = static_cast<double>(rand()) / RAND_MAX * 100; // ��������� ����� �� 0 �� 100
    }
  }

  // ����� ��� ��������� ������������ �������� �������
  double Vector::minValue() {
    if (size == 0) return 0;

    double minVal = elements[0];
    for (int i = 1; i < size; i++) {
      if (elements[i] < minVal) {
        minVal = elements[i];
      }
    }
    return minVal;
  }