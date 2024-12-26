#pragma once
/*

function square_roots:
	- returns : void
	- arguments: ostream& ostream, int num
	- body:
		- instantiate an osyncstream with the outstream
		- loop from 0 to num:
			- syncStrm << "squareroot of " << i << " is "  << std::sqrt(i) << '\n' <<
			- ^^ don't forget to flush!

void for_main:
	- ofstream for a file names "tmp_noor.out"
	- launch 3 jthreads with args: square_roots, a reference to the file_stream, 5
*/
#include <fstream>
#include <syncstream>
#include <thread>
#include <cmath>
#include <iostream>

void square_roots(int num, std::ostream& ostream = std::cout)
{
	std::osyncstream osyncstream{ ostream };
	for (int i{ 0 }; i < num; ++i)
	{
		osyncstream << "squareroot of " << i << " is " << std::sqrt(i) << '\n' << std::flush_emit;
	}
}

void for_main()
{
	std::ofstream ofstream{ "tmp_noor.out" };
	std::jthread jt0{ square_roots, 5, std::ref(ofstream) };
	std::jthread jt1{ square_roots, 5, std::ref(ofstream) };
	std::jthread jt2{ square_roots, 5, std::ref(ofstream) };
}