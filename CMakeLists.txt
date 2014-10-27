project( CODEJAM CXX )
cmake_minimum_required( VERSION 2.8.8 )

# +--------------------+
# | CodeJam Helper Lib |
# +--------------------+
add_library( codejamhelper src/codejam.hpp src/codejam.cpp )

# +--------------+
# | Store Credit |
# +--------------+
add_executable( storecredit src/StoreCredit/main.cpp )
target_link_libraries( storecredit codejamhelper )

# +------------------------+
# | Minimum Scalar Product |
# +------------------------+
add_executable( minscalprod src/MinimumScalarProduct/main.cpp )
target_link_libraries( minscalprod codejamhelper )

# +---------------+
# | Reverse Words |
# +---------------+
add_executable( reversewords src/ReverseWords/main.cpp )
target_link_libraries( reversewords codejamhelper )

