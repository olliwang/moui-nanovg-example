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

set(PROJECT_NAME "MouiDemo-iOS")

project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Archives)
set(CMAKE_OSX_SYSROOT "iphoneos")
set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "9.0")

set(RESOURCES "LaunchScreen.storyboard")
add_subdirectory("../app" "moui-app")

add_executable(${PROJECT_NAME}
    MACOSX_BUNDLE
    "MOAppDelegate.mm"
    "main.mm"
    ${RESOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES"
    XCODE_ATTRIBUTE_INFOPLIST_FILE "Info.plist"
    XCODE_ATTRIBUTE_INSTALL_PATH "${PROJECT_BINARY_DIR}"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.moui.nanovg"
    XCODE_ATTRIBUTE_SKIP_INSTALL "NO"
    XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2"
    RESOURCE "${RESOURCES}")

target_link_libraries(${PROJECT_NAME} PUBLIC app)
