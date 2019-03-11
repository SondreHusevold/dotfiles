Fenris - A Norweigan QMK Pok3r layout
=====================================

QMK keymaps for Norwegian keyboard version of the Vortex Pok3r.

It is customized for my own usage and is not the default Norwegian Pok3r keymaps by any means.

Requires you to unlock and flash QMK on your pok3r through ChaoticConundrum's excellent [qmk pok3r port](https://github.com/pok3r-custom/qmk_pok3r/blob/master/readme.md) and [pok3rtools](https://github.com/pok3r-custom/pok3rtool).

You need to clone ChaoticConundrum's QMK port, and replace the files in keyboards/vortex

Build:
`make vortex/pok3r:fenris`

Flash:
`./pok3rtool -t pok3r flash "QMK_FENRIS" ./vortex_pok3r_fenris.bin`
