#include "../ft_graph.h"

volatile sig_atomic_t resized = 1;

void on_resize(int sig)
{
    (void)sig;
    resized = 1;
}





////#include <stdio.h>
////#include <stdlib.h>

////int main(void)
////{
////    const char *program = "./npuzzle";
////    char command[1024];

////    snprintf(command, sizeof(command),
////        "wt.exe -w new -p \"WSL Tiny\" "
////        "-- \"%s\"",
////        program);

////    return (system(command) == -1);
////}
////Horizontal:  ─ ━ ╌ ╍ ═ ┄ ┅ ┈ ┉ ─ ⎯ ― ‒ – - _ ¯
////Vertical:    │ ┃ ╎ ╏ ║ ┆ ┇ ┊ ┋ | ¦ ! l I 1
////Diagonal /:  / ╱ ／ ⁄ ∕ ⟋ ⧸
////Diagonal \:  \ ╲ ＼ ⟍ ⧹
////Crossed:     × ✕ ✖ ╳ ╬ ╪ ╫ ╋
////Other:       ┌ ┐ └ ┘ ┍ ┎ ┏ ┑ ┒ ┓ ┕ ┖ ┗ ┙ ┚ ┛

////And here's a more extensive angle and line character collection, including less common Unicode line glyphs:
////text

////─ ━ ┄ ┅ ┈ ┉ ╌ ╍ ═ ═
////│ ┃ ┆ ┇ ┊ ┋ ╎ ╏ ║
////╱ ╲ ╳ ╱ ╲ ／ ＼
////⟋ ⟍ ⧸ ⧹ ∕ ⁄
////╴ ╵ ╶ ╷ ╸ ╹ ╺ ╻
////⎯ ― ‒ – — ― ⸺ ⸻
///// \ | ! l I i 1 _ - =

//#include <stdio.h>
//#include <signal.h>
//#include <sys/ioctl.h>
//#include <unistd.h>

//volatile sig_atomic_t resized = 1;

//void on_resize(int sig)
//{
//    (void)sig;
//    resized = 1;
//}

//int main(void)
//{
//    struct winsize ws;

//    signal(SIGWINCH, on_resize);

//    while (1) {
//        if (resized) {
//            resized = 0;

//            if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0) {
//                printf("\033[2J\033[H");  // Clear screen
//                printf("Width: %d columns\n", ws.ws_col);
//                printf("Height: %d rows\n", ws.ws_row);
//                fflush(stdout);
//            }
//        }

//        pause();
//    }

//    return 0;
//}
