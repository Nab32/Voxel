#include "Rendering.h"


//This is the constructor for the Rendering class
//The constructor initializes GLFW and GLAD
//Params: none
//returns: none
Rendering::Rendering(){
    init();
}


//This function initializes GLFW and GLAD
//Params: none
//returns: none
void Rendering::init(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    _window = Window::getInstance(_width, _height, "Voxel Engine");

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    std::cout << "Everything initialized correctly" << std::endl;
}


//This function renders the scene
//Params: none
//returns: none
void Rendering::render(){
    while (!_window->isClosed()){
        renderFrame();
    }
}


//This function renders a frame
//Params: none
//returns: none
void Rendering::renderFrame(){
    _window->changeBGColor(0.9f, 0.3f, 0.3f, 1.0f);
    _window->swapBuffers();
    _window->pollEvents();
}