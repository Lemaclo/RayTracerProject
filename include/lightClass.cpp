# include "lightClass.hpp"

light::light(point3 loc, color dc, color sc){
	location = loc;
	diffuse_component = dc;
	specular_component = sc;
}
