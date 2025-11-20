# include "hittableClass.hpp"

void hit_record::set_face_normal(const ray& r, const vec3& out_normal){
	front_face = dot(r.direction, out_normal) < 0; // Apuntan en direcciones distintas
	normal = front_face ? out_normal : -out_normal;
}
