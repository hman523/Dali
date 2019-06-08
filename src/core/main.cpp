#include <iostream>

int main(int argc, char *argv[]){
	std::cout << "Starting Dali Compiler" << std::endl;
	if (argc != 2){
		std::cout << "Need a file to compile" << std::endl;
		exit(1);
	}

	

	return 0;
}
