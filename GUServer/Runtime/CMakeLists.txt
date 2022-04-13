set(TARGET_NAME GUServerRuntime)

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${SOURCE_FILES})

add_library(${TARGET_NAME} ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "GUServerRuntime")

# Link dependencies    
target_link_libraries(${TARGET_NAME} PUBLIC
          )


target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}
)