# ifndef INTERVAL
# define INTERVAL

# include<limits>

using namespace std;

const double infinity = numeric_limits<double>::infinity();

// Clase de intervalos para trabajar con los timepos de los rayos
struct interval {
	double min, max;
	interval(); // Intervalo vacío
	interval(double m, double M); //Constructor normal
	double size() const; // Longitud del intervalo
	bool contains(double x); // x in i?
	bool surrounds(double x); // Sin considerar la frontera
	static const interval empty, universe; // Intervalos vacios y R, respectivamente
};

# endif
