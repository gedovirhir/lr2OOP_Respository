#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Point3D {
    public:
        int xcord, ycord, zcord;
        
        Point3D() {
            xcord = 0;
            ycord = 0;
            zcord = 0;

            cout << "Point3D::Point3D()\n";
        }
        Point3D(int a,int b,int c) {
            xcord = a;
            ycord = b;
            zcord = c;

            cout << "Point3D::Point3D(int a,int b,int c)\n";
        }
        Point3D(Point3D &p) {
            xcord = p.xcord;
            ycord = p.ycord;
            zcord = p.zcord;

            cout << "Point3D::Point3D(Point3D &p)\n";
        }
        Point3D(Point3D *p) {
            xcord = p->xcord;
            ycord = p->ycord;
            zcord = p->zcord;

            cout << "Point3D::Point3D(Point3D *p)\n";
        }

        ~Point3D() {
            cout << "Point3D::~Point3D\n";
        }
};

class Figure {
    protected:
        int x, y;

        Figure() {
            x = 0;
            y = 0;

            cout << "Figure::Figure()\n";
        }
        Figure(int x, int y) {
            this->x = x;
            this->y = y;

            cout << "Figure::Figure(int x, int y)\n";
        }
        Figure(Figure &p) {
            x = p.x;
            y = p.y;

            cout << "Figure::Figure(Figure &p)\n";
        }
        Figure(Figure *p) {
            x = p->x;
            y = p->y;

            cout << "Figure::Figure(Figure *p)\n";
        }

        virtual ~Figure() {
            printf("Figure::~Figure()\n");
        }
    public:
        void set(int x, int y) {
            this->x = x;
            this->y = y;
        }
        virtual void getInfo() {
            cout << "X: " << x << " Y: " << y << endl;
        }
};

class Figure3D : protected Figure {
    protected:
        int z;

        Figure3D() {
            x = 0;
            y = 0;
            z = 0;

            cout << "Figure3D::Figure3D()\n";
        }
        Figure3D(int x, int y, int z) : Figure(x,y) {
            this->z = z;

            cout << "Figure3D::Figure3D(int x, int y, int z)\n";
        }
        Figure3D(Figure &p, int z) : Figure(p) {
            this->z = z;

            cout << "Figure3D::Figure3D(Figure &p, int z)\n";
        }
        Figure3D(Figure *p, int z) : Figure(p) {
            this->z = z;

            cout << "Figure3D::Figure3D(Figure *p, int z)\n";
        }
        Figure3D(Figure3D &p) {
            x = p.x;
            y = p.y;

            cout << "Figure3D::Figure3D(Figure3D &p)\n";
        }
        Figure3D(Figure3D *p) {
            x = p->x;
            y = p->y;

            cout << "Figure3D::Figure3D(Figure3D *p)\n";
        }

        ~Figure3D() {
            printf("Figure3D::~Figure3D()\n");
        }
};

class ellipse : public Figure {
    private:
        int osx;
        int osy;

        float S;
    public:
        ellipse() {
            osx = 1;
            osy = 1;

            cout << "ellipse::ellipse()\n";
        }
        ellipse(int x, int y, int osx, int osy) : Figure(x,y) {
            this->osx = osx;
            this->osy = osy;

            cout << "ellipse::ellipse(int x, int y, int osx, int osy)\n";
        }
        ellipse(Point3D &p, int osx, int osy) : Figure(p.xcord,p.ycord) {
            this->osx = osx;
            this->osy = osy;

            cout << "ellipse::ellipse(Point3D &p, int osx, int osy)\n";
        }
        ellipse(ellipse &e) {
            osx = e.osx;
            osy = e.osy;

            cout << "ellipse::ellipse(ellipse &e)\n";
        }
        ellipse(ellipse *e) {
            osx = e->osx;
            osy = e->osx;

            cout << "ellipse::ellipse(ellipse *e)\n";
        }

        void getInfo() {
            cout << "X: " << x << " Y: " << y << endl;
            cout << "osX: " << osx << " osY: " << osy << endl;
            S = 3.14 * 0.5 * osx * osy;
            cout << "Площадь: " << S << endl;
        }

        ~ellipse() {
            cout << "ellipse::~ellipse() \n";
        }
};

class parallelepiped : Figure3D {
    private:
        int a, b, c;
        float V;
    public:
        parallelepiped() {
            a = 1;
            b = 1;
            c = 1;

            cout << "parallelepiped::parallelepiped()\n";
        }
        parallelepiped(int x, int y, int z, int t, int i, int u) : Figure3D(x,y,z) {
            a = t;
            b = i;
            c = u;

            cout << "parallelepiped::parallelepiped(int x, int y, int z, int t, int i, int u)\n";
        }
        parallelepiped(Point3D &p, int t, int i, int u) : Figure3D(p.xcord,p.ycord,p.zcord) {
            a = t;
            b = i;  
            c = u;

            cout << "parallelepiped::parallelepiped(Point3D &p, int t, int i, int u)\n";
        }

        void getInfo() {
            cout << "X: " << x << " Y: " << y << " z: " << z <<  endl;
            cout << "a: " << a << " b: " << c << " c: " << c << endl;
            V = a * b * c;
            cout << "Объем: " << V << endl;
        }

        ~parallelepiped() {
            cout << "parallelepiped::~parallelepiped() \n";
        }


};



int main() {
    setlocale(LC_ALL, "rus");

    ellipse fw;
    //123123123
}