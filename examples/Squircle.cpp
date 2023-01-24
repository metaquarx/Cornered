// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#include <SFML/Graphics.hpp>
#include <Cornered/RoundRect.hpp>
#include <Cornered/Squircle.hpp>

int main() {
	sf::ContextSettings ctx;
	ctx.antialiasingLevel = 8;

    sf::RenderWindow window{{1000, 1000}, "Squircle", sf::Style::Default, ctx};
    window.setVerticalSyncEnabled(true);

    crd::RoundRect rr{{800, 800}, 216};
    rr.setFillColor(sf::Color(252, 227, 3));
    rr.setOrigin(400, 400);
    rr.setPosition(500, 500);

    crd::Squircle sq{400};
    sq.setFillColor(sf::Color(252, 177, 3));
    sq.setPosition(500, 500);

    while (window.isOpen()) {
        for (sf::Event event{}; window.pollEvent(event); ) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(rr);
        window.draw(sq);
        window.display();
    }
}
