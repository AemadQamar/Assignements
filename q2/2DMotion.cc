#include "2DMotion.h"
#include <iomanip>
#include <cmath>

using namespace std;

Point::Point() : x{0}, y{0} {}

Point Point::operator+(Force &f) {
    Point newPoint;
    newPoint.x = x + (f.getMagnitude())*cos((f.getDegrees())*(PI/180));
    newPoint.y = y + (f.getMagnitude())*sin((f.getDegrees())*(PI/180));
    return newPoint;
}

// Point Point::operator+(Force &f, Point &p) {
//     return (p + f);
// }

int Point::quadrant(){
    if (x >= 0) {
        if (y >= 0){
            return 1;
        } else {
            return 4;
        }
    } else {
        if (y >= 0){
            return 2;
        } else {
            return 3;
        }
    }
}

istream &operator>>(istream &in, Point &p){
    return in >> p.x >> p.y;
}

ostream &operator<<(ostream &out, const Point &p){
    return out << "(" << fixed << setprecision(2) << p.x << "," << fixed << setprecision(2) << p.y << ")";
}

Force::Force() : angle{0}, magnitude{0} {}

float Force::getMagnitude(){
    return (magnitude);
}

float Force::getDegrees(){
    return (angle);
}

Force Force::operator*(float scalar) {
    Force newForce;
    newForce.magnitude = magnitude * scalar;
    newForce.angle = angle;
    return newForce;
}

// Force Force::operator*(float scalar, Force &f) {
//     return (force * scalar);
// }

istream &operator>>(istream &in, Force &f){
    return in >> f.angle >> f.magnitude;
}

ostream &operator<<(ostream &out, const Force &f){
    return out << f.angle << " degrees with magnitude of " << f.magnitude;
}