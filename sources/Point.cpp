#include "Point.hpp"

using namespace ariel;

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() {
    return this->x;
}

void Point::setX(double x) {
    this->x = x;
}

double Point::getY() {
    return this->y;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::distance(Point other) {
    double deltaX = other.getX() - this->x;
    double deltaY = other.getY() - this->y;

    return sqrt(pow(deltaY, 2) + pow(deltaX, 2));
}

void Point::print() {
    cout << "(" << this->x << ", " << this->y << ")";
}

Point Point::moveTowards(Point source, Point destination, double distance) {
    if (distance < 0) {
        throw invalid_argument("The given distance is NEGATIVE.");
    }
    
    double srcToDest = source.distance(destination);

    if (srcToDest < distance) {
        return destination;
    }

    // Calculating the unit vector - from source to destination.
    double deltaX = destination.getX() - source.getX();
    double deltaY = destination.getY() - source.getY();
    // Building the unit vector span.
    double unitVectorX = deltaX / srcToDest;
    double unitVectorY = deltaY / srcToDest;
    Point unitVector(unitVectorX * distance, unitVectorY * distance);

    return Point(source.getX() + unitVector.getX(), source.getY() + unitVector.getY());
}

string Point::toString() {
    return "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
}


