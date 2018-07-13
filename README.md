# Native Node Module.

## Purpose

This repo is just a first try to integrate a c++ module into node.js with V8 Javascript Motor.

### Features

* Instantiate a C++ class, ManagerWrapper.
* Call ManagerWrapper getMethod method that call internal class ManagerImpl and print "Hello World"

## Prerequisites :

* Node.js v9.9.0
* cmake-js (npm install -g cmake-js)
OR
* CMake (but for now you need to change node include paths)

## Build :

Before all :

```npm install```

### With cmake-js

run in source dir

```bash
cmake-js configure .
cmake-js build
```

### With CMake Vanilla

```bash
cmake configure .
cmake build
```

## Running the server (test file for now)

```npm start```

## TODOS :

* Give a try to Native Abstractions for Node (alias Nan)
* Add few complexity in the code.
* Export C/C++ structure with Basic Types (int, float, string, char, double, ...)
* Use Conan to retrieve V8 / Node Api.
* Make a real server