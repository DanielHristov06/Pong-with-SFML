#include "SFML/Graphics.hpp"

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Window", sf::Style::Default);

	sf::Event e;

	while (window.isOpen()) {

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	return 0;
}