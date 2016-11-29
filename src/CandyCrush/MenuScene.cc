/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#include "MenuScene.hh"
#include "System.hh"
#include "Logger.hh"
using namespace Logger;


MenuScene::MenuScene(void) : playButton(SCREEN_WIDTH/2, SCREEN_HEIGHT /4, SCREEN_WIDTH*0.27f, SCREEN_HEIGHT*0.12f, string("Play")), exitButton(SCREEN_WIDTH/2, SCREEN_HEIGHT /2, SCREEN_WIDTH*0.27f, SCREEN_HEIGHT*0.12f, string("Exit")) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_01 };
}

MenuScene::~MenuScene(void) {
}

void MenuScene::OnEntry(void) {
}

void MenuScene::OnExit(void) {
}

void MenuScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
	}
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");
	if(playButton.ClickButton(mouseCoords.x, mouseCoords.y)) SM.SetCurScene<GameScene>();
	if (exitButton.ClickButton(mouseCoords.x, mouseCoords.y)) exit(0);
}

void MenuScene::Draw(void) {
	m_background.Draw(); // Render background
	playButton.Draw();
	exitButton.Draw();
}