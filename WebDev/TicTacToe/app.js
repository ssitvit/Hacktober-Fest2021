//Player factory function to return player objects
const player = (playerNumber, playerType, playerMark, playerTurn) => {
    return { playerNumber, playerType, playerMark, playerTurn };
}

const player1 = player(1, 'human', 'X', true);
const player2 = player(2, 'human', 'O', false);

//Gameboard module to return gameboard object
const gameBoard = (() => {
    let board = [];
    let movesLeft = 9;
    let winner = null;
    let winnerHeading = document.getElementById("winner-heading");

    //Node list of all square grids
    let squareGridsList = document.querySelectorAll(".square-grid");

    for (let i = 0; i < squareGridsList.length; i++) {
        squareGridsList[i].addEventListener("click", () => {
            if (winner == null && movesLeft > 0) {
                if (player1.playerTurn == true && squareGridsList[i].textContent == "") {
                    board[i] = player1.playerMark;
                    squareGridsList[i].textContent = player1.playerMark;
                    squareGridsList[i].classList.add("square-grid-mark", "player1-mark");
                    squareGridsList[i].style.backgroundColor = "#ddd";
                    player1.playerTurn = false;
                    player2.playerTurn = true;
                }
                else if (player2.playerTurn == true && squareGridsList[i].textContent == "") {
                    board[i] = player2.playerMark;
                    squareGridsList[i].textContent = player2.playerMark;
                    squareGridsList[i].classList.add("square-grid-mark", "player2-mark");
                    squareGridsList[i].style.backgroundColor = "#ddd";
                    player1.playerTurn = true;
                    player2.playerTurn = false;
                }
                movesLeft--;
                winnerCheck();
            }
        })
    }

    //List of all winning positions
    const winConditions = [
        [0, 1, 2],
        [0, 3, 6],
        [0, 4, 8],
        [1, 4, 7],
        [2, 5, 8],
        [3, 4, 5],
        [6, 7, 8],
        [6, 4, 2]
    ];

    //Function to check winner status after every move
    function winnerCheck() {
        winConditions.forEach((e) => {
            if (board[e[0]] == "X" && board[e[1]] == "X" && board[e[2]] == "X") {
                winner = player1.playerNumber;
            }
            else if (board[e[0]] == "O" && board[e[1]] == "O" && board[e[2]] == "O") {
                winner = player2.playerNumber;
            }
        })
        winnerDisplay();
    }

    //Displays winner
    function winnerDisplay() {
        if (winner != null) {
                winnerHeading.textContent = `Player ${winner} has won the game!`;
        }
        else if (movesLeft == 0 && winner == null) {
            winnerHeading.textContent = "It's a tie.";
        }
    }

    return { board, movesLeft, winner };
})();