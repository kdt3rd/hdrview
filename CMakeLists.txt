cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(VersionFromGit)

version_from_git(LOG ON TIMESTAMP "%Y-%m-%d-%H:%M:%S")

project(
  hdrview
  DESCRIPTION
    "A simple research-oriented image viewer with an emphasis on examining and comparing high-dynamic range (HDR) images."
  VERSION ${VERSION}
  LANGUAGES C CXX
)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp ${CMAKE_CURRENT_BINARY_DIR}/src/_version.cpp
  COMMAND ${CMAKE_COMMAND} -D SRC_DIR=${CMAKE_CURRENT_SOURCE_DIR}/src -D BIN_DIR=${CMAKE_CURRENT_BINARY_DIR}/src -D
          CMAKE_SIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P} -P ${CMAKE_SOURCE_DIR}/cmake/generate_version.cmake
  COMMENT "Generating git version file"
)

include(sanitizers)

# Set ourselves as the startup project in visual studio. Not available until cmake 3.6, but doesn't break older
# versions.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT HDRView)

# ============================================================================
# Set a default build configuration (Release)
# ============================================================================
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(DEFAULT_BUILD_TYPE Release)
  if(EMSCRIPTEN)
    set(DEFAULT_BUILD_TYPE MinSizeRel)
  endif()
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE
      ${DEFAULT_BUILD_TYPE}
      CACHE STRING "Choose the type of build." FORCE
  )
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
string(TOUPPER "${CMAKE_BUILD_TYPE}" U_CMAKE_BUILD_TYPE)

# ============================================================================
# Enable folders for projects in Visual Studio
# ============================================================================
if(CMAKE_GENERATOR MATCHES "Visual Studio")
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  # Prefer libc++ in conjunction with Clang
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag("-stdlib=libc++" HAS_LIBCPP)
    if(HAS_LIBCPP)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -D_LIBCPP_VERSION")
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
      set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
      message(STATUS "HDRView: using libc++.")
    else()
      message(
        WARNING
          "libc++ is recommended in conjunction with clang. Please install the libc++ development headers, provided e.g. by the packages 'libc++-dev' and 'libc++abi-dev' on Debian/Ubuntu."
      )
    endif()
  endif()

  # Enable link time optimization and set the default symbol visibility to hidden (very important to obtain small
  # binaries)
  if(NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEBUG)
    # Default symbol visibility
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
    # set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  endif()

  # Disable specific GCC 7 warnings
  if(CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.0)
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Wno-misleading-indentation -Wformat-truncation=0 -Wno-int-in-bool-context -Wimplicit-fallthrough=0"
    )
  endif()
endif()

# ============================================================================
# Sanitize build environment for static build with C++11/17
# ============================================================================
if(MSVC)
  # Disable annoying secure CRT warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_WARNINGS")

  # Parallel build on MSVC (all targets)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

  if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:SSE2")
  endif()

  # Static build
  set(CompilerFlags
      CMAKE_CXX_FLAGS
      CMAKE_CXX_FLAGS_DEBUG
      CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL
      CMAKE_CXX_FLAGS_RELWITHDEBINFO
      CMAKE_C_FLAGS
      CMAKE_C_FLAGS_DEBUG
      CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_MINSIZEREL
      CMAKE_C_FLAGS_RELWITHDEBINFO
  )
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()
endif()

# ============================================================================
# Add dependencies via CPM (cmake/tools.cmake includes cmake/CPM.cmake)
#
# see https://github.com/TheLartians/CPM.cmake for more info
# ============================================================================
include(cmake/CPM.cmake)

