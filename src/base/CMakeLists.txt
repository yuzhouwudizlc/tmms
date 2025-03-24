aux_source_directory(. DIR_LIB_SRCS)
add_library (base ${DIR_LIB_SRCS})
add_executable(TestSingleton TestSingleton.cpp)

add_executable(TestTask TestTask.cpp Task.cpp TaskMgr.cpp TTime.cpp)
target_link_libraries(TestTask
    base
    pthread # 添加线程库
    stdc++fs
)

add_executable(TestLog TestLog.cpp Logger.cpp)
target_link_libraries(TestLog base)
