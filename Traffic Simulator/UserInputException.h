#include <stdexcept>
using namespace std;
class UserInputException : public runtime_error
{
public:
	UserInputException()
		:runtime_error("Invalid user input was used"){}


};