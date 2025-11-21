# include "hittableListClass.hpp"

hittableList::hittableList(){}
hittableList::hittableList(shared_ptr<hittable> obj){
	add(obj);
}

void hittableList::clear(){
	objects.clear();
}

void hittableList::add(shared_ptr<hittable> obj){
	objects.push_back(obj);
}

bool hittableList::hit(const ray& r, interval t, hit_record& rec) const {
	// Vamos a probar si el rayo le pega a cualquier primitiva de la lista
	hit_record cur_record;
	bool hit_any = false;
	double closest = t.max; // Y vamos a conservar solo la más cercana
	for(shared_ptr<hittable> obj : objects){
		// Usamos closest como tmax para los objetos
		if(obj->hit(r,interval(t.min,closest),cur_record)){
			hit_any = true;
			closest = cur_record.t;
		}
	}
	rec = cur_record;
	return hit_any;
}

void hittableList::add_light_source(light l){
	light_sources.push_back(l);
}
