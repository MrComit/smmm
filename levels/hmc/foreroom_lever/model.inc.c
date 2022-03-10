Lights1 foreroom_lever_Lever_001_v4_lights = gdSPDefLights1(
	0x31, 0x42, 0x48,
	0x62, 0x85, 0x90, 0x28, 0x28, 0x28);

Gfx foreroom_lever_metal_ci4_aligner[] = {gsSPEndDisplayList()};
u8 foreroom_lever_metal_ci4[] = {
	0x01, 0x20, 0x20, 0x30, 0x40, 0x00, 0x33, 0x03, 
	0x33, 0x56, 0x35, 0x53, 0x33, 0x73, 0x35, 0x33, 
	0x53, 0x73, 0x53, 0x33, 0x77, 0x33, 0x33, 0x53, 
	0x33, 0x33, 0x53, 0x70, 0x87, 0x00, 0x02, 0x22, 
	0x42, 0x24, 0x73, 0x33, 0x44, 0x02, 0x33, 0x35, 
	0x55, 0x65, 0x55, 0x63, 0x53, 0x37, 0x33, 0x33, 
	0x77, 0x05, 0x38, 0x33, 0x73, 0x07, 0x07, 0x73, 
	0x73, 0x77, 0x33, 0x35, 0x08, 0x70, 0x00, 0x00, 
	0x02, 0x20, 0x30, 0x37, 0x00, 0x04, 0x33, 0x35, 
	0x65, 0x53, 0x66, 0x66, 0x53, 0x33, 0x33, 0x50, 
	0x00, 0x70, 0x33, 0x33, 0x77, 0x07, 0x20, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x37, 0x00, 
	0x02, 0x07, 0x00, 0x30, 0x20, 0x00, 0x33, 0x33, 
	0x55, 0x66, 0x66, 0x65, 0x33, 0x53, 0x53, 0x37, 
	0x30, 0x03, 0x73, 0x00, 0x37, 0x07, 0x20, 0x00, 
	0x04, 0x00, 0x00, 0x02, 0x40, 0x40, 0x00, 0x00, 
	0x24, 0x00, 0x00, 0x73, 0x03, 0x70, 0x37, 0x05, 
	0x66, 0x66, 0x66, 0x66, 0x55, 0x55, 0x55, 0x50, 
	0x30, 0x37, 0x37, 0x33, 0x70, 0x70, 0x00, 0x92, 
	0x24, 0x24, 0x00, 0x00, 0x00, 0x77, 0x80, 0x00, 
	0x02, 0x07, 0x00, 0x37, 0x33, 0x30, 0x57, 0x73, 
	0x66, 0xa6, 0x66, 0x66, 0x65, 0x65, 0x33, 0x57, 
	0x37, 0x78, 0x73, 0x37, 0x03, 0x87, 0x04, 0x24, 
	0x24, 0x20, 0x20, 0x00, 0x00, 0x07, 0x30, 0x00, 
	0x29, 0x40, 0x00, 0x03, 0x07, 0x04, 0x00, 0x73, 
	0x5a, 0x66, 0x66, 0x66, 0x66, 0x55, 0x35, 0x65, 
	0x30, 0x77, 0x33, 0x33, 0x07, 0x77, 0x20, 0x20, 
	0x44, 0x22, 0x00, 0x00, 0x00, 0x03, 0x37, 0x80, 
	0x22, 0x00, 0x04, 0x07, 0x00, 0x2b, 0x03, 0x33, 
	0x33, 0x6a, 0x66, 0x66, 0x66, 0x66, 0xac, 0xcc, 
	0x32, 0x07, 0x33, 0x33, 0x70, 0x00, 0x22, 0x20, 
	0x22, 0x00, 0x07, 0x00, 0x78, 0x03, 0x37, 0x00, 
	0x00, 0x77, 0x00, 0x00, 0x00, 0x21, 0x03, 0x53, 
	0x33, 0x36, 0x66, 0xc6, 0x66, 0x66, 0xcc, 0xcc, 
	0x52, 0x03, 0x03, 0x07, 0x03, 0x77, 0x24, 0x22, 
	0x42, 0x20, 0x73, 0x33, 0x70, 0x73, 0x37, 0x30, 
	0x00, 0x73, 0x00, 0x00, 0x08, 0x09, 0x05, 0xaa, 
	0xa6, 0x6a, 0xca, 0xca, 0x66, 0x65, 0xcc, 0xcc, 
	0x32, 0x00, 0x33, 0x73, 0x33, 0x70, 0x40, 0x40, 
	0x02, 0x07, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 
	0x00, 0x03, 0x04, 0x03, 0x07, 0x01, 0x05, 0xcc, 
	0xcc, 0xac, 0xcc, 0xc6, 0x6a, 0x66, 0x6c, 0xcc, 
	0x72, 0x00, 0x03, 0x73, 0x37, 0x37, 0x04, 0x44, 
	0x24, 0x08, 0x33, 0x33, 0x73, 0x33, 0x30, 0x80, 
	0x07, 0x03, 0x30, 0x07, 0x08, 0x01, 0x05, 0xcc, 
	0xcc, 0x6c, 0xcc, 0xca, 0x65, 0x65, 0x6a, 0xcc, 
	0x72, 0x03, 0x03, 0x73, 0x33, 0x33, 0x70, 0x04, 
	0x00, 0x00, 0x03, 0x35, 0x00, 0x07, 0x33, 0x33, 
	0x00, 0x03, 0x30, 0x33, 0x33, 0x09, 0x05, 0xac, 
	0xaa, 0x5a, 0xcc, 0xcc, 0x65, 0x65, 0x55, 0x66, 
	0x04, 0x07, 0x33, 0x33, 0x33, 0x33, 0x73, 0x00, 
	0x70, 0x00, 0x40, 0x33, 0x00, 0x00, 0x33, 0x33, 
	0x30, 0x77, 0x30, 0x33, 0x33, 0x79, 0x75, 0xa6, 
	0x56, 0x56, 0xca, 0x66, 0x55, 0x53, 0x33, 0x35, 
	0x42, 0x00, 0x87, 0x83, 0x33, 0x35, 0x35, 0x33, 
	0x33, 0x30, 0x22, 0x77, 0x20, 0x83, 0x33, 0x55, 
	0x00, 0x03, 0x37, 0x88, 0x33, 0x09, 0x76, 0x66, 
	0x56, 0x66, 0xaa, 0x65, 0x53, 0x53, 0x33, 0x55, 
	0x00, 0x07, 0x77, 0x30, 0x35, 0x66, 0x66, 0x55, 
	0x66, 0xa6, 0x70, 0x22, 0x07, 0x83, 0x55, 0x33, 
	0x33, 0x73, 0x70, 0x08, 0x33, 0x02, 0x06, 0x65, 
	0x56, 0xaa, 0xa6, 0x63, 0x65, 0x53, 0x33, 0x85, 
	0x02, 0x77, 0x30, 0x00, 0x73, 0x6a, 0x66, 0x6a, 
	0xac, 0xcc, 0x58, 0x00, 0x00, 0x08, 0x33, 0x35, 
	0x30, 0x03, 0x30, 0x00, 0x33, 0x02, 0x05, 0x00, 
	0x35, 0x55, 0x67, 0x03, 0x53, 0x37, 0x21, 0x05, 
	0x00, 0x03, 0x00, 0x00, 0x03, 0x66, 0x66, 0x6a, 
	0xca, 0xca, 0x66, 0x00, 0x00, 0x03, 0x38, 0x37, 
	0x33, 0x37, 0x30, 0x03, 0x77, 0x72, 0x08, 0xb9, 
	0x88, 0x73, 0x39, 0xb4, 0x33, 0x87, 0x21, 0x03, 
	0x22, 0x30, 0x00, 0x00, 0x73, 0x66, 0x66, 0x66, 
	0x65, 0x55, 0x6a, 0x50, 0x42, 0x07, 0x33, 0x83, 
	0x30, 0x07, 0x80, 0x00, 0x03, 0x29, 0x23, 0x00, 
	0x70, 0x30, 0x04, 0x20, 0x33, 0x30, 0x04, 0x00, 
	0x24, 0x04, 0x24, 0x44, 0x03, 0x56, 0x66, 0x65, 
	0x53, 0x33, 0x55, 0x58, 0x2d, 0x10, 0x00, 0x00, 
	0x24, 0x00, 0x22, 0x42, 0x00, 0x21, 0x90, 0x43, 
	0x73, 0x00, 0x44, 0x00, 0x77, 0x00, 0x00, 0x49, 
	0x11, 0xbb, 0xbb, 0x22, 0x73, 0x55, 0x65, 0x53, 
	0x35, 0x33, 0x33, 0x33, 0x01, 0x00, 0x2b, 0xb1, 
	0x29, 0x22, 0x11, 0x11, 0x12, 0x1b, 0x20, 0x00, 
	0x07, 0x02, 0x02, 0x44, 0x08, 0x74, 0x22, 0x29, 
	0xb1, 0x1b, 0xbd, 0x13, 0x33, 0x36, 0x63, 0x53, 
	0x73, 0x30, 0x73, 0x30, 0x70, 0x33, 0x0b, 0x19, 
	0x42, 0x22, 0x12, 0x99, 0x92, 0x9b, 0xb1, 0x22, 
	0x29, 0x99, 0x99, 0x22, 0x20, 0x77, 0x00, 0x02, 
	0x91, 0x99, 0x9b, 0x25, 0x53, 0x53, 0x55, 0x63, 
	0x33, 0x80, 0x77, 0x70, 0x30, 0x75, 0x32, 0x40, 
	0x22, 0x29, 0x91, 0xbb, 0x20, 0x29, 0x92, 0x22, 
	0x42, 0x22, 0x22, 0x24, 0x00, 0x03, 0x33, 0x72, 
	0x00, 0x00, 0x2b, 0x46, 0x50, 0x03, 0x56, 0xa6, 
	0x33, 0x80, 0x33, 0x77, 0x34, 0x73, 0x01, 0x27, 
	0x29, 0x19, 0x99, 0xbb, 0x24, 0x09, 0x22, 0x22, 
	0x22, 0x92, 0x22, 0x24, 0x00, 0x00, 0x70, 0x30, 
	0x00, 0x04, 0x9b, 0x47, 0x39, 0xb7, 0x56, 0x65, 
	0x33, 0x00, 0x07, 0x77, 0x07, 0x00, 0x1b, 0xb2, 
	0x02, 0x19, 0x11, 0x92, 0x22, 0x29, 0x22, 0x02, 
	0x22, 0x22, 0x22, 0x22, 0x02, 0x20, 0x9b, 0x24, 
	0x40, 0x00, 0x21, 0x00, 0x04, 0x07, 0x33, 0x33, 
	0x30, 0x00, 0x00, 0x00, 0x00, 0x04, 0xbb, 0x12, 
	0x29, 0x19, 0x11, 0x92, 0x22, 0x21, 0x20, 0x04, 
	0x22, 0x92, 0x24, 0x40, 0x02, 0x22, 0x1b, 0x42, 
	0x20, 0x00, 0x21, 0x07, 0x00, 0x33, 0x07, 0x87, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xbb, 0x99, 
	0x11, 0x99, 0x11, 0x22, 0x22, 0x9b, 0x23, 0x34, 
	0x29, 0x21, 0x22, 0x07, 0x04, 0x22, 0x20, 0x99, 
	0x22, 0x00, 0x21, 0x03, 0x80, 0x33, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1b, 0x09, 0xbb, 0x24, 
	0x11, 0x11, 0x1b, 0x29, 0x22, 0x1b, 0xb2, 0x30, 
	0x22, 0x19, 0x92, 0x22, 0x22, 0x91, 0x1b, 0xbb, 
	0x12, 0x02, 0x91, 0x07, 0x30, 0x33, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x04, 0xbb, 0x42, 0xbb, 0x99, 
	0x11, 0x11, 0x1b, 0x11, 0x99, 0x29, 0x11, 0x22, 
	0x22, 0x12, 0x99, 0x11, 0x11, 0xbb, 0xb1, 0xbb, 
	0x12, 0x42, 0x1b, 0x17, 0x30, 0x33, 0x00, 0x40, 
	0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0xbb, 0x22, 
	0x11, 0x11, 0x1b, 0x11, 0x12, 0x22, 0x22, 0x24, 
	0x42, 0x12, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x92, 0x21, 0x1b, 0xb4, 0x73, 0x34, 0x40, 0x42, 
	0x40, 0x00, 0x07, 0x00, 0x00, 0x30, 0x11, 0x22, 
	0x99, 0x11, 0x11, 0x11, 0x92, 0x22, 0x92, 0x24, 
	0x02, 0x29, 0x22, 0x42, 0x22, 0x22, 0x22, 0x29, 
	0x11, 0x91, 0x1b, 0xb2, 0x38, 0x0b, 0x10, 0x42, 
	0x00, 0x00, 0x73, 0x37, 0x78, 0x00, 0x19, 0x22, 
	0x92, 0x22, 0x11, 0x11, 0x92, 0x22, 0x24, 0x40, 
	0x40, 0x24, 0x00, 0x22, 0x22, 0x22, 0x22, 0x29, 
	0x11, 0x19, 0x1b, 0xb1, 0x07, 0x74, 0x20, 0x20, 
	0x40, 0x03, 0x83, 0x38, 0x77, 0x04, 0x19, 0x99, 
	0x22, 0x29, 0x91, 0x11, 0x22, 0x22, 0x40, 0x20, 
	0x00, 0x40, 0x04, 0x00, 0x22, 0x20, 0x41, 0x22, 
	0x91, 0xbb, 0x1b, 0x11, 0x00, 0x07, 0x70, 0x04, 
	0x00, 0x37, 0x33, 0x38, 0x02, 0x00, 0x92, 0x44, 
	0x22, 0x22, 0x21, 0x91, 0x12, 0x20, 0x00, 0x20, 
	0x04, 0x00, 0x00, 0x00, 0x42, 0x22, 0x22, 0x29, 
	0x91, 0xbb, 0x11, 0x21, 0x40, 0x07, 0x37, 0x00, 
	0x00, 0x00, 0x07, 0x33, 0xbb, 0x07, 0x92, 0x22, 
	0x22, 0x22, 0x29, 0x99, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x22, 
	0x99, 0x99, 0x92, 0x11, 0x00, 0x02, 0x03, 0x70, 
	0x00, 0x00, 0x20, 0x33, 0x22, 0x37, 0x22, 0x22, 
	0x24, 0x22, 0x12, 0x22, 0x00, 0x40, 0x04, 0x02, 
	0x00, 0x00, 0x00, 0x02, 0x42, 0x22, 0x22, 0x22, 
	0x92, 0x22, 0x40, 0x49, 0x07, 0x4b, 0x93, 0x80, 
	0x00, 0x00, 0x00, 0x73, 0x33, 0x33, 0x02, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x00, 0x07, 0x00, 0x00, 
	0x73, 0x80, 0x70, 0x00, 0x22, 0x24, 0x22, 0x22, 
	0x29, 0x20, 0x33, 0x09, 0x70, 0x02, 0x03, 0x30, 
	0x08, 0x00, 0x00, 0x73, 0x55, 0x33, 0x09, 0x24, 
	0x22, 0x92, 0x12, 0x22, 0x00, 0x03, 0x30, 0x07, 
	0x73, 0x87, 0x70, 0x00, 0x00, 0x20, 0x24, 0x22, 
	0x29, 0x20, 0x03, 0x41, 0x00, 0x00, 0x03, 0x78, 
	0x03, 0x70, 0x70, 0x35, 0x36, 0x33, 0x02, 0x20, 
	0x22, 0x22, 0x99, 0x22, 0x00, 0x07, 0x38, 0x33, 
	0x33, 0x33, 0x04, 0x44, 0x00, 0x22, 0x22, 0x99, 
	0x99, 0x12, 0x00, 0x21, 0x02, 0x22, 0x22, 0x22, 
	0x20, 0x07, 0x76, 0x65, 0x53, 0x30, 0x72, 0x20, 
	0x22, 0x24, 0x22, 0x20, 0x40, 0x08, 0x35, 0x56, 
	0x55, 0x53, 0x00, 0x40, 0x75, 0x60, 0x22, 0x22, 
	0x00, 0x07, 0x55, 0x74, 0x57, 0x29, 0x22, 0x20, 
	0x07, 0x33, 0x76, 0xac, 0xcc, 0x65, 0x32, 0x22, 
	0x22, 0x42, 0x92, 0x24, 0x20, 0x07, 0x36, 0x66, 
	0x66, 0x53, 0x07, 0x83, 0x6c, 0xa3, 0x40, 0x07, 
	0x33, 0x03, 0x65, 0x80, 0xa6, 0x33, 0x33, 0x53, 
	0x08, 0x30, 0x83, 0x6c, 0xcc, 0xcc, 0xc2, 0x22, 
	0x22, 0x44, 0x22, 0x40, 0x00, 0x07, 0x56, 0x6a, 
	0x66, 0x60, 0x70, 0x33, 0x35, 0x33, 0x02, 0x00, 
	0x33, 0x00, 0x33, 0x22, 0x66, 0x63, 0x33, 0x33, 
	0x21, 0x78, 0x35, 0x6c, 0x65, 0x6a, 0x52, 0x92, 
	0x22, 0x22, 0x20, 0x00, 0x02, 0x40, 0x56, 0xaa, 
	0xa6, 0x33, 0x00, 0x87, 0x70, 0x00, 0x42, 0x47, 
	0x37, 0x4b, 0x20, 0x29, 0x66, 0x65, 0x53, 0x33, 
	0x21, 0x03, 0x53, 0x55, 0x29, 0x03, 0x09, 0x22, 
	0x92, 0x22, 0x40, 0x00, 0x04, 0x07, 0x36, 0x66, 
	0x66, 0x33, 0x87, 0x83, 0x00, 0x40, 0x22, 0x20, 
	0x00, 0x22, 0x00, 0x22, 0x66, 0x66, 0x66, 0x55, 
	0x33, 0x55, 0x55, 0x37, 0x21, 0x03, 0x01, 0x22, 
	0x99, 0x29, 0x20, 0x20, 0x02, 0x00, 0x33, 0x66, 
	0xa6, 0x37, 0x87, 0x33, 0x00, 0x20, 0x24, 0x24, 
	0x00, 0x40, 0x00, 0x02, 0x66, 0x66, 0x66, 0x53, 
	0x33, 0x33, 0x37, 0x77, 0x00, 0x40, 0x71, 0x92, 
	0x19, 0x22, 0x20, 0x24, 0x00, 0x44, 0x05, 0x36, 
	0xa6, 0x33, 0x03, 0x30, 0x00, 0x22, 0x22, 0x22, 
	0x22, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x55, 
	0x33, 0x33, 0x77, 0x00, 0x00, 0x07, 0x39, 0x29, 
	0x91, 0x12, 0x22, 0x24, 0x00, 0x40, 0x85, 0x55, 
	0x53, 0x00, 0x88, 0x80, 0x04, 0x04, 0x22, 0x22, 
	0x24, 0x20, 0x07, 0x70, 0xaa, 0xcc, 0x6a, 0x66, 
	0x53, 0x35, 0x37, 0x04, 0x44, 0x03, 0x51, 0x19, 
	0x91, 0x22, 0x22, 0x44, 0x04, 0x40, 0x86, 0x53, 
	0x00, 0x00, 0x08, 0x00, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x07, 0x00, 0xaa, 0xa6, 0xac, 0xa6, 
	0x53, 0x83, 0x37, 0x04, 0x42, 0x27, 0x31, 0x99, 
	0x19, 0x24, 0x20, 0x04, 0x42, 0x19, 0x33, 0x37, 
	0x00, 0x9b, 0x94, 0x02, 0x22, 0x1b, 0x14, 0x92, 
	0x22, 0x1d, 0x17, 0x22, 0x6c, 0xac, 0xca, 0xaa, 
	0x65, 0x07, 0x70, 0x04, 0x42, 0x40, 0x7b, 0x11, 
	0x12, 0x22, 0x00, 0x04, 0x40, 0x12, 0x07, 0x30, 
	0x02, 0x1b, 0x92, 0x22, 0x99, 0x1b, 0x12, 0x22, 
	0x02, 0x21, 0x20, 0x22, 0x6c, 0xac, 0xa6, 0x6a, 
	0x66, 0x33, 0x80, 0x04, 0x9b, 0x20, 0x3b, 0x22, 
	0x92, 0x22, 0x07, 0x00, 0x00, 0x40, 0x70, 0x07, 
	0x00, 0x22, 0x22, 0x29, 0x11, 0x11, 0x19, 0x29, 
	0x21, 0x22, 0x00, 0x22, 0x6a, 0xaa, 0xaa, 0x66, 
	0x55, 0x33, 0x37, 0x00, 0x9b, 0x20, 0x4b, 0x20, 
	0x11, 0xb1, 0x92, 0x42, 0x22, 0x42, 0x44, 0x24, 
	0x22, 0x22, 0x21, 0x99, 0x19, 0x22, 0x91, 0x11, 
	0x99, 0x99, 0x9b, 0xbb, 0x66, 0x66, 0x66, 0x66, 
	0x35, 0x35, 0x63, 0x30, 0x02, 0x24, 0x2b, 0x20, 
	0x21, 0x19, 0x22, 0x04, 0x77, 0x02, 0x09, 0x2b, 
	0x11, 0x11, 0x91, 0x92, 0x22, 0x36, 0x50, 0x24, 
	0x04, 0x44, 0x22, 0xb9, 0x56, 0x66, 0x66, 0x55, 
	0x55, 0x35, 0x53, 0x22, 0x22, 0x20, 0x34, 0x56, 
	0x00, 0x70, 0x36, 0x66, 0x6c, 0xa6, 0xc6, 0x60, 
	0x03, 0x33, 0x33, 0x35, 0x55, 0x6c, 0x65, 0x33, 
	0x63, 0x56, 0x35, 0x65, 0x65, 0x56, 0x56, 0x65, 
	0x55, 0x53, 0x87, 0x29, 0x24, 0x00, 0x72, 0x35, 
	0x40, 0x00, 0x33, 0x55, 0x33, 0x33, 0x56, 0x83, 
	0x83, 0x33, 0x00, 0x33, 0x35, 0x56, 0x37, 0x00, 
	0x77, 0x33, 0x33, 0x35, 0x33, 0x56, 0x56, 0x65, 
	0x55, 0x65, 0x30, 0x02, 0x22, 0x76, 0x01, 0x00, 
	0x00, 0x30, 0x35, 0x53, 0x30, 0x20, 0x53, 0x00, 
	0x00, 0x03, 0x02, 0x73, 0x33, 0x33, 0x73, 0x00, 
	0x83, 0x33, 0x00, 0x00, 0x03, 0x3a, 0x66, 0x66, 
	0x66, 0x66, 0x65, 0x33, 0x91, 0x3a, 0x62, 0x20, 
	0x77, 0x80, 0x73, 0x37, 0x30, 0x00, 0x53, 0x00, 
	0x00, 0x00, 0x41, 0x00, 0x74, 0x20, 0x00, 0x20, 
	0x02, 0x42, 0x12, 0x04, 0x03, 0x56, 0x66, 0x66, 
	0xaa, 0xcc, 0xc6, 0x66, 0x67, 0x03, 0x32, 0x03, 
	0x33, 0x73, 0x33, 0x33, 0x33, 0x37, 0x67, 0x80, 
	0x70, 0x00, 0x02, 0x07, 0x02, 0xd9, 0x00, 0x40, 
	0x42, 0x21, 0xb1, 0x12, 0x40, 0x77, 0x00, 0x20, 
	0x03, 0x66, 0x53, 0x53, 0x35, 0x04, 0x00, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x70, 0x07, 0x33, 0x00, 
	0x70, 0x03, 0x09, 0x00, 0x02, 0x12, 0x40, 0x00, 
	0x02, 0x22, 0x11, 0xdb, 0x44, 0x00, 0x00, 0x02, 
	0x02, 0x20, 0x02, 0x21, 0x11, 0xbb, 0x98, 0x33, 
	0x33, 0x07, 0x33, 0x33, 0x33, 0x30, 0x53, 0x00, 
	0x07, 0x03, 0x04, 0x03, 0x37, 0x03, 0x78, 0x73, 
	0x07, 0x00, 0x42, 0x12, 0x00, 0x70, 0x03, 0x30, 
	0x0b, 0xb4, 0x00, 0x00, 0x22, 0x20, 0x73, 0x73, 
	0x63, 0x00, 0x00, 0x33, 0x33, 0x70, 0x33, 0x40, 
	0x07, 0x37, 0x73, 0x33, 0x37, 0x78, 0x07, 0x00, 
	0x00, 0x40, 0x22, 0x40, 0x00, 0x07, 0x33, 0x00, 
	0x02, 0x93, 0x83, 0x38, 0x00, 0x44, 0x00, 0x03, 
	0x30, 0x07, 0x07, 0x35, 0x50, 0x92, 0x03, 0x03, 
	0x33, 0x33, 0x33, 0x33, 0x30, 0x73, 0x07, 0x03, 
	0x33, 0x37, 0x00, 0x04, 0x00, 0x77, 0x33, 0x70, 
	0x37, 0x00, 0x30, 0x00, 0x40, 0x42, 0x09, 0x20, 
	0x02, 0x20, 0x80, 0x00, 0x02, 0x92, 0x33, 0x00, 
	0x73, 0x33, 0x33, 0x35, 0x30, 0x70, 0x70, 0x00, 
	0x08, 0x37, 0x07, 0x04, 0x40, 0x33, 0x33, 0x77, 
	0x33, 0x35, 0x53, 0x37, 0x00, 0x22, 0x02, 0x94, 
	0x22, 0x24, 0x40, 0x00, 0x04, 0x22, 0x37, 0x03, 
	0x55, 0x33, 0x35, 0x55, 0x53, 0x83, 0x33, 0x33, 
	0x37, 0x30, 0x33, 0x70, 0x00, 0x33, 0x33, 0x30, 
	0x33, 0x83, 0x38, 0x37, 0x00, 0x42, 0x22, 0x22, 
	
};

