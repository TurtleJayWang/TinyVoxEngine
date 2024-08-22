#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include <CL/opencl.h>

class RendererFactory
{
public:

    RendererFactory();

    ~RendererFactory();

    Renderer* createRenderer();

private:

    cl_context context;

    cl_platform_id platformID;

    cl_device_id deviceGPU;

    cl_command_queue queue;

};

class Renderer
{
public:

    friend class RendererFactory;

    ~Renderer();

    virtual void render() = 0;

protected:

    Renderer();

    void bindProgram(const char* programFileName);

    cl_context context;

    cl_platform_id platformID;

    cl_device_id deviceGPU;

    cl_program program;

};
