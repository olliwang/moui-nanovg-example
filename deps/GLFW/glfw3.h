// Copyright (c) 2017 Olli Wang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This file replaces the true glfw3 header file for supressing compile errors
// when building NanoVG's demo app.
//
// ---
// Author: olliwang@ollix.com (Olli Wang)

#ifndef GLFW_GLFW3_H_
#define GLFW_GLFW3_H_

#define GLint int
#define GL_QUERY_RESULT_AVAILABLE 0
#define GL_UNSIGNED_BYTE 0
#define GL_RGBA 0

void glBeginQuery(int target, int id);
void glEndQuery(int target);
void glGetQueryObjectiv(int id, int pname, int*params);
void glReadPixels(int x, int y, int width, int height, int format, int type,
                  void* data);

#endif  //GLFW_GLFW3_H_
