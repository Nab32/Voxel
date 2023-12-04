#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Scene.h"

class Rendering {
    public:
        Rendering();
        void render();
        void init();
        void renderFrame();
    private:
        Window* _window;
        const unsigned int _width = 800;
        const unsigned int _height = 800;
};