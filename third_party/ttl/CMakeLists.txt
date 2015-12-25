# Build rules for header-only TTL library

set(TTL_INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Promote TTL_INCLUDE_DIRECTORY to parent scope
set(TTL_INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

set( TTL_HDRS
    ${TTL_INCLUDE_DIRECTORY}/ttl/ttl.h
    ${TTL_INCLUDE_DIRECTORY}/ttl/halfedge/hedart.h
    ${TTL_INCLUDE_DIRECTORY}/ttl/halfedge/hetraits.h
    ${TTL_INCLUDE_DIRECTORY}/ttl/halfedge/hetriang.h
)
