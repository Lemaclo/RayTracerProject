# ifndef VEC3
# define VEC3

# include <cmath>
# include <iostream>
# define point3 vec3

using namespace std;

struct vec3{
	double v[3];
	// Constructores
	vec3();
	vec3(double x, double y, double z);
	vec3(const vec3 &u);
	// Acceso a coordenadas
	double x() const;
	double y() const;
	double z() const;
	vec3 operator-() const; // Regresa -v
	double operator[](int i) const;
	double& operator[](int i);
	// Operaciones básicas
	vec3& operator+=(const vec3 &u);
	vec3& operator-=(const vec3 &u);
	vec3& operator*=(double t);
	vec3& operator/=(double t);
	double norm() const;
	double norm2() const;
};

// Aquí tuve un pequeño error: Las funciones inline no se puden definir en el archivo .cpp!

inline ostream& operator<<(ostream &o, const vec3& v){ // Imprime un vector
	return o << v[0] << ' ' << v[1] << ' ' << v[2];
}

// Operaciones aritméticas entre vectores
inline vec3 operator+(const vec3& u, const vec3& v){
	return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
	return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v){ //Entrada a entrada
	return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

// Operaciones aritméticas entre vectores y escalares
inline vec3 operator*(const vec3& u, double t){
	return vec3(u[0] * t, u[1] * t, u[2] * t);
}

inline vec3 operator*(double t, const vec3& u){
	return vec3(u[0] * t, u[1] * t, u[2] * t);
}

inline vec3 operator/(const vec3& u, double t){
	return vec3(u[0] / t, u[1] / t, u[2] / t);
}

// Operaciones vectoriales
inline double dot(const vec3& u, const vec3& v){
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}

inline vec3 cross(const vec3& u, const vec3& v){
	return vec3(u[1]*v[2] - u[2]*v[1], -u[0]*v[2] + u[2]*v[0], u[0]*v[1] - u[1]*v[0]);
}

inline vec3 normalize(const vec3& u){
	return u / u.norm();
}
# endif
