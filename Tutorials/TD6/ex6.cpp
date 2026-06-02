#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

// The aim of this file is to find which player wins a Tic-Tac-Toe game.
// The Tic-Tac-Toe player positions are read from external files.

// For a 3 by 3 Tic-Tac-Toe, the winning sequences are
// Rows: [(0,0)(0,1)(0,2)], [(1,0)(1,1)(1,2)], [(2,0)(2,1)(2,2)].
// Columns: [(0, 0)(1, 0)(2, 0)], [(0, 1)(1, 1)(2, 1)], [(0, 2)(1, 2)(2, 2)].
// Diagonals : [(0, 0)(1, 1)(2, 2)], [(0, 2)(1, 1)(2, 0)].

// In this code, the winning sequences are set for an n by n matrix.
// Hence, the code can handle Tic-Tac-Toe games of dimensions > 3.
// For a 3 by 3 Tic-Tac-Toe, the number of dimensions is going to be set
// to 3.

// Each sequence is constituted of n positions. Each position is a point
// with two axes value.Hence, for clarity, alias are used. 

using Position = std::pair<int, int>;
using Sequence = std::vector<Position>;
using WinningSequence = std::vector<Sequence>;


/// <summary>
/// This function sets the winning sequenes of the Tic-Tac-Toe game, based
/// on the number of dimensions of the n by n matrix.
/// </summary>
/// <param name="matrixDimension">The number of dimensions of the square matrix.</param>
/// <returns></returns>
WinningSequence setWinningSequences(int matrixDimension) {

	// Initiaalize an empty winning sequence.
	WinningSequence winningSequences;

	// Add the winning sequences corresponding to rows
	// in the winningSequences variable.
	for (size_t i = 0; i < matrixDimension; i++) {
		Sequence sequence;
		for (size_t j = 0; j < matrixDimension; j++) {
			sequence.push_back({ j, i });
		}
		winningSequences.push_back(sequence); 
	}

	// Add the winning sequences corresponding to columns
	// in the winningSequences variable.
	for (size_t i = 0; i < matrixDimension; i++) {
		Sequence sequence;
		for (size_t j = 0; j < matrixDimension; j++) {
			sequence.push_back({ i, j });
		}
		winningSequences.push_back(sequence);
	}

	// Add the winning sequence (1) corresponding to the leading diagonal
	// in the winningSequences variable.
	Sequence leadingDiagonalSequence;
	for (size_t i = 0; i < matrixDimension; i++) {
		leadingDiagonalSequence.push_back({ i, i });
	}
	winningSequences.push_back(leadingDiagonalSequence);

	// Add the winning sequence (1) corresponding to the non leading diagonal
	// in the winningSequences variable.
	Sequence nonLeadingDiagonalSequence;
	for (size_t i = 0; i < matrixDimension; i++) {
		nonLeadingDiagonalSequence.push_back({ i,matrixDimension - i - 1 });
	}
	winningSequences.push_back(nonLeadingDiagonalSequence);

	return winningSequences;
}


/// <summary>
/// This function check if a target sequence is found in the list of 
/// winning sequences of Tic-Tac-Toe game.
/// </summary>
/// <param name="winningSequences">
/// The vector containing all the winning sequences of the game.
/// </param>
/// <param name="sequence">The target sequence</param>
/// <returns>
/// True if the target sequence is found in the winning sequences. Otherwise,
/// returns false.
/// </returns>
bool isInWinningSequences(WinningSequence winningSequences, Sequence sequence) {
	for (const auto& winningSequence : winningSequences) {
		if (winningSequence == sequence) {
			return true;
		}
	}
	return false;
}


/// <summary>
/// This is a function used to print all the winning sequences in
/// a Tic-Tac-Toe game of n dimensions, where n corresponds to the
/// size of the square matrix.
/// </summary>
/// <param name="winningSequences">A vector of all the winning sequences.</param>
void printWinningSequences(WinningSequence winningSequences) {
	for (const auto& sequence : winningSequences) {
		std::cout << "[";
		for (const auto& couple : sequence) {
			std::cout << "(" << couple.first << ", " << couple.second << ")";
		}
		std::cout << "]  ";
	}
	std::cout << std::endl;
}

void readGame(Sequence& oSequence, Sequence& xSequence)
{

}



int main()
{
	int matrixDimension = 3;
	WinningSequence winningSequences = setWinningSequences(matrixDimension);
	printWinningSequences(winningSequences);

	Sequence testSequence = {{0, 0}, { 1, 1 }, { 2, 2 }};
	std::cout << "In winning sequence " << isInWinningSequences(winningSequences, testSequence) << std::endl;


}
