#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <omp.h>

void clear(std::vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		v[i] = 0;
	}
}

void print(std::vector<int>& v) {
	for (int i = 0; i < 52; ++i) {
		std::cout << v[i];
	}
}

int main() {
	int som = 800;
	std::vector<int> matrix1(som * som);
	std::vector<int> matrix2(som * som);
	std::vector<int> result1(som * som);
	std::ifstream data("Data.txt");
	/*for (int i = 0; i < som*som; i++) {
		matrix1[i] = (rand() % 100 + 5);
		matrix2[i] = (rand() % 100 - i - 15);
	}
	std::ofstream data("Data.txt");
	for (int i = 0; i < som*som; i++) {
		data << matrix1[i] << " " << matrix2[i] << " ";
	}
	data.close();*/
	int temp;
	bool changer = true;
	int i1 = 0;
	int i2 = 0;
	while (data >> temp) {
		if (changer) {
			matrix1[i1] = temp;
			i1++;
		}
		else {
			matrix2[i2] = temp;
			i2++;
		}
		changer = !changer;
	}
	int s = 0;
	std::vector<int> sizes = { 100, 200, 300, 400, 800 };
	std::ofstream file("Time without.txt");
	while (s < sizes.size()) {
		clear(result1);
		const int size = sizes[s];
		auto start = std::chrono::steady_clock::now();
		for (int row = 0; row < size; ++row) {
			for (int col = 0; col < size; ++col) {
				int sum_result = 0;
				for (int i = 0; i < size; ++i) {
					sum_result += matrix1[row * size + i] * matrix2[col + i * size];
				}
				result1[row * size + col] = sum_result;
			}
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> elapsed = end - start;
		std::cout << std::endl;
		std::cout << "Matrix's size is: " << size << "x" << size << std::endl;
		std::cout << "Def meth\'s time: " << elapsed.count() << std::endl;
		std::cout << "_______________________________";
		s++;
		file << "\n";
		file << "Matrix's size is: " << size << "\n";
		file << "Def meth's time: " << elapsed.count() << "\n";
		file << "_______________________________";
	}
	file.close();
	std::cout << "______________________" << std::endl;
	std::cout << "With parallel" << std::endl;
	s = 0;
	std::ofstream file2("Time with omp.txt");
	while (s < sizes.size()) {
		clear(result1);
		const int size = sizes[s];
		auto start = std::chrono::steady_clock::now();
#pragma omp parallel for
		for (int row = 0; row < size; ++row) {
			for (int col = 0; col < size; ++col) {
				int sum_result = 0;
				for (int i = 0; i < size; ++i) {
					sum_result += matrix1[row * size + i] * matrix2[col + i * size];
				}
				result1[row * size + col] = sum_result;
			}
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> elapsed = end - start;
		std::cout << std::endl;
		std::cout << "Matrix's size is: " << size << "x" << size << std::endl;
		std::cout << "Def meth\'s time: " << elapsed.count() << std::endl;
		std::cout << "_______________________________";
		s++;
		file2 << "\n";
		file2 << "Matrix's size is: " << size << "\n";
		file2 << "Def meth's time: " << elapsed.count() << "\n";
		file2 << "_______________________________";
	}
	file2.close();
}