# ifndef RAY
# define RAY

# include "vec3Class.hpp"

struct ray{
	point3 origin; // Desde dónde sale el rayo
	vec3 direction; // Vector de dirección
	ray();
	ray(const point3& orig, const vec3& dir);
	// Evalúa la posición del rayo al momento t
	point3 at(double t) const;
};

# endif
