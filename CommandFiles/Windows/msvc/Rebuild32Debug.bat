call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32DebugHome%
MSBuild INSTALL.vcxproj /t:rebuild /p:Platform=x86;Configuration=Debug
