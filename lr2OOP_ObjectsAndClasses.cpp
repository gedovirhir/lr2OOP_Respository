#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>
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
    Point3D(int a, int b) {
        xcord = a;
        ycord = b;
        zcord = 0;

        cout << "Point3D::Point3D(int a,int b)\n";
    }
    Point3D(int a, int b, int c) {
        xcord = a;
        ycord = b;
        zcord = c;

        cout << "Point3D::Point3D(int a,int b,int c)\n";
    }
    Point3D(Point3D& p) {
        xcord = p.xcord;
        ycord = p.ycord;
        zcord = p.zcord;

        cout << "Point3D::Point3D(Point3D &p)\n";
    }
    Point3D(Point3D* p) {
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
    Point3D *point = new Point3D;

    Figure() {
        x = 0;
        y = 0;

        point->xcord = x;
        point->ycord = y;

        cout << "Figure::Figure()\n";
    }
    Figure(int x, int y) {
        this->x = x;
        this->y = y;

        point->xcord = x;
        point->ycord = y;

        cout << "Figure::Figure(int x, int y)\n";
    }
    Figure(Figure& p) {
        x = p.x;
        y = p.y;

        point->xcord = p.x;
        point->ycord = p.y;

        cout << "Figure::Figure(Figure &p)\n";
    }
    Figure(Figure* p) {
        x = p->x;
        y = p->y;

        point->xcord = p->x;
        point->ycord = p->y;

        cout << "Figure::Figure(Figure *p)\n";
    }

public:
    virtual ~Figure() {
        printf("Figure::~Figure()\n");

        delete &point;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    virtual void getInfo() {
        cout << "X: " << x << " Y: " << y << endl;
    }
    void getX() {
        cout << "X from Figure \n";
        cout << this->x << endl;
    }
    Point3D getCords() {
        Point3D a(x, y);
        return a;
    }
};

class Figure3D : public Figure {
protected:
    int z;

    Figure3D() {
        x = 0;
        y = 0;
        z = 0;

        point->zcord = z;

        cout << "Figure3D::Figure3D()\n";
    }
    Figure3D(int x, int y, int z) : Figure(x, y) {
        this->z = z;
        point->zcord = z;

        cout << "Figure3D::Figure3D(int x, int y, int z)\n";
    }
    Figure3D(Figure& p, int z) : Figure(p) {
        this->z = z;
        point->zcord = z;

        cout << "Figure3D::Figure3D(Figure &p, int z)\n";
    }
    Figure3D(Figure* p, int z) : Figure(p) {
        this->z = z;
        point->zcord = z;

        cout << "Figure3D::Figure3D(Figure *p, int z)\n";
    }
    Figure3D(Figure3D& p) {
        x = p.x;
        y = p.y;
        point->zcord = p.z;

        cout << "Figure3D::Figure3D(Figure3D &p)\n";
    }
    Figure3D(Figure3D* p) {
        x = p->x;
        y = p->y;
        point->zcord = p->z;

        cout << "Figure3D::Figure3D(Figure3D *p)\n";
    }

    ~Figure3D() {
        printf("Figure3D::~Figure3D()\n");
    }

public:
    Point3D getCords() {
        Point3D a(x, y, z);
        return a;
    }

    void getX() {
        cout << "X from Figure3D \n";
        cout << this->x << endl;
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
    ellipse(int x, int y, int osx, int osy) : Figure(x, y) {
        this->osx = osx;
        this->osy = osy;

        cout << "ellipse::ellipse(int x, int y, int osx, int osy)\n";
    }
    ellipse(Point3D& p, int osx, int osy) : Figure(p.xcord, p.ycord) {
        this->osx = osx;
        this->osy = osy;

        cout << "ellipse::ellipse(Point3D &p, int osx, int osy)\n";
    }
    ellipse(ellipse& e) {
        osx = e.osx;
        osy = e.osy;

        cout << "ellipse::ellipse(ellipse &e)\n";
    }
    ellipse(ellipse* e) {
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
    void getX() {
        cout << "X from ellipse \n";
        cout << this->x << endl;
    }
    int getOsx() {
        return osx;
    }
    int getOsy() {
        return osy;
    }

    ~ellipse() {
        cout << "ellipse::~ellipse() \n";
    }
};

class coloredEllipse : ellipse {
public:
    string color;
};

class parallelepiped : public Figure3D {
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
    parallelepiped(int x, int y, int z, int t, int i, int u) : Figure3D(x, y, z) {
        a = t;
        b = i;
        c = u;

        cout << "parallelepiped::parallelepiped(int x, int y, int z, int t, int i, int u)\n";
    }
    parallelepiped(Point3D& p, int t, int i, int u) : Figure3D(p.xcord, p.ycord, p.zcord) {
        a = t;
        b = i;
        c = u;

        cout << "parallelepiped::parallelepiped(Point3D &p, int t, int i, int u)\n";
    }

    void getX() {
        cout << "X from parallelepiped \n";
        cout << this->x << endl;
    }

    void getInfo() {
        cout << "X: " << x << " Y: " << y << " z: " << z << endl;
        cout << "a: " << a << " b: " << c << " c: " << c << endl;
        V = a * b * c;
        cout << "Объем: " << V << endl;
    }

    ~parallelepiped() {
        cout << "parallelepiped::~parallelepiped() \n";
    }


};

ellipse ReflectEllipse(ellipse e) {
    Point3D a;
    a = e.getCords();
    ellipse ell(a, e.getOsx(), e.getOsy());
    return ell;
};

void createEllipseStatic1() {
    cout << "Создание объекта класса ellipse статически\n";
    ellipse el1;
    el1.getInfo();
    cout << "Изменим координаты с помощью метода класса Figure\n";
    el1.set(10, 10);
    el1.getInfo();

    cout << "Создание объекта-отражения объекта el1 с помощью функци ReflectEllipse\n";
    el1 = ReflectEllipse(el1);
    ellipse el2(el1);
    el2.getInfo();

};

void createEllipseStatic2() {
    cout << "Создание объекта класса ellipse статически c помощью 4-х переменных\n";
    ellipse el1(1, 2, 3, 4);
    el1.getInfo();

};

void createEllipseStatic3() {
    cout << "Создание объекта класса ellipse статически с помощью точки Point\n";
    Point3D point(1, 2);
    ellipse el1(point, 3, 4);
    el1.getInfo();
};

void createEllipseStatic4() {
    cout << "Создание объекта класса ellipse статически с помощью другого объекта ellipse, объявленного динамически, затем удаление\n";
    ellipse* el = new ellipse;
    ellipse el1(el);
    el1.getInfo();
    delete el;

};

void createColoredEllipse1() {
    cout << "Создание объекта класса, у которого нет ни конкструктора, ни деструктора, однако таковые есть у его предков\n";
    coloredEllipse el1;
    el1.color = "red";
    cout << "Присваиваем единсвенному атрибуту color значение " << el1.color << endl;

};

void createParallelepipedDynamic() {
    cout << "Создание объекта класса parallelepipedстатически динамически\n";
    parallelepiped* pa1 = new parallelepiped;
    pa1->getInfo();
    
    delete pa1;

};

void differenceObjects1() {
    cout << "Создание массива класса Figure, и помещение в его ячейки объектов класса-потомков ellipse и parallelepiped, и вызов виртуальной функции getInfo с демонстрацией разных результатов, затем удаление динамически созданного объекта \n";
    Figure *mas[10];
    for (int i = 0; i<10; i++) {
        if (rand() % 2 == 0) {
            mas[i] = new ellipse();
        }
        else
        {
            mas[i] = new parallelepiped();
        }
    }
    for (int i = 0; i < 10; i++) {
        mas[i]->getInfo();
        delete mas[i];
    }

}

void differenceObjects2() {
    cout << "Создание переменной класса Figrue, помещение в нее объекта класса parallelepiped и вызов НЕ виртуальной функции getX \n";
    Figure *p = new parallelepiped();
    p->getX();

    delete p;
}






int main() {
    setlocale(LC_ALL, "rus");
    
    cout << "Во всех объектах классов-потомков класса Figure создается указатель на объект класса Point3D, который удаляется в деструкторе \n ";

    createEllipseStatic1();
    cout<< "||||||||||||||||||||||||||||||\n";
    createEllipseStatic2();
    cout<< "||||||||||||||||||||||||||||||\n";
    createEllipseStatic3();
    cout<< "||||||||||||||||||||||||||||||\n";
    createEllipseStatic4();
    cout<< "||||||||||||||||||||||||||||||\n";
    
    createColoredEllipse1();
    cout<< "||||||||||||||||||||||||||||||\n";

    createParallelepipedDynamic();
    cout<< "||||||||||||||||||||||||||||||\n";

    differenceObjects1();
    cout<< "||||||||||||||||||||||||||||||\n";
    differenceObjects2();
    cout<< "||||||||||||||||||||||||||||||\n";
    cout << "Конец!!!!!!!!!!!!!!!";

    return 0;
}