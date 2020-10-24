//
//  Triangle.h
//  testglfw
//
//  Created by Dev on 2020-10-24.
//  Copyright © 2020 Syritx. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

float vertices[] = {
   0.0f,  0.5f,  0.0f,
   0.5f, -0.5f,  0.0f,
  -0.5f, -0.5f,  0.0f
};

const char* vertexShaderSource =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
"}";

const char* fragmentShaderSource =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.45, 0.0, 0.75, 1.0);"
"}";

#endif /* Triangle_h */
