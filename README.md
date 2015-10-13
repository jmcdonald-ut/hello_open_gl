`hello_open_gl`
===============

### Dependencies (OS X)

* [X11](http://xquartz.macosforge.org/landing/)
* [glfw3](http://www.glfw.org/)
* [glew](https://github.com/nigels-com/glew)
* [OpenGL](https://www.opengl.org/)

### Installation (OS X)

This documented process is intended for those on Mac OS X.  This installation
guide assumes you have [homebrew](http://brew.sh/).

1. **X11**: The windowing system that used to ship with Mac OS X by default,
but this is no longer the case. Simply download
[X11](http://xquartz.macosforge.org/landing/) and run the installer.

2. **glfw3**: Install `glfw3`. `glfw3` is an open source, cross platform,
library for creating and managing windows with an OpenGL context. This means
that it relies heavily on the implementation provided by `X11`.
```sh
$ brew tap homebrew/versions
$ brew install glfw3
```

3. **glew**: Install `glew`. This provides a small layer between us and
`OpenGL`.
```sh
$ brew install glew
```

Finally once these dependencies are installed you can run make in the root of
the project folder and the program will be compiled and output in the bin
folder.
```sh
$ make
$ ./bin/hello_open_gl
```
