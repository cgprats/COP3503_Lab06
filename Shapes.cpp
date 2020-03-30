#include <iostream>
#include "Shapes.h"
#define PI 3.14159f
//Shape
Shape::~Shape() {
}
//Shape2D
Shape2D::~Shape2D() {
}
void Shape2D::ShowArea() const {
	std::cout << "The area of the " << this->GetName2D() << " is : " << this->Area() << std::endl;
}
bool Shape2D::operator>(const Shape2D &rhs) const {
	if (this->Area() > rhs.Area()) {
		return true;
	}
	else {
		return false;
	}
}
bool Shape2D::operator<(const Shape2D &rhs) const {
	if (this->Area() < rhs.Area()) {
		return true;
	}
	else {
		return false;
	}
}
bool Shape2D::operator==(const Shape2D &rhs) const {
	if (this->Area() == rhs.Area()) {
		return true;
	}
	else {
		return false;
	}
}
//Shape3D
Shape3D::~Shape3D() {
}
void Shape3D::ShowVolume() const {
	std::cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << std::endl;
}
bool Shape3D::operator>(const Shape3D &rhs) const {
	if (this->Volume() > rhs.Volume()) {
		return true;
	}
	else {
		return false;
	}
}
bool Shape3D::operator<(const Shape3D &rhs) const {
	if (this->Volume() < rhs.Volume()) {
		return true;
	}
	else {
		return false;
	}
}
bool Shape3D::operator==(const Shape3D &rhs) const {
	if (this->Volume() == rhs.Volume()) {
		return true;
	}
	else {
		return false;
	}
}
//Square
Square::Square() {
	_sideLength = 0.0;
}
Square::Square(double sideLength) {
	_sideLength = sideLength;
}
void Square::Scale(float scaleFactor) {
	_sideLength *= scaleFactor;
}
void Square::Display() const {
	this->ShowArea();
	std::cout << "Length of a side: " << _sideLength;
}
float Square::Area() const {
	return (_sideLength * _sideLength);
}
std::string Square::GetName2D() const {
	return "Square";
}
//Triangle
Triangle::Triangle() {
	_base = 0.0;
	_height = 0.0;
}
Triangle::Triangle(double base, double height) {
	_base = base;
	_height = height;
}
void Triangle::Scale(float scaleFactor) {
	_base *= scaleFactor;
	_height *= scaleFactor;
}
void Triangle::Display() const {
	this->ShowArea();
	std::cout << "Base: " << _base << std::endl;
	std::cout << "Height: " << _height << std::endl;
}
float Triangle::Area() const {
	return (_base * _height * 0.5);
}
std::string Triangle::GetName2D() const {
	return "Triangle";
}
//Circle
Circle::Circle() {
	_radius = 0.0;
}
Circle::Circle(double radius) {
	_radius = radius;
}
void Circle::Scale(float scaleFactor) {
	_radius *= scaleFactor;
}
void Circle::Display() const {
	this->ShowArea();
	std::cout << "Radius: " << _radius << std::endl;
}
float Circle::Area() const {
	return (_radius * _radius * PI);
}
std::string Circle::GetName2D() const {
	return "Circle";
}
//TriangularPyramid
TriangularPyramid::TriangularPyramid() {
	_heightPyramid = 0.0;
	_lengthBase = 0.0;
	_heightBase = 0.0;
	_triangularBase = Triangle(_lengthBase, _heightBase);
}
TriangularPyramid::TriangularPyramid(double heightPyramid, double lengthBase, double heightBase) {
	_heightPyramid = heightPyramid;
	_lengthBase = lengthBase;
	_heightBase = heightBase;
	_triangularBase = Triangle(_lengthBase, _heightBase);
}
void TriangularPyramid::Scale(float scaleFactor) {
	_heightPyramid *= scaleFactor;
	_lengthBase *= scaleFactor;
	_heightBase *= scaleFactor;
	_triangularBase = Triangle(_lengthBase, _heightBase);
}
void TriangularPyramid::Display() const {
	this->ShowVolume();
	std::cout << "The height is: " << _heightPyramid << std::endl;
	_triangularBase.Display();
}
float TriangularPyramid::Volume() const {
	return ((_triangularBase.Area() * _heightPyramid) / 3);
}
std::string TriangularPyramid::GetName3D() const {
	return "TriangularPyramid";
}
//Cylinder
Cylinder::Cylinder() {
	_height = 0.0;
	_radius = 0.0;
	_circularBase = Circle(_radius);
}
Cylinder::Cylinder(double height, double radius) {
	_height = height;
	_radius = radius;
	_circularBase = Circle(_radius);
}
void Cylinder::Scale(float scaleFactor) {
	_height *= scaleFactor;
	_radius *= scaleFactor;
	_circularBase = Circle(_radius);
}
void Cylinder::Display() const {
	this->ShowVolume();
	std::cout << "The height is: " << _height << std::endl;
	_circularBase.Display();
}
float Cylinder::Volume() const {
	return (_radius * _radius * _height * PI);
}
std::string Cylinder::GetName3D() const {
	return "Cylinder";
}
//Sphere
Sphere::Sphere() {
	_radius = 0.0;
	_circle = Circle(_radius);
}
Sphere::Sphere(double radius) {
	_radius = radius;
	_circle = Circle(_radius);
}
void Sphere::Scale(float scaleFactor) {
	_radius *= scaleFactor;
	_circle = Circle(_radius);
}
void Sphere::Display() const {
	this->ShowVolume();
	_circle.Display();
}
float Sphere::Volume() const {
	return ((_radius * _radius * _radius * 4 * PI) / 3);
}
std::string Sphere::GetName3D() const {
	return "Sphere";
}
