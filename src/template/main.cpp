#include "../codejam.hpp"

#include <iostream>
#include <string>

class Problem : public Codejam
{
public:

  // TEST DATA
  // typedef test_data_type data_t

  // OUTPUT DATA
  // typedef output_data_type output_t

public:

  Problem( int argc, const char** argv )
    : Codejam( argc, argv ) {}

  void get_test();
  void debug() const;
  void solve();
  void write_output( int );

private:

  data_t   m_data;
  output_t m_output;
  
};

// +----------+
// | GET_TEST |
// +----------+
void Problem::get_test() 
{
  // implement get_test() here
}

// +-------+
// | DEBUG |
// +-------+ 
void Problem::debug() const 
{
  // implement debug() here
}

// +-------+
// | SOLVE |
// +-------+
void Problem::solve() 
{
  // implement solve() here
}

// +--------------+
// | WRITE_OUTPUT |
// +--------------+
void Problem::write_output( int i ) 
{
  // implement write_output here
}

// +------+
// | MAIN |
// +------+
int main( int argc, const char** argv )
{

  try {

    Problem prob( argc, argv );

    int N = prob.get_num_tests();

    // loop over all tests
    for ( int i=1; i<=N; i++ )
    {

      prob.get_test();

      // call debug function if desired
      //prob.debug();

      prob.solve();

      prob.write_output( i );

    }

  }
  catch( const std::string& emesg )
  {
    std::cout << "Error: " << emesg << std::endl;
  }

  return 0;

}