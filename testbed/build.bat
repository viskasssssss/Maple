REM build script for testbed
@ECHO OFF
SetLocal EnableDelayedExpansion

REM get a list of all src files
SET cFiles=
FOR /R %%f in (*.c) do (
    SET cFiles=!cFiles! %%f
)

SET assembly=testbed
SET compilerFlags=-g -gcodeview
SET includeFlags=-Isrc -I../engine/src/
SET linkerFlags=-L../bin/ -lengine
SET defines=-D_DEBUG -DMIMPORT
SET pdbFlag=-Wl,-pdb,"../bin/%assembly%.pdb"

ECHO "building %assembly%%..."
clang %cFiles% %defines% %includeFlags% %compilerFlags% %linkerFlags% %pdbFlag% -o "../bin/%assembly%.exe"