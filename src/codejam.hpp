#ifndef CODE_JAM_HPP_
#define CODE_JAM_HPP_

#include <fstream>

// +------------------------------------------------------------------------+
// | Codejam                                                                |
// |   -- Helper struct for code jam problems.                              |
// |   -- User must inherit this class and implement the virtual functions. |
// |   -- User must specify any additional data members.                    |
// |   -- See template/main.cpp for an example                              |
// +------------------------------------------------------------------------+
struct Codejam
{

  // +---------------------------------------+
  // | CONSTRUCTOR                           |
  // |   -- Parses command line arguments    |
  // |   -- Opens files for input and output |
  // +---------------------------------------+
  Codejam( int argc, const char** argv ); 

  int get_num_tests();

  // VIRTUAL FUNCTIONS
  virtual void get_test() = 0;           // read the test data from the input
                                         //   file
  virtual void debug() const = 0;        // generic function to add any helpful
                                         //   output
  virtual void solve() = 0;              // logic to solve the problem
  virtual void write_output( int ) = 0;  // write to output file in format
                                         //   specified
  // DATA MEMBERS
  std::ifstream m_in;       // input stream
  std::ofstream m_out;      // output stream

};

#endif // CODE_JAM_HPP_