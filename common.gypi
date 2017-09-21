# Copyright (c) 2017 Olli Wang
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# ---
# Author: olliwang@ollix.com (Olli Wang)

{
  # Project-level configurations.
  'configurations': {
    'Debug': {
      'xcode_settings': {
        'ONLY_ACTIVE_ARCH': 'YES',
      },
    },
  },
  # Target-level configurations.
  'target_defaults': {
    'default_configuration': 'Release',
    'configurations': {
      'Debug': {
        'defines': [
          'DEBUG',
        ],
      },  # Debug
      'Release': {
        'defines': [
          'NDEBUG',
        ],
      }  # Release
    },  # configurations
    'conditions': [
      ['OS=="ios"', {
        'xcode_settings': {
          'IPHONEOS_DEPLOYMENT_TARGET': '9.0',
          'SDKROOT': 'iphoneos',  # -isysroot
          'VALID_ARCHS': 'arm64',
        },
      }],  # OS=="ios"
      ['OS=="mac"', {
        'xcode_settings': {
          'COMBINE_HIDPI_IMAGES': 'YES',
          'MACOSX_DEPLOYMENT_TARGET': '10.11',
          'SDKROOT': 'macosx',  # -isysroot
        },
      }],  # OS=="mac"
    ],
    'xcode_settings': {
      'GCC_OPTIMIZATION_LEVEL': 's',
      'OTHER_CPLUSPLUSFLAGS': [
        '-std=c++11',  # supports C++11
      ],
    },  # xcode_settings
  },  # target_defaults
}
