# ifndef UTILITY
# define UTILITY

# include <iostream>
# include <cmath>
# include <limits>
# include <memory>

using namespace std;

// Constantes
//const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Funciondes de utilidad mischeláneas
inline double degrees_to_radians(double deg){
	return deg * pi / 180.0f;
}

// Incluye todo lo demás

# include "colorFunctions.hpp"
# include "intervalClass.hpp"
# include "vec3Class.hpp"
# include "hittableClass.hpp"
# include "hittableListClass.hpp"
# include "sphereClass.hpp"
# include "rayClass.hpp"

# endif
