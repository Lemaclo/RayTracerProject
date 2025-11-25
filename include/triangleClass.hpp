# ifndef TRIANGLE
# define TRIANGLE

# include "hittableClass.hpp"

// Primitiva de triángulo
struct triangle : hittable {
	// Vértices del triángulo
	point3 a,b,c;
	triangle();
	triangle(point3 A, point3 B, point3 C, shared_ptr<material> &m);
	bool hit(const ray& r, interval t, hit_record &rec) const override;
	shared_ptr<material> mat; // Material del triángulo
};

# endif
