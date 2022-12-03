#ifndef BASE_ASNSII_ESC_CODES_H

/* general anscii codes */
#define ANSII_BEL				"\a"
#define ANSII_BS				"\b"
#define ANSII_HT				"\t"
#define ANSII_LF				"\n"
#define ANSII_VT				"\v"
#define ANSII_FF				"\f"
#define ANSII_CR				"\r"
#define ANSII_ESC				"\033"

/* cursor controls */
#define ANSII_ESC_TO_POS			ANSII_ESC "[H"
#define ANSII_ESC_TO_LC(l,c)			ANSII_ESC "\[" #l ";" #c "f"
#define ANSII_ESC_N_UP(n) 			ANSII_ESC "\[" #n "A"
#define ANSII_ESC_N_DOWN(n)			ANSII_ESC "\[" #n "B"
#define ANSII_ESC_N_RIGHT(n)			ANSII_ESC "\[" #n "C"
#define ANSII_ESC_N_LEFT(n)			ANSII_ESC "\[" #n "D"
#define ANSII_ESC_START_OF_N_DOWN(n)		ANSII_ESC "\[" #n "E"
#define ANSII_ESC_START_OF_N_UP(n)		ANSII_ESC "\[" #n "F"
#define ANSII_ESC_TO_COL_N(n)			ANSII_ESC "\[" #n "G"
#define ANSII_ESC_REQ_CURSOR_POS(l,c)		ANSII_ESC "\[" #l ";" #c "R"
#define ANSII_ESC_UP_W_SCROLL			ANSII_ESC "[M"
#define ANSII_ESC_SAVE_CURSOR_POS_DEC		ANSII_ESC "[7"
#define ANSII_ESC_SAVE_CURSOR_POS_SCO		ANSII_ESC "[7"
#define ANSII_ESC_RESTORE_LAST_CURSOR_POS_DEC	ANSII_ESC "[8"
#define ANSII_ESC_RESTORE_LAST_CURSOR_POS_SCO	ANSII_ESC "[8"

/* erase functions */
#define ANSII_ESC_ERASE_TO_SCREEN_END		ANSII_ESC "[0J"
#define ANSII_ESC_ERASE_FROM_SCREEN_START	ANSII_ESC "[1J"
#define ANSII_ESC_ERASE_SCREEN			ANSII_ESC "[2J"
#define ANSII_ESC_ERASE_SAVED			ANSII_ESC "[3J"
#define ANSII_ESC_ERASE_IN_LINE			ANSII_ESC "[K"
#define ANSII_ESC_ERASE_TO_END			ANSII_ESC "[0K"
#define ANSII_ESC_ERASE_FROM_START		ANSII_ESC "[1K"
#define ANSII_ESC_ERASE_LINE			ANSII_ESC "[2K"

/* colors/graphics mode */
#define ANSII_ESC_RESET_ALL			ANSII_ESC "[0m"
#define ANSII_ESC_BOLD				ANSII_ESC "[1m"
#define ANSII_ESC_BOLD_RESET			ANSII_ESC "[21m"
#define ANSII_ESC_DIM				ANSII_ESC "[2m"
#define ANSII_ESC_DIM_RESET			ANSII_ESC "[22m"
#define ANSII_ESC_ITALIC			ANSII_ESC "[3m"
#define ANSII_ESC_ITALIC_RESET			ANSII_ESC "[23m"
#define ANSII_ESC_UNDERLINE			ANSII_ESC "[4m"
#define ANSII_ESC_UNDERLINE_RESET		ANSII_ESC "[24m"
#define ANSII_ESC_BLINK				ANSII_ESC "[5m"
#define ANSII_ESC_BLINK_RESET			ANSII_ESC "[25m"
#define ANSII_ESC_INVERSE			ANSII_ESC "[7m"
#define ANSII_ESC_INVERSE_RESET			ANSII_ESC "[27m"
#define ANSII_ESC_HIDDEN			ANSII_ESC "[8m"
#define ANSII_ESC_HIDDEN_RESET			ANSII_ESC "[28m"
#define ANSII_ESC_STRIKETHROUGH			ANSII_ESC "[9m"
#define ANSII_ESC_STRIKETHROUGH_RESET		ANSII_ESC "[29m"

/* rgb color codes */
#define ANSII_ESC_RGB_FG(r,g,b)		ESC "[38;2;" #r ";" #g ";" #b "m"
#define ANSII_ESC_RGB_BG(r,g,b)		ESC "[48;2;" #r ";" #g ";" #b "m"

/* screen modes */
#define ANSII_ESC_CURSOR_HIDDEN			ANSII_ESC "[?25l"
#define ANSII_ESC_CURSOR_VISIBLE		ANSII_ESC "[?25h"
#define ANSII_ESC_RESTORE_SCREEN		ANSII_ESC "[?47l"
#define ANSII_ESC_SAVE_SCREEN			ANSII_ESC "[?47h"
#define ANSII_ESC_ENABLE_ALT_BUFFER		ANSII_ESC "[?1049h"
#define ANSII_ESC_DISABLE_ALT_BUFFER		ANSII_ESC "[?1049l"

/* view others at:
 * https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 */

#define BASE_ASNSII_ESC_CODES_H
#endif
