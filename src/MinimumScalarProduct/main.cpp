// +-------------------------------------------------------------+
// | Minimum Scalar Product                                      |
// | http://code.google.com/codejam/contest/32016/dashboard#s=p0 |
// +-------------------------------------------------------------+
#include "../codejam.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <set>

class MinScalProd : public Codejam
{
public:

  // TEST DATA
  typedef struct {
    std::multiset<int> set1;
    std::multiset<int> set2;
  } data_t;

  // OUTPUT DATA
  typedef long long int output_t;

public:

  MinScalProd( int argc, const char** argv )
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
void MinScalProd::get_test() 
{

  // clear any old states
  m_data.set1.clear();
  m_data.set2.clear();
  
  int vec_size;
  m_in >> vec_size;

  // read first set
  int tmp;
  for (int j=0; j<vec_size; j++)
  {
    m_in >> tmp;
    m_data.set1.insert( tmp );
  }

  // read second set
  for (int j=0; j<vec_size; j++)
  {
    m_in >> tmp;
    m_data.set2.insert( tmp );
  }

}

// +-------+
// | DEBUG |
// +-------+ 
void MinScalProd::debug() const 
{
  // implement debug() here
}

// +-------+
// | SOLVE |
// +-------+
void MinScalProd::solve() 
{

  std::multiset<int>::const_iterator it1;
  std::multiset<int>::const_reverse_iterator it2 = m_data.set2.rbegin();
  m_output = 0;
  for ( it1=m_data.set1.begin(); it1!=m_data.set1.end(); it1++, it2++ )
    m_output += static_cast<long long int>(*it1) * (*it2);

}

// +--------------+
// | WRITE_OUTPUT |
// +--------------+
void MinScalProd::write_output( int i ) 
{

  m_out << "Case #" << i << ": " << m_output << std::endl;

}

// +------+
// | MAIN |
// +------+
int main( int argc, const char** argv )
{

  try {

    MinScalProd prob( argc, argv );

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