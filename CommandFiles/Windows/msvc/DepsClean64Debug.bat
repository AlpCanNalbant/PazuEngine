call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Debug
cd %depsProjectsHome%
call DepsClean-MSVC.bat
:: Tehlikeli ve seytani bunlari kullanma!
:: cd %depsLib64DebugHome%
:: del /q .\\*
:: cd %depsBin64DebugHome%
:: del /q .\\*.dll
:: cd %depsIncludeHome%
:: call %commandsHome%\\Paths\\CleanCurrentFolder.bat
