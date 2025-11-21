# include "sphereClass.hpp"

sphere::sphere(){
		radius = 1.0f;
		center = vec3(0.0f,0.0f,0.0f);
}

sphere::sphere(double r, point3 c, shared_ptr<material> &m) : radius(r), center(c),
mat(m) {}

bool sphere::hit(const ray& r, interval t, hit_record &rec) const {
	vec3 oc = center - r.origin;
	// Resuelve una cuadratica que sale de la ecuacion de la esfera
	double a = r.direction.norm2();
	double h = dot(r.direction, oc);
	double c = oc.norm2() - radius*radius;
	double discriminant = h*h - a*c;
	if(discriminant < 0){
		return false;
	}
	double sq = sqrt(discriminant);
	// Hay dos tiempos de interseccion. Vamos a seleccionar el que sea válido (en [tmin, tmax])
	double root = (h - sq) / a;
	if(!t.surrounds(root)){
		root = (h + sq) / a;
		if(!t.surrounds(root)) return false;
	}
	// Si encontramos un tiempo válido, lo registramos en rec
	rec.t = root;
	rec.p = r.at(root);
	rec.mat = mat;
	vec3 out_normal = (rec.p - center) / radius; // Dividimos sobre el radio para normalizar
	rec.set_face_normal(r, out_normal);
	return true;
}
