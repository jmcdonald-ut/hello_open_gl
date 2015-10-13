hello\_open\_gl
===============
Simple C program to demonstrate OpenGL on OS X.

## Project Structure
```
.
├── Makefile          # Handles compiling the project.
├── README.md
├── bin
│   └── hello_open_gl # Compiled program, OpenGL example :)
└── source
    ├── main.c        # Core application file that draws the triangle.
    ├── xsys.c        # Wrapper methods around system calls.
    └── xsys.h
```

## Installation (OS X)
This installation guide assumes you have [homebrew](http://brew.sh/).

#### Dependencies (OS X)
* [X11](http://xquartz.macosforge.org/landing/)
* [glfw3](http://www.glfw.org/)
* [glew](https://github.com/nigels-com/glew)
* [OpenGL](https://www.opengl.org/)

##### Step 1
`X11` is the windowing system that used to ship with Mac OS X by default, but
this is no longer the case. Simply download
[`X11`](http://xquartz.macosforge.org/landing/) and run the installer.

##### Step 2
`glfw3` is an open source, cross platform, library for creating and managing
windows with an `OpenGL` context. This means that it relies heavily on the
windowing system provided by `X11`.
```sh
$ brew tap homebrew/versions
$ brew install glfw3
```

##### Step 3
Next let's install `glew`. This provides a small layer between our code and
`OpenGL`.
```sh
$ brew install glew
```

##### Step 4
Finally once the dependencies are installed you can run make in the root of
the project folder.
```sh
$ make
$ ./bin/hello_open_gl
```
