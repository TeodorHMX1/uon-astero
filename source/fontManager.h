#pragma once

// include external headers
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

// include generated headers
#include "font_ttf.h"

class fontManager
{

public:
    fontManager();

    ~fontManager();

public:
    GRRLIB_ttfFont *fontM;

};