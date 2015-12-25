include_directories(
    .
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIR}
    ${CMAKE_BINARY_DIR}
    )

set(POLYGON_SRCS
    math_for_graphics.cpp
    PolyLine.cpp
    polygon_test_point_inside.cpp
    clipper.cpp
)

add_library(polygon STATIC ${POLYGON_SRCS})

add_dependencies( polygon lib-dependencies )

