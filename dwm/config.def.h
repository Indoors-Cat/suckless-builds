/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 4;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";	/* this is the main bar color (underneath the icons) */
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#8be9fd";	/* This is the color of the icons themselves */
static const char col_gray4[]       = "#eeeeee";	/* This is the workspace icon, & window name color */
static const char col_cyan[]        = "#bd93f9";	/* This is the color of the bar itself */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Cider",		NULL,	NULL,	1 << 3,		0,	-1 },
	{ "Spotify",		NULL,	NULL,	1 << 3,		0,	-1 },
	{ "ckb-next",		NULL,	NULL,	1 << 8,		0,	-1 },
	{ "steam",		NULL,	NULL,	1 << 5,		0,	-1 },
	{ "Virt-Manager",	NULL,	NULL,	1 << 7,		0,	-1 },
	/* { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 }, */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "󰖯",      monocle },
	{ "󰕭",		col },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
/* Application Variables: */
static const char *browser[] = { "firefox-esr", NULL };
//static const char *browser[] = { "brave", NULL };
static const char *editor2[] = { "codium", NULL };
static const char *files[] = { "nemo", NULL };
static const char *music[] = { "cider", NULL };
/*static const char *music[] = { "spotify", NULL }; */
static const char *termcmd[]  = { "st", NULL };
static const char *virt[] = { "virt-manager", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
// Applications:
	{ MODKEY,			XK_b,	spawn,	{.v = browser } },
	//{ MODKEY|ShiftMask,		XK_b,	spawn,	{.v = browser2 } },
	{ MODKEY,			XK_e,	spawn,	SHCMD("kitty -e nvim") },
	{ MODKEY|ShiftMask,		XK_e,	spawn,	{.v = editor2 } },
	{ MODKEY,			XK_f,	spawn,	{.v = files } },
	{ MODKEY,			XK_m,	spawn,	{.v = music } },
	{ MODKEY,			XK_r,	spawn,	SHCMD("rofi -show drun -show-icons") },
	//{ MODKEY,                       XK_p,   spawn,  {.v = dmenucmd } },
	{ MODKEY,			XK_p,	spawn,	SHCMD("rofi -show run -show-icons") },
	{ MODKEY,			XK_t,	spawn,	{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_t,	spawn,	SHCMD("kitty -e zsh") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,	{.v = termcmd } },
	{ Mod1Mask,			XK_Tab,	spawn,	SHCMD("rofi -show window") },
	{ MODKEY,			XK_c,	spawn,	SHCMD("rofi -show calc") },
	//This is broken atm: { MODKEY|ControlMask,		XK_l,	spawn,	SHCMD("rofi -show power-menu -modi 'power-menu:rofi-power-menu'") },
	{ MODKEY,			XK_v,	spawn,	{.v = virt } },
// Multimedia Keys:
	//{ 0,				XK86AudioPlay,	spawn,	SCHMD("playerctl play-pause") },
// Window Management:
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,		XK_j,	rotatestack,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_k,	rotatestack,	{.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
// Layout Management: 
	{ Mod1Mask,                     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ Mod1Mask,                     XK_f,      setlayout,      {.v = &layouts[1]} },
	{ Mod1Mask,                     XK_m,      setlayout,      {.v = &layouts[2]} },
	{ Mod1Mask,			XK_c,	   setlayout,	   {.v = &layouts[3]} },
	{ Mod1Mask,			XK_comma,  cyclelayout,    {.i = -1 } },
	{ Mod1Mask,			XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
// Workspace Controls:
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
// DWM System Controls:
	{ Mod1Mask,                     XK_b,      togglebar,      {0} },
	{ MODKEY,			XK_q,	killclient,	{0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,		XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

