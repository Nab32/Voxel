#include "Rendering.h"


float lastX = width / 2.0f;
float lastY = height / 2.0f;
bool firstMouse = true;

Camera* Rendering::camera = new Camera(glm::vec3(0.0f, 4.0f, 15.0f));

//This is the constructor for the Rendering class
//The constructor initializes GLFW and GLAD
//Params: none
//returns: none
Rendering::Rendering(){
    init();
    _shader = new Shader("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/shaders/vertexShader.glsl", "C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/shaders/fragmentShader.glsl");
    _projection = glm::perspective(glm::radians(FOV), (float)width / (float)height, NEAR_PLANE, FAR_PLANE);
    scene = new Scene(_shader);
    scene->createCube();
    scene->generateModels();
    glEnable(GL_DEPTH_TEST);
}

void Rendering::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;
   
    camera->ProcessMouseMovement(xoffset, yoffset);
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

    _window = Window::getInstance(width, height, "Voxel Engine");

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
    glfwSetCursorPosCallback(_window->getWindow(), mouse_callback);
    glfwSetInputMode(_window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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
    _window->changeBGColor(0.4f, 0.3f, 0.3f, 1.0f);
    _window->commonInputs();
    camera->cameraInputs(_window->getWindow());
    glClear(GL_DEPTH_BUFFER_BIT);
    _shader->use();
    _shader->setMat4("view", camera->getView());
    _shader->setMat4("projection", _projection);

    std::vector<Model> models = scene->getModels();
    for (int i = 0; i < models.size(); i++) {
        models[i].render();
    }

    
    _window->swapBuffers();
    _window->pollEvents();
}