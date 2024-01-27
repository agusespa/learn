const canvas = document.getElementById('board');
const ctx = canvas.getContext('2d');
const gameOverImage = document.getElementById('game-over');
const block = 30;
const sequence = [];
const board = new Array(22).fill(0).map(() => new Array(10).fill(0));
const pieceSet = {
    0: [
        [0, 0, 0, 0],
        [1, 1, 1, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
    ],
    1: [
        [1, 0, 0],
        [1, 1, 1],
        [0, 0, 0],
    ],
    2: [
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0],
    ],
    3: [
        [1, 1],
        [1, 1],
    ],
    4: [
        [0, 1, 1],
        [1, 1, 0],
        [0, 0, 0],
    ],
    5: [
        [1, 1, 0],
        [0, 1, 1],
        [0, 0, 0],
    ],
    6: [
        [0, 1, 0],
        [1, 1, 1],
        [0, 0, 0],
    ],
};

let frameCount = 0;
let piece = getNextPiece();
let animation = null;
let gameOver = false;

function generateSequence() {
    for (i = 0; i < 10; i++) {
        sequence.push(Math.floor(Math.random() * 7));
    }
}

function getNextPiece() {
    // TODO display upcoming pieces
    if (sequence.length < 5) {
        sequence.concat(generateSequence());
    }

    const shape = pieceSet[sequence.pop()];
    return {
        shape,
        position: {
            topRow: 0,
            leftCol: board[0].length / 2 - Math.ceil(shape[0].length / 2),
        },
    };
}

function rotate() {
    return piece.shape[0].map((_, index) => piece.shape.map(row => row[index]).reverse());
}

function isValidMove(shape, nextCol, nextRow) {
    for (let row = 0; row < shape.length; row++) {
        for (let col = 0; col < shape[0].length; col++) {
            let pieceBlockVal = shape[row][col];
            if (pieceBlockVal === 0) continue;

            // check if falls off the board
            let pieceElAbsCol = piece.position.leftCol + col;
            let pieceElAbsRow = piece.position.topRow + row;
            if (
                pieceElAbsCol + (nextCol - piece.position.leftCol) > 9 ||
                pieceElAbsCol + (nextCol - piece.position.leftCol) < 0 ||
                pieceElAbsRow + (nextRow - piece.position.topRow) > 21
            )
                return false;

            // check collision with placed pieces
            let boardElVal = board[nextRow + row][nextCol + col];
            if (boardElVal === 1) return false;
        }
    }
    return true;
}

function placePiece() {
    for (let row = 0; row < piece.shape.length; row++) {
        for (let col = 0; col < piece.shape[0].length; col++) {
            let relRow = piece.position.topRow + row;
            let relCol = piece.position.leftCol + col;
            if (piece.shape[row][col]) board[relRow][relCol] = piece.shape[row][col];

            // check if piece reaches the top of the board
            if (piece.shape[row][col] === 1 && relRow < 3) displayGameOver();
        }
    }

    checkCompleteLines();

    piece = getNextPiece();
}

function checkCompleteLines() {
    let row = board.length - 1;
    while (row > 0) {
        if (board[row].every(e => e === 1)) {
            for (let r = row; r > 0; r--) {
                for (let c = 0; c < board[0].length; c++) {
                    board[r][c] = board[r - 1][c];
                }
            }
        } else {
            row--;
        }
    }
}

function displayGameOver() {
    cancelAnimationFrame(animation);
    gameOver = true;

    ctx.fillStyle = 'black';
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    ctx.drawImage(gameOverImage, 0, 150);

    ctx.fillStyle = 'red';
    ctx.textAlign = 'center';
    ctx.font = '30px Arial';
    ctx.fillText('GAME OVER', canvas.width / 2, 100);
}

document.addEventListener('keydown', function (e) {
    if (gameOver) return;

    if (e.key === 'ArrowLeft' || e.key === 'ArrowRight') {
        const nextCol = e.key === 'ArrowLeft' ? piece.position.leftCol - 1 : piece.position.leftCol + 1;

        if (isValidMove(piece.shape, nextCol, piece.position.topRow)) {
            piece.position.leftCol = nextCol;
        }
    }

    if (e.key === 'ArrowUp') {
        const shape = rotate();
        if (isValidMove(shape, piece.position.leftCol, piece.position.topRow)) {
            piece.shape = shape;
        }
        // allow rotation with horizontal displacement
        else {
            let nextCol = piece.position.leftCol < 5 ? piece.position.leftCol + 1 : piece.position.leftCol - 1;
            // allow for two displacements to accomodate for all pieces dimentions
            for (let i = 0; i < 2; i++) {
                if (isValidMove(shape, nextCol, piece.position.topRow)) {
                    piece.position.leftCol = nextCol;
                    piece.shape = shape;
                    break;
                } else nextCol = piece.position.leftCol < 5 ? nextCol + 1 : nextCol - 1;
            }
        }
    }

    if (e.key === 'ArrowDown') {
        const row = piece.position.topRow + 1;

        if (isValidMove(piece.shape, piece.position.leftCol, row)) {
            piece.position.topRow = row;
        } else {
            placePiece();
        }
    }
});

function animate() {
    animation = requestAnimationFrame(animate);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = 'green';
    frameCount++;

    // draw board
    for (let row = 2; row < board.length; row++) {
        for (let col = 0; col < board[0].length; col++) {
            if (board[row][col] === 1) {
                ctx.fillRect(col * block, (row - 2) * block, block, block);
            }
        }
    }

    // draw current piece
    for (let row = 0; row < piece.shape.length; row++) {
        for (let col = 0; col < piece.shape[0].length; col++) {
            if (piece.shape[row][col] === 1)
                ctx.fillRect(
                    (piece.position.leftCol + col) * block,
                    (piece.position.topRow + row - 2) * block,
                    block,
                    block
                );
        }
    }

    // TODO use elapsed time instead of frame counts
    // move or place current piece
    if (frameCount > 40) {
        let nextRow = piece.position.topRow + 1;
        if (!isValidMove(piece.shape, piece.position.leftCol, nextRow)) {
            placePiece();
        } else {
            piece.position.topRow = nextRow;
        }
        frameCount = 0;
    }
}

animate();
