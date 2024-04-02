#define _USE_MATH_DEFINES
#include "lab_4.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define M_PI
using std::cout;
using std::cin;


Vector2D::Vector2D(double x, double y) {
	this->x = x;
	this->y = y;
};
Vector2D::Vector2D() = default;
Vector2D::Vector2D(double x) {
	this->x = x;
	this->y = x;
};
double Vector2D::len() const {
	return sqrt(this->x * this->x + this->y * this->y);
};
void Vector2D::print() const {
	cout << this->x << ' ' << this->y << "\n";
};
Vector2D Vector2D::operator- (Vector2D& v) const {
	const Vector2D result(v.x - this->x, v.y - this->y);
	return result;
};
Vector2D Vector2D::operator+(Vector2D& v) const {
	const Vector2D result(v.x + this->x, v.y + this->y);
	return result;
};
Vector2D Vector2D::operator+=(Vector2D& v) const {
	const Vector2D result(v.x + this->x, v.y + this->y);
	return result;
};
Vector2D Vector2D::operator/=(double v) const {
	const Vector2D result(this->x / v, this->y / v);
	return result;
};
Vector2D Vector2D::operator/(double v) const {
	const Vector2D result(this->x / v, this->y / v);
	return result;
};
Vector2D Vector2D::operator*(double v) const {
	const Vector2D result(this->x * v, this->y * v);
	return result;
};
// class Hexagon (�����)
// ======================================================================================
Hexagon::Hexagon() {
	// this->Hexagon::initFromDialog();
};
const char*  Hexagon::classname() {
	return "Hexagon";
};
unsigned int Hexagon::size() {
	// ������ ������� ������� ������ �������
	this->_size = sizeof(Hexagon);
	return this->_size;
};
double Hexagon::mass() {
	return this->_mass;
};
void Hexagon::initFromDialog() {
	cout << "Input six coordinates of hexagon\n";
	// ������������� ����� ��������������
	for (size_t i = 0; i < 6; i++) {
		cout << "	" << i + 1 << ". ";
		cin >> v[i].x >> v[i].y;
	}
	// ������������� �����
	cout << "Input mass\n";
	cout << "	Mass: ";
	cin >> this->_mass;
	// ��������� ������� ��������������
	for (auto& i : this->v)
		this->pos += i;
	this->pos /= 6;
};
double Hexagon::square() {
	for (size_t i = 0; i < 6; i++) {
		// ��� ������� � ������������ i-��� ������������
		const double a = (this->pos - this->v[i]).len();
		const double b = (this->pos - this->v[(i + 1) % 6]).len();
		const double c = (this->v[i] - this->v[(i + 1) % 6]).len();
		const double p = (a + b + c) / 2;
		// ������� i-��� ������������
		Si[i] = sqrt((p) * (p - a) * (p - b) * (p - c));
		// ������� ���� ������
		this->S += Si[i];
	}
	return this->S;
};
double Hexagon::perimeter() {
	// ��������� ������� ������������ � �� �����
	for (size_t i = 0; i < 6; i++) {
		Vector2D a = this->v[(i + 1) % 6] - this->v[i];
		this->P += a.len();
	}
	return this->P;
};
Vector2D Hexagon::massCenter() {
	// ���������� ����� ���� ������
	Vector2D mass_center(0.0, 0.0); // ����� ���� ���� ������
	for (size_t i = 0; i < 6; i++) {
		// ���������� �������� i-��� ������������
		Vector2D center = (this->pos + this->v[i] + this->v[(i + 1) % 6]) / 3 * Si[i];
		// ��������� ����� ���� i-��� ������������
		mass_center += center;
	}
	// �������� ����� ���� �������� ������
	this->mass_center = mass_center / this->S;
	return this->mass_center;
};
Vector2D Hexagon::position() {
	this->pos.print();
	return this->pos;
};
bool Hexagon::operator== (PhysObject& ob) {
	return this->mass() == ob.mass();
};
bool Hexagon::operator< (PhysObject& ob) {
	return this->mass() < ob.mass();
};
void Hexagon::draw() const {
	cout << "Classname: " << this->_classname << "\n";
	cout << "Size: " << this->_size << "\n";
	cout << "Coordinates:\n";
	for (auto i : this->v)
		i.print();
	cout << "Mass: " << this->_mass << "\n";
	cout << "Position: ";
	this->pos.print();
	cout << "Square: " << this->S << "\n";
	cout << "Perimeter: " << this->P << "\n";
	cout << "Mass center: ";
	this->mass_center.print();
};
// class Ellipse (�����)
// ======================================================================================
Ellipse::Ellipse() {
	// this->Ellipse::initFromDialog();
};
const char* Ellipse::classname() {
	return "Ellipse";
};
unsigned int Ellipse::size() {
	// ������ ������� ������� ������ �������
	this->_size = sizeof(Ellipse);
	return this->_size;
};
void Ellipse::initFromDialog() {
	cout << "Input four borders of ellipse\n";
	// ������ ���������� ������ �������
	for (size_t i = 0; i < 4; i++) {
		cout << "	" << i + 1 << ". ";
		cin >> v[i].x >> v[i].y;
	}
	// ��������� ����� ������� ���� ������� � ���������� ��� �������, ����� ����������
	if (this->v[2].y - this->v[0].y != 0)
		std::swap(this->v[1], this->v[2]);
	// ������ ����� ������
	cout << "Input mass\n";
	cout << "	Mass: ";
	cin >> this->_mass;
	// ������� ���������� �������� ������� (��� �������)
	this->pos.x = abs(this->v[1].x - this->v[3].x) / 2;
	this->pos.y = abs(this->v[1].y - this->v[3].y) / 2;
	// ���� ������� � ����� �������
	this->l_a = (this->v[1] - this->pos).len();
	this->l_b = (this->v[0] - this->pos).len();
};
double Ellipse::square() {
	// ���� �������
	this->S = M_PI + this->l_a + this->l_b;
	return this->S;
};
double Ellipse::perimeter() {
	// ���� ��������
	this->P = 4 * (this->S + abs(this->l_a - this->l_b)) / (this->l_a + this->l_b);
	return this->P;
};
double Ellipse::mass() {
	return this->_mass;
};
Vector2D Ellipse::massCenter() {
	// ���������� ����� ���� (��������� � ������� �������)
	this->mass_center = this->pos;
	return this->mass_center;
};
Vector2D Ellipse::position() {
	this->pos.print();
	return this->pos;
};
bool Ellipse::operator== (PhysObject& ob) {
	return this->mass() == ob.mass();
};
bool Ellipse::operator< (PhysObject& ob) {
	return this->mass() == ob.mass();
};
void Ellipse::draw() const {
	cout << "Classname: " << this->_classname << "\n";
	cout << "Size: " << this->_size << "\n";
	cout << "Coordinates:\n";
	for (auto i : this->v)
		i.print();
	cout << "Mass: " << this->_mass << "\n";
	cout << "Position: ";
	this->pos.print();
	cout << "Square: " << this->S << "\n";
	cout << "Perimeter: " << this->P << "\n";
	cout << "Mass center: ";
	this->mass_center.print();
};
