Lights1 l1_thin_book_BookSides_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 l1_thin_book_pages_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx l1_thin_book_ci8_books_dark_ci8_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_ci8_books_dark_ci8[] = {
	0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 
	0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 
	0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 
	0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 
	0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 
	0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 
	0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 
	0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 
	0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 
	0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 
	0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 
	0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 
	0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 
	0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 
	0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 
	0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 
	0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 
	0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 
	0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 
	0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 
	0x19, 0x1D, 0x5, 0x1A, 0x1, 0x2, 0x2, 0x1E, 0x3, 
	0x1F, 0x1A, 0x4, 0x5, 0x5, 0x1A, 0x20, 0x8, 0x9, 
	0xB, 0xB, 0x21, 0x1A, 0x22, 0x22, 0x1A, 0x1A, 0x20, 
	0x8, 0x9, 0xB, 0x21, 0x1A, 0x1A, 0x22, 0x22, 0x1A, 
	0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0x1A, 0x22, 0x22, 
	0x22, 0x1A, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x1A, 
	0x22, 0x22, 0x1A, 0x1A, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 
	0x1A, 0x1A, 0x1D, 0x5, 0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x1C, 0x1A, 0x4, 0x5, 0x5, 0x1A, 0x1C, 0x1C, 
	0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 0x22, 0x5, 0x1A, 0x1A, 
	0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 0x1A, 0x22, 0x22, 
	0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 0x22, 
	0x22, 0x22, 0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 
	0x1A, 0x22, 0x22, 0x1A, 0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x1A, 0x1A, 0x1D, 0x5, 0x0, 0x1, 0x1A, 0x1A, 
	0x1C, 0x1C, 0x1A, 0x1, 0x4, 0x5, 0x5, 0xA, 0x20, 
	0x1C, 0x1C, 0x1C, 0x1C, 0x23, 0x7, 0xA, 0x5, 0x6, 
	0x6, 0x20, 0x1C, 0x1C, 0x1C, 0x20, 0x7, 0x7, 0xA, 
	0x5, 0xC, 0xD, 0x1C, 0x1C, 0x1C, 0x1C, 0xE, 0xD, 
	0x11, 0x5, 0x5, 0x12, 0x13, 0x1C, 0x1C, 0x1C, 0x1C, 
	0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1C, 0x1C, 
	0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 0x1A, 
	0x1A, 0x1C, 0x1C, 0x1A, 0x1, 0x4, 0x5, 0x5, 0xA, 
	0x20, 0x1C, 0x1C, 0x1C, 0x1C, 0x23, 0x7, 0xA, 0x5, 
	0x6, 0x6, 0x20, 0x1C, 0x1C, 0x1C, 0x20, 0x7, 0x7, 
	0xA, 0x5, 0xC, 0xD, 0x1C, 0x1C, 0x1C, 0x1C, 0xE, 
	0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1C, 
	0x1C, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 
	0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 0x5, 
	0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 0xA, 
	0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 0x7, 
	0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 
	0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 0x15, 
	0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 
	0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 
	0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 
	0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 
	0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 
	0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 
	0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 
	0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 
	0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 
	0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 
	0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 
	0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 
	0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 
	0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 
	0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 
	0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 
	0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 
	0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 
	0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 
	0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 
	0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 
	0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 
	0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 
	0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 
	0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 
	0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 
	0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 
	0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 
	0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 
	0x19, 0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 
	0x2, 0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 
	0x9, 0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 
	0x8, 0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 
	0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 
	0x5, 0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 
	0x17, 0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 
	0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 
	0x3, 0x2, 0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 
	0x9, 0x9, 0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 
	0x7, 0x8, 0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 
	0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 
	0x5, 0x5, 0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 
	0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 
	0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 
	0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 
	0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 
	0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 
	0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 
	0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 
	0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 
	0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 0x2, 
	0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 0x5, 0x6, 
	0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 0xA, 0x5, 
	0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 0x7, 0x7, 
	0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 
	0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 0x15, 0x16, 
	0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1A, 
	0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 
	0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 0x5, 
	0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 0xA, 
	0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 0x7, 
	0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 
	0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 0x15, 
	0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 
	0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 
	0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x5, 
	0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 
	0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 0x8, 
	0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 0xF, 
	0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x14, 
	0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 
	0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 
	0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 
	0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 
	0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 0xB, 
	0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 0xE, 
	0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 
	0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 0x18, 
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 
	0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 
	0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 
	0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 0x9, 
	0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 0xE, 
	0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 0x12, 
	0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 0x5, 
	0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 0x19, 
	0x1D, 0x5, 0x0, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 
	0x1, 0x4, 0x5, 0x5, 0x6, 0x7, 0x8, 0x9, 0x9, 
	0x9, 0x8, 0x7, 0xA, 0x5, 0x6, 0x6, 0x7, 0x8, 
	0x9, 0xB, 0x8, 0x7, 0x7, 0xA, 0x5, 0xC, 0xD, 
	0xE, 0xE, 0xF, 0x10, 0xE, 0xD, 0x11, 0x5, 0x5, 
	0x12, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x13, 0x17, 
	0x5, 0x18, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 0x19, 
	0x19, 0x1D, 0x5, 0x1A, 0x1, 0x2, 0x2, 0x1E, 0x3, 
	0x1F, 0x1A, 0x4, 0x5, 0x5, 0x1A, 0x20, 0x8, 0x9, 
	0xB, 0xB, 0x21, 0x1A, 0x22, 0x22, 0x1A, 0x1A, 0x20, 
	0x8, 0x9, 0xB, 0x21, 0x1A, 0x1A, 0x22, 0x22, 0x1A, 
	0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0x1A, 0x22, 0x22, 
	0x22, 0x1A, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 0x1A, 
	0x22, 0x22, 0x1A, 0x1A, 0x19, 0x1A, 0x1B, 0x1C, 0x1A, 
	0x1A, 0x1A, 0x1D, 0x5, 0x1A, 0x1, 0x2, 0x2, 0x1E, 
	0x3, 0x1F, 0x1A, 0x4, 0x5, 0x5, 0x1A, 0x20, 0x8, 
	0x9, 0xB, 0xB, 0x21, 0x1A, 0x22, 0x22, 0x1A, 0x1A, 
	0x20, 0x8, 0x9, 0xB, 0x21, 0x1A, 0x1A, 0x22, 0x22, 
	0x1A, 0xD, 0xE, 0xE, 0xF, 0x10, 0xE, 0x1A, 0x22, 
	0x22, 0x22, 0x1A, 0x13, 0x14, 0x15, 0x16, 0x16, 0x14, 
	0x1A, 0x22, 0x22, 0x1A, 0x1A, 0x19, 0x1A, 0x1B, 0x1C, 
	0x1A, 0x1A, 0x1A, 0x1D, 0x5, 0x1A, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x1C, 0x1C, 0x1A, 0x4, 0x5, 0x5, 0x1A, 0x1C, 
	0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 0x22, 0x5, 0x1A, 
	0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 0x1A, 0x22, 
	0x22, 0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1A, 
	0x22, 0x22, 0x22, 0x1A, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x1A, 0x22, 0x22, 0x1A, 0x1A, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x1C, 0x1A, 0x1A, 0x1D, 0x5, 0x0, 0x1, 0x1A, 
	0x1A, 0x1C, 0x1C, 0x1A, 0x1, 0x4, 0x5, 0x5, 0xA, 
	0x20, 0x1C, 0x1C, 0x1C, 0x1C, 0x23, 0x7, 0xA, 0x5, 
	0x6, 0x6, 0x20, 0x1C, 0x1C, 0x1C, 0x20, 0x7, 0x7, 
	0xA, 0x5, 0xC, 0xD, 0x1C, 0x1C, 0x1C, 0x1C, 0xE, 
	0xD, 0x11, 0x5, 0x5, 0x12, 0x13, 0x1C, 0x1C, 0x1C, 
	0x1C, 0x14, 0x13, 0x17, 0x5, 0x18, 0x18, 0x19, 0x1C, 
	0x1C, 0x1C, 0x1A, 0x19, 0x19, 0x1D, 0x5, 0x0, 0x1, 
	0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x24, 0x24, 
	0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 0x22, 
	0x24, 0x6, 0x6, 0x7, 0x8, 0x9, 0x9, 0x8, 0x7, 
	0x7, 0x22, 0x24, 0xC, 0xD, 0xE, 0xE, 0xF, 0x10, 
	0xE, 0xD, 0x22, 0x24, 0x24, 0x12, 0x13, 0x14, 0x15, 
	0x15, 0x15, 0x14, 0x13, 0x22, 0x24, 0x18, 0x18, 0x19, 
	0x1A, 0x1B, 0x1B, 0x1A, 0x19, 0x19, 0x22, 0x24, 0x0, 
	0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x1, 0x4, 0x24, 
	0x24, 0x6, 0x7, 0x8, 0x9, 0x9, 0x9, 0x8, 0x7, 
	0x22, 0x24, 0x6, 0x6, 0x7, 0x8, 0x9, 0x9, 0x8, 
	0x7, 0x7, 0x22, 0x24, 0xC, 0xD, 0xE, 0xE, 0xF, 
	0x10, 0xE, 0xD, 0x22, 0x24, 0x24, 0x12, 0x13, 0x14, 
	0x15, 0x15, 0x15, 0x14, 0x13, 0x22, 0x24, 0x18, 0x18, 
	0x19, 0x1A, 0x1B, 0x1B, 0x1A, 0x19, 0x19, 0x22, 0x24, 
	0x24, 0x0, 0x2, 0x2, 0x1E, 0x3, 0x2, 0x4, 0x24, 
	0x24, 0x24, 0x24, 0x6, 0x8, 0x9, 0x9, 0x9, 0x8, 
	0x6, 0x5, 0x24, 0x24, 0x24, 0x6, 0x8, 0x9, 0x9, 
	0x8, 0x6, 0x6, 0x24, 0x24, 0x24, 0xC, 0xE, 0xE, 
	0xF, 0xF, 0xE, 0xC, 0x24, 0x24, 0x24, 0x24, 0x12, 
	0x14, 0x15, 0x15, 0x15, 0x14, 0x12, 0x24, 0x24, 0x24, 
	0x24, 0x18, 0x1A, 0x1B, 0x1B, 0x1A, 0x18, 0x18, 0x5, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x0, 0x0, 0x0, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x6, 0x6, 0x6, 
	0x6, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x6, 
	0x6, 0x6, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xC, 
	0xC, 0xC, 0xC, 0xC, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x12, 0x12, 0x12, 0x12, 0x12, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x22, 0x18, 0x18, 0x22, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 
};

