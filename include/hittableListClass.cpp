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

bool hittableList::hit(const ray& r, double tmin, double tmax, hit_record& rec) const {
	// Vamos a probar si el rayo le pega a cualquier primitiva de la lista
	hit_record cur_record;
	bool hit_any = false;
	double closest = tmax; // Y vamos a conservar solo la más cercana
	for(shared_ptr<hittable> obj : objects){
		// Usamos closest como tmax para los objetos
		if(obj->hit(r,tmin,closest,cur_record)){
			hit_any = true;
			closest = cur_record.t;
		}
	}
	rec = cur_record;
	return hit_any;
}
