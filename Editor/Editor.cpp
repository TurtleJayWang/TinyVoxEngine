#include <SDLApplication.hpp>

class Application : public SDLApplication
{
public:

    Application();

protected:

    virtual void Update();

    virtual void WindowResize(int width, int height);

};

Application::Application()
{
    CreateSDLWindow("Editor", 1080, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SetBackgroundColor(0.3f, 0.4f, 0.4f);
}

void Application::Update()
{
    
}

void Application::WindowResize(int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
    Application app;
    app.Loop();

    return 0;
}
