# Patches:

- ActualFullscreen (Makes a true fullscreen keybinding available)
- AttachBelow (Makes new window spawn below window with focus, instead of taking master spot)
- Autostart (Allows having autostart script in ~/.dwm folder)
    - Can use cool-autostart if you'd rather have this functionality included in the dwm.c file
- Columns (Adds columns layout)
- CycleLayouts (Allows using Mod+Space to cycle through available layouts)
- RestartSig (Allows restarting DWM without logging out using a hotkey, Mod+Shift+r)
- RestoreAfterRestart (Puts windows back where you had them instead of dumping them all on workspace 1)
- RotateStack (Allows moving windows through the stack)
- SysTray (Adds a systray to the statusbar)
- UselessGap (Adds purly aesthetic gaps between windows)

# Installation:

1. Once cloned, make sure to place the ".dwm" folder & "autostart.sh" script in /$HOME/.dwm so that the autostart patch will work. 
2. To install you'll need to run `sudo make clean install`. This will compile dwm & install it. 
3. If you're using a login manager (LightDM, SDDM, etc.) you'll need to add a .desktop file to your /usr/share/xsessions/ folder.
4. Logout of your current session & log into DWM. 
