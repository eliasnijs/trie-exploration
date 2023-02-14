#ifndef BASE_ASNSII_ESC_CODES_H

/* general anscii codes */
#define ASCII_BEL				"\a"
#define ASCII_BS				"\b"
#define ASCII_HT				"\t"
#define ASCII_LF				"\n"
#define ASCII_VT				"\v"
#define ASCII_FF				"\f"
#define ASCII_CR				"\r"
#define ASCII_ESC				"\033"

/* cursor controls */
#define ASCII_ESC_TO_POS			ASCII_ESC "[H"
#define ASCII_ESC_TO_LC(l,c)			ASCII_ESC "\[" #l ";" #c "f"
#define ASCII_ESC_N_UP(n) 			ASCII_ESC "\[" #n "A"
#define ASCII_ESC_N_DOWN(n)			ASCII_ESC "\[" #n "B"
#define ASCII_ESC_N_RIGHT(n)			ASCII_ESC "\[" #n "C"
#define ASCII_ESC_N_LEFT(n)			ASCII_ESC "\[" #n "D"
#define ASCII_ESC_START_OF_N_DOWN(n)		ASCII_ESC "\[" #n "E"
#define ASCII_ESC_START_OF_N_UP(n)		ASCII_ESC "\[" #n "F"
#define ASCII_ESC_TO_COL_N(n)			ASCII_ESC "\[" #n "G"
#define ASCII_ESC_REQ_CURSOR_POS(l,c)		ASCII_ESC "\[" #l ";" #c "R"
#define ASCII_ESC_UP_W_SCROLL			ASCII_ESC "[M"
#define ASCII_ESC_SAVE_CURSOR_POS_DEC		ASCII_ESC "[7"
#define ASCII_ESC_SAVE_CURSOR_POS_SCO		ASCII_ESC "[7"
#define ASCII_ESC_RESTORE_LAST_CURSOR_POS_DEC	ASCII_ESC "[8"
#define ASCII_ESC_RESTORE_LAST_CURSOR_POS_SCO	ASCII_ESC "[8"

/* erase functions */
#define ASCII_ESC_ERASE_TO_SCREEN_END		ASCII_ESC "[0J"
#define ASCII_ESC_ERASE_FROM_SCREEN_START	ASCII_ESC "[1J"
#define ASCII_ESC_ERASE_SCREEN			ASCII_ESC "[2J"
#define ASCII_ESC_ERASE_SAVED			ASCII_ESC "[3J"
#define ASCII_ESC_ERASE_IN_LINE			ASCII_ESC "[K"
#define ASCII_ESC_ERASE_TO_END			ASCII_ESC "[0K"
#define ASCII_ESC_ERASE_FROM_START		ASCII_ESC "[1K"
#define ASCII_ESC_ERASE_LINE			ASCII_ESC "[2K"

/* colors/graphics mode */
#define ASCII_ESC_RESET_ALL			ASCII_ESC "[0m"
#define ASCII_ESC_BOLD				ASCII_ESC "[1m"
#define ASCII_ESC_BOLD_RESET			ASCII_ESC "[21m"
#define ASCII_ESC_DIM				ASCII_ESC "[2m"
#define ASCII_ESC_DIM_RESET			ASCII_ESC "[22m"
#define ASCII_ESC_ITALIC			ASCII_ESC "[3m"
#define ASCII_ESC_ITALIC_RESET			ASCII_ESC "[23m"
#define ASCII_ESC_UNDERLINE			ASCII_ESC "[4m"
#define ASCII_ESC_UNDERLINE_RESET		ASCII_ESC "[24m"
#define ASCII_ESC_BLINK				ASCII_ESC "[5m"
#define ASCII_ESC_BLINK_RESET			ASCII_ESC "[25m"
#define ASCII_ESC_INVERSE			ASCII_ESC "[7m"
#define ASCII_ESC_INVERSE_RESET			ASCII_ESC "[27m"
#define ASCII_ESC_HIDDEN			ASCII_ESC "[8m"
#define ASCII_ESC_HIDDEN_RESET			ASCII_ESC "[28m"
#define ASCII_ESC_STRIKETHROUGH			ASCII_ESC "[9m"
#define ASCII_ESC_STRIKETHROUGH_RESET		ASCII_ESC "[29m"

/* rgb color codes */
#define ASCII_ESC_RGB_FG(r,g,b)		ASCII_ESC "[38;2;" #r ";" #g ";" #b "m"
#define ASCII_ESC_RGB_BG(r,g,b)		ASCII_ESC "[48;2;" #r ";" #g ";" #b "m"

/* screen modes */
#define ASCII_ESC_CURSOR_HIDDEN			ASCII_ESC "[?25l"
#define ASCII_ESC_CURSOR_VISIBLE		ASCII_ESC "[?25h"
#define ASCII_ESC_RESTORE_SCREEN		ASCII_ESC "[?47l"
#define ASCII_ESC_SAVE_SCREEN			ASCII_ESC "[?47h"
#define ASCII_ESC_ENABLE_ALT_BUFFER		ASCII_ESC "[?1049h"
#define ASCII_ESC_DISABLE_ALT_BUFFER		ASCII_ESC "[?1049l"

/* view others at:
 * https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 */

#define BASE_ASNSII_ESC_CODES_H
#endif
