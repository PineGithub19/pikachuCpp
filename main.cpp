#include "header\\mylib.h"
#include "header\\board.h"
#include "header\\logic.h"
#include "header\\eventDispatch.h"
#include "header\\menu.h"
#include "header\\pictures.h"
#include "header\\player.h"
#include "header\\typeOfBoard.h"
#include "header\\push.h"
#include "header\\recommended_move.h"
#include "header\\levels.h"
#include "header\\play.h"
#include "header\\file.h"
#include "header\\time_left.h"

int main() {
	PlaySound(TEXT("songs\\streamdenbaogio.wav"), NULL, SND_LOOP | SND_ASYNC);
	play();

	return 0;
}
