# include "triangleClass.hpp"

triangle::triangle(){
	a = point3(0.0f,0.0f,0.0f); b = point3(0.0f,0.0f,0.0f); c = point3(0.0f,0.0f,0.0f);
}

triangle::triangle(point3 A, point3 B, point3 C, shared_ptr<material> &m){
	a = A; b = B; c = C; mat = m;
}

// Moller Trumbore Intersection Algorithm
bool triangle::hit(const ray& r, interval t, hit_record &rec) const{
	// Aristas del triángulo
	vec3 e1 = b - a;
	vec3 e2 = c - a;
	vec3 ray_cross_e2 = cross(r.direction, e2);
	double det = dot(e1, ray_cross_e2);
	if(abs(det) < EPS) return false;
	// Esto resuleve un sistema de ecuaciones de manera eficiente.
	double inv_det = 1.0f / det;
	vec3 s = r.origin - a;
	double u = inv_det * dot(s, ray_cross_e2);
	if((u < 0 && abs(u) > EPS) || (u > 1 && abs(u-1) > EPS)) return false;
	vec3 s_cross_e1 = cross(s,e1);
	double v = inv_det * dot(r.direction, s_cross_e1);
	if((v < 0 && abs(v) > EPS) || (u+v > 1 && abs(u+v-1) > EPS)) return false;
	double time_of_intersection = inv_det * dot(e2, s_cross_e1);
	if(!t.surrounds(time_of_intersection)) return  false;
	// Si hay intersección, la llevamos en rec
	rec.t = time_of_intersection;
	rec.p = r.at(rec.t);
	rec.mat = mat;
	vec3 out_normal = normalize(cross(e2,e1));
	rec.set_face_normal(r, out_normal);
	return true;
}
