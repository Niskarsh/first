#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

const char* vertexShaderSource = "#version 330 core\n layout (location =0) in vec3 aPos;void main () { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
const char* fragmentShaderSource = "#version 330 core\nout vec4 FragColor;void main () { FragColor = vec4(1.0f, 1.0f, .5f, 1.0f); }";
void windowResize (GLFWwindow* window, int width, int height);



int main ()
{
  
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //Making window object
  GLFWwindow* window = glfwCreateWindow(800, 600, "First", NULL, NULL);
  if (window==NULL) {
    cout << "window creation failed\n" << endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, windowResize);

  //making sure glad is loaded
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cout << "Failed to initialize GLAD" << endl;
    return -1;
  }

  //start rendering
  glViewport(100, 100, 800, 600);

  //bind and combine vertex shader
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

  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);

  glBindVertexArray(VAO);

  

  //create object for vertices data buffer
  unsigned int dataBuffer;
  glGenBuffers(1, &dataBuffer);

  //bind object to dataBuffer
  glBindBuffer(GL_ARRAY_BUFFER, dataBuffer);

  //push data
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //render loop to keep window open
  while (!glfwWindowShouldClose(window)) {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    //swapping next draw buffer
    glfwSwapBuffers(window);
    //invokes respective callbacks
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}

void windowResize (GLFWwindow* window, int width, int height) {
  glViewport(100, 100, width, height);
}

