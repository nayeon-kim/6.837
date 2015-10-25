#include "TimeStepper.h"
#include <iostream>
///TODO: implement Explicit Euler time integrator here
void ForwardEuler::takeStep(ParticleSystem* particleSystem, float stepSize)
{	
	vector<Vector3f> currentState = particleSystem->getState();
	vector<Vector3f> derivatives = particleSystem->evalF(currentState);
	vector<Vector3f> newState;

	for( int i = 0; i < derivatives.size(); i++ ) {
		newState.push_back(currentState[i] + stepSize * derivatives[i]);
	}
	particleSystem->setState(newState);
}

///TODO: implement Trapzoidal rule here
void Trapzoidal::takeStep(ParticleSystem* particleSystem, float stepSize)
{
	vector<Vector3f> currentState = particleSystem->getState();
	vector<Vector3f> fzero = particleSystem->evalF(currentState);

	vector<Vector3f> tempState;
	for( int i = 0; i < fzero.size(); i++ ) {
		tempState.push_back(currentState[i] + stepSize*fzero[i]);
	}
	vector<Vector3f> fone = particleSystem->evalF(tempState);

	vector<Vector3f> newState;
	for( int j = 0; j < fzero.size(); j++ ) {
		newState.push_back(currentState[j] + (stepSize/2)*(fzero[j]+fone[j]));
	}
	particleSystem->setState(newState);
}
