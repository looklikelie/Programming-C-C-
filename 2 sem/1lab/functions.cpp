#include "main.h"
#include <iostream>

void first(float &a){
    int b = a;
    a = a - b;
}
void first(float *a){
    int b = *a;
    *a = *a - b;
}

void second(float &b){
    b = -b;
}
void second(float *b){
    *b = -(*b);
}

void shift(float &a, float &b, square &s){
    s.first.x += a;
    s.first.y += b;
    s.second.x += a;
    s.second.y += b;
    s.third.x += a;
    s.third.y += b;
}

void shift(float *a, float *b, square *s){
    s->first.x += *a;
    s->first.y += *b;
    s->second.x += *a;
    s->second.y += *b;
    s->third.x += *a;
    s->third.y += *b;
}

void swap2lines(int &f, int &s, int *arr){
    for(int i = 0; i < 10; i++){
        std::swap(arr[10 * (f - 1) + i], arr[10 * (s - 1) + i]);
    }
}

void swap2lines(int *f, int *s, int *arr){
    for(int i = 0; i < 10; i++){
        std::swap(arr[10 * (*f - 1) + i], arr[10 * (*s - 1) + i]);
    }
}
