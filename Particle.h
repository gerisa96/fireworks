/*
 * Particle.h
 *
 *  Created on: 6 Nov 2018
 *      Author: geri
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace geri {

struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;
private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace geri */

#endif /* PARTICLE_H_ */
