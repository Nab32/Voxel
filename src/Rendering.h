#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Scene.h"
#include "Shader.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "constant.h"


class Rendering {
    public:
        Rendering();
        void render();
        void init();
        void renderFrame();
    private:
        glm::mat4 _projection;
        Scene* scene;
        Camera camera;
        Shader* _shader;
        Window* _window;
};