add_library(Exponential exponential/src/Exponential.cpp exponential/include/Exponential.h)
target_include_directories(Exponential PUBLIC exponential/include)

add_library(Expression
        expression/src/Expression.cpp expression/include/Expression.h
        expression/src/Add.cpp expression/include/Add.h
        expression/src/Const.cpp expression/include/Const.h
        expression/src/Divide.cpp expression/include/Divide.h
        expression/src/Multiply.cpp expression/include/Multiply.h
        expression/src/Negate.cpp expression/include/Negate.h
        expression/src/Subtract.cpp expression/include/Subtract.h
        expression/src/Variable.cpp expression/include/Variable.h
)
target_include_directories(Expression PUBLIC expression/include exponential/include)
target_link_libraries(Expression PUBLIC Exponential)