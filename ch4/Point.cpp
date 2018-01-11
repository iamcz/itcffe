#ifndef Point_CPP
#define Point_CPP

#include "Point.hpp"

// Private functions
void Point::init(double dx, double dy) {
  x = dx;
  y = dy;
}

Point::Point() {
  init(0.0, 0.0);
}

Point::Point(double newx, double newy) {
  init(newx, newy);
}

Point::Point(const Point& pt) {
  x = pt.x;
  y = pt.y;
}

Point::~Point() {
}

double Point::X() const {
  return x;
}

double Point::Y() const {
  return y;
}

void Point::X(double NewX) {
  x = NewX;
}

void Point::Y(double NewY) {
  y = NewY;
}

Point Point::add(const Point& p) const {
  return Point(x + p.x, y + p.y);
}

Point Point::subtract(const Point& p) const {
  return Point(x - p.x, y - p.y);
}

Point Point::scale(const Point& p) const {
  return Point(x * p.x, y * p.y);
}

Point Point::MidPoint(const Point& p2) const {
  Point result((x + p2.x) * 0.5, (y + p2.y) * 0.5);
  return result;
}

Point& Point::copy(const Point& p) {
  x = p.x;
  y = p.y;
  return *this;
}

ostream& operator<<(ostream& os, const Point& p) {
  os << "Point { x: " << p.X() << ", y:" << p.Y() << " }";
  return os;
}

#endif
