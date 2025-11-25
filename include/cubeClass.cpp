# include "cubeClass.hpp"

cube::cube(){}

cube::cube(interval _x, interval _y, interval _z, shared_ptr<material> &m){
	x = _x; y = _y; z = _z; mat = m;
}

bool cube::hit(const ray& r, interval t, hit_record &rec) const {
	double txlow = min((x.min - r.origin.x()) / r.direction.x(), (x.max - r.origin.x()) / r.direction.x());
	double txhigh = max((x.min - r.origin.x()) / r.direction.x(), (x.max - r.origin.x()) / r.direction.x());
	double tylow = min((y.min - r.origin.y()) / r.direction.y(), (y.max - r.origin.y()) / r.direction.y());
	double tyhigh = max((y.min - r.origin.y()) / r.direction.y(), (y.max - r.origin.y()) / r.direction.y());
	double tzlow = min((z.min - r.origin.z()) / r.direction.z(), (z.max - r.origin.z()) / r.direction.z());
	double tzhigh = max((z.min - r.origin.z()) / r.direction.z(), (z.max - r.origin.z()) / r.direction.z());
	double tclose = max(txlow,tylow);
	tclose = max(tclose, tzlow);
	double tfar = min(txhigh,tyhigh);
	tfar = min(tfar, tzhigh);
	if(tfar < tclose || !t.surrounds(tclose)) return false;
	rec.t = tclose;
	rec.p = r.at(rec.t);
	rec.mat = mat;
	vec3 out_normal = vec3(1.0f,0.0f,0.0f);
	if(tclose == tylow) out_normal = vec3(0.0f,1.0f,0.0f);
	if(tclose == tzlow) out_normal = vec3(0.0f,0.0f,1.0f);
	rec.set_face_normal(r, out_normal);
	return true;

}
