Lights1 blue_cushion_Couch_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx blue_cushion_cushions_blue_ci8_aligner[] = {gsSPEndDisplayList()};
u8 blue_cushion_cushions_blue_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
	0x03, 0x01, 0x01, 0x04, 0x04, 0x04, 0x05, 0x05, 
	0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 
	0x05, 0x05, 0x04, 0x02, 0x02, 0x04, 0x05, 0x05, 
	0x05, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x05, 
	0x05, 0x05, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x05, 0x05, 0x05, 0x05, 0x02, 0x05, 0x04, 
	0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x01, 0x04, 0x04, 0x06, 0x06, 0x04, 0x00, 
	0x00, 0x01, 0x05, 0x07, 0x07, 0x07, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 
	0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x06, 0x06, 0x06, 0x08, 0x08, 0x06, 0x01, 
	0x01, 0x01, 0x07, 0x08, 0x08, 0x08, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 0x0a, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x09, 0x0b, 0x08, 0x08, 
	0x08, 0x09, 0x09, 0x09, 0x09, 0x0b, 0x06, 0x00, 
	0x01, 0x02, 0x07, 0x08, 0x08, 0x08, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x09, 0x09, 0x09, 
	0x08, 0x09, 0x08, 0x0c, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x09, 
	0x09, 0x0b, 0x09, 0x0d, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x0c, 0x08, 0x08, 
	0x08, 0x0c, 0x0c, 0x0c, 0x09, 0x0b, 0x06, 0x00, 
	0x00, 0x02, 0x07, 0x08, 0x08, 0x0e, 0x06, 0x06, 
	0x00, 0x02, 0x02, 0x00, 0x02, 0x02, 0x02, 0x05, 
	0x05, 0x05, 0x02, 0x06, 0x06, 0x08, 0x08, 0x09, 
	0x08, 0x07, 0x06, 0x04, 0x02, 0x06, 0x01, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 
	0x07, 0x0c, 0x08, 0x08, 0x05, 0x05, 0x05, 0x06, 
	0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x02, 0x02, 0x06, 0x08, 0x0b, 0x06, 0x03, 
	0x00, 0x01, 0x07, 0x08, 0x08, 0x07, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 
	0x00, 0x00, 0x01, 0x01, 0x01, 0x0e, 0x08, 0x09, 
	0x08, 0x06, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x08, 0x08, 0x08, 0x04, 0x03, 0x00, 0x01, 
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x04, 0x02, 0x02, 0x08, 0x0b, 0x06, 0x00, 
	0x00, 0x00, 0x07, 0x09, 0x08, 0x06, 0x00, 0x00, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x04, 0x01, 
	0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x08, 0x08, 
	0x07, 0x02, 0x01, 0x01, 0x00, 0x04, 0x02, 0x00, 
	0x00, 0x00, 0x01, 0x04, 0x01, 0x01, 0x01, 0x03, 
	0x05, 0x08, 0x08, 0x07, 0x05, 0x03, 0x00, 0x00, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x01, 0x01, 0x00, 0x02, 0x07, 0x08, 0x06, 0x01, 
	0x01, 0x00, 0x07, 0x09, 0x0c, 0x02, 0x01, 0x00, 
	0x00, 0x00, 0x02, 0x04, 0x01, 0x04, 0x04, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x06, 0x08, 0x08, 
	0x06, 0x02, 0x01, 0x00, 0x00, 0x02, 0x05, 0x04, 
	0x04, 0x05, 0x04, 0x04, 0x01, 0x01, 0x00, 0x03, 
	0x01, 0x07, 0x08, 0x07, 0x05, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x01, 0x01, 0x04, 0x01, 0x00, 0x01, 
	0x01, 0x00, 0x01, 0x04, 0x07, 0x08, 0x06, 0x01, 
	0x01, 0x00, 0x07, 0x09, 0x0c, 0x01, 0x00, 0x03, 
	0x01, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x05, 0x08, 0x08, 
	0x06, 0x00, 0x00, 0x01, 0x00, 0x01, 0x04, 0x05, 
	0x06, 0x06, 0x06, 0x06, 0x04, 0x04, 0x00, 0x00, 
	0x00, 0x06, 0x08, 0x07, 0x02, 0x01, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x05, 0x06, 0x05, 0x01, 0x01, 
	0x00, 0x01, 0x00, 0x05, 0x07, 0x08, 0x06, 0x00, 
	0x01, 0x00, 0x07, 0x09, 0x0c, 0x01, 0x00, 0x01, 
	0x03, 0x01, 0x04, 0x05, 0x05, 0x02, 0x02, 0x01, 
	0x00, 0x01, 0x04, 0x01, 0x00, 0x02, 0x07, 0x08, 
	0x06, 0x01, 0x00, 0x02, 0x04, 0x00, 0x02, 0x01, 
	0x04, 0x06, 0x06, 0x06, 0x06, 0x05, 0x04, 0x03, 
	0x00, 0x06, 0x08, 0x07, 0x02, 0x01, 0x00, 0x00, 
	0x04, 0x05, 0x05, 0x04, 0x06, 0x05, 0x02, 0x04, 
	0x01, 0x01, 0x00, 0x05, 0x07, 0x08, 0x06, 0x01, 
	0x01, 0x00, 0x07, 0x09, 0x07, 0x01, 0x03, 0x01, 
	0x00, 0x02, 0x01, 0x01, 0x06, 0x05, 0x01, 0x00, 
	0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x07, 0x09, 
	0x06, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 
	0x01, 0x02, 0x05, 0x05, 0x04, 0x06, 0x05, 0x00, 
	0x01, 0x06, 0x08, 0x07, 0x05, 0x02, 0x00, 0x02, 
	0x05, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 
	0x04, 0x01, 0x00, 0x04, 0x08, 0x08, 0x06, 0x00, 
	0x00, 0x02, 0x07, 0x09, 0x07, 0x01, 0x03, 0x01, 
	0x00, 0x01, 0x00, 0x04, 0x04, 0x04, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x07, 0x09, 
	0x06, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x02, 
	0x02, 0x04, 0x05, 0x06, 0x05, 0x05, 0x05, 0x01, 
	0x01, 0x06, 0x08, 0x07, 0x05, 0x04, 0x01, 0x02, 
	0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x05, 0x04, 
	0x04, 0x01, 0x00, 0x04, 0x08, 0x08, 0x02, 0x01, 
	0x04, 0x01, 0x07, 0x09, 0x07, 0x02, 0x01, 0x01, 
	0x01, 0x00, 0x01, 0x04, 0x06, 0x04, 0x01, 0x04, 
	0x04, 0x01, 0x01, 0x01, 0x01, 0x02, 0x07, 0x09, 
	0x06, 0x01, 0x01, 0x00, 0x02, 0x02, 0x01, 0x04, 
	0x04, 0x04, 0x05, 0x06, 0x06, 0x06, 0x05, 0x01, 
	0x01, 0x06, 0x08, 0x07, 0x05, 0x02, 0x02, 0x05, 
	0x06, 0x06, 0x06, 0x04, 0x01, 0x04, 0x04, 0x04, 
	0x01, 0x01, 0x00, 0x04, 0x08, 0x08, 0x02, 0x01, 
	0x00, 0x04, 0x07, 0x09, 0x07, 0x02, 0x00, 0x00, 
	0x01, 0x02, 0x04, 0x06, 0x06, 0x05, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x05, 0x04, 0x02, 0x07, 0x09, 
	0x06, 0x00, 0x01, 0x00, 0x00, 0x02, 0x04, 0x04, 
	0x04, 0x04, 0x05, 0x06, 0x05, 0x04, 0x02, 0x00, 
	0x00, 0x06, 0x08, 0x07, 0x04, 0x01, 0x02, 0x05, 
	0x06, 0x05, 0x05, 0x04, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x00, 0x00, 0x05, 0x08, 0x08, 0x02, 0x00, 
	0x00, 0x01, 0x0e, 0x09, 0x07, 0x01, 0x03, 0x03, 
	0x01, 0x01, 0x02, 0x02, 0x06, 0x06, 0x06, 0x06, 
	0x05, 0x04, 0x04, 0x02, 0x02, 0x02, 0x07, 0x09, 
	0x06, 0x00, 0x00, 0x01, 0x03, 0x01, 0x02, 0x02, 
	0x02, 0x02, 0x04, 0x04, 0x04, 0x01, 0x00, 0x00, 
	0x01, 0x06, 0x08, 0x07, 0x04, 0x02, 0x04, 0x05, 
	0x06, 0x06, 0x06, 0x04, 0x00, 0x01, 0x01, 0x01, 
	0x00, 0x01, 0x03, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x01, 0x04, 0x06, 0x09, 0x07, 0x01, 0x0f, 0x00, 
	0x00, 0x02, 0x04, 0x01, 0x02, 0x06, 0x06, 0x06, 
	0x06, 0x05, 0x04, 0x01, 0x01, 0x02, 0x07, 0x09, 
	0x06, 0x00, 0x00, 0x01, 0x03, 0x00, 0x04, 0x02, 
	0x01, 0x02, 0x01, 0x01, 0x01, 0x03, 0x03, 0x00, 
	0x00, 0x06, 0x08, 0x07, 0x04, 0x01, 0x01, 0x02, 
	0x06, 0x05, 0x04, 0x06, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x03, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x01, 0x01, 0x06, 0x09, 0x07, 0x01, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x03, 0x04, 0x06, 0x06, 
	0x06, 0x05, 0x02, 0x01, 0x01, 0x02, 0x07, 0x09, 
	0x06, 0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 
	0x00, 0x00, 0x01, 0x01, 0x00, 0x10, 0x10, 0x00, 
	0x00, 0x06, 0x08, 0x07, 0x04, 0x01, 0x01, 0x02, 
	0x02, 0x01, 0x02, 0x06, 0x01, 0x00, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x05, 0x08, 0x0c, 0x05, 0x01, 
	0x01, 0x00, 0x07, 0x09, 0x07, 0x01, 0x00, 0x00, 
	0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x04, 
	0x04, 0x05, 0x01, 0x00, 0x00, 0x02, 0x07, 0x09, 
	0x06, 0x03, 0x03, 0x03, 0x10, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x02, 0x00, 0x10, 0x10, 0x10, 0x03, 
	0x00, 0x06, 0x08, 0x07, 0x04, 0x01, 0x04, 0x00, 
	0x00, 0x03, 0x01, 0x04, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x00, 0x01, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x01, 0x01, 0x06, 0x09, 0x07, 0x02, 0x03, 0x03, 
	0x10, 0x10, 0x10, 0x10, 0x03, 0x03, 0x00, 0x01, 
	0x05, 0x04, 0x00, 0x10, 0x03, 0x00, 0x06, 0x08, 
	0x06, 0x03, 0x10, 0x10, 0x10, 0x03, 0x03, 0x10, 
	0x0f, 0x03, 0x03, 0x10, 0x10, 0x10, 0x10, 0x03, 
	0x00, 0x06, 0x08, 0x07, 0x00, 0x00, 0x01, 0x01, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 
	0x03, 0x03, 0x00, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x01, 0x00, 0x06, 0x09, 0x07, 0x02, 0x03, 0x10, 
	0x0f, 0x0f, 0x10, 0x10, 0x10, 0x03, 0x10, 0x10, 
	0x00, 0x00, 0x03, 0x10, 0x03, 0x00, 0x06, 0x08, 
	0x06, 0x03, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x03, 0x0f, 0x10, 0x10, 0x0f, 0x0f, 0x03, 
	0x00, 0x06, 0x08, 0x06, 0x01, 0x00, 0x01, 0x00, 
	0x03, 0x10, 0x10, 0x10, 0x03, 0x03, 0x00, 0x00, 
	0x03, 0x03, 0x03, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x01, 0x00, 0x06, 0x09, 0x07, 0x02, 0x03, 0x10, 
	0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x01, 0x06, 0x08, 
	0x06, 0x03, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x0f, 
	0x10, 0x03, 0x10, 0x10, 0x10, 0x0f, 0x0f, 0x03, 
	0x00, 0x06, 0x08, 0x06, 0x01, 0x00, 0x03, 0x03, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x03, 0x03, 0x00, 
	0x10, 0x0f, 0x10, 0x05, 0x08, 0x0c, 0x05, 0x00, 
	0x00, 0x01, 0x06, 0x09, 0x07, 0x02, 0x10, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x0f, 0x0f, 0x0f, 0x01, 0x06, 0x07, 
	0x06, 0x03, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x0f, 0x0f, 0x10, 0x10, 0x0f, 0x0f, 0x03, 
	0x00, 0x06, 0x07, 0x06, 0x01, 0x00, 0x10, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x03, 0x03, 
	0x0f, 0x0f, 0x10, 0x05, 0x08, 0x0c, 0x05, 0x01, 
	0x00, 0x01, 0x06, 0x08, 0x08, 0x02, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x0f, 0x0f, 0x0f, 0x03, 0x06, 0x07, 
	0x06, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 
	0x00, 0x06, 0x07, 0x06, 0x01, 0x03, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x0f, 0x11, 0x0f, 0x05, 0x08, 0x07, 0x04, 0x01, 
	0x01, 0x01, 0x06, 0x08, 0x08, 0x01, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 
	0x0f, 0x10, 0x0f, 0x0f, 0x0f, 0x03, 0x05, 0x07, 
	0x06, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x00, 0x06, 0x0e, 0x06, 0x01, 0x03, 0x0f, 0x0f, 
	0x0f, 0x12, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x0f, 
	0x0f, 0x11, 0x0f, 0x05, 0x08, 0x07, 0x04, 0x01, 
	0x01, 0x02, 0x06, 0x08, 0x08, 0x02, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x03, 0x05, 0x07, 
	0x06, 0x00, 0x0f, 0x0f, 0x12, 0x0f, 0x12, 0x11, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x03, 0x05, 0x07, 0x06, 0x03, 0x0f, 0x11, 0x12, 
	0x12, 0x12, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 
	0x0f, 0x11, 0x0f, 0x05, 0x08, 0x07, 0x04, 0x01, 
	0x04, 0x02, 0x06, 0x08, 0x08, 0x02, 0x10, 0x11, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x0f, 0x0f, 
	0x12, 0x0f, 0x0f, 0x0f, 0x03, 0x01, 0x05, 0x06, 
	0x06, 0x00, 0x0f, 0x0f, 0x12, 0x0f, 0x0f, 0x11, 
	0x0f, 0x11, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x11, 
	0x03, 0x05, 0x07, 0x04, 0x01, 0x10, 0x11, 0x0f, 
	0x12, 0x12, 0x11, 0x12, 0x12, 0x11, 0x12, 0x0f, 
	0x0f, 0x11, 0x0f, 0x05, 0x08, 0x07, 0x04, 0x01, 
	0x01, 0x01, 0x06, 0x08, 0x08, 0x04, 0x10, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x03, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x02, 0x05, 0x06, 
	0x04, 0x00, 0x0f, 0x0f, 0x11, 0x10, 0x10, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x10, 0x03, 
	0x0f, 0x05, 0x06, 0x05, 0x02, 0x03, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x10, 0x03, 0x06, 0x07, 0x07, 0x02, 0x00, 
	0x01, 0x01, 0x06, 0x08, 0x08, 0x04, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 
	0x0f, 0x03, 0x10, 0x03, 0x02, 0x02, 0x05, 0x07, 
	0x06, 0x04, 0x00, 0x0f, 0x10, 0x00, 0x00, 0x03, 
	0x0f, 0x0f, 0x01, 0x01, 0x03, 0x0f, 0x01, 0x01, 
	0x01, 0x06, 0x06, 0x06, 0x02, 0x01, 0x10, 0x01, 
	0x01, 0x10, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 
	0x03, 0x01, 0x04, 0x06, 0x07, 0x07, 0x02, 0x00, 
	0x01, 0x01, 0x04, 0x08, 0x08, 0x05, 0x05, 0x05, 
	0x05, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x05, 0x06, 0x05, 0x05, 0x07, 
	0x07, 0x05, 0x06, 0x01, 0x02, 0x02, 0x02, 0x06, 
	0x01, 0x04, 0x06, 0x06, 0x05, 0x01, 0x04, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x02, 0x02, 0x02, 0x05, 
	0x06, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x02, 
	0x00, 0x05, 0x06, 0x06, 0x07, 0x07, 0x02, 0x00, 
	0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x00, 0x01, 0x02, 0x02, 0x01, 0x00, 0x00, 
	0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x03, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x01, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 
	0x00, 0x04, 0x00, 0x02, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x00, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 
	0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 
	0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x04, 0x01, 
	0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x04, 0x04, 
	0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
	0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x04, 
	
};

