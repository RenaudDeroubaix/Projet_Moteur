#pragma once
#include <ft2build.h>
#include FT_FREETYPE_H
#include "common/utils.hpp"

class Hud {
private:
    GLuint programID;
public:
    Hud(GLuint pID): programID(pID) {}

    ~Hud() {}

    void renderHUD(int SCREEN_WIDTH);
    void renderText(const char *text, float x, float y, float scale);
};