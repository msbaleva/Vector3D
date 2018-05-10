#ifndef VECTORD3D_1_VECTOR3D_H_
#define VECTORD3D_1_VECTOR3D_H_

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Vector3D
{
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();
	double getX() const;
	double getY() const;
	double getZ() const;
	Vector3D operator+(const Vector3D & secondVector) const;
	Vector3D operator-(const Vector3D & secondVector) const;
	Vector3D operator-() const;
	Vector3D operator*(double number) const;
	Vector3D operator=(const Vector3D & secondVector);
	friend Vector3D operator*(double number, const Vector3D & vector);
	friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);

private:
	double x_;
	double y_;
	double z_;
};


Vector3D::Vector3D()
{
	x_ = 0;
	y_ = 0;
	z_ = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
	x_ = x;
	y_ = y;
	z_ = z;
	
}

Vector3D::~Vector3D()
{

}

double Vector3D::getX() const
{
	return x_;
}

double Vector3D::getY() const
{
	return y_;
}

double Vector3D::getZ() const
{
	return z_;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D NewVector;
	NewVector.x_ = x_ + secondVector.x_;
	NewVector.y_ = y_ + secondVector.y_;
	NewVector.z_ = z_ + secondVector.z_;
	return NewVector;
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D NewVector;
	NewVector.x_ = x_ - secondVector.x_;
	NewVector.y_ = y_ - secondVector.y_;
	NewVector.z_ = z_ - secondVector.z_;
	return NewVector;
}

Vector3D Vector3D::operator-() const
{
	Vector3D NewVector;
	if (x_ != 0) { NewVector.x_ = -x_; }
	if (y_ != 0) { NewVector.y_ = -y_; }
	if (z_ != 0) { NewVector.z_ = -z_; }
	return NewVector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D NewVector;
	NewVector.x_ = x_*number;
	NewVector.y_ = y_*number;
	NewVector.z_ = z_*number;
	return NewVector;
}

Vector3D Vector3D::operator=(const Vector3D & secondVector)
{
	if (this != &secondVector) {
		x_ = secondVector.x_;
		y_ = secondVector.y_;
		z_ = secondVector.z_;
	}
	return *this;
}

Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D NewVector;
	NewVector.x_ = number*vector.x_;
	NewVector.y_ = number*vector.y_;
	NewVector.z_ = number*vector.z_;
	return NewVector;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector)
{
	iStream.ignore();
	iStream >> vector.x_;
	iStream.ignore();
	iStream >> vector.y_;
	iStream.ignore();
	iStream >> vector.z_;
	iStream.ignore();
	return iStream;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
	oStream << "(" << vector.x_ << "," << vector.y_ << "," << vector.z_ << ")";
	return oStream;
}
#endif