Gfx foreroom_lever_metal_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 foreroom_lever_metal_ci4_pal_rgba16[] = {
	0x73, 0x5b, 0x62, 0xd7, 0x6b, 0x19, 0x7b, 0x9d, 
	0x6b, 0x59, 0x7b, 0xdd, 0x83, 0xdf, 0x73, 0x9b, 
	0x7b, 0x9b, 0x63, 0x19, 0x84, 0x1f, 0x5a, 0xd7, 
	0x8c, 0x21, 0x52, 0x53, 
};

Gfx foreroom_lever_red_ball_ci8_aligner[] = {gsSPEndDisplayList()};
u8 foreroom_lever_red_ball_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x04, 
	0x05, 0x05, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 
	0x0b, 0x0b, 0x0b, 0x0a, 0x0a, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0c, 0x0d, 
	0x0d, 0x0e, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0b, 
	0x0f, 0x10, 0x10, 0x10, 0x10, 0x0f, 0x0b, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x03, 0x0c, 0x11, 0x12, 
	0x0e, 0x06, 0x07, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 
	0x10, 0x13, 0x13, 0x13, 0x14, 0x13, 0x13, 0x0f, 
	0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x03, 0x05, 0x11, 0x12, 0x15, 
	0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 
	0x13, 0x14, 0x14, 0x14, 0x16, 0x16, 0x14, 0x14, 
	0x13, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x04, 0x0d, 0x17, 0x18, 0x12, 0x19, 
	0x06, 0x08, 0x09, 0x0a, 0x0f, 0x0f, 0x10, 0x13, 
	0x14, 0x14, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 
	0x14, 0x13, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x1a, 0x1b, 0x1c, 0x18, 0x0e, 0x06, 
	0x07, 0x08, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x14, 
	0x14, 0x1d, 0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x16, 
	0x16, 0x14, 0x13, 0x0b, 0x01, 0x00, 0x00, 0x00, 
	0x01, 0x03, 0x20, 0x21, 0x1c, 0x12, 0x0e, 0x06, 
	0x07, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x14, 
	0x1e, 0x22, 0x23, 0x23, 0x22, 0x24, 0x1f, 0x1f, 
	0x1f, 0x16, 0x14, 0x10, 0x0b, 0x01, 0x00, 0x00, 
	0x00, 0x04, 0x20, 0x25, 0x1c, 0x15, 0x19, 0x06, 
	0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x1d, 
	0x23, 0x26, 0x27, 0x27, 0x26, 0x23, 0x24, 0x1f, 
	0x1f, 0x16, 0x16, 0x13, 0x0f, 0x00, 0x00, 0x00, 
	0x03, 0x1b, 0x28, 0x21, 0x18, 0x15, 0x19, 0x06, 
	0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x1d, 
	0x29, 0x2a, 0x2b, 0x2c, 0x2a, 0x26, 0x22, 0x24, 
	0x1f, 0x1f, 0x16, 0x14, 0x10, 0x0b, 0x00, 0x00, 
	0x04, 0x2d, 0x2e, 0x21, 0x18, 0x15, 0x19, 0x06, 
	0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x1d, 
	0x29, 0x2f, 0x30, 0x31, 0x2c, 0x27, 0x23, 0x24, 
	0x1f, 0x1f, 0x16, 0x14, 0x13, 0x0b, 0x00, 0x00, 
	0x2d, 0x32, 0x2e, 0x21, 0x18, 0x0e, 0x19, 0x06, 
	0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x1d, 
	0x23, 0x2a, 0x2c, 0x2b, 0x33, 0x27, 0x23, 0x24, 
	0x1f, 0x1f, 0x16, 0x14, 0x13, 0x0f, 0x0a, 0x01, 
	0x32, 0x2e, 0x28, 0x34, 0x18, 0x15, 0x19, 0x06, 
	0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 0x35, 
	0x36, 0x26, 0x27, 0x27, 0x27, 0x29, 0x22, 0x24, 
	0x1f, 0x1f, 0x16, 0x14, 0x13, 0x10, 0x0a, 0x01, 
	0x32, 0x2e, 0x28, 0x34, 0x18, 0x15, 0x19, 0x06, 
	0x07, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x10, 0x13, 
	0x35, 0x36, 0x23, 0x23, 0x23, 0x22, 0x24, 0x1f, 
	0x1f, 0x16, 0x16, 0x14, 0x13, 0x0f, 0x0a, 0x01, 
	0x32, 0x2e, 0x28, 0x21, 0x18, 0x15, 0x19, 0x06, 
	0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x13, 
	0x14, 0x14, 0x1d, 0x1e, 0x1e, 0x1e, 0x1f, 0x16, 
	0x16, 0x16, 0x14, 0x14, 0x13, 0x0f, 0x0a, 0x00, 
	0x32, 0x28, 0x25, 0x21, 0x1c, 0x15, 0x0e, 0x06, 
	0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x10, 0x10, 
	0x13, 0x14, 0x14, 0x16, 0x16, 0x16, 0x16, 0x16, 
	0x16, 0x14, 0x14, 0x13, 0x10, 0x0f, 0x0a, 0x00, 
	0x37, 0x28, 0x25, 0x21, 0x1c, 0x12, 0x0e, 0x06, 
	0x06, 0x07, 0x09, 0x0a, 0x0b, 0x0b, 0x0f, 0x10, 
	0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 
	0x14, 0x14, 0x13, 0x13, 0x10, 0x0b, 0x0a, 0x01, 
	0x37, 0x21, 0x21, 0x21, 0x34, 0x18, 0x15, 0x19, 
	0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0f, 0x0f, 
	0x10, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 
	0x14, 0x13, 0x13, 0x10, 0x0f, 0x0b, 0x09, 0x01, 
	0x38, 0x1c, 0x34, 0x34, 0x34, 0x18, 0x15, 0x0e, 
	0x06, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0f, 
	0x0f, 0x10, 0x10, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x10, 0x0f, 0x0b, 0x0a, 0x07, 0x01, 
	0x38, 0x34, 0x1c, 0x34, 0x34, 0x1c, 0x12, 0x0e, 
	0x19, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0a, 0x0b, 
	0x0f, 0x0f, 0x10, 0x10, 0x10, 0x13, 0x13, 0x10, 
	0x10, 0x10, 0x0f, 0x0b, 0x0a, 0x08, 0x06, 0x01, 
	0x1a, 0x1b, 0x18, 0x1c, 0x1c, 0x1c, 0x18, 0x15, 
	0x0e, 0x06, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 
	0x0b, 0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x10, 
	0x0f, 0x0f, 0x0b, 0x0a, 0x09, 0x07, 0x06, 0x01, 
	0x39, 0x17, 0x12, 0x18, 0x18, 0x18, 0x18, 0x12, 
	0x0e, 0x19, 0x06, 0x06, 0x07, 0x08, 0x09, 0x0a, 
	0x0a, 0x0b, 0x0b, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0b, 0x0a, 0x09, 0x08, 0x06, 0x04, 0x01, 
	0x02, 0x1a, 0x18, 0x12, 0x18, 0x18, 0x12, 0x12, 
	0x15, 0x0e, 0x19, 0x06, 0x06, 0x07, 0x08, 0x09, 
	0x0a, 0x0a, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0a, 0x09, 0x08, 0x06, 0x19, 0x04, 0x01, 
	0x02, 0x1a, 0x1a, 0x0e, 0x12, 0x12, 0x12, 0x12, 
	0x15, 0x15, 0x0e, 0x06, 0x06, 0x07, 0x07, 0x08, 
	0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x09, 0x09, 0x08, 0x06, 0x19, 0x05, 0x03, 0x01, 
	0x02, 0x05, 0x11, 0x15, 0x12, 0x15, 0x15, 0x15, 
	0x15, 0x0e, 0x0e, 0x19, 0x06, 0x06, 0x06, 0x07, 
	0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x08, 0x07, 0x06, 0x19, 0x15, 0x0d, 0x02, 0x00, 
	0x00, 0x03, 0x0c, 0x05, 0x15, 0x15, 0x0e, 0x0e, 
	0x0e, 0x0e, 0x0e, 0x19, 0x19, 0x06, 0x06, 0x06, 
	0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x08, 0x07, 
	0x06, 0x06, 0x19, 0x15, 0x11, 0x0c, 0x02, 0x00, 
	0x00, 0x00, 0x02, 0x03, 0x05, 0x0e, 0x0e, 0x19, 
	0x19, 0x19, 0x19, 0x19, 0x19, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x0e, 0x15, 0x11, 0x0c, 0x03, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x39, 0x04, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x19, 
	0x19, 0x19, 0x0d, 0x0c, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x39, 0x39, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x03, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 
	0x39, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x02, 
	0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x03, 0x03, 0x03, 0x39, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x01, 0x01, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x01, 0x01, 0x03, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x03, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx foreroom_lever_red_ball_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 foreroom_lever_red_ball_ci8_pal_rgba16[] = {
	0xb8, 0x42, 0xb0, 0x42, 0xa8, 0x42, 0xa0, 0x42, 
	0x90, 0x42, 0x80, 0x42, 0x90, 0x43, 0x98, 0x43, 
	0xa0, 0x43, 0xa8, 0x43, 0xb0, 0x43, 0xb8, 0x43, 
	0x88, 0x42, 0x78, 0x42, 0x80, 0x43, 0xc0, 0x43, 
	0xc8, 0x43, 0x70, 0x42, 0x70, 0x43, 0xd0, 0x43, 
	0xd8, 0x43, 0x78, 0x43, 0xe0, 0x43, 0x68, 0x42, 
	0x68, 0x43, 0x88, 0x43, 0x60, 0x42, 0x58, 0x42, 
	0x60, 0x43, 0xe0, 0x85, 0xe8, 0x85, 0xe8, 0x43, 
	0x48, 0x42, 0x50, 0x43, 0xf0, 0xc7, 0xf1, 0x09, 
	0xf0, 0x85, 0x48, 0x43, 0xf1, 0x8d, 0xf2, 0x11, 
	0x40, 0x43, 0xf1, 0x4b, 0xf2, 0x53, 0xf3, 0x5b, 
	0xf3, 0x19, 0x40, 0x42, 0x38, 0x43, 0xf2, 0x95, 
	0xf3, 0x9d, 0xf3, 0xdf, 0x30, 0x42, 0xf2, 0xd7, 
	0x58, 0x43, 0xd8, 0x85, 0xe8, 0xc7, 0x38, 0x42, 
	0x50, 0x42, 0x98, 0x42, 
};

