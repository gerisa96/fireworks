/*
 * Swarm.h
 *
 *  Created on: 6 Nov 2018
 *      Author: geri
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace geri {

class Swarm {
public:
	const static int NPARTICLES = 4500;

private:
	Particle *m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles() {return m_pParticles;};
};

} /* namespace geri */

#endif /* SWARM_H_ */
