/* Copyright 2010 Ilkka Halila
This file is part of Goblin Camp.

Goblin Camp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Goblin Camp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with Goblin Camp. If not, see <http://www.gnu.org/licenses/>.*/
#pragma once

#include <libtcod.hpp>
#include "MapRenderer.hpp"
#include <SDL.h>
#include <boost/multi_array.hpp>

enum TileType;

class SDLMapRenderer : public MapRenderer, public ITCODSDLRenderer
{
public:
	SDLMapRenderer(int screenWidth, int screenHeight);
	~SDLMapRenderer();

	void DrawMap(TCODConsole * console, Map* map, Coordinate upleft, int posX = 0, int posY = 0, int sizeX = 0, int sizeY = 0) ;
	void render(void *sdlSurface);
private:
	// the font characters size
	int tileWidth, tileHeight, screenWidth, screenHeight;
	SDL_Surface *mapSurface;
	SDL_Surface *tempBuffer;
	SDL_Surface *tiles;
	TCODColor keyColor;
	bool first;

	void DrawTile(Map* map, int tileX, int tileY, SDL_Rect * dstRect);
	void DrawWater(Map* map, int tileX, int tileY, SDL_Rect * dstRect);
	void DrawFilth(Map* map, int tileX, int tileY, SDL_Rect * dstRect);
	void DrawTerritoryOverlay(Map* map, int tileX, int tileY, SDL_Rect * dstRect);

	void DrawMarkers(Map * map, Coordinate upleft, int posX, int posY, int sizeX, int sizeY);
};