@echo off
REM 设置项目根目录
set PROJECT_DIR=%~dp0
set BUILD_DIR=%PROJECT_DIR%build
set CMAKE_GENERATOR="Visual Studio 17 2022"

REM 如果构建目录不存在，则创建它
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

REM 进入构建目录
cd %BUILD_DIR%

REM 运行 CMake 配置（确保CMake找到所有依赖项）
cmake -G %CMAKE_GENERATOR% .. -DCMAKE_BUILD_TYPE=Release

REM 如果CMake配置成功，执行构建
if %errorlevel% neq 0 (
    echo CMake配置失败！
    exit /b %errorlevel%
)

REM 开始构建
cmake --build . --config Debug

REM 如果构建成功
if %errorlevel% neq 0 (
    echo 构建失败！
    exit /b %errorlevel%
)

echo 构建完成！
pause
