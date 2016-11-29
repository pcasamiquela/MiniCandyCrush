#include "Button.hh"
#pragma once

Button::~Button()
{
}

bool Button::ClickButton(float mousePositionX, float mousePositionY)
{
	if (mousePositionX >= positionX && mousePositionX <= positionX + sizeX && mousePositionY >= positionY && mousePositionY <= positionY+sizeY) return true;
	return false;
}

void Button::Draw(){
	newButton.Draw();
	GUI::DrawTextBlended<FontID::CANDY>(text,
	{ positionX+sizeX/2, positionY+sizeY/2, 1, 1 },
	{ 115, 0, 180 });
}
