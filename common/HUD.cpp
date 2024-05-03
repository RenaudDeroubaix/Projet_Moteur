#include "HUD.hpp"


void Hud::renderText(const char *text, float x, float y, float scale) {
    // Initialisation de FreeType
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        std::cerr << "Erreur: Impossible d'initialiser FreeType" << std::endl;
        return;
    }

    // Chargement de la police
    FT_Face face;
    if (FT_New_Face(ft, "../src/font/bebas-neue/BebasNeue-Regular.ttf", 0, &face)) {
        std::cerr << "Erreur: Impossible de charger la police" << std::endl;
        return;
    }

    // Configuration de la taille de la police
    FT_Set_Pixel_Sizes(face, 0, 48);

    // Configuration de la position et de la taille du texte
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2f(x, y);

    // Rendu du texte caractère par caractère
    for (const char *p = text; *p; p++) {
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER)) {
            std::cerr << "Erreur: Impossible de charger le glyphe '" << *p << "'" << std::endl;
            continue;
        }
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        float x2 = x + face->glyph->bitmap_left * scale;
        float y2 = y - face->glyph->bitmap_top * scale;
        float w = face->glyph->bitmap.width * scale;
        float h = face->glyph->bitmap.rows * scale;

        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x2, y2);
        glTexCoord2f(0, 1); glVertex2f(x2, y2 + h);
        glTexCoord2f(1, 1); glVertex2f(x2 + w, y2 + h);
        glTexCoord2f(1, 0); glVertex2f(x2 + w, y2);
        glEnd();

        x += (face->glyph->advance.x >> 6) * scale;
    }

    // Libération des ressources FreeType
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

}

void Hud::renderHUD(int SCREEN_WIDTH) {
    // Rendu du HUD
    // Dans cet exemple, affichez l'heure en bas à droite
    time_t t = time(0);
    struct tm *now = localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", now);

    float textScale = 0.5f;
    float textX = SCREEN_WIDTH - 150.0f; // Décaler de 150 pixels depuis la droite
    float textY = 50.0f; // Décaler de 50 pixels depuis le bas

    renderText(buffer, textX, textY, textScale);
}