#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

const char* vertexShaderSource = "#version 330 core\n layout (location =0) in vec3 aPos;void main () { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
const char* fragmentShaderSource = "#version 330 core\nout vec4 FragColor;void main () { FragColor = vec4(1.0f, 1.0f, .5f, 1.0f); }";

int main () {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "ELEMENT ARRAY OBJECTS", NULL, NULL);
    if(window==NULL) {
        std::cout << "window creation failed you dickward" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(100, 100, 800, 600);
    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    glfwTerminate();   

    return 0;
}

