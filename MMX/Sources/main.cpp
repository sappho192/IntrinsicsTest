#include "main.h"

int main()
{
	if (!InstructionSet::MMX())
	{
		cout << "Your CPU doesn't support MMX." << endl;
		return 0;
	}
	high_resolution_clock::time_point t1, t2;
	duration<double> time;

	t1 = high_resolution_clock::now();
	for (short i = 0; i < 1000; i++)
	{
		addPlain();
	}
	t2 = high_resolution_clock::now();

	time = duration_cast<duration<double>>(t2 - t1);
	cout << std::fixed << "Elapsed time: " << time.count() << "seconds" << endl;

	t1 = high_resolution_clock::now();
	for (short i = 0; i < 1000; i++)
	{
		addMMX();
	}
	t2 = high_resolution_clock::now();

	
	time = duration_cast<duration<double>>(t2 - t1);
	cout << std::fixed << "Elapsed time: " << time.count() << "seconds" << endl;


	return 0;
}

void addPlain()
{
	int64_t x = 1024;
	int64_t y = 1024;
	int64_t result = x + y;
	//cout << "x: " << x << "\ty: " << y << endl;
	//cout << "x + y = " << result << endl;
}

void addMMX()
{
	__m64 a = _m_from_int(1024);
	__m64 b = _m_from_int(1024);

	__m64 result_m64 = _mm_add_pi32(a, b);
	//cout << "a: " << _m_to_int(a) << "\tb: " << _m_to_int(b) << endl;
	//cout << "a + b = " << _m_to_int(result_m64) << endl;
	_mm_empty();
}