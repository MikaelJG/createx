set(VERIFICATION_LIBRARY_SOURCES
    "append_tex_file.cpp"
    )
set(VERIFICATION_LIBRARY_HEADERS
    "append_tex_file.h"
    )
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(Append_Library STATIC
    ${VERIFICATION_LIBRARY_SOURCES}
    ${VERIFICATION_LIBRARY_HEADERS})

target_include_directories(Append_Library PUBLIC ${LIBRARY_INCLUDES})
