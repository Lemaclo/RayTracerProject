# ifndef HITTABLE
# define HITTABLE

# include "rayClass.hpp"
# include <vector>
# include <memory>

struct material;
// Estructura para guardar la información de colisión de un rayo
struct hit_record{
	point3 p; // Punto de intersección
	vec3 normal; // Vector normal (en contra del rayo)
	double t; // Tiempo de intersección
	bool front_face; // True si el rayo pegó por fuera de la primitiva
	shared_ptr<material> mat;
			 
	// En las primitivas calculamos el vector normal hacia afuera, pero
	// en algunos casos, queremos el que va hacia adentro, porque siempre queremos
	// que vaya contra el rayo (ejemplo: en cristal el rayo puede pegar por dentro!)
	void set_face_normal(const ray& r, const vec3& out_normal);
};

// Clase base para primitivas. Tengo que admitir que no soy muy versado en OOP, 
// así que tuve que investigar algunas de las plabaras clave ce C++ para esto
struct hittable{
	// Al parecer, es importante que el destructor de la clase base sea virtual,
	// para que la clase hijo llame a la función adecuada
	virtual ~hittable() = default; 
	// Esta sintaxis es nueva para mi. Significa que esta función tiene que ser
	// implementada en la clase hijo, o si no no se puede instanciar
	virtual bool hit(const ray& r, interval t, hit_record& rec) const = 0;
};

# endif
