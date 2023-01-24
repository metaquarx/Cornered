// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <SFML/Graphics/Shape.hpp>

namespace crd {

class RoundRect : public sf::Shape {
public:
	RoundRect(sf::Vector2f size = {0, 0}, float radius = 0);

	void setSize(sf::Vector2f size);
	sf::Vector2f getSize() const;

	void setRadius(float radius);
	float getRadius() const;

	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;

private:
	sf::Vector2f m_size;
	float m_radius;
};

} // namespace crd
