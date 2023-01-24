// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#include "Cornered/RoundRect.hpp"

#include <cmath>

namespace crd {

RoundRect::RoundRect(sf::Vector2f size, float radius)
: m_size(size)
, m_radius(radius) {
	update();
}

void RoundRect::setSize(sf::Vector2f size) {
	m_size = size;
	update();
}

sf::Vector2f RoundRect::getSize() const {
	return m_size;
}

void RoundRect::setRadius(float radius) {
	m_radius = radius;
	update();
}

float RoundRect::getRadius() const {
	return m_radius;
}

namespace {
	static constexpr std::size_t corner_points = 16;
	static constexpr float pi = 3.141592654;
} // namespace

std::size_t RoundRect::getPointCount() const {
	return corner_points * 4;
}

sf::Vector2f RoundRect::getPoint(std::size_t index) const {
	float da = 90.f / (corner_points - 1);
	auto centre_i = index / corner_points;

	sf::Vector2f centre{centre_i == 1 || centre_i == 2 ? m_radius : m_size.x - m_radius,
						centre_i == 0 || centre_i == 1 ? m_radius : m_size.y - m_radius};

	return {m_radius * std::cos(da * (index - centre_i) * pi / 180) + centre.x,
		   -m_radius * std::sin(da * (index - centre_i) * pi / 180) + centre.y};
}

} // namespace crd
