#!/bin/bash
# build script for engine
set echo on

mkdir -p ../bin

# get a list of all src files
cFiles=$(find . -type f -name "*.c")

assembly="engine"
compilerFlags="-g -shared -fdeclspec -fPIC"
# -fms-extensions
includeFlags="-Isrc -I$VULKAN_SDK/include"
linkerFlags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L$VULKAN_SDK/lib -L/usr/X11R6/lib"
defines="-D_DEBUG -DMEXPORT"

echo "building $assembly..."
clang $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkerFlags