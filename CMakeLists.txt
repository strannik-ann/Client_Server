cmake_minimum_required(VERSION 2.8)
project(Client_Server)

find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(OS_UNIX 1)
    
else()
    message(FATAL_ERROR "Unsupported operating system") 

endif()

#PROTOCOL

set(PROTO_INCROOT ${PROJECT_SOURCE_DIR}/Protocol)
set(PROTO_SRCROOT ${PROJECT_SOURCE_DIR}/Protocol)

add_library(Protocol
	${PROTO_SRCROOT}/Protocol.cpp
)

target_include_directories(Protocol
	PUBLIC ${PROTO_INCROOT}
)


#SERVER

set(SERVER_INCROOT ${PROJECT_SOURCE_DIR}/Server)
set(SERVER_SRCROOT ${PROJECT_SOURCE_DIR}/Server)

add_library(Server
	${SERVER_SRCROOT}/Server.cpp
)

target_include_directories(Server
	PUBLIC ${SERVER_INCROOT}
)
target_link_libraries(Server Protocol ${CMAKE_THREAD_LIBS_INIT})

set(CLIENT_INCROOT ${PROJECT_SOURCE_DIR}/Client)
set(CLIENT_SRCROOT ${PROJECT_SOURCE_DIR}/Client)

add_library(Client
	${CLIENT_SRCROOT}/Client.cpp
)
target_include_directories(Client
	PUBLIC ${CLIENT_INCROOT}
)

target_link_libraries(Client Protocol)

########################################

add_executable(Server_main Server_main.cpp)
target_link_libraries(Server_main Server)

########################################

add_executable(Client_main Client_main.cpp)
target_link_libraries(Client_main Client)
