# ifndef SPHERE
# define SPHERE

# include "hittableClass.hpp"

// Primitiva de esfera. 
struct sphere : hittable{
	// Centro y radio de la esfera
	double radius;
	point3 center;
	sphere();
	sphere(double r, point3 c, shared_ptr<material> &m);
	bool hit(const ray& r, interval t, hit_record &rec) const override;
	shared_ptr<material> mat;
};

# endif
