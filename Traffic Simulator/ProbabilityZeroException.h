#include <stdexcept>
using namespace std;
class ProbabilityZeroException : public runtime_error
{
public:
	ProbabilityZeroException()
		:runtime_error("Exception: Probability Value Zero Violation"){}


};