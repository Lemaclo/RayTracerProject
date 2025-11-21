# include "materialClass.hpp"

metal::metal(color c, double r){
	col = c;
	ref = r;
	light_source = false; 
}

bool metal::scatter(const ray& r_in, const hit_record& rec, ray &r_out){
	vec3 dir = normalize(reflect(r_in.direction, rec.normal));
	r_out = ray(rec.p, dir);
	return true;
}

lambertian::lambertian(color c, double r){
	col = c;
	ref = r;
	light_source = false; 
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, ray &r_out){
	vec3 dir = rec.normal + random_unit_vector();
	r_out = ray(rec.p, dir);
	return true;
}
