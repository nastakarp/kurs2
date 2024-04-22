cmake_minimum_required(VERSION 3.27)
project(proga_kurs)

set(CMAKE_CXX_STANDARD 17)

add_executable(proga_kurs
        model/core/Name.cpp
        Util.cpp
        Util.h
        model/node/NameNode.h
        model/core/Name.h
        model/node/NameNode.cpp
        model/core/City.cpp
        main.cpp
        model/core/City.h
        model/node/CityNode.cpp
        model/node/CityNode.h
        model/core/Position.h
        model/core/Position.cpp
        model/node/PositionNode.cpp
        model/node/PositionNode.h
        model/core/Status.cpp
        model/core/Status.h
        model/node/StatusNode.cpp
        model/node/StatusNode.h
        model/core/TeamName.cpp
        model/core/TeamName.h
        model/node/TeamNameNode.cpp
        model/node/TeamNameNode.h
        model/list/NameList.h
        model/list/NameList.cpp
        model/list/CityList.h
        model/list/CityList.cpp
        model/list/PositionList.cpp
        model/list/PositionList.h
        model/list/StatusList.cpp
        model/list/StatusList.h
        model/list/TeamNameList.cpp
        model/list/TeamNameList.h)
