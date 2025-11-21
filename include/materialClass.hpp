# ifndef MATERIAL
# define MATERIAL

# include "vec3Class.hpp"
# include "colorFunctions.hpp"
# include "hittableClass.hpp"

using namespace std;

struct material{
	color col;
	double ambient_coefficient, diffuse_coefficient, specular_coefficient;
	double reflectance, refractance;

	virtual ~material() = default;
	
	virtual bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) = 0;
};

struct metal : public material{
	metal(color c, double ka, double kd, double ks, double refl, double refr);
	bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) override;
};

struct lambertian : public material{
	lambertian(color c, double ka, double kd, double ks, double refl, double refr);
	bool scatter(const ray& r_in, const hit_record& rec, ray &r_out) override;
};

# endif