if(APPLE AND NOT EMSCRIPTEN)
  # default to GLFW+Metal on macOS
  set(HELLOIMGUI_HAS_METAL ON)

  set(HELLOIMGUI_USE_GLFW3 ON)

  # on macOS, download a fork of glfw that allows dragging files onto app icon.

  # need to enable OBJC language for the custom glfw fork
  enable_language(OBJC)
  set(HELLOIMGUI_DOWNLOAD_GLFW_IF_NEEDED OFF)
  CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY Tom94/glfw
    GIT_TAG 71eb7036b47e2733c2f7b4c0010e2ce62557009d
    OPTIONS "GLFW_BUILD_EXAMPLES OFF"
            "GLFW_BUILD_TESTS OFF"
            "GLFW_BUILD_DOCS OFF"
            "GLFW_BUILD_INSTALL OFF"
            "GLFW_INSTALL OFF"
            "GLFW_USE_CHDIR OFF"
            "BUILD_SHARED_LIBS OFF"
  )

  if(glfw_ADDED)
    message(STATUS "Using custom fork of glfw on macOS")

    mark_as_advanced(
      GLFW_BUILD_DOCS
      GLFW_BUILD_EXAMPLES
      GLFW_BUILD_INSTALL
      GLFW_BUILD_TESTS
      GLFW_DOCUMENT_INTERNALS
      GLFW_INSTALL
      GLFW_USE_CHDIR
      GLFW_USE_MENUBAR
      GLFW_USE_OSMESA
      GLFW_VULKAN_STATIC
      GLFW_USE_RETINA
      GLFW_USE_MIR
    )
  endif()
endif()

# copy asset directory to the build tree file
file(
  GLOB_RECURSE MY_RESOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} # CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/assets/**.*
)

if(APPLE AND HELLOIMGUI_HAS_METAL)

  # ~~~
  # # Precompile .metal shaders to .metallib files
  # # exclude metal files from the copy (we will compile them to metallib files below)
  # list(FILTER MY_RESOURCE_FILES EXCLUDE REGEX ".*\\.metal$")
  # # Glob up metal shaders
  # file(
  #   GLOB_RECURSE metal_shaders
  #   RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  #   ${CMAKE_CURRENT_SOURCE_DIR}/assets/**.metal
  # )
  # foreach(shader ${metal_shaders})
  #   set(shader_source "${CMAKE_CURRENT_SOURCE_DIR}/${shader}")
  #   set(shader_lib "${CMAKE_CURRENT_BINARY_DIR}/${shader}lib")
  #   # message(STATUS "Compiling Metal shader \"${shader_source}\" to MLTB library \"${shader_lib}\".")
  #   add_custom_command(
  #     OUTPUT ${shader_lib}
  #     DEPENDS ${shader_source}
  #     COMMAND xcrun -sdk macosx metal -std=osx-metal2.0 -O3 "${shader_source}" -o "${shader_lib}"
  #     WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  #     COMMENT "Compiling Metal shader \"${shader}\" to MLTB library \"${shader}lib\"."
  #     VERBATIM
  #   )
  #   set_property(
  #     SOURCE src/app.cpp
  #     APPEND
  #     PROPERTY OBJECT_DEPENDS ${shader_lib}
  #   )
  #   list(APPEND EXTRA_SOURCES ${shader_lib})
  # endforeach()
  # ~~~

  list(APPEND EXTRA_SOURCES src/renderpass_metal.mm src/shader_metal.mm src/texture_metal.mm)
endif()

foreach(MY_RESOURCE_FILE ${MY_RESOURCE_FILES})
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${MY_RESOURCE_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${MY_RESOURCE_FILE} COPYONLY
  )
endforeach()

set(HELLOIMGUI_EMSCRIPTEN_PTHREAD OFF)
set(HELLOIMGUI_EMSCRIPTEN_PTHREAD_ALLOW_MEMORY_GROWTH OFF)

# cmake-format: off
# CPMAddPackage(
#   NAME imgui_bundle
#   GITHUB_REPOSITORY pthom/imgui_bundle
#   GIT_TAG v1.6.0
#   OPTIONS "IMGUI_BUNDLE_WITH_TEST_ENGINE OFF"
#           "IMGUI_BUNDLE_DISABLE_NANOVG ON"
#           "IMGUI_BUNDLE_DISABLE_IMGUI_TEX_INSPECT ON"
#           "IMGUI_BUNDLE_DISABLE_IMGUIZMO ON"
#           "IMGUI_BUNDLE_DISABLE_IMFILEDIALOG ON"
#           "IMGUI_BUNDLE_DISABLE_IMGUI_NODE_EDITOR ON"
#           # "IMGUI_BUNDLE_DISABLE_IMPLOT ON"
#           "IMGUI_BUNDLE_DISABLE_IMMVISION ON"
# )
# if(imgui_bundle_ADDED)
#   message(STATUS "imgui_bundle library added")
#   if(HELLOIMGUI_EMSCRIPTEN_PTHREAD)
#     add_compile_options(-pthread)
#   endif()
# endif()
# cmake-format: on

