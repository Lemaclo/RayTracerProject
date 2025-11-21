# ifndef MATERIAL
# define MATERIAL

# include "vec3Class.hpp"
# include "colorFunctions.hpp"
# include "hittableClass.hpp"

struct material{
	color col;
	bool light_source;
	double reflection_coefficient;
	double color_coefficient;

	virtual ~material() = default;
	
	virtual bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) = 0;
};

struct metal : public material{
	metal(color c, double rco, double cco);
	bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) override;
};

struct lambertian : public material{
	lambertian(color c, double rco, double cco);
	bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) override;
};

# endif
