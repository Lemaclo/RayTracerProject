# ifndef SPHERE
# define SPHERE

# include "hittableClass.hpp"

// Primitiva de esfera. 
struct sphere : hittable{
	// Centro y radio de la esfera
	double radius;
	point3 center;
	sphere();
	sphere(double r, point3 c);
	bool hit(const ray& r, double tmin, double tmax, hit_record &rec) const override;
};

# endif
