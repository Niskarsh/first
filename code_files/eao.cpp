#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

const char* vertexShaderSource = "#version 330 core\n layout (location =0) in vec3 aPos;void main () { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
const char* fragmentShaderSource = "#version 330 core\nout vec4 FragColor;void main () { FragColor = vec4(1.0f, 1.0f, .5f, 1.0f); }";
void windowResize (GLFWwindow* window, int width, int height);
void processInput (GLFWwindow* window, int key, int scancode, int action, int mods);

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

    //making sure glad is loaded
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      cout << "Failed to initialize GLAD" << endl;
      return -1;
    }

    float vertices[] = {
        0.0f, .5f, 0.0f,
        .5f, -.5f, 0.0f,
        -.5f, -.5f, 0.0f 
    };

    unsigned int vao, vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), 0);


    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

      int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //bind and combine fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //create a shader program and link shaders to it
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // glUseProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glfwSetFramebufferSizeCallback(window, windowResize);
    glfwSetKeyCallback(window, processInput);

    glViewport(0, 0, 800, 600);

    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    glfwTerminate();   

    return 0;
}

void windowResize (GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);

    }
}