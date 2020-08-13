#define TERM        "fbpad-256"

/* framebuffer device */
#define FBDEV		"/dev/fb0"

/* list of tags */
#define TAGS		"123456789"
#define TAGS_SAVED	""

/* programs mapped to m-c, m-m, m-e */
#define SHELL		{"zsh"}
#define EDITOR		{"nvim"}
#define MAIL		{"neomutt"}
#define NOTES		{"nvim", "/home/kjell/Nextcloud/Documents/vimwiki/index.md"}

/* fbval_t should match framebuffer depth */
typedef unsigned int fbval_t;

/* tinyfont files for regular, italic, and bold fonts */
#define FR		"/usr/share/fbpad/font-r.tf"
#define FI		"/usr/share/fbpad/font-i.tf"
#define FB		"/usr/share/fbpad/font-b.tf"

/* foreground and background colors */
#define FGCOLOR		COLORF
#define BGCOLOR		COLOR0

/* where to write the screen shot */
#define SCRSHOT		"/tmp/scr"

/* lock command password; NULL disables locking */
#define PASS		"password"

/* optimized version of fb_val() */
#define FB_VAL(r, g, b)	fb_val((r), (g), (b))

/* brighten colors 0-7 for bold text */
#define BRIGHTEN	1

/* black */
#define COLOR0		0x282828
#define COLOR8		0x64645e
/* red */
#define COLOR1		0xe73c50
#define COLOR9		0xf92772
/* green */
#define COLOR2		0xa6e22e
#define COLORA		0x9ec400
/* yellow */
#define COLOR3		0xe6db74
#define COLORB		0xe7c547
/* blue */
#define COLOR4		0x66d9ef
#define COLORC		0x7aa6da
/* magenta */
#define COLOR5		0xae81ff
#define COLORD		0xb77ee0
/* cyan */
#define COLOR6		0xa1efe4
#define COLORE		0x54ced6
/* white */
#define COLOR7		0xe8e8e3
#define COLORF		0xffffff
