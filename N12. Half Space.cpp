# include <math.h>
# include <cmath>

class Point {
 public:
  Point() : _x(std::nan("1")), _y(std::nan("1")) {}

  Point(const double x, const double y) : _x(x), _y(y) { _initialize(); }

  // Rotate a vector counterclockwise.
  Point rotate_ccw(const double degree) {
    double radian = degree * M_PI / 180.0;

    Point rotated = Point(std::cos(radian) * _x - std::sin(radian) * _y, std::sin(radian) * _x + std::cos(radian) * _y);

    return rotated;
  }

  // Dot product between vectors
  double operator*(const Point& other) const { return _x * other.x() + _y * other.y(); }

  Point operator*(const double magnitude) const { return Point(_x * magnitude, _y * magnitude); }

  Point operator/(const double magnitude) const { return Point(_x / magnitude, _y / magnitude); }

  Point operator+(const Point& other) const { return Point(_x + other.x(), _y + other.y()); }

  Point operator-(const Point& other) const { return Point(_x - other.x(), _y - other.y()); }

  operator bool() const { return !std::isnan(_x) && !std::isnan(_y); }

  double x() const { return _x; }
  double y() const { return _y; }
  double length() const { return _length; }
  double angle() const { return _angle; }

 private:
  double _x;
  double _y;
  double _length;
  double _angle;

  void _initialize() {
    _length = std::sqrt(pow(_x, 2) + pow(_y, 2));
    _angle = std::atan2(_y, _x) * 180.0 / M_PI;
  };
};
typedef Point Vector;
typedef Point UnitVector;

class HalfSapce {
  HalfSapce();

  HalfSapce(const Point& origin, const Vector& normal) : _origin(origin), _normal(normal) {}

  bool contains(const Point& point) const {
    Vector arrow = point - _origin;
    double dot_product = arrow * _normal;
    if (dot_product > 1e-8) {
      return true;
    } else {
      return false;
    }
  }

  Point origin() const { return _origin; }
  Vector normal() const { return _normal; }

 private:
  Point _origin;
  Vector _normal;
};
