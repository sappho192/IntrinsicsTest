#include "main.h"

int main()
{
	static const short LOOP_TIME = 1000;

	if (!InstructionSet::MMX())
	{
		cout << "Your CPU doesn't support MMX." << endl;
		return 0;
	}
	high_resolution_clock::time_point t1, t2;
	duration<double> time;

	t1 = high_resolution_clock::now();
	for (short i = 0; i < LOOP_TIME; i++)
	{
		addPlain();
	}
	t2 = high_resolution_clock::now();

	time = duration_cast<duration<double>>(t2 - t1);
	cout << std::fixed << "Elapsed time: " << time.count() << "seconds" << endl;

	t1 = high_resolution_clock::now();
	for (short i = 0; i < LOOP_TIME; i++)
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
	int x[2] = { 512, 1024 };
	int y[2] = { 512, 1024 };
	int result[2] = { x[0] + y[0], x[1] + y[1] };
	//cout << "x: " << x << "\ty: " << y << endl;
	//cout << "x + y = " << result << endl;
}

void addMMX()
{
	__m64 x = _mm_set_pi32(1024, 512);
	__m64 y = _mm_set_pi32(1024, 512);

	__m64 result = _mm_add_pi32(x, y);
	//cout << "a: " << _m_to_int(a) << "\tb: " << _m_to_int(b) << endl;
	//cout << "a + b = " << _m_to_int(result_m64) << endl;
	
	_mm_empty(); // Should be essential when we've used MMX before.
}