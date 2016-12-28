#Find bullseye executables first
set(BULLSEYE_PATH "/opt/BullseyeCoverage/bin")

find_program(BULLSEYE_GCC 		        
            NAMES "gcc" 		        
            PATHS ${BULLSEYE_PATH} 		        
            NO_DEFAULT_PATH	    
)

find_program(BULLSEYE_G++ 		        
            NAMES "g++" 		        
            PATHS ${BULLSEYE_PATH} 		        
            NO_DEFAULT_PATH	    
)
find_program(BULLSEYE_CXX 		        
            NAMES "c++" 		        
            PATHS ${BULLSEYE_PATH} 		        
            NO_DEFAULT_PATH	    
)
find_program(BULLSEYE_C++ 		        
            NAMES "c++" 		        
            PATHS ${BULLSEYE_PATH} 		        
            NO_DEFAULT_PATH	    
)
find_program(BULLSYE_CC 
                NAMES "cl" 
                PATHS ${BULLSEYE_PATH} 
                NO_DEFAULT_PATH
            )
find_program(BULLSEYE_COV_ENABLE 
                NAMES "cov01" 
                PATHS ${BULLSEYE_PATH} 
                NO_DEFAULT_PATH
            ) 
#find_package_handle_standard_args(BULLSEYE DEFAULT_MSG BULLSEYE_GCC BULLSEYE_G++ BULLSEYE_CXX BULLSEYE_C++)
find_package_handle_standard_args(BULLSEYE DEFAULT_MSG BULLSEYE_CC BULLSEYE_COV_ENABLE)
set(CMAKE_CXX_COMPILER "${BULLSEYE_CC}"}

set(CMAKE_GCC_COMPILER "${BULLSEYE_GCC}")
set(CMAKE_G++_COMPILER "${BULLSEYE_G++}")
set(CMAKE_CXX_COMPILER "${BULLSEYE_CXX}")
set(CMAKE_C++_COMPILER "${BULLSEYE_C++}")
	
message(STATUS "CMAKE_CXX_COMPILER : ${CMAKE_GCC_COMPILER} ${CMAKE_G++_COMPILER} ${CMAKE_CXX_COMPILER} ${CMAKE_C++_COMPILER}")
message(STATUS "BULLSEYE_PATH      : ${BULLSEYE_PATH}")