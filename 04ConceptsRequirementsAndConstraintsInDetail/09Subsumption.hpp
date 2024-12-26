#pragma once
#include <concepts>

struct Color {};

class Test
{
public:
	int widgth() const {}
	int heigth() const {}

	void draw() {}

	void set_color(Color color) {}
	Color get_color() const {}
};


template<typename T>
concept geo_object = requires(T obj)
{
	{ obj.width() } -> std::integral;
	{ obj.height() } -> std::integral;
	obj.draw();
};

template<typename T>
concept colored_geo_objects =
	geo_object<T> &&
	requires(T obj) {	
	obj.set_color(std::declval<Color>());
	{ obj.get_color() } -> std::convertible_to<Color>;
	};

void for_main()
{

}