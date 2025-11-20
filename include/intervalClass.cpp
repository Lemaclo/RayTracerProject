# include "intervalClass.hpp"

interval::interval(){
	min = infinity;
	max = -infinity;
}

interval::interval(double m, double M) : min(m), max(M) {}

double interval::size() const{
	return max - min;
}

bool interval::contains(double x){
	return min <= x && x <= max;
}
bool interval::surrounds(double x){
	return min < x && x < max;
}

const interval interval::empty = interval(infinity, -infinity);
const interval interval::universe = interval(-infinity, infinity);

