#ifndef MOTION2D
#define MOTION2D
#include <iostream>

// Predefined constant for pi, to be used if/when converting degrees
// to radians.
#define PI 3.14159265

// Forward declation of Force. Needed in case any of Point references
// the existence of type Force.
class Force;

class Point {
    // Private fields and helpers here.
    float x;
    float y;
  public:
    // Required public interface here.
    Point();
    Point operator+(Force &f);
    // Point operator+(Force &f, Point &p);
    int quadrant();
    friend std::istream& operator>>(std::istream &in, Point &p);
    friend std::ostream& operator<<(std::ostream &out, const Point &p);
};

class Force {
    // Private fields and helpers here.
    float angle;
    float magnitude;
  public:
    // Required public interface here.
    Force();
    Force operator*(float scalar);
    float getMagnitude();
    float getDegrees();
    // Force operator*(float scalar, Force &f);
    friend std::istream& operator>>(std::istream &in, Force &f);
    friend std::ostream& operator<<(std::ostream &out, const Force &f);
};

#endif
