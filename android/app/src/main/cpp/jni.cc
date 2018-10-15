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
// ---
// Author: olliwang@ollix.com (Olli Wang)

#include <jni.h>

#include "moui/moui.h"

extern "C" {

JNIEXPORT void
JNICALL
Java_com_ollix_nanovg_MainActivity_inithMouiAppFromJNI(
    JNIEnv *env, jobject, jobject activity, jobject asset_manager) {
  moui::Application::InitJNI(env, activity, asset_manager);
  moui_main();
}

JNIEXPORT void
JNICALL
Java_com_ollix_nanovg_MainActivity_deleteApplicationFromJNI(
    JNIEnv *env, jobject) {
  auto moui_app = moui::Application::GetMainApplication();
  if (moui_app != nullptr) {
    delete moui_app;
  }
  moui::Application::ResetMainApplication();
}

}  // extern "C"
