#include <iostream>
#include <random>
int** sozdat_matrix(int& str, int& stolb) {
	
	std::cout << "skolko strok"<<std::endl;
	std::cin >> str;
	std::cout << "skolko stolbcov"<<std::endl;
	std::cin >> stolb;
	int** matrix = new int*[str];
	for (int  i = 0; i < str; ++i) {
		matrix[i] = new int[stolb];	
	}
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dist(1, 100);
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < stolb; ++j) {
			matrix[i][j] = dist(gen); 
		}
	}
	return matrix;
}
int** next_matrix(int** matrix, int str, int stolb) {
	int** mutant_matrix = new int*[str];
	for (int  i = 0; i < str; ++i) {
		mutant_matrix[i] = new int[stolb];
	}
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < stolb; ++j) {
			int stolb_sum = 0;
			int str_sum = 0;
			
			for (int k = 0; k < stolb; ++k) {
				str_sum += matrix[i][k];
			}
			for (int p = 0; p < str; ++p){
				stolb_sum += matrix[p][j];
			}
			mutant_matrix[i][j] = str_sum + stolb_sum - matrix[i][j];
		}
	}

	return mutant_matrix;
}
void pokaz_matrix(int** matrix, int str, int stolb) {
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < stolb; ++j) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
void pokaz_global(int** matrix, int** mutant, int str, int stolb) {
	std::cout << std::endl << "Bilo" << std::endl;
	pokaz_matrix(original, str, stolb);

	std::cout << std::endl << "Stalo" << std::endl;
	pokaz_matrix(modified, str, stolb);
}




int main() {
	int str = 0, stolb = 0;
	int** matrix = sozdat_matrix(str, stolb);
	int** mutant = next_matrix(matrix, str, stolb);
	pokaz_global(matrix, mutant, str, stolb);
	for (int i = 0; i < str; ++i) {
		delete[]matrix[i];
		delete[]mutant[i];
	}
	delete[]matrix;
	delete[]mutant;
	return 0;
}
