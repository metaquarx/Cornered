// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <SFML/Graphics/Shape.hpp>

namespace crd {

class Squircle : public sf::Shape {
public:
	Squircle(float radius, float n = 4, std::size_t resolution = 20);

	void setRadius(float radius);
	float getRadius() const;

	void setN(float p);
	float getN() const;

	void setResolution(std::size_t resolution);
	std::size_t getResolution() const;

	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;

private:
	float m_radius;
	float m_n;
	std::size_t m_resolution;
};

} // namespace crd
