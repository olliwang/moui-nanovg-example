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

#include "app/demo_view.h"

#include "moui/moui.h"
#include "nanovg/example/demo.h"
#include "nanovg/example/perf.h"

namespace {

// Overrides the original `loadDemoData()` function defined in
// `nanovg/example/demo.h` for loading resources at correct directory.
int loadDemoData(NVGcontext* context, DemoData* data, std::string& directory) {
  int i;

  if (context == NULL)
    return -1;

  for (i = 0; i < 12; i++) {
    char file[256];
    snprintf(file, 256, "%s/example/images/image%d.jpg", directory.c_str(),
             i + 1);
    data->images[i] = nvgCreateImage(context, file, 0);
    if (data->images[i] == 0) {
      printf("Could not load %s.\n", file);
      return -1;
    }
  }

  std::string font_path = directory + "/example/entypo.ttf";
  data->fontIcons = nvgCreateFont(context, "icons", font_path.c_str());
  if (data->fontIcons == -1) {
    printf("Could not add font icons.\n");
    return -1;
  }
  font_path = directory + "/example/Roboto-Regular.ttf";
  data->fontNormal = nvgCreateFont(context, "sans", font_path.c_str());
  if (data->fontNormal == -1) {
    printf("Could not add font italic.\n");
    return -1;
  }
  font_path = directory + "/example/Roboto-Bold.ttf";
  data->fontBold = nvgCreateFont(context, "sans-bold", font_path.c_str());
  if (data->fontBold == -1) {
    printf("Could not add font bold.\n");
    return -1;
  }
  font_path = directory + "/example/NotoEmoji-Regular.ttf";
  data->fontEmoji = nvgCreateFont(context, "emoji", font_path.c_str());
  if (data->fontEmoji == -1) {
    printf("Could not add font emoji.\n");
    return -1;
  }
  nvgAddFallbackFontId(context, data->fontNormal, data->fontEmoji);
  nvgAddFallbackFontId(context, data->fontBold, data->fontEmoji);

  return 0;
}

}  // namespace

namespace app {

DemoView::DemoView() : demo_data_(nullptr), timestamp_(0) {
  SetWidth(moui::Widget::Unit::kPercent, 100);
  SetHeight(moui::Widget::Unit::kPercent, 100);
  set_background_color(nvgRGBf(0.3, 0.3, 0.3));

  perf_graph_ = new PerfGraph;
  initGraph(perf_graph_, GRAPH_RENDER_FPS, "Frame Time");
}

DemoView::~DemoView() {
  delete perf_graph_;
}

void DemoView::ContextDidChange(NVGcontext* context) {
  if (context == nullptr)
    return;

  std::string app_directory = \
      moui::Path::GetDirectory(moui::Path::Directory::kResource);
  demo_data_ = new DemoData;
  loadDemoData(context, demo_data_, app_directory);
}

void DemoView::ContextWillChange(NVGcontext* context) {
  if (demo_data_ != nullptr) {
    freeDemoData(context, demo_data_);
    delete demo_data_;
    demo_data_ = nullptr;
  }
}

bool DemoView::HandleEvent(moui::Event* event) {
  if (event->type() == moui::Event::Type::kDown ||
      event->type() == moui::Event::Type::kMove) {
    mouseLocation_ = event->locations()->at(0);
  }
  return true;
}

void DemoView::Render(NVGcontext* context) {
  const double kTimestamp = moui::Clock::GetTimestamp();
  const double kTimeDiff = kTimestamp - timestamp_;
  updateGraph(perf_graph_, kTimeDiff);
  timestamp_ = kTimestamp;

#ifdef MOUI_MAC
  mouseLocation_ = widget_view()->GetMouseLocation();
#endif

  renderDemo(context, mouseLocation_.x, mouseLocation_.y, GetWidth(),
             GetHeight(), kTimestamp, 0, demo_data_);
  renderGraph(context, 5, 5, perf_graph_);
}

bool DemoView::ShouldHandleEvent(const moui::Point location) {
#ifdef MOUI_MAC
  return false;
#else
  return true;
#endif
}

}  // namespace app