Gfx l1_thin_book_ci8_books_dark_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_ci8_books_dark_ci8_pal_rgba16[] = {
	0x10, 0xCD, 0x11, 0x11, 0x19, 0x97, 0x21, 0xDD, 0x20, 
	0x8B, 0x20, 0x43, 0x28, 0x83, 0x38, 0x85, 0x48, 0x85, 
	0x58, 0xC7, 0x28, 0x43, 0x50, 0xC7, 0x0, 0xC1, 0x9, 
	0x3, 0x9, 0x43, 0x11, 0xC5, 0x9, 0x83, 0x18, 0x81, 
	0x10, 0x47, 0x18, 0x4B, 0x28, 0x8F, 0x38, 0x93, 0x30, 
	0x91, 0x18, 0x45, 0x31, 0x43, 0x39, 0x85, 0x41, 0xC5, 
	0x52, 0x7, 0x4A, 0x5, 0x28, 0xC3, 0x21, 0xDB, 0x31, 
	0xD9, 0x39, 0x5, 0x49, 0x5, 0x20, 0x83, 0x49, 0x85, 
	0x18, 0x43, 
};

Gfx l1_thin_book_book_sides_ci4_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_book_sides_ci4[] = {
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x0, 0x3, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x22, 0x23, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x0, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x13, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x23, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x33, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x33, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 
	0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 
	0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x32, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x33, 0x33, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 
	0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x32, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x30, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x31, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x33, 0x30, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 
	0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x30, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x31, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x30, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x33, 0x32, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 
	0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x31, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x30, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x32, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 
	0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x30, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x32, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x30, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x33, 0x31, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 
	0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x32, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x30, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x31, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x33, 0x30, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 
	0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x33, 0x33, 0x30, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x33, 0x33, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x33, 0x33, 0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 
	0x33, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 
	0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x33, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x3, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x23, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x0, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x33, 0x0, 0x3, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x33, 0x0, 0x3, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x33, 0x22, 0x23, 0x33, 0x33, 0x33, 0x33, 0x33, 
	0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
};

