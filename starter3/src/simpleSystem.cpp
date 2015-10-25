
#include "simpleSystem.h"
#include <iostream>

using namespace std;

SimpleSystem::SimpleSystem()
{	
	vector<Vector3f> startState;
	Vector3f pos = Vector3f(1.0f,1.0f,1.0f);
	startState.push_back(pos);
	setState(startState);
}

// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> SimpleSystem::evalF(vector<Vector3f> state)
{	
	vector<Vector3f> f;
	for( int i = 0; i < state.size(); i++ ) {
		Vector3f statePos = state[i];
		float x = statePos[0];
		float y = statePos[1];

		Vector3f newVec;
		newVec[0] = -1*y;
		newVec[1] = x;
		newVec[2] = 0;
		f.push_back(newVec);
	}
	return f;
}

// render the system (ie draw the particles)
void SimpleSystem::draw()
{
		vector<Vector3f> state = getState();
		Vector3f pos = state[0]; //YOUR PARTICLE POSITION
	  	glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
}
