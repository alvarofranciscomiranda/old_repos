/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
}

/**
 * Inicia um Sudoku com um conteúdo inicial.
 * Lança excepção IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem números repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Obtem o conteúdo actual (só para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku já está completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
}



/**
 * Resolve o Sudoku.
 * Retorna indicação de sucesso ou insucesso (sudoku impossível).
 */
bool Sudoku::solve()
{
	if(isComplete())
		return true;

	int i, j;
	if(!findBestCell(i,j))
		return false;

	for(int n = 1; n < 10; n++){
		if(accepts(i,j,n)){
			place(i,j,n);
			if(solve())
				return true;
			remove(i,j,n);
		}
	}
	return false;
}

bool Sudoku::findBestCell(int &best_i, int &best_j){

	best_i = -1;
	best_j = -1;
	int best_choice = 10;

	for(int i = 0; i < 9; i++){//lines
		for(int j = 0; j < 9; j++){//collums

			if(this->numbers[i][j] == 0){ //only continues if is 0

			int choice = 0;
			for(int k = 1; k < 10; k++){ //amount of possibilities of a cell
				if(accepts(i,j,k))
					choice++;
			}

			if(choice == 0) //impossible
				return false;

			if(choice > best_choice){
				choice = best_choice;
				best_i = i;
				best_j = j;
				}
			if(choice == 1)
				return true;
			}
		}
	}
	return false;
}

//see if i accepts a certain value at a position
bool Sudoku::accepts(int i, int j, int number){
	if(!this->lineHasNumber[i][number] && !this->columnHasNumber[j][number] && !this->block3x3HasNumber[i/3][j/3][number])
		return true;
	return false;
}

//place a value in sudoku
void Sudoku::place(int i, int j, int number){
	this->numbers[i][j] = number;
	this->countFilled++;
	this->lineHasNumber[i][number] = true;
	this->columnHasNumber[j][number] = true;
	this->block3x3HasNumber[i/3][j/3][number] = true;

}

//removes a value in sudoku
void Sudoku::remove(int i, int j, int n){
	this->numbers[i][j] = 0;
	this->countFilled--;
	this->lineHasNumber[i][n] = false;
	this->columnHasNumber[j][n] = false;
	this->block3x3HasNumber[i/3][j/3][n] = false;
}

/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}
