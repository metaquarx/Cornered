// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#include <SFML/Graphics.hpp>
#include <Cornered/RoundRect.hpp>

int main() {
	sf::ContextSettings ctx;
	ctx.antialiasingLevel = 8;

    sf::RenderWindow window{{600, 400}, "RoundRect", sf::Style::Default, ctx};
    window.setVerticalSyncEnabled(true);

    crd::RoundRect rr{{300, 200}, 50};
    rr.setFillColor(sf::Color::White);
    rr.setPosition({150, 100});

    while (window.isOpen()) {
        for (sf::Event event{}; window.pollEvent(event); ) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(rr);
        window.display();
    }
}
