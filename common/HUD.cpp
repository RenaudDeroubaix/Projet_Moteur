#include "HUD.hpp"


void RenderText(GLuint programID, GLuint VAO, GLuint VBO, std::map<GLchar, Character>& Characters, std::string text, float x, float y, float scale, glm::vec3 color) {
    glUniform3f(glGetUniformLocation(programID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

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

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}



void Hud::renderHUD(int SCREEN_WIDTH, int SCREEN_HEIGHT, Camera* camera) {

    // Rendu du HUD
    // Dans cet exemple, affichez l'heure en bas à droite
   /* time_t t = time(0);
    struct tm *now = localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", now);

    float textScale = 0.5f;
    float textX = SCREEN_WIDTH - 150.0f; // Décaler de 150 pixels depuis la droite
    float textY = 50.0f; // Décaler de 50 pixels depuis le bas

    renderText(buffer, textX, textY, textScale);*/
            // Activer le programme de shaders
        // Activer le programme de shaders
    std::cout << "render HUD ..." << std::endl;
     
    glUseProgram(programID);

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCREEN_WIDTH), 0.0f, static_cast<float>(SCREEN_HEIGHT));
    GLint projectionLoc = glGetUniformLocation(programID, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    RenderText(programID, VAO, VBO, Characters, "Oren mange mon groin", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
    RenderText(programID, VAO, VBO, Characters, "Ca fonctionne", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));

    // Désactiver le programme de shaders
    glUseProgram(0);

    std::cout << "render HUD OFF" << std::endl;
}