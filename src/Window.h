#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    public:
        Window(const Window&) = delete;
        static Window* getInstance(const unsigned int width, const unsigned int height, const char* title);
        GLFWwindow* getWindow();
        void terminate();
        void pollEvents();
        void swapBuffers();
        int isClosed();
        void changeBGColor(float r, float g, float b, float a);
        void commonInputs();
    private:
        static Window* instancePtr;
        Window(const unsigned int width, const unsigned int height, const char* title);
        GLFWwindow* _window;
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};