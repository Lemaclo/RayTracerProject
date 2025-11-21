# ifndef VEC3
# define VEC3

# include <cmath>
# include <iostream>
# include "intervalClass.hpp"
# include "utility.hpp"

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
	// Vectores aleatorios
	static vec3 random(); // Vector con entradas entre [0 y 1)
	static vec3 random(double min, double max); // Vector con entradas entre [min y max)
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

// Devuelve un vector aleatorio en la esfera unitaria. Hace esto rechazando vectores
// que se salen hasta encontrar uno que no se salga (de la esfera) y lo normaliza.
// No normalizamos el primero para que la disrtribución sea uniforme
inline vec3 random_unit_vector(){
	while(true){
		vec3 v = vec3::random(-1,1);
		double n2 = v.norm2();
		// Si es muy pequeño, rechazamos para evitar errores numéricos.
		if(1e-160 < n2 && n2 <= 1){
			return normalize(v);
		}
	}
}

// Regresa un vector unitario aleatorio en el mismo hemisferio que el vector normal
inline vec3 random_on_hemisphere(const vec3 &n){
	vec3 v = random_unit_vector();
	if(dot(v, n) > 0.0f) return v;
	return -v;
}

// Refleja v sobre n
inline vec3 reflect(const vec3& v, const vec3& n){
	return v - 2*dot(v,n)*n;
}

# endif
