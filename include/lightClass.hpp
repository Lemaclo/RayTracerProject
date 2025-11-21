# ifndef LIGHT
# define LIGHT

# include "vec3Class.hpp"
# include "colorFunctions.hpp"

struct light{
	point3 location;
	color diffuse_component;
	color specular_component;
	light(point3 loc, color dc, color sc);
};

# endif