CPMAddPackage("gh:pthom/hello_imgui#v1.6.0")
if(hello_imgui_ADDED)
  message(STATUS "hello_imgui library added")
  if(HELLOIMGUI_EMSCRIPTEN_PTHREAD)
    add_compile_options(-pthread)
  endif()
endif()

CPMAddPackage("gh:epezent/implot#77674d270e851d3f3718aad00234201af2b76ac9")
if(implot_ADDED)
  message(STATUS "implot library added")

  # implot has no CMake support, so we create our own target
  add_library(
    implot STATIC ${implot_SOURCE_DIR}/implot.h ${implot_SOURCE_DIR}/implot_internal.h ${implot_SOURCE_DIR}/implot.cpp
                  ${implot_SOURCE_DIR}/implot_items.cpp
  )
  target_include_directories(implot PUBLIC ${implot_SOURCE_DIR})
  target_link_libraries(implot PUBLIC imgui)
  set_target_properties(implot PROPERTIES CXX_STANDARD 17)
  list(APPEND EXTRA_SOURCES ${implot_SOURCE_DIR}/implot.h ${implot_SOURCE_DIR}/implot_internal.h
       ${implot_SOURCE_DIR}/implot.cpp ${implot_SOURCE_DIR}/implot_items.cpp
  )
endif()

CPMAddPackage("gh:samhocevar/portable-file-dialogs#7f852d88a480020d7f91957cbcefe514fc95000c")
if(portable-file-dialogs_ADDED)
  message(STATUS "portable-file-dialogs library added")
  add_library(portable-file-dialogs INTERFACE IMPORTED)
  target_include_directories(portable-file-dialogs INTERFACE "${portable-file-dialogs_SOURCE_DIR}")
endif()

# CPMAddPackage("gh:wkjarosz/imgui-command-palette#66124ae045c11eb153c9c3f184b1e12f4d5a0e7b")
CPMAddPackage(
  NAME my_imgui_command_palette
  GITHUB_REPOSITORY wkjarosz/imgui-command-palette
  GIT_TAG 826cd9a8802b52d190568dd10ca29a17be3320ab
  DOWNLOAD_ONLY YES
)

if(my_imgui_command_palette_ADDED)
  message(STATUS "imgui-command-palette library added")
  add_library(
    my_imgui_command_palette
    "${my_imgui_command_palette_SOURCE_DIR}/imcmd_command_palette.h"
    "${my_imgui_command_palette_SOURCE_DIR}/imcmd_command_palette.cpp"
    "${my_imgui_command_palette_SOURCE_DIR}/imcmd_fuzzy_search.h"
    "${my_imgui_command_palette_SOURCE_DIR}/imcmd_fuzzy_search.cpp"
  )
  target_compile_features(my_imgui_command_palette PUBLIC cxx_std_11)
  target_include_directories(my_imgui_command_palette PUBLIC . ${my_imgui_command_palette_SOURCE_DIR})
  target_link_libraries(my_imgui_command_palette PUBLIC imgui)
endif()

CPMAddPackage("gh:sgorsten/linalg@2.2")
if(linalg_ADDED)
  message(STATUS "linalg library added")
  add_library(linalg INTERFACE IMPORTED)
  target_include_directories(linalg INTERFACE "${linalg_SOURCE_DIR}")
endif()

CPMAddPackage("gh:fmtlib/fmt#11.0.2")
if(fmt_ADDED)
  message(STATUS "fmt library added")
endif()

CPMAddPackage(
  NAME spdlog
  URL https://github.com/gabime/spdlog/archive/refs/tags/v1.15.0.zip
  OPTIONS "SPDLOG_INSTALL NO" # don't create an installable target
          "SPDLOG_FMT_EXTERNAL YES" # use the fmt library we added above instead of the bundled one
)
if(spdlog_ADDED)
  message(STATUS "spdlog library added")
endif()

CPMAddPackage("gh:nothings/stb#a0a939058c579ddefd4c5671b046f29d12aeae01")
if(stb_ADDED)
  message(STATUS "stb library added")
  add_library(stb INTERFACE IMPORTED)
  target_include_directories(stb INTERFACE "${stb_SOURCE_DIR}")
endif()

