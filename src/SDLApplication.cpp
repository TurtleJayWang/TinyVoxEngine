#define COMMON_IMPL
#include <SDLApplication.hpp>

void SDLApplication::Loop()
{
    while (_running)
    {
        while (SDL_PollEvent(&_event))
        {
            switch (_event.type)
            {
            case SDL_QUIT: 
                _running = false;
                break;
            case SDL_WINDOWEVENT:
                switch (_event.window.event)
                {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    _width = _event.window.data1, _height = _event.window.data2;
                    WindowResize(_width, _height);
                    break;
                }
            }
        }

        auto clearMask = GL_COLOR_BUFFER_BIT;

        glClear(clearMask);
        glClearColor(0.3f, 0.4f, 0.4f, 1.0f);

        Update();
    }
}

void SDLApplication::CreateSDLWindow(const char* title, int width, int height, int flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    _width = width, _height = height;

    _window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, 
        flags
    );
    if (nullptr == _window)
    {
        log << "Failed to create window" << std::endl;
        log.print();
    }
    else
    {
        log << "Window created successfully" << std::endl;
        log.print();
    }

    _GLContext = SDL_GL_CreateContext(_window);
    if (nullptr == _GLContext)
    {
        log << "Failed to create OpenGL context" << std::endl;
        log.print();
    }
    else 
    {
        log << "OpenGL created successfully" << std::endl;
        log.print();
    }

    if (GLEW_OK != glewInit())
    {
        log << "Failed to initialize GLEW" << std::endl;
        log.print();
    }
    else 
    {
        log << "GLEW initialized successfully" << std::endl;
        log.print();
    }
}

SDLApplication::~SDLApplication()
{
    SDL_DestroyWindow(_window);
    SDL_GL_DeleteContext(_GLContext);
}

void SDLApplication::SetBackgroundColor(float r, float g, float b)
{
    bgR = r, bgG = g, bgB = b;
}
