# include "rayClass.hpp"

ray::ray(){ }
ray::ray(const point3& orig, const vec3& dir){
	origin = orig;
	direction = dir;
}

point3 ray::at(double t) const{
	return origin + t*direction;
}
