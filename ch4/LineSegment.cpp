#ifndef LineSegment_CPP
#define LineSegment_CPP

#include <math.h>
#include "Point.hpp"
#include "LineSegment.hpp"
using namespace std;

LineSegment::LineSegment() {
  e1 = Point(0, 0);
  e1 = Point(1, 1);
}

LineSegment::LineSegment(const Point& p1, const Point& p2) {
  e1 = p1;
  e2 = p2;
}

LineSegment::LineSegment(const LineSegment& l) {
  e1 = l.e1;
  e2 = l.e2;
}

LineSegment::~LineSegment() {
}

Point LineSegment::start() const {
  return e1;
}

Point LineSegment::end() const {
  return e2;
}

void LineSegment::start(const Point& pt) {
  e1 = pt;
}

void LineSegment::end(const Point& pt) {
  e2 = pt;
}

double LineSegment::length() const {
  double dX = e1.X() - e2.X();
  double dY = e1.Y() - e2.Y();
  return sqrt(dX * dX + dY * dY);
}

Point LineSegment::midPoint() const {
  return e1.MidPoint(e2);
}

ostream& operator<<(ostream& os, const LineSegment& l) {
  os << "LineSegment { start: " << l.start() << ", end: " << l.end() << " }";
  return os;
}

#endif
