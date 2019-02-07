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

#include "app/application.h"

#include "moui/moui.h"

#include "app/demo_view.h"

namespace app {

Application::Application() : demo_view_(nullptr), widget_view_(nullptr) {
}

Application::~Application() {
  DestroyUserInterface();
}

void Application::DestroyUserInterface() {
  if (demo_view_ != nullptr) {
    moui::Widget::SmartRelease(demo_view_);
    demo_view_ = nullptr;
  }
  if (widget_view_ != nullptr) {
    widget_view_->RemoveFromSuperview();
    delete widget_view_;
    widget_view_ = nullptr;
  }
}

void Application::LaunchUserInterface() {
  if (widget_view_ != nullptr) {
    return;
  }

  auto window = moui::Window::GetMainWindow();
  auto native_root_view = window->GetRootView();

  // Creates a `WidgetView` object and adds it to the native root view.
  // Creates the root widget view.
  const int kContextFlags = moui::nvgContextFlags(true,  // antialias
                                                  false,  // stencil strokes
                                                  3);  // triple buffering
  widget_view_ = new moui::WidgetView(kContextFlags);
  widget_view_->SetBounds(0, 0, native_root_view->GetWidth(),
                          native_root_view->GetHeight());
  native_root_view->AddSubview(widget_view_);

  // Creates a root widget and adds it to the widget view.
  demo_view_ = new DemoView();
  widget_view_->root_widget()->set_background_color(nvgRGBf(0, 0, 0));
  widget_view_->root_widget()->set_is_opaque(true);
  widget_view_->root_widget()->AddChild(demo_view_);
  demo_view_->StartAnimation();
}

}  // namespace monvg
