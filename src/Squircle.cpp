// SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
// SPDX-License-Identifier: Apache-2.0

#include "Cornered/Squircle.hpp"

#include <cmath>

namespace crd {

Squircle::Squircle(float radius, float n, std::size_t resolution)
: m_radius(radius)
, m_n(n)
, m_resolution(resolution) {
	update();
}

void Squircle::setRadius(float radius) {
	m_radius = radius;
	update();
}

float Squircle::getRadius() const {
	return m_radius;
}

void Squircle::setN(float p) {
	m_n = p;
	update();
}

float Squircle::getN() const {
	return m_n;
}

void Squircle::setResolution(std::size_t resolution) {
	m_resolution = resolution;
	update();
}

std::size_t Squircle::getResolution() const {
	return m_resolution * 4;
}

namespace {
	static constexpr float pi = 3.141592654;

	static constexpr float map(float value, float a, float b, float c, float d) {
		return (value - a) / (b - a) * (d - c) + c;
	}

	static constexpr float sign(float value) {
		if (value > 0) return 1;
		if (value < 0) return -1;
		return 0;
	}
} // namespace

std::size_t Squircle::getPointCount() const {
	return m_resolution * 4;
}

sf::Vector2f Squircle::getPoint(std::size_t index) const {
	auto local = index % (m_resolution * 2);
	// to go clockwise around the whole shape, flip the bottom half
	auto bottom = (index >= m_resolution * 2) ? -1.f : 1.f;

	auto x = map(local, 0, m_resolution * 2, -1, 1);
	// cubic easing function: dedicate more vertices to the corners
	x = (1 - std::pow(1 - std::abs(x), 3)) * sign(x) * bottom;
	x = map(x, -1, 1, -m_radius, m_radius);

	auto y = m_radius * std::pow(1.f - std::pow(std::abs(x / m_radius), m_n), 1.f / m_n);

	return {x, y * bottom};
}

} // namespace crd
