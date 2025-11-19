# include "vec3Class.hpp"

vec3::vec3(){
	v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f;
}

vec3::vec3(double x, double y, double z){
	v[0] = x; v[1] = y; v[2] = z;
}

vec3::vec3(const vec3 &u){
	v[0] = u[0]; v[1] = u[1]; v[2] = u[2];
}

double vec3::x() const { return v[0]; }
double vec3::y() const { return v[1]; }
double vec3::z() const { return v[2]; }

vec3 vec3::operator-() const{
	return vec3(-v[0], -v[1], -v[2]);
}

double vec3::operator[](int i) const { return v[i]; }
double& vec3::operator[](int i) { return v[i]; }

vec3& vec3::operator+=(const vec3 &u){
	v[0] += u[0]; v[1] += u[1]; v[2] += u[2];
	return *this;
}

vec3& vec3::operator-=(const vec3 &u){
	v[0] -= u[0]; v[1] -= u[1]; v[2] -= u[2];
	return *this;
}

vec3& vec3::operator*=(double t){
	v[0] *= t; v[1] *= t; v[2] *= t;
	return *this;
}

vec3& vec3::operator/=(double t){
	v[0] /= t; v[1] /= t; v[2] /= t;
	return *this;
}

double vec3::norm2() const{
	return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}

double vec3::norm() const{
	return sqrt(norm2());
}

