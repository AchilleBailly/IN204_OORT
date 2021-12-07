#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Representation.hpp"
#include "Engine.hpp"
#include <string>

std::string ressources_path = "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int main()
{
    load_from_json(ressources_path + "/test_object.json");
    return 0;
}
