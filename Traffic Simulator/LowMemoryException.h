#include <stdexcept>
using namespace std;
class LowMemoryException : public runtime_error
{
public:
	LowMemoryException()
		:runtime_error("Little to no memory is currently available on this system"){}


};