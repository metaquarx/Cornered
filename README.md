<!-- SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
SPDX-License-Identifier: Apache-2.0 -->

## Cornered

Rounded rectangles & superellipse-based squircle for the SFML library

![A screenshot showing the shape difference between a rounded square and a squircle](./assets/thumbnail.png?raw=true "A yellow rounded square, and an orange Squircle")

### Usage

This library provides 2 `sf::Drawable` objects: `crd::RoundRect` and `crd::Squircle`.

The APIs used are almost identical to [SFML's RectangleShape](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php) except for a few differences:

```cpp
#include <Cornered/RoundRect.hpp>
#include <Cornered/Squircle.hpp>

crd::RoundRect my_rectangle({100.f, 100.f}, 10.f); // Rounded rectangle, 100x100, with radius 10 corners
assert(my_rectangle.getRadius() == 10.f); // get corner radius
my_rectangle.setRadius(20.f); // set corner radius to 20

crd::Squircle my_squircle(50.f); // Squircle with radius 50
my_squircle.setResolution(50); // increase the resolution of the squircle - more points, smoother curves
my_squircle.setN(5.f);
```

The `n`-value of the squircles defines its shape. Find out more [here](https://en.wikipedia.org/wiki/Superellipse).

### Adding to your project

If you're using the CMake (eg through the [official sfml template](https://github.com/SFML/cmake-sfml-project)), you can also use it for this repo!

Simply add the following to your `CMakeLists.txt` file:

```cmake
FetchContent_Declare(Cornered
    GIT_REPOSITORY https://github.com/metaquarx/Cornered.git
    GIT_TAG 1.0.0)
FetchContent_MakeAvailable(Cornered)

target_link_libraries(YOUR_PROJECT_NAME PRIVATE Cornered)
```
