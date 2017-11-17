#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {
public:
    unsigned int x;
    unsigned int y;

    Point(int x, int y):x(x), y(y){}
    Point(){}

    bool operator==(const Point &o) {return x == o.x && y == o.y;}
};

#endif // POINT_H_INCLUDED