Gfx blue_cushion_cushions_blue_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 blue_cushion_cushions_blue_ci8_pal_rgba16[] = {
	0x1a, 0xd9, 0x1a, 0x99, 0x1a, 0x97, 0x1a, 0xdb, 
	0x12, 0x97, 0x12, 0x57, 0x12, 0x55, 0x12, 0x13, 
	0x11, 0xd1, 0x11, 0x8f, 0x09, 0x4d, 0x11, 0xcf, 
	0x11, 0xd3, 0x09, 0x8f, 0x12, 0x15, 0x1b, 0x1d, 
	0x1b, 0x1b, 0x1b, 0x5f, 0x1b, 0x5d, 
};

Vtx blue_cushion_BlueCushion_mesh_layer_1_vtx_0[16] = {
	{{{114, 0, -113},0, {1895, 837},{0x2C, 0x91, 0xD5, 0xFF}}},
	{{{150, 46, -150},0, {1974, 942},{0x3C, 0xA1, 0xC4, 0xFF}}},
	{{{150, 46, 150},0, {1329, 942},{0x3C, 0xA1, 0x3C, 0xFF}}},
	{{{-114, 0, -113},0, {1895, 177},{0xD4, 0x91, 0xD5, 0xFF}}},
	{{{-114, 0, 113},0, {1409, 177},{0xD4, 0x91, 0x2B, 0xFF}}},
	{{{114, 0, 113},0, {1409, 837},{0x2C, 0x91, 0x2B, 0xFF}}},
	{{{-150, 46, 150},0, {1329, 73},{0xC4, 0xA1, 0x3C, 0xFF}}},
	{{{-150, 46, -150},0, {1974, 73},{0xC4, 0xA1, 0xC4, 0xFF}}},
	{{{114, 92, -113},0, {1895, 837},{0x2C, 0x6F, 0xD5, 0xFF}}},
	{{{150, 46, 150},0, {1329, 942},{0x3C, 0x5F, 0x3C, 0xFF}}},
	{{{150, 46, -150},0, {1974, 942},{0x3C, 0x5F, 0xC4, 0xFF}}},
	{{{114, 92, 113},0, {1409, 837},{0x2C, 0x6F, 0x2B, 0xFF}}},
	{{{-114, 92, 113},0, {1409, 177},{0xD4, 0x6F, 0x2B, 0xFF}}},
	{{{-114, 92, -113},0, {1895, 177},{0xD4, 0x6F, 0xD5, 0xFF}}},
	{{{-150, 46, -150},0, {1974, 73},{0xC4, 0x5F, 0xC4, 0xFF}}},
	{{{-150, 46, 150},0, {1329, 73},{0xC4, 0x5F, 0x3C, 0xFF}}},
};

Gfx blue_cushion_BlueCushion_mesh_layer_1_tri_0[] = {
	gsSPVertex(blue_cushion_BlueCushion_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 2, 5, 0, 5, 2, 6, 0),
	gsSP2Triangles(5, 6, 4, 0, 4, 6, 7, 0),
	gsSP2Triangles(4, 7, 3, 0, 3, 7, 1, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(8, 12, 11, 0, 8, 13, 12, 0),
	gsSP2Triangles(13, 8, 10, 0, 13, 10, 14, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(11, 12, 15, 0, 11, 15, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_blue_cushion_Couch[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, blue_cushion_cushions_blue_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 18),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 64, blue_cushion_cushions_blue_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 252, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPSetLights1(blue_cushion_Couch_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_blue_cushion_Couch[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx blue_cushion_BlueCushion_mesh_layer_1[] = {
	gsSPDisplayList(mat_blue_cushion_Couch),
	gsSPDisplayList(blue_cushion_BlueCushion_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_blue_cushion_Couch),
	gsSPEndDisplayList(),
};

Gfx blue_cushion_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

