call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32ReleaseHome%
mingw32-make install -j20