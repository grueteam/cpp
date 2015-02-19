#include <iostream>

using namespace std;

// Базовый класс: Фигура
class Shape {
  // Имя фигуры (строка)
  char* name; // Обязательно private
 protected:
  // Конструктор для вызова из наследников
  Shape(char* name = NULL) : name(name) {
  }
  // Каждая фигура показывает своё имя
 public:
  virtual void show() = 0;

 protected:
  void showName() {
    if(name != NULL)
      cout << name << " ";
  }
};

// Наследники Shape:
class Point : public Shape {
  double x, y;
 public:
  // Конструктор
  Point(char* name, double x, double y) :
    Shape(name), x(x), y(y) {
  }
  void show() {
    cout << "Point ";
    Shape::showName();
    cout << "  x = " << x << " y = " << y << endl;
  }
};

class Line : public Shape {
  // Внутри 2 точки
  Point a, b;
 public:
  // Конструктор
  Line(char* name, Point a, Point b) :
    Shape(name), a(a), b(b) {
  }
  void show() {
    cout << "Line ";
    Shape::showName();
    a.show();
    cout << " - ";
    b.show();
  }
};

class Circle : public Shape {
  // Одна точка и радиус
  Point center;
  double radius;
  // Конструктор
 public:
  Circle(char* name, Point center, double radius) :
    Shape(name), center(center), radius(radius) {
  }
  void show() {
    cout << "Circle ";
    Shape::showName();
    center.show();
    cout << "  radius = " << radius << endl;
  }
};

// Везде метод show() -> показывает свойства фигуры

int main() {
  Shape* shapes[5] = {
    new Point("A", 1.2, 2.1),
    new Point("B", 5, 6),
    new Line("AB", Point("A", 1.2, 2.1),
    Point("B", 5, 6)),
    new Circle("CircleA", Point("A", 1.2, 2.1), 5.0),
    new Circle("CircleB", Point("B", 5, 6), 7.2)
  };

  for(int i = 0; i < 5; ++i)
    shapes[i]->show();

  return 0;
}