CPMAddPackage("gh:Armchair-Software/emscripten-browser-file#d21dec772050d581c02aa9820e4d877fdb060dc8")
if(emscripten-browser-file_ADDED)
  message(STATUS "emscripten-browser-file library added")
  add_library(emscripten-browser-file INTERFACE IMPORTED)
  target_include_directories(emscripten-browser-file INTERFACE "${emscripten-browser-file_SOURCE_DIR}")
endif()

CPMAddPackage(
  NAME Imath
  VERSION 3.1.12 # the git repo is incredibly large, so we download the archived include directory
  URL https://github.com/AcademySoftwareFoundation/Imath/archive/refs/tags/v3.1.12.zip
  OPTIONS "BUILD_SHARED_LIBS OFF" "IMATH_INSTALL OFF" "IMATH_INSTALL_PKG_CONFIG OFF" "BUILD_TESTING OFF"
          "EXCLUDE_FROM_ALL YES"
)

if(EMSCRIPTEN AND NOT HELLOIMGUI_EMSCRIPTEN_PTHREAD)
  set(OPENEXR_THREADING_OPTIONS "OPENEXR_ENABLE_THREADING OFF")
else()
  set(OPENEXR_THREADING_OPTIONS "OPENEXR_ENABLE_THREADING ON")
endif()

CPMAddPackage(
  NAME openexr
  GITHUB_REPOSITORY AcademySoftwareFoundation/openexr
  # FIXME: OpenEXR v3.3.0 and above seems to break our subsample channel loading
  GIT_TAG v3.2.4
  OPTIONS "BUILD_SHARED_LIBS OFF"
          "BUILD_TESTING OFF"
          "OPENEXR_BUILD_TOOLS OFF"
          "OPENEXR_BUILD_EXAMPLES OFF"
          "OPENEXR_INSTALL OFF"
          "OPENEXR_INSTALL_TOOLS OFF"
          "OPENEXR_INSTALL_EXAMPLES OFF"
          "OPENEXR_INSTALL_PKG_CONFIG OFF"
          "EXCLUDE_FROM_ALL YES"
          ${OPENEXR_THREADING_OPTIONS}
)
if(openexr_ADDED)
  message(STATUS "openexr library added with threading options: ${OPENEXR_THREADING_OPTIONS}")
endif()

CPMAddPackage(
  NAME cli11
  URL https://github.com/CLIUtils/CLI11/archive/v2.4.2.zip
  DOWNLOAD_ONLY YES
)
if(cli11_ADDED)
  message(STATUS "CLI11 library added")
  add_library(cli11 INTERFACE IMPORTED)
  target_include_directories(cli11 INTERFACE "${cli11_SOURCE_DIR}/include")
endif()

# ============================================================================
# Compile remainder of the codebase with compiler warnings turned on
# ============================================================================
if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wno-gnu-anonymous-struct -Wno-c99-extensions -Wno-nested-anon-types -Wno-deprecated-register"
    )
  endif()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Now build the HDRView viewer app
string(TIMESTAMP YEAR "%Y")

set(output_name "HDRView")
set(HELLO_IMGUI_BUNDLE_IDENTIFIER_URL_PART "com.im.HDRView")
set(HELLO_IMGUI_BUNDLE_IDENTIFIER_NAME_PART ${app_name})
set(HELLO_IMGUI_ICON_DISPLAY_NAME ${output_name})
set(HELLO_IMGUI_BUNDLE_NAME ${output_name})
set(HELLO_IMGUI_BUNDLE_COPYRIGHT "© Wojciech Jarosz, ${YEAR}")
set(HELLO_IMGUI_BUNDLE_EXECUTABLE ${output_name})
set(HELLO_IMGUI_BUNDLE_VERSION ${VERSION})
set(HELLO_IMGUI_BUNDLE_SHORT_VERSION ${VERSION})
set(HELLO_IMGUI_BUNDLE_ICON_FILE icon.icns)

# By default, we install in a portable way (i.e. assets and executable are in the same folder)
option(HDRVIEW_PORTABLE_INSTALL "Install in a portable way" ON)

if(NOT HDRVIEW_PORTABLE_INSTALL)
  # Disable HelloImGui default install behavior
  set(HELLOIMGUI_ADD_APP_WITH_INSTALL
      OFF
      CACHE BOOL "" FORCE
  )
endif()

