#!/bin/bash
mkdir build
g++ -Wall -std=c++17 -Iinclude src/*.cpp -o build/cell.exe
chmod +x build/cell.exe