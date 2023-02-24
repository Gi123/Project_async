set(LIB_NAME )
add_library(async SHARED
                  asynchronously/async.cpp
                  writer/AsyncCommandWriter.h
                  writer/AsyncCommandWriter.cpp
                  com/CommandProcessingFacade.h
                  com/CommandProcessingFacade.cpp
                  com/CommandProcessor.h
                  com/CommandProcessor.cpp
                  writer/ConsoleCommandWriter.h 
                  writer/ConsoleCommandWriter.cpp 
                  writer/FileCommandWriter.h
                  writer/FileCommandWriter.cpp 
                  util/Util.h
                  util/Util.cpp
                  FlushCommandListener.h)
                
# add_library(command SHARED 
#                     FlushCommandListener.h
#                   com/CommandProcessingFacade.h
#                   com/CommandProcessingFacade.cpp
#                   com/CommandProcessor.h
#                   com/CommandProcessor.cpp)
                  
# add_library(writer SHARED 
#                   writer/ConsoleCommandWriter.h 
#                   writer/ConsoleCommandWriter.cpp 
#                   writer/FileCommandWriter.h
#                   writer/FileCommandWriter.cpp )

# add_library(util SHARED 
#                   util/Util.h
#                   util/Util.cpp )

target_include_directories(
                async
                PRIVATE
                ${CMAKE_CURRENT_SOURCE_DIR}/writer
                ${CMAKE_CURRENT_SOURCE_DIR}/async
                ${CMAKE_CURRENT_SOURCE_DIR}/util
                ${CMAKE_CURRENT_SOURCE_DIR}/com
                ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(async_lib main.cpp)
set_target_properties(async_lib PROPERTIES OUTPUT_NAME async PUBLIC_HEADER asynchronously/async.h)

# set_target_properties(async_cli PROPERTIES OUTPUT_NAME command)
# set_target_properties(async_cli PROPERTIES OUTPUT_NAME writer)
# set_target_properties(async_cli PROPERTIES OUTPUT_NAME util)

find_package(Threads REQUIRED)
target_link_libraries(async_lib PRIVATE async Threads::Threads)

