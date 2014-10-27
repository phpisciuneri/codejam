#include "codejam.hpp"

#include <string>

// +-------------+
// | CONSTRUCTOR |
// +-------------+
Codejam::Codejam( int argc, const char** argv ) 
{

  // expect filename as first arg
  if ( argc < 2 ) 
    throw std::string("Input filename expected as argument.");
  std::string filename = argv[1];

  // open input file for reading
  m_in.open( filename.c_str(), std::ifstream::in );
  if ( m_in.fail() ) 
  {
    std::string emesg = "Cannot open file " + filename;
    throw emesg;
  }

  // open output file writing
  m_out.open( "output.txt", std::ofstream::out );
  if ( m_out.fail() ) 
    throw std::string( "Cannot create output.txt" );

}

// +---------------+
// | GET_NUM_TESTS |
// +---------------+
int Codejam::get_num_tests()
{
  int N;
  m_in >> N;
  return N;
}