Vtx foreroom_lever_base_mesh_layer_1_vtx_0[20] = {
	{{{-49, -11, 29},0, {4079, 394},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-49, 11, 30},0, {2032, 394},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-49, 11, -29},0, {2032, 1622},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-49, -11, -29},0, {4079, 1622},{0x81, 0x0, 0x0, 0xFF}}},
	{{{49, -11, 29},0, {-16, -2063},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-49, 11, 30},0, {2032, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-49, -11, 29},0, {2032, -2063},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{49, 11, 30},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{49, 11, -29},0, {-16, 1622},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-49, 11, -29},0, {2032, 1622},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-49, 11, 30},0, {2032, 394},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{49, 11, 30},0, {-16, 394},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-49, -11, -29},0, {2032, 4079},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-49, 11, -29},0, {2032, 2032},{0x0, 0x0, 0x81, 0xFF}}},
	{{{49, 11, -29},0, {-16, 2032},{0x0, 0x0, 0x81, 0xFF}}},
	{{{49, -11, -29},0, {-16, 4079},{0x0, 0x0, 0x81, 0xFF}}},
	{{{49, -11, -29},0, {-2063, 1622},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{49, 11, 30},0, {-16, 394},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{49, -11, 29},0, {-2063, 394},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{49, 11, -29},0, {-16, 1622},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx foreroom_lever_base_mesh_layer_1_tri_0[] = {
	gsSPVertex(foreroom_lever_base_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSPEndDisplayList(),
};

Vtx foreroom_lever_ball_mesh_layer_4_vtx_0[4] = {
	{{{-76, 61, 0},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-37, 61, 0},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-37, 101, 0},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-76, 101, 0},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx foreroom_lever_ball_mesh_layer_4_tri_0[] = {
	gsSPVertex(foreroom_lever_ball_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx foreroom_lever_handle_mesh_layer_1_vtx_0[36] = {
	{{{0, -3, -4},0, {3001, -2414},{0x99, 0xB5, 0x0, 0xFF}}},
	{{{-52, 68, 4},0, {2332, 4567},{0x99, 0xB5, 0x0, 0xFF}}},
	{{{-52, 68, -4},0, {3001, 4567},{0x99, 0xB5, 0x0, 0xFF}}},
	{{{0, -3, 4},0, {2332, -2414},{0x99, 0xB5, 0x0, 0xFF}}},
	{{{4, -1, -8},0, {-345, -2413},{0xBF, 0xD1, 0x9D, 0xFF}}},
	{{{0, -3, -4},0, {-1014, -2413},{0xBF, 0xD1, 0x9D, 0xFF}}},
	{{{-52, 68, -4},0, {-1014, 4568},{0xBF, 0xD1, 0x9D, 0xFF}}},
	{{{-47, 70, -8},0, {-345, 4568},{0xBF, 0xD1, 0x9D, 0xFF}}},
	{{{-43, 72, -4},0, {-267, -2582},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{-47, 70, -8},0, {2793, -2582},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{-52, 68, -4},0, {4322, -2776},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{-47, 70, 8},0, {-267, -2970},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{-52, 68, 4},0, {2793, -2970},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{-43, 72, 4},0, {-1797, -2776},{0xCB, 0x74, 0x0, 0xFF}}},
	{{{0, -3, 4},0, {2332, -2414},{0xBF, 0xD1, 0x63, 0xFF}}},
	{{{-47, 70, 8},0, {1663, 4567},{0xBF, 0xD1, 0x63, 0xFF}}},
	{{{-52, 68, 4},0, {2332, 4567},{0xBF, 0xD1, 0x63, 0xFF}}},
	{{{4, -1, 8},0, {1663, -2414},{0xBF, 0xD1, 0x63, 0xFF}}},
	{{{4, -1, 8},0, {1663, -2414},{0x41, 0x2F, 0x63, 0xFF}}},
	{{{-43, 72, 4},0, {993, 4568},{0x41, 0x2F, 0x63, 0xFF}}},
	{{{-47, 70, 8},0, {1663, 4567},{0x41, 0x2F, 0x63, 0xFF}}},
	{{{9, 1, 4},0, {993, -2413},{0x41, 0x2F, 0x63, 0xFF}}},
	{{{9, 1, 4},0, {993, -2413},{0x67, 0x4B, 0x0, 0xFF}}},
	{{{-43, 72, -4},0, {324, 4568},{0x67, 0x4B, 0x0, 0xFF}}},
	{{{-43, 72, 4},0, {993, 4568},{0x67, 0x4B, 0x0, 0xFF}}},
	{{{9, 1, -4},0, {324, -2413},{0x67, 0x4B, 0x0, 0xFF}}},
	{{{9, 1, -4},0, {324, -2413},{0x41, 0x2F, 0x9D, 0xFF}}},
	{{{-47, 70, -8},0, {-345, 4568},{0x41, 0x2F, 0x9D, 0xFF}}},
	{{{-43, 72, -4},0, {324, 4568},{0x41, 0x2F, 0x9D, 0xFF}}},
	{{{4, -1, -8},0, {-345, -2413},{0x41, 0x2F, 0x9D, 0xFF}}},
	{{{0, -3, -4},0, {-1014, -2413},{0x35, 0x8C, 0x0, 0xFF}}},
	{{{4, -1, -8},0, {-345, -2413},{0x35, 0x8C, 0x0, 0xFF}}},
	{{{9, 1, -4},0, {324, -2413},{0x35, 0x8C, 0x0, 0xFF}}},
	{{{4, -1, 8},0, {1663, -2414},{0x35, 0x8C, 0x0, 0xFF}}},
	{{{9, 1, 4},0, {993, -2413},{0x35, 0x8C, 0x0, 0xFF}}},
	{{{0, -3, 4},0, {2332, -2414},{0x35, 0x8C, 0x0, 0xFF}}},
};

Gfx foreroom_lever_handle_mesh_layer_1_tri_0[] = {
	gsSPVertex(foreroom_lever_handle_mesh_layer_1_vtx_0 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
	gsSP2Triangles(10, 12, 11, 0, 11, 13, 8, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 17, 15, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 25, 23, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
	gsSPVertex(foreroom_lever_handle_mesh_layer_1_vtx_0 + 30, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(2, 4, 3, 0, 3, 5, 0, 0),
	gsSPEndDisplayList(),
};


Gfx mat_foreroom_lever_Lever_001_v4[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, foreroom_lever_metal_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 13),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, foreroom_lever_metal_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPSetLights1(foreroom_lever_Lever_001_v4_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_foreroom_lever_Lever_001_v4[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_foreroom_lever_red_ball_001_v4[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, foreroom_lever_red_ball_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 57),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, foreroom_lever_red_ball_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_foreroom_lever_red_ball_001_v4[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx foreroom_lever_base_mesh_layer_1[] = {
	gsSPDisplayList(mat_foreroom_lever_Lever_001_v4),
	gsSPDisplayList(foreroom_lever_base_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_foreroom_lever_Lever_001_v4),
	gsSPEndDisplayList(),
};

Gfx foreroom_lever_ball_mesh_layer_4[] = {
	gsSPDisplayList(mat_foreroom_lever_red_ball_001_v4),
	gsSPDisplayList(foreroom_lever_ball_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_foreroom_lever_red_ball_001_v4),
	gsSPEndDisplayList(),
};

Gfx foreroom_lever_handle_mesh_layer_1[] = {
	gsSPDisplayList(mat_foreroom_lever_Lever_001_v4),
	gsSPDisplayList(foreroom_lever_handle_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_foreroom_lever_Lever_001_v4),
	gsSPEndDisplayList(),
};

Gfx foreroom_lever_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

