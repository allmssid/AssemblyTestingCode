#include <iostream>
#include <ctime>
using namespace std;

int rnd(const int min = 0, const int max = 100) {
	return rand() % (max - min) + min;
}

int main() {
	srand((unsigned)time(0));

	int a = rnd(), b = rnd(), c = rnd(), cCpp = 0, cAsm = 0;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	cCpp = a - ( b + c);
	
	__asm {
		mov eax, a
		mov ebx, b
		add ebx, c
		sub eax, ebx
		mov cAsm, eax
	}

	cout << "[C++]: " << cCpp << endl;
	cout << "[ASM]: " << cAsm << endl;
	
	system("pause");
	return 0;
}
