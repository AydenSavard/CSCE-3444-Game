const readline = require('readline-sync');
const boardSetup = require('./boardSetup.js'); // assuming boardSetup.js exports boardSetup function
const player = require('./player.js'); // assuming player.js exports player function
const players = require('./players.js'); // assuming players.js exports players function

let board = [];
let bSize = boardSize(); // assuming the boardSize function is defined

boardSetup(bSize, board);
