#!/bin/bash
# build script for testbed
set echo on
mkdir -p ../bin

# get a list of all src files
cFilenames=$(find . -type f -name "*.c")

assembly="testbed"
compilerFlags="-g -fdeclspec -fPIC" 
# -fms-extensions 
includeFlags="-Isrc -I../engine/src/"
linkerFlags="-L../bin/ -lengine -Wl,-rpath,."
defines="-D_DEBUG -DKIMPORT"

echo "building $assembly..."
echo clang $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkerFlags
clang $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkerFlags