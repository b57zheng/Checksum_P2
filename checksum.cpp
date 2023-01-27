#include <iostream>
#include <climits>

unsigned int add_checksum( unsigned int n );
void add_checksum( unsigned int array[], std::size_t capacity );
bool verify_checksum( unsigned int n );
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() 
{
	unsigned int value_to_protect{21352411};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect << " with the checksum added is " << protected_value << "." << std::endl;
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else 
	{
		std::cout << "The checksum is invalid." << std::endl;
	}
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	add_checksum(value_series, QTY_VALUES);
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0}; series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}
	std::cout << std::endl;
	return 0;
}
#endif

unsigned int add_checksum( unsigned int n )
{
    int counter{0};
    int digit (n%10);
    int sum{};
    int d{};
    int initial_n (n);
    
    if(n > 99999999)
    {
      return UINT_MAX;
    }
    else 
    {
      while (n != 0)
      {
          digit = n%10;
          if (counter%2 == 0)
        { 
          digit = 2*(n%10);
          if (digit > 9)
          {
            digit = digit%10 + 1;
          }
        }
          n = n/10;
          counter = counter + 1;
          sum = sum + digit;
      }
      sum = sum*9;
      d = sum%10;
      initial_n = initial_n*10 + d;
    }
    return initial_n;
}

void add_checksum( unsigned int array[], std::size_t capacity )
{
	for (int i{0}; i <= (capacity - 1); ++i)
  {
    add_checksum(array[i]); 
  }
}

bool verify_checksum( unsigned int n )
{
	if (n < 1000000000)
   {
	   if (n == add_checksum(n/10)) 
	   {
			return true;
	   }
   }
	return false;
}

unsigned int remove_checksum( unsigned int n )
{
  if (verify_checksum(n)) {
    return n/10;
  }
  else
  {
    return UINT_MAX;
  }
}

void remove_checksum( unsigned int array[], std::size_t capacity )
{
	for (int i{0}; i <= (capacity - 1); ++i)
  {
    remove_checksum( array[i] );
  }
}