DOWNLOAD_FILE(
        https://cdn.jsdelivr.net/gh/shimakaze09/MyData@main/MyBL/stb_image.h
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps/stb_image.h
        SHA256 594c2fe35d49488b4382dbfaec8f98366defca819d916ac95becf3e75f4200b3
)

DOWNLOAD_FILE(
        https://cdn.jsdelivr.net/gh/shimakaze09/MyData@main/MyBL/stb_image_write.h
        ${CMAKE_CURRENT_SOURCE_DIR}/_deps/stb_image_write.h
        SHA256 cbd5f0ad7a9cf4468affb36354a1d2338034f2c12473cf1a8e32053cb6914a05
)

ADD_TARGET(
        MODE STATIC
        SOURCE "${PROJECT_SOURCE_DIR}/include/MyBL"
        LIB My::MyGM_core My::MyDP_core
        INC include
)