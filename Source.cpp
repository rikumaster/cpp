#include "Control.h"

int main() {
	FreeConsole();
	Control * c = new Control(40, 30);
	c->generateLife();
	delete c;
}