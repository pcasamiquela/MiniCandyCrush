/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>

#define WIDTH 1920
#define HEIGHT 1080

int main(int, char*[]) { 
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw SDL_GetError();
		const Uint8 imgFiles = IMG_INIT_PNG | IMG_INIT_PNG;
		if (!(IMG_Init(imgFiles) & imgFiles)) throw IMG_GetError();
		SDL_Log("Executable built in %s", SDL_GetBasePath());
		SDL_Window *window = SDL_CreateWindow("OSCAR MARICA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH,HEIGHT, SDL_WINDOW_SHOWN);
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		//SPRITES
		SDL_Texture *bgTexture = IMG_LoadTexture(renderer, "../../res/gfx/bg.jpg");
		SDL_Texture *playerTexture = IMG_LoadTexture(renderer, "../../res/gfx/blue.png");
		if (bgTexture == nullptr || playerTexture == nullptr) throw IMG_GetError();
		SDL_Rect bgRect = {0,0, WIDTH, HEIGHT};
		SDL_Rect playerRect = { (WIDTH >> 1) - 50,(WIDTH >> 1) - 50, 100, 100};
		SDL_Rect playerTarget = {0,0,100,100};
		//GAME LOOP
		SDL_Event evnt;
		for (bool isRunning = true;isRunning;) {
			while (SDL_PollEvent(&evnt)) {
				switch (evnt.type) {
					case SDL_QUIT: isRunning = false; break;
					case SDL_MOUSEMOTION: playerTarget.x = evnt.motion.x - 50; playerTarget.y = evnt.motion.y - 50; break;
					default:;
				}
			}
			//UPDATE
			playerRect.x += (playerTarget.x - playerRect.x)*0.1f;
			playerRect.y += (playerTarget.y - playerRect.y)*0.1f;

			//DRAW
			SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);
			SDL_RenderCopy(renderer, playerTexture, nullptr, &bgRect);
			SDL_RenderPresent(renderer);
		}


		//DESTROY
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}
	catch (const char *msg) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", msg);
	}
	IMG_Quit();
	SDL_Quit();
	return 0;
}