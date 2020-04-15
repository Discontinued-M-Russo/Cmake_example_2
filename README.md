# Cmake Example
Simple example of a project using CMake and Boost for testing and logging. Based on the material available [here](https://gernotklingler.com/blog/simple-customized-logger-based-boost-log-v2/) and on the Boost documentation.

---

## Dependencies: Boost
[Boost](https://www.boost.org/) provides portable C++ source libraries that cover a very wide span of applications, from Linear Algebra to Image Processing. The code in this repo is focused on making use of the Logging and Testing capabilities

### _Download and Install Boost_
The latest version of Boost can be downloaded from [here](https://www.boost.org/users/download/). The code in this repo has been tested up to ver. 1.72. The instructions on how to get started can be found [here](boost.org/doc/libs/1_72_0/more/getting_started/unix-variants.html) for Unix variants (Linux/MacOS) and [here](https://www.boost.org/doc/libs/1_72_0/more/getting_started/windows.html) for Windows systems.

Summarizing the main instructions _for Unix systems_ we have:

1. Download `boost_X_XX_0.tar.bz2`;
2. Create a durectory where to put the Boost installation;
3. From the directory where you want to put the Boost installation, execute:

```sh
  tar --bzip2 -xf /path/to/boost_X_XX_0.tar.bz2
```

4. In the same directory execute:

```sh
  ./bootstrap.sh --prefix=path/to/installation/prefix
```

5. Change directory to the `path/to/istallation` just defined and run:

```sh
  ./b2 install
```

This will leave Boost binaries in the lib/ subdirectory of your installation prefix. You will also find a copy of the Boost headers in the include/ subdirectory of the installation prefix, so you can henceforth use that directory as an #include path.

## Other Dependencies
Beyond Boost, other important dependencies are:

* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

---

## How to build the code
After having cloned the repo and taken care of the dependencies as described above, it is necessary to define a `BOOST_ROOT` enviroment variable to point to the `path/to/istallation` folder defined in the previous step on how to install Boost. This will be referenced in the [`CMakeLists.txt`](CMakeLists.txt) file, lines 9-11:

```sh
  # REMEMBER to set BOOST_ROOT env variable to the root folder where Boost was installed
  set(BOOST_LIBRARYDIR $(BOOST_ROOT)/lib)
  set(BOOST_INCLUDEDIRS $(BOOST_ROOT)/include/boost)
```

Once done that, from the cloned repo you should just need to: 

1. Make a build directory: `mkdir build && cd build`
2. Compile: `cmake .. && make` 

---

## How to run the code

In order to run the code in [`main.cpp`](/main.cpp), from the `build` folder just type:

```sh
  ./rectangle 
```

This will output the log messages on the console and will also create a `logfile.log` file with the same messages.

In order to run the test suite, from the `build` folder you will have to:

1. Change to the `test` folder that was created when compiling: `cd test`
2. Run `./rectangleTest`
