#ifndef MAIN_H
#define MAIN_H

struct point{
    float x;
    float y;
};

struct square{
    point first;
    point second;
    point third;
};

void first(float &a);
void first(float *a);

void second(float &b);
void second(float *b);

void shift(float &a, float &b, square &s);
void shift(float *a, float *b, square *s);

void swap2lines(int &f, int &s, int *arr);
void swap2lines(int *f, int *s, int *arr);
#endif // MAIN_H
