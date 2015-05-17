@echo off
setlocal
pushd "%~dp0"

set DEST_DIR=UE4LikeIBL_%DATE:~0,4%%DATE:~5,2%%DATE:~8,2%

for /D %%a in (UE4LikeIBL_*) do rmdir /S /Q "%%a"
mkdir "%DEST_DIR%"

REM // readme.txt
xcopy /Y "readme.md" "%DEST_DIR%"
rename "%DEST_DIR%\readme.md" "readme.txt"

REM // root effects
xcopy /Y ..\*.fx* "%DEST_DIR%"

REM // sub directories
for %%a in (shader texture debug) do xcopy /I /Y "..\%%a" "%DEST_DIR%\%%a"

popd
exit /b 0
