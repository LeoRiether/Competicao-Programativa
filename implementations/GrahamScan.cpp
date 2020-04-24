#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// TODO: implement the faster Andrew's Monotone Chain algorithm

constexpr int oo = 0x3f3f3f3f;

enum class Orientation {
  Colinear, Clock, Counter
};

class Point {
private:
  static inline Orientation getOrientation(int k) {
    if (k == 0) return Orientation::Colinear;
    return k > 0 ? Orientation::Clock : Orientation::Counter;
  }

public:
  int x, y;

  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}

  inline int distSq(const Point& orig) const {
    int dx = x-orig.x, dy = y-orig.y;
    return dx*dx + dy*dy;
  }

  // Returns the orientation of the ordered triplet (q,p,r)
  // Probably wrong? I don't even know anymore
  static inline Orientation Orientation(const Point& q, const Point& p, const Point& r) {
    Point a = q-p, b = r-q;
    return getOrientation(a.cross(b));
  }

  inline Point operator-(const Point& b) const { 
    return { x-b.x, y-b.y };
  }
  inline int cross(const Point& b) const {
    return y*b.x - x*b.y;
  }

};

using pointList_t  = std::vector<Point>;
using pointStack_t = std::stack<Point>;

// Print point with std::cout
std::ostream& operator<<(std::ostream& os, const Point& p) {
  return os << '{' << p.x << ", " << p.y << '}';
}

// Print point list with std::cout
std::ostream& operator<<(std::ostream& os, const pointList_t& pl) {
  os << '[';
  int i = 0;
  for (const auto p : pl) {
    os << (i++ ? " " : "") << p;
  }
  return os << ']';
}


// Acts as a comparison function for sort()
struct AngleCompare {
  Point low;
  AngleCompare(const Point& low) : low(low) { }

  bool operator()(const Point& a, const Point& b) {
    Orientation o = Point::Orientation(low, a, b);
    if (o == Orientation::Colinear)
      return a.distSq(low) < b.distSq(low);
    return o == Orientation::Clock;
  }
};


// points must be already sorted by angle
// Returns a point stack with all the convex hull points
pointStack_t convexHull(const pointList_t& points) {
  int n = int(points.size());
  pointStack_t stack;

  stack.push(points[0]);
  stack.push(points[1]);

  Point stackTop;
  for (int i = 2; i < n; i++) {
    // Ah não, um do-while!
    do {
      stackTop = std::move(stack.top()); 
      stack.pop();
    } while (Point::Orientation(stack.top(), stackTop, points[i]) == Orientation::Counter);
    stack.push(std::move(stackTop));
    stack.push(points[i]);
  }

  return stack;
}

int main() {
  // Reads a list of n points
  // and finds the point with the lowest y
  int n; std::cin >> n;
  pointList_t points(n);
  Point low(oo, oo);
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    points[i] = { x, y };

    // Update lowest y point
    if (y < low.y || (y == low.y && x < low.x)) 
      low = points[i];
  }

  // Sort points by angle
  sort(points.begin(), points.end(), AngleCompare(low));

  // Print all points in (hopefully) sorted order
  std::cout << points << std::endl;
  std::cout << ">-----------------------------------------------------------------<" << std::endl;

  // Calculate convex hull
  // Hopefully g++ will do a return-value-optimization!
  pointStack_t chull = convexHull(points);

  // Print all convex hull points 
  std::cout << '[';
  int iii = 0;
  while (!chull.empty()) {
    std::cout << (iii++ ? " " : "") << chull.top();
    chull.pop();
  }
  std::cout << ']' << std::endl;

  return 0;
}

