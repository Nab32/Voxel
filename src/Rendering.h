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
#include <cstdlib>
#include <random>
#include <noise/noise.h>
#include "constant.h"

class Rendering {
    public:
        Rendering();
        void render();
        void init();
        void renderFrame();
        static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
    private:
        float* test;
        unsigned int VAO, VBO;
        glm::mat4 _projection;
        Scene* scene;
        static Camera* camera;
        Shader* _shader;
        Window* _window;
};