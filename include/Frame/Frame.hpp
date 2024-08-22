#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

class Frame
{
public:

    Frame(int width, int height, int channel = 3);

    void drawPoint();

    void drawImage(uint8_t* data, int offsetX, int offsetY, int width, int height, int channel);

    GLuint genGLTexture();

private:

    uint8_t frameData;

    int _width, _height, _channel;

};
