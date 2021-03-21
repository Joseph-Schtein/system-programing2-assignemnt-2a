#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("print correct massages") {
    ariel::Board board;
    board.post(299, 299, Direction::Horizontal, "abcd");
    board.post(300, 301, Direction::Vertical, "xzyw");
    board.post(302, 299, Direction::Horizontal, "pqr");
    board.post(298, 300, Direction::Vertical, "stpq");
    
    CHECK(board.read(298, 301, Direction::Vertical, 3) == "_cx");
    CHECK(board.read(300, 300, Direction::Horizontal, 5) == "px___");
    CHECK(board.read(299, 299, Direction::Vertical, 4) == "a_p_");
    CHECK(board.read(299, 299, Direction::Horizontal, 4) == "atcd");
    
    CHECK(board.read(302, 299, Direction::Horizontal, 4) == "__y_");
    CHECK(board.read(300, 297, Direction::Vertical, 3) == "___");
    CHECK(board.read(301, 298, Direction::Vertical, 6) == "______");
    CHECK(board.read(300, 298, Direction::Horizontal, 7) == "__px___");
    
    board.post(299, 303, Direction::Vertical, "azy");
    board.post(300, 297, Direction::Horizontal, "pqw");
    board.post(302, 301, Direction::Vertical, "alfg");

    CHECK(board.read(302, 299, Direction::Horizontal, 4) == "__a_");
    CHECK(board.read(300, 297, Direction::Vertical, 3) == "p__");
    CHECK(board.read(301, 298, Direction::Vertical, 6) == "______");
    CHECK(board.read(300, 298, Direction::Horizontal, 7) == "qwpx_z_");

    CHECK(board.read(305, 301, Direction::Horizontal, 3) == "g__");
    CHECK(board.read(301, 301, Direction::Vertical, 3) == "ral");
    CHECK(board.read(299, 300, Direction::Horizontal, 5) == "tcda_");
    CHECK(board.read(301, 301, Direction::Vertical, 4) == "r_y_");

    board.post(302, 303, Direction::Horizontal, "zyx");
    board.post(301, 300, Direction::Vertical, "waz");
    board.post(300, 302, Direction::Horizontal, "cvbn");

    CHECK(board.read(300, 300, Direction::Horizontal, 5) == "pxcz_");
    CHECK(board.read(299, 299, Direction::Vertical, 4) == "awp_");
    CHECK(board.read(300, 298, Direction::Horizontal, 7) == "qwpxcz_");
    CHECK(board.read(302, 301, Direction::Vertical, 4) == "vbn_");
    
}