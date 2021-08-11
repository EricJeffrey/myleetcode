/*
  Copyright Islam El-Ashi <islam@elashi.me>

  This file is part of El-Tetris.

  El-Tetris is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  El-Tetris is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with El-Tetris.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * Handles game dynamics (Choosing a piece, placing a piece, etc...)
 */

/**
 * Initialize an El-Tetris game.
 *
 * Args:
 *  number_of_columns - Number of columns in the tetris game.
 *  number_of_rows - Number of rows in the tetris game.
 */
function ElTetris(number_of_columns, number_of_rows) {
  this.number_of_rows = number_of_rows;
  this.number_of_columns = number_of_columns;
  this.rows_completed = 0;

  // The board is represented as an array of integers, one integer for each row.
  this.board = new Array(number_of_rows);
  for (var i = 0; i < number_of_rows; i++) {
    this.board[i] = 0;
  }

  this.FULLROW = Math.pow(2, number_of_columns) - 1;
}

ElTetris.prototype.play = function () {
  var piece = this.getTenNextPiece(true);
  // var piece = this.getRandomPiece();
  var move = this.pickMove(piece, this.getTenNextPiece(false), this.getTenNextPiece(false, 2));

  if (window.tttt.brickCount % 100 == 0) {
    console.log(tttt.brickCount);
  }
  if (move.column == -1) {
    return { game_over: true };
  }

  var last_move = this.playMove(this.board, move.orientation, move.column, piece[move.orientation_index]);
  if (this.board[19] & 0xffff > 0) {
  }

  if (!last_move.game_over) {
    this.rows_completed += last_move.rows_removed;
  }

  return last_move;
};

/**
 * Pick the best move possible (orientation and location) as determined by the
 * evaluation function.
 *
 * Given a tetris piece, tries all possible orientations and locations and to
 * calculate (what it thinks) is the best move.
 *
 * Args:
 *  piece - A tetris piece.
 *
 * Returns:
 *   An object containing the following attributes:
 *     * orientation - The orientation of the piece to use.
 *     * column - The column at which to place the piece.
 */
ElTetris.prototype.pickMove = function ({ piece, stateIndex }, { nextPiece, stateIndex: nextStateIndex }, { nextNextPiece, stateIndex: nnStateIndex }) {
  console.log(stateIndex, nextStateIndex, nnStateIndex);
  var best_evaluation = -10000000;
  var best_orientation = 0;
  var best_column = -1;

  var best_rowsRemoved = 0;
  var best_occupiedGridCount = 0;
  var best_landingHeight = 0;

  // Evaluate all possible orientations
  for (var i in piece) {
    var orientation = piece[i].orientation;

    // Evaluate all possible columns
    for (var j = 0; j < this.number_of_columns - piece[i].width + 1; j++) {
      // Copy current board
      var board = this.board.slice();
      var last_move = this.playMove(board, orientation, j, piece[i]);

      // if (!last_move.game_over) {
      //   evaluation = this.evaluateBoard(last_move, board);

      //   if (evaluation > best_evaluation) {
      //     best_evaluation = evaluation;
      //     best_orientation = i;
      //     best_column = j;
      //     best_rowsRemoved = last_move.rows_removed;
      //     best_occupiedGridCount = last_move.occupiedGridCount;
      //     best_landingHeight = last_move.landing_height;
      //   }
      // }

      if (!last_move.game_over) {

        for (var ii in nextPiece) {
          for (var jj = 0; jj < this.number_of_columns - nextPiece[ii].width + 1; jj++) {
            let board2 = board.slice();
            let last_move2 = this.playMove(board2, nextPiece[ii].orientation, jj, nextPiece[ii])

            if (!last_move2.game_over) {
              for (var iii in nextNextPiece) {
                for (var jjj = 0; jjj < this.number_of_columns - nextNextPiece[iii].width + 1; jjj++) {
                  let board3 = board2.slice();
                  let last_move3 = this.playMove(board3, nextNextPiece[iii].orientation, jjj, nextNextPiece[iii]);

                  if (!last_move3.game_over) {

                    let evaluation3 = this.evaluateBoard(last_move3, board3);

                    if (evaluation3 > best_evaluation) {
                      best_evaluation = evaluation3;
                      best_orientation = i;
                      best_column = j;
                      best_rowsRemoved = last_move.rows_removed;
                      best_occupiedGridCount = last_move.occupiedGridCount;
                      best_landingHeight = last_move.landing_height;
                    }
                  }

                }
              }

            }
          }
        }
      }

    }
  }

  if (window.tttt_scores == undefined) window.tttt_scores = [];
  if (best_rowsRemoved > 0) {
    let tmp_score = [0, 1, 3, 6, 10][best_rowsRemoved] * best_occupiedGridCount;
    // console.log("rowcount occupied", best_rowsRemoved, best_occupiedGridCount);
    window.tttt_scores.push(tmp_score);
  }


  let res = {
    'orientation_index': best_orientation,
    'orientation': piece[best_orientation].orientation,
    'column': best_column,
    'landingHeight': best_landingHeight,
  };
  if (window.tttt_moves == undefined) window.tttt_moves = [];
  window.tttt_moves.push(res);
  // console.log("moves:", res);
  return res;
};

