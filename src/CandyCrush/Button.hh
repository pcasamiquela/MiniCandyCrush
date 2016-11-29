#pragma once
#include "Sprite.hh"
#include "GUI.hh"

using namespace std;

class Button {
	int positionX, positionY, sizeX, sizeY;
	Sprite newButton;
	string text;
public:

	Button(int _positionX, int _positionY, int _sizeX, int _sizeY, string _text) : sizeX(_sizeX), sizeY(_sizeY), text(_text) {
		positionX = _positionX - sizeX / 2;
		positionY = _positionY - sizeY / 2;
		newButton = { { positionX, positionY, sizeX, sizeY }, ObjectID::BUTTON };

	};
	~Button();
	bool ClickButton(float mousePositionX, float mousePositionY);
	void Draw();

};