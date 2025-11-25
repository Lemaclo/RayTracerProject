# ifndef CUBE
# define CUBE

# include "hittableClass.hpp"

// Primitiva de cubp
struct cube : hittable{
	interval x, y, z;
	cube();
	cube(interval _x, interval _y, interval _z, shared_ptr<material> &m);
	bool hit(const ray& r, interval t, hit_record &rec) const override;
	shared_ptr<material> mat;
};

# endif