/**
 * Evaluate the board, giving a higher score to boards that "look" better.
 *
 * Args:
 *   last_move - An object containing the following information on the
 *               last move played:
 *                 * landing_height: the row at which the last piece was played
 *                 * piece: the last piece played
 *                 * rows_removed: how many rows were removed in the last move
 *
 * Returns:
 *   A number indicating how "good" a board is, the higher the number, the
 *   better the board.
 */
ElTetris.prototype.evaluateBoard = function (last_move, board) {
  const threshold = 159;
  // return GetLandingHeight(last_move, board) * -4.500158825082766 +
  //   // last_move.rows_removed * 3.4181268101392694 +
  //   [0, 1, 3, 6, 10][last_move.rows_removed] * 3.4181268101392694 * (last_move.occupiedGridCount / 202 + 1.05136) +
  //   // (last_move.occupiedGridCount > threshold ? (0.1 - last_move.occupiedGridCount / threshold) : (last_move.occupiedGridCount / threshold * 2.7950010)) +
  //   // last_move.occupiedGridCount / 200 + 3.418 +
  //   GetRowTransitions(board, this.number_of_columns) * -3.2178882868487753 +
  //   GetColumnTransitions(board, this.number_of_columns) * -9.348695305445199 +
  //   GetNumberOfHoles(board, this.number_of_columns) * - 3.899265427351652 +
  //   GetWellSums(board, this.number_of_columns) * -3.3855972247263626;
  return GetLandingHeight(last_move, board) * -4.500158825082766 +
    [0, 0.8, 1.3, 1.6, 1.9][last_move.rows_removed] * 5.99999999999999999 +
    (last_move.occupiedGridCount > 126 ? last_move.occupiedGridCount * -1 : last_move.occupiedGridCount * 0.8) +
    (last_move.occupiedGridCount / 100 - 1) +
    GetRowTransitions(board, this.number_of_columns) * -5.2178882868487753 +
    GetColumnTransitions(board, this.number_of_columns) * - 8.348695305445199 +
    GetNumberOfHoles(board, this.number_of_columns) * - 11.899265427351652 +
    GetWellSums(board, this.number_of_columns) * -4.3855972247263626;
};
//26w
// ElTetris.prototype.evaluateBoard = function (last_move, board) {
//     return GetLandingHeight(last_move, board) * -4.500158825082766 +
//         last_move.rows_removed * 4.9181268101392694 +
//         (last_move.occupiedGridCount > 100 ? last_move.occupiedGridCount * -1 : last_move.occupiedGridCount * 80) +
//         (last_move.occupiedGridCount / 100 - 1) * 1 +
//         GetRowTransitions(board, this.number_of_columns) * -5.2178882868487753 +


//         GetColumnTransitions(board, this.number_of_columns) * - 8.348695305445199 +
//         GetNumberOfHoles(board, this.number_of_columns) * - 9.899265427351652 +
//         GetWellSums(board, this.number_of_columns) * -4.3855972247263626;
// };

/**
 * Play the given piece at the specified location.
 *
 * Args:
 *  board - The game board.
 *  piece - The piece to play.
 *  column - The column at which to place the piece.
 *
 * Returns:
 *   True if play succeeded, False if game is over.
 */
