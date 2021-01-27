#include "fontManager.h"

fontManager::fontManager()
{

    fontM = GRRLIB_LoadTTF(font_ttf, font_ttf_size);

}

fontManager::~fontManager()
{

}
