
#include "pendulumSystem.h"
#include <iostream>

PendulumSystem::PendulumSystem(int numParticles):ParticleSystem(numParticles)
{
	m_numParticles = numParticles;
	
	// fill in code for initializing the state based on the number of particles
	vector<Vector3f> startState;
	vector<vector<Vector3f>> springs;

	for (int i = 0; i < m_numParticles; i++) {
		// Particles
		// for this system, we care about the position and the velocity
		Vector3f pos = Vector3f(i*0.25f,0.0f,0.0f);
		Vector3f vel = Vector3f(0.0f,0.0f,0.0f);
		startState.push_back(pos);
		startState.push_back(vel);

		// Springs 
		// for each P_i: [P_j, r, k], [P_k, r, k]...
		vector<Vector3f> springInfo;
		float r = 0.2; // rest lengt
		float k = 50; // spring constant - stiffness
		if (i > 0) {
			Vector3f prevSpringInfo = Vector3f((float)i-1,r,k);
			springInfo.push_back(prevSpringInfo);
		}
		if (i < m_numParticles - 1) {
			Vector3f nextSpringInfo = Vector3f((float)i+1,r,k);
			springInfo.push_back(nextSpringInfo);
		}
		springs.push_back(springInfo);
	}
	setState(startState);
	setSprings(springs);
}


// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> PendulumSystem::evalF(vector<Vector3f> state)
{
	vector<Vector3f> f;

	float mass = 2;
	float gConst = -9.8;
	float k = 1; // drag constant
	vector<vector<Vector3f>> springs = getSprings();

	for( int i = 0; i < state.size()/2; i++ ) {
		vector<Vector3f> springInfo = springs[i];
		
		Vector3f netForce;

		Vector3f statePos = state[i*2];
		Vector3f stateVel = state[i*2+1];
		Vector3f newPos = stateVel;
		
		Vector3f newVel;
		// Gravity
		Vector3f gForce = mass * Vector3f(0.0f,gConst,0.0f); // double check values
		// Viscous Drag
		Vector3f dragForce = -k * stateVel;
		
		netForce = gForce + dragForce;

		Vector3f springForce;
		for (int j = 0; j < springInfo.size(); j++) {
			// Spring Forces
			Vector3f otherPos = state[springInfo[j][0]*2];
			Vector3f d = statePos - otherPos;

			springForce = -springInfo[j][2] * (d.abs() - springInfo[j][1]) * (d/d.abs());
			netForce = netForce + springForce;
		}
		newVel = netForce / mass ;
		if (i == 0) {
			// fixed point
			newVel = Vector3f(0.0f,0.0f,0.0f);
		}
		f.push_back(newPos);
		f.push_back(newVel);
	}
	return f;
}

// render the system (ie draw the particles)
void PendulumSystem::draw()
{
	for (int i = 0; i < m_numParticles; i++) {
		vector<Vector3f> state = getState();
		Vector3f pos = state[i*2];//  position of particle i. YOUR CODE HERE
		glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
	}
}
