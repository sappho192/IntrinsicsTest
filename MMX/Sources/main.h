#pragma once
#include "../../CPUID/Sources/main.h"
using std::cout;
using std::endl;

// MMX header
#include <mmintrin.h>

// Benchmarking
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

void addPlain();
void addMMX();