#define RGFW_DEBUG
#define RGFW_IMPLEMENTATION
#include "RGFW.h"

int main(void) {
    RGFW_window* win = RGFW_createWindow("RGFW icons", 0, 0, 600, 400, RGFW_windowCenter | RGFW_windowNoResize);
    RGFW_window_setExitKey(win, RGFW_keyEscape);
    RGFW_mouseIcons mouse = 0;


	RGFW_mouse* icons[RGFW_mouseIconCount];

	for (RGFW_mouseIcons i = 0; i < RGFW_mouseIconCount; i++) {
        icons[i] = RGFW_createMouseStandard(i);
	}

    while (RGFW_window_shouldClose(win) == RGFW_FALSE) {
        RGFW_pollEvents();
        if (RGFW_isMousePressed(RGFW_mouseLeft)) {
			RGFW_window_setMouse(win, icons[mouse]);

			if (mouse < RGFW_mouseIconCount - 1) mouse++;
            else mouse = 0;
        }
    }


	for (size_t i = 0; i < RGFW_mouseIconCount; i++) {
		RGFW_freeMouse(icons[i]);
	}

    RGFW_window_close(win);
    return 0;
}
