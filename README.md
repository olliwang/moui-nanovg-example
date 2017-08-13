# moui-nanovg-example

This project demonstrates how to build a cross-platform [moui](https://github.com/ollix/moui) app that runs [NanoVG](https://github.com/memononen/nanovg)'s demo. Currently, this project only implements iOS and macOS targets, and uses Metal as NanoVG's backend by default.

## Generate Xcode projects

A moui app uses [GYP](https://gyp.gsrc.io) as the build system that generates
other build systems. For example, to generate the Xcode project that can build
the actual apps. Simply run:

    # For iOS
    cd ios
    gyp --depth=. demo.gyp -DOS=ios

    # For macOS
    cd mac
    gyp --depth=. demo.gyp -DOS=mac


Then you can open the generated Xcode project to build and run the demo app.
