# ifndef UTILITY
# define UTILITY

# include<limits>
# include<cstdlib>

using namespace std;

// Constantes
const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Funciondes de utilidad mischeláneas
inline double degrees_to_radians(double deg){
	return deg * pi / 180.0f;
}

// Regresa un número real aleatorio uniforme en [0,1)
inline double random_double(){
	return rand() / (RAND_MAX + 1.0f);
}

// Regresa un número real aleatorio uniforme (?) en [min,max)
inline double random_double(double min, double max){
	return min + (max - min)*random_double();
}

# endif
