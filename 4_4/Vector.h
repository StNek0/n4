#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Vector {
  const int MAX_SIZE = 100; // Максимально возможный размер массива
  double* elements; // Указатель на массив элементов
  int size;      // Количество элементов в векторе

public:
  // Конструктор без параметров
  Vector();

  // Конструктор с параметрами
  Vector(int n);

  // Конструктор копирования
  Vector(const Vector& other);

  // Конструктор перемещения
  Vector(Vector&& other);

  // Деструктор
  ~Vector();

  // Задание размерности вектора
  void setSize(int n);

  // Определение количества элементов в векторе
  int getSize();

  // Получение элемента вектора по индексу
  double getElement(int index);

  // Занесение значения элемента вектора по индексу
  void setElement(int index, double value);

  // Сложение всех элементов вектора на скаляр
  void addScalar(double scalar);

  // Вычитание всех элементов вектора на скаляр
  void subtractScalar(double scalar);

  // Умножение всех элементов вектора на скаляр
  void multiplyByScalar(double scalar);

  // Деление всех элементов вектора на скаляр
  void divideByScalar(double scalar);

  // Определение длины вектора
  double length();

  // Поэлементное сложение с другим вектором
  Vector add( Vector& other);

  // Поэлементное вычитание с другим вектором
  Vector subtract( Vector& other);

  // Поэлементное умножение с другим вектором
  Vector multiply( Vector& other);

  // Поэлементное деление с другим вектором
  Vector divide( Vector& other);

  // Вывод значений элементов вектора на экран
  void print();

  // Ввод значений элементов вектора с клавиатуры
  void input();

  // Заполнение элементов вектора случайными числами
  void fillRandom();

  // Метод для получения минимального значения вектора
  double minValue();
};