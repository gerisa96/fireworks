#include <iostream>
#include "SDL2/SDL.h"
#include <math.h>
#include <string.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace geri;

int main(int argc, char *argv[]) {

	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL!" << endl;
	}

	Swarm swarm;

	while (true) {
		//Update particles
		//Draw particles
		int elapsed = SDL_GetTicks();


		swarm.update(elapsed);

		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char red = (1 + cos(elapsed * 0.0001)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0001)) * 128;

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the screen
		screen.update();

		//Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	//cout << "Max: " << max << endl;
	screen.close();

	return 0;
}
