#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "../utils/sdlUtils.h"
#include "../main/input.h"
#include "../main/game.h"
#include "../main/ghost.h"
#include "../main/pacman.h"
#include "../graphics/gameGraphics.h"
#include "../graphics/footerGraphics.h"
#include "../graphics/headerGraphics.h"
#include "../graphics/mainMenuGraphics.h"


void initGraphics();
void destroyGraphics();
void graphicsHandler();

#endif