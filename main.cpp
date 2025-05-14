#include <iostream>
#include "geometry.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA");

    Triangle t;
    cout << "Введіть координати трикутника (A, B, C):";
    cout << "A (x y): ";
    cin >> t.a.x >> t.a.y;
    cout << "B (x y): ";
    cin >> t.b.x >> t.b.y;
    cout << "C (x y): ";
    cin >> t.c.x >> t.c.y;

    if (isDegenerate(t)) {
        cout << "Трикутник вироджений (площа = 0). Перевірка неможлива." << endl;
        return 1;
    }

    cout << "Периметр трикутника: " << perimeter(t) << endl;

    int method;
    cout << "Оберіть метод обчислення площі:\n";
    cout << "1 – через координати вершин\n";
    cout << "2 – через формулу Герона\n";
    cout << "Ваш вибір: ";
    cin >> method;

    if (method == 1) {
        cout << "Площа трикутника (координатна формула): " << area(t) << endl;
    }
    else if (method == 2) {
        cout << "Площа трикутника (формула Герона): " << areaHeron(t) << endl;
    }
    else {
        cout << "Невірний номер методу." << endl;
        return 1;
    }

    Point centr = centroid(t);
    cout << "Центроїд: (" << centr.x << ", " << centr.y << ")" << endl;

    int n;
    cout << "Скільки точок потрібно перевірити? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Point p;
        cout << "Координати точки #" << i + 1 << " (x y): ";
        cin >> p.x >> p.y;

        if (isOnEdge(t, p)) {
            cout << "Точка на межі трикутника." << endl;
        }
        else if (isInside(t, p)) {
            cout << "Точка всередині трикутника." << endl;
        }
        else {
            cout << "Точка поза трикутником." << endl;
        }
    }

    return 0;
}
