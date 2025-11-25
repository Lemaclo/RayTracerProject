# include <iostream>
# include <cmath>
# include <limits>
# include <memory>
# include <cstdlib>
# include <fstream>
# include <string>
# include <vector>

using namespace std;

# include "include/utility.hpp"
# include "include/colorFunctions.hpp"
# include "include/intervalClass.hpp"
# include "include/vec3Class.hpp"
# include "include/hittableClass.hpp"
# include "include/hittableListClass.hpp"
# include "include/sphereClass.hpp"
# include "include/triangleClass.hpp"
# include "include/cubeClass.hpp"
# include "include/rayClass.hpp"
# include "include/cameraClass.hpp"
# include "include/materialClass.hpp"
# include "include/lightClass.hpp"

int main(){
	// Materiales
	// ambient, diffuse, specular, specular_expo, reflectance, refractance
	//shared_ptr<material> rubber = make_shared<lambertian>(color(1.0f,0.0f,0.0f),0.02,0.01,0.4,10,0.3, 0.0);
	ifstream f1("materials.txt");
	int num_mat; f1 >> num_mat;
	vector< shared_ptr<material> > materials(num_mat);
	for(int i=0;i<num_mat;i++){
		int type; f1 >> type; // 0 lambertian, 1 metal
		double r,g,b; f1 >> r >> g >> b; // Color
		double ka, kd, ks, es; f1 >> ka >> kd >> ks >> es; // Parámetros de Phong
		double refl, refr; f1 >> refl >> refr; // Coeficientes de reflexion y refraccion.
		if(type) materials[i] = make_shared<metal>(color(r,g,b),ka,kd,ks,es,refl,refr);
		else materials[i] = make_shared<lambertian>(color(r,g,b),ka,kd,ks,es,refl,refr);
	}
	f1.close();
	//shared_ptr<material> rubber = make_shared<lambertian>(color(1.0f,0.0f,0.0f),0.2,0.5,0.4,10,0.02, 0.0);
	//shared_ptr<material> bronze = make_shared<lambertian>();
	//shared_ptr<material> bronze2 = make_shared<lambertian>;
	//shared_ptr<material> shiny = make_shared<metal>();
	//shared_ptr<material> right = make_shared<metal>(color(0.8f,0.6f,0.2f), 0.1,0.4,0.2, 0.3, 0.0);
	// Escena de prueba hardcodeada
	hittableList world(make_shared<cube>(interval(-100,100),interval(-100,-0.5f),interval(-100,10),materials[1]));
	world.add(make_shared<cube>(interval(-0.5f,0.5f), interval(-0.5f,0.5f), interval(-1.7f,0.-1.3f),materials[3]));
	world.add(make_shared<sphere>(0.5f, point3(0.0f,0.0f,1.0f), materials[0]));
	world.add(make_shared<sphere>(0.5f, point3(-1.0f,0.0f,-1.0f), materials[3]));
	world.add(make_shared<sphere>(0.5f, point3(1.0f,0.0f,-1.0f), materials[2]));
	//world.add(make_shared<triangle>(point3(-1.0f,1.0f,-1.0f), point3(1.0f,1.0f,-1.0f), point3(0.0f,0.0f,-1.5f), shiny));
	//world.add(make_shared<sphere>(0.5f, point3(-1.0f,0.0f,-1.0f), left));
	//world.add(make_shared<sphere>(0.5f, point3(1.0f,0.0f,-1.0f), right));
	world.ambient_light = color(1.0,1.0,1.0);
	world.background_color = color(0.2,0.2,0.2);
	//world.add_light_source(light(vec3(-1.0f, 10.0f, 0.0f), color(0.9,0.9,0.9), color(0.9,0.9,0.9)));
	world.add_light_source(light(vec3(10.0f, 10.0f, 2.0f), color(1.0,1.0,1.0), color(1.0,1.0,1.0)));
	//world.add_light_source(light(vec3(10.0f, 0.0f, 0.0f), color(0.9,0.9,0.9), color(0.9,0.9,0.9)));
	//world.add_light_source(light(vec3(0.0f, 0.0f, 3.0f), color(0.9,0.9,0.9), color(0.9,0.9,0.9)));
	//world.add_light_source(light(vec3(10.0f, 3.0f, 0.0f), color(0.0,0.9,0.0), color(0.9,0.9,0.9)));
	//world.add_light_source(light(vec3(0.0f, 0.0f, 5.0f), color(0.0,0.0,0.9), color(0.9,0.9,0.9)));
	// Creamos una cámara
	camera cam;
	ifstream f3("cameraConfig.txt");
	double arx, ary; f3 >> arx >> ary;
	cam.aspect_ratio = arx / ary;
	f3 >> cam.image_width;
	f3 >> cam.samples_per_pixel;
	f3 >> cam.max_depth;
	// Configuramos la vista
	f3 >> cam.vfov;
	double x,y,z; f3 >> x >> y >> z;
	cam.lookfrom = point3(x,y,z);
	f3 >> x >> y >> z;
	cam.lookat = point3(x,y,z);
	f3 >> x >> y >> z;
	cam.vup = vec3(x,y,z);
	// Renderizamos la imagen de la escena
	cam.render(world);
	f3.close();
	return 0;
}
