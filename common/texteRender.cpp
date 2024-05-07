#include "texteRender.hpp"


void RenderText(GLuint programID, GLuint VAO, GLuint VBO, std::map<GLchar, Character>& Characters, std::string text, float x, float y, float scale, glm::vec3 color, glm::vec3 outlineColor, float outlineWidth) {
    // Activer le programme et configurer la couleur du texte
    glUseProgram(programID);
    glUniform3f(glGetUniformLocation(programID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    // Rendu du contour du texte
    glUniform3f(glGetUniformLocation(programID, "textColor"), outlineColor.x, outlineColor.y, outlineColor.z);
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) { // Ne pas dessiner le contour sur le texte principal
                float offsetX = dx * outlineWidth;
                float offsetY = dy * outlineWidth;

                // Dessiner chaque caractère avec un décalage pour créer un contour
                float xPos = x + offsetX;
                float yPos = y + offsetY;
                for (auto c = text.begin(); c != text.end(); c++) {
                    Character ch = Characters[*c];

                    float xpos = xPos + ch.Bearing.x * scale;
                    float ypos = yPos - (ch.Size.y - ch.Bearing.y) * scale;

                    float w = ch.Size.x * scale;
                    float h = ch.Size.y * scale;

                    float vertices[6][4] = {
                        { xpos,     ypos + h,   0.0f, 0.0f },
                        { xpos,     ypos,       0.0f, 1.0f },
                        { xpos + w, ypos,       1.0f, 1.0f },
                        { xpos,     ypos + h,   0.0f, 0.0f },
                        { xpos + w, ypos,       1.0f, 1.0f },
                        { xpos + w, ypos + h,   1.0f, 0.0f }
                    };

                    glBindTexture(GL_TEXTURE_2D, ch.TextureID);
                    glBindBuffer(GL_ARRAY_BUFFER, VBO);
                    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

                    glDrawArrays(GL_TRIANGLES, 0, 6);

                    xPos += (ch.Advance >> 6) * scale;
                }
            }
        }
    }

    // Rendu du texte principal
    glUniform3f(glGetUniformLocation(programID, "textColor"), color.x, color.y, color.z);
    for (auto c = text.begin(); c != text.end(); c++) {
        Character ch = Characters[*c];

        float xpos = x + ch.Bearing.x * scale;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;

        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }
        };

        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        x += (ch.Advance >> 6) * scale;
    }

    // Désactiver le VAO et la texture
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    // Désactiver le programme de shaders
    glUseProgram(0);
}




void texteRender::renderTXT(int SCREEN_WIDTH, int SCREEN_HEIGHT,unsigned int cam_i, unsigned int scene_i, unsigned int gameState) {

    // Rendu du texteRender
    // Dans cet exemple, affichez l'heure en bas à droite
    time_t t = time(0);
    struct tm *now = localtime(&t);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", now);

    float textScale = 0.5f;
    float textX = SCREEN_WIDTH / 2.0 - sizeof(buffer)/2.0; // 
    float textY = 50.0f; // Décaler de 50 pixels depuis le bas

    glm::vec3 color_text(0.25f,0.25f,0.25f);
    glm::vec3 color_contour(1.f,1.0f,1.0f);

    // Couleur pour "REC"
    glm::vec3 color_rec(1.0f, 0.0f, 0.0f); // Rouge par défaut
    
    //std::cout << "render texteRender ..." << std::endl;
    glUseProgram(programIDTXT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glDisable(GL_DEPTH_TEST);
    GLint renderModeLocation = glGetUniformLocation(programIDTXT, "renderMode");

    // Set the value of renderMode
    int mode = 0; // 0 for text, 1 for plane
    glUniform1i(renderModeLocation, mode);
    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCREEN_WIDTH), 0.0f, static_cast<float>(SCREEN_HEIGHT));
    GLint projectionLoc = glGetUniformLocation(programIDTXT, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);

    if(gameState == 0 || gameState == 1){
        RenderText(programIDTXT, VAO, VBO, Characters, buffer, textX, textY, textScale, color_text, color_contour,1.0f);
        RenderText(programIDTXT, VAO, VBO, Characters, "CAM  #"+std::to_string(cam_i+1)+" : ROOM " + std::to_string(scene_i), 100.0, SCREEN_HEIGHT - 100.0, 1.f, color_text, color_contour,1.0f);
        RenderText(programIDTXT, VAO, VBO, Characters, "REC", SCREEN_WIDTH -200.0, SCREEN_HEIGHT - 100.0, 1.f, color_rec, color_contour,1.0f);
    }
    else if(gameState == 2){
        RenderText(programIDTXT, VAO, VBO, Characters, "GAMEOVER", 400  , SCREEN_HEIGHT/2.0  , 2.f, color_rec, color_contour,1.0f);
    }


    // Désactiver le programme de shaders
    glUseProgram(0);

    //std::cout << "render texteRender OFF" << std::endl;
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}