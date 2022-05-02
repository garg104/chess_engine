#include "StaticEvaluation.hpp"
#include <cstring>


class StaticEvaluation {

    public:
        int score[15][64];

        StaticEvaluation(int state) {
            // define and set scores
            int scorePawn[64]  =   {
                0,   0,   0,   0,   0,   0,   0,   0,
                50,  50,  50,  50,  50,  50,  50,  50,
                10,  10,  20,  30,  30,  20,  10,  10,
                5,   5,  10,  25,  25,  10,   5,   5,
                0,   0,   0,  20,  20,   0,   0,   0,
                5,  -5, -10,   0,   0, -10,  -5,   5,
                5,  10,  10, -20, -20,  10,  10,   5,
                0,   0,   0,   0,   0,   0,   0,   0  
            };
            
            /*
            int scoreOff[64]	=	{
                0,   0,   0,   0,   0,   0,   0,   0,
                50,  50,  50,  50,  50,  50,  50,  50,
                10,  10,  20,  30,  30,  20,  10,  10,
                5,   5,  10,  25,  25,  10,   5,   5,
                0,   0,   0,  20,  20,   0,   0,   0,
                5,  -5, -10,   0,   0, -10,  -5,   5,
                5,  10,  10, -20, -20,  10,  10,   5,
                0,   0,   0,   0,   0,   0,   0,   0  
            };
            */
            
            int scoreKnight[64]	=	{
                -50, -40, -30, -30, -30, -30, -40, -50,
                -40, -20,   0,   0,   0,   0, -20, -40,
                -30,   0,  10,  15,  15,  10,   0, -30,
                -30,   5,  15,  20,  20,  15,   0, -30,
                -30,   0,  15,  20,  20,  15,   0, -30,
                -30,   5,  10,  15,  15,  10,   5, -30,
                -40, -20,   0,   5,   5,   0, -20, -40,
                -50, -40, -30, -30, -30, -30, -40, -50
            };
            
            int scoreBishop[64]	=	{
                -20, -10, -10, -10, -10, -10, -10, -20,
                -10,   0,   0,   0,   0,   0,   0, -10,
                -10,   0,   5,  10,  10,   5,   0, -10,
                -10,   5,   5,  10,  10,   5,   5, -10,
                -10,   0,  10,  10,  10,  10,   0, -10,
                -10,  10,  10,  10,  10,  10,  10, -10,
                -10,   5,   0,   0,   0,   0,   5, -10,
                -20, -10, -10, -10, -10, -10, -10, -20
            };
            
            int scoreRook[64]	=	{
                0,   0,   0,   0,   0,   0,   0,   0,
                5,  10,  10,  10,  10,  10,  10,   5,
                -5,   0,   0,   0,   0,   0,   0,  -5,
                -5,   0,   0,   0,   0,   0,   0,  -5,
                -5,   0,   0,   0,   0,   0,   0,  -5,
                -5,   0,   0,   0,   0,   0,   0,  -5,
                -5,   0,   0,   0,   0,   0,   0,  -5,
                0,   0,   0,   5,   5,   0,   0,   0
            };
            
            int scoreQueen[64]	=	{
                -20, -10, -10,  -5,  -5, -10, -10, -20,
                -10,   0,   0,   0,   0,   0,   0, -10,
                -10,   0,   5,   5,   5,   5,   0, -10,
                -5,   0,   5,   5,   5,   5,   0,  -5,
                0,   0,   5,   5,   5,   5,   0,  -0,
                -10,   5,   5,   5,   5,   5,   0, -10,
                -10,   0,   5,   0,   0,   0,   0, -10,
                -20, -10, -10,  -5,  -5, -10, -10, -20	
            };
            
            int scoreKing[64]	=	{
                -30, -40, -40, -50, -50, -40, -40, -30,
                -30, -40, -40, -50, -50, -40, -40, -30,
                -30, -40, -40, -50, -50, -40, -40, -30,
                -30, -40, -40, -50, -50, -40, -40, -30,
                -20, -30, -30, -40, -40, -30, -30, -20,
                -10, -20, -20, -20, -20, -20, -20, -10,
                20,  20,   0,   0,   0,   0,  20,  20,
                20,  30,  10,   0,   0,  10,  30,  20
            };
            
            int scoreKingEnd[64] = {
                -50,-40,-30,-20,-20,-30,-40,-50,
                -30,-20,-10,  0,  0,-10,-20,-30,
                -30,-10, 20, 30, 30, 20,-10,-30,
                -30,-10, 30, 40, 40, 30,-10,-30,
                -30,-10, 30, 40, 40, 30,-10,-30,
                -30,-10, 20, 30, 30, 20,-10,-30,
                -30,-30,  0,  0,  0,  0,-30,-30,
                -50,-30,-30,-30,-30,-30,-30,-50
            };

            memset((void *)score[nil], 0, sizeof(int)*64);
            memset((void *)score[convertor], 0, sizeof(int)*64);

            for(int i=0; i<64; i++){
                score[whitePawn][i] = scorePawn[i];
                score[whiteKnight][i] = scoreKnight[i];
                score[whiteBishop][i] = scoreBishop[i];
                score[whiteRook][i] = scoreRook[i];
                score[whiteQueen][i] = scoreQueen[i];
                
                // value of black is reverse the board
                score[blackPawn][i]   = scorePawn[63 - i];
                score[blackKnight][i] = scoreKnight[63 - i];
                score[blackBishop][i] = scoreBishop[63 - i];
                score[blackRook][i]   = scoreRook[63 - i];
                score[blackQueen][i]  = scoreQueen[63 - i];
                
                // value of king is based on the game state
                if (state == 0) {
                    score[whiteKing][i] = scoreKing[i];
                    score[blackKing][i]   = scoreKing[63 - i];
                } else if(state == 1) {
                    score[whiteKing][i] = scoreKingEnd[i];
                    score[blackKing][i]   = scoreKingEnd[63 - i];
                }
                
            }

        }

        ~StaticEvaluation() {

        }

};
