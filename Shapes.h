#pragma once
class Shape {
	private:
	public:
		virtual ~Shape();
		virtual void Scale(float scaleFactor) = 0;
		virtual void Display() const = 0;
};
class Shape2D: virtual public Shape {
	private:
	public:
		~Shape2D();
		virtual float Area() const = 0;
		void ShowArea() const;
		virtual std::string GetName2D() const = 0;
		bool operator>(const Shape2D &rhs) const;
		bool operator<(const Shape2D &rhs) const;
		bool operator==(const Shape2D &rhs) const;
};
class Shape3D: virtual public Shape {
	private:
	public:
		~Shape3D();
		virtual float Volume() const = 0;
		void ShowVolume() const;
		virtual std::string GetName3D() const = 0;
		bool operator>(const Shape3D &rhs) const;
		bool operator<(const Shape3D &rhs) const;
		bool operator==(const Shape3D &rhs) const;
};
class Square: virtual public Shape2D {
	private:
		double _sideLength;
	public:
		Square();
		Square(double);
		void Scale(float);
		void Display() const;
		float Area() const;
		std::string GetName2D() const;
};
class Triangle: virtual public Shape2D {
	private:
		double _base;
		double _height;
	public:
		Triangle();
		Triangle(double, double);
		void Scale(float);
		void Display() const;
		float Area() const;
		std::string GetName2D() const;
};
class Circle: virtual public Shape2D {
	private:
		double _radius;
	public:
		Circle();
		Circle(double);
		void Scale(float);
		void Display() const;
		float Area() const;
		std::string GetName2D() const;
};
class TriangularPyramid: virtual public Shape3D, virtual public Triangle {
	private:
		double _heightPyramid;
		double _lengthBase;
		double _heightBase;
		Triangle _triangularBase;
	public:
		TriangularPyramid();
		TriangularPyramid(double, double, double);
		void Scale(float);
		void Display() const;
		float Volume() const;
		std::string GetName3D() const;
};
class Cylinder: virtual public Shape3D, virtual public Circle {
	private:
		double _height;
		double _radius;
		Circle _circularBase;
	public:
		Cylinder();
		Cylinder(double, double);
		void Scale(float);
		void Display() const;
		float Volume() const;
		std::string GetName3D() const;
};
class Sphere: virtual public Shape3D, virtual public Circle {
	private:
		double _radius;
		Circle _circle;
	public:
		Sphere();
		Sphere(double);
		void Scale(float);
		void Display() const;
		float Volume() const;
		std::string GetName3D() const;
};
