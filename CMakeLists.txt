cmake_minimum_required(VERSION 3.8)

project(files_backup)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 启用自动UI编译（AUTOUIC）
set(CMAKE_AUTOUIC ON)
# 自动元对象编译（AUTOMOC）
set(CMAKE_AUTOMOC ON)
# 自动资源编译（AUTORCC）
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenSSL REQUIRED)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)
file(GLOB RESOURCES *.qrc)  # 确保正确的qrc路径
file(GLOB FORMS forms/*.ui)  # 确保.ui文件的路径

set(SRCS ${SOURCES} ${HEADERS} ${RESOURCES} ${FORMS})

source_group("Header" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})
source_group("Ui" FILES ${FORMS})
source_group("Resource" FILES ${RESOURCES})

set(CMAKE_CXX_STANDARD 17)

# 创建可执行文件
add_executable(files_backup ${SRCS})

# 引入Qt和OpenSSL
target_link_libraries(files_backup Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(files_backup OpenSSL::SSL OpenSSL::Crypto)

# 设置目标属性
set_target_properties(files_backup PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
