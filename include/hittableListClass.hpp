# ifndef HITTABLE_LIST
# define HITTABLE_LIST

# include "hittableClass.hpp"
# include <memory>
# include <vector>

using namespace std;

struct hittableList : hittable{
	// Un shared_ptr es como un puntero más seguro con la memoria.
	vector<shared_ptr<hittable>> objects;
	hittableList();
	hittableList(shared_ptr<hittable> obj);

	void clear(); // Reinicia la lista de objetos
	void add(shared_ptr<hittable> obj); // Añade un objeto nuevo
	bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;
};

# endif
