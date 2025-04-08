#include "Vector.h";
  // Конструктор без параметров
  Vector::Vector() {
    elements = new double[MAX_SIZE];
    size = 0;
  }

  // Конструктор с параметрами
  Vector::Vector(int n) : elements(new double[MAX_SIZE]), size(n) {
    if (n > MAX_SIZE) {
      n = MAX_SIZE; // Ограничиваем размер до MAX_SIZE
    }
    fillRandom(); // Заполнение случайными числами при инициализации
  }

  // Конструктор копирования
  Vector::Vector(const Vector& other) : elements(new double[MAX_SIZE]), size(other.size) {
    for (int i = 0; i < size; ++i) {
      elements[i] = other.elements[i];
    }
  }

  // Конструктор перемещения
  Vector::Vector(Vector&& other) : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
  }

  // Деструктор
  Vector::~Vector() {
    delete[] elements;
  }

  // Задание размерности вектора
  void Vector::setSize(int n) {
    if (n > MAX_SIZE) {
      n = MAX_SIZE; // Ограничиваем размер до MAX_SIZE
    }
    size = n;
  }

  // Определение количества элементов в векторе
  int Vector::getSize() {
    return size;
  }

  // Получение элемента вектора по индексу
  double Vector::getElement(int index) {
    if (index >= size || index < 0) {
      throw out_of_range("Index outside vector boundaries");
    }
    return elements[index];
  }

  // Занесение значения элемента вектора по индексу
  void Vector::setElement(int index, double value) {
    if (index >= size || index < 0) {
      throw out_of_range("Index outside vector boundaries");
    }
    elements[index] = value;
  }

  // Сложение всех элементов вектора на скаляр
  void Vector::addScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] += scalar;
    }
  }

  // Вычитание всех элементов вектора на скаляр
  void Vector::subtractScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] -= scalar;
    }
  }

  // Умножение всех элементов вектора на скаляр
  void Vector::multiplyByScalar(double scalar) {
    for (int i = 0; i < size; i++) {
      elements[i] *= scalar;
    }
  }

  // Деление всех элементов вектора на скаляр
  void Vector::divideByScalar(double scalar) {
    if (scalar == 0) {
      throw invalid_argument("Division by zero");
    }
    for (int i = 0; i < size; i++) {
      elements[i] /= scalar;
    }
  }

  // Определение длины вектора
  double Vector::length() {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
      sum += elements[i] * elements[i];
    }
    return sqrt(sum);
  }

  // Поэлементное сложение с другим вектором
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

  // Поэлементное вычитание с другим вектором
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

  // Поэлементное умножение с другим вектором
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

  // Поэлементное деление с другим вектором
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

  // Вывод значений элементов вектора на экран
  void Vector::print() {
    for (int i = 0; i < size; ++i) {
      cout << elements[i] << " ";
    }
    cout << endl;
  }

  // Ввод значений элементов вектора с клавиатуры
  void Vector::input() {
    cout << "Enter " << size << " elements of vector: ";
    for (int i = 0; i < size; ++i) {
      cin >> elements[i];
    }
  }

  // Заполнение элементов вектора случайными числами
  void Vector::fillRandom() {

    for (int i = 0; i < size; ++i) {
      elements[i] = static_cast<double>(rand()) / RAND_MAX * 100; // Случайное число от 0 до 100
    }
  }

  // Метод для получения минимального значения вектора
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