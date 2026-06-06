#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <fstream>
#include <string>

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

static const int MATRIX_DIMENSIONS = 3;

using Position = std::pair<int, int>;
using Sequence = std::set<Position>;
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
			sequence.insert({ j, i });
		}
		winningSequences.push_back(sequence); 
	}

	// Add the winning sequences corresponding to columns
	// in the winningSequences variable.
	for (size_t i = 0; i < matrixDimension; i++) {
		Sequence sequence;
		for (size_t j = 0; j < matrixDimension; j++) {
			sequence.insert({ i, j });
		}
		winningSequences.push_back(sequence);
	}

	// Add the winning sequence (1) corresponding to the leading diagonal
	// in the winningSequences variable.
	Sequence leadingDiagonalSequence;
	for (size_t i = 0; i < matrixDimension; i++) {
		leadingDiagonalSequence.insert({ i, i });
	}
	winningSequences.push_back(leadingDiagonalSequence);

	// Add the winning sequence (1) corresponding to the non leading diagonal
	// in the winningSequences variable.
	Sequence nonLeadingDiagonalSequence;
	for (size_t i = 0; i < matrixDimension; i++) {
		nonLeadingDiagonalSequence.insert({ i,matrixDimension - i - 1 });
	}
	winningSequences.push_back(nonLeadingDiagonalSequence);

	return winningSequences;
}

/// <summary>
/// Checks if a position is found inside a player's sequence.
/// </summary>
/// <param name="playerSequence">Player sequence obtained from game.</param>
/// <param name="position">Any position inside the tic-tac-toe game.</param>
/// <returns>"true", if the player's sequence contains the specified game position.</returns>
bool playerContainsPosition(const Sequence& playerSequence, const Position& position)
{
	for (const auto& pos : playerSequence) {
		if (position == pos) {
			return true;
		}
	}
	return false;
}

/// <summary>
/// Checks if  player has won based on the player's sequence and the entire winning
/// sequences.
/// </summary>
/// <param name="playerSequence">The sequence obtained from the players in the game.</param>
/// <param name="winningSequences">All the possible winning sequences of the game.</param>
/// <returns>
/// "true" if a player's sequence contains at least one complete winning
/// sequence.
/// </returns>
bool hasWon(const Sequence& playerSequence, const WinningSequence& winningSequences)
{
	for (const auto& winningSequence : winningSequences) {
		bool completeWinningSequence = true;
		for (const auto& position : winningSequence) {
			if (!(playerContainsPosition(playerSequence, position))) {
				completeWinningSequence = false;
				break;
			}
		}
		if (completeWinningSequence) {
			return true;
		}
	}
	return false;
}

/// <summary>
/// Checks which player wins based on the final positions of the players (o and x) inside
/// the game.
/// </summary>
/// <param name="oSequence">The final game sequence for the player "o".</param>
/// <param name="xSequence">The final game sequence for the player "x".</param>
/// <param name="winningSequences">All the possible winning sequences.</param>
void identifyWinner(const Sequence& oSequence, const Sequence& xSequence,
	const WinningSequence& winningSequences)
{
	bool oPlayerWins = hasWon(oSequence, winningSequences);
	bool xPlayerWins = hasWon(xSequence, winningSequences);

	if (oPlayerWins && xPlayerWins) {
		std::cout << "This game state is invalid, please, check the positions again." << std::endl;
	}
	else if (oPlayerWins) {
		std::cout << "The player 'O' has won. " << std::endl;
	}
	else if (xPlayerWins) {
		std::cout << "The player 'X' has won. " << std::endl;
	}
	else {
		std::cout << "Draw ! None of the player has won." << std::endl;
	}
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

void readGame(const std::string& filename, 
	Sequence& oSequence, Sequence& xSequence)
{
	std::ifstream file(filename);

	if (!file) {
		std::cerr << "The file could not be opened. \n";
		return;
	}

	char cellEntry;

	for (std::size_t row = 0; row < MATRIX_DIMENSIONS; row++) {
		for (std::size_t column = 0; column < MATRIX_DIMENSIONS; column++) {
			file >> cellEntry;

			if (cellEntry == 'x')
			{
				xSequence.insert({ row, column });
			}
			else {
				oSequence.insert({ row, column });
			}
		}
		
	}
}



int main()
{
	WinningSequence winningSequences = setWinningSequences(MATRIX_DIMENSIONS);
	printWinningSequences(winningSequences);
	std::cout << std::endl;

	// Five files have been proposed to test the code.
	std::size_t nFilesToRead = 5;
	for (std::size_t i = 0; i < nFilesToRead; i++) {

		Sequence oSequence;
		Sequence xSequence;
		
		std::cout << "Game " << (i + 1) << " : " << std::endl;

		std::string fileName = "grille" + std::to_string(i + 1) + ".txt";
		readGame(fileName, oSequence, xSequence);
		identifyWinner(oSequence, xSequence, winningSequences);
		std::cout << std::endl;
	}
}
