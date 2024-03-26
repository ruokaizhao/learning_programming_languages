#ifndef MATH_UTILS
#define MATH_UTILS

struct Rectangle
{
  double length;
  double width;
};

namespace utilz
{
double area(double, double);

double area(double);

double area(Rectangle);

double pow(double, int = 3);
} // namespace utilz

#endif
