# CMakeList.txt : CMake project for uMod, include source and define
# project specific logic here.
#

project(uMod)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "You are configuring a 64bit build, this is not supported. Run cmake with `-A Win32`")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 5)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 0)

set(VERSION_RC "${CMAKE_CURRENT_BINARY_DIR}/version.rc")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in" "${VERSION_RC}" @ONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(uMod "${CMAKE_CURRENT_LIST_DIR}/")
set(DIRECTX_SDK_INCLUDE_DIR "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include")
set(DIRECTX_SDK_LIB_DIR "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/")

link_directories(${DIRECTX_SDK_LIB_DIR})
include_directories(${DIRECTX_SDK_INCLUDE_DIR})
add_library(uMod SHARED)
file(GLOB SOURCES
    "source/pch.h"
    "source/*.cpp"
    "header/*.h*"
    ${VERSION_RC})
target_link_libraries(uMod PRIVATE ${DIRECTX_SDK_LIB_DIR}/d3d9.lib ${DIRECTX_SDK_LIB_DIR}/d3dx9.lib ${DIRECTX_SDK_LIB_DIR}/dxguid.lib)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})
target_sources(uMod PRIVATE ${SOURCES})
target_compile_features(uMod PUBLIC cxx_std_17)
target_compile_definitions(uMod PRIVATE
    $<$<CONFIG:Debug>:BUILD_TYPE_DEBUG>
    $<$<CONFIG:Release>:BUILD_TYPE_RELEASE>
    INJECTION_METHOD=2
    DIRECT_INJECTION
    DEF_USE_DX9=true
    DX_XX_File=9
    LOG_MESSAGE
)

target_precompile_headers(uMod PRIVATE "header/pch.h")
target_include_directories(uMod PUBLIC "header")