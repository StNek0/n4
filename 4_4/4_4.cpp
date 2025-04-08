#include "Vector.h";

int main() {
  int N;

  cout << "Enter size of vectors: ";
  cin >> N;

  srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����

  Vector X(N); // ������� ������ X �������� N
  Vector Y(N); // ������� ������ Y �������� N

  X.fillRandom(); // ��������� X ���������� �������
  Y.fillRandom(); // ��������� Y ���������� �������

  cout << "Vector X: ";
  X.print(); // ������� X

  cout << "Vector Y: ";
  Y.print(); // ������� Y

  double a = X.minValue(); // ������� ����������� �������� � X
  double b = Y.minValue(); // ������� ����������� �������� � Y

  cout << "a: " << a << endl << "b: " << b << endl;

  Vector Z(N); // ������� ������ Z �������� N

  Vector aX(N); // ������ ��� a * X
  for (int i = 0; i < N; i++) {
    aX.setElement(i, X.getElement(i));
  }
  //aX = X;       // �������� X � aX
  aX.multiplyByScalar(a); // �������� aX �� a
  cout << "Vector a * X: ";
  aX.print();

  Vector bY(N); // ������ ��� b * Y
  for (int i = 0; i < N; i++) {
    bY.setElement(i, Y.getElement(i));
  }
  //bY = Y;       // �������� Y � bY
  bY.multiplyByScalar(b); // �������� bY �� b
  cout << "Vector b * Y: ";
  bY.print();

  for (int i = 0; i < N; i++) {
    Z.setElement(i, aX.getElement(i) - bY.getElement(i));
  }
  //Z = aX.subtract(bY); // ��������� Z ��� �������� aX � bY

  cout << "Vector Z: ";
  Z.print(); // ������� Z

  return 0;
}