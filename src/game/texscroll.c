#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "tile_scroll.h"
#include "texscroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/bob_texscroll.inc.c"
#include "src/game/texscroll/wf_texscroll.inc.c"
#include "src/game/texscroll/jrb_texscroll.inc.c"
#include "src/game/texscroll/group0_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/bbh_texscroll.inc.c"
#include "src/game/texscroll/ccm_texscroll.inc.c"
#include "src/game/texscroll/hmc_texscroll.inc.c"
#include "src/game/texscroll/lll_texscroll.inc.c"
#include "src/game/texscroll/ssl_texscroll.inc.c"
#include "src/game/texscroll/ddd_texscroll.inc.c"
#include "src/game/texscroll/sl_texscroll.inc.c"
#include "src/game/texscroll/wdw_texscroll.inc.c"
#include "src/game/texscroll/ttm_texscroll.inc.c"
#include "src/game/texscroll/thi_texscroll.inc.c"
#include "src/game/texscroll/ttc_texscroll.inc.c"
void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bob_segment_7SegmentRomStart)) {
		scroll_textures_bob();
	}
	//if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bob_segment_7SegmentRomStart)) {
	//	scroll_textures_bob();
	//}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_wf_segment_7SegmentRomStart)) {
		scroll_textures_wf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_jrb_segment_7SegmentRomStart)) {
		scroll_textures_jrb();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x4] == (uintptr_t)_group0_yay0SegmentRomStart)) {
		scroll_textures_group0();
	}


	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds();
	}
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bbh_segment_7SegmentRomStart)) {
		scroll_textures_bbh();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ccm_segment_7SegmentRomStart)) {
		scroll_textures_ccm();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_hmc_segment_7SegmentRomStart)) {
		scroll_textures_hmc();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_lll_segment_7SegmentRomStart)) {
		scroll_textures_lll();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ssl_segment_7SegmentRomStart)) {
		scroll_textures_ssl();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ddd_segment_7SegmentRomStart)) {
		scroll_textures_ddd();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_sl_segment_7SegmentRomStart)) {
		scroll_textures_sl();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_wdw_segment_7SegmentRomStart)) {
		scroll_textures_wdw();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ttm_segment_7SegmentRomStart)) {
		scroll_textures_ttm();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_thi_segment_7SegmentRomStart)) {
		scroll_textures_thi();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ttc_segment_7SegmentRomStart)) {
		scroll_textures_ttc();
	}

}
