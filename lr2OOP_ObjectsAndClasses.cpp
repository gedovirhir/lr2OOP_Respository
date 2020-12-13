#include <iostream>
#include <cstdlib>
#include <conio.h>


using namespace std;

class Point {
    public:
        int x, y;

        Point() {
            x = 0;
            y = 0;
        }
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        Point(Point &p) {
            x = p.x;
            y = p.y;
        }
        Point(Point *p) {
            x = p->x;
            y = p->y;
        }
};

class Point3D : Point {
    public:
        int z;

        Point3D() {
            x = 0;
            y = 0;
            z = 0;
        }
        Point3D(int x, int y, int z) : Point(x,y) {
            this->z = z;
        }
        Point3D(Point &p, int z) : Point(p) {
            this->z = z;
        }
        Point3D(Point *p, int z) : Point(p) {
            this->z = z;
        }
        Point3D(Point &p) {
            x = p.x;
            y = p.y;
        }
        Point3D(Point *p) {
            x = p->x;
            y = p->y;
        }
};

class Figure {
    protected:
        int xcord;
        int ycord;
        
        Figure() {
            xcord = 0;
            ycord = 0;
        }

        Figure(int x, int y) {
            xcord = x;
            ycord = y;
        }
};