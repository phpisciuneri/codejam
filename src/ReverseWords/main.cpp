// +---------------------------------------------------------------+
// | Reverse Words                                                 |
// | https://code.google.com/codejam/contest/351101/dashboard#s=p1 |
// +---------------------------------------------------------------+
#include "../codejam.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class ReverseWords : public Codejam
{
public:

  // TEST DATA
  typedef std::vector< std::string > data_t;

public:

  ReverseWords( int argc, const char** argv )
    : Codejam( argc, argv ) {}

  void get_test();
  void debug() const;
  void solve();
  void write_output( int );

private:

  data_t   m_data;
  
};

// +----------+
// | GET_TEST |
// +----------+
void ReverseWords::get_test() 
{
  static bool first_call = true;

  std::string line;
  if ( first_call ) {
    // at the end of first line, must advance
    std::getline( m_in, line );
    first_call = false;
  }
  else
    // clear data for new test
    m_data.clear();

  std::string word;
  std::getline( m_in, line );
  std::istringstream iss( line );
  while ( iss >> word )
    m_data.push_back( word );

}

// +-------+
// | DEBUG |
// +-------+ 
void ReverseWords::debug() const 
{
  
  for (std::size_t i=0; i<m_data.size(); i++ )
    std::cout << m_data[i] << " ";
  std::cout << std::endl;

}

// +-------+
// | SOLVE |
// +-------+
void ReverseWords::solve() 
{
  // implement solve() here
}

// +--------------+
// | WRITE_OUTPUT |
// +--------------+
void ReverseWords::write_output( int i ) 
{

  m_out << "Case #" << i << ": ";
  for ( int i=m_data.size()-1; i>=0; i-- )
    m_out << m_data[i] << " ";
  m_out << std::endl;

}

// +------+
// | MAIN |
// +------+
int main( int argc, const char** argv )
{

  try {

    ReverseWords prob( argc, argv );

    int N = prob.get_num_tests();

    // loop over all tests
    for ( int i=1; i<=N; i++ )
    {

      prob.get_test();

      // call debug function if desired
      //prob.debug();

      //prob.solve();

      prob.write_output( i );

    }

  }
  catch( const std::string& emesg )
  {
    std::cout << "Error: " << emesg << std::endl;
  }

  return 0;

}