hello_imgui_add_app(
  HDRView
  ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp
  src/app.cpp
  src/colorspace.cpp
  src/common.cpp
  src/fonts.cpp
  src/hdrview.cpp
  src/image.cpp
  src/imageio.cpp
  src/imgui_ext.cpp
  src/image_gui.cpp
  src/pfm.cpp
  src/parallelfor.cpp
  src/progress.cpp
  src/opengl_check.cpp
  src/scheduler.cpp
  src/shader.cpp
  src/shader_gl.cpp
  src/renderpass_gl.cpp
  src/texture.cpp
  src/texture_gl.cpp
  ${EXTRA_SOURCES}
  ASSETS_LOCATION
  ${CMAKE_CURRENT_BINARY_DIR}/assets
)

set_target_properties(HDRView PROPERTIES OUTPUT_NAME ${output_name} CXX_STANDARD 17)
# add_dependencies(HDRView gen_version_h_target) target_sources(HDRView PRIVATE
# ${CMAKE_CURRENT_BINARY_DIR}/src/version.cpp)
if(APPLE)
  target_compile_options(HDRView PRIVATE "-fobjc-arc")
  target_link_libraries(HDRView PRIVATE "-framework ApplicationServices")
  target_compile_definitions(HDRView PRIVATE IMGUI_ENABLE_OSX_DEFAULT_CLIPBOARD_FUNCTIONS)
endif(APPLE)
target_link_libraries(
  HDRView
  PRIVATE linalg
          fmt::fmt
          spdlog::spdlog
          OpenEXR::OpenEXR
          Imath::Imath
          stb
          implot
          cli11
          my_imgui_command_palette
)
target_compile_definitions(HDRView PRIVATE HELLOIMGUI_NO_FONT_AWESOME4)

if(EMSCRIPTEN)
  target_link_libraries(HDRView PRIVATE emscripten-browser-file)
  target_link_options(
    HDRView
    PRIVATE
    -fexceptions
    -sEXPORTED_RUNTIME_METHODS=[ccall]
    -sEXPORTED_FUNCTIONS=[_main,_malloc,_free]
    -sNO_DISABLE_EXCEPTION_CATCHING
    -sMAX_WEBGL_VERSION=2
    -sMIN_WEBGL_VERSION=2
  )
  target_compile_options(HDRView PRIVATE -fexceptions -sNO_DISABLE_EXCEPTION_CATCHING)
  if(HELLOIMGUI_EMSCRIPTEN_PTHREAD)
    target_link_options(HDRView PRIVATE -pthread)
    target_link_options(HDRView PRIVATE -sPTHREAD_POOL_SIZE=3)
  endif()
  hello_imgui_set_emscripten_target_initial_memory_megabytes(HDRView 300)
else()
  target_link_libraries(HDRView PRIVATE portable-file-dialogs)
endif()

if(UNIX AND NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEBUG)
  add_custom_command(
    TARGET HDRView
    POST_BUILD
    COMMAND strip $<TARGET_FILE:HDRView>
  )
endif()

# Force colored output for the ninja generator
if(CMAKE_GENERATOR STREQUAL "Ninja")
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcolor-diagnostics")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdiagnostics-color=always")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
  endif()
endif()

# Install and packaging support

if(NOT HDRVIEW_PORTABLE_INSTALL)
  # If not portable, we have to - install the app manually - install the assets manually - pass the assets location to
  # the app, and set this assets location in main() via the compile definition ASSETS_LOCATION: #ifdef ASSETS_LOCATION
  # \n HelloImGui::SetAssetsFolder(ASSETS_LOCATION); \n #endif
  include(GNUInstallDirs)
  install(TARGETS HDRView DESTINATION ${CMAKE_INSTALL_BINDIR})
  set(assets_install_dir ${CMAKE_INSTALL_DATADIR}/HDRView)
  if(NOT IS_ABSOLUTE ${assets_install_dir})
    set(assets_install_dir ${CMAKE_INSTALL_PREFIX}/${assets_install_dir})
  endif()
  install(DIRECTORY assets DESTINATION ${assets_install_dir})
  target_compile_definitions(HDRView PRIVATE ASSETS_LOCATION="${assets_install_dir}/assets")
endif()

set(CPACK_PACKAGE_VENDOR "Wojciech Jarosz")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/wkjarosz/hdrview")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}")

if(APPLE)
  set(CPACK_GENERATOR "DragNDrop")
endif()

include(CPack)