Gfx l1_thin_book_book_sides_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_book_sides_ci4_pal_rgba16[] = {
	0x28, 0x43, 0x0, 0xC1, 0x10, 0x47, 0x4A, 0x5, 
};

Gfx l1_thin_book_bookpage_ci8_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_bookpage_ci8[] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x1, 0x5, 0x4, 0x6, 
	0x4, 0x7, 0x8, 0x9, 0x6, 0xA, 0xB, 0xC, 0x1, 
	0x2, 0xD, 0x0, 0xE, 0x2, 0xF, 0x10, 0xF, 0x11, 
	0xB, 0xF, 0x6, 0x7, 0xA, 0xC, 0x1, 0x2, 0xF, 
	0xC, 0x12, 0x6, 0x1, 0xC, 0x1, 0xC, 0x6, 0x13, 
	0x7, 0x10, 0x11, 0x10, 0x1, 0x2, 0xF, 0xC, 0x12, 
	0x6, 0x12, 0x4, 0xE, 0x0, 0x7, 0x1, 0x7, 0x0, 
	0x14, 0x10, 0x1, 0x2, 0xF, 0xC, 0x12, 0x6, 0x12, 
	0x9, 0x12, 0x4, 0x7, 0x1, 0x10, 0x9, 0x0, 0x11, 
	0x1, 0x2, 0xF, 0xC, 0x12, 0x15, 0x12, 0x16, 0x12, 
	0x16, 0x7, 0xE, 0x10, 0x3, 0x17, 0x11, 0x1, 0x2, 
	0xF, 0xC, 0x12, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 
	0x12, 0x19, 0x3, 0x3, 0x7, 0x1, 0x2, 0xF, 0xC, 
	0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 0xC, 
	0x3, 0xF, 0xA, 0x1, 0x2, 0xF, 0xC, 0x12, 0x15, 
	0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 0xC, 0x1A, 0xF, 
	0xA, 0x1, 0x2, 0xF, 0xC, 0x12, 0x15, 0x18, 0x16, 
	0x18, 0x16, 0x7, 0x12, 0x0, 0xF, 0x1A, 0xA, 0x1, 
	0x2, 0x3, 0xC, 0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 
	0x7, 0x1B, 0x0, 0xD, 0xD, 0xA, 0x1, 0x2, 0x3, 
	0xC, 0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0xE, 
	0x0, 0xD, 0xD, 0x6, 0x1, 0x2, 0x3, 0xC, 0x18, 
	0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 0x0, 0xD, 
	0xD, 0x6, 0x1, 0x2, 0x3, 0x0, 0x12, 0x15, 0x18, 
	0x16, 0x18, 0x16, 0x7, 0x12, 0x0, 0xD, 0xD, 0x6, 
	0x1, 0x2, 0x3, 0x0, 0x12, 0x15, 0x18, 0x16, 0x18, 
	0x16, 0x7, 0x12, 0x0, 0xD, 0xD, 0x6, 0x1, 0x2, 
	0x3, 0x4, 0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 
	0x12, 0x0, 0xD, 0xD, 0x6, 0x1, 0x2, 0x16, 0x9, 
	0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 0x0, 
	0xD, 0xF, 0x6, 0x1, 0x2, 0x16, 0x16, 0x18, 0x15, 
	0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 0x0, 0x1A, 0xF, 
	0x6, 0x1, 0x2, 0x16, 0x16, 0x18, 0x15, 0x18, 0x16, 
	0x18, 0x16, 0x7, 0x12, 0x0, 0x1A, 0xF, 0x6, 0x1, 
	0x2, 0x9, 0x3, 0x18, 0x15, 0x18, 0x16, 0x18, 0x16, 
	0x7, 0x12, 0x0, 0xF, 0x3, 0x6, 0x1, 0x2, 0x16, 
	0x3, 0x12, 0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0x12, 
	0xC, 0x3, 0x3, 0x15, 0x1, 0x2, 0x16, 0x3, 0x12, 
	0x15, 0x18, 0x16, 0x18, 0x16, 0x7, 0xE, 0x0, 0xF, 
	0x16, 0xA, 0x1, 0x2, 0x16, 0x3, 0x12, 0x7, 0x18, 
	0x16, 0x18, 0x16, 0x11, 0xE, 0x0, 0x3, 0x16, 0x15, 
	0x1, 0x2, 0x16, 0x3, 0x12, 0x15, 0x18, 0x16, 0x18, 
	0x16, 0x11, 0xE, 0x0, 0x3, 0x16, 0x7, 0x1, 0x2, 
	0x3, 0x3, 0x12, 0x7, 0x12, 0x3, 0x12, 0x16, 0x1C, 
	0x1B, 0x0, 0x3, 0x4, 0x7, 0x1, 0x2, 0x3, 0x3, 
	0x12, 0x7, 0x12, 0x3, 0x18, 0x16, 0x10, 0x1B, 0x0, 
	0x16, 0x4, 0x7, 0x1, 0x2, 0x3, 0x3, 0x12, 0x7, 
	0x12, 0x3, 0x12, 0x9, 0x19, 0x1, 0x0, 0x16, 0x0, 
	0x7, 0x1, 0x2, 0x3, 0x3, 0x12, 0x11, 0xE, 0x3, 
	0x12, 0x9, 0x19, 0x1, 0x0, 0x4, 0x0, 0x7, 0x1, 
	0x2, 0x3, 0xF, 0xE, 0x7, 0x1, 0x3, 0x12, 0x4, 
	0x19, 0xD, 0xC, 0x0, 0x0, 0x7, 0x1, 0x2, 0x3, 
	0x3, 0x1, 0x11, 0x1, 0xF, 0x12, 0x4, 0x19, 0xD, 
	0xC, 0x0, 0x14, 0x7, 0x1, 0x2, 0x3, 0x3, 0xD, 
	0x10, 0x1, 0x3, 0xE, 0x0, 0x11, 0x1A, 0xC, 0xC, 
	0x10, 0x7, 0x1, 0x2, 0x3, 0x3, 0x1A, 0x11, 0x1A, 
	0xF, 0x1, 0x0, 0x11, 0x3, 0x19, 0xC, 0x10, 
};

