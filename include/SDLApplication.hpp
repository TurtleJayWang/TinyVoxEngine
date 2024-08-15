#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include <Common.hpp>

class SDLApplication
{
public:

    ~SDLApplication();

    void Loop();

protected:

    void CreateSDLWindow(const char* windowTitle, int width, int height, int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    virtual void Update() = 0;

    virtual void WindowResize(int width, int height) {}

    void SetBackgroundColor(float r, float g, float b);

private:

    SDL_Window* _window = nullptr;

    SDL_GLContext _GLContext = nullptr;

    SDL_Event _event;

    float bgR, bgG, bgB;

    bool _running = true;

    int _width, _height;

    enum WindowType { SDL } windowType;

    Log log;

};
