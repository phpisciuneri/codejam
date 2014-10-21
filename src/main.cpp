// +-------------------------------------------------------------+
// | Minimum Scalar Product                                      |
// | http://code.google.com/codejam/contest/32016/dashboard#s=p0 |
// +-------------------------------------------------------------+
#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main( int argc, const char** argv )
{

  try {

    // expect filename as first arg
    if ( argc < 2 ) 
      throw std::string("Input filename expected as argument.");
    std::string filename = argv[1];

    // open input file
    std::ifstream in;
    in.open( filename.c_str(), std::ifstream::in );
    if ( in.fail() ) 
    {
      std::string emesg = "Cannot open file " + filename;
      throw emesg;
    }

    // open output file
    std::ofstream out;
    out.open( "output.txt", std::ofstream::out );
    if ( out.fail() ) 
      throw std::string( "Cannot create output.txt" );

    // read input file
    int T;
    in >> T;
    for (int i=0; i<T; i++)
    {

      int vec_size;
      in >> vec_size;

      // read first set
      int tmp;
      std::multiset<int> set1;
      for (int j=0; j<vec_size; j++)
      {
        in >> tmp;
        set1.insert( tmp );
      }

      // read second set
      std::multiset<int> set2;
      for (int j=0; j<vec_size; j++)
      {
        in >> tmp;
        set2.insert( tmp );
      }

      // calculate minimum
      std::multiset<int>::const_iterator it1;
      std::multiset<int>::const_reverse_iterator it2 = set2.rbegin();
      long long int sum = 0;
      for ( it1=set1.begin(); it1!=set1.end(); it1++, it2++ )
        sum += static_cast<long long int>(*it1) * (*it2);

      // write answer to output
      out << "Case #" << i+1 << ": " << sum << std::endl;

    }


  }
  catch( const std::string& emesg )
  {
    std::cout << "Error: " << emesg << std::endl;
  }

  return 0;
}