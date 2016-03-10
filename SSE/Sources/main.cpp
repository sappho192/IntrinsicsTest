#include "main.h"

int main()
{
	if (!InstructionSet::SSE())
	{
		cout << "Your CPU doesn't support SSE." << endl;
		return 0;
	}



	return 0;
}