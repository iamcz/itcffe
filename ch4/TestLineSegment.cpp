#include "Point.hpp"
#include "LineSegment.hpp"
#include <iostream>
using namespace std;

int main() {
  LineSegment l1;
  cout << l1 << endl;
  cout << "Length: " << l1.length() << endl;
  cout << "MidPoint: " << l1.midPoint() << endl;
  Point p1(2, 3);
  Point p2(4, 5);
  LineSegment l2(p1, p2);
  LineSegment l3(l2);
  cout << l3 << endl;
  cout << "Length: " << l3.length() << endl;
  cout << "MidPoint: " << l3.midPoint() << endl;
  return 0;
}
