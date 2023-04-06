const readline = require('readline-sync');
const { performance } = require('perf_hooks');
const { createInterface } = require('readline');
const rl = createInterface({
    input: process.stdin,
    output: process.stdout
});

function boardSize() {
    while (true) {
        console.log("Board Size:\nSmall(1)\tMedium(2)\tLarge(3)\nSelection: ");
        const selection = parseInt(readline.question("Selection: "));
        if (isNaN(selection)) {
            console.log("\nInvalid selection\n");
            continue;
        }
        switch (selection) {
            case 1:
                return "5x5";
            case 2:
                return "7x7";
            case 3:
                return "9x9";
            default:
                console.log("\nInvalid selection\n");
        }
    }
}

function boardSetup(bSize, board) {//creates a board of the given size filled with '1s and 2s's
    const rows = parseInt(bSize.split("x")[0]);
    const coll = parseInt(bSize.split("x")[1]);
    console.log(rows + "x" + coll);//outputs board size

    for (let i = 0; i < rows; i++) {//creating the board of 1s and 2s
        const empt = [];
        for (let j = 0; j < coll; j++) {
            const random = Math.floor(Math.random() * 2) + 1;
            empt.push(random);
        }
        board.push(empt);
    }

    const randomRow = Math.floor(Math.random() * rows);
    const randomCol = Math.floor(Math.random() * coll);
    board[randomRow][randomCol] = 3; //adding the "player"

    const randomRow2 = Math.floor(Math.random() * rows);
    const randomCol2 = Math.floor(Math.random() * coll);
    board[randomRow2][randomCol2] = 4; //adding the "exit"

    for (let i = 0; i < board.length; i++) {//outputs the board, can be removed if not needed
        console.log(board[i].join(" "));
    }
}
