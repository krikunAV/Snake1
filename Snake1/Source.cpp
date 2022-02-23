/*#include "Source.h"
#include <iostream>
#include <windows.h>
#include <cmath>
#include <SFML/Window.hpp>

bool inGame;
const int size = 320;
const int dotSize = 16;
const int square = 400;
const int width = 20;
const int height = 20;
int x, y;
int appleX, appleY;
int point;
enum eDirect { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirect dir;

using namespace std;
namespace kk {

	void setup() {
		inGame = true;
		x = width / 2;
		y = height;
		appleX = rand() % 20;
		appleY = rand() % 20;
		point = 0;
		sf::Window window(sf::VideoMode(width * dotSize, height * dotSize), "My window", sf::Style::Close);
	}
	void draw() {

	}
	void input() {

	}
	void logic() {

	}
}*/