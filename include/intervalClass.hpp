# ifndef INTERVAL
# define INTERVAL

# include "utility.hpp"

// Clase de intervalos para trabajar con los timepos de los rayos
struct interval {
	double min, max;
	interval(); // Intervalo vacío
	interval(double m, double M); //Constructor normal
	double size() const; // Longitud del intervalo
	bool contains(double x); // x in i?
	bool surrounds(double x); // Sin considerar la frontera
	double clamp(double x) const; // Regresa el punto del intervalo mas cercano a x
	static const interval empty, universe; // Intervalos vacios y R, respectivamente
};

# endif
