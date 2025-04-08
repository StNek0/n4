#include "Vector.h";

int main() {
  int N;

  cout << "Enter size of vectors: ";
  cin >> N;

  srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

  Vector X(N); // Создаем вектор X размером N
  Vector Y(N); // Создаем вектор Y размером N

  X.fillRandom(); // Заполняем X случайными числами
  Y.fillRandom(); // Заполняем Y случайными числами

  cout << "Vector X: ";
  X.print(); // Выводим X

  cout << "Vector Y: ";
  Y.print(); // Выводим Y

  double a = X.minValue(); // Находим минимальное значение в X
  double b = Y.minValue(); // Находим минимальное значение в Y

  cout << "a: " << a << endl << "b: " << b << endl;

  Vector Z(N); // Создаем вектор Z размером N

  Vector aX(N); // Вектор для a * X
  for (int i = 0; i < N; i++) {
    aX.setElement(i, X.getElement(i));
  }
  //aX = X;       // Копируем X в aX
  aX.multiplyByScalar(a); // Умножаем aX на a
  cout << "Vector a * X: ";
  aX.print();

  Vector bY(N); // Вектор для b * Y
  for (int i = 0; i < N; i++) {
    bY.setElement(i, Y.getElement(i));
  }
  //bY = Y;       // Копируем Y в bY
  bY.multiplyByScalar(b); // Умножаем bY на b
  cout << "Vector b * Y: ";
  bY.print();

  for (int i = 0; i < N; i++) {
    Z.setElement(i, aX.getElement(i) - bY.getElement(i));
  }
  //Z = aX.subtract(bY); // Вычисляем Z как разность aX и bY

  cout << "Vector Z: ";
  Z.print(); // Выводим Z

  return 0;
}