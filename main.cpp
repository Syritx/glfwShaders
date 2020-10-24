#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "TriangleProperties.h" // custom header

GLuint createShader(const char* source, GLuint type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader,1,&source,NULL);
    glCompileShader(shader);
    
    return shader;
}

int main() {
    if (!glfwInit()) glfwTerminate();

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(1000, 720, "Test", NULL, NULL);
    if (!window) glfwTerminate();
    
    glfwMakeContextCurrent(window);
                                  
    glewExperimental = GL_TRUE;
    glewInit();
    glEnable(GL_DEPTH_TEST);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // the vertices variable can be found in TriangleProperties.h
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // vertexShaderSource and fragmentShaderSource can be found in TriangleProperties.h
    GLuint vertexShader = createShader(vertexShaderSource, GL_VERTEX_SHADER),
           fragmentShader = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    
    GLuint program = glCreateProgram();
    glAttachShader(program, fragmentShader);
    glAttachShader(program, vertexShader);
    glLinkProgram(program);
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUseProgram(program);
        glBindVertexArray(vao);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
