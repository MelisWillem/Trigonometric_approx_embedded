file(GLOB trio_SRC
    "*.c"
)
add_library(TRIO_lib STATIC ${trio_SRC})
set_property(TARGET TRIO_lib PROPERTY C_STANDARD 90)