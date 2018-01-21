# Copyright 2017 Ollix
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.4.1)

list(APPEND RESOURCES "../deps/moui/moui/deps/nanovg/example")
set(RESOURCES ${RESOURCES} PARENT_SCOPE)

add_library(app
    STATIC
    "../deps/GLFW/glfw3.c"
    "../deps/moui/moui/deps/nanovg/example/demo.c"
    "../deps/moui/moui/deps/nanovg/example/perf.c"
    "application.cc"
    "demo_view.cc"
    "main.cc")

set_target_properties(app
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

target_include_directories(app
    PRIVATE
    ".."
    "../deps")

if(ANDROID)
    add_subdirectory("../deps/moui/android" "moui-jni")
    target_link_libraries(app PUBLIC moui-jni)
else()
    add_subdirectory("../deps/moui/moui" "moui")
    target_link_libraries(app PUBLIC moui)
endif()
