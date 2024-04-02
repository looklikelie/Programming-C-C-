#include <iostream>
#include "main.h"

using namespace std;


// 13 ÂÀÐÈÀÍÒ
int main()
{
    float a, a1;
    cin >> a;
    a1 = a;
    first(a);
    first(&a1);
    cout<<'\n' << a << ' ' << a1;

    float b, b1;
    cin >> b;
    b1 = b;
    second(b);
    second(&b1);
    cout << '\n' << b << ' ' << b1;

    float a2, b2;
    square s;
    s.first.x = 0;
    s.first.y = 0;
    s.second.x = 0;
    s.second.y = 2;
    s.third.x = 2;
    s.third.y = 0;
    cin >> a2 >> b2;
    shift(a2, b2, s);
    //shift(&a2, &b2, &s);
    cout << s.first.x << ' ' << s.first.y << '\n' << s.second.x << ' ' << s.second.y << '\n' << s.third.x << ' ' << s.third.y << '\n';

    int matrix[10][10];
    for(int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
    int f, st;
    cin >> f >> st;
    //swap2lines(&f, &st, &matrix[0][0])
    swap2lines(f, st, &matrix[0][0]);
    for(int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
            cout << matrix[i][j] << ' ';
        }
        cout <<'\n';
    }
    return 0;
}