ElTetris.prototype.playMove = function (board, piece, column, realPiece) {
  // 检查旋转后的piece能否平移到column处
  // 当前位置是否合法 - 左移/右移 column-startColumn - 每次移动 - 判断当前位置是否合法
  let columnL2R = 10 - column - realPiece.width;
  for (let curCol = realPiece.startColumn; curCol != columnL2R; curCol += (columnL2R > realPiece.startColumn ? 1 : -1)) {
    let nToShift = this.number_of_columns - realPiece.width - curCol;
    let tmpPiece = this.movePiece(piece, nToShift);
    for (let i = 0; i < realPiece.heightOfVisiblePartOnOccur; i++) {
      let whichRow = 20 - realPiece.heightOfVisiblePartOnOccur + i;
      if (whichRow < this.number_of_rows && board[whichRow] & tmpPiece[realPiece.height - i - 1] !== 0)
        return { game_over: true };
    }
  }


  piece = this.movePiece(piece, column);
  var placementRow = this.getPlacementRow(board, piece, realPiece);
  var rowsRemoved = 0;

  if (placementRow + piece.length > this.number_of_rows) {
    // Game over.
    return { 'game_over': true };
  }

  // Add piece to board.
  for (var i = 0; i < piece.length; i++) {
    board[placementRow + i] |= piece[i];
  }

  // 计算 occupiedGridCount
  let occupiedGridCount = 0;
  for (i = 0; i < board.length; i++) {
    for (let j = 0; j < 10; j++) {
      if ((board[i] & (1 << j)) > 0) {
        occupiedGridCount += 1;
      }
    }
  }

  // Remove any full rows
  for (i = 0; i < piece.length; i++) {
    if (board[placementRow + i] == this.FULLROW) {
      board.splice(placementRow + i, 1);
      // Add an empty row on top.
      board.push(0);
      // Since we have decreased the number of rows by one, we need to adjust
      // the index accordingly.
      i--;
      rowsRemoved++;
    }
  }

  return {
    'landing_height': placementRow,
    'piece': piece,
    'rows_removed': rowsRemoved,
    'game_over': false,
    'occupiedGridCount': occupiedGridCount
  };
};

/**
 * Given a piece, return the row at which it should be placed.
 */
ElTetris.prototype.getPlacementRow = function (board, piece, realPiece) {
  // Descend from top to find the highest row that will collide
  // with the our piece.
  for (var row = this.number_of_rows - 1; row >= 0; row--) {
    // Check if piece collides with the cells of the current row.
    for (var i = 0; i < piece.length; i++) {
      if (row + i < this.number_of_rows && (board[row + i] & piece[i]) !== 0) {
        // Found collision - place piece on row above.
        return row + 1;
      }
    }
  }

  return 0; // No collision found, piece should be placed on first row.
};

ElTetris.prototype.movePiece = function (piece, column) {
  // Make a new copy of the piece
  var newPiece = piece.slice();
  for (var i = 0; i < piece.length; i++) {
    newPiece[i] = piece[i] << column;
  }

  return newPiece;
};

ElTetris.prototype.getRandomPieceIndex = function () {
  return Math.floor(Math.random() * PIECES.length);
};

ElTetris.prototype.getRandomPiece = function () {
  return PIECES[this.getRandomPieceIndex()];
};

ElTetris.prototype.getTenNextPiece = function (doUpdate, numberWhichNext = 1) {
  if (window.tttt == undefined) {
    window.tttt = new Tetris();
  }
  if (window.tttt_seq == undefined) {
    window.tttt_seq = [];
    window.tttt_pieces = [];
    for (let i = 0; i < 10010; i++) {
      tttt.curRandomNum = tttt.getRandomNum(tttt.curRandomNum);
      let tmpBrickInfo = tttt.getBrickInfo(tttt.curRandomNum, i, [4, 0], true);
      window.tttt_seq.push(tmpBrickInfo);
      let tmpbrickRaw = tmpBrickInfo.brickRawInfo;
      window.tttt_pieces.push({
        which: tmpbrickRaw.shapeIndex,
        shape: ['I', 'L', 'J', 'T', 'O', 'S', 'Z'][tmpbrickRaw.shapeIndex],
        state_index: tmpbrickRaw.stateIndex,
        pos: tmpBrickInfo.brickInfo.pos
      });
    }
  }
  let ten2elmap = { 0: 0, 1: 4, 2: 3, 3: 1, 4: 2, 5: 5, 6: 6 };
  if (doUpdate == false) {
    let seqWhich = window.tttt_seq[tttt.brickCount + numberWhichNext - 1];
    return { piece: PIECES[ten2elmap[seqWhich.brickRawInfo.shapeIndex]], stateIndex: seqWhich.brickRawInfo.stateIndex };
  }
  if (tttt.brickCount >= 10000) {
    return null;
  }
  // window.tttt_pieces.push({ which: tmpbrickRaw.shapeIndex, shape: shape, state_index: tmpbrickRaw.stateIndex, pos: tmpBrickInfo.brickInfo.pos });
  // console.log(shape);
  let resPiece = PIECES[ten2elmap[window.tttt_seq[tttt.brickCount].brickRawInfo.shapeIndex]];
  let resStateIndex = window.tttt_seq[tttt.brickCount].brickRawInfo.stateIndex;
  tttt.brickCount += 1;
  return { piece: resPiece, stateIndex: resStateIndex };
};
