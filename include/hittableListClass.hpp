# ifndef HITTABLE_LIST
# define HITTABLE_LIST

# include "hittableClass.hpp"
# include "lightClass.hpp"

using namespace std;

struct hittableList : hittable{
	// Un shared_ptr es como un puntero más seguro con la memoria.
	vector<shared_ptr<hittable>> objects;
	vector<light> light_sources;
	color ambient_light = color(0.1f,0.1f,0.1f);
	color background_color = color(0.1f,0.1f,0.1f);
	hittableList();
	hittableList(shared_ptr<hittable> obj);

	void clear(); // Reinicia la lista de objetos
	void add(shared_ptr<hittable> obj); // Añade un objeto nuevo
	void add_light_source(light l); // Añade una fuente de luz nueva
	bool hit(const ray& r, interval t, hit_record& rec) const override;
};

# endif
