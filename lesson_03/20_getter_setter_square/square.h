#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <cmath>

// Инкапсуляция
class Square {
  //private: // Инкапсуляция
  //double side;
  double area;
 public:
  // Получить сторону квадрата
  double getSide() {
    return sqrt(area);
    //return side;
  }
  // Задать сторону квадрата
  void setSide(double value) {
    area = value * value;
    //side = value;
  }
  // Получить площадь
  double getArea() {
    return area;
    //return side*side;
  }
  // Задать площадь
  void setArea(double value);
};

#endif // SQUARE_H_INCLUDED
