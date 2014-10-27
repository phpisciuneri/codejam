#include "../codejam.hpp"

#include <iostream>
#include <string>
#include <map>

class StoreCredit : public Codejam
{
public:

  // TEST DATA
  typedef struct {
    int C;
    std::multimap< int, int > price_index;
  } data_t;

  // OUTPUT DATA
  typedef std::pair< int, int > output_t;

public:

  StoreCredit( int argc, const char** argv )
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
void StoreCredit::get_test() 
{

  // make sure map is empty
  m_data.price_index.clear();

  int I; // number of items in store
  m_in >> m_data.C >> I;

  // read first set
  int tmp;
  for (int j=1; j<=I; j++)
  {
    m_in >> tmp;
    m_data.price_index.insert( std::pair<int,int>(tmp,j) );
  }

}

// +-------+
// | DEBUG |
// +-------+ 
void StoreCredit::debug() const {}

// +-------+
// | SOLVE |
// +-------+
void StoreCredit::solve() 
{

  // find two items
  std::multimap< int, int >::const_iterator it1;
  std::multimap< int, int >::const_iterator it2;
  for ( it1=m_data.price_index.begin(); it1!=m_data.price_index.end(); it1++ )
  {
    it2 = m_data.price_index.find( m_data.C - it1->first );
    // match found if two conditions met:
    // 1. end of the list wasn't reached
    // 2. the corner case of finding the same element when P = C/2
    if ( ( it2 != m_data.price_index.end() ) && ( it2->second != it1->second ) )
    {
      if ( it2->second > it1->second )
      {
        m_output.first  = it1->second;
        m_output.second = it2->second;
      }
      else
      {
        m_output.first  = it2->second;
        m_output.second = it1->second;
      }
      break;
    }
  }

}

// +--------------+
// | WRITE_OUTPUT |
// +--------------+
void StoreCredit::write_output( int i ) 
{

  // write answer to output
  m_out << "Case #" << i << ": ";
  m_out << m_output.first << " " << m_output.second << std::endl;

}

// +------+
// | MAIN |
// +------+
int main( int argc, const char** argv )
{

  try {

    StoreCredit prob( argc, argv );

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