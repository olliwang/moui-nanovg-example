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

#ifndef APP_DEMO_VIEW_H_
#define APP_DEMO_VIEW_H_

#include "moui/moui.h"

// Forward declaration.
struct DemoData;
struct PerfGraph;

namespace app {

class DemoView : public moui::Widget {
 public:
  DemoView();
  ~DemoView();

 private:
  // Inherited from `moui::Widget` class.
  void ContextDidChange(NVGcontext* context) final;

  // Inherited from `moui::Widget` class.
  void ContextWillChange(NVGcontext* context) final;

  // Inherited from `moui::Widget` class.
  bool HandleEvent(moui::Event* event) final;

  // Inherited from `moui::Widget` class.
  void Render(NVGcontext* context) final;

  // Inherited from `moui::Widget` class.
  bool ShouldHandleEvent(const moui::Point location) final;

  // Keeps the strong reference to hte `DemoData` object.
  struct DemoData* demo_data_;

  // Keeps the strong reference to the `PerfGraph` object.
  struct PerfGraph* perf_graph_;

  // Keeps the last timestamp rendering a frame.
  double timestamp_;

  // Keeps the latest mouse location.
  moui::Point mouseLocation_;

  DISALLOW_COPY_AND_ASSIGN(DemoView);
};

}  // namespace app

#endif  // APP_DEMO_VIEW_H_
