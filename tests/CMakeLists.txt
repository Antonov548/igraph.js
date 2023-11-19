find_program(NPM_EXECUTABLE npm REQUIRED)

if(NPM_EXECUTABLE)
    message(STATUS "npm found: ${NPM_EXECUTABLE}")

    # Example: Run npm install as a part of the build process
    add_custom_target(
        test
        COMMAND ${NPM_EXECUTABLE} install
        COMMAND ${NPM_EXECUTABLE} test
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
        COMMENT "Running test using npm"
    )

    add_dependencies(test jigraph)
else()
    message(WARNING "npm not found. Please install Node.js and npm.")
endif()
