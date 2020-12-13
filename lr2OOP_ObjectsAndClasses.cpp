#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Point3D {
    public:
        int xcord, ycord, zcord;
};

class Figure {
    protected:
        int x, y;

        Figure() {
            x = 0;
            y = 0;
        }
        Figure(int x, int y) {
            this->x = x;
            this->y = y;
        }
        Figure(Figure &p) {
            x = p.x;
            y = p.y;
        }
        Figure(Figure *p) {
            x = p->x;
            y = p->y;
        }

        virtual ~Figure() {
            printf("Figure::~Figure()\n");
        }
    public:
        void set(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void getCords() {
            cout << "X: " << x << " Y: " << y;
        }
};

class Figure3D : protected Figure {
    protected:
        int z;

        Figure3D() {
            x = 0;
            y = 0;
            z = 0;
        }
        Figure3D(int x, int y, int z) : Figure(x,y) {
            this->z = z;
        }
        Figure3D(Figure &p, int z) : Figure(p) {
            this->z = z;
        }
        Figure3D(Figure *p, int z) : Figure(p) {
            this->z = z;
        }
        Figure3D(Figure3D &p) {
            x = p.x;
            y = p.y;
        }
        Figure3D(Figure3D *p) {
            x = p->x;
            y = p->y;
        }

        ~Figure3D() {
            printf("Figure3D::~Figure3D()\n");
        }
};

class Ellipse : public Figure {
    private:
        int osx;
        int osy;
    public:
        Ellipse() {
            osx = 1;
            osy = 1;
        }
        Ellipse(int x, int y, int osx, int osy) : Figure(x,y) {
            this->osx = osx;
            this->osy = osy;
        }
        Ellipse(Ellipse &e) {
            osx = e.osx;
            osy = e.osy;
        }
        Ellipse(Ellipse *e) {
            osx = e->osx;
            osy = e->osx;
        }
};



int main() {
    setlocale(LC_ALL, "rus");

}