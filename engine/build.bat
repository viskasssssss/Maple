REM build script for engine
@ECHO OFF
SetLocal EnableDelayedExpansion

REM get a list of all src files
SET cFiles=
FOR /R %%f in (*.c) do (
    SET cFiles=!cFiles! %%f
)

SET assembly=engine
SET compilerFlags= -g -gcodeview -shared -Wvarargs -Wall -Werror
SET includeFlags= -Isrc -I%VULKAN_SDK%/Include
SET linkerFlags= -luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines= -D_DEBUG -DMEXPORT -D_CRT_SECURE_NO_WARNINGS
SET implibFlag= -Wl,--out-implib,"../bin/%assembly%.lib"
SET pdbFlag=-Wl,-pdb,"../bin/%assembly%.pdb"

ECHO "building %assembly%..."
clang %cFiles% %defines% %includeFlags% %compilerFlags% %linkerFlags% %implibFlag% %pdbFlag% -o "../bin/%assembly%.dll"