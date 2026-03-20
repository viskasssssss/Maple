#!/bin/bash
# Build script for rebuilding everything
set echo on

echo "building everything..."


pushd engine
source build.sh
popd

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
echo "error:"$ERRORLEVEL && exit
fi

pushd testbed
source build.sh
popd
ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
echo "error:"$ERRORLEVEL && exit
fi

echo "all assemblies built successfully!"