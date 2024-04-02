#include "proga_2.h"
#include <stdio.h>
#include <math.h>

Polinom::Polinom(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = b * b - 4 * a * c;
}
Polinom::Polinom() {
	this->a = 0.0;
	this->b = 0.0;
	this->c = 0.0;
	this->d = 0.0;
}
Polinom::Polinom(const Polinom& p) {
	this->a = p.a;
	this->b = p.b;
	this->c = p.c;
	this->d = p.d;
}
void Polinom::set_vars(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = b * b - 4 * a * c;
}
void Polinom::print() {
	printf("%fx^2 ", this->a);
	if (this->b > 0)
		printf("+");
	printf("%fx ", this->b);
	if (this->c > 0)
		printf("+");
	printf("%f\n", this->c);
}
void Polinom::fx(float x) {
	this->x = x;
	this->f_x = this->a * x * x + this->b * x + this->c;
}
void Polinom::howmuch() {
	if (this->d < 0) this->solutions = 0;
	else if (this->d == 0) this->solutions = 1;
	else if (this->d > 0) this->solutions = 2;
	printf("Count of solutions is: %i\n", this->solutions);
}
void Polinom::solve() {
	if (this->d < 0) {
		printf("No solutions\n");
	}
	else {
		this->sol_1 = (-(this->b) + sqrt(this->d)) / (2 * this->a);
		this->sol_2 = (-(this->b) - sqrt(this->d)) / (2 * this->a);
		printf("Solutions: %f %f\n", this->sol_1, this->sol_2);
	}
}
void Polinom::dydx() {
	float x = -(this->b) / (2 * this->a);
	float y = (this->a * x + this->b) * x + this->c;
	if (this->a > 0) printf("Max in (%f, %f)\n", x, y);
	else printf("Min in (%f, %f)\n", x, y);
}
