# SPDX-FileCopyrightText: 2023 metaquarx <metaquarx@protonmail.com>
# SPDX-License-Identifier: Apache-2.0

add_executable(RoundRect
	"RoundRect.cpp"
)
target_link_libraries(RoundRect PRIVATE Cornered)

add_executable(Squircle
	"Squircle.cpp"
)
target_link_libraries(Squircle PRIVATE Cornered)