Gfx l1_thin_book_bookpage_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 l1_thin_book_bookpage_ci8_pal_rgba16[] = {
	0xCE, 0x6B, 0xEF, 0x2F, 0xAD, 0x67, 0xDE, 0xAD, 0xD6, 
	0x6B, 0xA5, 0x25, 0xB5, 0xA7, 0xBD, 0xE9, 0xAD, 0x25, 
	0xD6, 0x6D, 0xBD, 0xA7, 0xB5, 0x67, 0xCE, 0x2B, 0xE6, 
	0xEF, 0xEF, 0x71, 0xDE, 0xED, 0xC6, 0x29, 0xC5, 0xE9, 
	0xF7, 0x71, 0xE7, 0x2F, 0xCE, 0x29, 0xBD, 0xA9, 0xD6, 
	0xAD, 0xD6, 0xAB, 0xF7, 0xB1, 0xC6, 0x2B, 0xE6, 0xED, 
	0xEF, 0x31, 0xC5, 0xEB, 
};

Vtx l1_thin_book_Red_mesh_vtx_0[4] = {
	{{{8, 0, 35},0, {916, 873},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8, 102, 35},0, {916, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 102, 35},0, {683, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 0, 35},0, {683, 873},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx l1_thin_book_Red_mesh_tri_0[] = {
	gsSPVertex(l1_thin_book_Red_mesh_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_Red_mesh_vtx_1[8] = {
	{{{-8, 0, 35},0, {496, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, 35},0, {496, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {-11, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {-11, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {496, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {496, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {-11, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {-11, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx l1_thin_book_Red_mesh_tri_1[] = {
	gsSPVertex(l1_thin_book_Red_mesh_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_Red_mesh_vtx_2[12] = {
	{{{-8, 102, 35},0, {513, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {-33, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {-33, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, 35},0, {513, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx l1_thin_book_Red_mesh_tri_2[] = {
	gsSPVertex(l1_thin_book_Red_mesh_vtx_2 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx l1_thin_book_root_Green_mesh_vtx_0[4] = {
	{{{8, 0, 35},0, {1257, 873},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8, 102, 35},0, {1257, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 102, 35},0, {1024, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 0, 35},0, {1024, 873},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx l1_thin_book_root_Green_mesh_tri_0[] = {
	gsSPVertex(l1_thin_book_root_Green_mesh_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_root_Green_mesh_vtx_1[8] = {
	{{{-8, 0, 35},0, {1008, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, 35},0, {1008, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {501, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {501, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {1008, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {1008, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {501, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {501, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx l1_thin_book_root_Green_mesh_tri_1[] = {
	gsSPVertex(l1_thin_book_root_Green_mesh_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_root_Green_mesh_vtx_2[12] = {
	{{{-8, 102, 35},0, {513, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {-33, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {-33, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, 35},0, {513, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx l1_thin_book_root_Green_mesh_tri_2[] = {
	gsSPVertex(l1_thin_book_root_Green_mesh_vtx_2 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx l1_thin_book_root_Purple_mesh_vtx_0[4] = {
	{{{8, 0, 35},0, {1603, 873},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8, 102, 35},0, {1603, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 102, 35},0, {1370, 1},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8, 0, 35},0, {1370, 873},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx l1_thin_book_root_Purple_mesh_tri_0[] = {
	gsSPVertex(l1_thin_book_root_Purple_mesh_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_root_Purple_mesh_vtx_1[8] = {
	{{{-8, 0, 35},0, {2032, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, 35},0, {2032, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {1525, 42},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {1525, 1077},{0x81, 0x0, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {2032, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {2032, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {1525, -22},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {1525, 1014},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx l1_thin_book_root_Purple_mesh_tri_1[] = {
	gsSPVertex(l1_thin_book_root_Purple_mesh_vtx_1 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};Vtx l1_thin_book_root_Purple_mesh_vtx_2[12] = {
	{{{-8, 102, 35},0, {513, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, 35},0, {-33, -2363},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8, 0, 35},0, {-33, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, 35},0, {513, 18361},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8, 102, -35},0, {513, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 102, -35},0, {-33, 3633},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8, 0, -35},0, {-33, 12365},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8, 0, -35},0, {513, 12365},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx l1_thin_book_root_Purple_mesh_tri_2[] = {
	gsSPVertex(l1_thin_book_root_Purple_mesh_vtx_2 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_l1_thin_book_Books_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, l1_thin_book_ci8_books_dark_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 36),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 64, l1_thin_book_ci8_books_dark_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 252, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_l1_thin_book_Books_001[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx mat_l1_thin_book_BookSides[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, l1_thin_book_book_sides_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 3),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, l1_thin_book_book_sides_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 126, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPSetLights1(l1_thin_book_BookSides_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_l1_thin_book_BookSides[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx mat_l1_thin_book_pages[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, l1_thin_book_bookpage_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 28),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 16, l1_thin_book_bookpage_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 60, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 124),
	gsSPSetLights1(l1_thin_book_pages_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_l1_thin_book_pages[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


Gfx l1_thin_book_Red_mesh[] = {
	gsSPDisplayList(mat_l1_thin_book_Books_001),
	gsSPDisplayList(l1_thin_book_Red_mesh_tri_0),
	gsSPDisplayList(mat_revert_l1_thin_book_Books_001),
	gsSPDisplayList(mat_l1_thin_book_BookSides),
	gsSPDisplayList(l1_thin_book_Red_mesh_tri_1),
	gsSPDisplayList(mat_revert_l1_thin_book_BookSides),
	gsSPDisplayList(mat_l1_thin_book_pages),
	gsSPDisplayList(l1_thin_book_Red_mesh_tri_2),
	gsSPDisplayList(mat_revert_l1_thin_book_pages),
	gsSPEndDisplayList(),
};



Gfx l1_thin_book_root_Green_mesh[] = {
	gsSPDisplayList(mat_l1_thin_book_Books_001),
	gsSPDisplayList(l1_thin_book_root_Green_mesh_tri_0),
	gsSPDisplayList(mat_revert_l1_thin_book_Books_001),
	gsSPDisplayList(mat_l1_thin_book_BookSides),
	gsSPDisplayList(l1_thin_book_root_Green_mesh_tri_1),
	gsSPDisplayList(mat_revert_l1_thin_book_BookSides),
	gsSPDisplayList(mat_l1_thin_book_pages),
	gsSPDisplayList(l1_thin_book_root_Green_mesh_tri_2),
	gsSPDisplayList(mat_revert_l1_thin_book_pages),
	gsSPEndDisplayList(),
};



Gfx l1_thin_book_root_Purple_mesh[] = {
	gsSPDisplayList(mat_l1_thin_book_Books_001),
	gsSPDisplayList(l1_thin_book_root_Purple_mesh_tri_0),
	gsSPDisplayList(mat_revert_l1_thin_book_Books_001),
	gsSPDisplayList(mat_l1_thin_book_BookSides),
	gsSPDisplayList(l1_thin_book_root_Purple_mesh_tri_1),
	gsSPDisplayList(mat_revert_l1_thin_book_BookSides),
	gsSPDisplayList(mat_l1_thin_book_pages),
	gsSPDisplayList(l1_thin_book_root_Purple_mesh_tri_2),
	gsSPDisplayList(mat_revert_l1_thin_book_pages),
	gsSPEndDisplayList(),
};



Gfx l1_thin_book_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
