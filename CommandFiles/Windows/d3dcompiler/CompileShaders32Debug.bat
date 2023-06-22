call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
set shaderExtension=hlsl
set shaderOutputExtension=shader

set shaderTarget=vs_5_0
set shaderEntryPoint=VS
set shaderName=%shadersHome%\\Model\\default
set shaderOutputName=%shadersHome%\\Model\\defaultVS
call CompileCurrentShaderDebug.bat
set shaderTarget=ps_5_0
set shaderEntryPoint=PS
set shaderName=%shadersHome%\\Model\\default
set shaderOutputName=%shadersHome%\\Model\\defaultPS
call CompileCurrentShaderDebug.bat

set shaderTarget=vs_5_0
set shaderEntryPoint=VS
set shaderName=%shadersHome%\\Model\\Animated\\default
set shaderOutputName=%shadersHome%\\Model\\Animated\\defaultVS
call CompileCurrentShaderDebug.bat
set shaderTarget=ps_5_0
set shaderEntryPoint=PS
set shaderName=%shadersHome%\\Model\\Animated\\default
set shaderOutputName=%shadersHome%\\Model\\Animated\\defaultPS
call CompileCurrentShaderDebug.bat
