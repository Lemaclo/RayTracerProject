# include "materialClass.hpp"

metal::metal(color c, double ka, double kd, double ks, double refl, double refr){
	col = c;
	ambient_coefficient = ka;
	diffuse_coefficient = kd;
	specular_coefficient = ks;
	reflectance = refl;
	refractance = refr;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, ray &r_out){
	vec3 dir = normalize(reflect(r_in.direction, rec.normal));
	if(dir.near_zero()) dir = rec.normal;
	r_out = ray(rec.p, dir);
	return true;
}

lambertian::lambertian(color c, double ka, double kd, double ks, double refl, double refr){
	col = c;
	ambient_coefficient = ka;
	diffuse_coefficient = kd;
	specular_coefficient = ks;
	reflectance = refl;
	refractance = refr;
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, ray &r_out){
	vec3 dir = rec.normal + random_unit_vector();
	if(dir.near_zero()) dir = rec.normal;
	r_out = ray(rec.p, dir);
	return true;
}
