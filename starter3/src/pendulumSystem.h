#ifndef PENDULUMSYSTEM_H
#define PENDULUMSYSTEM_H

#include "extra.h"
#include <vector>

#include "particleSystem.h"

class PendulumSystem: public ParticleSystem
{
public:
	PendulumSystem(int numParticles);
	
	vector<Vector3f> evalF(vector<Vector3f> state);
	
	// getter method for the pendulum system's springs
	vector<vector<Vector3f>> getSprings(){ return springs; };

	// setter method for the pendulum system's springs
	void setSprings(const vector<vector<Vector3f>>  &newSprings) { springs = newSprings; };

	void draw();

private:
	vector<vector<Vector3f>> springs;
};

#endif
